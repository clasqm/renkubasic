#!/bin/bash
# RenkuBASIC CLI test: the --bind command line option is gone
# @requires: renkubasic
#
# The interpreter must reject --bind (and -bind) instead of writing a file.

set -u

tmp=$(mktemp -d 2>/dev/null) || tmp="./c095-tmp"
mkdir -p "$tmp"
trap 'rm -rf "$tmp"' EXIT

cat > "$tmp/prog.yab" <<'EOF'
print "hello"
EOF

status=0
out=$("$RK_INTERP" --bind "$tmp/bound" "$tmp/prog.yab" 2>&1) || status=$?

if [ "$status" = 0 ]; then
  echo "FAIL: --bind succeeded (exit 0)"
  echo "$out"
  exit 1
fi

if [ -e "$tmp/bound" ]; then
  echo "FAIL: --bind created a file although it failed"
  exit 1
fi

case "$out" in
  *bind*|*Bind*|*BIND*) : ;;
  *)
    echo "FAIL: error message does not mention bind:"
    echo "$out"
    exit 1
    ;;
esac

# The short form must be rejected as well.
status=0
"$RK_INTERP" -bind "$tmp/bound2" "$tmp/prog.yab" >/dev/null 2>&1 || status=$?
if [ "$status" = 0 ] || [ -e "$tmp/bound2" ]; then
  echo "FAIL: -bind was accepted"
  exit 1
fi

echo "bind option rejected: $out"
exit 0
