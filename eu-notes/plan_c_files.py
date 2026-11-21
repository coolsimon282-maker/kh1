"""Which JP C files can move to EU as they are: every compiled function found once in EU, all at one shift,
and no .data/.rodata/.bss of their own in the JP layout. Writes eu-notes/c_plan.tsv:
file, JP start, JP end, shift, number of C functions, status."""
import re, collections, os
VER = os.environ.get('VER', 'eu')
def NOTE(x): return os.path.join(os.path.dirname(os.path.abspath(__file__)), x if VER == 'eu' else '%s_%s' % (VER, x.replace('eu_', '')))
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
yaml = open(os.path.join(R, 'config/kh.jp.yaml'), encoding='utf-8').read()
segs = [(int(o, 16), t, (n or '').strip()) for o, t, n in
        re.findall(r'^\s*-\s*\[\s*0x([0-9a-fA-F]+)\s*,\s*([.\w]+)\s*(?:,\s*([^\],#]+))?\]', yaml, re.M)]
text = []
for i, (o, t, n) in enumerate(segs):
    if t in ('c', 'asm', 'hasm'):
        nxt = segs[i + 1][0] if i + 1 < len(segs) else None
        text.append((o, t, n, nxt))
    if t in ('data', '.data', 'rodata', '.rodata'):
        break
has_data = {n for o, t, n in segs if t in ('.data', '.rodata', '.bss', 'data', 'rodata', 'bss') and n}
rows = collections.defaultdict(list)
for line in open(NOTE('eu_matches.tsv'), encoding='utf-8'):
    f, name, ln, hits, shift = (line.rstrip('\n').split('\t') + [''] * 5)[:5]
    rows[f.replace('__', '/')].append((name, int(ln), hits, shift))
out = []
for o, t, n, nxt in text:
    if t != 'c' or n.startswith('lib/'):
        continue
    src = os.path.join(R, 'src', n + '.c')
    rod = 'INCLUDE_RODATA' in open(src, encoding='utf-8', errors='replace').read() if os.path.exists(src) else False
    fn = rows.get(n, [])
    shifts = {s for _, _, h, s in fn if s}
    missing = [x for x, _, h, s in fn if not h or ',' in h]
    if n in has_data or rod: status = 'has own data'
    elif not fn: status = 'no C functions'
    elif missing: status = 'differs: ' + ','.join(missing[:3])
    elif len(shifts) != 1: status = 'several shifts'
    else: status = 'ok'
    sh = shifts.pop() if len(shifts) == 1 else ''
    out.append((n, o, nxt, sh, len(fn), status))
with open(NOTE('c_plan.tsv'), 'w', encoding='utf-8', newline='\n') as f:
    for r in out:
        f.write('%s\t%#x\t%#x\t%s\t%d\t%s\n' % r)
c = collections.Counter(r[5].split(':')[0] for r in out)
print(dict(c))
for r in out:
    if r[5] == 'ok': print('  %-28s JP %#8x-%#8x  shift %-7s %3d C funcs' % (r[0], r[1], r[2], r[3], r[4]))
