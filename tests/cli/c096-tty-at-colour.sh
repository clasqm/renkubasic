#!/bin/bash
# RenkuBASIC CLI test: terminal control (clear screen, at(), colour())
# @requires: pty
#
# These commands need a real terminal, so the test runs the program under
# script(1), which allocates a pseudo terminal. Without script(1) the runner
# skips this test (see @requires above).

set -u

# script(1) runs the program on a pseudo terminal; ncurses needs a known TERM.
case "${TERM:-}" in
  ""|dumb|unknown) export TERM=xterm-256color ;;
esac

tmp=$(mktemp -d 2>/dev/null) || tmp="./c096-tmp"
mkdir -p "$tmp"
trap 'rm -rf "$tmp"' EXIT

cat > "$tmp/tty.yab" <<'EOF'
clear screen
print at(2, 1) "TTY-MARKER"
print colour("red", "blue") "COLOUR-MARKER"
EOF

# yabasic asks for RETURN when a program ends on a terminal, so feed one.
if script -q -e -c "exit 0" /dev/null >/dev/null 2>&1; then
  printf '\n' | script -q -e -c "'$RK_INTERP' '$tmp/tty.yab'" /dev/null >"$tmp/out" 2>&1
  status=$?
else
  # BSD script: command and arguments after the typescript file.
  printf '\n' | script -q /dev/null "$RK_INTERP" "$tmp/tty.yab" >"$tmp/out" 2>&1
  status=$?
fi

if [ "$status" != 0 ]; then
  echo "FAIL: program exited with $status"
  cat "$tmp/out"
  exit 1
fi

missing=""
grep -q -- 'TTY-MARKER' "$tmp/out" || missing="$missing TTY-MARKER"
grep -q -- 'COLOUR-MARKER' "$tmp/out" || missing="$missing COLOUR-MARKER"

if [ -n "$missing" ]; then
  echo "FAIL: output is missing:$missing"
  echo "--- output start ---"
  cat -v "$tmp/out"
  echo "--- output end ---"
  exit 1
fi

# at() must emit a cursor movement before the marker, not just print it.
if ! tr -d '\r' < "$tmp/out" | grep -q '\[2d *TTY-MARKER'; then
  echo "FAIL: at(2,1) did not emit a cursor movement before the marker"
  cat -v "$tmp/out" | head -20
  exit 1
fi

echo "terminal control works"
exit 0
