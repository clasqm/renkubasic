/*
    RenkuBASIC --- platform seam implementation.

    This file is the only place that talks to the operating system about who
    we are and where things live. It uses Haiku's find_directory() instead of
    hard coded /usr or /etc paths, as required by the project rules.

    Compiles on Haiku; the non-Haiku branches exist so the test suite can be
    built on a development machine and are not a supported target.
*/

#include "yabasic.h"
#include "rk_platform.h"

#include <string.h>

#ifdef __HAIKU__
#include <FindDirectory.h>
#include <StorageDefs.h>
#include <unistd.h>
#include <sys/types.h>
#endif

int rk_yab_os_names = FALSE;

/* Marker file that distinguishes RenkuOS from plain Haiku. RenkuOS installs
   this file in its system data directory; plain Haiku does not have it. */
#define RK_RENKUOS_MARKER "/boot/system/data/renkuos/release"

static int rk_is_haiku(void) {
#ifdef __HAIKU__
  return TRUE;
#else
  return FALSE;
#endif
}

const char *rk_os_name(void) {
  const char *override = getenv("RK_OS");

  if (override && *override) {
    return override; /* test hook: RK_OS=renkuos */
  }
  if (rk_yab_os_names) {
    return rk_yab_os_name();
  }
  if (!rk_is_haiku()) {
    return "unix";
  }
#ifdef __HAIKU__
  if (access(RK_RENKUOS_MARKER, F_OK) == 0) {
    return "renkuos";
  }
#endif
  return "haiku";
}

const char *rk_yab_os_name(void) {
  if (!rk_is_haiku()) {
    return rk_os_name();
  }
#ifdef __HAIKU__
  if (access(RK_RENKUOS_MARKER, F_OK) == 0) {
    return "RenkuOS";
  }
#endif
  return "Haiku";
}

const char *rk_version_banner(void) {
  static char banner[160];
  static int initialized = FALSE;

  if (!initialized) {
    if (!strcmp(rk_yab_os_name(), "RenkuOS")) {
      snprintf(banner, sizeof(banner),
               "RenkuBASIC %s (yabasic language level %s, RenkuOS edition)",
               RENKU_VERSION, VERSION);
    } else {
      snprintf(banner, sizeof(banner),
               "RenkuBASIC %s (yabasic language level %s, %s)", RENKU_VERSION,
               VERSION, RENKU_EDITION);
    }
    initialized = TRUE;
  }
  return banner;
}

const char *rk_default_library_path(void) {
  static char path[B_PATH_NAME_LENGTH];
  static int initialized = FALSE;

  if (initialized) {
    return path;
  }
  path[0] = '\0';
#ifdef __HAIKU__
  {
    /* 0 selects the boot volume, which is where Haiku and RenkuOS live.
       Libraries shipped with the user's own (non-packaged) software win over
       the system ones, which matches how yab searched its home directory. */
    if (find_directory(B_USER_NONPACKAGED_LIB_DIRECTORY, 0, TRUE, path,
                       sizeof(path)) != B_OK) {
      if (find_directory(B_SYSTEM_NONPACKAGED_DIRECTORY, 0, TRUE, path,
                         sizeof(path)) == B_OK) {
        strncat(path, "/lib", sizeof(path) - strlen(path) - 1);
      }
    }
  }
#endif
  if (!path[0]) {
    strncpy(path, LIBRARY_PATH, sizeof(path) - 1);
  }
  initialized = TRUE;
  return path;
}

int rk_graphics_available(void) {
  /* Phase 2 supplies the BWindow/BBitmap backend. Until then the window
     commands must say so rather than silently drawing into nothing. */
  return FALSE;
}
