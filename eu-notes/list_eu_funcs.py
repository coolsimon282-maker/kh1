"""From a plain (no C) EU split, write eu-notes/eu_funcs.tsv: EU address and size of every function splat found."""
import re, os
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
out = []
for fn in ('asm/crt0.s', 'asm/1D8.s'):
    size = None; want = False
    for line in open(os.path.join(R, fn), encoding='utf-8'):
        m = re.match(r'^nonmatching (\w+), 0x([0-9A-F]+)', line)
        if m: size = int(m.group(2), 16); want = True; continue
        if want:
            m = re.match(r'^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ', line)
            if m: out.append((int(m.group(1), 16), size)); want = False
with open(os.path.join(R, 'eu-notes/eu_funcs.tsv'), 'w', newline='\n') as f:
    for a, s in out: f.write('%08X\t%x\n' % (a, s))
print(len(out), 'functions')
