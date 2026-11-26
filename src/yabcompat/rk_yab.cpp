/*
    RenkuBASIC --- yab compatibility layer, Haiku implementation.

    yab 1.8.3 gives a BASIC program a BeOS widget API: named windows, named
    views inside them, and a `draw` command set that paints on a view. This file
    implements the window/view/draw part of that API on the Haiku kits, on top
    of the same BApplication the yabasic graphic window uses (rick_gui.cpp,
    BUILDING.md decision D6).

    Design notes
    ------------
    * A yab window is a BWindow with one display BView. The pixels live in a
      `frame` BBitmap that has no child view, exactly like rk_gui.cpp's g_frame:
      the interpreter thread composites into it on flush, and the window thread
      only blits it, so the two threads never share a bitmap lock (round 6 in
      docs/phase2.md is that lesson).
    * A yab view is a named rectangle inside a window with its own offscreen
      BBitmap and BView. Drawing goes there; `draw flush` copies it into the
      window's frame at the view's offset and invalidates the window. That keeps
      view contents independent of window redraws, which is what yab programs
      expect (drawing survives exposing the window).
    * Windows are created on the interpreter thread once the application is
      running on its own thread; see rk_gui.cpp for why the BApplication has to
      be constructed on the thread that runs it. rk_gui_ensure_app() is that
      startup path, shared by both layers.
    * Locking always has a timeout. A wedged app_server has to produce an error
      ("the window did not respond"), never a hung program and a hung test.
*/

#include <Application.h>
#include <Bitmap.h>
#include <BitmapStream.h>
#include <Box.h>
#include <Button.h>
#include <CheckBox.h>
#include <File.h>
#include <Font.h>
#include <Message.h>
#include <RadioButton.h>
#include <ScrollBar.h>
#include <Slider.h>
#include <StatusBar.h>
#include <StringView.h>
#include <TabView.h>
#include <TextControl.h>
#include <TextView.h>
#include <TranslatorRoster.h>
#include <View.h>
#include <Window.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>

#include "rk_gui.h"
#include "yabcompat/rk_yab.h"

namespace {

struct YabWindow;

struct YabView {
  char *name;
  char *window_name;
  YabWindow *window;
  BRect rect;      /* in window content coordinates */
  BBitmap *canvas; /* accepts views: the drawing target */
  BView *view;
  BFont font;
  rgb_color background;
  rgb_color low;
  rgb_color high;
  int visible; /* 0 for a stack page that is not the selected one */
  YabView *next;
};

struct YabWindow {
  char *name;
  BWindow *window;
  BView *display;
  BBitmap *frame; /* content size, no views: only blitted */
  float width;
  float height;
  uint32 resize_mode; /* what `layout` set; applied to new widgets */
  YabWindow *next;
};

YabWindow *g_windows = NULL;
YabView *g_views = NULL;
char g_error[512] = "";
struct YabWidget; /* the widget registry follows copy_pixels() */
YabWidget *g_widgets = NULL;

void clear_error(void) {
  g_error[0] = '\0';
}

void set_error(const char *text) {
  snprintf(g_error, sizeof(g_error), "%s", text ? text : "");
}

YabWindow *find_window(const char *name) {
  for (YabWindow *window = g_windows; window; window = window->next) {
    if (window->name && name && strcmp(window->name, name) == 0) {
      return window;
    }
  }
  return NULL;
}

YabView *find_view(const char *name) {
  for (YabView *view = g_views; view; view = view->next) {
    if (view->name && name && strcmp(view->name, name) == 0) {
      return view;
    }
  }
  return NULL;
}

void trim(char *text) {
  char *start = text;
  while (*start == ' ' || *start == '\t') {
    start++;
  }
  if (start != text) {
    memmove(text, start, strlen(start) + 1);
  }
  size_t len = strlen(text);
  while (len > 0 && (text[len - 1] == ' ' || text[len - 1] == '\t')) {
    text[--len] = '\0';
  }
}

/* "Family, Style, Size", any part optional; an unknown family keeps the
   previous font but still applies the size. Same rules as rk_gui_set_font(),
   because both layers take yab's font specifications. */
void apply_font_spec(BFont *font, const char *spec) {
  char family[256] = "";
  char style[256] = "";
  float size = font->Size();
  char buffer[256];

  if (!spec) {
    return;
  }
  snprintf(buffer, sizeof(buffer), "%s", spec);
  char *part = buffer;
  char *comma = strchr(part, ',');
  if (comma) {
    *comma = '\0';
  }
  snprintf(family, sizeof(family), "%s", part);
  trim(family);
  if (comma) {
    part = comma + 1;
    comma = strchr(part, ',');
    if (comma) {
      *comma = '\0';
    }
    snprintf(style, sizeof(style), "%s", part);
    trim(style);
    if (comma) {
      float parsed = (float)atof(comma + 1);
      if (parsed >= 1.0f && parsed <= 512.0f) {
        size = parsed;
      }
    }
  } else if (family[0]) {
    char *end = NULL;
    double value = strtod(family, &end);
    if (end && *end == '\0' && value >= 1.0 && value <= 512.0) {
      size = (float)value;
      family[0] = '\0';
    }
  }

  BFont next(*font);
  if (family[0] && next.SetFamilyAndStyle(family, style[0] ? style : NULL) != B_OK) {
    next = *font;
  }
  next.SetSize(size);
  *font = next;
}

/* Copy `width` x `height` pixels from `source` at (sx, sy) into `target` at
   (tx, ty). Used for view -> window compositing and for screenshots. */
void copy_pixels(BBitmap *source, int sx, int sy, BBitmap *target, int tx,
                 int ty, int width, int height) {
  if (!source || !target || width < 1 || height < 1) {
    return;
  }
  const uint8 *src = (const uint8 *)source->Bits();
  uint8 *dst = (uint8 *)target->Bits();
  if (!src || !dst) {
    return;
  }
  int32 src_row = source->BytesPerRow();
  int32 dst_row = target->BytesPerRow();
  int32 src_width = (int32)source->Bounds().Width() + 1;
  int32 src_height = (int32)source->Bounds().Height() + 1;
  int32 dst_width = (int32)target->Bounds().Width() + 1;
  int32 dst_height = (int32)target->Bounds().Height() + 1;

  if (sx < 0) {
    width += sx;
    tx -= sx;
    sx = 0;
  }
  if (sy < 0) {
    height += sy;
    ty -= sy;
    sy = 0;
  }
  if (sx + width > src_width) {
    width = src_width - sx;
  }
  if (sy + height > src_height) {
    height = src_height - sy;
  }
  if (tx < 0) {
    width += tx;
    sx -= tx;
    tx = 0;
  }
  if (ty < 0) {
    height += ty;
    sy -= ty;
    ty = 0;
  }
  if (tx + width > dst_width) {
    width = dst_width - tx;
  }
  if (ty + height > dst_height) {
    height = dst_height - ty;
  }
  if (width < 1 || height < 1) {
    return;
  }
  size_t row_bytes = (size_t)width * 4;
  for (int y = 0; y < height; y++) {
    memcpy(dst + (size_t)(ty + y) * dst_row + (size_t)tx * 4,
           src + (size_t)(sy + y) * src_row + (size_t)sx * 4, row_bytes);
  }
}

/* ---- offscreen views --------------------------------------------------- */

/* A named offscreen surface inside a window. `view`, `canvas`, `region`,
   `splitview` and `stackview` all come through here. */
YabView *create_view(YabWindow *window, double x1, double y1, double x2,
                     double y2, const char *id) {
  float width = (float)(x2 - x1 + 1.0);
  float height = (float)(y2 - y1 + 1.0);
  BRect surface(0, 0, width - 1.0f, height - 1.0f);

  BBitmap *canvas = new BBitmap(surface, B_RGB32, true);
  if (!canvas || canvas->InitCheck() != B_OK) {
    delete canvas;
    set_error("view: could not create the drawing bitmap");
    return NULL;
  }
  BView *view = new BView(surface, "rk-yab-view", B_FOLLOW_NONE, 0);
  canvas->Lock();
  canvas->AddChild(view);
  view->SetHighColor(255, 255, 255, 255);
  view->FillRect(surface);
  view->SetDrawingMode(B_OP_COPY);
  BFont font(*be_plain_font);
  font.SetSize(12.0f);
  view->SetFont(&font);
  canvas->Unlock();

  YabView *entry = new YabView;
  entry->name = strdup(id);
  entry->window_name = strdup(window->name ? window->name : "");
  entry->window = window;
  entry->rect = BRect((float)x1, (float)y1, (float)x2, (float)y2);
  entry->canvas = canvas;
  entry->view = view;
  entry->font = font;
  entry->background.red = 255;
  entry->background.green = 255;
  entry->background.blue = 255;
  entry->background.alpha = 255;
  entry->low = entry->background;
  entry->high.red = 0;
  entry->high.green = 0;
  entry->high.blue = 0;
  entry->high.alpha = 255;
  entry->visible = 1;
  entry->next = g_views;
  g_views = entry;
  return entry;
}

/* The named view guard shared by view, canvas, region and the container
   views: a name is used once per program, and the rectangle must fit inside
   the window. */
YabView *open_view_at(YabWindow *window, double x1, double y1, double x2,
                      double y2, const char *id) {
  if (!id || !*id) {
    set_error("view: a view needs a name");
    return NULL;
  }
  if (find_view(id)) {
    snprintf(g_error, sizeof(g_error), "view: '%s' is already open", id);
    return NULL;
  }
  float width = (float)(x2 - x1 + 1.0);
  float height = (float)(y2 - y1 + 1.0);
  if (width < 1.0f || height < 1.0f || width > 8192.0f || height > 8192.0f) {
    set_error("view: the view size is out of range");
    return NULL;
  }
  if ((float)x1 < 0.0f || (float)y1 < 0.0f ||
      (float)x1 + width > window->width ||
      (float)y1 + height > window->height) {
    set_error("view: the view does not fit into its window");
    return NULL;
  }
  return create_view(window, x1, y1, x2, y2, id);
}

/* Repaint a window's frame from its views: white, then every visible view in
   creation order. `draw flush` uses it, and so does a stack page switch, so a
   page that was switched away cannot leave pixels behind. */
bool refresh_window(YabWindow *window) {
  if (!window || !window->window || !window->frame) {
    set_error("the window is not open");
    return false;
  }
  if (window->window->LockWithTimeout(100000) != B_OK) {
    set_error("the window did not respond");
    return false;
  }

  int count = 0;
  for (YabView *view = g_views; view; view = view->next) {
    if (view->window == window && view->visible) {
      count++;
    }
  }
  YabView **visible = count > 0 ? new YabView *[count] : NULL;
  int seen = 0;
  /* g_views is newest first, so the reverse is creation order. */
  for (YabView *view = g_views; view; view = view->next) {
    if (view->window == window && view->visible) {
      visible[count - 1 - seen++] = view;
    }
  }

  uint8 *bits = (uint8 *)window->frame->Bits();
  if (bits) {
    memset(bits, 0xff, (size_t)window->frame->BytesPerRow() *
                           (size_t)(window->frame->Bounds().Height() + 1.0f));
  }
  for (int i = 0; i < count; i++) {
    YabView *view = visible[i];
    view->canvas->Lock();
    copy_pixels(view->canvas, 0, 0, window->frame, (int)view->rect.left,
                (int)view->rect.top, (int)(view->rect.Width() + 1.0f),
                (int)(view->rect.Height() + 1.0f));
    view->canvas->Unlock();
  }
  delete[] visible;

  window->display->Invalidate();
  window->window->Unlock();
  return true;
}

/* ---- widget registry ---------------------------------------------------- */

/* yab calls its controls widgets and addresses them by name. The control is a
   BView child of the window's display view (so app_server draws and operates
   it); the window frame bitmap underneath keeps the `draw` output. A container
   such as a stack view has no control of its own and keeps view == NULL. */
enum YabWidgetKind {
  wkBUTTON, wkCHECKBOX, wkRADIO, wkLABEL, wkURL, wkTEXTCONTROL, wkTEXTEDIT,
  wkSLIDER, wkSPIN, wkSTATUSBAR, wkTABVIEW, wkBOXVIEW, wkSTACKVIEW,
  wkSCROLLBAR
};

struct YabWidget {
  char *name;
  YabWindow *window;
  YabWidgetKind kind;
  BView *view;   /* NULL for a container without a control */
  BView *extra;  /* the second scrollbar, when both were asked for */
  int number;    /* pages of a stack view, bars of a scrollbar */
  YabWidget *next;
};

YabWidget *find_widget(const char *name) {
  for (YabWidget *widget = g_widgets; widget; widget = widget->next) {
    if (widget->name && name && strcmp(widget->name, name) == 0) {
      return widget;
    }
  }
  return NULL;
}

void forget_window_widgets(YabWindow *window) {
  YabWidget *widget = g_widgets;
  YabWidget *previous = NULL;
  while (widget) {
    YabWidget *next = widget->next;
    if (widget->window == window) {
      if (previous) {
        previous->next = next;
      } else {
        g_widgets = next;
      }
      free(widget->name);
      delete widget;
    } else {
      previous = widget;
    }
    widget = next;
  }
}

/* The window a widget command lives in: the window itself (yab's root view
   carries the window's name) or a named view inside it. `dx`/`dy` are the
   offset of that view, so a widget's coordinates stay relative to it. */
YabWindow *widget_host(const char *name, float *dx, float *dy) {
  *dx = 0.0f;
  *dy = 0.0f;
  YabWindow *window = find_window(name);
  if (window) {
    return window;
  }
  YabView *view = find_view(name);
  if (view) {
    *dx = view->rect.left;
    *dy = view->rect.top;
    return view->window;
  }
  snprintf(g_error, sizeof(g_error), "view '%s' is not open",
           name ? name : "");
  return NULL;
}

bool attach_widget(YabWindow *window, BView *view) {
  if (!window || !window->window) {
    set_error("the window is not open");
    return false;
  }
  if (window->window->LockWithTimeout(100000) != B_OK) {
    set_error("the window did not respond");
    return false;
  }
  window->display->AddChild(view);
  window->window->Unlock();
  return true;
}

/* Register a finished control. The window owns the BView once it is a child;
   on any failure the caller still owns it and it is deleted here. */
bool finish_widget(YabWindow *window, YabWidgetKind kind, const char *id,
                   BView *view, int number, YabWidget **out) {
  if (out) {
    *out = NULL;
  }
  if (!id || !*id) {
    set_error("a widget needs a name");
    if (view) {
      delete view;
    }
    return false;
  }
  if (find_widget(id)) {
    snprintf(g_error, sizeof(g_error), "'%s' is already a widget", id);
    if (view) {
      delete view;
    }
    return false;
  }
  if (view) {
    BRect frame = view->Frame();
    if (frame.Width() < 1.0f || frame.Height() < 1.0f ||
        frame.right > window->width - 1.0f ||
        frame.bottom > window->height - 1.0f) {
      set_error("the widget does not fit into its window");
      delete view;
      return false;
    }
    view->SetResizingMode(window->resize_mode);
    if (!attach_widget(window, view)) {
      delete view;
      return false;
    }
  }

  YabWidget *widget = new YabWidget;
  widget->name = strdup(id);
  widget->window = window;
  widget->kind = kind;
  widget->view = view;
  widget->extra = NULL;
  widget->number = number;
  widget->next = g_widgets;
  g_widgets = widget;
  if (out) {
    *out = widget;
  }
  return true;
}

bool lock_widget(YabWidget *widget) {
  if (!widget || !widget->window || !widget->window->window) {
    set_error("the widget's window is gone");
    return false;
  }
  if (widget->window->window->LockWithTimeout(100000) != B_OK) {
    set_error("the window did not respond");
    return false;
  }
  return true;
}

rgb_color rgb_from(int r, int g, int b) {
  rgb_color colour;
  colour.red = (uint8)r;
  colour.green = (uint8)g;
  colour.blue = (uint8)b;
  colour.alpha = 255;
  return colour;
}

/* Text controls and the check box family are BControls; a label is a
   BStringView, and a box or a status bar keeps its caption elsewhere. */
bool widget_set_label(YabWidget *widget, const char *label) {
  const char *text = label ? label : "";
  switch (widget->kind) {
  case wkBUTTON:
  case wkCHECKBOX:
  case wkRADIO:
  case wkTEXTCONTROL:
    ((BControl *)widget->view)->SetLabel(text);
    return true;
  case wkLABEL:
  case wkURL:
    ((BStringView *)widget->view)->SetText(text);
    return true;
  case wkSLIDER:
    ((BSlider *)widget->view)->SetLabel(text);
    return true;
  case wkBOXVIEW:
    ((BBox *)widget->view)->SetLabel(text);
    return true;
  case wkSTATUSBAR:
    ((BStatusBar *)widget->view)->SetText(text);
    return true;
  default:
    return false;
  }
}

void widget_set_enabled(YabWidget *widget, bool enabled) {
  switch (widget->kind) {
  case wkBUTTON:
  case wkCHECKBOX:
  case wkRADIO:
  case wkTEXTCONTROL:
  case wkSLIDER:
    ((BControl *)widget->view)->SetEnabled(enabled);
    break;
  case wkTEXTEDIT:
    ((BTextView *)widget->view)->MakeEditable(enabled);
    break;
  default:
    break;
  }
}

/* `layout "left, top", "window"`: the resize mode yab programs select before
   they create their widgets. */
uint32 resize_mode_from_text(const char *text, uint32 fallback) {
  if (!text || !*text) {
    return fallback;
  }
  char buffer[256];
  snprintf(buffer, sizeof(buffer), "%s", text);
  uint32 mode = 0;
  char *part = buffer;
  while (part && *part) {
    char *comma = strchr(part, ',');
    if (comma) {
      *comma = '\0';
    }
    trim(part);
    if (strcasecmp(part, "all") == 0) {
      mode = B_FOLLOW_ALL;
    } else if (strcasecmp(part, "left") == 0) {
      mode |= B_FOLLOW_LEFT;
    } else if (strcasecmp(part, "right") == 0) {
      mode |= B_FOLLOW_RIGHT;
    } else if (strcasecmp(part, "top") == 0) {
      mode |= B_FOLLOW_TOP;
    } else if (strcasecmp(part, "bottom") == 0) {
      mode |= B_FOLLOW_BOTTOM;
    }
    part = comma ? comma + 1 : NULL;
  }
  return mode ? mode : fallback;
}

/* Haiku has no spinner control: a spin control is a text field with two small
   buttons that post their step back to it. */
class YabSpinner : public BView {
public:
  YabSpinner(BRect frame, const char *name, float minimum, float maximum,
             float step)
      : BView(frame, name, B_FOLLOW_LEFT_TOP, B_WILL_DRAW),
        fMinimum(minimum),
        fMaximum(maximum),
        fStep(step > 0.0f ? step : 1.0f),
        fValue(minimum) {
    float width = frame.Width() + 1.0f;
    float height = frame.Height() + 1.0f;
    fText = new BTextControl(BRect(0, 0, width - 19.0f, height - 1.0f), "value",
                             NULL, "", NULL);
    AddChild(fText);
    BMessage *up = new BMessage('rksp');
    up->AddInt32("delta", 1);
    fUp = new BButton(BRect(width - 17.0f, 0, width - 1.0f, height / 2.0f - 1.0f),
                      "up", "+", up);
    fUp->SetTarget(this);
    AddChild(fUp);
    BMessage *down = new BMessage('rksp');
    down->AddInt32("delta", -1);
    fDown =
        new BButton(BRect(width - 17.0f, height / 2.0f, width - 1.0f, height - 1.0f),
                    "down", "-", down);
    fDown->SetTarget(this);
    AddChild(fDown);
    SetValue(minimum);
  }

  void SetValue(double value) {
    if (value < fMinimum) {
      value = fMinimum;
    }
    if (value > fMaximum) {
      value = fMaximum;
    }
    fValue = value;
    char text[64];
    snprintf(text, sizeof(text), "%.10g", value);
    fText->SetText(text);
  }

  double Value() const { return fValue; }

  void MessageReceived(BMessage *message) {
    if (message->what == 'rksp') {
      int32 delta = 0;
      if (message->FindInt32("delta", &delta) == B_OK) {
        SetValue(fValue + (double)delta * (double)fStep);
      }
      return;
    }
    BView::MessageReceived(message);
  }

private:
  BTextControl *fText;
  BButton *fUp;
  BButton *fDown;
  float fMinimum;
  float fMaximum;
  float fStep;
  double fValue;
};

class YabDisplayView : public BView {
public:
  YabDisplayView(BRect frame, YabWindow *owner)
      : BView(frame, "rk-yab-display", B_FOLLOW_ALL, B_WILL_DRAW),
        fOwner(owner) {}

  void Draw(BRect update) {
    SetHighColor(255, 255, 255, 255);
    FillRect(update);
    if (fOwner && fOwner->frame) {
      /* The frame has no child view, so this blit takes no lock: the window
         thread can never wait for the interpreter thread. */
      DrawBitmap(fOwner->frame, BPoint(0, 0));
    }
  }

  /* A yab program closes its windows with `window close`; a stray click on the
     close box would destroy the window behind the interpreter's back. The yab
     window-lifecycle commands get their own shutdown path later, as with the
     yabasic graphic window. */
  bool QuitRequested() { return false; }

private:
  YabWindow *fOwner;
};

class YabWindowClass : public BWindow {
public:
  YabWindowClass(BRect frame, const char *title)
      : BWindow(frame, title ? title : "RenkuBASIC", B_TITLED_WINDOW,
                B_NOT_ZOOMABLE) {}

  bool QuitRequested() { return false; }
};

/* Bring a new window up and wait until its looper answers. Returns false when
   the window exists but never took the lock, in which case the caller must not
   delete it (a running BLooper is not deletable). */
bool show_window(BWindow *window, float width, float height, bool *locked) {
  *locked = false;
  window->Show();
  for (int i = 0; i < 200; i++) {
    if (window->LockWithTimeout(10000) == B_OK) {
      BRect inner = window->Bounds();
      float dw = width - (inner.Width() + 1.0f);
      float dh = height - (inner.Height() + 1.0f);
      if (dw != 0.0f || dh != 0.0f) {
        window->ResizeBy(dw, dh);
      }
      *locked = true;
      return true;
    }
  }
  return false;
}

void destroy_view(YabView *view) {
  if (!view) {
    return;
  }
  if (view->canvas) {
    view->canvas->Lock();
    if (view->view) {
      view->canvas->RemoveChild(view->view);
      delete view->view;
    }
    view->canvas->Unlock();
    delete view->canvas;
  }
  free(view->name);
  free(view->window_name);
  delete view;
}

void destroy_window(YabWindow *window) {
  if (!window) {
    return;
  }
  /* Widget controls are children of the window and are deleted with it; only
     the registry entries have to go. */
  forget_window_widgets(window);

  /* Views of this window go first; they point into it. */
  YabView *view = g_views;
  YabView *previous = NULL;
  while (view) {
    YabView *next = view->next;
    if (view->window == window) {
      if (previous) {
        previous->next = next;
      } else {
        g_views = next;
      }
      destroy_view(view);
    } else {
      previous = view;
    }
    view = next;
  }

  if (window->window) {
    if (window->window->LockWithTimeout(200000) == B_OK) {
      window->window->Quit();
    }
    /* When the lock timed out the window is left to the process exit; deleting
       a running BLooper would be worse. */
  }
  delete window->frame;
  free(window->name);
  delete window;
}

int32 window_flags_from_text(const char *text, uint32 current, char *error,
                             size_t error_size) {
  char buffer[512];
  snprintf(buffer, sizeof(buffer), "%s", text ? text : "");
  char *part = buffer;
  while (part && *part) {
    char *comma = strchr(part, ',');
    if (comma) {
      *comma = '\0';
    }
    trim(part);
    if (strcasecmp(part, "not-h-resizable") == 0) {
      current |= B_NOT_H_RESIZABLE;
    } else if (strcasecmp(part, "h-resizable") == 0) {
      current &= ~(uint32)B_NOT_H_RESIZABLE;
    } else if (strcasecmp(part, "not-v-resizable") == 0) {
      current |= B_NOT_V_RESIZABLE;
    } else if (strcasecmp(part, "v-resizable") == 0) {
      current &= ~(uint32)B_NOT_V_RESIZABLE;
    } else if (strcasecmp(part, "not-zoomable") == 0) {
      current |= B_NOT_ZOOMABLE;
    } else if (strcasecmp(part, "zoomable") == 0) {
      current &= ~(uint32)B_NOT_ZOOMABLE;
    } else if (strcasecmp(part, "not-closable") == 0) {
      current |= B_NOT_CLOSABLE;
    } else if (strcasecmp(part, "not-movable") == 0) {
      current |= B_NOT_MOVABLE;
    } else if (strcasecmp(part, "movable") == 0) {
      current &= ~(uint32)B_NOT_MOVABLE;
    } else {
      snprintf(error, error_size, "unknown window flag '%s'", part);
      return -1;
    }
    part = comma ? comma + 1 : NULL;
  }
  return (int32)current;
}

} // namespace

extern "C" {

int rk_yab_available(void) { return 1; }

const char *rk_yab_last_error(void) { return g_error; }

int rk_yab_window_open(double x1, double y1, double x2, double y2,
                       const char *id, const char *title) {
  clear_error();
  if (!id || !*id) {
    set_error("window open: a window needs a name");
    return 0;
  }
  if (find_window(id)) {
    snprintf(g_error, sizeof(g_error), "window open: '%s' is already open", id);
    return 0;
  }
  if (!rk_gui_ensure_app()) {
    set_error(rk_gui_last_error());
    if (!g_error[0]) {
      set_error("window open: the application is not running");
    }
    return 0;
  }

  float width = (float)(x2 - x1 + 1.0);
  float height = (float)(y2 - y1 + 1.0);
  if (width < 1.0f || height < 1.0f || width > 8192.0f || height > 8192.0f) {
    set_error("window open: the window size is out of range");
    return 0;
  }

  BRect content(0, 0, width - 1.0f, height - 1.0f);
  BBitmap *frame = new BBitmap(content, B_RGB32, false);
  if (!frame || frame->InitCheck() != B_OK) {
    delete frame;
    set_error("window open: could not create the window bitmap");
    return 0;
  }

  YabWindow *entry = new YabWindow;
  entry->name = strdup(id);
  entry->frame = frame;
  entry->width = width;
  entry->height = height;
  entry->resize_mode = B_FOLLOW_LEFT | B_FOLLOW_TOP;
  entry->next = NULL;

  BRect frame_rect((float)x1, (float)y1, (float)x2, (float)y2);
  YabWindowClass *window = new YabWindowClass(frame_rect, title ? title : id);
  YabDisplayView *display = new YabDisplayView(content, entry);
  window->AddChild(display);
  entry->window = window;
  entry->display = display;

  bool locked = false;
  if (!show_window(window, width, height, &locked)) {
    /* The window's looper is running but did not answer. Deleting a running
       BLooper is a debugger() call, and the display view points at the entry,
       so window, view and entry are left to the process exit (the same choice
       rk_gui.cpp makes). Only the bitmap the display would draw is dropped. */
    set_error(
        "window open: the window did not respond (is app_server reachable?)");
    return 0;
  }
  window->Unlock();

  entry->next = g_windows;
  g_windows = entry;
  return 1;
}

int rk_yab_window_close(const char *id) {
  clear_error();
  YabWindow *window = find_window(id);
  if (!window) {
    snprintf(g_error, sizeof(g_error), "window close: '%s' is not open",
             id ? id : "");
    return 0;
  }
  /* Unlink before destroying: a failing lock must not leave a half window in
     the list, and the views are destroyed with it. */
  YabWindow *previous = NULL;
  for (YabWindow *item = g_windows; item; item = item->next) {
    if (item == window) {
      if (previous) {
        previous->next = item->next;
      } else {
        g_windows = item->next;
      }
      break;
    }
    previous = item;
  }
  destroy_window(window);
  return 1;
}

int rk_yab_window_count(void) {
  int count = 0;
  for (YabWindow *window = g_windows; window; window = window->next) {
    count++;
  }
  return count;
}

double rk_yab_window_get(const char *id, const char *property) {
  clear_error();
  YabWindow *window = find_window(id);
  if (!window || !window->window) {
    snprintf(g_error, sizeof(g_error), "window get: '%s' is not open",
             id ? id : "");
    return 0.0;
  }
  if (!property) {
    set_error("window get: a property is needed");
    return 0.0;
  }
  if (strcmp(property, "width") == 0) {
    return (double)window->width;
  }
  if (strcmp(property, "height") == 0) {
    return (double)window->height;
  }
  if (strcmp(property, "position-x") == 0 || strcmp(property, "position-y") == 0 ||
      strcmp(property, "frame-width") == 0 ||
      strcmp(property, "frame-height") == 0) {
    double result = 0.0;
    if (window->window->LockWithTimeout(100000) == B_OK) {
      BRect frame = window->window->Frame();
      if (strcmp(property, "position-x") == 0) {
        result = (double)frame.left;
      } else if (strcmp(property, "position-y") == 0) {
        result = (double)frame.top;
      } else if (strcmp(property, "frame-width") == 0) {
        result = (double)(frame.Width() + 1.0f);
      } else {
        result = (double)(frame.Height() + 1.0f);
      }
      window->window->Unlock();
    } else {
      set_error("window get: the window did not respond");
      return 0.0;
    }
    return result;
  }
  snprintf(g_error, sizeof(g_error),
           "window get: '%s' is not a numeric window property", property);
  return 0.0;
}

int rk_yab_window_set(const char *id, const char *property, const char *value) {
  clear_error();
  YabWindow *window = find_window(id);
  if (!window || !window->window) {
    snprintf(g_error, sizeof(g_error), "window set: '%s' is not open",
             id ? id : "");
    return 0;
  }
  if (!property) {
    set_error("window set: a property is needed");
    return 0;
  }
  if (strcmp(property, "title") == 0) {
    if (window->window->LockWithTimeout(100000) != B_OK) {
      set_error("window set: the window did not respond");
      return 0;
    }
    window->window->SetTitle(value ? value : "");
    window->window->Unlock();
    return 1;
  }
  if (strcmp(property, "flags") == 0) {
    char problem[256] = "";
    uint32 current = 0;
    if (window->window->LockWithTimeout(100000) != B_OK) {
      set_error("window set: the window did not respond");
      return 0;
    }
    current = window->window->Flags();
    int32 flags = window_flags_from_text(value, current, problem, sizeof(problem));
    if (flags < 0) {
      window->window->Unlock();
      snprintf(g_error, sizeof(g_error), "window set: %s", problem);
      return 0;
    }
    window->window->SetFlags((uint32)flags);
    window->window->Unlock();
    return 1;
  }
  snprintf(g_error, sizeof(g_error),
           "window set: '%s' is not a window property", property);
  return 0;
}

int rk_yab_view_open(double x1, double y1, double x2, double y2,
                     const char *id, const char *window_name) {
  clear_error();
  YabWindow *window = find_window(window_name);
  if (!window) {
    snprintf(g_error, sizeof(g_error), "view: window '%s' is not open",
             window_name ? window_name : "");
    return 0;
  }
  if (!open_view_at(window, x1, y1, x2, y2, id)) {
    return 0;
  }
  return refresh_window(window) ? 1 : 0;
}

int rk_yab_view_set_font(const char *spec, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw set: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  apply_font_spec(&view->font, spec);
  view->canvas->Lock();
  view->view->SetFont(&view->font);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_view_set_colour(const char *property, int r, int g, int b,
                           const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw set: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  if (!property) {
    set_error("draw set: a property is needed");
    return 0;
  }
  rgb_color colour;
  colour.red = (uint8)r;
  colour.green = (uint8)g;
  colour.blue = (uint8)b;
  colour.alpha = 255;

  if (strcmp(property, "bgcolor") == 0 || strcmp(property, "background") == 0) {
    view->background = colour;
    view->canvas->Lock();
    view->view->SetHighColor(colour);
    view->view->FillRect(view->view->Bounds());
    view->canvas->Unlock();
    return 1;
  }
  if (strcmp(property, "lowcolor") == 0) {
    view->low = colour;
    return 1;
  }
  if (strcmp(property, "highcolor") == 0) {
    view->high = colour;
    return 1;
  }
  snprintf(g_error, sizeof(g_error),
           "draw set: '%s' is not a view colour", property);
  return 0;
}

double rk_yab_view_get(const char *property, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw get: view '%s' does not exist",
             view_name ? view_name : "");
    return 0.0;
  }
  if (!property) {
    set_error("draw get: a property is needed");
    return 0.0;
  }
  if (strcmp(property, "width") == 0) {
    return (double)(view->rect.Width() + 1.0f);
  }
  if (strcmp(property, "height") == 0) {
    return (double)(view->rect.Height() + 1.0f);
  }
  if (strcmp(property, "max-text-height") == 0 ||
      strcmp(property, "text-height") == 0) {
    font_height height;
    view->font.GetHeight(&height);
    return (double)(height.ascent + height.descent + 1.0f);
  }
  if (strcmp(property, "text-width") == 0) {
    set_error("draw get: text-width needs the text to measure");
    return 0.0;
  }
  snprintf(g_error, sizeof(g_error), "draw get: '%s' is not a view property",
           property);
  return 0.0;
}

double rk_yab_view_text_width(const char *text, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw get: view '%s' does not exist",
             view_name ? view_name : "");
    return 0.0;
  }
  double width = 0.0;
  view->canvas->Lock();
  width = (double)view->view->StringWidth(text ? text : "");
  view->canvas->Unlock();
  return width;
}

int rk_yab_draw_text(double x, double y, const char *text, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw text: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->SetFont(&view->font);
  view->view->SetDrawingMode(B_OP_OVER);
  view->view->DrawString(text ? text : "", BPoint((float)x, (float)y));
  view->view->SetDrawingMode(B_OP_COPY);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_dot(double x, double y, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw dot: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  /* One pixel: StrokeLine would paint two. */
  view->view->FillRect(BRect((float)x, (float)y, (float)x, (float)y));
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_line(double x1, double y1, double x2, double y2,
                     const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw line: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->SetPenSize(1.0f);
  view->view->StrokeLine(BPoint((float)x1, (float)y1),
                         BPoint((float)x2, (float)y2));
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_rect(double x1, double y1, double x2, double y2,
                     const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw rect: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokeRect(BRect((float)x1, (float)y1, (float)x2, (float)y2));
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_roundrect(double x1, double y1, double x2, double y2,
                          double radius_x, double radius_y,
                          const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error),
             "draw roundrect: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokeRoundRect(BRect((float)x1, (float)y1, (float)x2, (float)y2),
                              (float)radius_x, (float)radius_y);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_circle(double cx, double cy, double radius, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw circle: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BRect rect((float)(cx - radius), (float)(cy - radius), (float)(cx + radius),
             (float)(cy + radius));
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokeEllipse(rect);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_ellipse(double cx, double cy, double rx, double ry,
                        const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw ellipse: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BRect rect((float)(cx - rx), (float)(cy - ry), (float)(cx + rx),
             (float)(cy + ry));
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokeEllipse(rect);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_arc(double cx, double cy, double rx, double ry, double from,
                    double to, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw arc: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BRect rect((float)(cx - rx), (float)(cy - ry), (float)(cx + rx),
             (float)(cy + ry));
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  /* yab gives start and end in degrees; BView wants start and sweep. */
  view->view->StrokeArc(rect, (float)from, (float)(to - from));
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_curve(const double *xy, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view || !xy) {
    snprintf(g_error, sizeof(g_error), "draw curve: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BPoint points[4];
  for (int i = 0; i < 4; i++) {
    points[i].Set((float)xy[2 * i], (float)xy[2 * i + 1]);
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  /* BView::StrokeBezier() takes exactly four control points. */
  view->view->StrokeBezier(points);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_triangle(const double *xy, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view || !xy) {
    snprintf(g_error, sizeof(g_error), "draw triangle: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BPoint points[3];
  for (int i = 0; i < 3; i++) {
    points[i].Set((float)xy[2 * i], (float)xy[2 * i + 1]);
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokePolygon(points, 3, true);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_polygon(const double *xy, const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view || !xy) {
    snprintf(g_error, sizeof(g_error), "draw polygon: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  BPoint points[4];
  for (int i = 0; i < 4; i++) {
    points[i].Set((float)xy[2 * i], (float)xy[2 * i + 1]);
  }
  view->canvas->Lock();
  view->view->SetHighColor(view->high);
  view->view->StrokePolygon(points, 4, true);
  view->canvas->Unlock();
  return 1;
}

int rk_yab_draw_flush(const char *view_name) {
  clear_error();
  YabView *view = find_view(view_name);
  if (!view) {
    snprintf(g_error, sizeof(g_error), "draw flush: view '%s' does not exist",
             view_name ? view_name : "");
    return 0;
  }
  /* Repaint every visible view, not only this one: overlapping views (stack
     pages) then composite in creation order, as yab's do. */
  return refresh_window(view->window) ? 1 : 0;
}

int rk_yab_screenshot(double x1, double y1, double x2, double y2,
                      const char *path) {
  clear_error();
  if (!path || !*path) {
    set_error("screenshot: a file name is needed");
    return 0;
  }
  YabWindow *window = g_windows; /* frontmost: the most recently opened */
  if (!window || !window->frame) {
    set_error("screenshot: no window is open");
    return 0;
  }

  int width = (int)(x2 - x1 + 1.0);
  int height = (int)(y2 - y1 + 1.0);
  if (width < 1 || height < 1) {
    set_error("screenshot: the area is empty");
    return 0;
  }
  BRect bounds(0, 0, width - 1.0f, height - 1.0f);
  BBitmap *picture = new BBitmap(bounds, B_RGB32, false);
  if (!picture || picture->InitCheck() != B_OK) {
    delete picture;
    set_error("screenshot: could not create the picture bitmap");
    return 0;
  }
  if (window->window->LockWithTimeout(100000) == B_OK) {
    copy_pixels(window->frame, (int)x1, (int)y1, picture, 0, 0, width,
                height);
    window->window->Unlock();
  } else {
    set_error("screenshot: the window did not respond");
    delete picture;
    return 0;
  }

  int ok = 0;
  BTranslatorRoster *roster = BTranslatorRoster::Default();
  BFile file(path, B_CREATE_FILE | B_ERASE_FILE | B_WRITE_ONLY);
  if (!roster) {
    set_error("screenshot: no translator roster available");
  } else if (file.InitCheck() != B_OK) {
    set_error("screenshot: could not create the file");
  } else {
    /* BBitmapStream owns the bitmap it is handed, so detach it again or the
       picture is deleted with the stream. */
    BBitmapStream stream(picture);
    status_t status =
        roster->Translate(&stream, NULL, NULL, &file, B_PNG_FORMAT);
    BBitmap *detached = NULL;
    stream.DetachBitmap(&detached);
    if (status == B_OK) {
      ok = 1;
    } else {
      set_error("screenshot: could not encode the picture as PNG");
    }
  }
  delete picture;
  return ok;
}

double rk_yab_file_size(const char *path) {
  clear_error();
  struct stat info;
  if (!path || stat(path, &info) != 0) {
    snprintf(g_error, sizeof(g_error), "bfilesize: cannot read '%s'",
             path ? path : "");
    return -1.0;
  }
  return (double)info.st_size;
}

/* ---- widgets ----------------------------------------------------------- */

int rk_yab_layout(const char *spec, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  window->resize_mode = resize_mode_from_text(spec, window->resize_mode);
  return 1;
}

int rk_yab_button(double x1, double y1, double x2, double y2, const char *id,
                  const char *label, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BButton *button = new BButton(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", label ? label : "", NULL);
  return finish_widget(window, wkBUTTON, id, button, 0, NULL) ? 1 : 0;
}

int rk_yab_checkbox(double x, double y, const char *id, const char *label,
                    int checked, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  /* yab gives only the top left corner; the control takes the room its label
     needs, as BCheckBox does when it sizes itself. */
  float width = be_plain_font->StringWidth(label ? label : "") + 24.0f;
  if (width < 30.0f) {
    width = 30.0f;
  }
  BCheckBox *box =
      new BCheckBox(BRect((float)x + dx, (float)y + dy, (float)x + dx + width,
                          (float)y + dy + 18.0f),
                    id ? id : "", label ? label : "", NULL);
  box->SetValue(checked ? 1 : 0);
  return finish_widget(window, wkCHECKBOX, id, box, 0, NULL) ? 1 : 0;
}

int rk_yab_radiobutton(double x, double y, const char *id, const char *label,
                       int checked, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  float width = be_plain_font->StringWidth(label ? label : "") + 24.0f;
  if (width < 30.0f) {
    width = 30.0f;
  }
  BRadioButton *button =
      new BRadioButton(BRect((float)x + dx, (float)y + dy, (float)x + dx + width,
                             (float)y + dy + 18.0f),
                       id ? id : "", label ? label : "", NULL);
  button->SetValue(checked ? 1 : 0);
  return finish_widget(window, wkRADIO, id, button, 0, NULL) ? 1 : 0;
}

int rk_yab_checkbox_set(const char *id, int checked) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkCHECKBOX) {
    snprintf(g_error, sizeof(g_error), "checkbox set: '%s' is not a checkbox",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BCheckBox *)widget->view)->SetValue(checked ? 1 : 0);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_radiobutton_set(const char *id, int checked) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkRADIO) {
    snprintf(g_error, sizeof(g_error),
             "radiobutton set: '%s' is not a radio button", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BRadioButton *)widget->view)->SetValue(checked ? 1 : 0);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_text(double x, double y, const char *id, const char *text,
                const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  float width = be_plain_font->StringWidth(text ? text : "") + 4.0f;
  BStringView *label =
      new BStringView(BRect((float)x + dx, (float)y + dy, (float)x + dx + width,
                            (float)y + dy + 16.0f),
                      id ? id : "", text ? text : "");
  return finish_widget(window, wkLABEL, id, label, 0, NULL) ? 1 : 0;
}

int rk_yab_text_align(const char *id, const char *align) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || (widget->kind != wkLABEL && widget->kind != wkURL)) {
    snprintf(g_error, sizeof(g_error), "text set: '%s' is not a text label",
             id ? id : "");
    return 0;
  }
  alignment flag = B_ALIGN_LEFT;
  if (align && strstr(align, "center")) {
    flag = B_ALIGN_CENTER;
  } else if (align && strstr(align, "right")) {
    flag = B_ALIGN_RIGHT;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BStringView *)widget->view)->SetAlignment(flag);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_text_url(double x, double y, const char *id, const char *text,
                    const char *url, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  float width = be_plain_font->StringWidth(text ? text : "") + 4.0f;
  BStringView *label =
      new BStringView(BRect((float)x + dx, (float)y + dy, (float)x + dx + width,
                            (float)y + dy + 16.0f),
                      id ? id : "", text ? text : "");
  /* RenkuBASIC has no URL handler yet; the link is kept as the tool tip, so a
     program that asks for one still shows where it points. */
  label->SetHighColor(0, 0, 200, 255);
  label->SetToolTip(url ? url : "");
  return finish_widget(window, wkURL, id, label, 0, NULL) ? 1 : 0;
}

int rk_yab_textcontrol(double x1, double y1, double x2, double y2,
                       const char *id, const char *label, const char *value,
                       const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BTextControl *control = new BTextControl(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", label ? label : "", value ? value : "", NULL);
  return finish_widget(window, wkTEXTCONTROL, id, control, 0, NULL) ? 1 : 0;
}

int rk_yab_textcontrol_set(const char *id, const char *value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTCONTROL) {
    snprintf(g_error, sizeof(g_error),
             "textcontrol set: '%s' is not a text control", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BTextControl *)widget->view)->SetText(value ? value : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_textcontrol_mask(const char *id, int masked) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTCONTROL) {
    snprintf(g_error, sizeof(g_error),
             "textcontrol set: '%s' is not a text control", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BTextControl *)widget->view)->TextView()->HideTyping(masked != 0);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_textcontrol_clear(const char *id) {
  return rk_yab_textcontrol_set(id, "");
}

const char *rk_yab_textcontrol_get(const char *id) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTCONTROL) {
    snprintf(g_error, sizeof(g_error),
             "textcontrol get: '%s' is not a text control", id ? id : "");
    return "";
  }
  return ((BTextControl *)widget->view)->Text();
}

int rk_yab_textedit(double x1, double y1, double x2, double y2,
                    const char *id, int scrollbar, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BRect frame((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy);
  /* The scrollbar argument is accepted as yab's is; the text view wraps, so
     the bars have nothing to scroll yet. */
  (void)scrollbar;
  BTextView *edit = new BTextView(frame, id ? id : "",
                                  BRect(2, 2, frame.Width() - 2.0f,
                                        frame.Height() - 2.0f),
                                  B_FOLLOW_ALL, B_WILL_DRAW);
  edit->SetWordWrap(true);
  return finish_widget(window, wkTEXTEDIT, id, edit, 0, NULL) ? 1 : 0;
}

int rk_yab_textedit_add(const char *id, const char *text) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTEDIT) {
    snprintf(g_error, sizeof(g_error), "textedit add: '%s' is not a text edit",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BTextView *edit = (BTextView *)widget->view;
  int32 length = (int32)strlen(edit->Text());
  edit->Insert(length, text ? text : "", (int32)strlen(text ? text : ""));
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_textedit_set(const char *id, const char *text) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTEDIT) {
    snprintf(g_error, sizeof(g_error), "textedit set: '%s' is not a text edit",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BTextView *)widget->view)->SetText(text ? text : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_textedit_clear(const char *id) {
  return rk_yab_textedit_set(id, "");
}

const char *rk_yab_textedit_get(const char *id) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTEDIT) {
    snprintf(g_error, sizeof(g_error), "textedit get: '%s' is not a text edit",
             id ? id : "");
    return "";
  }
  return ((BTextView *)widget->view)->Text();
}

int rk_yab_textedit_colour(const char *id, const char *property, int r, int g,
                           int b) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTEXTEDIT) {
    snprintf(g_error, sizeof(g_error),
             "textedit colour: '%s' is not a text edit", id ? id : "");
    return 0;
  }
  rgb_color colour = rgb_from(r, g, b);
  if (!lock_widget(widget)) {
    return 0;
  }
  BTextView *edit = (BTextView *)widget->view;
  bool ok = true;
  if (property && strcmp(property, "highcolor") == 0) {
    edit->SetFontAndColor(be_plain_font, B_FONT_ALL, &colour);
  } else if (property && (strcmp(property, "bgcolor") == 0 ||
                          strcmp(property, "background") == 0)) {
    edit->SetViewColor(colour);
    edit->SetLowColor(colour);
    edit->Invalidate();
  } else if (property && strcmp(property, "lowcolor") == 0) {
    edit->SetLowColor(colour);
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "textedit colour: '%s' is not a text edit colour",
             property ? property : "");
    return 0;
  }
  return 1;
}

int rk_yab_slider(double x1, double y1, double x2, double y2, const char *id,
                  const char *label, double minimum, double maximum,
                  const char *options, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BSlider *slider = new BSlider(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", label ? label : "", NULL, (int32)minimum, (int32)maximum);
  if (options) {
    if (strstr(options, "vertical")) {
      slider->SetOrientation(B_VERTICAL);
      slider->SetBarThickness(10.0f);
    }
    if (strstr(options, "triangle")) {
      slider->SetStyle(B_TRIANGLE_THUMB);
    }
  }
  return finish_widget(window, wkSLIDER, id, slider, 0, NULL) ? 1 : 0;
}

int rk_yab_slider_set(const char *id, double value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSLIDER) {
    snprintf(g_error, sizeof(g_error), "slider set: '%s' is not a slider",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BSlider *)widget->view)->SetValue((int32)value);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_slider_marks(const char *id, const char *location, double count) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSLIDER) {
    snprintf(g_error, sizeof(g_error), "slider set: '%s' is not a slider",
             id ? id : "");
    return 0;
  }
  hash_mark_location where = B_HASH_MARKS_BOTH;
  if (location && strcmp(location, "none") == 0) {
    where = B_HASH_MARKS_NONE;
  } else if (location && strcmp(location, "left") == 0) {
    where = B_HASH_MARKS_LEFT;
  } else if (location && strcmp(location, "right") == 0) {
    where = B_HASH_MARKS_RIGHT;
  } else if (location && strcmp(location, "top") == 0) {
    where = B_HASH_MARKS_TOP;
  } else if (location && strcmp(location, "bottom") == 0) {
    where = B_HASH_MARKS_BOTTOM;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BSlider *slider = (BSlider *)widget->view;
  slider->SetHashMarks(where);
  slider->SetHashMarkCount((int32)count);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_slider_labels(const char *id, const char *minimum,
                         const char *maximum) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSLIDER) {
    snprintf(g_error, sizeof(g_error), "slider label: '%s' is not a slider",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((BSlider *)widget->view)->SetLimitLabels(minimum ? minimum : "",
                                            maximum ? maximum : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_slider_colour(const char *id, const char *property, int r, int g,
                         int b) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSLIDER) {
    snprintf(g_error, sizeof(g_error), "slider colour: '%s' is not a slider",
             id ? id : "");
    return 0;
  }
  rgb_color colour = rgb_from(r, g, b);
  if (!lock_widget(widget)) {
    return 0;
  }
  BSlider *slider = (BSlider *)widget->view;
  if (property && strcmp(property, "fillcolor") == 0) {
    slider->UseFillColor(true, &colour);
  } else {
    slider->SetBarColor(colour);
  }
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_scrollbar(const char *id, int bars, const char *view_name) {
  clear_error();
  if (!id || !*id) {
    set_error("scrollbar: a scrollbar needs a name");
    return 0;
  }
  YabView *target = find_view(view_name);
  if (!target) {
    snprintf(g_error, sizeof(g_error), "scrollbar: view '%s' is not open",
             view_name ? view_name : "");
    return 0;
  }
  YabWindow *window = target->window;
  if (!window) {
    set_error("scrollbar: the view's window is gone");
    return 0;
  }
  /* yab's numbers: 1 vertical, 2 horizontal, 3 both. */
  bool vertical = bars != 2;
  bool horizontal = bars == 2 || bars >= 3;
  float thickness = 12.0f;
  BScrollBar *first = NULL;
  BScrollBar *second = NULL;
  if (vertical) {
    first = new BScrollBar(
        BRect(target->rect.right - thickness + 1.0f, target->rect.top,
              target->rect.right,
              horizontal ? target->rect.bottom - thickness
                         : target->rect.bottom),
        id, window->display, 0.0f, 100.0f, B_VERTICAL);
  }
  if (horizontal) {
    BScrollBar *bar = new BScrollBar(
        BRect(target->rect.left, target->rect.bottom - thickness + 1.0f,
              vertical ? target->rect.right - thickness : target->rect.right,
              target->rect.bottom),
        id, window->display, 0.0f, 100.0f, B_HORIZONTAL);
    if (first) {
      second = bar;
    } else {
      first = bar;
    }
  }
  YabWidget *widget = NULL;
  if (!finish_widget(window, wkSCROLLBAR, id, first, bars, &widget)) {
    return 0;
  }
  widget->extra = second;
  return 1;
}

int rk_yab_scrollbar_set(const char *id, const char *property, double value,
                         double other, int two) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSCROLLBAR) {
    snprintf(g_error, sizeof(g_error), "scrollbar set: '%s' is not a scrollbar",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BScrollBar *primary = (BScrollBar *)widget->view;
  BScrollBar *secondary = (BScrollBar *)widget->extra;
  bool vertical_first = widget->number != 2;
  bool ok = true;
  if (property && strcmp(property, "horizontal-range") == 0) {
    BScrollBar *bar = vertical_first ? secondary : primary;
    if (!bar) {
      ok = false;
    } else if (two) {
      bar->SetRange((float)value, (float)other);
    } else {
      bar->SetRange(0.0f, (float)value);
    }
  } else if (property && strcmp(property, "vertical-range") == 0) {
    BScrollBar *bar = vertical_first ? primary : NULL;
    if (!bar) {
      ok = false;
    } else if (two) {
      bar->SetRange((float)value, (float)other);
    } else {
      bar->SetRange(0.0f, (float)value);
    }
  } else if (property && strcmp(property, "proportion") == 0) {
    primary->SetProportion((float)value);
    if (secondary) {
      secondary->SetProportion((float)value);
    }
  } else if (property && strcmp(property, "value") == 0) {
    primary->SetValue((float)value);
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "scrollbar set: '%s' is not a scrollbar property",
             property ? property : "");
    return 0;
  }
  return 1;
}

int rk_yab_statusbar(double x1, double y1, double x2, double y2,
                     const char *id, const char *label, const char *trailing,
                     const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BRect frame((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy);
  BStatusBar *bar = new BStatusBar(frame, id ? id : "", label ? label : "",
                                   trailing ? trailing : "");
  float height = frame.Height() - be_plain_font->Size() - 5.0f;
  bar->SetBarHeight(height > 4.0f ? height : 4.0f);
  return finish_widget(window, wkSTATUSBAR, id, bar, 0, NULL) ? 1 : 0;
}

int rk_yab_statusbar_set(const char *id, const char *label,
                         const char *trailing, double percent) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSTATUSBAR) {
    snprintf(g_error, sizeof(g_error),
             "statusbar set: '%s' is not a status bar", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BStatusBar *bar = (BStatusBar *)widget->view;
  bar->Reset();
  bar->Update((float)percent, label ? label : "", trailing ? trailing : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_spincontrol(double x, double y, const char *id, const char *label,
                       double minimum, double maximum, double step,
                       const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  if (maximum < minimum) {
    double swap = maximum;
    maximum = minimum;
    minimum = swap;
  }
  YabSpinner *spinner = new YabSpinner(
      BRect((float)x + dx, (float)y + dy, (float)x + dx + 100.0f,
            (float)y + dy + 22.0f),
      id ? id : "", (float)minimum, (float)maximum, (float)step);
  /* yab takes a label for the spin control; Haiku's text field has none, so
     the label becomes the tool tip. */
  spinner->SetToolTip(label ? label : "");
  return finish_widget(window, wkSPIN, id, spinner, 0, NULL) ? 1 : 0;
}

int rk_yab_spincontrol_set(const char *id, double value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSPIN) {
    snprintf(g_error, sizeof(g_error),
             "spincontrol set: '%s' is not a spin control", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  ((YabSpinner *)widget->view)->SetValue(value);
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_option_set(const char *id, const char *property, const char *value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || !widget->view) {
    snprintf(g_error, sizeof(g_error), "option set: '%s' is not a widget",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  bool ok = true;
  if (property &&
      (strcmp(property, "label") == 0 || strcmp(property, "text") == 0)) {
    ok = widget_set_label(widget, value);
  } else if (property && strcmp(property, "tooltip") == 0) {
    widget->view->SetToolTip(value ? value : "");
  } else if (property && strcmp(property, "enabled") == 0) {
    bool enabled =
        !(value && (strcmp(value, "0") == 0 || strcasecmp(value, "false") == 0));
    widget_set_enabled(widget, enabled);
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "option set: '%s' is not a widget property",
             property ? property : "");
    return 0;
  }
  return 1;
}

int rk_yab_option_set_number(const char *id, const char *property,
                             double value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || !widget->view) {
    snprintf(g_error, sizeof(g_error), "option set: '%s' is not a widget",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  bool ok = true;
  if (property && strcmp(property, "enabled") == 0) {
    widget_set_enabled(widget, value != 0.0);
  } else if (property && strcmp(property, "value") == 0) {
    char text[64];
    snprintf(text, sizeof(text), "%.10g", value);
    switch (widget->kind) {
    case wkTEXTCONTROL:
      ((BTextControl *)widget->view)->SetText(text);
      break;
    case wkTEXTEDIT:
      ((BTextView *)widget->view)->SetText(text);
      break;
    case wkSLIDER:
      ((BSlider *)widget->view)->SetValue((int32)value);
      break;
    case wkSPIN:
      ((YabSpinner *)widget->view)->SetValue(value);
      break;
    case wkSTATUSBAR:
      ((BStatusBar *)widget->view)->Update((float)value);
      break;
    case wkBUTTON:
    case wkCHECKBOX:
    case wkRADIO:
      ((BControl *)widget->view)->SetValue((int32)value);
      break;
    default:
      ok = false;
      break;
    }
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "option set: '%s' is not a widget property",
             property ? property : "");
    return 0;
  }
  return 1;
}

int rk_yab_option_colour(const char *id, const char *property, int r, int g,
                         int b) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || !widget->view) {
    snprintf(g_error, sizeof(g_error), "option colour: '%s' is not a widget",
             id ? id : "");
    return 0;
  }
  rgb_color colour = rgb_from(r, g, b);
  if (!lock_widget(widget)) {
    return 0;
  }
  bool ok = true;
  if (property && (strcmp(property, "bgcolor") == 0 ||
                   strcmp(property, "background") == 0)) {
    widget->view->SetViewColor(colour);
    widget->view->SetLowColor(colour);
    widget->view->Invalidate();
  } else if (property && strcmp(property, "highcolor") == 0) {
    widget->view->SetHighColor(colour);
  } else if (property && strcmp(property, "lowcolor") == 0) {
    widget->view->SetLowColor(colour);
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "option colour: '%s' is not a widget colour",
             property ? property : "");
    return 0;
  }
  return 1;
}

int rk_yab_tooltip(const char *id, const char *text) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || !widget->view) {
    snprintf(g_error, sizeof(g_error), "tooltip: '%s' is not a widget",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  widget->view->SetToolTip(text ? text : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_tabview(double x1, double y1, double x2, double y2, const char *id,
                   const char *side, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  BTabView *tabs = new BTabView(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", B_WIDTH_FROM_LABEL);
  if (side) {
    if (strcasecmp(side, "bottom") == 0) {
      tabs->SetTabSide(BTabView::kBottomSide);
    } else if (strcasecmp(side, "left") == 0) {
      tabs->SetTabSide(BTabView::kLeftSide);
    } else if (strcasecmp(side, "right") == 0) {
      tabs->SetTabSide(BTabView::kRightSide);
    } else {
      tabs->SetTabSide(BTabView::kTopSide);
    }
  }
  return finish_widget(window, wkTABVIEW, id, tabs, 0, NULL) ? 1 : 0;
}

int rk_yab_tab_add(const char *id, const char *label) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTABVIEW) {
    snprintf(g_error, sizeof(g_error), "tabview add: '%s' is not a tab view",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BTabView *tabs = (BTabView *)widget->view;
  BView *page = new BView(tabs->Bounds(), "page", B_FOLLOW_ALL, B_WILL_DRAW);
  BTab *tab = new BTab();
  tabs->AddTab(page, tab);
  tab->SetLabel(label ? label : "");
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_tab_set(const char *id, double index) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTABVIEW) {
    snprintf(g_error, sizeof(g_error), "tabview set: '%s' is not a tab view",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BTabView *tabs = (BTabView *)widget->view;
  int32 selected = (int32)index - 1;
  bool ok = selected >= 0 && selected < tabs->CountTabs();
  if (ok) {
    tabs->Select(selected);
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "tabview set: there is no tab %d",
             (int)index);
    return 0;
  }
  return 1;
}

int rk_yab_tab_remove(const char *id, double index) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkTABVIEW) {
    snprintf(g_error, sizeof(g_error), "tabview remove: '%s' is not a tab view",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BTabView *tabs = (BTabView *)widget->view;
  int32 selected = (int32)index - 1;
  if (selected < 0 || selected >= tabs->CountTabs()) {
    widget->window->window->Unlock();
    snprintf(g_error, sizeof(g_error), "tabview remove: there is no tab %d",
             (int)index);
    return 0;
  }
  /* RemoveTab() detaches the page from the container and returns the tab
     without deleting it; the tab owns the page, so deleting the tab deletes
     the page. Deleting the page a second time corrupts the heap (on Haiku a
     double free reaches debugger(), which blocks the process). */
  BTab *tab = tabs->RemoveTab(selected);
  delete tab;
  widget->window->window->Unlock();
  return 1;
}

int rk_yab_boxview(double x1, double y1, double x2, double y2, const char *id,
                   const char *label, int line_type, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  border_style border = B_FANCY_BORDER;
  if (line_type == 0) {
    border = B_NO_BORDER;
  } else if (line_type == 1) {
    border = B_PLAIN_BORDER;
  }
  BBox *box = new BBox(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", B_FOLLOW_LEFT_TOP, B_WILL_DRAW | B_FRAME_EVENTS, border);
  box->SetLabel(label ? label : "");
  return finish_widget(window, wkBOXVIEW, id, box, 0, NULL) ? 1 : 0;
}

int rk_yab_boxview_set(const char *id, const char *option, const char *value) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkBOXVIEW) {
    snprintf(g_error, sizeof(g_error), "boxview set: '%s' is not a box view",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BBox *box = (BBox *)widget->view;
  bool ok = true;
  if (option && strcmp(option, "label") == 0) {
    box->SetLabel(value ? value : "");
  } else if (option && strcmp(option, "line") == 0) {
    if (value && strcmp(value, "0") == 0) {
      box->SetBorder(B_NO_BORDER);
    } else if (value && strcmp(value, "1") == 0) {
      box->SetBorder(B_PLAIN_BORDER);
    } else {
      box->SetBorder(B_FANCY_BORDER);
    }
  } else {
    ok = false;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "boxview set: '%s' is not a box view option",
             option ? option : "");
    return 0;
  }
  return 1;
}

int rk_yab_splitview(double x1, double y1, double x2, double y2,
                     const char *id, int vertical, int style,
                     const char *view_name) {
  clear_error();
  if (!id || !*id) {
    set_error("splitview: a split view needs a name");
    return 0;
  }
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  float left = (float)x1 + dx;
  float top = (float)y1 + dy;
  float right = (float)x2 + dx;
  float bottom = (float)y2 + dy;
  float thickness = style ? 10.0f : 5.0f;
  float middle = vertical ? (left + right) / 2.0f : (top + bottom) / 2.0f;
  BRect first;
  BRect second;
  if (vertical) {
    first.Set(left, top, middle - thickness / 2.0f, bottom);
    second.Set(middle + thickness / 2.0f, top, right, bottom);
  } else {
    first.Set(left, top, right, middle - thickness / 2.0f);
    second.Set(left, middle + thickness / 2.0f, right, bottom);
  }
  char name[512];
  snprintf(name, sizeof(name), "%s1", id);
  if (!open_view_at(window, first.left, first.top, first.right, first.bottom,
                    name)) {
    return 0;
  }
  snprintf(name, sizeof(name), "%s2", id);
  if (!open_view_at(window, second.left, second.top, second.right,
                    second.bottom, name)) {
    return 0;
  }
  return refresh_window(window) ? 1 : 0;
}

int rk_yab_stackview(double x1, double y1, double x2, double y2,
                     const char *id, int pages, const char *view_name) {
  clear_error();
  if (!id || !*id) {
    set_error("stackview: a stack view needs a name");
    return 0;
  }
  if (pages < 1 || pages > 64) {
    set_error("stackview: the page count is out of range");
    return 0;
  }
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  if (!window) {
    return 0;
  }
  if (!finish_widget(window, wkSTACKVIEW, id, NULL, pages, NULL)) {
    return 0;
  }
  for (int i = 1; i <= pages; i++) {
    char name[512];
    snprintf(name, sizeof(name), "%s%d", id, i);
    YabView *page = open_view_at(window, (float)x1 + dx, (float)y1 + dy,
                                 (float)x2 + dx, (float)y2 + dy, name);
    if (!page) {
      return 0;
    }
    page->visible = i == 1;
  }
  return refresh_window(window) ? 1 : 0;
}

int rk_yab_stackview_set(const char *id, double index) {
  clear_error();
  YabWidget *widget = find_widget(id);
  if (!widget || widget->kind != wkSTACKVIEW) {
    snprintf(g_error, sizeof(g_error), "stackview set: '%s' is not a stack view",
             id ? id : "");
    return 0;
  }
  int selected = (int)index;
  if (selected < 1 || selected > widget->number) {
    snprintf(g_error, sizeof(g_error), "stackview set: there is no page %d",
             selected);
    return 0;
  }
  for (int i = 1; i <= widget->number; i++) {
    char name[512];
    snprintf(name, sizeof(name), "%s%d", id, i);
    YabView *page = find_view(name);
    if (page) {
      page->visible = i == selected;
    }
  }
  return refresh_window(widget->window) ? 1 : 0;
}

int rk_yab_canvas(double x1, double y1, double x2, double y2, const char *id,
                  const char *view_name) {
  clear_error();
  YabWindow *window = find_window(view_name);
  if (!window) {
    snprintf(g_error, sizeof(g_error), "canvas: window '%s' is not open",
             view_name ? view_name : "");
    return 0;
  }
  if (!open_view_at(window, x1, y1, x2, y2, id)) {
    return 0;
  }
  return refresh_window(window) ? 1 : 0;
}

int rk_yab_region(double x1, double y1, double x2, double y2, const char *id,
                  const char *view_name) {
  clear_error();
  YabWindow *window = find_window(view_name);
  if (!window) {
    snprintf(g_error, sizeof(g_error), "region: window '%s' is not open",
             view_name ? view_name : "");
    return 0;
  }
  if (!open_view_at(window, x1, y1, x2, y2, id)) {
    return 0;
  }
  return refresh_window(window) ? 1 : 0;
}

} // extern "C"
