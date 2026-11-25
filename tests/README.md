# RenkuBASIC test suites

Two automated suites and one interactive one, driven by a single shell script.
Phase 0 created them from the yabasic 2.92.1 and yab 1.8.3 example/test trees so
that Phase 1 (core compiles) and Phase 2 (GUI) have something to measure.

```
tests/
  run-tests.sh          runner: options, directives, pass/fail/skip reporting
  lib/                  libraries importable by tests (harness, c063 fixtures)
  cli/                  non-interactive programs
  gui/                  windows, widgets, drawing (needs an app server)
  manual/               interactive programs, run by a human (see manual/README.md)
  fixtures/             data files fed on stdin
```

## Running

```sh
# the whole automated set
tests/run-tests.sh

# a build that is not installed yet
tests/run-tests.sh --interpreter build/renkubasic

# only the command line suite, only string tests
tests/run-tests.sh --suite cli --filter c05

# what would run?
tests/run-tests.sh --list
```

Exit status is 0 when nothing failed, 1 when something failed, 2 for a usage or
setup problem. `PASS`, `FAIL` and `SKIP` lines are printed per test, with the
last lines of output for a failure; `--verbose` also shows the output of
passing tests.

## Suites

| Suite | Needs | What it proves |
| --- | --- | --- |
| `cli` | nothing but the interpreter | the language: control flow, strings, numbers, arrays, subs, libraries, files, stdin, system, peeks, errors, command line options |
| `gui` | a Haiku/RenkuOS desktop session (`window open` must work) | yab's window/widget/view API and yabasic's graphic window, including TrueType fonts, screenshots and PostScript printing |
| `manual` | a person | modal alerts, file panels, popup menus, the exact text of widget messages |

`--suite all` means `cli` + `gui`. `manual` is never included automatically.
The GUI suite is skipped with a reason when no window can be opened; a plain
yabasic binary is handled the same way.

## Test directives

A test declares what it needs in its first 40 lines, either as `// @key: value`
in a `.yab` file or `# @key: value` in a `.sh` file.

| Directive | Meaning |
| --- | --- |
| `@requires: renkubasic` | skip when the interpreter is not RenkuBASIC (used for the new requirements) |
| `@requires: gui` | skip when `window open` fails (no app server) |
| `@requires: pty` | skip when `script(1)` is missing |
| `@requires: ffi` | skip when the foreign function interface answers nothing |
| `@requires: haiku` | skip unless `peek$("os")` is `haiku` or `renkuos` |
| `@stdin: fixtures/digits.txt` | feed this file (relative to `tests/`) on stdin |
| `@expect-exit: 1` | the program is supposed to fail with status 1 |
| `@expect-stdout-contains: text` | stdout must contain `text` |
| `@expect-stderr-contains: text` | stderr must contain `text` |
| `@expect-empty-output: 1` | stdout and stderr must both be empty |
| `@timeout: 60` | per-test timeout in seconds (default 30) |
| `@skip: reason` | always skip, with a reason |

Exit status 77 from a test also means "skipped"; `harness.skip("reason")` does
that for you.

## Writing a test

```basic
// RenkuBASIC CLI test: what this checks
// Derived from: yabasic 2.92.1 tests/for.yab

import harness

assert_eq(2 + 2, 4, "arithmetic")
assert_str$(upper$("ab"), "AB", "upper$")

print "c999 done"
exit 0
```

Rules that keep the suite trustworthy:

1. A test prints nothing on success except an optional `done` line; the runner
   judges by exit status, not by parsing output.
2. The harness (`tests/lib/harness.yab`) stops the test at the first failing
   assertion and prints the actual and expected values.
3. Every ported test keeps a `Derived from:` line naming the upstream file, so
   behaviour can be re-checked against yabasic after an upstream update.
4. Expectations are pinned to what yabasic 2.92.1 actually does, not to what
   its manual claims, where the two differ (see the notes below).
5. New RenkuBASIC behaviour (OS detection, no `bind`, TrueType fonts) is marked
   `@requires: renkubasic`, so the suite can still be run against yabasic as a
   sanity check of the tests themselves.

## Using the suite as a baseline check

The suites were written and validated against a stock yabasic 2.92.1 build.
Running them against yabasic proves the tests are correct about the inherited
language before RenkuBASIC exists:

```sh
tests/run-tests.sh --interpreter /path/to/yabasic
```

Expected result: every `cli` test passes except the ones marked
`@requires: renkubasic` (c082, c083, c094, c095, c098), which report
`SKIP ... needs RenkuBASIC`. Any other failure is a bug in a test, not in the
interpreter.

## Coverage map

| CLI test | Covers | Ported from |
| --- | --- | --- |
| c010-print | print forms, separators, concatenation | yabasic `tests/simple.yab` |
| c011-print-format | `str$` pictures, C-style formats, `using` | `tests/strdollar.yab`, manual |
| c012-escape-sequences | every escape sequence | `tests/escape-sequences.yab` |
| c013-short-if | one-line `if` | `tests/short_if.yab` |
| c014-if-elsif | `if`/`elsif`/`else`/`fi`, short circuits | `tests/grammar.yab`, `tests/bugs.yab` |
| c020-for-loop | `for`/`next`/`step` | `tests/for.yab` |
| c021-loops-break | `break`/`continue`, `break 2`, stack check | `tests/break.yab` |
| c022-switch | number/string `switch`, fallthrough | `tests/switch*.yab` |
| c023-goto-gosub | `goto`, `gosub`, `on … goto/gosub` | `tests/switch_goto/gosub/subr.yab` |
| c030-arrays | `dim`, `redim`, sizes, string arrays | `tests/array.yab` |
| c031-array-references | arrays as sub arguments | manual, "References on arrays" |
| c040-numbers | rounding, maths, trig, `ran` | `tests/numbers.yab` |
| c041-hex-bin | base 2/16 literals and conversions | `tests/hex_bin.yab` |
| c042-bitops | bitwise operators | `tests/bitops.yab` |
| c043-compare | all comparison operators | `tests/compare.yab` |
| c050-strings | substring/trim/replace/glob/search | `tests/string.yab` |
| c051-string-assign | assigning to `left$`/`right$`/`mid$` | `tests/string.yab` |
| c052-token-split | `token`, `split` | manual, yab `Checkbox.yab` |
| c060-subs-local | recursion, `local`, return values | `tests/local.yab` |
| c061-subs-static-numparams | `static`, `numparams` | manual |
| c062-compile-execute | `compile`/`execute`/`eval` | `tests/compile.yab`, `tests/eval.yab` |
| c063-libraries | `import`, namespaces, `export`, nested import | `tests/import.yab`, `tests/nested_import.yab` |
| c070-file-io | open/read/write/seek/tell/eof | `tests/io.yab` |
| c071-stdin | reading stdin to EOF | `tests/resources/read_stdin.yab` |
| c072-silent | no banner or warning output | `tests/silent.sh` |
| c073-docu | `doc` and `docu$` | `tests/resources/docu.yab` |
| c074-arguments | `peek("argument")`, program name/path | `tests/interpreter_and_program.yab` |
| c080-system | `system`, `system$` | `tests/system.yab` |
| c081-peek-poke | peeks, `poke`, error code | manual, yab `Version.yab` |
| c082-os-detection | **new**: `haiku`/`renkuos`, `yabos` | — |
| c083-yab-peeks | yab-only peeks (`directory`, `numwindows`, …) | yab `Version.yab`, `AllInOne.yab` |
| c090-errors-explicit | `error` exit status and message | `tests/error/explicit_error.yab` |
| c091-errors-syntax | parse errors are reported | `tests/error/*` |
| c092-long-names | long identifiers, case sensitivity | `tests/long_variable_name.yab` |
| c093-grammar | compile-only corner cases | `tests/grammar.yab` |
| c094-bind-removed | **new**: `bind` fails with a message | — |
| c095-bind-option.sh | **new**: `--bind`/`-bind` rejected | — |
| c096-tty-at-colour.sh | `clear screen`, `at()`, `colour()` under a pty | `tests/print-at.sh` |
| c097-ffi | `foreign_function_call`, buffers | `tests/foreign*.yab` |
| c098-version-help.sh | **new**: renamed banner/help, no `--bind`/`--display` | — |
| c099-docu-option.sh | `--docu` | `tests/docu.sh` |

| GUI test | Covers | Derived from |
| --- | --- | --- |
| g0100-window | open/close, count, geometry, flags | `WindowWorld.yab`, `ButtonWorld.yab` |
| g0101-view-draw | every `draw` primitive, `draw get`, screenshot | `ColorDemo.yab`, `MessageWorld.yab` |
| g0102-canvas-region | `canvas`, `region` | `GUI-World.yab` |
| g0103-fonts | **new**: TrueType families and sizes change metrics | — |
| g0110-buttons | button, checkbox, radio, `option set` | `ButtonWorld.yab`, `Checkbox.yab` |
| g0111-text-controls | `text`, `texturl`, `textcontrol`, `textedit` | `EvenMoreControls.yab`, `AllInOne.yab` |
| g0112-lists | `listbox`, `dropbox` add/get/count/remove/clear | `AllInOne.yab`, `GUI-World.yab` |
| g0113-tree-column | `treebox`, `columnbox` | `AllInOne.yab`, `TreeDemo.yab`, `Filebox.yab` |
| g0114-slider-status | slider, scrollbar, statusbar, spincontrol, stackview | `SliderWorld.yab`, `AllInOne.yab` |
| g0115-views | `tabview`, `boxview`, `splitview`, `stackview` | `AllInOne.yab`, `Loop-World.yab` |
| g0116-calendar-color | `calendar`, `colorcontrol` | `ColorDemo.yab`, `AllInOne.yab` |
| g0117-menus | `menu`, `submenu`, `subsubmenu`, tooltip | `subsubmenu.yab` |
| g0118-clipboard | `clipboard copy`/`paste` | yab grammar |
| g0119-window-lifecycle | repeated open/close, `message$` does not block | `WindowWorld.yab` |
| g0120-bitmap | screenshot, `bitmap get`, `draw bitmap`, `bitmap remove` | `IconWorld.yab`, `FakeTransparency.yab`, `3D-Curve.yab` |
| g0130-yabasic-graphics | yabasic graphic window, primitives, `getbit$`/`putbit`, origin | yabasic manual |
| g0131-yabasic-printer | `open printer "file"`, PostScript output, page break | yabasic manual |

## What was verified in Phase 0, and what was not

* The `cli` suite was written and then run against a stock **yabasic 2.92.1**
  binary. Every test passes; the five `@requires: renkubasic` tests skip. This
  checked the tests, the harness, the runner and the file/stdin/pty handling.
* The `gui` and `manual` suites **could not be run** in the Phase 0 environment:
  it is not Haiku and has no app server, and RenkuBASIC does not exist yet.
  Their syntax was derived line by line from the yab 1.8.3 grammar
  (`yabasic.bison`), its example programs and yabasic 2.92.1's manual, but they
  must be expected to need small corrections when Phase 2 first runs them.
  Treat a GUI test failure as a work item, not as proof that the interpreter is
  wrong.

## Things the tests pinned down about yabasic 2.92.1

These were found while writing the suite and matter for the compatibility layer
(they are also recorded in `docs/platform-inventory.md` and `BUILDING.md`):

* `dec("10")` with one argument reads **hex**, so it returns 16.
* `not(x)` is **logical** (0 or 1); `bitnot(x)` is the bitwise complement, and
  it is 32 bit wide (`bitnot(3)` is 4294967292).
* `chomp$` strips **all** trailing newlines in 2.92.1, although the manual says
  one.
* Variable names are **case sensitive** (`a` and `A` differ); keywords are not.
* `dec`, `numparams`/`numparam` and `docu$` behave as documented, but
  `peek$("directory")`, `window count` and the `b*` file helpers are **yab-only**
  extensions, not yabasic ones.
* The 2.92.1 grammar contains rules for `tokenalt()`, `splitalt()` and
  `arrayerase()` that **no keyword reaches**; they cannot be called (dead
  syntax). `token()` and `split()` are the usable forms.
* `print … using` belongs **after** the value list (`print x using "##.##"`),
  and `print` may end with `;` or `,` but not contain a bare `;` between
  values.
* `right$(a$,n) = s$` with a short `s$` overwrites only `len(s$)` characters and
  leaves the rest of the field, while `left$` truncates to the field length.
