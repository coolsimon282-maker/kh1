#!/usr/bin/env python3
"""List the near-misses the Qwen workers left behind (run on Windows from the main checkout):

    python eu-notes/near_misses.py [max_off=8]

agent-tools.sh keeps, per function a worker gave up, its closest attempt: qwen/attempts/<func>.c and
<func>.score ("<instructions off> <of how many> <file>"). A function that is only a few instructions off is a head
start for a stronger model or for the permuter. Prints them closest first, still-unmatched ones only."""
import glob, os, re, sys
mx = int(sys.argv[1]) if len(sys.argv) > 1 else 8
here = os.path.dirname(os.path.dirname(os.path.abspath(__file__))); ks = os.path.dirname(here)
still = set()
for c in glob.glob(os.path.join(here, 'src', '**', '*.c'), recursive=True):
    still.update(re.findall(r'^INCLUDE_ASM\("[^"]+",\s*(\w+)\);', open(c, encoding='utf-8', errors='replace').read(), re.M))
rows = []
for sc in glob.glob(os.path.join(ks, 'kh1-wt', '*', 'qwen', 'attempts', '*.score')):
    fn = os.path.basename(sc)[:-6]
    p = open(sc).read().split()
    if fn in still and len(p) >= 3 and int(p[0]) <= mx:
        rows.append((int(p[0]), int(p[1]), fn, p[2], sc[:-6] + '.c'))
for off, tot, fn, f, c in sorted(rows):
    print('%2d of %3d off  %-22s %-28s %s' % (off, tot, fn, f, os.path.relpath(c, ks)))
print('%d near-misses (up to %d instructions off)' % (len(rows), mx))
