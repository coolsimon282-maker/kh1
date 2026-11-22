#!/bin/bash
# Assembler wrapper for decomp-permuter's import.py: INPUT -o OUTPUT, assembled like the build's "as" rule.
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
"$ROOT/tools/cc/ee-gcc2.96/ee/bin/as" -O2 -G0 -EL -mabi=eabi -I"$ROOT/include/ee-as" -I"$ROOT/include" -I"$ROOT" "$1" -o "$3"
