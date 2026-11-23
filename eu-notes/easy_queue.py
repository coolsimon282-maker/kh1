#!/usr/bin/env python3
"""Rank every function still in assembly by how close an ALREADY-MATCHED function is to it (run inside WSL from the
main checkout, after a build):   python3 eu-notes/easy_queue.py [min_score=0.6] > queue

A function whose machine code is nearly the same as a matched one is the easiest work there is for the local
model: `agent-tools.sh next` shows it that matched function's C (tools/similar.py), and it only has to change
names, offsets and constants. Output: the queue format `next` reads (size, function, file), best score first,
with the score and the look-alike as a trailing comment. Uses the same index as tools/similar.py."""
import collections, glob, json, os, re, subprocess, sys
lo = float(sys.argv[1]) if len(sys.argv) > 1 else 0.6
mirror = os.path.expanduser('~/kh1-decomp-build')
elf = os.path.join(mirror, 'build', 'fm', 'SLPS_251.98.elf')
# build / refresh the index by asking similar.py about any function (it caches next to the ELF)
any_s = next(iter(glob.glob('asm/nonmatchings/**/*.s', recursive=True)), None)
if any_s:
    f = os.path.relpath(os.path.dirname(any_s), 'asm/nonmatchings'); fn = os.path.basename(any_s)[:-2]
    subprocess.run([sys.executable, 'tools/similar.py', f, fn, '1'], capture_output=True)
idx = json.load(open(os.path.join(mirror, 'build', 'fm', '.simindex.json')))['funcs']
where = {}                                         # unmatched function -> file (from its INCLUDE_ASM line)
defined = set()
for p in glob.glob('src/**/*.c', recursive=True):
    s = open(p, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'^INCLUDE_ASM\("asm/nonmatchings/([^"]+)",\s*(\w+)\);', s, re.M): where[m.group(2)] = m.group(1)
    for m in re.finditer(r'^(?!\s)[A-Za-z_][\w \t\*]*?\b(\w+)\s*\([^;{}()]*\)\s*\{', s, re.M): defined.add(m.group(1))
def grams(ops):
    while ops and ops[-1] == 'nop': ops = ops[:-1]
    return collections.Counter(zip(ops, ops[1:], ops[2:])), len(ops)
done = [(n,) + grams(list(e['ops'])) for n, e in idx.items() if e['ok'] and n in defined]
by_len = collections.defaultdict(list)
for n, g, l in done: by_len[l].append((n, g))
out = []
for fn, f in where.items():
    if fn not in idx: continue
    tg, tn = grams(list(idx[fn]['ops']))
    if tn < 4: continue
    best = (0, None)
    for l in range(int(0.75 * tn), int(1.35 * tn) + 1):
        for n, g in by_len.get(l, ()):
            u = sum((tg | g).values()); s = sum((tg & g).values()) / u if u else 0
            if s > best[0] and n != fn: best = (s, n)
    if best[0] >= lo: out.append((best[0], tn * 4, fn, f, best[1]))
print('# Easiest first: functions still in assembly that look most like one already matched (score, look-alike)')
for s, size, fn, f, like in sorted(out, key=lambda x: (-round(x[0], 2), x[1])):
    print('%4d  %-18s %-28s # %.2f like %s' % (size, fn, f, s, like))
