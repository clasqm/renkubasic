# Phase 2 — Haiku GUI backend

Phase 2 replaces yabasic's Xlib graphic window with a Haiku window and adds the
yab compatibility layer. This document records both slices: the graphic window
and the first part of the yab layer (`src/yabcompat/`), which now runs yab's
`window`, `view` and `draw` commands. Buttons, lists, menus and the rest of the
widget set are the next slice.

## What exists now

| Piece | Where | State |
| --- | --- | --- |
| C bridge between the C core and the Haiku kits | `src/rk_gui.h` | done |
| `BApplication`, `BWindow`, `BView`, `BBitmap` backend | `src/rk_gui.cpp` | compiles on Haiku; the open/close probe passes (round 5); drawing not yet confirmed, `g0130` still times out |
| yabasic drawing commands on that bridge | `src/rk_graphics.c` | ported from 2.92.1 |
| TrueType/OpenType font selection | `rk_gui_set_font()` | done |
| `getbit$` / `putbit` | `rk_graphics.c` | ported, same `rgb W,H:` string format |
| PNG capture of the canvas | `rk_gui_save_png()` | done; the yab layer's `screenshot` uses its own capture, see below |
| PostScript file output | `rk_graphics.c` | writes a header and page breaks; not yet complete PostScript |
| Haiku print server | — | not started |
| yab grammar for `window`, `view`, `draw`, `screenshot` | `src/yabasic.bison`, `src/yabasic.flex` | done |
| yab windows, views, drawing | `src/yabcompat/rk_yab.cpp` | done for the command set below |
| yab controls, lists, menus, bitmap, canvas | `src/yabcompat/` | not started; those tests ask for `gui-widgets` and skip |

## Design decisions

**C core, C++ backend.** The interpreter is C; the Haiku application kit is C++.
`rk_gui.h` is the only interface between them, so `rk_graphics.c` reads almost
exactly like upstream `graphic.c` with each Xlib call replaced by one bridge
call.

**Offscreen canvas.** All drawing goes into a `B_RGB32` `BBitmap`. The window's
view only blits it. That gives three things at once: expose redraws need no
primitive replay, `getbit$` reads a stable picture, and `putbit` writes into the
same pixels it later reads back. Pixel access is direct through `Bits()` with
`BytesPerRow()`; the layout on little-endian Haiku is B, G, R, A.

**One BApplication, built and run on one helper thread.** Decision D6 says one
application object for both the graphic window and yab widgets. The interpreter
owns the main thread for the whole program, so the application lives on a
helper thread; what matters is that the *same* thread constructs it and calls
`Run()` (round 4 explains why). Every window operation from the interpreter
takes the window lock. If app_server turns out to reject window creation from
the interpreter thread, the fallback is to create the window on the GUI thread
and post the interpreter's drawing requests to it.

**TrueType only.** A font specification is `"Family, Style, Size"`, any part
optional; an unknown family keeps the previous family and still applies the
size. There is no bitmap-font path, because Haiku has no bitmap fonts. Text
metrics come from `BView::StringWidth()` and `BFont::GetHeight()`, so
`draw get "text-width"` and `peek("font")` will report real values.

**Coordinates.** `transform()` and `moveorigin()` are upstream's, unchanged:
`window origin` takes the two-letter code (`lt`, `cb`, …), and yabasic's
top-left y-down coordinates map directly onto BView coordinates.

## Tests

`tests/gui/g0130-yabasic-graphics.yab` and `g0131-yabasic-printer.yab` now
declare `@requires: graphics` instead of `@requires: gui`. The runner probes the
yabasic window with a tiny `open window 20,20 : close window` program, so these
two tests run as soon as the backend works, while the yab-widget tests keep
skipping until `src/yabcompat/` exists. That keeps the suite honest in both
directions: no false passes, and no failing tests for features that are simply
not written yet.

There are now two yab capabilities, because the layer arrives in slices:

* `gui` — the window, view and draw commands. Probed with a program that opens
  and closes a window. `g0100`, `g0101`, `g0103` and `g0119` run with it.
* `gui-widgets` — buttons and the other controls. Probed with a program that
  creates a `button`; until that command exists the probe fails with a syntax
  error and the eleven widget tests skip with `(requires gui-widgets)`. When
  the widget slice lands, the tag comes off those tests one group at a time and
  the probe starts passing on its own.

The probe is the first thing that touches the backend, so a failing probe used
to turn every graphical test into a bare `SKIP (requires graphics)` with no
explanation. Probes now run with `RK_GUI_TRACE=1`, under the same kind of
watchdog as a test, and their log is printed when they fail. The banner also
reports `graphics` next to `gui`, because those are separate capabilities.

`g0103-fonts.yab` (TrueType metrics through yab's `draw get`) stays with the yab
layer, because it uses yab syntax; the yabasic equivalent is exercised by
g0130's two `text` calls with an explicit font.

## The yab layer

**The grammar is yab's.** yab 1.8.3 is itself a yabasic fork, so its GUI
commands are already expressed as yacc productions that emit opcodes
(`add_command(cVIEW, …)`); `yab/yab-1.8.3/yabasic.bison` is the reference. The
productions, tokens and flex rules were copied from it into `src/yabasic.bison`
and `src/yabasic.flex`, reduced to the command groups that are implemented. The
generated files (`src/bison.c`, `src/bison.h`, `src/flex.c`) stay checked in, so
a normal build needs neither bison nor flex; `make parser` regenerates them.

**set, get and count are context keywords.** yab reserves them, yabasic does
not, and existing yabasic programs use `count` as a variable (the CLI test
c020 does). The scanner therefore has an exclusive start condition, `YABKEY`,
entered by `window`, `view` and `draw` only. Inside it those three words are
keywords; the first other token leaves the state and scans normally. The cost is
small (three rules plus a fallback that re-scans the character) and it keeps
both dialects working.

**%expect 4.** The yab extensions add four shift/reduce conflicts, and all four
are resolved the way yab resolves them: a `+` after `window get`/`draw get`
concatenates the result, and a `,` after `draw get "prop", "text"` continues
the longer three-string form. The count is asserted, so a future rule that adds
a conflict makes bison fail instead of silently changing how an existing program
parses.

**One handler, one bridge.** All the new statements compile to `cYAB*` opcodes
and are dispatched together: `main.c` has one case group that calls
`rk_yab_command()`, which pops its own arguments in reverse order (exactly what
yab's `graphic.c` does) and calls `src/yabcompat/rk_yab.h`. The numeric getters
are `fYAB*` function ids handled in `function.c`; they sit in the enum's
argument-count groups, because that ordering is what tells `function()` how many
arguments to pop. A failed bridge call becomes an ordinary BASIC runtime error
with the bridge's message, so a missing window or an unreachable app_server
reads as a normal error.

**Windows own a frame, views own a canvas.** Each yab window has one display
view and a `frame` `BBitmap` without child views; `draw flush` composites the
view's bitmap into that frame and invalidates the window, and the window thread
only ever blits the frame. That is the round 6 rule again: the window thread
takes no bitmap lock that the interpreter could be holding. A view keeps its
own `B_RGB32` bitmap with a `BView`, so its contents survive an expose without
replaying the primitives.

**Screenshots.** yab's `screenshot` captures the screen. RenkuBASIC captures
the frontmost yab window's frame instead, so the command works the same when
other applications are open. It is encoded with `BTranslatorRoster` as PNG,
like `rk_gui_save_png()`.

## Known gaps

* **PostScript output is incomplete.** The file has a valid header and page
  breaks, but the drawing operators (`LI`, `RE`, `CI`, `TRI`, `DO`, `AT`) are
  written without the prolog that would define them, so the file is not yet
  printable. Completing the prolog, and handing the finished file to the Haiku
  print server, is the printing task left in this phase.
* **The yab window close box is ignored.** `YabWindowClass::QuitRequested()`
  returns false for the same reason the yabasic window does: destroying the
  window from its own thread would leave the interpreter holding dangling
  pointers. A program closes it with `window close`.
* **Only the properties the tests need exist.** `window get` knows `width`,
  `height`, `position-x`, `position-y`, `frame-width` and `frame-height`;
  `window set` knows `title` and `flags` (`not-h-resizable`, `not-v-resizable`,
  `not-zoomable`, `not-closable`, `not-movable`, and their positive forms).
  Anything else is a runtime error naming the property, not a silent no-op.
* **`draw` covers the primitives the GUI tests use.** There is no `draw bitmap`,
  no canvas or region, no view removal, and no `message$` for widget events;
  those belong with the widget slice.
* **Window keyboard input is buffered, not selectable.** `rk_window_pending()`
  reports buffered window keys, but `rk_window_fd()` stays -1 because a BWindow
  has no file descriptor. `inkey$` therefore still waits on the terminal; a
  program that only expects window input needs a poll loop or a later change to
  `inkey`'s wait.
* **The close box is ignored.** `QuitRequested()` returns false. If the window
  could be closed by hand it would be destroyed without telling the interpreter
  thread, leaving dangling pointers in the bridge. Proper handling needs a
  shutdown request that the interpreter loop checks, which belongs with the yab
  window commands. A program closes the window with `close window`.

## Build rounds

**Round 1 (2026-11-25).** `main.c` failed in `rk_gui.h`:

```
src/rk_gui.h:71:39: error: expected declaration specifiers or '...' before 'cur_term'
   71 | int rk_gui_mouse(int *x, int *y, int *buttons);
```

`yabasic.h` includes `<term.h>` before the bridge header, and terminfo defines
`buttons` (the `btns` capability, "number of buttons on mouse") as
`((TERMTYPE *)cur_term)->Numbers[…]`. The preprocessor therefore rewrote the
parameter name. The parameters are now `out_x`/`out_y`/`out_buttons`, with a
comment in the header saying why.

Two more API mistakes were found by inspection against the Haiku headers in the
same round:

* `BWindow` has no `Invalidate()` method. `rk_gui_flush()` now invalidates the
  display `BView` instead.
* `BTranslatorRoster::Translate()` has no `BBitmap*` source overload, so
  `rk_gui_save_png()` was passing a `BPositionIO*` in the wrong position. The
  canvas now goes through a `BBitmapStream`, which must be detached again before
  it is destroyed or it deletes the canvas.
* `BFont` has no `SetFamily()`. `rk_gui_set_font()` now uses
  `SetFamilyAndStyle(family, style)`, with a NULL style meaning the family's
  default style, and starts from the current font so a size-only specification
  keeps the family.

Also in this round: the window frame is resized after `Show()` until its content
area is exactly `width × height`, because the frame passed to `BWindow` includes
the tab and border and would otherwise clip the right and bottom of the canvas;
the display view is now non-resizable to match the fixed-size bitmap; `dot`
fills a single pixel instead of drawing a two-pixel line; and an unset font can
no longer be applied to a missing canvas view.

**Round 2 (2026-11-25).** The build succeeds: all C sources and `rk_gui.cpp`
compile with gcc 15.3 and `renkubasic` links against `libbe` and
`libtranslation`. Two warnings were removed: unused `r, g, b` variables left in
`putbit` by the Xlib port, and a possible `snprintf` truncation when splitting
the font specification.

**Round 3 (2026-11-25, first run on Haiku).** The CLI suite stays at 39 passed,
0 failed, 2 skipped. The graphic-window probe in the runner (`open window 20,20`
/ `close window`) passes, so the `graphics` capability is on and g0130/g0131 run
instead of skipping.

`g0131` failed on its own test code: it used `bfilesize()`, a yab function that
belongs to the compatibility layer. It now reads the file back with plain
yabasic and sums `len()` instead.

`g0130` was killed by the runner's 30-second watchdog. On Haiku the watchdog's
`kill -9` arrives as `SIGKILLTHR` (21), so bash reports exit 149 rather than
137; the runner now accepts both as a timeout. The test also writes the
statement it is executing to `g0130-trace.txt`, because a hung program leaves
no captured output behind (stdout is block buffered), so the next run will say
which statement does not return.

What the first run has yet to confirm: whether a `BApplication` created on the
interpreter thread accepts `Run()` on a helper thread (yab instead runs the
application on the main thread and the interpreter on a helper), and whether
`BBitmap::Lock()` around the blit is enough for the window thread's `Draw()`. If
either fails, the fallback is to create the window on the GUI thread and post
drawing requests to it.

**Round 4 (2026-11-25, second run on Haiku).** Same build, same CLI suite
(39 passed), but this time the graphics probe did not come back: bash reported
the probe's own line as killed, so no test ran at all and the suite turned into
17 skips with `(requires graphics)`. Together with round 3 — where the same
probe passed and only `g0130` hung — that is a race inside the backend, not in
the tests.

Haiku's source names it. `BLooper::_InitData()` ends with
`gLooperList.AddLooper(this)`, commented "this will also lock this looper": a
new looper stays **locked by the thread that constructed it**. `Run()`, `Loop()`
and `AddHandler()` all begin with `AssertLocked()`, and `BLooper::Loop()` records
`find_thread(NULL)` as the loop thread. The old `ensure_app()` did

```cpp
g_app = new BApplication("application/x-vnd.RenkuBASIC");   /* interpreter thread */
spawn_thread(gui_thread, ..., g_app);                       /* helper thread */
```

so `Run()` on the helper asked `IsLocked()`, found the lock owned by the
interpreter thread, and called `debugger("looper must be locked before
proceeding")`. With no debugger installed that suspends the helper thread for
good: the application's message loop never runs and nobody reads the
application's port. Windows still appear, because every `BWindow` has its own
looper thread started by `Show()`, which is why the symptom moved between runs
instead of failing outright — but an application port that is never drained is
exactly what makes an app_server round trip in `open window` or `close window`
stop answering.

The application is now constructed *inside* `gui_thread()`, on the thread that
calls `Run()`, and the interpreter waits for it on a semaphore with a ten second
timeout instead of the old fixed `usleep(20000)`. A failed `InitCheck()` or a
timeout is reported through `rk_gui_last_error()`, so a machine without a
reachable app_server says "could not start the application (is app_server
reachable?)" instead of hanging. `rk_gui_open_window()` now honours that failure
rather than carrying on into `new BWindow`, whose `be_app == NULL` check is
another `debugger()`.

Two smaller changes in the same round:

* `rk_gui_close_window()` lost its silent fallback, which deleted the canvas
  under a window whose lock it could not take. On a lock timeout it records the
  error and leaves both alone: leaking is better than a window thread drawing
  through a freed bitmap.
* `RK_GUI_TRACE=1` makes the backend print each blocking step of open and close
  to stderr, and the runner sets it for its probes (see Tests).

What the next run has to confirm: that the probe passes on repeated runs rather
than sometimes, and that `g0130` gets past `open window`. Its trace file
`tests/.scratch/run/g0130-yabasic-graphics/g0130-trace.txt` will then name the
next statement that does not return, if there is one.

**Round 5 (2026-11-26, third run on Haiku).** The build is unchanged and clean,
the CLI suite stays at 39 passed / 0 failed / 2 skipped, and the graphics probe
now comes back: the runner prints `graphics : available` and the window tests
really run. That closes round 4's open question — constructing the
`BApplication` on the thread that calls `Run()` was the fix, and `open window` /
`close window` complete on repeated runs instead of racing.

The gui probe still fails, and this time the reason is not a backend fault:
`window open 20, 20 to 90, 90, ...` is yab syntax and `src/yabcompat/` has not
been written yet, so the probe reports a syntax error and the fifteen widget
tests skip with `(requires gui)`. That note in every run's output is the
expected state of the phase, not a defect.

`g0131-yabasic-printer` passes: the PostScript header, the primitives as
`DO`/`LI`/`RE`/`CI`/`TRI`/`AT` operators and the page break all reach
`rk-print.ps`, and the test reads the file back with plain yabasic.

`g0130-yabasic-graphics` still times out, now with no captured stdout or stderr
at all, so it stops somewhere after `open window`. Because the failure left
nothing to read, this round is diagnosis only — no behaviour changed:

* `g0130` marks **every statement** instead of every group, so the last line of
  `g0130-trace.txt` names the call that does not return, not just the block.
* The runner prints any `*.txt`/`*.log` file a test left in its run directory
  when the test times out or fails, so that trace file arrives with the test
  output instead of needing a separate look in `tests/.scratch`.
* The runner sets `RK_GUI_TRACE=1` for tests that require `gui` or `graphics`
  (unless the test inspects stderr), and the backend now traces every primitive
  plus both halves of the display view's `Draw()`. A killed test's stderr is
  flushed line by line, so its last line names the backend call that was
  entered and never returned — which separates "stuck in the interpreter" from
  "stuck inside the window thread".

What the next run has to settle: whether the trace stops before a drawing
statement, at one particular primitive, or after `close window`. The three
candidates are a Haiku `debugger()` trap (the team is suspended, which looks
exactly like this), a block in the window thread's redraw, and something in
`getbit$`/`putbit`, whose per-pixel bridge calls are the only loops here.

**Round 6 (2026-11-26, fourth run on Haiku).** The instrumentation from round 5
answered the question it was added for. `g0130` still times out, but now the
last backend steps and the statement trace agree:

```
rk_gui: open: done
rk_gui: clear          <- clearwin() at the end of openwin()
rk_gui: flush
rk_gui: display: draw
rk_gui: display: draw done
rk_gui: clear          <- the test's own `clear window`
rk_gui: display: draw
rk_gui: display: draw done
rk_gui: display: draw
rk_gui: display: draw done
g0130-trace.txt: clear window
```

The statement that does not return is `clear window`, and inside it the stall is
between the `clear` marker and the `flush` marker that `rk_gui_clear()` calls
next, while the window thread kept completing blits. In other words the
interpreter is waiting for something the window thread takes and releases — the
canvas bitmap's lock, which was the only lock in the backend without a timeout:
`rk_gui_clear()` and every primitive held it, and `RkDisplayView::Draw()` held it
across `DrawBitmap()`.

So the window thread no longer touches the canvas at all. `rk_gui_flush()` —
which runs on the interpreter thread, while it holds the window lock — copies
the canvas into `g_frame`, a second `BBitmap` created **without**
`B_BITMAP_ACCEPTS_VIEWS`, and invalidates the display view. `Draw()` blits
`g_frame`, which has no child view and therefore no looper, so the blit takes no
lock and can never wait for the interpreter. The snapshot is taken under the
window lock, so the window thread cannot see a half-written frame either. One
writer, one reader, one lock, and that lock is the window's, which every call
already takes with `LockWithTimeout()`.

`rk_gui_clear()` and `rk_gui_flush()` are also split into finer trace steps
(`clear: locking canvas`, `clear: canvas locked`, `clear: filled`,
`flush: locking window`, `flush: frame copied`, `flush: done`), so the next
run says whether the stall is now in the canvas lock, in the drawing call
itself, or gone.

Two things this round deliberately does not know yet: whether the canvas lock
was really the blocker (Haiku renders drawing into a views-bitmap through
app_server, so a stall could also be in that round trip rather than the lock),
and whether the snapshot blit is cheap enough — `g_frame` has no server-side
copy, so app_server may take the pixels again on the first blit of each frame.
Both are visible in the next run: the trace either reaches `flush: done` or it
does not, and the suite's timing shows whether the copy costs anything.

**Round 7 (2026-11-26, fifth run on Haiku, and the first yab slice).** Round 6's
snapshot fixed the hang: the build is unchanged and clean, the CLI suite stays at
39 passed / 0 failed / 2 skipped, and the GUI suite went from one passing test to
two:

```
PASS  g0130-yabasic-graphics
PASS  g0131-yabasic-printer
```

`graphics` is available and `g0130` now completes its whole statement sequence —
the primitives, `text`, `getbit$` and `putbit` — well inside its 45 second
timeout. The canvas-lock theory was right: the window thread was blocking the
interpreter on the bitmap lock that the snapshot removed.

That closes the graphic-window slice, so this round starts the yab layer. What
is in it:

* `src/yabasic.bison` and `src/yabasic.flex` are now project sources. The yab
  productions are taken from `yab/yab-1.8.3/yabasic.bison`, and the generated
  `src/bison.c`, `src/bison.h` and `src/flex.c` remain checked in (verified to be
  byte-identical to a regeneration from the 2.92.1 sources before any change).
  `make parser` regenerates them; a normal `cmake .. && make` still needs no
  bison and no flex.
* New commands: `window open/close/set`, `window count`, `window get "w","prop"`,
  `view x,y to x,y, "v", "w"`, `draw set` (colours and a font specification),
  `draw text/line/rect/roundrect/dot/circle/ellipse/arc/curve/triangle/polygon/
  flush`, `draw get "text-width"/"max-text-height"`, `screenshot`, and
  `bfilesize()`. The grammar is yab's, including the `to` separators.
* `set`, `get` and `count` are keywords only right after `window`, `view` and
  `draw` (a scanner start condition). Reserving them outright broke c020, which
  counts with a variable called `count`; that is exactly the yabasic
  compatibility the merged grammar has to keep.
* The interpreter glue is `src/yabcompat/rk_yab_cmd.c` (one dispatch for all the
  `cYAB*` opcodes, popping in reverse like yab's `graphic.c`), the bridge is
  `src/yabcompat/rk_yab.h`, and the implementation is
  `src/yabcompat/rk_yab.cpp`. `rk_gui_ensure_app()` is the one startup path both
  layers use, so there is still a single `BApplication` (decision D6).
* Tests: `gui` now means windows/views/drawing and covers `g0100`, `g0101`,
  `g0103` and `g0119`; the eleven widget tests ask for the new `gui-widgets`
  capability and keep skipping until the widget slice exists, so nothing turns
  red for a feature that is simply not written.

What was checked here, on the development machine (Linux, no app_server):

* A regeneration from the untouched 2.92.1 grammar produced byte-identical
  `bison.c`, `bison.h` and `flex.c`, so the toolchain matches the checked-in
  files (Bison 3.8.2, flex 2.6.4).
* All C sources and `rk_yab_cmd.c` compile and link against a throwaway stub of
  the two bridges (`.tools/`, not part of the project), and the CLI suite passes
  35 / 0 / 6 with that build. The six skips are the tests that only run when
  `peek$("os")` is Haiku; the stub reports `unix`.
* A program using every new command runs through the parser, the opcodes and the
  bridge: `window count` → 1, `window get "width"` → 301 for
  `window open 100,100 to 400,300`, the whole `draw` set, `draw get
  "text-width"`, `screenshot` and `bfilesize()`.
* `src/yabcompat/rk_yab.cpp` and `src/rk_gui.cpp` were syntax-checked with
  `g++ -fsyntax-only` against Haiku's own public headers, which catches API and
  type mistakes without a Haiku machine.
* `g0100`, `g0101` and `g0119` pass against the stub; `g0103` reaches its font
  assertions and fails only because the stub's text width ignores the font size.

What the next Haiku run has to confirm: that the `gui` probe opens a yab window
on app_server, and that `g0100`, `g0101`, `g0103` and `g0119` pass there. The
four tests open real windows, so if one of them stops, the runner's probe log and
the failing test's stderr say which call it was inside.

Next slice: `button`, `checkbox`, `radiobutton`, `textcontrol`, `text`,
`textedit`, `slider`, `statusbar`, `option`/`attribute`; then the list controls
(`listbox`, `dropbox`, `columnbox`, `treebox`, `calendar`, `colorcontrol`), then
menus, clipboard, `bitmap`, `canvas`/`region` and `message$`.
