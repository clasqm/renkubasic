# Phase 2 — Haiku GUI backend

Phase 2 replaces yabasic's Xlib graphic window with a Haiku window and adds the
yab compatibility layer. This document records both slices: the graphic window
and the yab layer (`src/yabcompat/`), which runs yab's `window`, `view` and
`draw` commands plus the widget controls, text, sliders, containers and
`canvas`/`region` and the list family. Menus, the clipboard and bitmaps are the
next slices.

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
| yab widget controls, text, sliders, containers, `canvas`/`region` | `src/yabcompat/rk_yab.cpp` | done; the `gui-widgets` tests run |
| yab lists, tree/column, calendar, colour control | `src/yabcompat/rk_yab.cpp` | done; the `gui-lists` tests run |
| yab menus, submenus and the clipboard | `src/yabcompat/rk_yab.cpp` | done; the `gui-menus` tests run |
| yab bitmaps | `src/yabcompat/rk_yab.cpp` | done; the `gui-bitmaps` test runs |
| yab file attributes (`attribute set`/`clear`/`get$`/`get`) | `src/yabcompat/rk_yab.cpp` | done; the `attributes` capability turns on the test |

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
  creates a `button`. It now covers `g0102` (canvas/region), `g0110` (buttons,
  check boxes, radio buttons), `g0111` (text labels, text control, text edit),
  `g0114` (sliders, scrollbar, status bar, spin control, stack view) and `g0115`
  (tab, box, split and stack views).
* `gui-lists` — `listbox`, `dropbox`, `treebox`, `columnbox`, `calendar` and
  `colorcontrol`; covers `g0112`, `g0113` and `g0116`.
* `gui-menus` — `menu`, `submenu`, the clipboard and `message$`; covers `g0117`
  and `g0118`.
* `gui-bitmaps` — `bitmap`; covers `g0120`.

Each family has its own probe, so a slice turns its tests on by itself and the
other tests keep skipping with a reason instead of failing for a command that is
simply not written yet.

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

**%expect 6.** The yab extensions add six shift/reduce conflicts, and all are
resolved the way yab resolves them: a `+` after `window get`/`draw get`
concatenates the result, a `,` after `draw get "prop", "text"` continues the
longer three-string form, and a `+` after `textcontrol get "id"` / `textedit
get "id"` runs the argument to the `+` (the getter takes the whole string
expression that follows it). The count is asserted, so a future rule that adds a
conflict makes bison fail instead of silently changing how an existing program
parses. The list family's string getters end in a bare expression too
(`listbox get$ "id", n`); those states carry the lowest precedence
(`%prec tARGUMENT`), which states the shift explicitly, so they resolve the same
way without being counted and the asserted number stays six.

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

**Widgets are children of the window's display view.** yab addresses its
controls by name; the layer keeps a registry (`YabWidget`) and puts each
`BButton`, `BCheckBox`, `BRadioButton`, `BStringView`, `BTextControl`,
`BTextView`, `BSlider`, `BStatusBar`, `BBox`, `BTabView` or scrollbar into the
window as a child of the display view, so app_server draws and operates it. A
`layout` command sets the resize mode the later widgets get. A command's last
string names the view the widget belongs to; the window's own root view answers
to the window's name, which is what yab programs pass, and a named view offsets
the coordinates.

**Container views own plain views.** `splitview` creates `id1` and `id2`;
`stackview` creates `id1` … `idN` and shows one at a time; `canvas` and `region`
are ordinary drawable views. All of them are offscreen surfaces composited into
the window frame, and `draw flush` now repaints every visible view in creation
order (white first), so switching a stack page cannot leave the old page's
pixels behind.

**Two small extensions.** yab has no way to read a widget back, but a text
control and a text edit are only useful if the program can, so
`textcontrol get "id"` and `textedit get "id"` are RenkuBASIC string
functions. And because a yab program selects its font with `draw set`, that
command also records the specification as yabasic's `fontname`, which is what
`peek$("font")` reports (`g0103` asserts exactly that).

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
* **`draw` covers the primitives the GUI tests use.** There is no view removal
  yet.
* **Bitmaps cover the forms the tests use.** `bitmap w, h, id`,
  `bitmap get id, "path", file`, `bitmap remove id` and
  `draw bitmap x, y, id, mode, view` work. Not ported: `bitmap get` with
  `"mime16"`/`"mime32"` (a MIME type's application icon), the numeric-size icon
  form (`bitmap get 32, id, path`), the scaling form of `draw bitmap`
  (`draw bitmap x1, y1 to x2, y2, …`), `bitmap get` copying a screen area, and
  `canvas drag`. Each is an error naming the command, not a silent no-op.
* **The column box has no horizontal scrolling.** Haiku's `BColumnListView` is
  a private header, so the column box is a plain `BListView` that draws its own
  cells under its own header row; it scrolls vertically only, and a column
  wider than the box is clipped.
* **The calendar is drawn by hand.** Haiku has no calendar view, so
  `YabCalendar` is a `BTextControl` with a month grid it paints itself: Monday
  first, a click selects a day, the arrows change the month. `calendar set`
  parses the date at fixed offsets 0/3/6 and prints it back as
  `%02d<sep>%02d<sep>%04d`, which is what yab does.
* **A drop box selection is 1-based.** yab's `DropBoxGetNum` returns a 0-based
  index while every other list reports 1-based positions; RenkuBASIC returns
  1-based for the drop box too, so `select n` and `get` agree.
* **`treebox sort` flattens nothing.** It is `BOutlineListView`'s full-list sort
  with level skipping, as in yab, so sorting keeps each item under its parent.
* **Widgets are the controls, not yab's custom classes.** A `boxview` is a
  `BBox`, so it has no drawable child view of its own; tab pages are empty
  `BView`s; a split view has two panes whose bar only `splitview set` moves,
  because a yab view is an offscreen bitmap at a fixed rectangle and cannot
  follow a dragged bar; `scrollbar` attaches bars to the window over the view's edges rather
  than scrolling its contents; a spin control is a text field with `+`/`-`
  buttons, because Haiku has no spinner; `textedit` wraps but has no scrollbars
  yet; and `texturl` keeps its link as a tool tip, since there is no URL
  handler.
* **`message$` reports yab's widget events, with two families still open.**
  Buttons, check boxes, radio buttons, text controls, sliders, colour
  controls, the list family (selection and invocation), drop boxes, menus and
  the window's own activation, deactivation and close request all append their
  yab spelling to a per-window queue that `message$` drains. `mouse message$`
  and `keyboard message$` are not implemented: they need mouse tracking and
  keyboard focus messages per view, not the event queue. Dropped files
  (`_Dropped`) are not reported either, because a yab view is an offscreen
  bitmap here and never receives a drop.
* **The audio commands play one sound at a time.** `sound` uses the game kit,
  which plays WAV files (and loops them); `mediasound` plays whatever the media
  kit can decode, so its formats are the machine's decoders. There is no mixing
  of several simultaneous sounds, no seeking and no length/position query,
  because yab has none of those either: its stop and wait commands take an
  argument they ignore. `loudness` moves the whole mixer, as yab's does.
* **The dialogs cover yab's common forms.** `alert text$, button$, icon$` is a
  command; yab's five-argument alert *function* (three buttons, returning the
  number of the button pressed) needs five arguments, and the interpreter's
  function dispatch stops at four. `filepanel` takes the mode, the title and the
  starting directory, but not yab's fourth argument, the name a save panel
  starts with: after the third string a ',' is ambiguous with the end of the
  argument list, which would cost a seventh shift/reduce conflict. `BFilePanel`
  has no title of its own, so the title is accepted and unused. `popupmenu`
  returns the chosen label; yab offers shortcuts and icons in it, which are not
  built here.
* **Only the widget properties the tests need exist.** `option set` knows
  `label`/`text`, `enabled`, `value` and `tooltip`; `option colour` knows
  `bgcolor`, `highcolor` and `lowcolor`; a slider knows `barcolor` and
  `fillcolor` (Haiku's slider has one bar colour, so both set it) and hash
  marks; a text edit knows `highcolor`, `bgcolor` and `lowcolor`. An unknown
  property is a runtime error naming it.
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

**Round 8 (2026-11-26).** The round-7 run on Haiku built clean and passed
everything except `g0103`, which failed exactly where predicted: `peek$('font')`
was empty, because a yab program selects its font with `draw set` and nothing
told yabasic's `fontname`. `draw set "<spec>"` now records the specification
(the bridge call lives in `rk_yab_cmd.c`, so the C++ side stays unaware of
yabasic's globals) and `g0103` gets past that assertion.

This round adds the widget slice: `layout`, `button`, `checkbox`,
`radiobutton`, `text`, `texturl`, `textcontrol`, `textedit`, `slider`,
`scrollbar`, `statusbar`, `spincontrol`, `option set`/`option colour`,
`tooltip`, `tabview`, `boxview`, `splitview`, `stackview`, `canvas` and
`region`, with their `set`/`add`/`remove`/`clear`/`label`/`colour` forms and the
two `… get` extensions. Notes:

* The scanner enters `YABKEY` after every widget keyword too, so `set`, `get`,
  `add` and `remove` are keywords only there. `add` and `remove` are guarded by
  trailing context (`ADD/[ \t]`), and `set`/`get` got the same guard, so a
  program can still write `add$`, `set$` or a variable named `add`.
* `text 10, 10, "id", "label", "window"` is the widget form, exactly as in
  yab, and it takes the place of yabasic's third `text` form (three strings
  after the coordinates). That production is gone: for a merged grammar yab's
  reading has to win.
* The two `… get` string functions add two conflicts, both about a following
  `+` (the argument runs to it), so `%expect` is 6.
* On the C++ side the widgets are one registry: creation commands build the
  Haiku control and attach it to the window's display view under the window
  lock, property commands find it by name and change it under the same lock,
  and a failed call becomes a runtime error naming the widget or the property.
  Closing a window frees the registry entries; the window deletes the controls.
* `draw flush` and a stack page switch go through one `refresh_window()`, which
  paints the frame white and composites every visible view in creation order.
* A tab page belongs to its `BTab`: `RemoveTab()` detaches the page and returns
  the tab without deleting it, and the tab's destructor deletes the page. The
  first round-8 Haiku run hung in `tabview remove` because the code deleted the
  page as well; a second free on Haiku reaches `debugger()`, which blocks the
  thread, so the symptom was a timeout with no output instead of a crash.

Checked here (Linux, no app_server): the grammar regenerates with the expected
six conflicts; all C sources plus a stub of both bridges build and link; the CLI
suite stays at 35 / 0 / 6; `g0102`, `g0110`, `g0111`, `g0114` and `g0115` run
end to end against the stub, which is what exercises the argument order, the
keyword states and the `textcontrol get`/`textedit get` round trip; `g0103` now
passes the `peek$("font")` assertion and fails only on the stub's font-width
limitation; and `rk_yab.cpp` still passes `g++ -fsyntax-only` against Haiku's
own public headers. Not checked: anything on app_server. No control was ever
drawn, so layout, focus, resizing and event handling on Haiku are the next run's
business.

The first Haiku run of this slice passed ten tests and timed out on `g0115`
(views) in `tabview remove`, for the ownership reason above; that fix is the
only change since. What the rerun should show: `gui-widgets : available`;
`gui-lists`, `gui-menus` and `gui-bitmaps` unavailable with their probe
explanation; and `g0100`, `g0101`, `g0102`, `g0103`, `g0110`, `g0111`, `g0114`,
`g0115`, `g0119`, `g0130` and `g0131` passing.

**Round 9 (2026-11-27).** The list family: `listbox`, `dropbox`, `treebox`,
`columnbox`, `calendar` and `colorcontrol`, with `add`, `remove`, `select`,
`clear`, `sort`, `expand`/`collapse`, `column`, `colour` and `set` where yab has
them, plus the getters. Notes:

* yab spells its text getter `get` and its numeric one `getnum`; yabasic's
  `get` is already a keyword here, so the text getters are `get$`
  (`listbox get$ "id", pos`) and the numeric ones keep `get` (item count, the
  selected position, the colour components, `columnbox count column`).
  `textcontrol get` and `textedit get` keep the plain spelling they were
  introduced with, and now accept `get$` as well.
* `count` stays in the command state after a widget keyword, because
  `columnbox count column "id"` is the one form where a second command word
  follows; the state's fallback rule rescans anything else normally. `column`,
  `sort`, `select`, `expand` and `collapse` are likewise keywords only there and
  only with trailing context, so identifiers with those names keep working.
* `treebox add "id", "parent", "item", expanded` builds a real hierarchy in a
  `BOutlineListView`, and `get$`/`select` count the flattened list. yab's
  five-argument `treebox add` form is left out: yab's own `graphic.c` pops only
  three of the five arguments it pushes, so the form is broken there.
* Haiku's `BColumnListView` lives in a private header, so the column box is a
  `BListView` (`YabColumnList`) that draws its own cells, under a header view
  that draws the titles. `columnbox add` sets one cell, which creates the row
  the first time that position appears.
* The calendar is `YabCalendar`: a text field plus a month grid it paints
  itself, because Haiku has no calendar control. The format string only picks
  the divider (`/`, `-`, else `.`) and month-day order when it contains `MD`,
  exactly as yab's `graphic.c` does.
* `colorcontrol` is a `BColorControl`, created without the size check the other
  widgets go through, because it sizes itself from its corner.
* `columnbox colour` matches its option the way yab does: case-insensitively
  anywhere in the string and in yab's order, so "Selection-Active" and
  "Row-Divider" from yab's own Filebox example work, and "bgcolor" is rejected
  just as yab rejects it.
* The drop box reports 1-based positions, unlike yab's 0-based
  `DropBoxGetNum`; see the gaps list.

The C++ side gained one registry entry per kind and a `BView *outer`: a list or
table can be wrapped in a `BScrollView`, and the widget entry keeps the wrapper
for deletion while `view` stays the control the commands operate.

Checked here (Linux, no app_server): the grammar regenerates with the expected
six conflicts; all C sources plus the stub bridges build and link; `g0112`,
`g0113` and `g0116` pass end to end against the stub, which exercises the
keyword states, the argument popping and the `get$`/`get` split; the CLI suite
stays at 35 / 0 / 6; and `rk_yab.cpp` passes `g++ -fsyntax-only` against Haiku's
own public headers. That check found three API mistakes, now fixed: `BListView`
and `BOutlineListView` take the selection type after the name, and a
`BListItem` is selected with `Select()`/`Deselect()`, not `SetSelected()`. The
first Haiku build then failed to link one more: `BListItem::DrawItem` is
declared in the header but libbe defines it only inside its own subclass, so the
row's fallback path paints a plain row with the standard list colours instead of
calling it.

The round-9 Haiku run built clean: CLI 39 / 0 / 2, `gui-lists` probed as
available, and `g0112` and `g0116` passed at once. `g0113` failed on
`columnbox colour "rk_cols", "bgcolor"`, which is my test's spelling rather than
yab's: yab matches the option case-insensitively anywhere in the string and only
knows `selection-text`, `non-focus-selection`, `selection`, `text`,
`row-divider` and `background`. The table had compared whole strings, so it also
rejected yab's own `Filebox.yab` spellings (`Selection-Active`, `Row-Divider`);
both are fixed, and the test asks for `background`. The rerun passed everything:
GUI 14 / 0 / 3.

**Round 10 (2026-11-27).** Menus and the clipboard: `menu`, `submenu`,
`subsubmenu` with their `set` forms (radio groups and the `disable`, `enable`,
`mark`, `plain`, `remove` options), `clipboard copy`/`clipboard paste$`, and the
`translate$`/`menu translate$` functions. Notes:

* Each window gets one `BMenuBar`, created by the first menu command and kept
  in the window's entry, with the menus and submenus under it. A label that is
  already a plain item becomes a submenu when a `submenu` command names it, as
  in yab's `SubMenu`.
* The shortcut string is yab's: its last character is the key, and an `s`, `c`
  or `o` before it adds shift, control or option. The menu options are matched
  the way yab matches them, one substring test each, last match wins.
* yab spells the clipboard getter `paste$` (its scanner matches the literal
  `PASTE$`), so the test uses `clipboard paste$`; `copy` and `paste$` are
  keywords only after `clipboard`, and `translate$` is a keyword on its own
  because yab programs call it in expressions.
* The clipboard holds `text/plain` without a terminator, exactly as yab stores
  it, and paste reads it back by length.
* RenkuBASIC ships no message catalogs, so `translate$` returns its identifier
  unchanged; that is also what yab returns for a key its catalog does not know,
  and it is what `g0117` asserts (an unknown identifier must not become empty).
  `menu translate$` has the same answer, because with no catalog every `:`
  separated part keeps its text.
* `message$` and `attribute` are not part of this slice: they need a widget
  event queue, which is the next slice's work, so a menu item's message is
  posted to a `BMessage` nothing reads yet.

Checked here (Linux, no app_server): the grammar regenerates with the expected
six conflicts, so the menu productions add none; all C sources plus the stub
bridges build and link; `g0117` and `g0118` run end to end against the stub, as
do `g0112`, `g0113` and `g0116`; a scratch program exercises every menu form,
`menu translate$` and `clipboard paste$`; the CLI suite stays at 35 / 0 / 6; and
`rk_yab.cpp` passes `g++ -fsyntax-only` against Haiku's public headers. Not
checked: anything on app_server. No menu bar has been drawn or opened, and no
item has been clicked, so layout of the bar, submenu placement and the radio and
check marks are the next run's business.

The first Haiku run of this slice probed `gui-menus` as available but failed
both new tests, for two unrelated reasons. `g0117` asked for a button at
y 240–264 in a window only 221 pixels tall, so the widget fits check (rightly)
refused it; the test's window is now 320 pixels tall. `g0118` failed with "the
clipboard is busy" on its first command, because a `BApplication` owns the
clipboard and that test copies before it opens any window; `clipboard copy` and
`clipboard paste$` now start the application first, and paste reads an
unavailable clipboard as the empty string, which is what yab does. The Linux
stub reproduces neither the fits check nor the missing application, which is why
both reached Haiku.

The first Haiku run of the menu slice probed `gui-menus` as available but failed
both new tests, for two unrelated reasons. `g0117` asked for a button at
y 240–264 in a window only 221 pixels tall, so the widget fits check (rightly)
refused it; the test's window is now 320 pixels tall. `g0118` failed with "the
clipboard is busy" on its first command, because a `BApplication` owns the
clipboard and that test copies before it opens any window; `clipboard copy` and
`clipboard paste$` now start the application first, and paste reads an
unavailable clipboard as the empty string, which is what yab does. The Linux
stub reproduces neither the fits check nor the missing application, which is why
both reached Haiku. The rerun passed everything: GUI 16 / 0 / 1.

**Round 11 (2026-11-27).** Bitmaps: `bitmap w, h, id`,
`bitmap get id, "path", file`, `bitmap remove id` and
`draw bitmap x, y, id, mode, view`. Notes:

* The bitmap registry holds name -> `BBitmap`. Every bitmap is `B_RGBA32` with a
  child view named like the bitmap, as yab's bitmaps have, and is cleared to
  transparent black.
* `draw bitmap` blits into a view's canvas with yab's modes in yab's order
  (`copy`, `alpha`, `invert`, `max`, `min`, `subtract`, `add`, `blend`),
  matched case-insensitively anywhere in the string. The view keeps its drawing
  mode afterwards, as in yab.
* `bitmap get` with `"path"` asks the file for its tracker icon
  (`BNodeInfo::GetTrackerIcon`, a 32 by 32 `B_CMAP8` icon) and paints that over
  a transparent bitmap with `B_OP_OVER`, so the icon's transparent pixels stay
  transparent; yab copies it with the default `B_OP_COPY`.
* `g0120` follows the shape of yab's `3D-Curve.yab`, `FakeTransparency.yab` and
  `IconWorld.yab`: draw into a view, capture it with `screenshot`, load the file
  as a bitmap, blit it back with `copy` and `alpha`, capture again, then remove
  the bitmap.

Checked here (Linux, no app_server): the grammar regenerates with the expected
six conflicts, so the bitmap productions add none; all C sources plus the stub
bridges build and link; `g0120` runs end to end against the stub, as do `g0117`,
`g0118` and `g0112`; a scratch program exercises `bitmap w, h, id`, four drawing
modes, a file's tracker icon, a screenshot of the result and both removes; the
CLI suite stays at 35 / 0 / 6; and `rk_yab.cpp` passes `g++ -fsyntax-only`
against Haiku's public headers. Not checked: anything on app_server -- no bitmap
has been blitted there, and the icon path needs a real `BNode` and a real file,
so what the blit looks like is the next run's business.

The first Haiku run of the slice passed `g0120` and probed `gui-bitmaps` as
available, but `g0115-views` failed with status 1 after printing its own last
line, and with nothing on stderr. That combination has only two possible
causes: an assertion in the test harness (which prints what it asserted before
exiting) or a signal that arrives once the program has finished, which the
signal handler turns into a bare `exit(1)`. So the handler now prints the signal
number instead of exiting silently, and the runner exports `RK_GUI_TRACE` for
the widget suites as it already did for `gui` and `graphics`, so the next
failure shows how far the backend got.

Reading the close path for the cause found a real defect worth fixing whatever
the signal turns out to be: `destroy_window` deleted a window's views even when
the window thread never gave up its lock, leaving a running thread with
pointers to freed views -- a crash waiting for the next message, and a `window
close` that reports success. It now tries the lock for two seconds in short
steps; when the lock still does not arrive nothing is freed, the window goes
back into the registry, and `window close` fails with "the window did not
respond to window close" instead of pretending.

The rerun passed everything: CLI 39 / 0 / 2, GUI 17 / 0 / 0, `g0115` among
them. That is the second intermittent failure in that test and the only change
between the failing and the passing run was the close-path fix, so the failed
lock is the best explanation the evidence supports; the trace and the signal
name stay in, because a future failure of that test has to be readable.

**Round 12 (2026-11-27).** File attributes: `attribute set type, name, value,
file`, `attribute clear name, file`, `attribute get$(name, file)` and
`attribute get(name, file)`. This is not a widget feature: yab's `attribute`
writes typed metadata onto a file through `BNode`, which is why it is a slice of
its own and why it lands in the CLI suite rather than the GUI one. Notes:

* The type word is matched the way yab matches it -- case-insensitively,
  anywhere in the string, in yab's order: `string`, `mime`, `bool`, `i8`, `u8`,
  `i16`, `u16`, `int`, `l32`, `u32`, `l64`, `u64`, `double`, `float`, `time`.
  Because the order is yab's, `uint32` is written as an `int` (it contains
  `int`); that is yab's behaviour, not an oversight.
* `bool` is one byte, 0 only when the value contains "false", and `string`/
  `mime` are stored with their terminating zero, as yab stores them.
* Integers are range-clamped to their type exactly as yab clamps them, so
  `attribute set "u8", ..., "300", ...` stores 255.
* `attribute get$` reads the type back: numbers and bools as text, `time` through
  `localtime` and `strftime("%c")`, string and MIME types (and the three
  signature types) as the stored text, and anything else as yab's hex dump with
  the empty string as the result. With an empty name it lists every attribute of
  the file as `name | Type | name | Type |`, trailing separator included, using
  yab's type names (`String`, `Int`, `Bool`, `Long`, ...).
* `attribute get` is a numeric function in the grammar, not a string one: a rule
  in `string_function` makes the compiler pop the result as a string and the
  number turns into "expected a string but found a number" at run time. Sorting
  that out cost a round trip, and the rule for `attribute get$` stayed where it
  was; the grammar still has exactly the expected six conflicts.
* `attribute clear` ignores whether the attribute was there, as yab does.

Two deliberate departures from yab, both in `attribute set`, both about types
yab writes in a form no reader can use: `int`/`l32` write a real 32-bit integer
instead of the value's characters, and `time` writes the seconds it parses
instead of the value's characters under `B_TIME_TYPE`. yab's empty-name fallback
of returning the directory of the running program when the file does not exist
is not ported either; a file that cannot be read is an error naming it.

Checked here (Linux, no attributes): the grammar regenerates with the expected
six conflicts; all C sources plus the stub bridges build and link; the test
program compiles and reaches the bridge (the stub refuses, so the run stops
there); a scratch program exercises both getter spellings in an assignment and
inside `print`, which is what found the arity and `string_function` mistakes;
and the CLI suite stays at 35 / 0 / 7 with `c084` skipped for the missing
capability. Not checked: anything on Haiku -- no attribute has been written
through `BNode` here, so the round trip, the type words and the listing format
are the next run's business.

What the next Haiku run has to show: `attributes : available` in the banner, 36
CLI tests passed with `c084-attributes` among them, and the GUI suite unchanged
at 17 / 0 / 0.

The first run of the slice probed `attributes` as unavailable, and the probe
output named the cause: `if-clause starting at line 8 has seen no 'endif'`.
That was the probe, not the grammar -- yabasic's `if ... then` form always wants
an `endif`, and only a short `if` (no `then`) ends at the newline. The probe now
closes its `if`, and the parser had already accepted the three `attribute` lines
before it.

The rerun probed `attributes` as available and passed every CLI test except
`c084-attributes`, which failed on "int attribute as a number -- got 0, expected
42". That was a real defect: `attribute get` read the attribute's bytes and ran
`atof` over them, so a real `B_INT32_TYPE` attribute (`2a 00 00 00`) read as
zero while `attribute get$` correctly said "42". The numeric getter now decodes
the stored type -- int8 through int64, float, double, bool, and `time` as the
seconds it holds -- and only treats an attribute as text (string and MIME)
when it is one.

The third run was green: CLI 40 / 0 / 2, GUI unchanged at 17 / 0 / 0, with
`attributes : available`. That is round 12 accepted.

**Round 13 (2026-11-27).** `message$` and the widget event queue. Notes:

* yab spells the getter `message$`, and its scanner matches the literal
  `MESSAGE$`; RenkuBASIC adds `tMESSAGE` to the same keyword list. The bare form
  is the only one in the grammar: `message$()` would put a shift/reduce
  conflict on the `(`, and yab's own programs call `message$` without
  parentheses. The grammar still regenerates with exactly six conflicts.
* A window owns a `std::string` queue. The window thread appends to it under
  the window lock (its `MessageReceived`, `WindowActivated`, `QuitRequested`),
  and `message$` locks each window, takes the text and clears it. The registry
  itself has a `std::mutex`, because windows register before they are shown
  (their first activation has to find them) while their threads look themselves
  up; it is never held across a window lock.
* Widgets are wired where they are registered: a button, check box, radio
  button, text control, slider or colour control posts one message with a
  pointer to its registry entry, a list posts separate selection and invocation
  messages, and drop box items carry the item they selected. The window thread
  turns each into yab's text, so no lookup by name is needed on the way back.
* The spellings are yab's: `name|` for a button or radio button,
  `name:ON|`/`name:OFF|` for a check box, `name:text|` for a text control,
  `name:value|` for a slider, `name:r:g:b|` for a colour control,
  `name:_Select:n|` and `name:_Invoke:n|` for the list family (1-based, and the
  tree box uses the full-list position), `window:item|` for a drop box, and
  `window:head:...:item|` for a menu. A window also reports
  `window:_Activated|`, `window:_Deactivated|` and `window:_QuitRequested|`.
* The close box now reports `_QuitRequested` and still refuses the quit, which
  is exactly what yab does: the program decides when the window goes. That
  makes yab's `while not instr(message$, "_QuitRequested|")` loop work, and it
  is what the manual test m0102 now exits on.
* `message$` posts nothing and never sleeps: events wait in the queue until the
  next call. That is a departure from yab, which snoozes 20 ms before it
  harvests, and it is what lets a program poll in a tight loop.
* `mouse message$`, `keyboard message$` and dropped files are not part of this
  slice (see the gaps list); the manual test no longer asks for the keyboard
  form, which never parsed.

Checked here (Linux, no app_server): the grammar regenerates with the same six
conflicts; all C sources plus the stub bridges build and link; `print
message$`, `a$ = message$` and `"[" + message$ + "]"` compile and run against
the stub as the empty string; the new `g0121` parses and takes its failure at
the activation assertion, which is the stub's expected answer; the CLI suite
stays at 35 / 0 / 7; and `rk_yab.cpp` passes `g++ -fsyntax-only` against Haiku's
public headers (which is how `SetInvokeMessage` was caught -- the list uses
`SetInvocationMessage`). Not checked: anything on app_server -- no click has
reached a widget here, so the event strings, the menu paths and the drop box
form are the next run's business.

What the next Haiku run has to show: GUI 18 / 0 / 0 with `g0121-messages`
passing (a new window reports `_Activated`), and the CLI suite unchanged at
40 / 0 / 2.

Accepted on Haiku (2026-11-28): GUI **18 / 0 / 0** with `g0121-messages`
passing -- a new window does report `_Activated` -- and CLI **40 / 0 / 2**. The
same run started the three manual tests. `m0102-widget-messages` stopped at its
radiobutton with "the widget does not fit into its window": the test's window
was 321 pixels tall and the test's list box ends at y = 490, so the window is
now 520 pixels tall instead. `m0100-alerts` and `m0101-filepanel-popupmenu`
stopped at a syntax error, because `alert`, `popupmenu` and `filepanel` were
never ported; that run was built from a tree that predates round 14 too, so
`g0122-containers` was not in it. Round 15 is those three commands.

**Round 14 (2026-11-28).** Split view geometry and the container getters.

The three container views had only their creation commands; yab's `set` and
`get` forms were missing. Notes:

* Five commands are new: `splitview set id, "divider", position`,
  `splitview set id, "minimumsizes", left, right`,
  `splitview get(id, "divider")`, `tabview get(id)` and `stackview get(id)`.
  They are grammar additions only -- `splitview` and the other two were already
  keywords, and `get`/`set` already follow them -- so the grammar still
  regenerates with exactly six conflicts.
* A split view is registered as a widget now (it was two anonymous views), and
  it keeps what yab's SplitPane keeps: its frame, its orientation, the bar
  thickness, the bar position and the two panes' minimum sizes. Moving the bar
  or setting a minimum lays the two panes out again from that state.
* The bar position counts from the split's left or top edge, as
  `SplitPane::GetBarPosition()` returns it, and is clamped so neither pane
  falls below its minimum -- the same clamp `SplitPane::Update()` applies, and
  the reason `splitview get` can report a number other than the one that was
  set. The panes are opened at their own size, so `draw get "width"` on a pane
  still reports the pane and not the whole split.
* The options are found as yab finds them, by a case-insensitive substring
  (`BString::IFindFirst`): "Divider" and "divider bar" both name the bar, and
  "minimumsizes" matches SplitPane's "MinimumSizes". Any other option is a
  runtime error naming it.
* `tabview get` asks `BTabView` for its own selection, so it follows a tab the
  user clicks; a stack view keeps its page in the widget entry, because its
  pages are RenkuBASIC's own views and not a Haiku control.
* The bar still has no drag handle (see the gaps list). Haiku's `BSplitView`
  moves real child views, while a yab view here is an offscreen bitmap
  composited at a fixed rectangle, so a dragged bar would have to move the
  panes' rectangles and their contents. `splitview set` is how a program moves
  it.

Checked here (Linux, no app_server): the grammar regenerates with the same six
conflicts; all C sources plus the stub bridges build and link; the new `g0122`
runs green against the stub, which repeats the bar clamp so the test exercises
it; `g0115`, the older container test, still runs green; the CLI suite stays at
35 / 0 / 7; and `rk_yab.cpp` passes `g++ -fsyntax-only` against Haiku's public
headers. Not checked: app_server -- no bar has been moved on screen here, so
whether the panes are redrawn where the geometry says they are is the next
run's business.

What the next Haiku run has to show: GUI 19 / 0 / 0 with `g0122-containers`
passing as well as `g0121-messages`, and the CLI suite unchanged at 40 / 0 / 2.
The run that accepted round 13 was built before this round, so it did not
include `g0122`; the two rounds are checked together next time.

**Round 15 (2026-11-28).** The three dialogs: `alert`, `popupmenu` and
`filepanel`.

The three manual tests found them missing. They are the first commands in this
layer that stop the program until a human answers, which is why they were left
for a round of their own. Notes:

* `alert text$, button$, icon$` is yab's one-button alert. The icon word is
  matched anywhere in the string, case-insensitively, in yab's order (info,
  idea, warning, stop) and anything else is an empty alert. `Go()` blocks until
  a button is pressed and deletes the alert then, exactly as yab's call relies
  on.
* `popupmenu x, y, "item|item|--|item", "view"` builds a `BPopUpMenu`, opens it
  at the point named -- relative to the view, or to the window when the view is
  the window's own name -- and returns the chosen label, or "" when the menu was
  dismissed. "--" is a separator, as in yab. The window is locked only long
  enough to convert the point to screen coordinates, so the menu's own loop is
  never run under the window lock.
* `filepanel mode$, title$, directory$` returns the chosen path or "" when the
  panel was cancelled. `BFilePanel` only reports by message, so the target is a
  looper of our own that records the path and releases a semaphore the caller
  waits on; `B_CANCEL` releases it with an empty answer. The mode is yab's,
  matched by substring with the longest form first, so "Load-File-and-Directory"
  is not read as "Load-File".
* The three of them start the application themselves, because a program may
  raise an alert before it opens a window.
* Two yab forms are not in the grammar, both for the same reason: they would
  mean a seventh shift/reduce conflict (the grammar is pinned at six). yab's
  five-argument `alert` *function* (`alert text, b1, b2, b3, icon` returning the
  button number) needs five arguments and the interpreter's function dispatch
  stops at four. yab's four-argument `filepanel` (the name a save panel starts
  with) puts a ',' where the three-argument form reduces, so it is genuinely
  ambiguous; `popupmenu` and the two `filepanel` forms above are unaffected.
  See the gaps list.

Checked here (Linux, no app_server): the grammar regenerates with the same six
conflicts (the four-argument `filepanel` rule was tried and removed for this
reason); all C sources plus the stub bridges build and link; a probe script with
`alert`, both `filepanel` forms and `popupmenu` parses and runs against the stub
(which answers 1 and ""); the CLI suite stays at 35 / 0 / 7; `g0122` still runs
green; and `rk_yab.cpp` passes `g++ -fsyntax-only` against Haiku's public
headers, which is where `BAlert`, `BFilePanel`, `BPopUpMenu::Go` and the
`create_sem`/`BMessenger` calls were checked. Not checked: app_server -- no alert
has been pressed, no popup opened and no panel shown here, so a real click is
the next run's business.

What the next Haiku run has to show: GUI 19 / 0 / 0, and the three manual tests
(`m0100`, `m0101`, `m0102`) running to the end by hand.

**Round 16 (2026-11-28).** The audio commands, and the tests that go with the
two sound files now in `tests/`.

yab's audio family was missing entirely, so there was nothing for an audio test
to call. The round ports the commands and then tests them. Notes:

* Five commands and three getters: `sound play file$, loop` and
  `mediasound play file$` (both functions returning 1 when the file started),
  `sound stop n`, `sound wait n`, `mediasound stop n`, `loudness set volume` and
  `loudness get`.
* Only one sound plays at a time, which is why yab's stop and wait commands take
  an argument nothing uses: starting a sound stops the previous one.
* `sound` goes through the game kit -- `BFileGameSound`, which plays WAV files
  and loops them -- and `sound wait` is yab's pause toggle: it pauses a playing
  sound and resumes a paused one. `mediasound` goes through the media kit: the
  first track of the file that decodes to raw audio is fed to a `BSoundPlayer`
  by its buffer callback, so MP3 and everything else the media kit decodes
  plays, and the player is told when the track runs out. `loudness` is the audio
  mixer's `B_MASTER_GAIN` parameter, read and written through its parameter web
  and clamped by the mixer's own minimum and maximum.
* The scanner gets the words by trailing context, as the other command families
  do: `sound`, `mediasound` and `loudness` are keywords, but `play`, `stop` and
  `wait` only are directly after `sound` or `mediasound`, and only when the word
  really ends there -- a variable called `stopwatch` still scans as a variable.
  The shared `get` rule also learned to end a line, because `loudness get` is a
  getter with no argument at all.
* `sound play`'s file is a plain path (the game kit takes one), while
  `mediasound play` needs an `entry_ref` first. A missing file, a file that is
  not audio, a file with no audio track and a missing audio output are runtime
  errors naming the command, not a silent zero.
* The build now links `libgame` and `libmedia` as well as `libbe` and
  `libtranslation`; CMake fails with a clear message if any of the four is
  missing.

Tests:

* `tests/gui/g0123-audio.yab` starts the short WAV once, pauses and resumes it,
  stops it, plays it looping and stops it, plays it through the media kit and
  stops it, stops both players a second time (stopping nothing must not fail),
  reads the master gain and checks it is plausible. It cannot hear anything, so
  it proves the commands run and leave no stuck player, not that the sound is
  audible.
* `tests/manual/m0103-audio.yab` is the listening test: it prints seven steps
  and waits between them, so a person can confirm the WAV plays once, loops,
  pauses, resumes and stops, and that the MP3 decodes through the media kit.
  A media kit without an MP3 decoder stops the program at step 6, after the WAV
  steps have passed.
* The runner learned two things for these: an `@data:` directive that copies
  files from `tests/` into the test's own scratch directory (`@data: INTRO.WAV`,
  or several names), because every test runs in a fresh directory, and an
  `audio` capability probe that plays `tests/INTRO.WAV` once and reads the
  master gain. A machine without a sound device reports `SKIP` for the group
  instead of failing it.

Checked here (Linux, no app_server): the grammar regenerates with the same six
conflicts; all C sources plus the stub bridges build and link; the CLI suite
stays at 35 / 0 / 7; `g0123` and `m0103` both run to the end against the stub
(which answers 1 to the players and 0.5 to the gain), `g0123` failing only its
fixture check when the WAV is not beside it; the `gui` and `manual` suites skip
both on the stub as `requires audio`; and `rk_yab.cpp` passes `g++ -fsyntax-only`
against Haiku's public headers, which is where `BFileGameSound`,
`BSoundPlayer`, `BMediaFile`/`BMediaTrack` and the parameter web calls were
checked. Not checked: no sound has been heard here, and the MP3 path depends on
the media kit's decoder on the run's machine.

What the next Haiku run has to show: GUI **20 / 0 / 0** (the 19 from round 14
plus `g0123-audio`, or 19 passed and one skipped if the audio probe fails), the
CLI suite unchanged at 40 / 0 / 2, and `m0103-audio` played by hand with the
seven steps heard.

Next slice: `mouse message$` and `keyboard message$`, which now have a queue to
feed.
