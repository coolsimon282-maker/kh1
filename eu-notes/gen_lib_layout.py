"""Turn the Final Mix library segments that are still whole assembly files into C files with one INCLUDE_ASM per
function, so workers can match library functions one at a time like game functions (23 Nov).

Run from the repo root on Windows, after a build (it reads the asm/<segment>.s files splat generated):
    python eu-notes/gen_lib_layout.py [--only lib/libkernl/sifrpc,...] [--skip a,b]

For each `[ 0x..., asm, lib/... ]` line of config/kh.fm.yaml it writes src/<segment>.c and changes the line to `c`.
A source file that already exists (matched for the Japanese version) is kept for that version and gets the
INCLUDE_ASM list under #ifdef VERSION_FM. Segments that are assembly in the original stay as they are (SKIP)."""
import os, re, sys

SKIP = {'lib/libkernl/klib'}          # system-call stubs: hand-written assembly in Sony's library, not C
def arg(flag):
    return set(sys.argv[sys.argv.index(flag) + 1].split(',')) if flag in sys.argv else set()
only, SKIP = arg('--only'), SKIP | arg('--skip')

yaml_path = 'config/kh.fm.yaml'
y = open(yaml_path, encoding='utf-8').read()
done = []
for m in list(re.finditer(r'^(\s*-\s*\[\s*0x[0-9a-fA-F]+\s*,\s*)asm(\s*,\s*(lib/[^\s\],]+)\s*\])', y, re.M)):
    seg = m.group(3)
    if seg in SKIP or (only and seg not in only): continue
    asm = 'asm/%s.s' % seg
    if not os.path.exists(asm):
        print('no asm file, skipped:', seg); continue
    funcs = re.findall(r'^nonmatching (\w+), 0x[0-9A-Fa-f]+', open(asm, encoding='utf-8', errors='replace').read(), re.M)
    if not funcs:
        print('no functions found, skipped:', seg); continue
    inc = ''.join('INCLUDE_ASM("asm/nonmatchings/%s", %s);\n\n' % (seg, f) for f in funcs).rstrip('\n') + '\n'
    out = 'src/%s.c' % seg
    # newlib's files are compiled with newlib's own headers only: reach the INCLUDE_ASM macro by path
    head = '#include "../../../include/include_asm.h"' if seg.startswith(('lib/libc/', 'lib/libm/')) else '#include "common.h"'
    if os.path.exists(out):
        old = open(out, encoding='utf-8').read()
        if 'VERSION_FM' in old:
            print('already has a Final Mix part, skipped:', out); continue
        new = ('#ifdef VERSION_FM\n// Final Mix links a newer build of this library file: its functions are matched one by one below.\n'
               '#include "common.h"\n\n' + inc + '\n#else\n' + old.rstrip('\n') + '\n#endif\n')
    else:
        new = ('// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.\n'
               '// Data this file owns is still in the data segments: declare it extern here, do not define it.\n'
               '#include "common.h"\n\n' + inc)
    os.makedirs(os.path.dirname(out), exist_ok=True)
    open(out, 'w', encoding='utf-8', newline='\n').write(new)
    y = y.replace(m.group(0), m.group(1) + 'c' + m.group(2), 1)
    done.append((seg, len(funcs)))
open(yaml_path, 'w', encoding='utf-8', newline='\n').write(y)
print('%d segments converted, %d functions' % (len(done), sum(n for _, n in done)))
for seg, n in done: print('  %-34s %3d' % (seg, n))
