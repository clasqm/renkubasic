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

#include <Alignment.h>
#include <Application.h>
#include <Bitmap.h>
#include <BitmapStream.h>
#include <Box.h>
#include <Button.h>
#include <CheckBox.h>
#include <Clipboard.h>
#include <ColorControl.h>
#include <File.h>
#include <Font.h>
#include <ListItem.h>
#include <ListView.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <Message.h>
#include <OutlineListView.h>
#include <PopUpMenu.h>
#include <RadioButton.h>
#include <ScrollBar.h>
#include <ScrollView.h>
#include <SeparatorItem.h>
#include <Slider.h>
#include <StatusBar.h>
#include <String.h>
#include <StringItem.h>
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
#include <time.h>

#include <vector>

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
  BView *menubar; /* the window's menu bar, created by the first `menu` */
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
  wkSCROLLBAR, wkLISTBOX, wkDROPBOX, wkTREEBOX, wkCOLUMNBOX, wkCALENDAR,
  wkCOLORCONTROL
};

struct YabWidget {
  char *name;
  YabWindow *window;
  YabWidgetKind kind;
  BView *view;   /* NULL for a container without a control */
  BView *extra;  /* the second scrollbar, when both were asked for */
  BView *outer;  /* what was attached when it wraps view: a BScrollView or a
                    container view. NULL when view itself was attached. */
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
   on any failure the caller still owns it and it is deleted here. `outer` is
   what goes into the window when it differs from the control itself (a scroll
   view around a list, a container around a column box); deleting it deletes
   the control inside it. `check_frame` is 0 for controls that size themselves
   from a corner, where the window clips rather than the command failing. */
bool finish_widget_ex(YabWindow *window, YabWidgetKind kind, const char *id,
                      BView *view, BView *outer, int number, int check_frame,
                      YabWidget **out) {
  BView *attached = outer ? outer : view;

  if (out) {
    *out = NULL;
  }
  if (!id || !*id) {
    set_error("a widget needs a name");
    if (outer) {
      delete outer;
    } else if (view) {
      delete view;
    }
    return false;
  }
  if (find_widget(id)) {
    snprintf(g_error, sizeof(g_error), "'%s' is already a widget", id);
    if (outer) {
      delete outer;
    } else if (view) {
      delete view;
    }
    return false;
  }
  if (attached) {
    BRect frame = attached->Frame();
    if (check_frame && (frame.Width() < 1.0f || frame.Height() < 1.0f ||
                        frame.right > window->width - 1.0f ||
                        frame.bottom > window->height - 1.0f)) {
      set_error("the widget does not fit into its window");
      if (outer) {
        delete outer;
      } else {
        delete view;
      }
      return false;
    }
    attached->SetResizingMode(window->resize_mode);
    if (!attach_widget(window, attached)) {
      if (outer) {
        delete outer;
      } else {
        delete view;
      }
      return false;
    }
  }

  YabWidget *widget = new YabWidget;
  widget->name = strdup(id);
  widget->window = window;
  widget->kind = kind;
  widget->view = view;
  widget->outer = outer;
  widget->extra = NULL;
  widget->number = number;
  widget->next = g_widgets;
  g_widgets = widget;
  if (out) {
    *out = widget;
  }
  return true;
}

bool finish_widget(YabWindow *window, YabWidgetKind kind, const char *id,
                   BView *view, int number, YabWidget **out) {
  return finish_widget_ex(window, kind, id, view, NULL, number, 1, out);
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

/* ---- the list family --------------------------------------------------- */

/* yab's column box (its "file box") is a table with titled columns. Haiku's
   BColumnListView is private API, so this is a small table of its own: a header
   view that draws the titles and a BListView whose items draw their cells.
   Column widths are fixed, and there is no horizontal scrolling. */

struct YabColumn {
  char *title;
  float width;
  alignment align;
};

class YabColumnList;
class YabColumnHeader;

class YabColumnList : public BListView {
public:
  YabColumnList(BRect frame, const char *name)
      : BListView(frame, name, B_SINGLE_SELECTION_LIST, B_FOLLOW_ALL,
                  B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE),
        fHeader(NULL), fText(rgb_from(0, 0, 0)),
        fBackground(rgb_from(255, 255, 255)),
        fSelection(rgb_from(195, 195, 195)),
        fSelectionText(rgb_from(0, 0, 0)), fDivider(rgb_from(160, 160, 160)) {
    SetViewColor(fBackground);
    SetLowColor(fBackground);
  }

  void SetHeader(YabColumnHeader *header) { fHeader = header; }
  void AddColumn(const char *title, float width, alignment align);
  void RemoveColumn(int index);
  int CountColumns() const { return (int)fColumns.size(); }
  const std::vector<YabColumn> &Columns() const { return fColumns; }
  /* x of a column inside the view, counting a one pixel divider per column */
  float ColumnOffset(int index) const;
  float TotalWidth() const { return ColumnOffset(CountColumns()); }

  rgb_color TextColour() const { return fText; }
  rgb_color BackgroundColour() const { return fBackground; }
  rgb_color SelectionColour() const { return fSelection; }
  rgb_color SelectionTextColour() const { return fSelectionText; }
  rgb_color DividerColour() const { return fDivider; }

  void SetTextColour(rgb_color colour) {
    fText = colour;
    Invalidate();
  }
  void SetBackgroundColour(rgb_color colour) {
    fBackground = colour;
    SetViewColor(colour);
    SetLowColor(colour);
    Invalidate();
  }
  void SetSelectionColour(rgb_color colour) {
    fSelection = colour;
    Invalidate();
  }
  void SetSelectionTextColour(rgb_color colour) {
    fSelectionText = colour;
    Invalidate();
  }
  void SetDividerColour(rgb_color colour) {
    fDivider = colour;
    Invalidate();
  }

private:
  std::vector<YabColumn> fColumns;
  YabColumnHeader *fHeader;
  rgb_color fText;
  rgb_color fBackground;
  rgb_color fSelection;
  rgb_color fSelectionText;
  rgb_color fDivider;
};

class YabColumnHeader : public BView {
public:
  YabColumnHeader(BRect frame, YabColumnList *list)
      : BView(frame, "rk-yab-column-header", B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW),
        fList(list) {
    SetViewColor(tint_color(ui_color(B_PANEL_BACKGROUND_COLOR), 1.04f));
  }

  void Draw(BRect update);

private:
  YabColumnList *fList;
};

class YabColumnRow : public BListItem {
public:
  YabColumnRow(float height) : BListItem() { SetHeight(height); }

  void SetCell(int column, const char *text) {
    if (column < 0) {
      return;
    }
    while ((int)fCells.size() <= column) {
      fCells.push_back(BString());
    }
    fCells[column] = text ? text : "";
  }

  const char *Cell(int column) const {
    if (column < 0 || column >= (int)fCells.size()) {
      return "";
    }
    return fCells[column].String();
  }

  void DrawItem(BView *owner, BRect frame, bool complete);

private:
  std::vector<BString> fCells;
};

void YabColumnList::AddColumn(const char *title, float width,
                              alignment align) {
  YabColumn column;

  column.title = strdup(title ? title : "");
  column.width = width > 8.0f ? width : 8.0f;
  column.align = align;
  fColumns.push_back(column);
  Invalidate();
  if (fHeader) {
    fHeader->Invalidate();
  }
}

void YabColumnList::RemoveColumn(int index) {
  if (index < 0 || index >= (int)fColumns.size()) {
    return;
  }
  free(fColumns[index].title);
  fColumns.erase(fColumns.begin() + index);
  for (int32 i = 0; i < CountItems(); i++) {
    YabColumnRow *row = dynamic_cast<YabColumnRow *>(ItemAt(i));
    if (row) {
      /* The cells move up with their columns; the last one is left empty. */
      for (int c = index; c < (int)fColumns.size(); c++) {
        row->SetCell(c, row->Cell(c + 1));
      }
    }
  }
  Invalidate();
  if (fHeader) {
    fHeader->Invalidate();
  }
}

float YabColumnList::ColumnOffset(int index) const {
  float x = 0.0f;

  for (int i = 0; i < index && i < (int)fColumns.size(); i++) {
    x += fColumns[i].width + 1.0f;
  }
  return x;
}

void YabColumnHeader::Draw(BRect update) {
  BRect bounds = Bounds();
  font_height height;

  SetHighColor(ViewColor());
  FillRect(update);
  GetFontHeight(&height);
  SetHighColor(0, 0, 0, 255);
  const std::vector<YabColumn> &columns = fList->Columns();
  for (size_t i = 0; i < columns.size(); i++) {
    float left = fList->ColumnOffset((int)i);
    if (left > bounds.right) {
      break;
    }
    BString title(columns[i].title);
    float text_width = StringWidth(title.String());
    float x = left + 4.0f;
    if (columns[i].align == B_ALIGN_CENTER) {
      x = left + (columns[i].width - text_width) / 2.0f;
    } else if (columns[i].align == B_ALIGN_RIGHT) {
      x = left + columns[i].width - text_width - 4.0f;
    }
    DrawString(title.String(), BPoint(x, height.ascent + 3.0f));
    SetHighColor(160, 160, 160, 255);
    StrokeLine(BPoint(left + columns[i].width, bounds.top),
               BPoint(left + columns[i].width, bounds.bottom));
    SetHighColor(0, 0, 0, 255);
  }
  SetHighColor(120, 120, 120, 255);
  StrokeLine(BPoint(bounds.left, bounds.bottom), BPoint(bounds.right, bounds.bottom));
}

void YabColumnRow::DrawItem(BView *owner, BRect frame, bool complete) {
  YabColumnList *list = dynamic_cast<YabColumnList *>(owner);

  if (!list) {
    /* BListItem declares DrawItem but libbe defines it only inside its own
       subclass, so there is no base implementation to fall back on: paint a
       plain row with the standard list colours instead. */
    (void)complete;
    owner->SetLowColor(ui_color(IsSelected()
                                    ? B_LIST_SELECTED_BACKGROUND_COLOR
                                    : B_LIST_BACKGROUND_COLOR));
    owner->FillRect(frame, B_SOLID_LOW);
    return;
  }

  rgb_color background =
      IsSelected() ? list->SelectionColour() : list->BackgroundColour();
  owner->SetLowColor(background);
  owner->FillRect(frame, B_SOLID_LOW);
  owner->SetHighColor(list->DividerColour());
  owner->StrokeLine(BPoint(frame.left, frame.bottom),
                    BPoint(frame.right, frame.bottom));
  owner->SetHighColor(IsSelected() ? list->SelectionTextColour()
                                  : list->TextColour());

  font_height height;
  owner->GetFontHeight(&height);
  const std::vector<YabColumn> &columns = list->Columns();
  for (size_t i = 0; i < columns.size(); i++) {
    const char *text = Cell((int)i);
    if (!text || !*text) {
      continue;
    }
    float left = list->ColumnOffset((int)i) + 4.0f;
    float width = columns[i].width - 8.0f;
    float text_width = owner->StringWidth(text);
    float x = left;

    if (width < 1.0f) {
      continue;
    }
    if (columns[i].align == B_ALIGN_CENTER) {
      x = left + (width - text_width) / 2.0f;
    } else if (columns[i].align == B_ALIGN_RIGHT) {
      x = left + width - text_width;
    }
    owner->DrawString(text, BPoint(x, frame.top + height.ascent + 2.0f));
  }
}

/* ---- the calendar control --------------------------------------------- */

/* yab's calendar is a date field in the program's format plus a month grid.
   The public Haiku kits have no calendar view, so the grid is drawn here: a
   title with two arrows, the weekday initials and six weeks of day numbers.
   Clicking a day (or editing the field) changes the date the program reads. */

struct YabDateValue {
  int day;
  int month;
  int year;
};

int yab_days_in_month(int year, int month) {
  static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month == 2) {
    bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    return leap ? 29 : 28;
  }
  if (month < 1 || month > 12) {
    return 30;
  }
  return days[month - 1];
}

int yab_weekday(int year, int month, int day) /* 0 = Sunday, 1 = Monday, ... */ {
  struct tm moment;

  memset(&moment, 0, sizeof(moment));
  moment.tm_year = year - 1900;
  moment.tm_mon = month - 1;
  moment.tm_mday = day;
  if (mktime(&moment) == (time_t)-1) {
    return 0;
  }
  return moment.tm_wday;
}

class YabCalendar : public BView {
public:
  YabCalendar(BRect frame, const char *name, const char *format,
              const char *date);

  void SetDateText(const char *date);
  const char *DateText() const {
    const char *text = fText ? fText->Text() : NULL;
    return text ? text : "";
  }
  void MessageReceived(BMessage *message);
  void Draw(BRect update);
  void MouseDown(BPoint where);

private:
  void ParseDate(const char *text);
  void FormatDate(char *buffer, size_t size) const;
  void SyncText();
  float TitleHeight() const { return 20.0f; }
  float CellHeight() const;
  float CellWidth() const;
  BRect DayCell(int row, int column) const;
  void ChangeMonth(int delta);

  int fYear;
  int fMonth;
  int fDay;
  int fOrder; /* 0 = day first, 1 = month first */
  char fDivider;
  bool fSyncing;
  BTextControl *fText;
};

YabCalendar::YabCalendar(BRect frame, const char *name, const char *format,
                         const char *date)
    : BView(frame, name, B_FOLLOW_NONE, B_WILL_DRAW),
      fYear(1970), fMonth(1), fDay(1), fOrder(0), fDivider('.') ,
      fSyncing(false), fText(NULL) {
  BString spec(format ? format : "");

  if (spec.FindFirst("/") != B_ERROR) {
    fDivider = '/';
  } else if (spec.FindFirst("-") != B_ERROR) {
    fDivider = '-';
  }
  if (spec.IFindFirst("MD") != B_ERROR) {
    fOrder = 1;
  }
  SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

  BRect field(0, 0, Bounds().Width(), 20);
  fText = new BTextControl(field, "rk-yab-calendar-date", "", "",
                           new BMessage('rkcd'));
  fText->SetDivider(0.0f);
  fText->SetModificationMessage(new BMessage('rkcd'));
  AddChild(fText);

  ParseDate(date);
  SyncText();
}

float YabCalendar::CellHeight() const {
  float available = Bounds().Height() - TitleHeight();

  return available > 1.0f ? available / 7.0f : 1.0f;
}

float YabCalendar::CellWidth() const {
  float width = Bounds().Width() / 7.0f;

  return width > 1.0f ? width : 1.0f;
}

BRect YabCalendar::DayCell(int row, int column) const {
  float cw = CellWidth();
  float ch = CellHeight();
  float top = TitleHeight() + (float)(row + 1) * ch;

  return BRect((float)column * cw, top, (float)(column + 1) * cw - 1.0f,
               top + ch - 1.0f);
}

void YabCalendar::ParseDate(const char *text) {
  BString value(text ? text : "");

  if (value.Length() >= 8) {
    int first = atoi(value.String());
    int second = atoi(value.String() + 3);
    int year = atoi(value.String() + 6);

    if (fOrder == 1) {
      fMonth = first;
      fDay = second;
    } else {
      fDay = first;
      fMonth = second;
    }
    if (year > 0) {
      fYear = year;
    }
  }
  if (fMonth < 1 || fMonth > 12) {
    fMonth = 1;
  }
  if (fDay < 1 || fDay > yab_days_in_month(fYear, fMonth)) {
    fDay = 1;
  }
}

void YabCalendar::FormatDate(char *buffer, size_t size) const {
  if (fOrder == 1) {
    snprintf(buffer, size, "%02d%c%02d%c%04d", fMonth, fDivider, fDay,
             fDivider, fYear);
  } else {
    snprintf(buffer, size, "%02d%c%02d%c%04d", fDay, fDivider, fMonth,
             fDivider, fYear);
  }
}

void YabCalendar::SyncText() {
  char date[32];

  FormatDate(date, sizeof(date));
  fSyncing = true;
  fText->SetText(date);
  fSyncing = false;
}

void YabCalendar::SetDateText(const char *date) {
  ParseDate(date);
  SyncText();
  Invalidate();
}

void YabCalendar::ChangeMonth(int delta) {
  fMonth += delta;
  while (fMonth > 12) {
    fMonth -= 12;
    fYear++;
  }
  while (fMonth < 1) {
    fMonth += 12;
    fYear--;
  }
  int days = yab_days_in_month(fYear, fMonth);
  if (fDay > days) {
    fDay = days;
  }
  SyncText();
  Invalidate();
}

void YabCalendar::MessageReceived(BMessage *message) {
  if (message->what == 'rkcd') {
    if (!fSyncing) {
      ParseDate(fText->Text());
      SyncText();
      Invalidate();
    }
    return;
  }
  BView::MessageReceived(message);
}

void YabCalendar::Draw(BRect update) {
  BRect bounds = Bounds();
  float cw = CellWidth();
  int first = yab_weekday(fYear, fMonth, 1);
  /* Monday first, as in yab's calendar. */
  int offset = (first + 6) % 7;
  static const char *initials[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
  static const char *months[12] = {"January", "February", "March", "April",
                                   "May", "June", "July", "August",
                                   "September", "October", "November",
                                   "December"};
  font_height height;
  char title[64];

  GetFontHeight(&height);
  SetHighColor(ViewColor());
  FillRect(BRect(0, TitleHeight(), bounds.right, bounds.bottom));

  /* title row: month and year, with the arrows on the right */
  snprintf(title, sizeof(title), "%s %d",
           months[(fMonth > 0 && fMonth <= 12) ? fMonth - 1 : 0], fYear);
  SetHighColor(0, 0, 0, 255);
  DrawString(title, BPoint(4.0f, TitleHeight() - 6.0f));
  DrawString("<", BPoint(bounds.right - 32.0f, TitleHeight() - 6.0f));
  DrawString(">", BPoint(bounds.right - 12.0f, TitleHeight() - 6.0f));

  SetHighColor(96, 96, 96, 255);
  for (int i = 0; i < 7; i++) {
    BRect cell = DayCell(-1, i);
    DrawString(initials[i], BPoint(cell.left + 2.0f,
                                   cell.top + height.ascent + 1.0f));
  }

  int days = yab_days_in_month(fYear, fMonth);
  for (int day = 1; day <= days; day++) {
    int slot = offset + day - 1;
    int row = slot / 7;
    int column = slot % 7;

    if (row > 5) {
      break;
    }
    BRect cell = DayCell(row, column);
    char number[8];

    snprintf(number, sizeof(number), "%d", day);
    if (day == fDay) {
      BRect highlight = cell;
      highlight.InsetBySelf(1.0f, 1.0f);
      SetHighColor(90, 130, 200, 255);
      FillRect(highlight);
      SetHighColor(255, 255, 255, 255);
    } else {
      SetHighColor(0, 0, 0, 255);
    }
    float text_width = StringWidth(number);
    DrawString(number, BPoint(cell.left + (cw - text_width) / 2.0f,
                              cell.top + height.ascent + 1.0f));
  }

  SetHighColor(200, 200, 200, 255);
  StrokeRect(BRect(0, TitleHeight(), bounds.right, bounds.bottom));
}

void YabCalendar::MouseDown(BPoint where) {
  float ch = CellHeight();

  if (where.y < TitleHeight()) {
    return;
  }
  if (where.y < TitleHeight() + ch) {
    if (where.x > Bounds().right - 24.0f) {
      ChangeMonth(1);
    } else if (where.x > Bounds().right - 44.0f) {
      ChangeMonth(-1);
    }
    return;
  }

  int row = (int)((where.y - TitleHeight()) / ch) - 1;
  int column = (int)(where.x / CellWidth());
  int first = yab_weekday(fYear, fMonth, 1);
  int offset = (first + 6) % 7;
  int day = row * 7 + column - offset + 1;

  if (row < 0 || row > 5 || column < 0 || column > 6) {
    return;
  }
  if (day < 1 || day > yab_days_in_month(fYear, fMonth)) {
    return;
  }
  fDay = day;
  SyncText();
  Invalidate();
}

/* ---- list family helpers ---------------------------------------------- */

/* The list boxes, drop boxes, tree boxes and column boxes share their item
   commands, so one lookup covers all four and the caller switches on the kind.
   "get" and "sort" name the missing command in the error. */
YabWidget *find_list_widget(const char *id, const char *command) {
  YabWidget *widget = find_widget(id);

  if (!widget) {
    snprintf(g_error, sizeof(g_error), "%s: '%s' is not open", command,
             id ? id : "");
    return NULL;
  }
  if (widget->kind != wkLISTBOX && widget->kind != wkDROPBOX &&
      widget->kind != wkTREEBOX && widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error), "%s: '%s' is not a list control",
             command, id ? id : "");
    return NULL;
  }
  return widget;
}

BMenu *dropbox_menu(YabWidget *widget) {
  BMenuField *field = dynamic_cast<BMenuField *>(widget->view);

  return field ? field->Menu() : NULL;
}

YabColumnList *column_list(YabWidget *widget) {
  return dynamic_cast<YabColumnList *>(widget->view);
}

/* Two sort comparators, because BListView::SortItems takes void pointers and
   BOutlineListView::FullListSortItems takes BListItem pointers. Both sort by
   text, ignoring case, as yab's compare does; a tree also keeps each level on
   its own, so children never jump over a parent. */
int compare_list_items(const void *first, const void *second) {
  const BStringItem *a = *(const BStringItem *const *)first;
  const BStringItem *b = *(const BStringItem *const *)second;

  if (!a || !b) {
    return 0;
  }
  return strcasecmp(a->Text(), b->Text());
}

int compare_tree_items(const BListItem *first, const BListItem *second) {
  const BStringItem *a = dynamic_cast<const BStringItem *>(first);
  const BStringItem *b = dynamic_cast<const BStringItem *>(second);

  if (!a || !b) {
    return 0;
  }
  if (a->OutlineLevel() != b->OutlineLevel()) {
    return 0;
  }
  return strcasecmp(a->Text(), b->Text());
}

/* BScrollView around a list: yab's `scrollbar` argument, 0 none, 1 vertical,
   2 horizontal, 3 both. The list is shrunk first so the bars fit inside the
   rectangle the program asked for. */
BView *wrap_list_in_scroll(BListView *list, int bars) {
  if (bars <= 0) {
    return NULL;
  }
  BRect frame = list->Frame();

  if (bars == 1 || bars == 3) {
    frame.right -= B_V_SCROLL_BAR_WIDTH;
    list->ResizeTo(frame.Width() + 1.0f, list->Bounds().Height());
  }
  if (bars == 2 || bars == 3) {
    frame.bottom -= B_H_SCROLL_BAR_HEIGHT;
    list->ResizeTo(list->Bounds().Width(), frame.Height() + 1.0f);
  }
  return new BScrollView("rk-yab-scroll", list, B_FOLLOW_NONE,
                         B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE, bars == 2 || bars == 3,
                         bars != 2);
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
  entry->menubar = NULL;
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

/* ---- list family ------------------------------------------------------- */

int rk_yab_listbox(double x1, double y1, double x2, double y2,
                   const char *id, int bars, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);

  if (!window) {
    return 0;
  }
  BListView *list = new BListView(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", B_SINGLE_SELECTION_LIST, B_FOLLOW_NONE,
      B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_NAVIGABLE);
  list->SetSelectionMessage(new BMessage('rkls'));
  BView *scroll = wrap_list_in_scroll(list, bars);

  return finish_widget_ex(window, wkLISTBOX, id, list, scroll, 0, 1, NULL) ? 1
                                                                        : 0;
}

int rk_yab_dropbox(double x1, double y1, double x2, double y2, const char *id,
                   const char *label, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);

  if (!window) {
    return 0;
  }
  BPopUpMenu *menu = new BPopUpMenu("");
  BMenuField *field = new BMenuField(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", label ? label : "", menu, true);

  return finish_widget(window, wkDROPBOX, id, field, 0, NULL) ? 1 : 0;
}

int rk_yab_treebox(double x1, double y1, double x2, double y2, const char *id,
                   int bars, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);

  if (!window) {
    return 0;
  }
  BOutlineListView *tree = new BOutlineListView(
      BRect((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy),
      id ? id : "", B_SINGLE_SELECTION_LIST, B_FOLLOW_NONE,
      B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_NAVIGABLE);
  tree->SetSelectionMessage(new BMessage('rkts'));
  BView *scroll = wrap_list_in_scroll(tree, bars);

  return finish_widget_ex(window, wkTREEBOX, id, tree, scroll, 0, 1, NULL) ? 1
                                                                        : 0;
}

int rk_yab_columnbox(double x1, double y1, double x2, double y2,
                     const char *id, int bars, const char *options,
                     const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BRect frame((float)x1 + dx, (float)y1 + dy, (float)x2 + dx, (float)y2 + dy);
  const float header_height = 19.0f;

  (void)bars;    /* the table scrolls vertically inside its own list */
  (void)options; /* "no-border"/"no-sorting" only affect yab's own table */
  if (!window) {
    return 0;
  }
  YabColumnList *list = new YabColumnList(
      BRect(0, header_height + 1.0f, frame.Width(), frame.Height()),
      "rk-yab-columns");
  YabColumnHeader *header =
      new YabColumnHeader(BRect(0, 0, frame.Width(), header_height), list);
  BView *box = new BView(frame, "rk-yab-columnbox", B_FOLLOW_NONE, B_WILL_DRAW);

  list->SetHeader(header);
  list->SetSelectionMessage(new BMessage('rkcs'));
  box->AddChild(header);
  box->AddChild(list);
  return finish_widget_ex(window, wkCOLUMNBOX, id, list, box, 0, 1, NULL) ? 1
                                                                       : 0;
}

int rk_yab_list_add(const char *id, const char *item) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "add");
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX:
  case wkTREEBOX:
    ((BListView *)widget->view)->AddItem(new BStringItem(item ? item : ""));
    ok = 1;
    break;
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    if (menu) {
      if (item && strcmp(item, "--") == 0) {
        menu->AddItem(new BSeparatorItem());
        ok = 1;
      } else {
        BMenuItem *entry = new BMenuItem(item ? item : "", new BMessage('rkdb'));
        menu->AddItem(entry);
        if (menu->CountItems() == 1) {
          entry->SetMarked(true);
        }
        ok = 1;
      }
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "add: '%s' cannot take items",
             id ? id : "");
    return 0;
  }
  return 1;
}

int rk_yab_list_add_at(const char *id, double position, const char *item) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "add");
  int32 index = (int32)position - 1;
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  if (index < 0) {
    index = 0;
  }
  switch (widget->kind) {
  case wkLISTBOX:
  case wkTREEBOX: {
    BListView *list = (BListView *)widget->view;
    BStringItem *entry = new BStringItem(item ? item : "");
    if (index >= list->CountItems()) {
      list->AddItem(entry);
    } else {
      /* A tree keeps the outline level of the item it is inserted before. */
      BOutlineListView *tree = dynamic_cast<BOutlineListView *>(list);
      if (tree) {
        BListItem *before = tree->FullListItemAt(index);
        if (before) {
          entry->SetOutlineLevel(before->OutlineLevel());
        }
      }
      list->AddItem(entry, index);
    }
    ok = 1;
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "add: '%s' takes no position",
             id ? id : "");
    return 0;
  }
  return 1;
}

int rk_yab_list_remove(const char *id, const char *item) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "remove");
  const char *text = item ? item : "";
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    BListView *list = (BListView *)widget->view;
    for (int32 i = 0; i < list->CountItems() && !ok; i++) {
      BStringItem *entry = dynamic_cast<BStringItem *>(list->ItemAt(i));
      if (entry && strcmp(entry->Text(), text) == 0) {
        delete list->RemoveItem(i);
        ok = 1;
      }
    }
    break;
  }
  case wkTREEBOX: {
    BOutlineListView *tree = (BOutlineListView *)widget->view;
    for (int32 i = 0; i < tree->FullListCountItems() && !ok; i++) {
      BStringItem *entry =
          dynamic_cast<BStringItem *>(tree->FullListItemAt(i));
      if (entry && strcmp(entry->Text(), text) == 0) {
        tree->RemoveItem(entry);
        delete entry;
        ok = 1;
      }
    }
    break;
  }
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    for (int32 i = 0; menu && i < menu->CountItems() && !ok; i++) {
      BMenuItem *entry = menu->ItemAt(i);
      if (entry && entry->Label() && strcmp(entry->Label(), text) == 0) {
        delete menu->RemoveItem(i);
        ok = 1;
      }
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "remove: '%s' has no item '%s'",
             id ? id : "", text);
    return 0;
  }
  return 1;
}

int rk_yab_list_remove_at(const char *id, double position) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "remove");
  int32 index = (int32)position - 1;
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    BListView *list = (BListView *)widget->view;
    if (index >= 0 && index < list->CountItems()) {
      delete list->RemoveItem(index);
      ok = 1;
    }
    break;
  }
  case wkTREEBOX: {
    BOutlineListView *tree = (BOutlineListView *)widget->view;
    BListItem *entry =
        index >= 0 ? tree->FullListItemAt(index) : (BListItem *)NULL;
    if (entry) {
      tree->RemoveItem(entry);
      delete entry;
      ok = 1;
    }
    break;
  }
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    if (menu && index >= 0 && index < menu->CountItems()) {
      delete menu->RemoveItem(index);
      ok = 1;
    }
    break;
  }
  case wkCOLUMNBOX: {
    YabColumnList *list = column_list(widget);
    if (list && index >= 0 && index < list->CountItems()) {
      delete list->RemoveItem(index);
      list->Invalidate();
      ok = 1;
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "remove: '%s' has no item %d",
             id ? id : "", (int)position);
    return 0;
  }
  return 1;
}

int rk_yab_list_select(const char *id, double position) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "select");
  int32 index = (int32)position - 1;
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    BListView *list = (BListView *)widget->view;
    if (index < 0) {
      list->DeselectAll();
      ok = 1;
    } else if (index < list->CountItems()) {
      list->Select(index);
      list->ScrollToSelection();
      ok = 1;
    }
    break;
  }
  case wkTREEBOX: {
    BOutlineListView *tree = (BOutlineListView *)widget->view;
    if (index < 0) {
      tree->DeselectAll();
      ok = 1;
    } else {
      BListItem *entry = tree->FullListItemAt(index);
      if (entry) {
        tree->DeselectAll();
        entry->Select();
        tree->ScrollTo(tree->FullListIndexOf(entry));
        ok = 1;
      }
    }
    break;
  }
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    for (int32 i = 0; menu && i < menu->CountItems(); i++) {
      BMenuItem *entry = menu->ItemAt(i);
      if (entry) {
        entry->SetMarked(i == index);
      }
    }
    ok = menu != NULL && menu->CountItems() > 0;
    break;
  }
  case wkCOLUMNBOX: {
    YabColumnList *list = column_list(widget);
    if (list) {
      if (index < 0) {
        list->DeselectAll();
        ok = 1;
      } else {
        if (index < list->CountItems()) {
          list->Select(index);
          list->ScrollToSelection();
          ok = 1;
        }
      }
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "select: '%s' has no item %d",
             id ? id : "", (int)position);
    return 0;
  }
  return 1;
}

int rk_yab_list_clear(const char *id) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "clear");
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    BListView *list = (BListView *)widget->view;
    while (list->CountItems() > 0) {
      delete list->RemoveItem((int32)0);
    }
    ok = 1;
    break;
  }
  case wkTREEBOX:
    ((BOutlineListView *)widget->view)->MakeEmpty();
    ok = 1;
    break;
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    while (menu && menu->CountItems() > 0) {
      delete menu->RemoveItem((int32)0);
    }
    ok = menu != NULL;
    break;
  }
  case wkCOLUMNBOX: {
    YabColumnList *list = column_list(widget);
    while (list && list->CountItems() > 0) {
      delete list->RemoveItem((int32)0);
    }
    if (list) {
      list->Invalidate();
      ok = 1;
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "clear: '%s' cannot be cleared",
             id ? id : "");
    return 0;
  }
  return 1;
}

int rk_yab_list_sort(const char *id) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "sort");
  int ok = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX:
    ((BListView *)widget->view)->SortItems(compare_list_items);
    ok = 1;
    break;
  case wkTREEBOX:
    ((BOutlineListView *)widget->view)->FullListSortItems(compare_tree_items);
    ok = 1;
    break;
  default:
    break;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "sort: '%s' cannot be sorted",
             id ? id : "");
    return 0;
  }
  return 1;
}

int rk_yab_list_count(const char *id) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "count");
  int count = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX:
    count = (int)((BListView *)widget->view)->CountItems();
    break;
  case wkTREEBOX:
    count = (int)((BOutlineListView *)widget->view)->FullListCountItems();
    break;
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    count = menu ? (int)menu->CountItems() : 0;
    break;
  }
  case wkCOLUMNBOX: {
    YabColumnList *list = column_list(widget);
    count = list ? (int)list->CountItems() : 0;
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  return count;
}

const char *rk_yab_list_get(const char *id, double position) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "get");
  int32 index = (int32)position - 1;
  const char *result = "";

  if (!widget || !lock_widget(widget)) {
    return "";
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    BStringItem *entry = dynamic_cast<BStringItem *>(
        ((BListView *)widget->view)->ItemAt(index));
    if (entry) {
      result = entry->Text();
    }
    break;
  }
  case wkTREEBOX: {
    BStringItem *entry = dynamic_cast<BStringItem *>(
        ((BOutlineListView *)widget->view)->FullListItemAt(index));
    if (entry) {
      result = entry->Text();
    }
    break;
  }
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    BMenuItem *entry = menu ? menu->ItemAt(index) : NULL;
    if (entry) {
      result = entry->Label();
    }
    break;
  }
  default:
    break;
  }
  /* Copy before unlocking: the control may change its items at any time. */
  static char text[1024];
  bool found = result && *result;

  snprintf(text, sizeof(text), "%s", result ? result : "");
  widget->window->window->Unlock();
  if (!found) {
    snprintf(g_error, sizeof(g_error), "get: '%s' has no item %d", id ? id : "",
             (int)position);
    return "";
  }
  return text;
}

int rk_yab_list_selected(const char *id) {
  clear_error();
  YabWidget *widget = find_list_widget(id, "get");
  int selected = 0;

  if (!widget || !lock_widget(widget)) {
    return 0;
  }
  switch (widget->kind) {
  case wkLISTBOX: {
    int32 index = ((BListView *)widget->view)->CurrentSelection();
    selected = index >= 0 ? (int)index + 1 : 0;
    break;
  }
  case wkTREEBOX: {
    int32 index = ((BOutlineListView *)widget->view)->FullListCurrentSelection();
    selected = index >= 0 ? (int)index + 1 : 0;
    break;
  }
  case wkDROPBOX: {
    BMenu *menu = dropbox_menu(widget);
    int32 index = menu ? menu->IndexOf(menu->FindMarked()) : -1;
    selected = index >= 0 ? (int)index + 1 : 0;
    break;
  }
  case wkCOLUMNBOX: {
    YabColumnList *list = column_list(widget);
    for (int32 i = 0; list && i < list->CountItems(); i++) {
      if (list->ItemAt(i) && list->ItemAt(i)->IsSelected()) {
        selected = (int)i + 1;
        break;
      }
    }
    break;
  }
  default:
    break;
  }
  widget->window->window->Unlock();
  return selected;
}

int rk_yab_tree_add_child(const char *id, const char *parent,
                          const char *item, int expanded) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkTREEBOX) {
    snprintf(g_error, sizeof(g_error),
             "treebox add: '%s' is not a tree box", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BOutlineListView *tree = (BOutlineListView *)widget->view;
  for (int32 i = 0; i < tree->FullListCountItems() && !ok; i++) {
    BStringItem *head = dynamic_cast<BStringItem *>(tree->FullListItemAt(i));
    if (head && strcmp(head->Text(), parent ? parent : "") == 0) {
      int32 level = (int32)head->OutlineLevel() + 1;
      int32 under = tree->CountItemsUnder(head, false);
      BStringItem *child = new BStringItem(item ? item : "", level);

      tree->AddItem(child, i + under + 1);
      if (!expanded) {
        tree->Collapse(head);
      }
      ok = 1;
    }
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "treebox add: '%s' has no item '%s'",
             id ? id : "", parent ? parent : "");
    return 0;
  }
  return 1;
}

int rk_yab_tree_remove_child(const char *id, const char *parent,
                             const char *item) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkTREEBOX) {
    snprintf(g_error, sizeof(g_error),
             "treebox remove: '%s' is not a tree box", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BOutlineListView *tree = (BOutlineListView *)widget->view;
  for (int32 i = 0; i < tree->FullListCountItems() && !ok; i++) {
    BStringItem *head = dynamic_cast<BStringItem *>(tree->FullListItemAt(i));
    if (!head || strcmp(head->Text(), parent ? parent : "") != 0) {
      continue;
    }
    int32 under = tree->CountItemsUnder(head, false);
    for (int32 j = 1; j <= under && !ok; j++) {
      BStringItem *child =
          dynamic_cast<BStringItem *>(tree->FullListItemAt(i + j));
      if (child && strcmp(child->Text(), item ? item : "") == 0) {
        tree->RemoveItem(child);
        delete child;
        ok = 1;
      }
    }
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "treebox remove: '%s' has no child '%s' under '%s'", id ? id : "",
             item ? item : "", parent ? parent : "");
    return 0;
  }
  return 1;
}

int rk_yab_tree_expand(const char *id, const char *item, int expand) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkTREEBOX) {
    snprintf(g_error, sizeof(g_error),
             "treebox: '%s' is not a tree box", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BOutlineListView *tree = (BOutlineListView *)widget->view;
  for (int32 i = 0; i < tree->FullListCountItems() && !ok; i++) {
    BStringItem *head = dynamic_cast<BStringItem *>(tree->FullListItemAt(i));
    if (head && strcmp(head->Text(), item ? item : "") == 0) {
      if (expand) {
        tree->Expand(head);
      } else {
        tree->Collapse(head);
      }
      ok = 1;
    }
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "treebox: '%s' has no item '%s'",
             id ? id : "", item ? item : "");
    return 0;
  }
  return 1;
}

int rk_yab_columnbox_column(const char *id, const char *title,
                            double position, double maximum, double minimum,
                            double width, const char *options) {
  clear_error();
  YabWidget *widget = find_widget(id);
  alignment align = B_ALIGN_LEFT;

  (void)maximum;
  (void)minimum;
  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox column: '%s' is not a column box", id ? id : "");
    return 0;
  }
  if (options) {
    if (strstr(options, "center")) {
      align = B_ALIGN_CENTER;
    } else if (strstr(options, "right")) {
      align = B_ALIGN_RIGHT;
    }
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabColumnList *list = column_list(widget);

  (void)position; /* a column is added to the right, as yab's table does */
  if (list) {
    list->AddColumn(title, (float)width, align);
  }
  widget->window->window->Unlock();
  return list ? 1 : 0;
}

int rk_yab_columnbox_add(const char *id, double column, double position,
                         double height, const char *text) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox add: '%s' is not a column box", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabColumnList *list = column_list(widget);
  int32 index = (int32)position - 1;
  int32 cell = (int32)column - 1;

  if (list && index >= 0 && cell >= 0) {
    YabColumnRow *row = dynamic_cast<YabColumnRow *>(list->ItemAt(index));
    if (!row) {
      row = new YabColumnRow(height > 1.0 ? (float)height : 20.0f);
      list->AddItem(row, index);
    }
    row->SetCell((int)cell, text);
    list->Invalidate();
    ok = 1;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "columnbox add: '%s' has no column %d at row %d", id ? id : "",
             (int)column, (int)position);
    return 0;
  }
  return 1;
}

int rk_yab_columnbox_remove(const char *id, double position) {
  return rk_yab_list_remove_at(id, position);
}

int rk_yab_columnbox_remove_column(const char *id, double position) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox remove column: '%s' is not a column box",
             id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabColumnList *list = column_list(widget);
  int32 index = (int32)position - 1;

  if (list && index >= 0 && index < list->CountColumns()) {
    list->RemoveColumn(index);
    ok = 1;
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "columnbox remove column: '%s' has no column %d", id ? id : "",
             (int)position);
    return 0;
  }
  return 1;
}

int rk_yab_columnbox_select(const char *id, double position) {
  return rk_yab_list_select(id, position);
}

int rk_yab_columnbox_clear(const char *id) {
  return rk_yab_list_clear(id);
}

int rk_yab_columnbox_colour(const char *id, const char *option, int r, int g,
                            int b) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int ok = 0;

  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox colour: '%s' is not a column box", id ? id : "");
    return 0;
  }
  if (!option) {
    set_error("columnbox colour: an option is needed");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabColumnList *list = column_list(widget);

  if (list) {
    /* yab matches these case-insensitively anywhere in the string and in this
       order, so its examples' "Selection-Active" and "Row-Divider" work too. */
    BString opt(option);
    if (opt.IFindFirst("selection-text") >= 0) {
      list->SetSelectionTextColour(rgb_from(r, g, b));
      ok = 1;
    } else if (opt.IFindFirst("non-focus-selection") >= 0 ||
               opt.IFindFirst("selection") >= 0) {
      list->SetSelectionColour(rgb_from(r, g, b));
      ok = 1;
    } else if (opt.IFindFirst("text") >= 0) {
      list->SetTextColour(rgb_from(r, g, b));
      ok = 1;
    } else if (opt.IFindFirst("row-divider") >= 0) {
      list->SetDividerColour(rgb_from(r, g, b));
      ok = 1;
    } else if (opt.IFindFirst("background") >= 0) {
      list->SetBackgroundColour(rgb_from(r, g, b));
      ok = 1;
    }
  }
  widget->window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "columnbox colour: '%s' is not a colour option", option);
    return 0;
  }
  return 1;
}

int rk_yab_columnbox_columns(const char *id) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int count = 0;

  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox count: '%s' is not a column box", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabColumnList *list = column_list(widget);
  count = list ? list->CountColumns() : 0;
  widget->window->window->Unlock();
  return count;
}

const char *rk_yab_columnbox_get(const char *id, double column,
                                 double position) {
  clear_error();
  YabWidget *widget = find_widget(id);
  static char text[1024];

  text[0] = '\0';
  if (!widget || widget->kind != wkCOLUMNBOX) {
    snprintf(g_error, sizeof(g_error),
             "columnbox get: '%s' is not a column box", id ? id : "");
    return text;
  }
  if (!lock_widget(widget)) {
    return text;
  }
  YabColumnList *list = column_list(widget);
  YabColumnRow *row =
      list ? dynamic_cast<YabColumnRow *>(list->ItemAt((int32)position - 1))
           : NULL;

  if (row) {
    snprintf(text, sizeof(text), "%s", row->Cell((int)column - 1));
  } else {
    snprintf(g_error, sizeof(g_error),
             "columnbox get: '%s' has no row %d", id ? id : "",
             (int)position);
  }
  widget->window->window->Unlock();
  return text;
}

int rk_yab_calendar(double x, double y, const char *id, const char *format,
                    const char *date, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);

  if (!window) {
    return 0;
  }
  YabCalendar *calendar = new YabCalendar(
      BRect((float)x + dx, (float)y + dy, (float)x + dx + 210.0f,
            (float)y + dy + 190.0f),
      id ? id : "", format, date);

  return finish_widget(window, wkCALENDAR, id, calendar, 0, NULL) ? 1 : 0;
}

int rk_yab_calendar_set(const char *id, const char *date) {
  clear_error();
  YabWidget *widget = find_widget(id);

  if (!widget || widget->kind != wkCALENDAR) {
    snprintf(g_error, sizeof(g_error),
             "calendar set: '%s' is not a calendar", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  YabCalendar *calendar = dynamic_cast<YabCalendar *>(widget->view);

  if (calendar) {
    calendar->SetDateText(date);
  }
  widget->window->window->Unlock();
  return calendar ? 1 : 0;
}

const char *rk_yab_calendar_get(const char *id) {
  clear_error();
  YabWidget *widget = find_widget(id);
  static char text[64];

  text[0] = '\0';
  if (!widget || widget->kind != wkCALENDAR) {
    snprintf(g_error, sizeof(g_error),
             "calendar get: '%s' is not a calendar", id ? id : "");
    return text;
  }
  if (!lock_widget(widget)) {
    return text;
  }
  YabCalendar *calendar = dynamic_cast<YabCalendar *>(widget->view);

  if (calendar) {
    snprintf(text, sizeof(text), "%s", calendar->DateText());
  }
  widget->window->window->Unlock();
  return text;
}

int rk_yab_colorcontrol(double x, double y, const char *id,
                        const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);

  if (!window) {
    return 0;
  }
  BColorControl *control = new BColorControl(
      BPoint((float)x + dx, (float)y + dy), B_CELLS_32x8, 2, id ? id : "",
      new BMessage('rkcc'), false);

  /* The control sizes itself from its corner, so the window clips it rather
     than the command failing when it reaches past the window edge. */
  return finish_widget_ex(window, wkCOLORCONTROL, id, control, NULL, 0, 0,
                          NULL)
             ? 1
             : 0;
}

int rk_yab_colorcontrol_set(const char *id, int r, int g, int b) {
  clear_error();
  YabWidget *widget = find_widget(id);

  if (!widget || widget->kind != wkCOLORCONTROL) {
    snprintf(g_error, sizeof(g_error),
             "colorcontrol set: '%s' is not a colour control", id ? id : "");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BColorControl *control = dynamic_cast<BColorControl *>(widget->view);

  if (control) {
    control->SetValue(rgb_from(r, g, b));
  }
  widget->window->window->Unlock();
  return control ? 1 : 0;
}

int rk_yab_colorcontrol_get(const char *id, const char *option) {
  clear_error();
  YabWidget *widget = find_widget(id);
  int value = -1;

  if (!widget || widget->kind != wkCOLORCONTROL) {
    snprintf(g_error, sizeof(g_error),
             "colorcontrol get: '%s' is not a colour control", id ? id : "");
    return 0;
  }
  if (!option) {
    set_error("colorcontrol get: an option is needed");
    return 0;
  }
  if (!lock_widget(widget)) {
    return 0;
  }
  BColorControl *control = dynamic_cast<BColorControl *>(widget->view);

  if (control) {
    rgb_color colour = control->ValueAsColor();

    if (strcasecmp(option, "red") == 0) {
      value = colour.red;
    } else if (strcasecmp(option, "green") == 0) {
      value = colour.green;
    } else if (strcasecmp(option, "blue") == 0) {
      value = colour.blue;
    }
  }
  widget->window->window->Unlock();
  if (value < 0) {
    snprintf(g_error, sizeof(g_error),
             "colorcontrol get: '%s' is not a colour option", option);
    return 0;
  }
  return value;
}

/* ---- menus ------------------------------------------------------------- */

/* yab keeps one menu bar per window, named "menubar", inside the view its menu
   commands name. RenkuBASIC keeps one per window as well, at the top of the
   window's display view, and creates it with the first menu command. The
   caller holds the window lock, because every menu command changes the bar. */
BMenuBar *window_menubar(YabWindow *window) {
  BMenuBar *bar;

  if (!window) {
    set_error("menu: the window is not open");
    return NULL;
  }
  if (window->menubar) {
    return (BMenuBar *)window->menubar;
  }
  bar = new BMenuBar(BRect(0.0f, 0.0f, window->width - 1.0f, 0.0f), "menubar");
  bar->SetResizingMode(B_FOLLOW_LEFT_RIGHT | B_FOLLOW_TOP);
  window->display->AddChild(bar);
  bar->ResizeToPreferred();
  bar->ResizeTo(window->width - 1.0f, bar->Bounds().Height());
  window->menubar = bar;
  return bar;
}

BMenuItem *find_menu_item(BMenu *menu, const char *label) {
  for (int32 i = 0; menu && i < menu->CountItems(); i++) {
    BMenuItem *item = menu->ItemAt(i);
    if (item && item->Label() && label && strcmp(item->Label(), label) == 0) {
      return item;
    }
  }
  return NULL;
}

/* The named submenu, created on first use. A plain item with that label is
   replaced by the submenu, which is what yab's SubMenu does. */
BMenu *ensure_menu(BMenu *parent, const char *label) {
  int32 index = -1;
  BMenu *menu;

  if (!parent) {
    set_error("menu: the menu bar is gone");
    return NULL;
  }
  for (int32 i = 0; i < parent->CountItems(); i++) {
    BMenuItem *item = parent->ItemAt(i);
    if (item && item->Label() && label && strcmp(item->Label(), label) == 0) {
      if (item->Submenu()) {
        return item->Submenu();
      }
      index = i;
      break;
    }
  }
  menu = new BMenu(label ? label : "");
  if (index >= 0) {
    BMenuItem *plain = parent->RemoveItem(index);
    delete plain;
    parent->AddItem(menu, index);
  } else {
    parent->AddItem(menu);
  }
  return menu;
}

/* yab's shortcut string: the last character is the key, and an `s`, `c` or `o`
   before it adds shift, control or option (case-insensitively, as yab's
   BString::IFindFirst does). */
void apply_shortcut(BMenuItem *item, const char *shortcut) {
  uint32 modifiers = 0;
  char key;

  if (!item || !shortcut || !*shortcut) {
    return;
  }
  BString spec(shortcut);
  if (spec.Length() > 1) {
    key = shortcut[spec.Length() - 1];
    if (spec.IFindFirst("s") >= 0 && spec.IFindFirst("s") < spec.Length() - 1) {
      modifiers |= B_SHIFT_KEY;
    }
    if (spec.IFindFirst("c") >= 0 && spec.IFindFirst("c") < spec.Length() - 1) {
      modifiers |= B_CONTROL_KEY;
    }
    if (spec.IFindFirst("o") >= 0 && spec.IFindFirst("o") < spec.Length() - 1) {
      modifiers |= B_OPTION_KEY;
    }
  } else {
    key = shortcut[0];
  }
  item->SetShortcut(key, modifiers);
}

/* 0 disable, 1 enable, 2 mark, 3 plain, 4 remove, -1 unknown; yab tests the
   options in this order and the last one that matches wins. */
int menu_action(const char *option) {
  BString text(option ? option : "");
  int action = -1;

  if (text.IFindFirst("disable") >= 0) action = 0;
  if (text.IFindFirst("enable") >= 0) action = 1;
  if (text.IFindFirst("mark") >= 0) action = 2;
  if (text.IFindFirst("plain") >= 0) action = 3;
  if (text.IFindFirst("remove") >= 0) action = 4;
  return action;
}

int apply_menu_action(BMenu *menu, BMenuItem *item, int action) {
  switch (action) {
    case 0:
      item->SetEnabled(false);
      return 1;
    case 1:
      item->SetEnabled(true);
      return 1;
    case 2:
      item->SetMarked(true);
      return 1;
    case 3:
      item->SetMarked(false);
      return 1;
    case 4:
      menu->RemoveItem(item);
      delete item;
      return 1;
    default:
      return 0;
  }
}

/* The menu a command names, created as needed: the top level one and then one
   level per label that is not NULL. */
BMenu *menu_path(BMenuBar *bar, const char *head, const char *item,
                 const char *subitem) {
  BMenu *menu = ensure_menu(bar, head);

  if (menu && item) {
    menu = ensure_menu(menu, item);
  }
  if (menu && subitem) {
    menu = ensure_menu(menu, subitem);
  }
  return menu;
}

const uint32 kYabMenuMessage = 'rkym';

int lock_window(YabWindow *window) {
  if (!window || !window->window) {
    set_error("the window is not open");
    return 0;
  }
  if (window->window->LockWithTimeout(100000) != B_OK) {
    set_error("the window did not respond");
    return 0;
  }
  return 1;
}

int rk_yab_menu(const char *head, const char *item, const char *shortcut,
                const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? ensure_menu(bar, head) : NULL;
  if (!menu) {
    window->window->Unlock();
    return 0;
  }
  if (item && strcmp(item, "--") == 0) {
    menu->AddItem(new BSeparatorItem());
  } else {
    entry = new BMenuItem(item ? item : "", new BMessage(kYabMenuMessage));
    apply_shortcut(entry, shortcut);
    menu->AddItem(entry);
  }
  window->window->Unlock();
  return 1;
}

int rk_yab_menu_radio(const char *head, int radio, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? ensure_menu(bar, head) : NULL;
  if (menu) {
    menu->SetRadioMode(radio != 0);
  }
  window->window->Unlock();
  return menu ? 1 : 0;
}

int rk_yab_menu_option(const char *head, const char *item, const char *option,
                       const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;
  int action = menu_action(option);
  int ok = 0;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (action < 0) {
    snprintf(g_error, sizeof(g_error), "menu set: '%s' is not an option",
             option ? option : "");
    return 0;
  }
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? ensure_menu(bar, head) : NULL;
  entry = find_menu_item(menu, item);
  if (menu && entry) {
    ok = apply_menu_action(menu, entry, action);
  }
  window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error), "menu set: '%s' has no item '%s'",
             head ? head : "", item ? item : "");
    return 0;
  }
  return 1;
}

int rk_yab_submenu(const char *head, const char *item, const char *subitem,
                   const char *shortcut, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (item && strcmp(item, "--") == 0) {
    /* yab returns without a word: a separator cannot own a submenu. */
    return 1;
  }
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, NULL) : NULL;
  if (!menu) {
    window->window->Unlock();
    return 0;
  }
  if (subitem && strcmp(subitem, "--") == 0) {
    menu->AddItem(new BSeparatorItem());
  } else {
    entry = new BMenuItem(subitem ? subitem : "", new BMessage(kYabMenuMessage));
    apply_shortcut(entry, shortcut);
    menu->AddItem(entry);
  }
  window->window->Unlock();
  return 1;
}

int rk_yab_submenu_radio(const char *head, const char *item, int radio,
                         const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, NULL) : NULL;
  if (menu) {
    menu->SetRadioMode(radio != 0);
  }
  window->window->Unlock();
  return menu ? 1 : 0;
}

int rk_yab_submenu_option(const char *head, const char *item,
                          const char *subitem, const char *option,
                          const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;
  int action = menu_action(option);
  int ok = 0;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (action < 0) {
    snprintf(g_error, sizeof(g_error), "submenu set: '%s' is not an option",
             option ? option : "");
    return 0;
  }
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, NULL) : NULL;
  entry = find_menu_item(menu, subitem);
  if (menu && entry) {
    ok = apply_menu_action(menu, entry, action);
  }
  window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "submenu set: '%s' has no item '%s'", item ? item : "",
             subitem ? subitem : "");
    return 0;
  }
  return 1;
}

int rk_yab_subsubmenu(const char *head, const char *item, const char *subitem,
                      const char *subsubitem, const char *shortcut,
                      const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (item && strcmp(item, "--") == 0) {
    return 1;
  }
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, subitem) : NULL;
  if (!menu) {
    window->window->Unlock();
    return 0;
  }
  if (subsubitem && strcmp(subsubitem, "--") == 0) {
    menu->AddItem(new BSeparatorItem());
  } else {
    entry = new BMenuItem(subsubitem ? subsubitem : "",
                          new BMessage(kYabMenuMessage));
    apply_shortcut(entry, shortcut);
    menu->AddItem(entry);
  }
  window->window->Unlock();
  return 1;
}

int rk_yab_subsubmenu_radio(const char *head, const char *item,
                            const char *subitem, int radio,
                            const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, subitem) : NULL;
  if (menu) {
    menu->SetRadioMode(radio != 0);
  }
  window->window->Unlock();
  return menu ? 1 : 0;
}

int rk_yab_subsubmenu_option(const char *head, const char *item,
                             const char *subitem, const char *subsubitem,
                             const char *option, const char *view_name) {
  clear_error();
  float dx = 0.0f;
  float dy = 0.0f;
  YabWindow *window = widget_host(view_name, &dx, &dy);
  BMenuBar *bar;
  BMenu *menu;
  BMenuItem *entry;
  int action = menu_action(option);
  int ok = 0;

  if (!window) {
    return 0;
  }
  (void)dx;
  (void)dy;
  if (action < 0) {
    snprintf(g_error, sizeof(g_error), "subsubmenu set: '%s' is not an option",
             option ? option : "");
    return 0;
  }
  if (!lock_window(window)) {
    return 0;
  }
  bar = window_menubar(window);
  menu = bar ? menu_path(bar, head, item, subitem) : NULL;
  entry = find_menu_item(menu, subsubitem);
  if (menu && entry) {
    ok = apply_menu_action(menu, entry, action);
  }
  window->window->Unlock();
  if (!ok) {
    snprintf(g_error, sizeof(g_error),
             "subsubmenu set: '%s' has no item '%s'", subitem ? subitem : "",
             subsubitem ? subsubitem : "");
    return 0;
  }
  return 1;
}

/* ---- clipboard and translation ----------------------------------------- */

int rk_yab_clipboard_copy(const char *text) {
  clear_error();
  const char *copy = text ? text : "";

  /* The clipboard belongs to a BApplication, and a program may copy before it
     opens its first window, so the application is started here. */
  if (!rk_gui_ensure_app() || !be_clipboard) {
    set_error(rk_gui_last_error());
    if (!g_error[0]) {
      set_error("clipboard copy: the application is not running");
    }
    return 0;
  }
  if (!be_clipboard->Lock()) {
    set_error("clipboard copy: the clipboard is busy");
    return 0;
  }
  be_clipboard->Clear();
  BMessage *data = be_clipboard->Data();
  if (!data) {
    be_clipboard->Unlock();
    set_error("clipboard copy: the clipboard has no data message");
    return 0;
  }
  /* yab stores the text without its terminator and pastes it back by length. */
  if (data->AddData("text/plain", B_MIME_TYPE, copy, (ssize_t)strlen(copy)) !=
      B_OK) {
    be_clipboard->Unlock();
    set_error("clipboard copy: could not write the clipboard");
    return 0;
  }
  be_clipboard->Commit();
  be_clipboard->Unlock();
  return 1;
}

const char *rk_yab_clipboard_paste(void) {
  static BString text;

  clear_error();
  text.SetTo("");
  if (!rk_gui_ensure_app() || !be_clipboard) {
    /* yab reads an empty clipboard as an empty string, and so does this when
       there is no application to ask. */
    return text.String();
  }
  if (be_clipboard->Lock()) {
    BMessage *clip = be_clipboard->Data();
    const void *data = NULL;
    ssize_t length = 0;
    if (clip && clip->FindData("text/plain", B_MIME_TYPE, &data, &length) ==
                    B_OK &&
        data && length > 0) {
      text.SetTo((const char *)data, (int32)length);
    }
    be_clipboard->Unlock();
  }
  return text.String();
}

/* RenkuBASIC ships no message catalogs, so a translation is the identifier
   itself -- which is also what yab returns for a key its catalog does not
   know, and what the `translate$` test asserts. */
const char *rk_yab_translate(const char *text) {
  static char result[4096];

  clear_error();
  snprintf(result, sizeof(result), "%s", text ? text : "");
  return result;
}

const char *rk_yab_menu_translate(const char *text) {
  /* yab splits a menu key on ':' and translates each part; with no catalog
     every part keeps its text, so the key comes back unchanged. */
  return rk_yab_translate(text);
}

} // extern "C"
