/*
    RenkuBASIC --- yabasic graphics on the Haiku graphic window.

    The drawing logic here follows yabasic 2.92.1's graphic.c: the same stack
    order for every command, the same coordinate transformation from
    `window origin`, the same `new curve` state, the same paper-tape encoding
    for getbit$/putbit. What changed is the backend: instead of Xlib (or GDI)
    every primitive calls the rk_gui_* bridge in rk_gui.cpp, which draws into a
    B_RGB32 BBitmap shown by a BWindow, with TrueType fonts.

    Printing writes PostScript to a named file (open printer "page.ps"); handing
    that file to the Haiku print server is the remaining part of phase 2.
*/

#include "yabasic.h"
#include "rk_gui.h"
#include "rk_platform.h"

/* ------------- global state declared in yabasic.h ---------------- */

int print_to_file = FALSE;
FILE *printerfile = NULL;
double xoff = 0.0;
double xinc = 1.0;
double yoff = 0.0;
double yinc = 1.0;
int winopened = FALSE;
char *winorigin = NULL;
int winwidth = 100;
int winheight = 100;
int displaywidth = 0;
int displayheight = 0;
int mousex = 0;
int mousey = 0;
int mouseb = 0;
int mousemod = 0;
char *ykey[kLASTKEY + 1];
char *text_align = NULL;
int fontheight = 10;
char *foreground = NULL;
char *background = NULL;
char *geometry = NULL;
char *displayname = NULL;
char *fontname = NULL;
int drawmode = 0;
int winpid = 0;
int termpid = 0;
int backpid = -1;

static char *printerfilename = NULL;
static double psscale = 1.0;
static int fore_rgb[3] = {0, 0, 0};
static int back_rgb[3] = {255, 255, 255};
static int bitcount = 0;

static void erasing(int clear) {
  if (clear) {
    rk_gui_set_colour(back_rgb[0], back_rgb[1], back_rgb[2]);
  }
}

static void done_erasing(int clear) {
  if (clear) {
    rk_gui_set_colour(fore_rgb[0], fore_rgb[1], fore_rgb[2]);
  }
}

/* ------------- helpers ---------------- */

static void rk_set_font(char *fname) {
  rk_gui_set_font(fname);
  if (fontname) {
    my_free(fontname);
  }
  fontname = my_strdup(fname);
  fontheight = rk_gui_text_height();
  if (fontheight < 1) {
    fontheight = 10;
  }
}

static int change_font(char *fname) {
  if (!fname || !*fname) {
    return TRUE;
  }
  rk_set_font(fname);
  return TRUE;
}

/* do coordinate transformation from coordinates of yabasic (regarding origin)
   to coordinates of the graphics system */
static void transform(double *x, double *y) {
  double xz, yz, xd, yd;

  switch (winorigin[0]) {
  case 'l':
    xz = 0;
    xd = 1.0;
    break;
  case 'c':
    xz = winwidth / 2;
    xd = 1.0;
    break;
  case 'r':
    xz = winwidth;
    xd = -1.0;
    break;
  default:
    xd = xz = 0;
  }
  switch (winorigin[1]) {
  case 't':
    yz = 0;
    yd = 1.0;
    break;
  case 'c':
    yz = winheight / 2;
    yd = 1.0;
    break;
  case 'b':
    yz = winheight;
    yd = -1.0;
    break;
  default:
    yd = yz = 0;
  }
  *x = xz + (*x) * xd;
  *y = yz + (*y) * yd;
}

static void itransform(int *ix, int *iy) {
  double dx = *ix;
  double dy = *iy;
  transform(&dx, &dy);
  *ix = (int)dx;
  *iy = (int)dy;
}

/* ------------- window ---------------- */

void create_openwin(int fnt) {
  struct command *cmd;

  cmd = add_command(cOPENWIN);
  cmd->args = fnt;
}

void openwin(struct command *cmd) {
  char *fname = NULL;
  int width, height;

  if (winopened) {
    error(sWARNING, "Window already open");
    return;
  }
  if (cmd->args) {
    fname = (char *)pop(stSTRING)->pointer;
  }
  height = (int)pop(stNUMBER)->value;
  if (height < 1) {
    error(sERROR, "winheight less than 1 pixel");
    return;
  }
  width = (int)pop(stNUMBER)->value;
  if (width < 1) {
    error(sERROR, "winwidth less than 1 pixel");
    return;
  }
  winwidth = width;
  winheight = height;
  determine_display_size();
  if (!winorigin) {
    winorigin = my_strdup("lt");
  }
  calc_psscale();
  if (!rk_gui_open_window(winwidth, winheight,
                          progname ? progname : "RenkuBASIC")) {
    sprintf(estring, "could not create window: %s", rk_gui_last_error());
    error(sERROR, estring);
    return;
  }
  rk_gui_set_colour(fore_rgb[0], fore_rgb[1], fore_rgb[2]);
  rk_gui_set_background(back_rgb[0], back_rgb[1], back_rgb[2]);
  if (fname && *fname) {
    rk_set_font(fname);
  } else if (fontname) {
    rk_set_font(fontname);
  }
  winopened = TRUE;
  clearwin();
}

void closewin(void) {
  if (!winopened) {
    error(sWARNING, "Got no window to close");
    return;
  }
  winopened = FALSE;
  rk_gui_close_window();
  if (printerfile) {
    closeprinter();
  }
}

void clearwin(void) {
  if (!winopened) {
    error(sWARNING, "Got no window to clear");
    return;
  }
  rk_gui_clear();
  if (printerfile) {
    fprintf(printerfile, "showpage\n");
    fflush(printerfile);
  }
}

void moveorigin(char *origin) {
  if (origin == NULL) {
    origin = pop(stSTRING)->pointer;
  }
  origin[0] = (char)tolower((int)origin[0]);
  origin[1] = (char)tolower((int)origin[1]);
  if (origin[2] != '\0' || !strchr("lcr", origin[0]) ||
      !strchr("tbc", origin[1])) {
    error(sERROR, "invalid window origin");
    return;
  }
  strcpy(winorigin, origin);
}

void determine_display_size(void) {
  rk_gui_screen_size(&displaywidth, &displayheight);
}

void x11_send_expose(void) {
  /* Historical debugging aid; Haiku windows redraw themselves. */
}

void getwinkey(char *retkey) {
  retkey[0] = '\0';
  rk_gui_next_key(retkey, INBUFFLEN);
}

void gettermkey(char *retkey) {
  int c;

  retkey[0] = '\0';
  c = getch();
  switch (c) {
  case KEY_UP:
    strcpy(retkey, ykey[kUP] ? ykey[kUP] : "up");
    break;
  case KEY_DOWN:
    strcpy(retkey, ykey[kDOWN] ? ykey[kDOWN] : "down");
    break;
  case KEY_LEFT:
    strcpy(retkey, ykey[kLEFT] ? ykey[kLEFT] : "left");
    break;
  case KEY_RIGHT:
    strcpy(retkey, ykey[kRIGHT] ? ykey[kRIGHT] : "right");
    break;
  case KEY_DC:
    strcpy(retkey, ykey[kDEL] ? ykey[kDEL] : "del");
    break;
  case KEY_IC:
    strcpy(retkey, ykey[kINS] ? ykey[kINS] : "ins");
    break;
  case KEY_HOME:
    strcpy(retkey, ykey[kHOME] ? ykey[kHOME] : "home");
    break;
  case KEY_END:
    strcpy(retkey, ykey[kEND] ? ykey[kEND] : "end");
    break;
  case ERR: /* also EOF */
    break;
  default:
    if (c >= 0 && c < 256) {
      retkey[0] = (char)c;
      retkey[1] = '\0';
    }
    break;
  }
}

/* ------------- drawing ---------------- */

int check_alignment(char *al) {
  if (!al || !al[0] || !al[1]) {
    return FALSE;
  }
  al[0] = (char)tolower((int)al[0]);
  al[1] = (char)tolower((int)al[1]);
  if (!strchr("clr", al[0]) || !strchr("ctb", al[1])) {
    return FALSE;
  }
  return TRUE;
}

/* Spelling kept from the phase 1 placeholder; the implementation is the same
   check as yabasic's check_alignment(). */
int check_alignement(char *al) {
  char horizontal, vertical;

  if (!al || strlen(al) != 2) {
    return FALSE;
  }
  horizontal = (char)tolower((int)al[0]);
  vertical = (char)tolower((int)al[1]);
  if (!strchr("clr", horizontal) || !strchr("ctb", vertical)) {
    return FALSE;
  }
  return TRUE;
}

void putindrawmode(int mode) {
  if (mode) {
    last_cmd->tag = mode;
  } else {
    last_cmd->tag = drawmode;
  }
  drawmode = 0;
}

void dot(struct command *cmd) {
  double x, y;

  y = pop(stNUMBER)->value;
  x = pop(stNUMBER)->value;
  transform(&x, &y);
  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  erasing(cmd->tag & dmCLEAR);
  rk_gui_point(x, y);
  done_erasing(cmd->tag & dmCLEAR);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "%g %g (%c) DO\n", (x - 0.5) * psscale,
            (winheight - y + 0.5) * psscale,
            (cmd->tag & dmCLEAR) ? 'y' : 'n');
  }
}

void create_line(int numpoints) {
  struct command *cmd;

  cmd = add_command(cLINE);
  cmd->args = numpoints;
  cmd->tag = dmNORMAL;
}

void line(struct command *cmd) {
  double x1, y1, x2, y2;
  static double lastx, lasty;
  static int lastvalid = FALSE;
  static double initialx, initialy;
  static int initialvalid = FALSE;
  int numpoints;
  int clear;

  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  clear = cmd->tag & dmCLEAR;
  numpoints = cmd->args;
  if (numpoints == -1) {
    /* new curve */
    lastvalid = FALSE;
    initialvalid = FALSE;
    return;
  } else if (numpoints == 0) {
    /* close curve */
    if (!lastvalid || !initialvalid) {
      return;
    }
    lastvalid = FALSE;
    initialvalid = FALSE;
    x1 = lastx;
    y1 = lasty;
    x2 = initialx;
    y2 = initialy;
  } else {
    y2 = pop(stNUMBER)->value;
    x2 = pop(stNUMBER)->value;
    if (numpoints == 1) {
      if (!lastvalid) {
        initialx = lastx = x2;
        initialy = lasty = y2;
        initialvalid = lastvalid = TRUE;
        return;
      }
      y1 = lasty;
      x1 = lastx;
    } else {
      y1 = pop(stNUMBER)->value;
      x1 = pop(stNUMBER)->value;
    }
  }
  lastx = x2;
  lasty = y2;
  if (!initialvalid) {
    initialx = x1;
    initialy = y2;
    initialvalid = TRUE;
  }
  transform(&x1, &y1);
  transform(&x2, &y2);
  erasing(clear);
  rk_gui_line(x1, y1, x2, y2);
  done_erasing(clear);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "%g %g %g %g (%c) LI\n", x1 * psscale,
            (winheight - y1) * psscale, x2 * psscale,
            (winheight - y2) * psscale, clear ? 'y' : 'n');
    fflush(printerfile);
  }
}

void change_colour(struct command *cmd) {
  int r, g, b;

  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  if (cmd->type == cGCOLOUR || cmd->type == cGBACKCOLOUR) {
    b = (int)pop(stNUMBER)->value;
    g = (int)pop(stNUMBER)->value;
    r = (int)pop(stNUMBER)->value;
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
      sprintf(string,
              "arguments to command colour must be between 0 and 255 (not "
              "%d,%d,%d)",
              r, g, b);
      error(sERROR, string);
      return;
    }
  } else {
    char *h = (char *)(pop(stSTRING)->pointer);
    if (sscanf(h, "%d,%d,%d", &r, &g, &b) != 3 || r < 0 || r > 255 ||
        g < 0 || g > 255 || b < 0 || b > 255) {
      sprintf(string,
              "string argument to command colour must be three numbers between "
              "0 and 255, separated by commas (not '%s')",
              h);
      error(sERROR, string);
      return;
    }
  }
  if (cmd->type == cGCOLOUR || cmd->type == cGCOLOUR2) {
    fore_rgb[0] = r;
    fore_rgb[1] = g;
    fore_rgb[2] = b;
    rk_gui_set_colour(r, g, b);
  } else {
    back_rgb[0] = r;
    back_rgb[1] = g;
    back_rgb[2] = b;
    rk_gui_set_background(r, g, b);
  }
}

void circle(struct command *cmd) {
  double x, y, r;
  int fill, clear;

  fill = cmd->tag & dmFILL;
  clear = cmd->tag & dmCLEAR;
  r = pop(stNUMBER)->value;
  y = pop(stNUMBER)->value;
  x = pop(stNUMBER)->value;
  transform(&x, &y);
  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  erasing(clear);
  rk_gui_ellipse(x, y, r, r, fill);
  done_erasing(clear);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "N\n");
    fprintf(printerfile, "%g %g %g (%c) (%c) CI\n", (winheight - y) * psscale,
            x * psscale, r * psscale, clear ? 'y' : 'n', fill ? 'y' : 'n');
    fflush(printerfile);
  }
}

void triangle(struct command *cmd) {
  double x0, y0, x1, y1, x2, y2;
  double points[8];
  int fill, clear;

  fill = cmd->tag & dmFILL;
  clear = cmd->tag & dmCLEAR;
  y2 = pop(stNUMBER)->value;
  x2 = pop(stNUMBER)->value;
  y1 = pop(stNUMBER)->value;
  x1 = pop(stNUMBER)->value;
  y0 = pop(stNUMBER)->value;
  x0 = pop(stNUMBER)->value;
  transform(&x0, &y0);
  transform(&x1, &y1);
  transform(&x2, &y2);
  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  points[0] = x0;
  points[1] = y0;
  points[2] = x1;
  points[3] = y1;
  points[4] = x2;
  points[5] = y2;
  points[6] = x0;
  points[7] = y0;
  erasing(clear);
  rk_gui_polygon(points, 4, fill);
  done_erasing(clear);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "N\n");
    fprintf(printerfile, "%g %g %g %g %g %g (%c) (%c) TRI\n", x0 * psscale,
            (winheight - y0) * psscale, x1 * psscale,
            (winheight - y1) * psscale, x2 * psscale,
            (winheight - y2) * psscale, clear ? 'y' : 'n', fill ? 'y' : 'n');
    fflush(printerfile);
  }
}

void text(struct command *cmd) {
  double x, y;
  char *txt;
  char *arg1 = NULL;
  char *arg2 = NULL;
  char *align = NULL;
  char *fname = NULL;
  int xoffset, yoffset;

  if (cmd->type == cTEXT3) {
    arg2 = pop(stSTRING)->pointer;
  }
  if (cmd->type == cTEXT2 || cmd->type == cTEXT3) {
    arg1 = pop(stSTRING)->pointer;
  }
  if (arg1) {
    if (check_alignment(arg1)) {
      align = arg1;
    } else {
      fname = arg1;
    }
  }
  if (arg2) {
    if (check_alignment(arg2)) {
      if (align) {
        sprintf(string, "Found two possible alignments: '%s' and '%s'", arg1,
                arg2);
        error(sERROR, string);
      }
      align = arg2;
    } else {
      fname = arg2;
    }
  }
  if (arg1 && arg2 && !align) {
    error(sERROR, "There should be a specification for a text alignment (e.g. "
                  "'ct')");
    error(sERROR, "among the last two arguments");
    return;
  }
  if (!align) {
    align = text_align;
  }
  if (fname && !change_font(fname)) {
    return;
  }
  txt = pop(stSTRING)->pointer;
  y = pop(stNUMBER)->value;
  x = pop(stNUMBER)->value;
  transform(&x, &y);
  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  if (align[0] == 'l') {
    xoffset = 0;
  } else if (align[0] == 'r') {
    xoffset = -rk_gui_text_width(txt);
  } else {
    xoffset = -rk_gui_text_width(txt) / 2;
  }
  if (align[1] == 't') {
    yoffset = fontheight;
  } else if (align[1] == 'b') {
    yoffset = 0;
  } else {
    yoffset = fontheight / 2;
  }
  rk_gui_text(x + xoffset, y + yoffset, txt);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "%g %g (%c) (%s) AT\n", x * psscale,
            (winheight - y - yoffset) * psscale, align[0], txt);
  }
}

void rect(struct command *cmd) {
  int fill, clear;
  double x1, y1, x2, y2, s;

  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  fill = cmd->tag & dmFILL;
  clear = cmd->tag & dmCLEAR;
  y2 = pop(stNUMBER)->value;
  x2 = pop(stNUMBER)->value;
  y1 = pop(stNUMBER)->value;
  x1 = pop(stNUMBER)->value;
  transform(&x1, &y1);
  transform(&x2, &y2);
  if (x1 > x2) {
    s = x2;
    x2 = x1;
    x1 = s;
  }
  if (y1 > y2) {
    s = y2;
    y2 = y1;
    y1 = s;
  }
  erasing(clear);
  rk_gui_rect(x1, y1, x2, y2, fill);
  done_erasing(clear);
  rk_gui_flush();
  if (printerfile) {
    fprintf(printerfile, "%g %g %g %g (%c) (%c) RE\n", x1 * psscale,
            (winheight - y1) * psscale, x2 * psscale,
            (winheight - y2) * psscale, clear ? 'y' : 'n', fill ? 'y' : 'n');
    fflush(printerfile);
  }
}

void calc_psscale(void) {
  if ((float)winwidth / winheight > (float)18 / 25) {
    psscale = 18 * 0.39 * 72 / winwidth;
  } else {
    psscale = 25 * 0.39 * 72 / winheight;
  }
  xoff = 0.0;
  xinc = 1.0;
  yoff = 0.0;
  yinc = 1.0;
}

/* ------------- bitmaps ---------------- */

static char *newrgb(int w, int h) {
  char *bits;

  sprintf(string, "rgb %d,%d:", w, h);
  bits = my_malloc(strlen(string) + ((size_t)w * h * 6) + 2);
  strcpy(bits, string);
  bitcount = 0;
  return bits;
}

static void addrgb(char *bits, unsigned short red, unsigned short green,
                   unsigned short blue) {
  static char *pbits;

  if (bitcount == 0) {
    pbits = bits + strlen(bits);
  }
  bitcount++;
  sprintf(pbits, "%02x%02x%02x", red, green, blue);
  pbits += 6;
}

static int readrgb(char *bits, int off, unsigned short *red,
                   unsigned short *green, unsigned short *blue) {
  static char *bitpt;
  static char *bitstart;
  int r, g, b;
  int scanned;

  if (bits) {
    bitpt = bits + off;
    bitstart = bits;
    return 1;
  }
  scanned = sscanf(bitpt, "%02x%02x%02x", &r, &g, &b);
  if (scanned == 3) {
    if (red) {
      *red = (unsigned short)r;
    }
    if (green) {
      *green = (unsigned short)g;
    }
    if (blue) {
      *blue = (unsigned short)b;
    }
    bitpt += 6;
    return 1;
  }
  if (scanned == EOF) {
    sprintf(estring, "Invalid bitmap: unexpected end of supplied string");
  } else {
    sprintf(estring,
            "Invalid bitmap: could only extract %d hex-values from supplied "
            "string at position %ld: '%.6s'",
            scanned, (long)(bitpt - bitstart), bitpt);
  }
  error(sERROR, estring);
  return 0;
}

void putbit(void) {
  char *mode;
  char *bitstring;
  char m;
  int xe, ye, we, he;
  int x, y, xdest, ydest, w, h, n;
  unsigned short red, green, blue;
  int r, g, b;

  mode = pop(stSTRING)->pointer;
  if (print_to_file) {
    error(sERROR, "Cannot putbit to printer");
    return;
  }
  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return;
  }
  for (char *pm = mode; *pm; pm++) {
    *pm = (char)tolower(*pm);
  }
  if (!strncmp(mode, "solid", strlen(mode))) {
    m = 's';
  } else if (strlen(mode) && !strncmp(mode, "transparent", strlen(mode))) {
    m = 't';
  } else {
    sprintf(string,
            "Invalid mode for putbit: '%s', only 'solid' and 'transparent' are "
            "allowed",
            mode);
    error(sERROR, string);
    return;
  }
  ydest = (int)pop(stNUMBER)->value;
  xdest = (int)pop(stNUMBER)->value;
  itransform(&xdest, &ydest);
  bitstring = pop(stSTRING)->pointer;
  if (sscanf(bitstring, "rgb %d,%d:%n", &w, &h, &n) != 2 || w < 0 || h < 0) {
    error(sERROR,
          "Invalid bitmap (must start with 'rgb X,Y:', where X and Y are >0)");
    return;
  }
  if (xdest >= winwidth || ydest >= winheight || xdest + w < 0 ||
      ydest + h < 0) {
    return;
  }
  xe = xdest;
  ye = ydest;
  we = w;
  he = h;
  if (xe < 0) {
    we += xe;
    xe = 0;
  }
  if (ye < 0) {
    he += ye;
    ye = 0;
  }
  if (we > winwidth - xe) {
    we = winwidth - xe;
  }
  if (he > winheight - ye) {
    he = winheight - ye;
  }
  readrgb(bitstring, n, NULL, NULL, NULL);
  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
      if (!readrgb(NULL, 0, &red, &green, &blue)) {
        sprintf(estring,
                "error while reading line %d of %d, pixel %d of %d from string",
                y + 1, h, x + 1, w);
        error(sERROR, estring);
        return;
      }
      if (x + xdest >= xe && x + xdest < xe + we && y + ydest >= ye &&
          y + ydest < ye + he) {
        if (m == 't' && red == back_rgb[0] && green == back_rgb[1] &&
            blue == back_rgb[2]) {
          continue;
        }
        rk_gui_set_pixel(xdest + x, ydest + y, red, green, blue);
      }
    }
  }
  rk_gui_flush();
}

char *getbit(int x1, int y1, int x2, int y2) {
  int s, x, y;
  int xe1, ye1, xe2, ye2;
  char *bitstring;

  if (!winopened) {
    error(sERROR, "Got no window to draw");
    return my_strdup("");
  }
  itransform(&x1, &y1);
  itransform(&x2, &y2);
  if (x2 < x1) {
    s = x1;
    x1 = x2;
    x2 = s;
  }
  if (y2 < y1) {
    s = y1;
    y1 = y2;
    y2 = s;
  }
  xe1 = x1;
  ye1 = y1;
  xe2 = x2;
  ye2 = y2;
  if (xe1 < 0) {
    xe1 = 0;
  }
  if (ye1 < 0) {
    ye1 = 0;
  }
  if (xe2 >= winwidth) {
    xe2 = winwidth - 1;
  }
  if (ye2 >= winheight) {
    ye2 = winheight - 1;
  }
  bitstring = newrgb(x2 - x1 + 1, y2 - y1 + 1);
  for (y = y1; y <= y2; y++) {
    for (x = x1; x <= x2; x++) {
      int r = back_rgb[0];
      int g = back_rgb[1];
      int b = back_rgb[2];
      if (x >= xe1 && x <= xe2 && y >= ye1 && y <= ye2) {
        rk_gui_get_pixel(x, y, &r, &g, &b);
      }
      addrgb(bitstring, (unsigned short)r, (unsigned short)g,
             (unsigned short)b);
    }
  }
  return bitstring;
}

char *getreg(char *name) {
  (void)name;
  return NULL; /* the Windows registry does not exist on Haiku */
}

/* ------------- printing ---------------- */

static void rk_print_header(void) {
  fprintf(printerfile, "%%!PS-Adobe-3.0\n");
  fprintf(printerfile, "%%%%Creator: RenkuBASIC %s\n", RENKU_VERSION);
  fprintf(printerfile, "%%%%Title: %s\n",
          main_file_name ? main_file_name : "RenkuBASIC program");
  fprintf(printerfile, "%%%%Pages: 1\n");
  fprintf(printerfile, "%%%%EndComments\n");
  fprintf(printerfile, "%%%%Page: 1 1\n");
  fprintf(printerfile, "gsave\n");
}

static void rk_print_footer(void) {
  fprintf(printerfile, "grestore\n");
  fprintf(printerfile, "showpage\n");
  fprintf(printerfile, "%%%%EOF\n");
}

void create_openprinter(int num) {
  struct command *cmd;

  cmd = add_command(cOPENPRN);
  cmd->args = num;
}

void openprinter(struct command *cmd) {
  if (printerfile) {
    closeprinter();
  }
  if (cmd->args == 1) {
    printerfilename = my_strdup((char *)(pop(stSTRING)->pointer));
    print_to_file = TRUE;
  } else {
    printerfilename = my_strdup("");
    print_to_file = FALSE;
  }
  if (*printerfilename == '\0') {
    sprintf(estring,
            "printing to a printer needs the Haiku print server, which is "
            "still to be wired up; supply a filename instead: open printer "
            "\"page.ps\"");
    error(sERROR, estring);
    return;
  }
  if (!(printerfile = fopen(printerfilename, "w"))) {
    sprintf(estring, "could not open '%s' for printing: %s", printerfilename,
            my_strerror(errno));
    error(sERROR, estring);
    return;
  }
  rk_print_header();
}

void closeprinter(void) {
  if (!printerfile) {
    return;
  }
  rk_print_footer();
  fclose(printerfile);
  printerfile = NULL;
  if (printerfilename) {
    my_free(printerfilename);
    printerfilename = NULL;
  }
}
