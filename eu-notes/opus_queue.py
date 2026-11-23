#!/usr/bin/env python3
"""Work lists for Claude agents on the mid-sized functions nobody else owns (run on Windows from the main checkout):

    python eu-notes/opus_queue.py [min=257] [max=800] [parts=2]   -> writes kh1-wt/a<N>/work/queue.txt

Every function still in assembly between MIN and MAX bytes, except: anything in a Qwen queue (local q1, rented
r1..r4, the staging copies, f1's easy list), vector / special-instruction code, jump tables, library code.
Whole files go to one agent (so two agents never edit the same file), biggest files dealt first to the agent with
the least work; each list is sorted smallest first."""
import collections, glob, os, re, sys
lo = int(sys.argv[1]) if len(sys.argv) > 1 else 257
hi = int(sys.argv[2]) if len(sys.argv) > 2 else 800
parts = int(sys.argv[3]) if len(sys.argv) > 3 else 2
here = os.path.dirname(os.path.dirname(os.path.abspath(__file__))); ks = os.path.dirname(here)
taken = set()
for q in (glob.glob(os.path.join(ks, 'qwen-staging', '*.txt')) + glob.glob(os.path.join(ks, 'kh1-wt', '[qr]*', 'qwen', '*.txt'))
          + glob.glob(os.path.join(ks, 'kh1-wt', 'f1', 'fable-work', 'easy_queue*.txt'))):
    for l in open(q, errors='replace'):
        m = re.match(r'^\s*\d+\s+(\w+)\s+\S+', l)
        if m: taken.add(m.group(1))
rows = collections.defaultdict(list)
for c in glob.glob(os.path.join(here, 'src', '**', '*.c'), recursive=True):
    f = os.path.relpath(c, os.path.join(here, 'src'))[:-2].replace(os.sep, '/')
    if f.startswith('lib/'): continue
    for m in re.finditer(r'^INCLUDE_ASM\("asm/nonmatchings/[^"]+",\s*(\w+)\);', open(c, encoding='utf-8', errors='replace').read(), re.M):
        fn = m.group(1)
        if fn in taken: continue
        s = os.path.join(here, 'asm', 'nonmatchings', f, fn + '.s')
        if not os.path.exists(s): continue
        t = open(s, errors='replace').read()
        z = re.search(r'nonmatching\s+\w+,\s*(0x[0-9A-Fa-f]+)', t)
        if not z: continue
        size = int(z.group(1), 16)
        if not lo <= size <= hi: continue
        if re.search(r'\b(lqc2|sqc2|vmul\w*|vadd\w*|vsub\w*|qmfc2|qmtc2|ctc2|cfc2|vcallms|mfc0|mtc0|syscall)\b', t): continue
        if re.search(r'\bjr\s+\$(?!31\b)', t): continue                       # jump table
        rows[f].append((size, fn, f))
load = [0] * parts; out = [[] for _ in range(parts)]
for f, ls in sorted(rows.items(), key=lambda x: -sum(r[0] for r in x[1])):
    w = load.index(min(load)); out[w] += ls; load[w] += sum(r[0] for r in ls)
for i, ls in enumerate(out):
    d = os.path.join(ks, 'kh1-wt', 'a%d' % (i + 1), 'work'); os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, 'queue.txt'), 'w', newline='\n') as o:
        o.write('# Work list for Claude agent a%d: functions of %d-%d bytes nobody else owns, whole files, smallest first.\n# bytes  function  file\n' % (i + 1, lo, hi))
        for size, fn, f in sorted(ls): o.write('%4d  %-22s %s\n' % (size, fn, f))
    print('a%d: %d functions, %d KB, %d files: %s' % (i + 1, len(ls), sum(r[0] for r in ls) // 1024, len({r[2] for r in ls}), ', '.join(sorted({r[2] for r in ls}))[:170]))
