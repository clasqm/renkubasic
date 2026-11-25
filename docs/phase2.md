# Phase 2 — Haiku GUI backend

Phase 2 replaces yabasic's Xlib graphic window with a Haiku window and adds the
yab compatibility layer. This document records the first slice: the graphic
window. The yab widget layer (`src/yabcompat/`) is the next slice.

## What exists now

| Piece | Where | State |
| --- | --- | --- |
| C bridge between the C core and the Haiku kits | `src/rk_gui.h` | done |
| `BApplication`, `BWindow`, `BView`, `BBitmap` backend | `src/rk_gui.cpp` | first build round fixed, next build pending |
| yabasic drawing commands on that bridge | `src/rk_graphics.c` | ported from 2.92.1 |
| TrueType/OpenType font selection | `rk_gui_set_font()` | done |
| `getbit$` / `putbit` | `rk_graphics.c` | ported, same `rgb W,H:` string format |
| PNG capture of the canvas | `rk_gui_save_png()` | done; wired to a command in the yab layer, not yet called from yabasic |
| PostScript file output | `rk_graphics.c` | writes a header and page breaks; not yet complete PostScript |
| Haiku print server | — | not started |
| yab widgets, views, draw, BFS helpers | `src/yabcompat/` | not started |

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

**One BApplication, message loop on a helper thread.** Decision D6 says one
application object for both the graphic window and yab widgets. The interpreter
owns the main thread for the whole program, so the application's looper runs on
a helper thread and every window operation from the interpreter takes the window
lock. This is the part of the design most likely to need adjustment on a real
Haiku system; if the app_server rejects window creation from the interpreter
thread, the fix is to create the window on the GUI thread and post the
interpreter's drawing requests to it.

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

`g0103-fonts.yab` (TrueType metrics through yab's `draw get`) stays with the yab
layer, because it uses yab syntax; the yabasic equivalent is exercised by
g0130's two `text` calls with an explicit font.

## Known gaps

* **PostScript output is incomplete.** The file has a valid header and page
  breaks, but the drawing operators (`LI`, `RE`, `CI`, `TRI`, `DO`, `AT`) are
  written without the prolog that would define them, so the file is not yet
  printable. Completing the prolog, and handing the finished file to the Haiku
  print server, is the printing task left in this phase.
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

What still has to be confirmed on the first successful build: whether a
`BApplication` created on the interpreter thread accepts `Run()` on a helper
thread (yab instead runs the application on the main thread and the interpreter
on a helper), and whether `BBitmap::Lock()` around the blit is enough for the
window thread's `Draw()`. If either fails, the fallback is to create the window
on the GUI thread and post drawing requests to it.
