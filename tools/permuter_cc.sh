#!/bin/bash
# Compiler wrapper for decomp-permuter: the game's real pipeline (ee-gcc 2.96 -> masps2 -> ee as) for one C file.
#   permuter_cc.sh [--g=-g|--g=] [--cf=<extra cflags>] <cpp flags...> INPUT -o OUTPUT
# Run from the repo root (the build mirror). Flags per file come from configure.py (NO_G_FILES, STRICT_ALIASING_FILES).
G="-g"; CF="-fno-strict-aliasing"; ARGS=()
for a in "$@"; do
  case "$a" in
    --g=*) G="${a#--g=}" ;;
    --cf=*) CF="${a#--cf=}" ;;
    *) ARGS+=("$a") ;;
  esac
done
n=${#ARGS[@]}; OUT="${ARGS[$((n-1))]}"; IN="${ARGS[$((n-3))]}"; FLAGS=("${ARGS[@]:0:$((n-3))}")
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; CC="$ROOT/tools/cc/ee-gcc2.96"
set -o pipefail
"$CC/bin/ee-gcc" -c -B "$CC/bin/ee-" "${FLAGS[@]}" -O2 -G0 $G $CF "$IN" -S -o - 2>/dev/null \
  | MASPS2_NO_NOPS=1 python3 "$ROOT/tools/masps2.py" > "$OUT.s" && "$CC/ee/bin/as" -O2 -G0 $G -EL -mabi=eabi "$OUT.s" -o "$OUT"
s=$?; rm -f "$OUT.s"; exit $s
