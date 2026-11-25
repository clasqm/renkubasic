/*
    RenkuBASIC --- a yab-compatible BASIC for Haiku and RenkuOS,
    based on yabasic 2.92.1 by Marc Ihm.

    config.h --- build configuration for the Haiku port.

    The upstream project generates this file with autoconf. RenkuBASIC is
    built with CMake on Haiku only, so the settings are fixed here instead of
    being probed at configure time. Keep this file small: everything that can
    be decided by CMake belongs in CMakeLists.txt.
*/

#ifndef RK_CONFIG_H
#define RK_CONFIG_H

/* Language level, reported by peek$("version") and in the banner. This must
   stay at the yabasic version whose behaviour RenkuBASIC implements. */
#define VERSION "2.92.1"
#define PACKAGE_VERSION "2.92.1"

/* RenkuBASIC release number, reported by peek$("renkuversion"). */
#define RENKU_VERSION "0.1.0"

/* What the graphic window edition is called in the banner. */
#define RENKU_EDITION "Haiku edition"

/* yabasic.h maps ARCHITECTURE to this for the UNIX build flavour. */
#define UNIX_ARCHITECTURE "haiku"

/* Shown by --version and in debug output. A fixed string keeps the build
   reproducible; see the note next to BANNER in main.c. */
#define BUILD_TIME "Haiku build"

/* Headers and functions available on Haiku. */
#define HAVE_NCURSES_H 1
#define HAVE_STRERROR 1
#define HAS_STRING_HEADER 1
#define HAVE_ALLOCA_H 1
#define HAVE_GETNSTR 1
#define HAVE_MKSTEMP 1

/* Haiku has no /proc and no prctl. */
#undef HAVE_PRCTL_H
#undef HAVE_LINUX_PERF_EVENT_H

/* Foreign function interface. Set by CMake when libffi is found. */
#ifndef RK_WITH_FFI
#undef USE_DL_FFI
#endif

/* Default library search path. Overridden at runtime by rk_default_library_path()
   and by --librarypath. */
#define LIBRARY_PATH "/boot/system/non-packaged/lib"

#endif /* RK_CONFIG_H */
