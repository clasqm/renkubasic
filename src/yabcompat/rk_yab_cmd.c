/*
    RenkuBASIC --- yab compatibility layer, interpreter glue.

    The yab GUI statements are compiled to the cYAB* opcodes declared in
    yabasic.h and executed here. Each production pushes its arguments in
    reading order (see src/yabasic.bison), so this file pops them in reverse,
    which is also how yab's own graphic.c does it. Keeping the popping out of
    main.c's dispatch keeps that switch as small as it is for yabasic's own
    graphic commands.

    A failed bridge call becomes an ordinary BASIC runtime error: the message
    comes from the bridge, so a missing window, an unsupported property or an
    unreachable app_server all read as a normal error instead of a silent
    no-op.
*/

#include <string.h>

#include "yabasic.h"
#include "yabcompat/rk_yab.h"
#include "yabcompat/rk_yab_runtime.h"

static char *take_string(void) /* pop the top string expression */
{
  struct stackentry *entry = pop(stSTRING);

  if (!entry || !entry->pointer) {
    return (char *)"";
  }
  return (char *)entry->pointer;
}

static double take_number(void) /* pop the top number expression */
{
  struct stackentry *entry = pop(stNUMBER);

  if (!entry) {
    return 0.0;
  }
  return entry->value;
}

static void report_failure(void) /* turn the bridge error into a BASIC error */
{
  const char *message = rk_yab_last_error();

  if (!message || !*message) {
    message = "the yab GUI command failed";
  }
  error(sERROR, (char *)message);
}

static void expect(int ok) {
  if (!ok) {
    report_failure();
  }
}

void rk_yab_note_font(const char *spec) {
  if (!spec || !*spec) {
    return;
  }
  if (fontname) {
    my_free(fontname);
  }
  fontname = (char *)my_strdup((char *)spec);
}

void rk_yab_check(void) {
  const char *message = rk_yab_last_error();

  if (message && *message) {
    error(sERROR, (char *)message);
  }
}

void rk_yab_command(struct command *cmd) {
  int count;
  double xy[8];

  switch (cmd->type) {
  case cYABOPENWIN: {
    char *title = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_window_open(x1, y1, x2, y2, id, title));
    break;
  }
  case cYABCLOSEWIN: {
    char *id = take_string();

    expect(rk_yab_window_close(id));
    break;
  }
  case cYABWINSET: {
    char *value = take_string();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_window_set(id, property, value));
    break;
  }
  case cYABVIEW: {
    char *window = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_view_open(x1, y1, x2, y2, id, window));
    break;
  }
  case cYABDRAWSETTEXT: {
    char *view = take_string();
    char *value = take_string();

    if (!rk_yab_view_set_font(value, view)) {
      report_failure();
    } else {
      /* The yab font command is this program's idea of "the font", so make
         peek$("font") agree with it. */
      rk_yab_note_font(value);
    }
    break;
  }
  case cYABDRAWSETCOLOUR: {
    char *view = take_string();
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *property = take_string();

    expect(rk_yab_view_set_colour(property, r, g, b, view));
    break;
  }
  case cYABDRAWTEXT: {
    char *view = take_string();
    char *text = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_draw_text(x, y, text, view));
    break;
  }
  case cYABDRAWDOT: {
    char *view = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_draw_dot(x, y, view));
    break;
  }
  case cYABDRAWLINE: {
    char *view = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_draw_line(x1, y1, x2, y2, view));
    break;
  }
  case cYABDRAWRECT: {
    char *view = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_draw_rect(x1, y1, x2, y2, view));
    break;
  }
  case cYABDRAWROUNDRECT: {
    char *view = take_string();
    double radius_y = take_number();
    double radius_x = take_number();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_draw_roundrect(x1, y1, x2, y2, radius_x, radius_y, view));
    break;
  }
  case cYABDRAWCIRCLE: {
    char *view = take_string();
    double radius = take_number();
    double cy = take_number();
    double cx = take_number();

    expect(rk_yab_draw_circle(cx, cy, radius, view));
    break;
  }
  case cYABDRAWELLIPSE: {
    char *view = take_string();
    double ry = take_number();
    double rx = take_number();
    double cy = take_number();
    double cx = take_number();

    expect(rk_yab_draw_ellipse(cx, cy, rx, ry, view));
    break;
  }
  case cYABDRAWARC: {
    char *view = take_string();
    double to = take_number();
    double from = take_number();
    double ry = take_number();
    double rx = take_number();
    double cy = take_number();
    double cx = take_number();

    expect(rk_yab_draw_arc(cx, cy, rx, ry, from, to, view));
    break;
  }
  case cYABDRAWCURVE: {
    char *view = take_string();

    for (count = 7; count >= 0; count--) {
      xy[count] = take_number();
    }
    expect(rk_yab_draw_curve(xy, view));
    break;
  }
  case cYABDRAWTRIANGLE: {
    char *view = take_string();

    for (count = 5; count >= 0; count--) {
      xy[count] = take_number();
    }
    expect(rk_yab_draw_triangle(xy, view));
    break;
  }
  case cYABDRAWPOLYGON: {
    char *view = take_string();

    for (count = 7; count >= 0; count--) {
      xy[count] = take_number();
    }
    expect(rk_yab_draw_polygon(xy, view));
    break;
  }
  case cYABDRAWFLUSH: {
    char *view = take_string();

    expect(rk_yab_draw_flush(view));
    break;
  }
  case cYABSCREENSHOT: {
    char *path = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_screenshot(x1, y1, x2, y2, path));
    break;
  }
  /* ---- widgets ------------------------------------------------------- */
  case cYABLAYOUT: {
    char *view = take_string();
    char *spec = take_string();

    expect(rk_yab_layout(spec, view));
    break;
  }
  case cYABBUTTON: {
    char *view = take_string();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_button(x1, y1, x2, y2, id, label, view));
    break;
  }
  case cYABCHECKBOX: {
    char *view = take_string();
    int checked = (int)take_number();
    char *label = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_checkbox(x, y, id, label, checked, view));
    break;
  }
  case cYABCHECKBOXSET: {
    double checked = take_number();
    char *id = take_string();

    expect(rk_yab_checkbox_set(id, (int)checked));
    break;
  }
  case cYABRADIOBUTTON: {
    char *view = take_string();
    int checked = (int)take_number();
    char *label = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_radiobutton(x, y, id, label, checked, view));
    break;
  }
  case cYABRADIOSET: {
    double checked = take_number();
    char *id = take_string();

    expect(rk_yab_radiobutton_set(id, (int)checked));
    break;
  }
  case cYABTEXT: {
    char *view = take_string();
    char *text = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_text(x, y, id, text, view));
    break;
  }
  case cYABTEXTALIGN: {
    char *align = take_string();
    char *id = take_string();

    expect(rk_yab_text_align(id, align));
    break;
  }
  case cYABTEXTURL: {
    char *view = take_string();
    char *url = take_string();
    char *text = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_text_url(x, y, id, text, url, view));
    break;
  }
  case cYABTEXTCONTROL: {
    char *view = take_string();
    char *value = take_string();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_textcontrol(x1, y1, x2, y2, id, label, value, view));
    break;
  }
  case cYABTEXTCONTROLSET: {
    char *value = take_string();
    char *id = take_string();

    expect(rk_yab_textcontrol_set(id, value));
    break;
  }
  case cYABTEXTCONTROLMASK: {
    double masked = take_number();
    char *id = take_string();

    expect(rk_yab_textcontrol_mask(id, (int)masked));
    break;
  }
  case cYABTEXTCONTROLCLEAR: {
    char *id = take_string();

    expect(rk_yab_textcontrol_clear(id));
    break;
  }
  case cYABTEXTEDIT: {
    char *view = take_string();
    int scrollbar = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_textedit(x1, y1, x2, y2, id, scrollbar, view));
    break;
  }
  case cYABTEXTEDITADD: {
    char *text = take_string();
    char *id = take_string();

    expect(rk_yab_textedit_add(id, text));
    break;
  }
  case cYABTEXTEDITSET: {
    char *text = take_string();
    char *id = take_string();

    expect(rk_yab_textedit_set(id, text));
    break;
  }
  case cYABTEXTEDITCLEAR: {
    char *id = take_string();

    expect(rk_yab_textedit_clear(id));
    break;
  }
  case cYABTEXTEDITCOLOUR: {
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_textedit_colour(id, property, r, g, b));
    break;
  }
  case cYABSLIDER:
  case cYABSLIDEROPT: {
    char *view = take_string();
    char *options = NULL;
    if (cmd->type == cYABSLIDEROPT) {
      options = take_string();
    }
    double maximum = take_number();
    double minimum = take_number();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_slider(x1, y1, x2, y2, id, label, minimum, maximum, options,
                         view));
    break;
  }
  case cYABSLIDERSET: {
    double value = take_number();
    char *id = take_string();

    expect(rk_yab_slider_set(id, value));
    break;
  }
  case cYABSLIDERMARKS: {
    double count = take_number();
    char *location = take_string();
    char *id = take_string();

    expect(rk_yab_slider_marks(id, location, count));
    break;
  }
  case cYABSLIDERLABEL: {
    char *maximum = take_string();
    char *minimum = take_string();
    char *id = take_string();

    expect(rk_yab_slider_labels(id, minimum, maximum));
    break;
  }
  case cYABSLIDERCOLOUR: {
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_slider_colour(id, property, r, g, b));
    break;
  }
  case cYABSCROLLBAR: {
    char *view = take_string();
    int bars = (int)take_number();
    char *id = take_string();

    expect(rk_yab_scrollbar(id, bars, view));
    break;
  }
  case cYABSCROLLBARSET: {
    double value = take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_scrollbar_set(id, property, value, 0.0, 0));
    break;
  }
  case cYABSCROLLBARRANGE: {
    double other = take_number();
    double value = take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_scrollbar_set(id, property, value, other, 1));
    break;
  }
  case cYABSTATUSBAR: {
    char *view = take_string();
    char *trailing = take_string();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_statusbar(x1, y1, x2, y2, id, label, trailing, view));
    break;
  }
  case cYABSTATUSBARSET: {
    double percent = take_number();
    char *trailing = take_string();
    char *label = take_string();
    char *id = take_string();

    expect(rk_yab_statusbar_set(id, label, trailing, percent));
    break;
  }
  case cYABSPINCONTROL: {
    char *view = take_string();
    double step = take_number();
    double maximum = take_number();
    double minimum = take_number();
    char *label = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_spincontrol(x, y, id, label, minimum, maximum, step, view));
    break;
  }
  case cYABSPINCONTROLSET: {
    double value = take_number();
    char *id = take_string();

    expect(rk_yab_spincontrol_set(id, value));
    break;
  }
  case cYABOPTIONTEXT: {
    char *text = take_string();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_option_set(id, property, text));
    break;
  }
  case cYABOPTIONNUMBER: {
    double value = take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_option_set_number(id, property, value));
    break;
  }
  case cYABOPTIONCOLOUR: {
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *property = take_string();
    char *id = take_string();

    expect(rk_yab_option_colour(id, property, r, g, b));
    break;
  }
  case cYABTOOLTIP: {
    char *text = take_string();
    char *id = take_string();

    expect(rk_yab_tooltip(id, text));
    break;
  }
  case cYABTABVIEW: {
    char *view = take_string();
    char *side = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_tabview(x1, y1, x2, y2, id, side, view));
    break;
  }
  case cYABTABADD: {
    char *label = take_string();
    char *id = take_string();

    expect(rk_yab_tab_add(id, label));
    break;
  }
  case cYABTABSET: {
    double index = take_number();
    char *id = take_string();

    expect(rk_yab_tab_set(id, index));
    break;
  }
  case cYABTABREMOVE: {
    double index = take_number();
    char *id = take_string();

    expect(rk_yab_tab_remove(id, index));
    break;
  }
  case cYABBOXVIEW: {
    char *view = take_string();
    int line_type = (int)take_number();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_boxview(x1, y1, x2, y2, id, label, line_type, view));
    break;
  }
  case cYABBOXVIEWSET: {
    char *value = take_string();
    char *option = take_string();
    char *id = take_string();

    expect(rk_yab_boxview_set(id, option, value));
    break;
  }
  case cYABSPLITVIEW: {
    char *view = take_string();
    int style = (int)take_number();
    int vertical = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_splitview(x1, y1, x2, y2, id, vertical, style, view));
    break;
  }
  case cYABSTACKVIEW: {
    char *view = take_string();
    int pages = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_stackview(x1, y1, x2, y2, id, pages, view));
    break;
  }
  case cYABSTACKVIEWSET: {
    double index = take_number();
    char *id = take_string();

    expect(rk_yab_stackview_set(id, index));
    break;
  }
  case cYABCANVAS: {
    char *view = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_canvas(x1, y1, x2, y2, id, view));
    break;
  }
  case cYABREGION: {
    char *view = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_region(x1, y1, x2, y2, id, view));
    break;
  }
  /* ---- list family --------------------------------------------------- */
  case cYABLISTBOX: {
    char *view = take_string();
    int bars = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_listbox(x1, y1, x2, y2, id, bars, view));
    break;
  }
  case cYABLISTBOXADD:
  case cYABDROPBOXADD: {
    char *item = take_string();
    char *id = take_string();

    expect(rk_yab_list_add(id, item));
    break;
  }
  case cYABLISTBOXADD2: {
    char *item = take_string();
    double position = take_number();
    char *id = take_string();

    expect(rk_yab_list_add_at(id, position, item));
    break;
  }
  case cYABLISTBOXREMOVE:
  case cYABTREEREMOVE: {
    char *item = take_string();
    char *id = take_string();

    expect(rk_yab_list_remove(id, item));
    break;
  }
  case cYABLISTBOXREMOVE2:
  case cYABTREEREMOVE2:
  case cYABDROPBOXREMOVE: {
    double position = take_number();
    char *id = take_string();

    expect(rk_yab_list_remove_at(id, position));
    break;
  }
  case cYABLISTBOXSELECT:
  case cYABDROPBOXSELECT:
  case cYABTREESELECT:
  case cYABCOLUMNBOXSELECT: {
    double position = take_number();
    char *id = take_string();

    expect(rk_yab_list_select(id, position));
    break;
  }
  case cYABLISTBOXCLEAR:
  case cYABDROPBOXCLEAR:
  case cYABTREECLEAR:
  case cYABCOLUMNBOXCLEAR: {
    char *id = take_string();

    expect(rk_yab_list_clear(id));
    break;
  }
  case cYABLISTSORT:
  case cYABTREESORT: {
    char *id = take_string();

    expect(rk_yab_list_sort(id));
    break;
  }
  case cYABDROPBOX: {
    char *view = take_string();
    char *label = take_string();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_dropbox(x1, y1, x2, y2, id, label, view));
    break;
  }
  case cYABTREEBOX: {
    char *view = take_string();
    int bars = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_treebox(x1, y1, x2, y2, id, bars, view));
    break;
  }
  case cYABMENU: {
    char *view = take_string();
    char *shortcut = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_menu(head, item, shortcut, view));
    break;
  }
  case cYABMENURADIO: {
    char *view = take_string();
    int radio = (int)take_number();
    char *head = take_string();

    expect(rk_yab_menu_radio(head, radio, view));
    break;
  }
  case cYABMENUOPTION: {
    char *view = take_string();
    char *option = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_menu_option(head, item, option, view));
    break;
  }
  case cYABSUBMENU: {
    char *view = take_string();
    char *shortcut = take_string();
    char *subitem = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_submenu(head, item, subitem, shortcut, view));
    break;
  }
  case cYABSUBMENURADIO: {
    char *view = take_string();
    int radio = (int)take_number();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_submenu_radio(head, item, radio, view));
    break;
  }
  case cYABSUBMENUOPTION: {
    char *view = take_string();
    char *option = take_string();
    char *subitem = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_submenu_option(head, item, subitem, option, view));
    break;
  }
  case cYABSUBSUBMENU: {
    char *view = take_string();
    char *shortcut = take_string();
    char *subsubitem = take_string();
    char *subitem = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_subsubmenu(head, item, subitem, subsubitem, shortcut, view));
    break;
  }
  case cYABSUBSUBMENURADIO: {
    char *view = take_string();
    int radio = (int)take_number();
    char *subitem = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(rk_yab_subsubmenu_radio(head, item, subitem, radio, view));
    break;
  }
  case cYABSUBSUBMENUOPTION: {
    char *view = take_string();
    char *option = take_string();
    char *subsubitem = take_string();
    char *subitem = take_string();
    char *item = take_string();
    char *head = take_string();

    expect(
        rk_yab_subsubmenu_option(head, item, subitem, subsubitem, option, view));
    break;
  }
  case cYABATTRIBUTESET: {
    char *file = take_string();
    char *value = take_string();
    char *name = take_string();
    char *type = take_string();

    expect(rk_yab_attribute_set(type, name, value, file));
    break;
  }
  case cYABATTRIBUTECLEAR: {
    char *file = take_string();
    char *name = take_string();

    expect(rk_yab_attribute_clear(name, file));
    break;
  }
  case cYABCLIPBOARDCOPY: {
    char *text = take_string();

    expect(rk_yab_clipboard_copy(text));
    break;
  }
  case cYABBITMAP: {
    char *id = take_string();
    double height = take_number();
    double width = take_number();

    expect(rk_yab_bitmap(width, height, id));
    break;
  }
  case cYABBITMAPDRAW: {
    char *view = take_string();
    char *mode = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_bitmap_draw(x, y, id, mode, view));
    break;
  }
  case cYABBITMAPGET: {
    char *argument = take_string();
    char *option = take_string();
    char *id = take_string();

    expect(rk_yab_bitmap_get(id, option, argument));
    break;
  }
  case cYABBITMAPREMOVE: {
    char *id = take_string();

    expect(rk_yab_bitmap_remove(id));
    break;
  }
  case cYABTREEADD: {
    char *item = take_string();
    char *id = take_string();

    expect(rk_yab_list_add(id, item));
    break;
  }
  case cYABTREEADDCHILD: {
    int expanded = (int)take_number();
    char *item = take_string();
    char *parent = take_string();
    char *id = take_string();

    expect(rk_yab_tree_add_child(id, parent, item, expanded));
    break;
  }
  case cYABTREEADDAT: {
    double position = take_number();
    char *item = take_string();
    char *id = take_string();

    expect(rk_yab_list_add_at(id, position, item));
    break;
  }
  case cYABTREEREMOVECHILD: {
    char *item = take_string();
    char *parent = take_string();
    char *id = take_string();

    expect(rk_yab_tree_remove_child(id, parent, item));
    break;
  }
  case cYABTREEEXPAND:
  case cYABTREECOLLAPSE: {
    char *item = take_string();
    char *id = take_string();

    expect(rk_yab_tree_expand(id, item, cmd->type == cYABTREEEXPAND));
    break;
  }
  case cYABCOLUMNBOX: {
    char *view = take_string();
    char *options = take_string();
    int bars = (int)take_number();
    char *id = take_string();
    double y2 = take_number();
    double x2 = take_number();
    double y1 = take_number();
    double x1 = take_number();

    expect(rk_yab_columnbox(x1, y1, x2, y2, id, bars, options, view));
    break;
  }
  case cYABCOLUMNBOXCOLUMN: {
    char *options = take_string();
    double width = take_number();
    double minimum = take_number();
    double maximum = take_number();
    double position = take_number();
    char *title = take_string();
    char *id = take_string();

    expect(rk_yab_columnbox_column(id, title, position, maximum, minimum,
                                   width, options));
    break;
  }
  case cYABCOLUMNBOXADD: {
    char *text = take_string();
    double height = take_number();
    double position = take_number();
    double column = take_number();
    char *id = take_string();

    expect(rk_yab_columnbox_add(id, column, position, height, text));
    break;
  }
  case cYABCOLUMNBOXREMOVE: {
    double position = take_number();
    char *id = take_string();

    expect(rk_yab_columnbox_remove(id, position));
    break;
  }
  case cYABCOLUMNBOXREMOVECOLUMN: {
    double position = take_number();
    char *id = take_string();

    expect(rk_yab_columnbox_remove_column(id, position));
    break;
  }
  case cYABCOLUMNBOXCOLOUR: {
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *option = take_string();
    char *id = take_string();

    expect(rk_yab_columnbox_colour(id, option, r, g, b));
    break;
  }
  case cYABCALENDAR: {
    char *view = take_string();
    char *date = take_string();
    char *format = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_calendar(x, y, id, format, date, view));
    break;
  }
  case cYABCALENDARSET: {
    char *date = take_string();
    char *id = take_string();

    expect(rk_yab_calendar_set(id, date));
    break;
  }
  case cYABCOLORCONTROL: {
    char *view = take_string();
    char *id = take_string();
    double y = take_number();
    double x = take_number();

    expect(rk_yab_colorcontrol(x, y, id, view));
    break;
  }
  case cYABCOLORCONTROLSET: {
    int b = (int)take_number();
    int g = (int)take_number();
    int r = (int)take_number();
    char *id = take_string();

    expect(rk_yab_colorcontrol_set(id, r, g, b));
    break;
  }
  default:
    error(sERROR, "unknown yab GUI command");
    break;
  }
}
