#!/usr/bin/env python3
"""Does the build mirror lack an assembly file that a C file still includes?  (run from the mirror's root)

    python3 tools/missing_asm.py check      prints RESPLIT when a re-split is needed, nothing otherwise
    python3 tools/missing_asm.py baseline   run right after a re-split: remembers what is missing anyway

Why (23 Nov): the splitter writes asm/nonmatchings/<file>/<func>.s only for functions that are INCLUDE_ASM lines
at the moment it runs. If it runs while a function is replaced by a worker's C attempt, and the attempt is then
given up (the INCLUDE_ASM line comes back), that function's .s file does not exist and EVERY build fails with
"Can't open asm/nonmatchings/...". The build tool calls `check` first and re-splits when that has happened.
Files that are missing even straight after a re-split (lines that belong to another game version) are remembered
by `baseline` and ignored, so they cannot cause a re-split on every build."""
import glob, os, re, sys
BASE = '.asm_missing_baseline'
missing = set()
for p in glob.glob('src/**/*.c', recursive=True):
    for d, fn in re.findall(r'^INCLUDE_ASM\("([^"]+)",\s*(\w+)\);', open(p, encoding='utf-8', errors='replace').read(), re.M):
        if not os.path.exists(os.path.join(d, fn + '.s')): missing.add('%s/%s' % (d, fn))
if sys.argv[1:] == ['baseline']:
    open(BASE, 'w').write('\n'.join(sorted(missing)) + '\n')
else:
    known = set(open(BASE).read().split()) if os.path.exists(BASE) else None
    # no baseline yet (first run after this tool arrived): only library files are new enough to be affected
    new = missing - known if known is not None else {m for m in missing if '/lib/' in m}
    if new: print('RESPLIT', ' '.join(sorted(new)[:5]))
