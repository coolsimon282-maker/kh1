#!/usr/bin/env python3
"""Collect near-miss C for still-unmatched functions from scratch folders into ~/perm-queue (run in the build mirror):
    python3 tools/perm_seed.py <scratch dir> [<scratch dir> ...]
A candidate = a .c/.txt file that defines an unmatched function; it's kept if it compiles in place of the function's
INCLUDE_ASM line and differs in at most 40 instructions (tools/quickcmp.py). Best candidate per function wins."""
import glob, os, re, shutil, subprocess, sys
Q = os.path.expanduser('~/perm-queue'); os.makedirs(Q, exist_ok=True)
un = {}
for c in glob.glob('src/**/*.c', recursive=True):
    f = c[4:-2]
    if f.startswith('lib/') or f.endswith('__perm'): continue
    for fn in re.findall(r'^INCLUDE_ASM\("[^"]+",\s*(\w+)\);', open(c, encoding='utf-8', errors='replace').read(), re.M):
        if os.path.exists('asm/nonmatchings/%s/%s.s' % (f, fn)): un[fn] = f
best = {}
files = [p for d in sys.argv[1:] for p in glob.glob(d + '/**/*', recursive=True)
         if p.endswith(('.c', '.txt')) and os.path.isfile(p) and os.path.getsize(p) < 30000]
print(len(un), 'unmatched functions;', len(files), 'scratch files')
for p in files:
    t = open(p, encoding='utf-8', errors='replace').read().replace('\r\n', '\n')
    names = set(re.findall(r'^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\([^;{}]*\)\s*\{', t, re.M)) & set(un)
    if len(names) != 1: continue
    fn = names.pop(); f = un[fn]; src = 'src/%s.c' % f
    orig = open(src, encoding='utf-8').read()
    pat = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*%s\);$' % re.escape(fn), re.M)
    if len(pat.findall(orig)) != 1: continue
    try:
        open(src, 'w', newline='\n').write(pat.sub(lambda m: t, orig, count=1))
        r = subprocess.run(['python3', 'tools/quickcmp.py', f, fn, '1'], capture_output=True, text=True)
    finally:
        open(src, 'w', newline='\n').write(orig)
    m = re.search(r'differs in (\d+) of (\d+)', r.stdout)
    if r.returncode == 1 and m and int(m.group(1)) <= 40 and (fn not in best or int(m.group(1)) < best[fn][0]):
        best[fn] = (int(m.group(1)), f, p)
    elif r.returncode == 0:
        best[fn] = (0, f, p)
rows = sorted((d, fn, f, p) for fn, (d, f, p) in best.items())
with open(Q + '/queue.tsv', 'w') as o:
    for d, fn, f, p in rows:
        shutil.copy(p, '%s/%s.c' % (Q, fn)); o.write('%d\t%s\t%s\n' % (d, fn, f))
print(len(rows), 'candidates queued in', Q); print('\n'.join('%3d  %s (%s)' % r[:3] for r in rows[:60]))
