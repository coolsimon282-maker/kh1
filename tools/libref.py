#!/usr/bin/env python3
"""Print a library function's source from the reference library sources, if they have it:
    python3 tools/libref.py <function> [max lines=90]
The references live outside the repo in kh1-study/libref/kfiv-sce (Sony SDK, newlib and libgcc files from the ICO and
King's Field IV matching decompiles, MIT licensed: see the LICENSE files there). They were built with SDK 2.2.x; Final
Mix links a newer SDK, so a function may differ a little. Their static data has real names: in this project the
same data is still in the data segments under D_xxxxxxxx names (see the function's assembly), so declare it extern."""
import glob, os, re, sys
fn = sys.argv[1]; limit = int(sys.argv[2]) if len(sys.argv) > 2 else 90
root = next((d for d in ('../libref/kfiv-sce', '../../libref/kfiv-sce') if os.path.isdir(d)), None)
if not root: sys.exit(0)
pat = re.compile(r'^(?![ \t#/])[A-Za-z_][^;{}()\n]*\b%s[ \t]*\([^;{}]*\)\s*\{' % re.escape(fn), re.M)
for p in sorted(glob.glob(root + '/**/*.c', recursive=True)):
    s = open(p, encoding='utf-8', errors='replace').read()
    m = pat.search(s)
    if not m: continue
    end = s.find('\n}', m.end())
    body = s[m.start():end + 2 if end >= 0 else len(s)].splitlines()
    rel = os.path.relpath(p, os.path.dirname(root)).replace(os.sep, '/')
    print('== REFERENCE SOURCE for %s: libref/%s (the same library function matched for another PS2 game) ==' % (fn, rel))
    print('\n'.join(body[:limit]) + ('\n... (%d more lines: read the file)' % (len(body) - limit) if len(body) > limit else ''))
    print('== use it as the starting point: same logic; types/structs it uses are defined higher up in that file or in its')
    print('   headers (copy what you need into your work file); its named static data = the D_ symbols in the assembly ==')
    sys.exit(0)
print('== no reference source found for %s in libref ==' % fn)
