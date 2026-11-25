# Phase 1 — core compiles on Haiku

This document records what the first Phase 1 commit does, how to build it, and
what is deliberately still missing. It is the working note for the round trip
between the maintainer's Haiku machine and this repository: the cloud
environment cannot run a Haiku build, so the maintainer builds and reports the
compiler output.

## What was done

* `src/` now holds the interpreter: `main.c`, `function.c`, `io.c`,
  `symbol.c`, `foreign.c`, `flow.c`, `flex.c`, `bison.c`, `yabasic.h`,
  `bison.h`, copied from yabasic 2.92.1. The generated parser and scanner
  (`bison.c`, `flex.c`) are checked in, so no bison or flex is needed to build.
* `CMakeLists.txt` builds one executable, `renkubasic`, with
  `mkdir build && cd build && cmake .. && make`.
* `src/config.h` replaces the autoconf-generated header with fixed Haiku
  settings (`VERSION` stays 2.92.1, `RENKU_VERSION` is 0.1.0).
* `src/rk_platform.h`, `src/rk_platform.c` — the platform seam: `rk_os_name()`,
  `rk_yab_os_name()`, `rk_version_banner()`, `rk_default_library_path()` (via
  `find_directory`), `rk_graphics_available()`.
* `src/rk_graphics.c` replaces `graphic.c`. The X11 and Win32 backends are gone;
  the file keeps the interpreter linkable and reports that the window backend
  arrives in Phase 2.
* `bind` removed: the command now fails with an explanatory error, `--bind` and
  `-bind` fail without writing a file, the bound-program trailer loader
  (`isbound`, `seekback`, `mybind`) is deleted, and `whereami.c` went with it
  because `bind` was its only user. `peek("isbound")` still exists and always
  returns 0 (documented cruft).
* `--display` is rejected with an explanation; X11 colour/font-name options are
  no longer advertised in `--help`. `--yab-os-names` was added.
* `peek$("os")` returns `"haiku"` or `"renkuos"`; `peek$("yabos")` returns
  `"Haiku"` or `"RenkuOS"`, which is also what the internal `yabos$` variable
  holds. `peek$("renkuversion")` returns `"0.1.0"`; `peek$("version")` still
  returns the yabasic language level `"2.92.1"`.
* Banners, help text and error messages say RenkuBASIC.

## Building

Requirements on Haiku: `cmake`, a C compiler (`gcc` from the development
package) and `ncurses_devel` (the console layer uses ncurses). For the optional
foreign function interface, `libffi` and its headers are needed as well.

```sh
mkdir build && cd build
cmake ..
make
```

`make clean` in `build` is supported as required by AGENTS.md. No `make
install` is needed.

To check the command line behaviour once the binary exists:

```sh
./renkubasic --version
tests/run-tests.sh --interpreter build/renkubasic --suite cli
```

## What this commit does not attempt

* **No compiled build was made.** The cloud environment is not Haiku and the
  project rules forbid verification builds, so the first build will find the
  first set of compiler errors. They are expected; report them and they will be
  fixed in the next round.
* **No graphic window.** `open window` fails with "open window needs a graphic
  window, and this build has no window backend yet; see BUILDING.md phase 2".
  Consequently `tests/gui` skips (its probe cannot open a window) and
  `tests/manual` cannot run. This is intentional: a silent no-op window would
  make the tests lie.
* **Printing** works only to a named file (`open printer "page.ps"`), which
  writes a small PostScript file. Printing to the Haiku print server is Phase 2,
  together with the window.
* **FFI is off by default** (`-DRK_WITH_FFI=ON` enables it); `tests/cli/c097`
  will skip while it is off.
* **Windows and X11 code** is no longer compiled and the backends are deleted
  with `graphic.c`. The `#ifdef WINDOWS` blocks that remain in the copied core
  files are not compiled either; deleting them file by file is cleanup for a
  later round, and is recorded as cruft in `docs/platform-inventory.md`.

## Expected first-build issues, so they are easy to spot

* `config.h` may be missing a define that autoconf used to supply
  (`HAVE_MKSTEMP`, `HAVE_GETNSTR`, `HAVE_ALLOCA_H` are the likely ones).
* `io.c` and `symbol.c` still contain `#ifdef WINDOWS` branches; they are not
  compiled, but any symbol only defined there will show up as an error if it is
  also used by the compiled path.
* `rk_graphics.c` guesses the stack order of `open window` (`height` pushed
  before `width`, matching the old `openwin`); a wrong guess shows up as a
  swapped `peek("winwidth")`/`peek("winheight")` once windows work, not as a
  compile error.
* `tests/run-tests.sh` calls the interpreter directly; if the binary is not
  executable from the repository root, pass an absolute path.

## Acceptance (2026-11-25)

Accepted on Haiku: `mkdir build && cd build && cmake .. && make` completes with
no warnings, and the CLI suite is green.

```
$ tests/run-tests.sh --interpreter build/renkubasic --suite cli
Summary: 39 passed, 0 failed, 2 skipped
```

The skips are expected, not failures: `c097-ffi` needs `-DRK_WITH_FFI=ON` and
`c096-tty-at-colour` needs a pty. The GUI suite stays unavailable until phase 2
supplies a window backend — the runner detects that by trying to open a window,
so it reports "gui: unavailable" instead of false passes.

### Defects found by the first builds

Three build rounds and one test round, all fixed:

1. `io.c` still called `XPending()`/`ConnectionNumber()` on an X11 `Display`.
   Window input now goes through `rk_window_fd()`/`rk_window_pending()`, which
   return -1/0 until phase 2.
2. ncurses defines `ERR` and `EOF` as the same value, so the placeholder's key
   mapping had a duplicate `case`.
3. The placeholder declared `backpid = 0`; `end_it()` reads 0 as "this process
   is the background redraw helper" and calls `exit(1)`. Every program that
   finished normally therefore exited 1. Upstream declares it -1.
4. `peek$("directory")` was missing from the rewritten `peek2()`; yab 1.8.3's
   `Examples/Version.yab` prints it.
5. The test runner kept a relative `--interpreter` path while changing into each
   test's scratch directory, so every test exited 127.

Two further failures were mistakes in the tests themselves, not the
interpreter: `assert_eq()` was given string arguments (it takes numbers), and
`c083-yab-peeks` asserted yab widget/file extras that belong to phase 3; it now
covers the string peeks phase 1 provides.
