/*
    RenkuBASIC --- graphic window and printer, Phase 1 placeholder.

    yabasic 2.92.1 implements this file twice over: once with Xlib and once with
    the Win32 GDI. RenkuBASIC deletes both (see docs/platform-inventory.md) and
    will implement the window on a Haiku BWindow/BBitmap in Phase 2, reusing
    yab's View class for the drawing primitives.

    Until that backend exists this file keeps the interpreter linkable and
    behaves honestly:

      * `open window` fails with an explanatory error, so no program believes
        it has a window and no test silently passes;
      * `open printer "file"` still writes a PostScript file, because that path
        is plain stdio and is useful before the window exists;
      * console handling (clear screen, at, colour, inkey) is NOT here: it
        lives in io.c and uses ncurses, which Haiku provides.

    Everything declared in yabasic.h's "graphic.c" section is defined below so
    that the rest of the interpreter links. When the Haiku backend arrives,
    replace this file; do not grow it into a second renderer.
*/

#include "yabasic.h"
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
int backpid = 0;

static char *printerfilename = NULL;
static int openwin_font = 0;

/* ------------- helpers ---------------- */

static void rk_no_graphics(const char *what) {
  sprintf(estring,
          "%s needs a graphic window, and this build has no window backend "
          "yet; see BUILDING.md phase 2",
          what);
  error(sERROR, estring);
}

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

/* ------------- window ---------------- */

void create_openwin(int fnt) { openwin_font = fnt; }

void openwin(struct command *cmd) {
  double h, w;

  (void)cmd;
  h = pop(stNUMBER)->value;
  w = pop(stNUMBER)->value;
  if (!rk_graphics_available()) {
    rk_no_graphics("open window");
    return;
  }
  winwidth = (int)w;
  winheight = (int)h;
  winopened = TRUE;
}

void closewin(void) { winopened = FALSE; }

void clearwin(void) {
  if (!winopened) {
    rk_no_graphics("clear window");
  }
}

void moveorigin(char *origin) {
  if (winorigin) {
    my_free(winorigin);
  }
  winorigin = my_strdup(origin);
}

void determine_display_size(void) {
  /* Haiku's default screen is large; the real value comes from BScreen in
     phase 2. Reporting a value here keeps peek("displaywidth") usable. */
  displaywidth = 1920;
  displayheight = 1080;
}

void x11_send_expose(void) {
  /* Historical debugging aid, kept as documented cruft: there is no X11
     expose event on Haiku. */
}

void getwinkey(char *retkey) { retkey[0] = '\0'; }

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
  case ERR:
  case EOF:
    break;
  default:
    if (c < 256) {
      retkey[0] = (char)c;
      retkey[1] = '\0';
    }
    break;
  }
}

/* ------------- drawing ---------------- */

int check_alignment(char *al) {
  if (!al || strlen(al) != 2) {
    return FALSE;
  }
  return check_alignement(al);
}

int check_alignement(char *al) {
  char horizontal, vertical;

  horizontal = al[0];
  vertical = al[1];
  if (horizontal != 'l' && horizontal != 'c' && horizontal != 'r') {
    return FALSE;
  }
  if (vertical != 'b' && vertical != 't' && vertical != 'c') {
    return FALSE;
  }
  return TRUE;
}

void putindrawmode(int mode) { drawmode = mode; }

void dot(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("dot");
}

void create_line(int numpoints) { (void)numpoints; }

void line(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("line");
}

void circle(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("circle");
}

void triangle(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("triangle");
}

void create_text(int num) { (void)num; }

void text(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("text");
}

void rect(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("rectangle");
}

void change_colour(struct command *cmd) {
  (void)cmd;
  rk_no_graphics("color");
}

void putbit(void) { rk_no_graphics("putbit"); }

char *getbit(int x1, int y1, int x2, int y2) {
  (void)x1;
  (void)y1;
  (void)x2;
  (void)y2;
  rk_no_graphics("getbit$");
  return my_strdup("");
}

char *getreg(char *name) {
  (void)name;
  return NULL; /* the Windows registry does not exist on Haiku */
}

void calc_psscale(void) {
  xoff = 0.0;
  xinc = 1.0;
  yoff = 0.0;
  yinc = 1.0;
}

/* ------------- printing ---------------- */

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
            "added in phase 2; supply a filename instead: open printer "
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
