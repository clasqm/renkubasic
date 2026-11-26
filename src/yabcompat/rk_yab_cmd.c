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

    expect(rk_yab_view_set_font(value, view));
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
  default:
    error(sERROR, "unknown yab GUI command");
    break;
  }
}
