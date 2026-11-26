/*
    RenkuBASIC --- Haiku graphic window bridge.

    The interpreter core is C; the Haiku application kit is C++. This header is
    the narrow C interface between them: everything here is implemented in
    rk_gui.cpp and called from rk_graphics.c (yabasic graphics) and, later, from
    the yab compatibility layer.

    Coordinates are window pixels, origin top-left, y downwards, exactly as
    rk_graphics.c hands them over after transform().
*/

#ifndef RK_GUI_H
#define RK_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

/* 1 when the backend is compiled in and a window can be created. */
int rk_gui_available(void);

/* Start the application thread, if it is not running yet. Both this window and
   the yab windows (src/yabcompat) share the one BApplication, so the yab layer
   calls this before it creates its first window. Returns 1 on success; a
   failure is explained by rk_gui_last_error(). */
int rk_gui_ensure_app(void);

/* Create the window and its offscreen canvas. Returns 1 on success; on failure
   the backend has already reported the reason with rk_gui_last_error(). */
int rk_gui_open_window(int width, int height, const char *title);
void rk_gui_close_window(void);
int rk_gui_window_open(void);

/* Destroy everything before the process exits. Safe to call more than once. */
void rk_gui_shutdown(void);

/* Last failure text, or "" when the last call succeeded. */
const char *rk_gui_last_error(void);

/* Canvas operations. */
void rk_gui_clear(void);
void rk_gui_flush(void);
void rk_gui_set_colour(int r, int g, int b);
void rk_gui_set_background(int r, int g, int b);

/* Font specification: "Family, Style, Size" (any part may be omitted). */
void rk_gui_set_font(const char *spec);
int rk_gui_text_width(const char *text);
int rk_gui_text_height(void);

/* Primitives. */
void rk_gui_point(double x, double y);
void rk_gui_line(double x1, double y1, double x2, double y2);
void rk_gui_rect(double x1, double y1, double x2, double y2, int fill);
void rk_gui_ellipse(double cx, double cy, double rx, double ry, int fill);
void rk_gui_polygon(const double *xy, int count, int fill);
void rk_gui_text(double x, double y, const char *text);

/* Single pixels, used by getbit$/putbit. Colours are 0..255 components. */
void rk_gui_set_pixel(int x, int y, int r, int g, int b);
void rk_gui_get_pixel(int x, int y, int *r, int *g, int *b);

/* Write the canvas as PNG. Returns 1 on success. */
int rk_gui_save_png(const char *path);

/* Screen size, from BScreen. */
void rk_gui_screen_size(int *width, int *height);

/* Keyboard/mouse state for inkey$ and yab's peek(): the backend collects them
   while it runs. rk_window_fd() stays -1 because a BWindow has no descriptor;
   rk_window_pending() reports buffered window keys instead. */
int rk_gui_key_pending(void);
/* Copy the next key (yabasic name for special keys, else the character) into
   out; returns 1 when a key was available. */
int rk_gui_next_key(char *out, int outlen);
/* Parameter names below are prefixed because this header is included after
   <term.h>/<curses.h>, whose capability macros include "buttons". */
int rk_gui_mouse(int *out_x, int *out_y, int *out_buttons);

#ifdef __cplusplus
}
#endif

#endif /* RK_GUI_H */
