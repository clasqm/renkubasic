/*
    RenkuBASIC --- yab compatibility layer, C bridge.

    yab 1.8.3 is a BASIC with a BeOS/Haiku widget API: `window open ...`,
    `view ...`, `draw line ...`. RenkuBASIC keeps yabasic's language and adds
    those command groups on top of the Haiku kits. This header is the C
    interface between the interpreter (C, src/yabcompat/rk_yab_cmd.c) and the
    Haiku implementation (C++, src/yabcompat/rk_yab.cpp), exactly like
    rk_gui.h does for yabasic's own graphic window.

    Conventions
    -----------
    * Every function returns 1 on success and 0 on failure. On failure
      rk_yab_last_error() says what went wrong; the interpreter turns that into
      a runtime error, which is how yab reports a bad window name or an
      unreachable app_server.
    * Names ("id", "view", window names) are the strings a program uses; the
      layer keeps its own registry. There is no handle a program could see.
    * Coordinates are window pixels, origin top-left. A window opened with
      `window open 100, 100 to 400, 300` has a 301 x 201 pixel content area,
      because yab's coordinates are inclusive on both ends.
    * Parameter names avoid "buttons", which <term.h> (included by yabasic.h)
      defines as a terminfo macro. rk_gui.h has the same rule and explains it.
*/

#ifndef RK_YAB_H
#define RK_YAB_H

#ifdef __cplusplus
extern "C" {
#endif

/* 1 when the layer is compiled in and a window can be created. */
int rk_yab_available(void);

/* Reason the last call failed, or "" when it succeeded. */
const char *rk_yab_last_error(void);

/* ---- windows ---------------------------------------------------------- */

int rk_yab_window_open(double x1, double y1, double x2, double y2,
                       const char *id, const char *title);
int rk_yab_window_close(const char *id);
/* Number of open windows, or 0 when none is open. */
int rk_yab_window_count(void);
/* Numeric window property: "width", "height", "position-x", "position-y",
   "frame-width", "frame-height". Returns 0 and sets the error for an unknown
   property or a missing window. */
double rk_yab_window_get(const char *id, const char *property);
/* Textual window properties: "title" and "flags". */
int rk_yab_window_set(const char *id, const char *property, const char *value);

/* ---- views ------------------------------------------------------------ */

/* A view is a named rectangle inside a window with its own drawing surface. */
int rk_yab_view_open(double x1, double y1, double x2, double y2,
                     const char *id, const char *window);

/* Select the font of a view: "Family, Style, Size", any part optional. */
int rk_yab_view_set_font(const char *spec, const char *view);
/* "bgcolor", "lowcolor" or "highcolor", 0..255 components. bgcolor also fills
   the view, as yab does. */
int rk_yab_view_set_colour(const char *property, int r, int g, int b,
                           const char *view);
/* Numeric view property: "width", "height", "max-text-height", "text-width"
   (the last one needs rk_yab_view_text_width). */
double rk_yab_view_get(const char *property, const char *view);
double rk_yab_view_text_width(const char *text, const char *view);

/* ---- drawing ---------------------------------------------------------- */

int rk_yab_draw_text(double x, double y, const char *text, const char *view);
int rk_yab_draw_dot(double x, double y, const char *view);
int rk_yab_draw_line(double x1, double y1, double x2, double y2,
                     const char *view);
int rk_yab_draw_rect(double x1, double y1, double x2, double y2,
                     const char *view);
int rk_yab_draw_roundrect(double x1, double y1, double x2, double y2,
                          double radius_x, double radius_y, const char *view);
int rk_yab_draw_circle(double cx, double cy, double radius, const char *view);
int rk_yab_draw_ellipse(double cx, double cy, double rx, double ry,
                        const char *view);
int rk_yab_draw_arc(double cx, double cy, double rx, double ry, double from,
                    double to, const char *view);
/* x1,y1,x2,y2,x3,y3,x4,y4 --- a cubic Bezier, as `draw curve`.
   `draw triangle` passes the first six values, `draw polygon` all eight. */
int rk_yab_draw_curve(const double *xy, const char *view);
int rk_yab_draw_triangle(const double *xy, const char *view);
int rk_yab_draw_polygon(const double *xy, const char *view);

/* Copy the view's surface into its window and redraw it. */
int rk_yab_draw_flush(const char *view);

/* ---- program helpers -------------------------------------------------- */

/* Write the screen area x1,y1 to x2,y2 of the frontmost yab window as PNG.
   yab captures the screen; RenkuBASIC captures its own windows so the command
   works the same on a desktop with other windows open. */
int rk_yab_screenshot(double x1, double y1, double x2, double y2,
                      const char *path);

/* Size of a file in bytes, or -1 when it cannot be read. */
double rk_yab_file_size(const char *path);

#ifdef __cplusplus
}
#endif

#endif /* RK_YAB_H */
