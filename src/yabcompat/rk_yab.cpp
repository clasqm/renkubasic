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
#include <File.h>
#include <Font.h>
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
  YabView *next;
};

struct YabWindow {
  char *name;
  BWindow *window;
  BView *display;
  BBitmap *frame; /* content size, no views: only blitted */
  float width;
  float height;
  YabWindow *next;
};

YabWindow *g_windows = NULL;
YabView *g_views = NULL;
char g_error[512] = "";

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
  if (!id || !*id) {
    set_error("view: a view needs a name");
    return 0;
  }
  if (find_view(id)) {
    snprintf(g_error, sizeof(g_error), "view: '%s' is already open", id);
    return 0;
  }
  YabWindow *window = find_window(window_name);
  if (!window) {
    snprintf(g_error, sizeof(g_error), "view: window '%s' is not open",
             window_name ? window_name : "");
    return 0;
  }

  float width = (float)(x2 - x1 + 1.0);
  float height = (float)(y2 - y1 + 1.0);
  if (width < 1.0f || height < 1.0f || width > 8192.0f || height > 8192.0f) {
    set_error("view: the view size is out of range");
    return 0;
  }
  if ((float)x1 < 0.0f || (float)y1 < 0.0f || (float)x1 + width > window->width ||
      (float)y1 + height > window->height) {
    set_error("view: the view does not fit into its window");
    return 0;
  }

  BRect rect(0, 0, width - 1.0f, height - 1.0f);
  BBitmap *canvas = new BBitmap(rect, B_RGB32, true);
  if (!canvas || canvas->InitCheck() != B_OK) {
    delete canvas;
    set_error("view: could not create the drawing bitmap");
    return 0;
  }
  BView *view = new BView(rect, "rk-yab-view", B_FOLLOW_NONE, 0);
  canvas->Lock();
  canvas->AddChild(view);
  view->SetHighColor(255, 255, 255, 255);
  view->FillRect(rect);
  view->SetDrawingMode(B_OP_COPY);
  BFont font(*be_plain_font);
  font.SetSize(12.0f);
  view->SetFont(&font);
  canvas->Unlock();

  YabView *entry = new YabView;
  entry->name = strdup(id);
  entry->window_name = strdup(window_name ? window_name : "");
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

  /* A new view starts as a white rectangle in its window, like yab. */
  if (window->window->LockWithTimeout(100000) == B_OK) {
    copy_pixels(canvas, 0, 0, window->frame, (int)entry->rect.left,
                (int)entry->rect.top, (int)width, (int)height);
    window->display->Invalidate();
    window->window->Unlock();
  }

  entry->next = g_views;
  g_views = entry;
  return 1;
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
  YabWindow *window = view->window;
  if (!window || !window->window) {
    set_error("draw flush: the view's window is gone");
    return 0;
  }
  if (window->window->LockWithTimeout(100000) != B_OK) {
    set_error("draw flush: the window did not respond");
    return 0;
  }
  /* The canvas lock is this thread's own: the window thread only ever reads
     the window frame, never a view's canvas. */
  view->canvas->Lock();
  copy_pixels(view->canvas, 0, 0, window->frame, (int)view->rect.left,
              (int)view->rect.top, (int)(view->rect.Width() + 1.0f),
              (int)(view->rect.Height() + 1.0f));
  view->canvas->Unlock();
  window->display->Invalidate();
  window->window->Unlock();
  return 1;
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

} // extern "C"
