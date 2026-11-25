/*
    RenkuBASIC --- platform seam.

    Everything the interpreter needs to know about the operating system it is
    running on is declared here. The implementation (rk_platform.c) is the only
    file that includes Haiku headers for this purpose; the rest of the
    interpreter stays platform-neutral.

    Phase 1 implements: operating system detection, the version banner, the
    default library path and the availability flag for the graphic window.
    Later phases add the BApplication, BWindow and print server pieces here.
*/

#ifndef RK_PLATFORM_H
#define RK_PLATFORM_H

#include <stdio.h>

/* True when --yab-os-names was given: make peek$("os") report the yab
   spelling ("Haiku") for programs that compare against it. */
extern int rk_yab_os_names;

/* "haiku" on Haiku, "renkuos" on RenkuOS (detected by the release marker),
   "unix" elsewhere. Lower case, as required for peek$("os"). */
const char *rk_os_name(void);

/* The yab spelling: "Haiku", "RenkuOS" or, on a system that is neither,
   the value of rk_os_name(). Used for peek$("yabos") and for the yabos$
   internal variable. */
const char *rk_yab_os_name(void);

/* The full --version line, including the yabasic language level. */
const char *rk_version_banner(void);

/* Default library directory, chosen with Haiku's find_directory(). The pointer
   stays valid for the life of the process. */
const char *rk_default_library_path(void);

/* 1 when a graphic window backend is compiled in and usable. Phase 1 has
   none, so the window commands fail with an explanatory message instead of
   pretending to draw. */
int rk_graphics_available(void);

#endif /* RK_PLATFORM_H */
