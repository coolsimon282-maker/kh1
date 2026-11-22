#!/bin/bash
# Run decomp-permuter on one near-miss function. From the repo root, in WSL (through wsl-build.sh):
#   bash wsl-build.sh bash tools/permute.sh <file e.g. xpotato> <func> <cfile with the closest C> [seconds=600] [jobs=12]
# <cfile>: what `agent-tools.sh put` takes (the function plus any declarations it needs).
# Prints the best score every few seconds; score 0 = a match, saved under ~/decomp-permuter/nonmatchings/<func>/.
set -e
FILE="$1"; FN="$2"; CF="$3"; SECS="${4:-600}"; JOBS="${5:-12}"
P=~/decomp-permuter; ROOT="$(pwd)"
[ -d "$P" ] || git clone -q --depth 1 https://github.com/simonlindholm/decomp-permuter.git "$P"
python3 -c "import pycparser, toml, Levenshtein" 2>/dev/null || pip install -q pycparser toml Levenshtein
python3 - "$FILE" "$FN" "$CF" <<'PY'
import re, sys
f, fn, cf = sys.argv[1:4]
s = open('src/%s.c' % f, encoding='utf-8').read(); c = open(cf, encoding='utf-8').read().replace('\r\n', '\n')
pat = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*%s\);$' % re.escape(fn), re.M)
assert len(pat.findall(s)) == 1, 'need exactly one INCLUDE_ASM line for %s in src/%s.c' % (fn, f)
open('src/%s__perm.c' % f, 'w', newline='\n').write(pat.sub(lambda m: c, s, count=1))
conf = open('configure.py').read()
def lst(name):
    m = re.search(name + r'\s*=\s*\[(.*?)\]', conf, re.S); return re.findall(r'"([^"]+)"', m.group(1)) if m else []
base = f.split('/')[-1] + '.c'
g = '' if base in lst('NO_G_FILES') else '-g'
cfl = '' if base in lst('STRICT_ALIASING_FILES') else '-fno-strict-aliasing'
open('permuter_settings.toml', 'w').write(
    'compiler_command = "bash tools/permuter_cc.sh --g=%s --cf=%s -Iinclude -isystem include/sdk/ee -isystem include/gcc -DVERSION_FM -DPERMUTER"\n'
    'assembler_command = "bash tools/permuter_as.sh"\nasm_prelude_file = "tools/permuter_prelude.inc"\ncompiler_type = "gcc"\n'
    'objdump_command = "mips-linux-gnu-objdump -drz -m mips:5900"\n' % (g, cfl))
print('flags: g=%r cflags=%r' % (g, cfl))
PY
rm -rf "$P/nonmatchings/$FN"
(cd "$P" && python3 import.py "$ROOT/src/${FILE}__perm.c" "$ROOT/asm/nonmatchings/$FILE/$FN.s" 2>&1 | tail -4)
rm -f "src/${FILE}__perm.c"
cd "$P" && timeout "$SECS" python3 permuter.py "nonmatchings/$FN" -j "$JOBS" --stop-on-zero --best-only 2>&1 | grep -vE "^\s*$" | tail -${PERM_TAIL:-12}
ls "nonmatchings/$FN" | grep -E "^output" | head -5
