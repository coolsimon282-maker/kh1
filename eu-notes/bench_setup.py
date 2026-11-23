"""Model benchmark for matching: hide 20 functions the Claude agents matched and queue them for a local/rented model.
Run from a checkout that is at fm (the bench worktree), on Windows:   python eu-notes/bench_setup.py
It replaces each chosen function's C with its INCLUDE_ASM line again, and writes qwen/queue.txt (the same job format
the Qwen loop uses), so `agent-tools.sh next` / `try` / `giveup` drive the test. Score = how many get re-matched.
Functions: from src/unsplit files (not Qwen's), plain definitions, 7 of 64-128 bytes, 7 of 129-256, 6 of 257-512."""
import os, re, struct, subprocess, sys, random, collections
sys.path.insert(0, os.path.dirname(__file__))
import elf_funcs
from elf_funcs import elf_functions
names = elf_functions(os.path.join(elf_funcs.WSL_HOME, 'kh1-decomp-build', 'build', 'fm', 'SLPS_251.98.elf'))
starts = sorted(v for v, n in names.items() if 0x100000 <= v < 0x272c70 and any(x.startswith(('func_', 'fm_func_')) and not x.endswith('.NON_MATCHING') for x in n))
size = {}
for a, b in zip(starts, starts[1:]):
    for x in names[a]:
        if x.startswith(('func_', 'fm_func_')) and not x.endswith('.NON_MATCHING'): size[x] = b - a
log = subprocess.run(['git', 'log', '--format=%s', '5000bb5..HEAD'], capture_output=True, text=True).stdout
cands = []
for s in log.splitlines():
    m = re.match(r'^Match (.+) \((unsplit/seg_\w+)\)$', s)
    if not m or m.group(2) == 'unsplit/seg_132D60': continue
    for fn in [x.strip() for x in m.group(1).split(',')]:
        if fn in size: cands.append((fn, m.group(2)))
random.seed(20261123); random.shuffle(cands)
want = {(64, 128): 7, (129, 256): 7, (257, 512): 6}; picked = []; src = {}
def span(text, fn):
    ms = list(re.finditer(r'^[A-Za-z_][^;{}\n#]*\b%s\s*\([^;{}]*\)\s*\{' % re.escape(fn), text, re.M))
    if len(ms) != 1: return None
    i = text.index('{', ms[0].start()); d = 0
    for j in range(i, len(text)):
        d += {'{': 1, '}': -1}.get(text[j], 0)
        if d == 0: return ms[0].start(), j + 1
for fn, f in cands:
    z = size[fn]; k = next((k for k in want if k[0] <= z <= k[1] and want[k] > 0), None)
    if not k or fn in [p[0] for p in picked]: continue
    t = src.setdefault(f, open('src/%s.c' % f, encoding='utf-8').read())
    sp = span(t, fn)
    if not sp or re.search(r'__asm__|register .* asm\(', t[sp[0]:sp[1]]): continue
    src[f] = t[:sp[0]] + 'INCLUDE_ASM("asm/nonmatchings/%s", %s);' % (f, fn) + t[sp[1]:]
    picked.append((fn, f, z)); want[k] -= 1
    if not any(want.values()): break
for f, t in src.items(): open('src/%s.c' % f, 'w', encoding='utf-8', newline='\n').write(t)
os.makedirs('qwen', exist_ok=True); os.makedirs('notes', exist_ok=True)
open('qwen/queue.txt', 'w', newline='\n').write('# Benchmark queue: 20 functions the Claude agents matched, hidden again.\n' + ''.join('%4d  %-16s %s\n' % (z, fn, f) for fn, f, z in sorted(picked, key=lambda p: p[2])))
open('qwen/twins.txt', 'w', newline='\n').write('# (none)\n'); open('qwen/work.c', 'w').write('')
open('notes/%s.md' % os.path.basename(os.getcwd()), 'w', newline='\n').write('# Benchmark notes\n')
print(len(picked), 'functions hidden:', collections.Counter(f for _, f, _ in picked).most_common())
