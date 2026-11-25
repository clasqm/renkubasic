#!/bin/bash
# RenkuBASIC CLI test: the --docu command line option
# Derived from: yabasic 2.92.1 tests/docu.sh

set -u

tmp=$(mktemp -d 2>/dev/null) || tmp="./c099-tmp"
mkdir -p "$tmp"
trap 'rm -rf "$tmp"' EXIT

cat > "$tmp/docu.yab" <<'EOF'
doc one
doc two
print "program output"
EOF

out=$("$RK_INTERP" --docu "$tmp/docu.yab" 2>&1)
status=$?

if [ "$status" != 0 ]; then
  echo "FAIL: --docu exited with $status"
  echo "$out"
  exit 1
fi

case "$out" in
  *one*) : ;;
  *) echo "FAIL: --docu did not print the documentation: $out"; exit 1 ;;
esac
case "$out" in
  *two*) : ;;
  *) echo "FAIL: --docu did not print the second line: $out"; exit 1 ;;
esac

# --docu must print the documentation only, not run the program.
case "$out" in
  *"program output"*)
    echo "FAIL: --docu executed the program"
    exit 1
    ;;
esac

echo "docu option works"
exit 0
