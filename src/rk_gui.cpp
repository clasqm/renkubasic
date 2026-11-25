/*
    RenkuBASIC --- Haiku graphic window backend.

    yabasic 2.92.1 drew its graphic window through Xlib (and GDI on Windows).
    RenkuBASIC has neither: this file implements the same canvas on a
    BWindow showing a BBitmap, with TrueType/OpenType text from the Haiku font
    manager.

    Design notes
    ------------
    * One BApplication for the whole process (BUILDING.md decision D6). It is
      created on first use and its message loop runs on a helper thread, because
      the interpreter owns the main thread for the whole program. Every window
      operation from the interpreter takes the window lock.
    * All drawing goes into an offscreen B_RGB32 BBitmap. The window's view only
      blits that bitmap, so getbit$ and screenshots read a stable canvas and
      redraws on expose need no primitive replay. The pixel buffer is also what
      putbit writes into, which keeps those two commands symmetric.
    * Text is a BFont. A font specification is "Family, Style, Size"; the parts
      are optional and a missing family falls back to be_plain_font. Bitmap
      fonts are not used anywhere, as Haiku has none.
*/

#include <Application.h>
#include <Bitmap.h>
#include <File.h>
#include <Font.h>
#include <Message.h>
#include <Screen.h>
#include <TranslatorRoster.h>
#include <View.h>
#include <Window.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "rk_gui.h"

namespace {

BBitmap *g_canvas = NULL;
BView *g_canvas_view = NULL;
BWindow *g_window = NULL;
BApplication *g_app = NULL;
BFont g_font;
rgb_color g_fore = {0, 0, 0, 255};
rgb_color g_back = {255, 255, 255, 255};
int g_width = 0;
int g_height = 0;
char g_error[512] = "";

/* Keys collected by the window thread, read by inkey$ on the interpreter
   thread. Small and lock-free on purpose: a missed key during a redraw is
   better than a deadlock between the two threads. */
const int kKeyQueue = 64;
char g_keys[kKeyQueue][16];
int g_key_write = 0;
int g_key_read = 0;

int g_mouse_x = 0;
int g_mouse_y = 0;
int g_mouse_buttons = 0;

void set_error(const char *text) {
  snprintf(g_error, sizeof(g_error), "%s", text ? text : "");
}

bool queue_key(const char *name) {
  int next = (g_key_write + 1) % kKeyQueue;
  if (next == g_key_read) {
    return false; /* full: drop the oldest behaviour would be worse */
  }
  snprintf(g_keys[g_key_write], sizeof(g_keys[0]), "%s", name);
  g_key_write = next;
  return true;
}

void push_special_key(uint32 key) {
  switch (key) {
  case B_UP_ARROW:
    queue_key("up");
    break;
  case B_DOWN_ARROW:
    queue_key("down");
    break;
  case B_LEFT_ARROW:
    queue_key("left");
    break;
  case B_RIGHT_ARROW:
    queue_key("right");
    break;
  case B_DELETE:
    queue_key("del");
    break;
  case B_INSERT:
    queue_key("ins");
    break;
  case B_HOME:
    queue_key("home");
    break;
  case B_END:
    queue_key("end");
    break;
  default:
    break;
  }
}

class RkDisplayView : public BView {
public:
  RkDisplayView(BRect frame)
      : BView(frame, "renku-display", B_FOLLOW_ALL, B_WILL_DRAW) {}

  void Draw(BRect update) {
    SetHighColor(g_back);
    FillRect(update);
    if (!g_canvas) {
      return;
    }
    /* The canvas is written by the interpreter thread; take its lock for the
       duration of the blit. */
    if (g_canvas->Lock() == B_OK) {
      DrawBitmap(g_canvas, BPoint(0, 0));
      g_canvas->Unlock();
    }
  }
};

class RkWindow : public BWindow {
public:
  RkWindow(BRect frame, const char *title)
      : BWindow(frame, title, B_TITLED_WINDOW, B_NOT_ZOOMABLE) {}

  bool QuitRequested() { return true; }

  void MessageReceived(BMessage *message) {
    switch (message->what) {
    case B_KEY_DOWN: {
      int32 raw = 0;
      if (message->FindInt32("key", &raw) == B_OK) {
        push_special_key((uint32)raw);
      }
      const char *bytes = NULL;
      if (message->FindString("bytes", &bytes) == B_OK && bytes && bytes[0]) {
        /* The interpreter is byte oriented; take the first byte of the UTF-8
           sequence, which is what yabasic's inkey$ always did. */
        char one[2];
        one[0] = bytes[0];
        one[1] = '\0';
        queue_key(one);
      }
      break;
    }
    case B_MOUSE_MOVED:
    case B_MOUSE_DOWN:
    case B_MOUSE_UP: {
      BPoint where;
      if (message->FindPoint("where", &where) == B_OK) {
        g_mouse_x = (int)where.x;
        g_mouse_y = (int)where.y;
      }
      int32 buttons = 0;
      if (message->FindInt32("buttons", &buttons) == B_OK) {
        g_mouse_buttons = (int)buttons;
      }
      break;
    }
    default:
      BWindow::MessageReceived(message);
      break;
    }
  }

};

int32 gui_thread(void *data) {
  BApplication *app = (BApplication *)data;
  app->Run();
  return 0;
}

void ensure_app() {
  if (g_app) {
    return;
  }
  g_app = new BApplication("application/x-vnd.RenkuBASIC");
  thread_id thread = spawn_thread(gui_thread, "RenkuBASIC GUI", B_NORMAL_PRIORITY,
                                  g_app);
  if (thread >= 0) {
    resume_thread(thread);
    /* Give the looper a moment to start; BWindow creation below retries. */
    usleep(20000);
  }
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
  while (len > 0 &&
         (text[len - 1] == ' ' || text[len - 1] == '\t' ||
          text[len - 1] == '\r' || text[len - 1] == '\n')) {
    text[--len] = '\0';
  }
}

} // namespace

extern "C" {

int rk_gui_available(void) { return 1; }

const char *rk_gui_last_error(void) { return g_error; }

int rk_gui_window_open(void) { return g_window != NULL; }

int rk_gui_open_window(int width, int height, const char *title) {
  if (g_window) {
    set_error("a window is already open");
    return 0;
  }
  if (width < 1 || height < 1) {
    set_error("window size must be at least 1x1");
    return 0;
  }
  set_error("");
  ensure_app();

  BRect canvas_rect(0, 0, width - 1, height - 1);
  BBitmap *canvas = new BBitmap(canvas_rect, B_RGB32, true);
  if (!canvas || canvas->InitCheck() != B_OK) {
    delete canvas;
    set_error("could not create the drawing bitmap");
    return 0;
  }
  BView *canvas_view =
      new BView(canvas_rect, "renku-canvas", B_FOLLOW_NONE, 0);
  canvas->Lock();
  canvas->AddChild(canvas_view);
  canvas_view->SetHighColor(g_back);
  canvas_view->FillRect(canvas_rect);
  canvas_view->SetDrawingMode(B_OP_COPY);
  canvas->Unlock();

  BRect frame(60, 60, 60 + width - 1, 60 + height - 1);
  RkWindow *window = new RkWindow(frame, title ? title : "RenkuBASIC");
  window->AddChild(new RkDisplayView(frame.OffsetToCopy(B_ORIGIN)));
  window->Show();

  /* Wait until the looper really handles the window, so the first drawing is
     not lost. LockWithTimeout keeps a broken app_server from hanging us. */
  bool up = false;
  for (int i = 0; i < 200; i++) {
    if (window->LockWithTimeout(10000) == B_OK) {
      window->Unlock();
      up = true;
      break;
    }
    usleep(10000);
  }
  if (!up) {
    set_error("could not start the window (is app_server reachable?)");
    delete window;
    delete canvas;
    return 0;
  }

  g_canvas = canvas;
  g_canvas_view = canvas_view;
  g_window = window;
  g_width = width;
  g_height = height;
  g_font = *be_plain_font;
  g_font.SetSize(12.0f);
  g_canvas->Lock();
  g_canvas_view->SetFont(&g_font);
  g_canvas->Unlock();
  return 1;
}

void rk_gui_close_window(void) {
  BBitmap *canvas = g_canvas;
  BView *canvas_view = g_canvas_view;
  BWindow *window = g_window;

  g_canvas = NULL;
  g_canvas_view = NULL;
  g_window = NULL;
  g_width = g_height = 0;

  if (window) {
    if (window->LockWithTimeout(100000) == B_OK) {
      window->Quit();
    } else {
      window->PostMessage(B_QUIT_REQUESTED);
    }
  }
  if (canvas) {
    canvas->Lock();
    if (canvas_view) {
      canvas->RemoveChild(canvas_view);
      delete canvas_view;
    }
    canvas->Unlock();
    delete canvas;
  }
}

void rk_gui_shutdown(void) {
  rk_gui_close_window();
  /* The application looper belongs to a helper thread; the process is about to
     exit, so it is not joined. Closing the window is what matters for the
     app_server. */
}

void rk_gui_clear(void) {
  if (!g_canvas || !g_canvas_view) {
    return;
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_back);
  g_canvas_view->FillRect(g_canvas_view->Bounds());
  g_canvas->Unlock();
  rk_gui_flush();
}

void rk_gui_flush(void) {
  if (!g_window) {
    return;
  }
  if (g_window->LockWithTimeout(100000) == B_OK) {
    g_window->Invalidate();
    g_window->Unlock();
  }
}

void rk_gui_set_colour(int r, int g, int b) {
  g_fore.red = (uint8)r;
  g_fore.green = (uint8)g;
  g_fore.blue = (uint8)b;
  g_fore.alpha = 255;
}

void rk_gui_set_background(int r, int g, int b) {
  g_back.red = (uint8)r;
  g_back.green = (uint8)g;
  g_back.blue = (uint8)b;
  g_back.alpha = 255;
}

void rk_gui_set_font(const char *spec) {
  char family[128] = "";
  char style[128] = "";
  float size = 12.0f;
  char buffer[256];

  snprintf(buffer, sizeof(buffer), "%s", spec ? spec : "");
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
    /* A single numeric field is a size, not a family. */
    char *end = NULL;
    double value = strtod(family, &end);
    if (end && *end == '\0' && value >= 1.0 && value <= 512.0) {
      size = (float)value;
      family[0] = '\0';
    }
  }

  BFont font(*be_plain_font);
  if (family[0]) {
    status_t status = B_NAME_NOT_FOUND;
    if (style[0]) {
      status = font.SetFamilyAndStyle(family, style);
    }
    if (status != B_OK) {
      status = font.SetFamily(family);
    }
    if (status != B_OK) {
      /* Unknown family: keep the previous family but honour the size below. */
      font = g_font;
      font.SetSize(size);
      g_font = font;
      if (g_canvas) {
        g_canvas->Lock();
        g_canvas_view->SetFont(&g_font);
        g_canvas->Unlock();
      }
      return;
    }
  }
  font.SetSize(size);
  g_font = font;
  if (g_canvas && g_canvas_view) {
    g_canvas->Lock();
    g_canvas_view->SetFont(&g_font);
    g_canvas->Unlock();
  }
}

int rk_gui_text_width(const char *text) {
  if (!g_canvas_view) {
    return 0;
  }
  int width = 0;
  g_canvas->Lock();
  width = (int)g_canvas_view->StringWidth(text ? text : "");
  g_canvas->Unlock();
  return width;
}

int rk_gui_text_height(void) {
  font_height height;
  g_font.GetHeight(&height);
  return (int)(height.ascent + height.descent + 0.5f);
}

void rk_gui_point(double x, double y) {
  if (!g_canvas) {
    return;
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  g_canvas_view->StrokeLine(BPoint((float)x, (float)y),
                            BPoint((float)x + 1, (float)y));
  g_canvas->Unlock();
}

void rk_gui_line(double x1, double y1, double x2, double y2) {
  if (!g_canvas) {
    return;
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  g_canvas_view->SetPenSize(1.0f);
  g_canvas_view->StrokeLine(BPoint((float)x1, (float)y1),
                            BPoint((float)x2, (float)y2));
  g_canvas->Unlock();
}

void rk_gui_rect(double x1, double y1, double x2, double y2, int fill) {
  if (!g_canvas) {
    return;
  }
  BRect rect((float)x1, (float)y1, (float)x2, (float)y2);
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  if (fill) {
    g_canvas_view->FillRect(rect);
  } else {
    g_canvas_view->StrokeRect(rect);
  }
  g_canvas->Unlock();
}

void rk_gui_ellipse(double cx, double cy, double rx, double ry, int fill) {
  if (!g_canvas) {
    return;
  }
  BRect rect((float)(cx - rx), (float)(cy - ry), (float)(cx + rx),
             (float)(cy + ry));
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  if (fill) {
    g_canvas_view->FillEllipse(rect);
  } else {
    g_canvas_view->StrokeEllipse(rect);
  }
  g_canvas->Unlock();
}

void rk_gui_polygon(const double *xy, int count, int fill) {
  if (!g_canvas || count < 2 || !xy) {
    return;
  }
  BPoint *points = new BPoint[count];
  for (int i = 0; i < count; i++) {
    points[i].Set((float)xy[2 * i], (float)xy[2 * i + 1]);
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  if (fill) {
    g_canvas_view->FillPolygon(points, count);
  } else {
    g_canvas_view->StrokePolygon(points, count);
  }
  g_canvas->Unlock();
  delete[] points;
}

void rk_gui_text(double x, double y, const char *text) {
  if (!g_canvas || !text) {
    return;
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor(g_fore);
  g_canvas_view->SetDrawingMode(B_OP_OVER);
  g_canvas_view->DrawString(text, BPoint((float)x, (float)y));
  g_canvas_view->SetDrawingMode(B_OP_COPY);
  g_canvas->Unlock();
}

void rk_gui_set_pixel(int x, int y, int r, int g, int b) {
  if (!g_canvas || x < 0 || y < 0 || x >= g_width || y >= g_height) {
    return;
  }
  g_canvas->Lock();
  g_canvas_view->SetHighColor((uint8)r, (uint8)g, (uint8)b, 255);
  g_canvas_view->FillRect(BRect((float)x, (float)y, (float)x, (float)y));
  g_canvas->Unlock();
}

void rk_gui_get_pixel(int x, int y, int *r, int *g, int *b) {
  if (r) {
    *r = 0;
  }
  if (g) {
    *g = 0;
  }
  if (b) {
    *b = 0;
  }
  if (!g_canvas || x < 0 || y < 0 || x >= g_width || y >= g_height) {
    return;
  }
  g_canvas->Lock();
  const uint8 *bits = (const uint8 *)g_canvas->Bits();
  const uint8 *pixel = bits + (size_t)y * g_canvas->BytesPerRow() + x * 4;
  /* B_RGB32 is stored as B, G, R, A on little-endian Haiku. */
  if (b) {
    *b = pixel[0];
  }
  if (g) {
    *g = pixel[1];
  }
  if (r) {
    *r = pixel[2];
  }
  g_canvas->Unlock();
}

int rk_gui_save_png(const char *path) {
  if (!g_canvas || !path) {
    return 0;
  }
  BTranslatorRoster *roster = BTranslatorRoster::Default();
  if (!roster) {
    set_error("no translator roster available");
    return 0;
  }
  BFile file(path, B_CREATE_FILE | B_ERASE_FILE | B_WRITE_ONLY);
  if (file.InitCheck() != B_OK) {
    set_error("could not create the screenshot file");
    return 0;
  }
  g_canvas->Lock();
  status_t status = roster->Translate(g_canvas, NULL, NULL, &file, B_PNG_FORMAT);
  g_canvas->Unlock();
  if (status != B_OK) {
    set_error("could not encode the screenshot as PNG");
    return 0;
  }
  return 1;
}

void rk_gui_screen_size(int *width, int *height) {
  int w = 1920;
  int h = 1080;
  ensure_app();
  BScreen screen;
  if (screen.IsValid()) {
    BRect frame = screen.Frame();
    w = (int)frame.Width() + 1;
    h = (int)frame.Height() + 1;
  }
  if (width) {
    *width = w;
  }
  if (height) {
    *height = h;
  }
}

int rk_gui_key_pending(void) { return g_key_write != g_key_read; }

int rk_gui_next_key(char *out, int outlen) {
  if (!out || outlen < 1 || g_key_write == g_key_read) {
    return 0;
  }
  snprintf(out, (size_t)outlen, "%s", g_keys[g_key_read]);
  g_key_read = (g_key_read + 1) % kKeyQueue;
  return 1;
}

int rk_gui_mouse(int *x, int *y, int *buttons) {
  if (x) {
    *x = g_mouse_x;
  }
  if (y) {
    *y = g_mouse_y;
  }
  if (buttons) {
    *buttons = g_mouse_buttons;
  }
  return 1;
}

} // extern "C"
