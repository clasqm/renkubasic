#!/bin/bash
#
# RenkuBASIC test runner.
#
# Runs plain BASIC test programs and decides pass/fail from their exit status:
#   0  passed
#   1  failed
#   77 skipped
#
# Tests live in tests/cli (non-interactive), tests/gui (windows, needs an app
# server) and tests/manual (interactive examples, never run by `--suite all`).
#
# A test may declare its needs in its first 40 lines:
#   // @requires: renkubasic        skip when the interpreter is a plain yabasic
#   // @requires: gui               skip when no window can be opened
#   // @requires: pty               skip when script(1) is unavailable
#   // @requires: ffi               skip when foreign_function_call is missing
#   // @requires: haiku             skip unless peek$("os") is haiku/renkuos
#   // @stdin: <file>               feed this file to the program (relative to tests/)
#   // @expect-exit: <n>            expected exit status (default 0)
#   // @expect-stdout-contains: s   stdout must contain s
#   // @expect-stderr-contains: s   stderr must contain s
#   // @expect-empty-output: 1      stdout and stderr must both be empty
#   // @timeout: <seconds>          per-test timeout (default 30)
#   // @skip: <reason>              always skip, with the given reason
#
# Both .yab and .sh tests are supported. Shell tests get the environment
# variables RK_INTERP (the interpreter), RK_TESTS (tests/) and RK_LIB (tests/lib).
#
# Usage:
#   tests/run-tests.sh [options]
#     --interpreter PATH   interpreter to test (default: build/renkubasic,
#                          renkubasic in PATH, then yabasic in PATH)
#     --suite cli|gui|manual|all   default: all (cli + gui)
#     --filter TEXT        only run tests whose file name contains TEXT
#     --list               list the tests that would run
#     --verbose            print test output even for passing tests
#     --stop               stop after the first failure
#     --keep               keep scratch directories
#
# Exit status: 0 when nothing failed, 1 on failure, 2 on usage/setup error.

set -u

HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/.." && pwd)
LIBDIR="$HERE/lib"
SCRATCH="$HERE/.scratch"
SCRATCH_RUN="$SCRATCH/run"

SUITE="all"
FILTER=""
VERBOSE=0
LISTONLY=0
STOP=0
KEEP=0
INTERP=""

usage() {
  sed -n '2,40p' "$0" | sed 's/^# \{0,1\}//'
}

while [ $# -gt 0 ]; do
  case "$1" in
    --interpreter)
      [ $# -ge 2 ] || { echo "--interpreter needs a value" >&2; exit 2; }
      INTERP="$2"; shift 2 ;;
    --interpreter=*) INTERP="${1#*=}"; shift ;;
    --suite)
      [ $# -ge 2 ] || { echo "--suite needs a value" >&2; exit 2; }
      SUITE="$2"; shift 2 ;;
    --suite=*) SUITE="${1#*=}"; shift ;;
    --filter)
      [ $# -ge 2 ] || { echo "--filter needs a value" >&2; exit 2; }
      FILTER="$2"; shift 2 ;;
    --filter=*) FILTER="${1#*=}"; shift ;;
    --verbose|-v) VERBOSE=1; shift ;;
    --list) LISTONLY=1; shift ;;
    --stop) STOP=1; shift ;;
    --keep) KEEP=1; shift ;;
    --help|-h) usage; exit 0 ;;
    *) echo "unknown option: $1" >&2; usage >&2; exit 2 ;;
  esac
done

case "$SUITE" in
  all) SUITE_DIRS="cli gui" ;;
  cli|gui|manual) SUITE_DIRS="$SUITE" ;;
  *) echo "unknown suite '$SUITE' (use cli, gui, manual or all)" >&2; exit 2 ;;
esac

find_interpreter() {
  if [ -n "$INTERP" ]; then
    printf '%s\n' "$INTERP"
    return 0
  fi
  if [ -n "${RENKUBASIC:-}" ]; then
    printf '%s\n' "$RENKUBASIC"
    return 0
  fi
  for candidate in "$ROOT/build/renkubasic" "$ROOT/src/renkubasic" "$ROOT/renkubasic"; do
    if [ -x "$candidate" ]; then
      printf '%s\n' "$candidate"
      return 0
    fi
  done
  if command -v renkubasic >/dev/null 2>&1; then
    command -v renkubasic
    return 0
  fi
  if command -v yabasic >/dev/null 2>&1; then
    command -v yabasic
    return 0
  fi
  return 1
}

INTERP=$(find_interpreter) || {
  echo "error: no interpreter found." >&2
  echo "       build one (build/renkubasic), put renkubasic in PATH, or pass --interpreter PATH." >&2
  exit 2
}

if [ ! -x "$INTERP" ]; then
  echo "error: interpreter '$INTERP' is not executable" >&2
  exit 2
fi

# Make the interpreter path absolute. Each test runs inside its own scratch
# directory, so a relative --interpreter (build/renkubasic) would otherwise
# stop resolving once the runner changes directory.
case "$INTERP" in
  /*) : ;;
  */*)
    absdir=$(cd "$(dirname "$INTERP")" 2>/dev/null && pwd) || {
      echo "error: cannot resolve the interpreter path '$INTERP'" >&2
      exit 2
    }
    INTERP="$absdir/$(basename "$INTERP")"
    ;;
  *)
    resolved=$(command -v "$INTERP") || {
      echo "error: cannot resolve the interpreter '$INTERP'" >&2
      exit 2
    }
    INTERP="$resolved"
    ;;
esac

# Environment for shell tests.
export RK_INTERP="$INTERP"
export RK_TESTS="$HERE"
export RK_LIB="$LIBDIR"
export RK_ROOT="$ROOT"

# --- interpreter capabilities ----------------------------------------------

OSNAME=$("$INTERP" -e 'print peek$("os")' 2>/dev/null | tr -d '\r\n')
if [ -z "$OSNAME" ]; then
  OSNAME=$("$INTERP" -e 'print peek$("os");' 2>/dev/null | tr -d '\r\n')
fi
[ -n "$OSNAME" ] || OSNAME="unknown"

case "$OSNAME" in
  haiku|renkuos) IS_RENKU=1 ;;
  *) IS_RENKU=0 ;;
esac

HAS_PTY=0
if command -v script >/dev/null 2>&1; then
  HAS_PTY=1
fi

mkdir -p "$SCRATCH" "$SCRATCH_RUN"

# A capability probe is a tiny program that opens and closes a window. It runs
# with RK_GUI_TRACE=1, so a backend that stalls names the call it stopped in,
# and under a watchdog, so a stalled probe cannot hang the whole run. When a
# probe fails its log is printed: a skip with no reason is not diagnosable.
PROBE_TIMEOUT=20
run_probe() {  # probe-file log-file
  local probe="$1"
  local log="$2"
  local pid watchdog status
  ( cd "$SCRATCH_RUN" && RK_GUI_TRACE=1 exec "$INTERP" "$probe" ) \
    >"$log" 2>&1 &
  pid=$!
  ( sleep "$PROBE_TIMEOUT"; kill -9 "$pid" 2>/dev/null ) >/dev/null 2>&1 &
  watchdog=$!
  wait "$pid"
  status=$?
  kill "$watchdog" 2>/dev/null
  wait "$watchdog" 2>/dev/null
  return $status
}

probe_note() {  # label log-file
  echo "note: the $1 probe failed, so its tests skip. Probe output:"
  if [ -s "$2" ]; then
    tail -n 12 "$2" | sed 's/^/    /'
  else
    echo "    (empty)"
  fi
}

GUI_OK=0
probe_gui() {
  local probe="$SCRATCH/gui-probe.yab"
  cat > "$probe" <<'PROBE'
window open 20, 20 to 90, 90, "rkprobe", "RenkuBASIC probe"
window close "rkprobe"
exit 0
PROBE
  run_probe "$probe" "$SCRATCH/gui-probe.log"
}
if [ "$IS_RENKU" = "1" ]; then
  if probe_gui; then GUI_OK=1; else probe_note gui "$SCRATCH/gui-probe.log"; fi
else
  # A plain yabasic cannot run the yab window commands, so the GUI suite is
  # meaningless. Do not spend a window on it.
  GUI_OK=0
fi

# The yabasic graphic window is a separate capability from yab's widget
# windows: it can exist before the compatibility layer does.
GRAPHICS_OK=0
probe_graphics() {
  local probe="$SCRATCH/graphics-probe.yab"
  cat > "$probe" <<'PROBE'
open window 20, 20
close window
exit 0
PROBE
  run_probe "$probe" "$SCRATCH/graphics-probe.log"
}
if [ "$IS_RENKU" = "1" ]; then
  case " $SUITE_DIRS " in
    *" gui "*)
      if probe_graphics; then
        GRAPHICS_OK=1
      else
        probe_note graphics "$SCRATCH/graphics-probe.log"
      fi
      ;;
  esac
fi

# --- helpers ---------------------------------------------------------------

matches_filter() {
  [ -z "$FILTER" ] && return 0
  case "$1" in
    *"$FILTER"*) return 0 ;;
    *) return 1 ;;
  esac
}

# directive FILE KEY  -> value of the first "// @KEY: value" (or "# @KEY: value") line
directive() {
  sed -n '1,40p' "$1" 2>/dev/null \
    | sed -n "s|^// @$2[[:space:]]*:[[:space:]]*||p;s|^# @$2[[:space:]]*:[[:space:]]*||p" \
    | head -1
}

requirement_met() {
  case "$1" in
    renkubasic) [ "$IS_RENKU" = "1" ] ;;
    gui) [ "$GUI_OK" = "1" ] ;;
    graphics) [ "$GRAPHICS_OK" = "1" ] ;;
    pty) [ "$HAS_PTY" = "1" ] ;;
    haiku) case "$OSNAME" in haiku|renkuos) return 0 ;; *) return 1 ;; esac ;;
    ffi)
      "$INTERP" -e 'x = foreign_function_size("int")' >/dev/null 2>&1
      ;;
    *) return 0 ;;
  esac
}

show_output() {
  local out="$1" err="$2" limit="$3"
  if [ -s "$out" ]; then
    echo "    --- stdout (last $limit lines) ---"
    tail -n "$limit" "$out" | sed 's/^/    /'
  fi
  if [ -s "$err" ]; then
    echo "    --- stderr (last $limit lines) ---"
    tail -n "$limit" "$err" | sed 's/^/    /'
  fi
}

PASS=0
FAIL=0
SKIP=0
TIMEOUT=0
FAILED_NAMES=""

declare -a FILES
for dir in $SUITE_DIRS; do
  [ -d "$HERE/$dir" ] || continue
  for f in "$HERE/$dir"/*.yab "$HERE/$dir"/*.sh; do
    [ -e "$f" ] || continue
    matches_filter "$(basename "$f")" && FILES+=("$f")
  done
done

if [ ${#FILES[@]} -eq 0 ]; then
  echo "error: no tests found (suite=$SUITE filter='$FILTER')" >&2
  exit 2
fi

echo "RenkuBASIC test runner"
echo "  interpreter : $INTERP"
echo "  os          : $OSNAME"
echo "  suites      : $SUITE_DIRS"
echo "  gui         : $([ "$GUI_OK" = "1" ] && echo available || echo unavailable)"
echo "  graphics    : $([ "$GRAPHICS_OK" = "1" ] && echo available || echo unavailable)"
echo "  pty         : $([ "$HAS_PTY" = "1" ] && echo available || echo unavailable)"
echo

for f in "${FILES[@]}"; do
  name=$(basename "$f" .yab)

  if [ "$LISTONLY" = "1" ]; then
    echo "$f"
    continue
  fi

  skip_reason=$(directive "$f" "skip")
  if [ -n "$skip_reason" ]; then
    echo "SKIP  $name  ($skip_reason)"
    SKIP=$((SKIP + 1))
    continue
  fi

  unmet=""
  requires=$(directive "$f" "requires")
  if [ -n "$requires" ]; then
    old_ifs=$IFS
    IFS=','
    for req in $requires; do
      IFS=$old_ifs
      req=$(printf '%s' "$req" | tr -d ' ')
      [ -z "$req" ] && continue
      if ! requirement_met "$req"; then
        unmet="$req"
        break
      fi
    done
    IFS=$old_ifs
  fi
  if [ -n "$unmet" ]; then
    if [ "$unmet" = "renkubasic" ]; then
      echo "SKIP  $name  (needs RenkuBASIC, this is a plain yabasic baseline)"
    else
      echo "SKIP  $name  (requires $unmet)"
    fi
    SKIP=$((SKIP + 1))
    continue
  fi

  expect_exit=$(directive "$f" "expect-exit")
  [ -n "$expect_exit" ] || expect_exit=0
  tmo=$(directive "$f" "timeout")
  [ -n "$tmo" ] || tmo=30

  stdin_file=$(directive "$f" "stdin")
  if [ -n "$stdin_file" ]; then
    case "$stdin_file" in
      /*) : ;;
      *) stdin_file="$HERE/$stdin_file" ;;
    esac
    if [ ! -r "$stdin_file" ]; then
      echo "FAIL  $name  (stdin file '$stdin_file' is not readable)"
      FAIL=$((FAIL + 1))
      FAILED_NAMES="$FAILED_NAMES $name"
      continue
    fi
  fi

  rundir="$SCRATCH_RUN/$name"
  rm -rf "$rundir"
  mkdir -p "$rundir"
  out="$SCRATCH/$name.out"
  err="$SCRATCH/$name.err"
  : > "$out"
  : > "$err"

  case "$f" in
    *.sh)
      if [ -n "$stdin_file" ]; then
        ( cd "$rundir" && exec /bin/bash "$f" ) \
          <"$stdin_file" >"$out" 2>"$err" &
      else
        ( cd "$rundir" && exec /bin/bash "$f" ) \
          </dev/null >"$out" 2>"$err" &
      fi
      ;;
    *)
      if [ -n "$stdin_file" ]; then
        ( cd "$rundir" && exec "$INTERP" --librarypath "$LIBDIR" "$f" ) \
          <"$stdin_file" >"$out" 2>"$err" &
      else
        ( cd "$rundir" && exec "$INTERP" --librarypath "$LIBDIR" "$f" ) \
          </dev/null >"$out" 2>"$err" &
      fi
      ;;
  esac
  pid=$!

  ( sleep "$tmo"; kill -9 "$pid" 2>/dev/null ) >/dev/null 2>&1 &
  watchdog=$!

  wait "$pid"
  status=$?
  kill "$watchdog" 2>/dev/null
  wait "$watchdog" 2>/dev/null

  # 137 is 128+SIGKILL. Haiku's bash reports 149 here instead: a process id is
  # a thread id there, so the watchdog's kill -9 arrives as SIGKILLTHR (21).
  if [ "$status" = "137" ] || [ "$status" = "149" ]; then
    echo "FAIL  $name  (timeout after ${tmo}s)"
    show_output "$out" "$err" 15
    FAIL=$((FAIL + 1))
    TIMEOUT=$((TIMEOUT + 1))
    FAILED_NAMES="$FAILED_NAMES $name"
    [ "$STOP" = "1" ] && break
    continue
  fi

  if [ "$status" = "77" ]; then
    reason=$(grep -m1 'SKIP:' "$out" 2>/dev/null | sed 's/^ *SKIP: *//')
    [ -n "$reason" ] || reason="skipped by the test"
    echo "SKIP  $name  ($reason)"
    SKIP=$((SKIP + 1))
    continue
  fi

  want_stdout=$(directive "$f" "expect-stdout-contains")
  want_stderr=$(directive "$f" "expect-stderr-contains")
  want_empty=$(directive "$f" "expect-empty-output")
  content_ok=1
  content_why=""
  if [ -n "$want_stdout" ] && ! grep -qF -- "$want_stdout" "$out" 2>/dev/null; then
    content_ok=0
    content_why="stdout does not contain '$want_stdout'"
  fi
  if [ -n "$want_stderr" ] && ! grep -qF -- "$want_stderr" "$err" 2>/dev/null; then
    content_ok=0
    content_why="stderr does not contain '$want_stderr'"
  fi
  if [ "$want_empty" = "1" ] && { [ -s "$out" ] || [ -s "$err" ]; }; then
    content_ok=0
    content_why="expected no output"
  fi

  if [ "$status" = "$expect_exit" ] && [ "$content_ok" = "1" ]; then
    if [ "$VERBOSE" = "1" ]; then
      echo "PASS  $name"
      show_output "$out" "$err" 10
    else
      echo "PASS  $name"
    fi
    PASS=$((PASS + 1))
  else
    if [ "$content_ok" != "1" ] && [ "$status" = "$expect_exit" ]; then
      echo "FAIL  $name  ($content_why)"
      show_output "$out" "$err" 20
      FAIL=$((FAIL + 1))
      FAILED_NAMES="$FAILED_NAMES $name"
      [ "$STOP" = "1" ] && break
      continue
    fi
    if [ "$expect_exit" = "0" ]; then
      echo "FAIL  $name  (exit $status)"
    else
      echo "FAIL  $name  (exit $status, expected $expect_exit)"
    fi
    show_output "$out" "$err" 20
    FAIL=$((FAIL + 1))
    FAILED_NAMES="$FAILED_NAMES $name"
    [ "$STOP" = "1" ] && break
  fi
done

if [ "$LISTONLY" = "1" ]; then
  exit 0
fi

echo
echo "Summary: $PASS passed, $FAIL failed, $SKIP skipped"
if [ "$FAIL" -gt 0 ]; then
  echo "Failed tests:$FAILED_NAMES"
  echo "Scratch output: $SCRATCH"
  exit 1
fi

if [ "$KEEP" != "1" ]; then
  rm -rf "$SCRATCH_RUN"
fi

exit 0
