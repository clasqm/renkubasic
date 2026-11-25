# RenkuBASIC — planning and build document

*Revision 2 (Phase 0 output). The unedited first revision is preserved as
[docs/BUILDING-original.md](docs/BUILDING-original.md) (identical to revision 1 as committed);
this file is the document the project will be built from.*

RenkuBASIC is a BASIC dialect for RenkuOS/Haiku. It is a **rebase of yabasic 2.92.1**,
not a fork of yab: yab's language extensions and widget/GUI commands are carried over as a
compatibility layer, while the interpreter core tracks current yabasic.

Language reference point: **yabasic 2.92.1** (released 20 July 2026, `AC_INIT([yabasic], [2.92.1])`).
Compatibility reference point: **yab 1.8.3**.

---

## 1. Goals and non-goals

Goals

1. Run existing yab programs with no (or documented, mechanical) source changes.
2. Track future yabasic releases with a small, auditable patch set (see §8).
3. Offer one interpreter for both CLI programs (ncurses/normal terminal) and GUI programs
   (Haiku application kit, yab's widget set, graphic window).
4. Ship a test suite that proves (1) and (3) on every build.

Non-goals for this round

* No IDE (explicitly deferred).
* No bytecode compiler or standalone "binding" (removed, see §3.3).
* No Windows or X11 target. Windows and X11 code paths are removed, not maintained
  (permission requested in §12).
* No new language syntax unless a requirement below demands it.

---

## 2. Ground rules

RenkuBASIC is a Haiku program; the rules in `AGENTS.md` apply to the code, not just to
documents:

* No glibc/Linux assumptions, no `/usr`, `/etc`, `/proc`; use `find_directory()`.
* Networking is `libnetwork`; GUI is `libbe`; no X11, no win32.
* Build with CMake. `mkdir build && cd build && cmake .. && make` must succeed;
  `make clean` must work. Old `Makefile`/`Makefile.am`/`configure` files are removed in
  Phase 4 once CMake is verified.
* Do not run verification builds in this project's cloud workspace; the maintainer builds
  and runs the suites on Haiku and reports results. Phase 0 therefore contains no `src/`
  code — only this document and the test suite.
* Branch policy from `AGENTS.md` is superseded for this project (it is not a BeOS or Qt
  conversion): all work goes to `main`.

---

## 3. Language surface

### 3.1 Carried over from yabasic 2.92.1 (must work identically)

The full yabasic command and function set, notably:

| Area | Contents |
| --- | --- |
| Control flow | `if/elsif/else/endif`, short `if`, `for/next/step`, `while/wend`, `repeat/until`, `do/loop`, `switch/case/default/end switch`, `break`/`continue` (incl. `break n`), `goto`, `gosub`, `return`, `label`, `on … goto/gosub`, `on interrupt break/continue` |
| Data | `dim`/`redim`, `arraysize()`, `arraydim()`, array erase, array references (`a()`), `data`/`read`/`restore`, `local`, `static`, `numparams` |
| Strings | `left$`, `right$`, `mid$` (also assignable), `len`, `upper$`, `lower$`, `ltrim$`, `rtrim$`, `trim$`, `chomp$`, `string$` (repeat), `replace$`, `instr`, `rinstr`, `token`, `split`, `glob`, `str$` (with `using` formats), `val`, `chr$`, `asc`, `hex$`, `bin$`, `dec` |
| Numbers | `int`, `frac`, `floor`, `ceil`, `round`, `abs`, `sig`, `min`, `max`, `mod`, `sqr`, `sqrt`, `exp`, `log(x)`/`log(x,b)`, trig incl. `atan(y,x)`, `ran`, constants `pi`, `euler`, `true`, `false`; base 2/16 literals |
| Bits | `and()`, `or()`, `eor()`, `bitnot()`, `shl()`, `shr()`, `not` |
| I/O | `print` (`,` `;` `using` `at()` `color()`), `input`, `line input`, `open … for reading/writing as #n`, `print #n`, `input #n`, `seek`, `tell`, `eof`, `close`, `clear screen`, `screen`, `getscreen$`/`putscreen` |
| Runtime code | `compile`, `execute`, `execute$`, `eval`, `eval$`, `doc`/`docu$`, `error`, `exit`, `end`, `wait`/`sleep`/`pause`, `bell`/`beep` |
| Libraries | `import`, `export`, namespaced calls (`lib.sub`), `--librarypath` |
| Introspection | `peek`, `peek$`, `poke`, `system`, `system$`, `date$`, `time$`, `--docu`, `--check`, `--infolevel`, `--execute` |
| FFI | `foreign_function_call`, `foreign_function_call$`, `foreign_buffer_*`, `foreign_function_size` |
| Graphics | `open window`, `close window`, `window origin`, `line`, `rectangle`/`box`, `circle`, `triangle`, `dot`, `text`, `clear window`, `fill`/`clear`, `new curve`/`close curve`, `color`, `backcolor`, `putbit`/`getbit$`, `open printer`/`close printer` |

`flex.c` and `bison.c` are checked in; the grammar can be rebuilt with an optional
`-DRENKU_REGENERATE_PARSER=ON` CMake switch, so a plain build needs no flex/bison.

### 3.2 Carried over from yab 1.8.3 (compatibility layer)

yab's own additions on top of its ancient yabasic base — all of these must keep yab's
syntax exactly:

* **Widgets/views**: `window open/close/set`, `layout`, `view`, `region`, `canvas`, `boxview`,
  `tabview` (+`add/set/remove`), `splitview`, `stackview`, `scrollbar`, `button` (+`image`),
  `checkbox` (+`image`, `set`), `radiobutton` (+`set`), `textcontrol`, `textedit`
  (`add/set/colour/clear/get`), `listbox` (`add/clear/remove/select/sort/get`),
  `dropbox` (`add/clear/remove/select/get`), `columnbox` (`column/add/clear/remove/select/get/colour`),
  `treebox` (`add/clear/remove/select/expand/collapse/sort/get`), `calendar` (`set/get`),
  `colorcontrol` (`set/get`), `slider` (`label/set/colour`), `statusbar`, `spincontrol`,
  `tooltip`, `texturl`, `menu`, `submenu`, `subsubmenu`, `popupmenu`, `filepanel`,
  `shortcut`, `alert`, `localize`/`translate$`, `option set/colour`, `attribute set/clear/get`
* **Drawing**: `draw text/line/rect/roundrect/dot/circle/ellipse/arc/curve/triangle/polygon`,
  `draw set` (colours, font, alpha), `draw flush`, `draw get`, `draw bitmap`, `bitmap get num`,
  `bitmap remove`, `screenshot x,y to x,y, "file"`
* **Events**: `message$`, `mouse message$`/`mouse set`, `keyboard message$`,
  `window count`, `peek("scrollbarwidth")` and the other yab peeks/pokes
* **Platform**: `system$`, `launch`, `sound`/`mediasound`/`stop`/`loudness`,
  `thread`, `clipboard copy`/`clipboard paste`,
  `bfilesize$`/`bdirsize$`/`bfilecopy$`/`bfilelink$`/`bfiledirexists$`/`bfiledelete$`,
  `languagesavailable$`, `timezonesavailable$`, `defaulttimezone$`, `iscomputeron$`,
  `pcworkspaces$`, `attribute` access (BFS attributes)

yab's GUI layer is already Haiku-native C++ (`YabInterface.cpp`, `YabWindow.cpp`, …), so it
is *ported*, not rewritten. It moves under `src/yabcompat/`.

### 3.3 Renamed, removed, added

**Renamed** (Phase 1, mechanical; historical mentions stay where they are informative):

* Program name: `renkubasic` (binary), window/About titles, help header, man page, banner.
* `peek$("version")` **keeps returning the language level** (`"2.92.1"`), so version-gated
  yab/yabasic programs keep working. New: `peek$("renkuversion")` returns the RenkuBASIC
  release (e.g. `"0.1.0"`), and `--version` prints
  `RenkuBASIC 0.1.0 (yabasic language level 2.92.1, Haiku edition)`.
* `peek$("interpreter_path")`, `peek$("program_name")` keep their meaning.
* Error/warning prefix `yabasic:` becomes `renkubasic:` (documented as a change; scripts
  that grep stderr for the prefix need updating).

**Removed**

* `bind` command and `--bind` option, *and* everything that exists only to support them:
  the trailer written by `mybind()`, `run_bound()` program loading, `is_bound`,
  `peek("isbound")` (kept, always `0`), the bound-program section of the manual, the
  `tests/bind_import.yab`/`nested_bind_import.yab` tests, and the `bind_import`/`nested_bind_import`
  artifacts in the upstream tree. Removing `bind` is a small change: one grammar rule, one
  lexer keyword, one `case cBIND`, `mybind()`, `--bind` parsing, and the trailing-trailer
  reader in `main.c`. Nothing else depends on it.
* Windows support (`#ifdef WINDOWS` branches in `io.c`, `graphic.c`, `main.c`, `function.c`,
  `symbol.c`), including the GDI graphics window, console-API terminal handling, winspool
  printing and `.exe` handling.
* X11 graphics (`Xlib`, `--display`, X colour names in `-fg/-bg`, X font names/`--font`
  X11 spelling). Replaced by the Haiku backend (§5.3).
* The "Creating a standalone program" manual chapter and `--bind` from `yabasic.1`,
  `yabasic.htm` and `README`.
* Autotools build files (Phase 4) once CMake is verified.

**Added**

* `peek$("os")` returns **`"haiku"`** on Haiku and **`"renkuos"`** on RenkuOS, in addition to
  `"unix"` and `"windows"` (which remain valid names for the other platforms).
  `peek$("yabos")` returns yab's historical spellings (`"Haiku"`, `"BeOS"`) for unmodified
  yab code; see §4.
* TrueType/OpenType font support in the graphic window (`draw set "DejaVu Sans, Bold, 32"`,
  `--font`, `peek$("font")`), since Haiku has no bitmap fonts. This replaces yabasic's
  `change_font()`/X font machinery in `graphic.c`.
* `renkubasic --selftest` — runs a short built-in check (parser, math, string, file I/O,
  OS peek) and prints one line per check; used by packagers and by the test runner when no
  external test script is available.
* A `--gui-backend=` switch is *not* added in this round (one backend: Haiku).

**Deliberately kept although obsolete**: `peek$("os")` returning `"unix"`/`"windows"` names,
`getbit$`/`putbit`, `open printer` (re-implemented as "write PostScript to a file and hand it
to the Haiku print server / `launch`"), `screen`/`getscreen$`, `inkey$` mouse encoding,
`--check` compatibility warnings. These are cheap to keep and expensive to remove safely.

### 3.4 Other newer yabasic features

yabasic 2.92.1 is a moving target; the pieces a yab-era program never saw are the FFI
(`foreign_function_call`, buffers), `string$` (repeat) and `replace$`, the `console_*` pokes,
the `screenposx`/`screenposy` and `displaywidth`/`displayheight` peeks, and `input … at()
color()`. yab has none of these; they belong in the core, not the compatibility layer, and
are covered by `tests/cli/c050`, `c042`, `c081`, `c096` and `c095`.

yabasic has **no classes and no object system** (checked against the 2.92.1 grammar), so
RenkuBASIC does not add one. Programs needing structured data use arrays and subs, exactly
as in yabasic and yab.

---

## 4. Compatibility contract

1. **Every valid yab 1.8.3 program parses and behaves the same**, with these documented
   exceptions:
   * `bind` no longer exists (hard error with an explanatory message).
   * `peek$("os")` returns `"haiku"`/`"renkuos"` instead of `"Haiku"`; `peek$("yabos")`
     gives the old spelling, and `--yab-os-names` (a startup option) makes `peek$("os")`
     return yab's spelling for the whole run, for untouched yab programs.
   * the program name in `peek$("program_name")`/banners is `renkubasic`.
   * anything Windows/X11-specific is gone (yab was BeOS/Haiku-only, so no yab program
     should notice).
2. **Every valid yabasic 2.92.1 program parses and behaves the same**, except the removals
   above (`bind`, Windows, X11) and except yabasic programs that rely on X11 font names or
   `--display`.
3. The test suites in `tests/` are the executable form of this contract. A release is not
   made unless `tests/run-tests.sh --suite cli` and `--suite gui` pass on Haiku/RenkuOS.

---

## 5. Architecture

### 5.1 Layers

```
            +-----------------------------------------------+
            |  yab compatibility layer (src/yabcompat/)      |
            |  widgets, views, events, draw, bitmap, sound,  |
            |  BFS attribute/file helpers                     |
            +-----------------------------------------------+
            |  RenkuBASIC core (src/, from yabasic 2.92.1)   |
            |  lexer/parser, symbol table, flow, io, ffi      |
            +-----------------------------------------------+
            |  platform services (src/platform/haiku/)       |
            |  graphics | terminal | print | paths | events   |
            +-----------------------------------------------+
```

The core stays *as close to upstream as possible*. Platform differences enter through three
narrow, documented seams rather than scattered `#ifdef`s:

* `graphic.c` keeps its public entry points but delegates device work to
  `rk_graphics_*` (`platform/haiku/rk_graphics.c`): open/close window, set colour/font,
  line/rect/ellipse/arc/text/bit, flush, resize/event pumping, screenshot, printer output.
* `io.c` keeps its public entry points and delegates terminal capabilities to
  `rk_term_*` (`platform/haiku/rk_term.c`), which is a thin ncurses wrapper plus Haiku
  `find_directory()`-based path handling.
* `function.c` platform bits (`peek("os")`, `screenposx/y`, millisecond clock, `system$`)
  call `rk_platform_*` helpers.

`#ifdef WINDOWS` is deleted outright (not stubbed), so the remaining code has one
platform story and the seams above.

### 5.2 GUI: two front-ends, one message loop

yab programs open Haiku windows and pump `message$`. yabasic programs draw into the
graphic window. Both must coexist in one process (a yab program may use `draw` on a
`canvas`; a yabasic program uses `open window`). The Haiku backend therefore owns:

* one `BApplication` (created lazily, named `application/x-renkubasic`);
* any number of `BWindow`s: the yab widget windows and the single graphic window;
* one message pump that feeds both `message$` (yab widget messages) and `inkey$`/mouse
  state (graphic window), so a program never needs two loops.

### 5.3 Graphics and fonts

yabasic's graphic window is redrawn into an offscreen `BBitmap`; `getbit$`/`putbit`/`screenshot`
read from it. Fonts come from `BFont` via a small parser for the
`family[, style][, size]` string used by yab and by the new `--font` option, with the
yabasic `fontsize`/`fontheight` peeks derived from the selected font. The old
`change_font()` X11 code and the X bitmap-font assumption disappear.

### 5.4 Modularity for upstream updates

* Upstream sources keep their filenames and function names.
* Every intentional deviation is wrapped in
  `/* RenkuBASIC: begin … */ … /* RenkuBASIC: end */` markers, and listed in
  `docs/upstream-sync.md` together with the reason.
* `tools/upstream-diff.sh <tag>` prints exactly the hunks that differ from a fresh
  yabasic tarball, so an update is a diff review, not an archaeology exercise.
* `vendor/` holds the pristine upstream tree for that diff (kept out of the build).

---

## 6. Repository layout

(Target state; directories marked *planned* appear in the phase that needs them.)

```
BUILDING.md                  this document
BUILDREPORT.md               Phase 5 report (planned)
docs/
  BUILDING-original.md       revision 1, unedited
  platform-inventory.md      Windows-only / Unix-only / X11 / yab inventory and decisions
  upstream-sync.md           how to move to a new yabasic release (planned)
  manual/                    Phase 3 unified documentation (planned)
src/                         interpreter core (upstream files, marked deviations)
  platform/haiku/            graphics, terminal, print, paths, application pump
  yabcompat/                 yab widget/view/event/BFS compatibility layer
include/                     internal headers
vendor/yabasic-2.92.1/       pristine upstream reference tree (not built)
tests/                       test suites and runner (see tests/README.md)
tools/                       upstream-diff.sh, doc generators
yab/, yabasic/               reference trees, deleted when the project is complete
```

---

## 7. Build system

* CMake ≥ 3.16, project `RenkuBASIC`, target `renkubasic`.
* Sources: core `.c` (C11) + platform/yabcompat `.cpp` (C++17, Haiku API).
* Links: `be`, `root` (implicit), `ncursesw`, `m`, `dl`; `libffi` when the FFI is enabled;
  no `X11`, no `winspool`.
* Options: `RENKU_ENABLE_FFI` (default ON), `RENKU_REGENERATE_PARSER` (default OFF),
  `RENKU_WERROR` (default OFF), `RENKU_BUILD_TESTS` (default ON).
* `make check` / `ctest` runs `tests/run-tests.sh --interpreter ./renkubasic`.
* `make install` installs `renkubasic` and the man page to the paths given by
  `CMAKE_INSTALL_PREFIX` (no `make install` is required for development).

---

## 8. Tracking new yabasic releases

1. `tools/fetch-upstream.sh 2.93.0` unpacks the tarball into `vendor/yabasic-2.93.0/`.
2. `tools/upstream-diff.sh 2.93.0` prints the hunks between our `src/` and that tarball.
3. Apply upstream changes to `src/` (three-way merge), re-apply the marked deviations.
4. Rebuild, run `tests/cli` (must pass unchanged) and `tests/gui` (new behaviour may need
   new tests).
5. Update `docs/upstream-sync.md` with the new release, date and any new deviation.

Because the yab compatibility code lives in its own directory and talks to the core only
through the parser's command table and the `c*` command codes, a core update rarely forces
changes there; where it does, the compiler and the test suite say so immediately.

---

## 9. Testing

Two suites, one runner; see [tests/README.md](tests/README.md).

* `tests/cli/` — non-interactive programs, ported from yabasic `tests/` and yab's CLI
  examples, plus new RenkuBASIC requirements. Exit status is the verdict; `error`/`exit`
  conventions follow upstream; a few tests compare captured output against
  `tests/expected/`.
* `tests/gui/` — widget, view, draw and event tests derived from yab's `Examples/`.
  They create windows, query state through yab's getters, take one screenshot and verify
  it is non-trivial, then close everything — no clicking required.
* `tests/manual/` — the genuinely interactive yab examples (alerts, file panels, popups,
  sound), with a checklist, run by a human before a release.
* Terminal-dependent behaviour (`at()`, `color`, `clear screen`, `inkey$`) runs in the
  `pty` subset, which needs `script(1)`; elsewhere it is skipped.

No suite is allowed to be "expected to fail" without an explicit `EXPECT-EXIT`/`SKIP`
directive in the test header, and every skip prints its reason.

---

## 10. Phases and acceptance criteria

**Phase 0 — planning and tests (this round)**

* [x] Refine this document; keep the original (docs/BUILDING-original.md).
* [x] Write the platform inventory and the removal proposal (docs/platform-inventory.md).
* [x] Build the test suites and the runner from the yabasic and yab example trees.
* [x] Validate the suites against a stock `yabasic` 2.92.1: `--suite cli` is green (all
  failures fixed in the tests, five tests skip because they need RenkuBASIC).
  `--suite gui` and `--suite manual` cannot run off Haiku; see tests/README.md.
* [x] Record the required changes (haiku/renkuos, no bind, TrueType fonts, renames).
* [x] User decision on the removal list: §12 Q1 and Q2 approved as proposed
  (2026-11-25). §12 Q3 was left open and defaults to the proposal until Phase 2.
* Acceptance: suites are runnable against an existing `yabasic` 2.92.1 binary and pass
  except tests marked `@requires: renkubasic`.

**Phase 1 — core compiles (complete 2026-11-25)**

* [x] CMake project; `src/` holds the core; Windows and X11 backends deleted, the
  platform seam (`src/rk_platform.*`) and a Phase 1 graphic placeholder
  (`src/rk_graphics.c`) keep the interpreter linkable. See `docs/phase1.md`.
* [x] `bind` gone (statement, `--bind`/`-bind`, bound-program loader, `whereami.c`);
  renames applied; `peek$("os")`/`peek$("yabos")`/`peek$("renkuversion")` and
  `--yab-os-names` implemented.
* [x] First build on Haiku: compiler errors found and fixed in three rounds
  (recorded in `docs/phase1.md`).
* [x] `tests/run-tests.sh --suite cli` green on Haiku (2026-11-25):
  39 passed, 0 failed, 2 skipped (`c097-ffi` needs `-DRK_WITH_FFI=ON`,
  `c096-tty-at-colour` needs a pty).
* Acceptance met: faultless build; CLI suite passes on Haiku.

**Phase 2 — Haiku/RenkuOS API and GUI**

* Graphic window on `BBitmap`/`BWindow` with TrueType fonts; screenshot, getbit/putbit,
  printer-to-PostScript.
* yab compatibility layer ported; widget, event and BFS helpers work.
* Acceptance: `tests/gui` passes; `tests/manual` checklist signed off.

**Phase 3 — documentation**

* One Markdown manual covering every command from both traditions, with a
  "yab/yabasic → RenkuBASIC" migration appendix and the compatibility exceptions.

**Phase 4 — cleanup**

* Delete `yab/`, `yabasic/`, autotools files, Windows/X11 leftovers, dead references.

**Phase 5 — build report**

* `./BUILDREPORT.md`, about 500 words, describing how this build was created.

---

## 11. Decision log

| # | Decision | Rationale |
| --- | --- | --- |
| D1 | Rebase on yabasic 2.92.1, re-add yab's GUI as a layer | yab's parser is 20 years behind; its GUI is the part worth keeping |
| D2 | Keep `peek$("version")` = language level; add `peek$("renkuversion")` | version-gated yab/yabasic code keeps working |
| D3 | Remove `bind` including its program-trailer reader | required; small and self-contained |
| D4 | Delete Windows and X11 code instead of stubbing (approved, §12 Q1/Q2) | one platform story; less code to update on each rebase |
| D5 | `#ifdef UNIX` stays as the single "POSIX-ish" compile path | Haiku is UNIX-like enough; avoids a third `#ifdef` family |
| D6 | One `BApplication` serves the graphic window and yab widgets | a program must not need two event loops |
| D7 | Tests are plain BASIC programs plus a shell runner, not a framework | no new dependency; matches yabasic's own `make check` culture |
| D8 | GUI tests use getters and one screenshot; no scripted clicking | deterministic, no X11-style input injection needed |
| D9 | Keep obsolete-but-harmless yabasic features (print/printer, getscreen$, `--check`) | removing them cascades into docs and code for no benefit |

---

## 12. Permissions requested and open questions

These are the items the original brief asked to be raised rather than decided silently.

**Q1 — Windows-only abilities: permission to remove?**
**APPROVED 2026-11-25: remove the Windows backend entirely.**
Proposed for removal (inventory with file references in `docs/platform-inventory.md`):
GDI graphic window and its font handling; Windows console API terminal handling
(`clear screen`, colours, cursor position, `getscreen$`/`putscreen`); winspool printing and
`open printer` on Windows; `.exe` suffix/`bind` leftovers; `--font` Windows style names;
Windows filename and drive-letter chapter in the manual. None of this is reachable from
Haiku, and keeping it means carrying a second backend through every rebase.

**Q2 — Unix-only abilities: permission to remove or replace?**
**APPROVED 2026-11-25: delete the X11 window, `--display`, X11 colour/font names and
`~/.yabasicrc`; replace `lpr` printing with PostScript + the Haiku print server; keep
ncurses and `system`/`system$`.**
Proposed:
* *Remove*: X11 window, `--display`, X11 colour/font names, `~/.yabasicrc` handling.
* *Replace*: Unix `lpr`-based printing → PostScript file + Haiku print server;
  ncurses cursor/colour backend → same API on Haiku's ncurses (kept, not removed).
* *Keep*: `system`/`system$` (POSIX process spawn), `peek$("os")` = `"unix"` as a name.

**Q3 — `peek$("os")` spelling.** **APPROVED 2026-11-25: lowercase `haiku`/`renkuos`,
`peek$("yabos")` returns `"Haiku"`, and `--yab-os-names` restores `"Haiku"` for old yab
programs.**
The brief asks for `"haiku"`/`"renkuos"`; yab programs compare with `"Haiku"`. Proposal:
`peek$("os")` returns the lowercase names as specified, `peek$("yabos")` returns the yab
spelling, and `--yab-os-names` makes `peek$("os")` return `"Haiku"` for the whole run so
unmodified yab programs take the right font branch. Alternative: always return `"Haiku"`
(matches yab, contradicts the lowercase wording of the brief).

**Q4 — scope of the yab GUI port in Phase 2.**
Proposal: port every widget/view and the file/attribute/sound helpers, but treat
`popupmenu`, `filepanel`, `alert` and `mediasound` as "manual-test only" (they are modal or
media-dependent). Everything else gets an automated GUI test.

**Q5 — version numbering.**
Proposal: RenkuBASIC 0.1.0 for the first working build; language level always reported
separately (see D2).

---

## 13. Risks

| Risk | Mitigation |
| --- | --- |
| yab GUI code is C++ against a 2005-era Haiku API | port incrementally behind `yabcompat/`; compile early in Phase 2; keep widget tests per class |
| Two event loops (graphic window vs widget windows) fight over messages | single `BApplication` + single pump (D6) and an explicit GUI test that opens both kinds of window in one program |
| Bitmap-font assumptions hide in yabasic's `graphic.c` | inventory §5.3 lists every font call site; `tests/gui/g0103-fonts.yab` checks that TrueType families and sizes change the measured text metrics |
| Upstream rebase becomes a merge nightmare | marked deviations + `tools/upstream-diff.sh` (§5.4/§8) |
| Tests drift from real yab behaviour | every ported test keeps a `Derived from:` line naming the yab/yabasic file and version |
| `peek$("os")` change silently breaks yab examples | Q3 decision + a CLI test that asserts both spellings |
