# Platform and feature inventory

Phase 0 deliverable, companion to [BUILDING.md](../BUILDING.md). Every item below was found
in the reference trees that ship with this project:

* `yabasic/yabasic-2.92.1/` — interpreter core, taken as the language baseline.
* `yab/yab-1.8.3/` — the compatibility target.

File/line references are to those trees and are given so the Phase 1 edits can be made and
reviewed without re-reading 20 000 lines. "Cascade" says how far a removal spreads.

---

## 1. Operating-system detection

| Where | What it does today | RenkuBASIC |
| --- | --- | --- |
| `function.c:1892` (`peek$("os")`) | `#ifdef UNIX` → `"unix"`, else `"windows"` | `"haiku"`, `"renkuos"`, `"unix"`, `"windows"` (runtime, not compile time) |
| `yab` examples (`AllInOne.yab:12`) | `if(peek$("os") = "Haiku")` | still works via `peek$("yabos")` or `--yab-os-names` (BUILDING.md Q3) |
| `main.c:1152` | pushes the literal `"windows"` into the `os` symbol for bound programs | removed with `bind` |
| `README`, `yabasic.htm` ch. 2/3 | "under Windows" / "under Unix" chapters | replaced by one "Running RenkuBASIC" chapter (Phase 3) |

`peek$("os")` is the only OS query; there is no compile-time constant in the language, so
detection is a runtime string and needs no grammar change.

---

## 2. Windows-only abilities (removal requested — Q1)

| Ability | Location | Notes | Cascade |
| --- | --- | --- | --- |
| Graphic window via GDI | `graphic.c` (`#ifdef WINDOWS` from line 50: `winthread`, `startdraw`, `enddraw`, `wndproc`, GDI pens/brushes) | whole `#ifdef WINDOWS` branch | self-contained; replaced by Haiku backend |
| Font selection by Windows style+size (`swiss10`) | `graphic.c:967` `CreateFontIndirect`; `main.c` `--font` help text | contrasts with X11 names; neither survives | replaced by TrueType family/style/size parser |
| Console handling via Win32 API | `io.c` `#ifdef WINDOWS` (lines 58, 138, 205, 239, 269, 336, 516, 717, 865, 1283, 1835, 1945): cursor, colours, `ClearConsoleScreen`, `_kbhit`/`_getch`, ANSI enable | includes `clear screen`, `at()`, `color()`, `getscreen$`/`putscreen`, `inkey$` | replaced by ncurses path (already used by yab on Haiku) |
| Cursor position | `function.c:1736-1770` `peek("screenposx"/"screenposy")` | X11 branch uses curses `getyx`, Windows branch uses `GetConsoleScreenBufferInfo` | keep the peek, keep the curses branch |
| Printer via winspool | `graphic.c:64-70`, `graphic.c:967-1055`, `io.c:810` `GetProfileString("windows","device",…)` | device-context printing | replaced by PostScript file (see §4) |
| Millisecond clock | `function.c:1997` `GetTickCount()` | vs `clock_gettime` | keep the POSIX branch |
| Command-line arguments quoting | `main.c:621-700` (`#ifdef UNIX` re-splits `argv[1]`) | Windows does not split; Unix does | keep the Unix behaviour |
| `.exe` suffix / bound executables | `main.c:2613` `mybind`, bound-trailer reader `main.c:2460` | only exists to make a standalone `.exe` | removed with `bind` |
| `--font` style list (decorative/dontcare/…) | `main.c:735-745` | Windows-only help text | removed |
| Windows filename chapter (drive letters, backslashes) | `yabasic.htm` §"Specifying Filenames under Windows" | docs only | removed from the manual |

No further Windows dependencies were found in `symbol.c`, `flow.c`, `whereami.c` or
`foreign.c`; `whereami.c` has a Windows branch for locating the running executable, which is
only needed by `bind`.

---

## 3. Unix/X11-only abilities (removal or replacement requested — Q2)

| Ability | Location | RenkuBASIC |
| --- | --- | --- |
| Graphic window via Xlib | `graphic.c:19-295` (`XOpenDisplay`, `XCreateWindow`, `XNextEvent`, `XDrawLine`, `XFillRectangle`, `pixmap`), `yabasic.h:61-66` | **remove**; Haiku `BWindow`/`BBitmap` backend |
| X11 colour names and `-fg`/`-bg` | `main.c:750-775`, `graphic.c` colour parsing | **remove** switch; keep RGB triplets and the named-colour table used by yab (`draw set`) |
| `--display`, `--geometry` | `main.c:750-780`, X11 window placement | `--geometry` **keep** (place the Haiku window); `--display` **remove** |
| X11/bitmap fonts | `graphic.c` `change_font`, `fontname`, `--font` | **replace** with TrueType/OpenType via `BFont` (BUILDING.md §5.3) |
| Terminal control via ncurses | `io.c:283-300` `curinit`, `initcol`, `graphic.c:22` `#include <curses.h>` | **keep**; Haiku ships ncurses, and yab already links `-lncurses` |
| `inkey$` mouse encoding (`MB1+…`, `MB2+…`) | `graphic.c:2464` `getwinkey` (Windows) / ncurses `KEY_MOUSE` | **keep** as the documented encoding, fed by the Haiku backend |
| Printing via `/usr/bin/lpr` | `io.c:744` hard-coded `/usr/bin/lpr`, `graphic.c:2446` `lpr …` | **replace**: write PostScript to a file, then hand it to Haiku's print server (or `launch`) — no `/usr` on Haiku |
| `open printer` PostScript output | `graphic.c:1032` `psscale`, `%g %g (%c) DO` | keep the PostScript writer (portable), change only delivery |
| `system`/`system$` via `popen`/`fork` | `io.c`, `function.c:1175` `do_system2`, `function.c:1262` `do_system` | **keep** (POSIX spawn works on Haiku); document `system` returns the raw wait status |
| `/proc/self/exe` style self-location | `whereami.c` | only used by `bind`; removed |
| `HOME`-based config | none found (no `~/.yabasicrc` in 2.92.1) | nothing to do |

Not Unix-only but worth listing because it *looks* portable: `date$`/`time$` are hard-wired
to `%w-%m-%d-%Y-%a-%b` / `%H-%M-%S` (`function.c:838,844`). That format is part of the
language (yab programs split on `-`), so it stays.

---

## 4. Features that cascade — keep as cruft, document as such

The brief allows leaving a feature in the code while removing it from the manual when
removal would cause major changes. These qualify:

| Feature | Why it stays |
| --- | --- |
| `getscreen$`/`putscreen` | implemented entirely on top of ncurses; yab programs use it for text screens |
| `getbit$`/`putbit` | serialised bitmap strings; used by yab `FakeTransparency.yab`-style code; cheap on `BBitmap` |
| `open printer`/`close printer`/`--print` | only the delivery mechanism changes; the language surface is small and documented |
| `peek`/`poke` `console_*` (2.91.x) | yab-compatible colour control on the terminal; harmless |
| `--check` compatibility warnings | useful when running old yab code; keep |
| `fontsize`/`fontheight` peeks | meaningful with TrueType fonts; keep |

---

## 5. yab-only abilities that must be preserved

yab 1.8.3 is BeOS/Haiku-native; its GUI is the reason this project exists. Command groups,
from `yab/yab-1.8.3/yabasic.bison` (lines 230-400) — the authoritative syntax:

* **Windows/views**: `window open/close/set`, `window count`, `layout`, `view`, `region`,
  `canvas`, `boxview`, `tabview`, `splitview`, `stackview`, `scrollbar`, `view remove`
* **Controls**: `button` (`button image`), `checkbox` (`checkbox image`, `checkbox set`),
  `radiobutton`/`radiobutton set`, `textcontrol` (`set`, `clear`, `get`), `textedit`
  (`add`, `set`, `colour`, `clear`, `get`), `text` (`text set` alignment), `texturl`
* **Lists**: `listbox` (`add`, `clear`, `remove`, `select`, `sort`, `get`), `dropbox`
  (`add`, `clear`, `remove`, `select`, `get`), `columnbox` (`column`, `add`, `clear`,
  `remove`, `select`, `colour`, `get`), `treebox` (`add`, `clear`, `remove`, `select`,
  `expand`, `collapse`, `sort`, `get`), `calendar` (`set`, `get`), `colorcontrol` (`set`, `get`)
* **Menus/dialogs**: `menu`, `submenu`, `subsubmenu`, `menu set`, `popupmenu`, `filepanel`,
  `alert`, `tooltip`/`tooltip colour`, `shortcut`, `localize`, `translate$`, `menu translate$`
* **Feedback**: `slider` (`label`, `set`, `colour`), `statusbar` (`set`), `spincontrol`
  (`set`), `option set/colour`, `attribute set/clear/get`
* **Drawing**: `draw text/line/rect/roundrect/dot/circle/ellipse/arc/curve/triangle/polygon/
  bitmap/set/flush/get`, `bitmap get num`, `bitmap remove`, `screenshot x,y to x,y,"f"`
* **Events**: `message$`, `mouse message$`/`mouse set`, `keyboard message$`,
  `peek("scrollbarwidth")`
* **Haiku integration**: `system$`, `launch`, `sound`/`mediasound`/`sound stop`/`sound wait`/
  `mediasound stop`, `loudness set`, `thread`, `clipboard copy`/`clipboard paste`,
  `bfilesize$`, `bdirsize$`, `bfilecopy$`, `bfilelink$`, `bfiledirexists$`, `bfiledelete$`,
  `languagesavailable$`, `timezonesavailable$`, `defaulttimezone$`, `iscomputeron$`,
  `pcworkspaces$`

Implementation is already C++ against `BApplication`/`BWindow`/`BView`
(`yab/yab-1.8.3/YabInterface.cpp`, 13 120 lines; `YabWindow.cpp`, `YabView.cpp`,
`YabList.cpp`, `YabMenu.h`, …). It is *ported* into `src/yabcompat/`.

### Conflict to resolve in Phase 1/2

yab's parser owns the `draw`/`window`/`text` keywords for its widget API, while yabasic's
parser owns `open window`, `close window`, `window origin`, `line`, `rectangle`, `circle`,
`triangle`, `dot`, `text`, `clear window`, `color`, `backcolor`, `putbit`, `getbit$`.
`window`, `draw`, `text`, `clear`, `color` therefore exist in both traditions with different
argument shapes. The merged grammar must:

1. keep yabasic's forms exactly (`open window x,y to x,y`, `close window`, `line x,y to x,y`,
   `rectangle …`, `text x,y,"s"`, `clear window`, `color r,g,b`);
2. keep yab's forms exactly (`window open x,y to x,y,"name","title"`, `draw line …`,
   `draw text x,y,"s","view"`, `text x,y,"name","label","view"`);
3. disambiguate by lookahead, not by rewriting either tradition. The two `window open`
   spellings are distinguishable on the second token; `text` takes 3 expressions in yabasic
   and 5 in yab; `line` is followed by `x,y to x,y` in yabasic and by `x,y to x,y,"view"` in
   yab. Where lookahead is not enough, prefer the yabasic reading in `.bas` files and the
   yab reading in `.yab` files? **No** — file-extension-dependent parsing is a trap. Prefer
   yabasic reading when the trailing `string` is absent, yab reading when present; both are
   unambiguous in practice. Record the final rule in the manual.

---

## 6. Build-system and artefact inventory

| Item | Today | RenkuBASIC |
| --- | --- | --- |
| Build | autotools (`configure.ac`, `Makefile.am`) + `runme` helper | CMake (AGENTS.md), autotools removed in Phase 4 |
| Parser | `flex.c` / `bison.c` checked in, regenerated by `make flex`/`make bison` | same files, regenerated only with `-DRENKU_REGENERATE_PARSER=ON` |
| X11 | `-lX11`, `X_CFLAGS` in `Makefile.am` | dropped |
| curses | `HAVE_CURSES_H`/`HAVE_NCURSES_H` via configure | `ncursesw` required, found by CMake |
| FFI | `libffi` via `--with-ffi` | CMake option `RENKU_ENABLE_FFI`, default ON |
| `whereami` | bundled, used for `peek$("interpreter_path")` and `bind` | kept for `peek$("interpreter_path")`, bound-program code removed |
| yab build | hand-written `Makefile`, links `-lbe -lroot -ltranslation -ltracker -lmedia -llocale -lgame -lncurses` | folded into the CMake target |
| Man page | `yabasic.1` | rewritten as `renkubasic.1` (Phase 3) |
| Test driver | automake `TESTS` + `tests/*.yab` | own runner (`tests/run-tests.sh`), no automake |

---

## 7. Summary of the removal request

**Status: approved by the maintainer on 2026-11-25.** The Windows backend goes entirely;
X11 and `lpr` printing go, replaced as described below; ncurses and `system`/`system$` stay.

Remove: Windows backend (graphics, console, printing, fonts, `.exe`, docs), X11 backend
(window, display, colours, fonts), `bind` + `--bind` + bound-program loader, automake build.

Replace: X11 graphic window → Haiku `BWindow`/`BBitmap`; X11 fonts → TrueType/OpenType;
`lpr` printing → PostScript + Haiku print server; Windows console → ncurses.

Keep: ncurses terminal control, `system`/`system$`, PostScript writer, `getscreen$`,
`getbit$`/`putbit`, `console_*` pokes, `--check`, `--docu`, `--execute`, `--infolevel`,
`--librarypath`, `--geometry`, FFI, and the whole yab widget/GUI layer.
