#!/bin/bash
# RenkuBASIC CLI test: version and help text are renamed and bind-free
# @requires: renkubasic
#
# Guards the Phase 1 renaming work: the banner must say RenkuBASIC, the help
# must not advertise the removed --bind option, and the version must still
# mention the yabasic language level for compatibility.

set -u

version=$("$RK_INTERP" --version 2>&1)
case "$version" in
  *RenkuBASIC*) : ;;
  *) echo "FAIL: --version does not mention RenkuBASIC: $version"; exit 1 ;;
esac
case "$version" in
  *2.92.1*) : ;;
  *) echo "FAIL: --version does not mention the language level 2.92.1: $version"; exit 1 ;;
esac

help=$("$RK_INTERP" --help 2>&1)
case "$help" in
  *RenkuBASIC*) : ;;
  *) echo "FAIL: --help does not mention RenkuBASIC"; exit 1 ;;
esac
if printf '%s' "$help" | grep -q -- '--bind'; then
  echo "FAIL: --help still advertises --bind"
  exit 1
fi
if printf '%s' "$help" | grep -qi -- 'display DISP'; then
  echo "FAIL: --help still advertises --display (X11 is gone)"
  exit 1
fi

# An empty program must not print a banner.
empty="$RK_TESTS/.scratch/c098-empty.yab"
: > "$empty"
out=$("$RK_INTERP" "$empty" 2>&1)
if [ -n "$out" ]; then
  echo "FAIL: empty program produced output: $out"
  exit 1
fi

echo "version/help text is correct"
exit 0
