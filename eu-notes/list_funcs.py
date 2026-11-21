"""From a plain split (configure.py with no extra C files), write eu-notes/<version>_funcs.tsv: address and size
of every function splat found, in every assembly file.   python3 eu-notes/list_funcs.py fm"""
import re, os, glob, sys
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ver = sys.argv[1]
out = {}
for fn in glob.glob(os.path.join(R, 'asm', '**', '*.s'), recursive=True):
    if os.sep + 'data' + os.sep in fn: continue
    size = None; want = False
    for line in open(fn, encoding='utf-8'):
        m = re.match(r'^nonmatching (\w+), 0x([0-9A-F]+)', line)
        if m: size = int(m.group(2), 16); want = True; continue
        if want:
            m = re.match(r'^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ', line)
            if m: out[int(m.group(1), 16)] = size; want = False
with open(os.path.join(R, 'eu-notes', ver + '_funcs.tsv'), 'w', newline='\n') as f:
    for a in sorted(out): f.write('%08X\t%x\n' % (a, out[a]))
print(len(out), 'functions')
