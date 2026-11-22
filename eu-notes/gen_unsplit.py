"""Write src/unsplit/seg_XXXXXX.c placeholder files (one INCLUDE_ASM per function, in address order) from the
asm/nonmatchings/unsplit/seg_XXXXXX/*.s files splat generated. Run from the repo root on Windows after configure."""
import glob, os, re, sys
for d in sorted(glob.glob('asm/nonmatchings/unsplit/seg_*')):
    seg = os.path.basename(d)
    out = 'src/unsplit/%s.c' % seg
    if os.path.exists(out) and '--force' not in sys.argv:
        print('exists, skipped:', out); continue
    funcs = []
    for p in glob.glob(d + '/*.s'):
        s = open(p, encoding='utf-8').read()
        m = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', s)
        if not m or not re.search(r'^\s*(glabel|nonmatching) ', s, re.M): continue
        funcs.append((int(m.group(1), 16), os.path.basename(p)[:-2]))
    funcs.sort()
    os.makedirs('src/unsplit', exist_ok=True)
    lines = ['// Placeholder for code that hasn\'t been assigned to a source file yet (Final Mix offset 0x%s).' % seg[4:],
             '// Functions can be matched here like in any other file; the file may be split later.',
             '#include "common.h"', '']
    lines += ['INCLUDE_ASM("asm/nonmatchings/unsplit/%s", %s);\n' % (seg, f) for _, f in funcs]
    open(out, 'w', encoding='utf-8', newline='\n').write('\n'.join(lines))
    print(out, len(funcs), 'functions')
