#!/usr/bin/env python3
"""Queue for the rented (RunPod) model, kept apart from the local Qwen's work.   python eu-notes/runpod_queue.py > queue

Run on Windows from the main checkout. Takes every function still in assembly up to MAX bytes, smallest first:
in the named source files any size, in the src/unsplit files only those ABOVE 128 bytes (the local Qwen owns the
ones up to 128 there, and all of its own file seg_132D60). It leaves out:
  - anything in the local Qwen's queue or twins list (kh1-study/qwen-staging and kh1-wt/q1/qwen),
  - anything a notes file already records (given up or known wall, by any agent),
  - files whose first draft cannot be produced (inline-assembly sources) and library code.
"""
import glob, os, re, sys
MAX = int(sys.argv[1]) if len(sys.argv) > 1 else 256
here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ks = os.path.dirname(here)
taken = set()
for q in glob.glob(os.path.join(ks, 'qwen-staging', '*.txt')) + glob.glob(os.path.join(ks, 'kh1-wt', 'q1', 'qwen', '*.txt')):
    for l in open(q, errors='replace'):
        m = re.match(r'^\s*\d+\s+(\w+)\s+\S+', l)
        if m: taken.add(m.group(1))
noted = set()
for n in glob.glob(os.path.join(here, 'notes', '*.md')) + glob.glob(os.path.join(ks, 'kh1-wt', '*', 'notes', '*.md')):
    noted.update(re.findall(r'\b(?:fm_)?func_[0-9A-Fa-f]{8}\b', open(n, errors='replace').read()))
skip_files = ('lib/', 'unsplit/seg_132D60', 'ppp/eiProg/pppSRand', 'ppp/ryjProg/pppRyjMegaBirthFilter', 'ppp/ryjProg/pppRyjMegaPlaceLamp',
              'ppp/draw/draw', 'xbuffalo', 'xpeanut')
rows = []
for c in glob.glob(os.path.join(here, 'src', '**', '*.c'), recursive=True):
    f = os.path.relpath(c, os.path.join(here, 'src'))[:-2].replace(os.sep, '/')
    if f.startswith(skip_files): continue
    for m in re.finditer(r'^INCLUDE_ASM\("asm/nonmatchings/[^"]+",\s*(\w+)\);', open(c, encoding='utf-8', errors='replace').read(), re.M):
        fn = m.group(1)
        if fn in taken or fn in noted: continue
        s = os.path.join(here, 'asm', 'nonmatchings', f, fn + '.s')
        if not os.path.exists(s): continue
        t = open(s, errors='replace').read()
        z = re.search(r'nonmatching\s+\w+,\s*(0x[0-9A-Fa-f]+)', t)
        if not z or 'jr         $' in t and 'jr         $31' not in t: continue
        size = int(z.group(1), 16)
        if re.search(r'\b(lqc2|sqc2|vmul|vadd|vsub|qmfc2|qmtc2|ctc2|cfc2|vcallms|ldl|ldr|sdl|sdr|mfc0|mtc0|syscall|break)\b', t): continue   # not plain C
        if f.startswith('unsplit/') and size <= 128: continue           # the local Qwen's share
        if 8 < size <= MAX: rows.append((size, fn, f))
print('# Queue for the rented model (RunPod): named files up to %d bytes, unsplit files 129-%d bytes, smallest first.' % (MAX, MAX))
print('# Not in it: the local Qwen\'s functions, anything already noted as given up, vector/special-instruction code.')
for size, fn, f in sorted(rows): print('%4d  %-18s %s' % (size, fn, f))
