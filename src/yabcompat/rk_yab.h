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
/* `tabview get(id)`: the selected tab, 1-based, as yab returns it. */
int rk_yab_tabview_get(const char *id);

/* `boxview ... , "label", line_type, view`: 0 no border, 1 plain, 2 fancy. */
int rk_yab_boxview(double x1, double y1, double x2, double y2, const char *id,
                   const char *label, int line_type, const char *view);
int rk_yab_boxview_set(const char *id, const char *option, const char *value);

/* A split view owns two panes, named id1 and id2; a stack view owns `count`
   pages, named id1, id2, ... Only the selected page is shown. */
int rk_yab_splitview(double x1, double y1, double x2, double y2,
                     const char *id, int vertical, int style,
                     const char *view);
/* `splitview set id, "divider", position` and
   `splitview set id, "minimumsizes", left, right`. The bar position counts
   from the split's left or top edge, as SplitPane's does, and is clamped so
   neither pane falls below its minimum size. */
int rk_yab_splitview_set(const char *id, const char *option, double position);
int rk_yab_splitview_minimums(const char *id, const char *option, double left,
                              double right);
/* `splitview get(id, "divider")`: the bar position in the same pixels. */
double rk_yab_splitview_get(const char *id, const char *option);
int rk_yab_stackview(double x1, double y1, double x2, double y2,
                     const char *id, int count, const char *view);
int rk_yab_stackview_set(const char *id, double index);
/* `stackview get(id)`: the selected page, 1-based. */
int rk_yab_stackview_get(const char *id);

/* A canvas and a region are drawable views; a region is meant to clip drawing
   to its rectangle inside its parent view. */
int rk_yab_canvas(double x1, double y1, double x2, double y2, const char *id,
                  const char *view);
int rk_yab_region(double x1, double y1, double x2, double y2, const char *id,
                  const char *view);

/* ---- list family ------------------------------------------------------ */

/* yab's list boxes, drop boxes, tree boxes and column boxes share their item
   operations: `add`, `add id, pos`, `remove id, item`, `remove id, pos`,
   `select`, `clear`, `sort`, `count`, `get$ id, pos` and the numeric `get id`
   for the selected position. Each call checks that the named widget is one of
   those four and reports the wrong kind as an error. Positions are 1-based;
   `select 0` deselects. */

/* `listbox x1, y1 to x2, y2, id, bars, view`: bars 1 vertical, 2 horizontal,
   3 both, 0 none, as in yab. */
int rk_yab_listbox(double x1, double y1, double x2, double y2,
                   const char *id, int bars, const char *view);
/* `dropbox x1, y1 to x2, y2, id, label, view`; the label is the caption left
   of the field. */
int rk_yab_dropbox(double x1, double y1, double x2, double y2, const char *id,
                   const char *label, const char *view);
int rk_yab_treebox(double x1, double y1, double x2, double y2, const char *id,
                   int bars, const char *view);

int rk_yab_list_add(const char *id, const char *item);
int rk_yab_list_add_at(const char *id, double position, const char *item);
int rk_yab_list_remove(const char *id, const char *item);
int rk_yab_list_remove_at(const char *id, double position);
int rk_yab_list_select(const char *id, double position);
int rk_yab_list_clear(const char *id);
int rk_yab_list_sort(const char *id);
int rk_yab_list_count(const char *id);
const char *rk_yab_list_get(const char *id, double position);
int rk_yab_list_selected(const char *id);

/* `treebox add id, parent, item, expanded`: the item becomes a child of the
   first item whose text is `parent`; expand/collapse name that parent too. */
int rk_yab_tree_add_child(const char *id, const char *parent,
                          const char *item, int expanded);
int rk_yab_tree_remove_child(const char *id, const char *parent,
                             const char *item);
int rk_yab_tree_expand(const char *id, const char *item, int expand);

/* `columnbox x1, y1 to x2, y2, id, hscroll, options, view`; options accepts
   what yab's file box accepts ("no-border", "no-sorting"). */
int rk_yab_columnbox(double x1, double y1, double x2, double y2,
                     const char *id, int bars, const char *options,
                     const char *view);
/* `columnbox column id, title, position, maximum, minimum, width, options`;
   the option is an alignment: "align-left", "align-center", "align-right". */
int rk_yab_columnbox_column(const char *id, const char *title,
                            double position, double maximum, double minimum,
                            double width, const char *options);
/* `columnbox add id, column, position, height, text`: sets one cell, creating
   the row when the position is new. */
int rk_yab_columnbox_add(const char *id, double column, double position,
                         double height, const char *text);
int rk_yab_columnbox_remove(const char *id, double position);
int rk_yab_columnbox_remove_column(const char *id, double position);
int rk_yab_columnbox_select(const char *id, double position);
int rk_yab_columnbox_clear(const char *id);
/* `columnbox colour id, option, r, g, b`: option is "background", "text",
   "selection", "selection-text", "non-focus-selection" or "row-divider". */
int rk_yab_columnbox_colour(const char *id, const char *option, int r, int g,
                            int b);
int rk_yab_columnbox_columns(const char *id);
const char *rk_yab_columnbox_get(const char *id, double column,
                                 double position);

/* `calendar x, y, id, format, date, view`: the format is yab's date format
   string -- its divider ("/", "-" or ""), and MM/DD order when it contains
   "MD". The date is parsed as a date, not as a format. */
int rk_yab_calendar(double x, double y, const char *id, const char *format,
                    const char *date, const char *view);
int rk_yab_calendar_set(const char *id, const char *date);
const char *rk_yab_calendar_get(const char *id);

/* `colorcontrol x, y, id, view` and `colorcontrol set id, r, g, b`. The getter
   takes "red", "green" or "blue". */
int rk_yab_colorcontrol(double x, double y, const char *id,
                        const char *view);
int rk_yab_colorcontrol_set(const char *id, int r, int g, int b);
int rk_yab_colorcontrol_get(const char *id, const char *option);

/* ---- menus and the clipboard ------------------------------------------ */

/* `menu "head", "item", "shortcut", "view"`: adds an item to a top level menu,
   creating the menu (and the window's menu bar) on first use. "--" is a
   separator. The shortcut is yab's: its last character is the key and a `s`,
   `c` or `o` before it adds shift, control or option. */
int rk_yab_menu(const char *head, const char *item, const char *shortcut,
                const char *view);
/* `menu set "head", radio, "view"`: 1 makes the menu a radio group. */
int rk_yab_menu_radio(const char *head, int radio, const char *view);
/* `menu set "head", "item", "option", "view"`: the option is "disable",
   "enable", "mark", "plain" or "remove", matched as yab matches it. */
int rk_yab_menu_option(const char *head, const char *item, const char *option,
                       const char *view);

/* `submenu "head", "item", "subitem", "shortcut", "view"` and the two `set`
   forms (`radio` for a radio group, `option` for an item's state). */
int rk_yab_submenu(const char *head, const char *item, const char *subitem,
                   const char *shortcut, const char *view);
int rk_yab_submenu_radio(const char *head, const char *item, int radio,
                         const char *view);
int rk_yab_submenu_option(const char *head, const char *item,
                          const char *subitem, const char *option,
                          const char *view);

/* `subsubmenu head, item, subitem, subsubitem, shortcut, view` and its `set`
   forms, one level deeper. */
int rk_yab_subsubmenu(const char *head, const char *item, const char *subitem,
                      const char *subsubitem, const char *shortcut,
                      const char *view);
int rk_yab_subsubmenu_radio(const char *head, const char *item,
                            const char *subitem, int radio, const char *view);
int rk_yab_subsubmenu_option(const char *head, const char *item,
                             const char *subitem, const char *subsubitem,
                             const char *option, const char *view);

/* `clipboard copy text$` and the `clipboard paste$` string function. */
int rk_yab_clipboard_copy(const char *text);
const char *rk_yab_clipboard_paste(void);

/* ---- file attributes --------------------------------------------------- */

/* `attribute set type, name, value, file` writes a typed attribute. The type
   is yab's word, matched case-insensitively anywhere in the string, in yab's
   order: string, mime, bool, i8, u8, i16, u16, int, l32, u32, l64, u64,
   double, float, time. */
int rk_yab_attribute_set(const char *type, const char *name, const char *value,
                         const char *file);
/* `attribute clear name, file`: removing an attribute that is not there is
   not an error, as in yab. */
int rk_yab_attribute_clear(const char *name, const char *file);
/* `attribute get$(name, file)`: the attribute as text, every attribute of the
   file when the name is empty ("name | Type | ..."). The string is owned by
   the bridge until the next call. */
const char *rk_yab_attribute_get(const char *name, const char *file);
/* `attribute get(name, file)`: the attribute as a number; bool attributes are
   0 or 1 and everything else is read like yab reads it, with atof. */
double rk_yab_attribute_getnum(const char *name, const char *file);

/* `translate$(...)` and `menu translate$(...)`. */
const char *rk_yab_translate(const char *text);
const char *rk_yab_menu_translate(const char *text);

/* `message$`: every widget event collected since the last call. */
const char *rk_yab_message(void);

/* ---- audio ------------------------------------------------------------- */

/* `sound play path$, loop` starts a file through the game kit; `loop` other
   than 0 repeats it until it is stopped. Only one sound plays at a time: a new
   one replaces the previous. Returns 1 on success, 0 with the reason in
   rk_yab_last_error(). */
int rk_yab_sound_play(const char *path, int loop);
/* `sound stop n`: stops whatever `sound play` started; the argument yab passes
   is not needed and is not part of this interface. */
int rk_yab_sound_stop(void);
/* `sound wait n`: pauses a playing sound, resumes a paused one. */
int rk_yab_sound_pause(void);

/* `mediasound play path$`: decodes the first audio track of any file the media
   kit understands and plays it. `mediasound stop n` stops it. */
int rk_yab_mediasound_play(const char *path);
int rk_yab_mediasound_stop(void);

/* `loudness set volume` and `loudness get`: the audio mixer's master gain,
   clamped by the mixer's own minimum and maximum. */
int rk_yab_loudness_set(double volume);
double rk_yab_loudness_get(void);

/* ---- dialogs ----------------------------------------------------------- */

/* `alert text$, button$, icon$`: yab's one-button alert. The icon is matched
   as a word anywhere in the string -- "info", "idea", "warning", "stop",
   anything else for an empty alert. The call waits for the button, as yab's
   does. */
int rk_yab_notice(const char *text, const char *button, const char *icon);

/* `win$ = popupmenu x, y, "item|item|--|item", "view"`: the label of the entry
   the user picked, or "" when the menu was dismissed. The point is relative to
   the view, or to the window when the view is the window's own name. The
   string is owned by the bridge until the next call. */
const char *rk_yab_popupmenu(double x, double y, const char *items,
                             const char *view);

/* `filepanel mode$, title$, directory$, filename$`: the path the user chose, or
   "" when the panel was cancelled. The mode is yab's, matched as a word
   anywhere in the string: "Load-File", "Save-File", "Load-Directory" or
   "Load-File-and-Directory". `filename` is the name a save panel starts with;
   it is compulsory in the language and unused for the other modes. The title
   goes on the panel's own window, which is what yab titles. The string is owned
   by the bridge until the next call. */
const char *rk_yab_filepanel(const char *mode, const char *title,
                             const char *directory, const char *filename);

/* ---- bitmaps ----------------------------------------------------------- */

/* `bitmap w, h, id`: an offscreen B_RGBA32 bitmap of that size, cleared to
   transparent black, kept under `id` for `draw bitmap`. */
int rk_yab_bitmap(double width, double height, const char *id);
/* `draw bitmap x, y, id, mode, view`: blit the bitmap into a view. The mode is
   yab's: "copy", "alpha", "invert", "max", "min", "subtract", "add" or
   "blend", matched case-insensitively anywhere in the string. */
int rk_yab_bitmap_draw(double x, double y, const char *id, const char *mode,
                       const char *view);
/* `bitmap get id, option, path`: an icon for a file ("path") or a MIME type
   ("mime16", "mime32"). */
int rk_yab_bitmap_get(const char *id, const char *option, const char *argument);
/* `bitmap remove id`: frees the bitmap. */
int rk_yab_bitmap_remove(const char *id);

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
