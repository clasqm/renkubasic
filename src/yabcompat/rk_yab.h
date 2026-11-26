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

/* ---- widgets ---------------------------------------------------------- */

/* A widget command's last string names the view the widget goes into. yab's
   window root view answers to the window's own name, which is what yab
   programs pass; a named view works too, and its coordinates are then relative
   to that view. Every call returns 1 on success, 0 on failure with the reason
   in rk_yab_last_error(). */

/* `layout "left, top", "window"`: resize mode for the widgets created later. */
int rk_yab_layout(const char *spec, const char *view);

int rk_yab_button(double x1, double y1, double x2, double y2, const char *id,
                  const char *label, const char *view);
int rk_yab_checkbox(double x, double y, const char *id, const char *label,
                    int checked, const char *view);
int rk_yab_radiobutton(double x, double y, const char *id, const char *label,
                       int checked, const char *view);
int rk_yab_checkbox_set(const char *id, int checked);
int rk_yab_radiobutton_set(const char *id, int checked);

int rk_yab_text(double x, double y, const char *id, const char *text,
                const char *view);
int rk_yab_text_align(const char *id, const char *align);
int rk_yab_text_url(double x, double y, const char *id, const char *text,
                    const char *url, const char *view);

int rk_yab_textcontrol(double x1, double y1, double x2, double y2,
                       const char *id, const char *label, const char *value,
                       const char *view);
int rk_yab_textcontrol_set(const char *id, const char *value);
/* The second form of `textcontrol set` hides what is typed. */
int rk_yab_textcontrol_mask(const char *id, int masked);
int rk_yab_textcontrol_clear(const char *id);
/* RenkuBASIC extension: the value of a text control, or "" when it is missing
   (rk_yab_last_error() says why). */
const char *rk_yab_textcontrol_get(const char *id);

int rk_yab_textedit(double x1, double y1, double x2, double y2,
                    const char *id, int scrollbar, const char *view);
int rk_yab_textedit_add(const char *id, const char *text);
int rk_yab_textedit_set(const char *id, const char *text);
int rk_yab_textedit_clear(const char *id);
int rk_yab_textedit_colour(const char *id, const char *property, int r,
                           int g, int b);
const char *rk_yab_textedit_get(const char *id);

/* `slider ... , min, max [, "vertical, triangle"], view` */
int rk_yab_slider(double x1, double y1, double x2, double y2, const char *id,
                  const char *label, double minimum, double maximum,
                  const char *options, const char *view);
int rk_yab_slider_set(const char *id, double value);
/* `slider set id, "left", 15`: hash marks on a side and their count. */
int rk_yab_slider_marks(const char *id, const char *location, double count);
int rk_yab_slider_labels(const char *id, const char *minimum,
                         const char *maximum);
int rk_yab_slider_colour(const char *id, const char *property, int r, int g,
                         int b);

/* `scrollbar id, bars, view`: 1 vertical, 2 horizontal, 3 both. */
int rk_yab_scrollbar(const char *id, int bars, const char *view);
/* With two != 0 both numbers are used, as `scrollbar set id, "range", a, b`
   does; otherwise only value is. */
int rk_yab_scrollbar_set(const char *id, const char *property, double value,
                         double other, int two);

int rk_yab_statusbar(double x1, double y1, double x2, double y2,
                     const char *id, const char *label,
                     const char *trailing, const char *view);
int rk_yab_statusbar_set(const char *id, const char *label,
                         const char *trailing, double percent);

int rk_yab_spincontrol(double x, double y, const char *id, const char *label,
                       double minimum, double maximum, double step,
                       const char *view);
int rk_yab_spincontrol_set(const char *id, double value);

/* `option set id, "label", "text"` and `option set id, "enabled", 0`; the
   property names are what yab's programs use. */
int rk_yab_option_set(const char *id, const char *property, const char *value);
int rk_yab_option_set_number(const char *id, const char *property,
                             double value);
int rk_yab_option_colour(const char *id, const char *property, int r, int g,
                         int b);
int rk_yab_tooltip(const char *id, const char *text);

int rk_yab_tabview(double x1, double y1, double x2, double y2, const char *id,
                   const char *side, const char *view);
int rk_yab_tab_add(const char *id, const char *label);
int rk_yab_tab_set(const char *id, double index);
int rk_yab_tab_remove(const char *id, double index);

/* `boxview ... , "label", line_type, view`: 0 no border, 1 plain, 2 fancy. */
int rk_yab_boxview(double x1, double y1, double x2, double y2, const char *id,
                   const char *label, int line_type, const char *view);
int rk_yab_boxview_set(const char *id, const char *option, const char *value);

/* A split view owns two panes, named id1 and id2; a stack view owns `count`
   pages, named id1, id2, ... Only the selected page is shown. */
int rk_yab_splitview(double x1, double y1, double x2, double y2,
                     const char *id, int vertical, int style,
                     const char *view);
int rk_yab_stackview(double x1, double y1, double x2, double y2,
                     const char *id, int count, const char *view);
int rk_yab_stackview_set(const char *id, double index);

/* A canvas and a region are drawable views; a region is meant to clip drawing
   to its rectangle inside its parent view. */
int rk_yab_canvas(double x1, double y1, double x2, double y2, const char *id,
                  const char *view);
int rk_yab_region(double x1, double y1, double x2, double y2, const char *id,
                  const char *view);

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
