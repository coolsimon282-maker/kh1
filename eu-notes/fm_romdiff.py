"""Where does the rebuilt EU image differ from the original? Lists differing ranges and the config piece each is in.
Run in WSL in ~/kh1-decomp-build (after ninja)."""
import re, sys
a = open('build/fm/SLPS_251.98.rom', 'rb').read(); b = open('SLPS_251.98.rom', 'rb').read()
segs = [(int(o, 16), t, (n or '').strip()) for o, t, n in re.findall(r'^\s*-\s*\[\s*0x([0-9a-fA-F]+)\s*,\s*([.\w]+)\s*(?:,\s*([^\],#]+))?\]', open('config/kh.fm.yaml').read(), re.M)]
segs.sort()
def seg(off):
    best = None
    for o, t, n in segs:
        if o <= off: best = (o, t, n)
        else: break
    return best
if len(a) != len(b): print('size differs: rebuilt %#x, original %#x' % (len(a), len(b)))
ranges, i, n = [], 0, min(len(a), len(b))
while i < n:
    if a[i] != b[i]:
        j = i
        while j < n and (a[j] != b[j] or any(a[k] != b[k] for k in range(j, min(j + 16, n)))): j += 1
        ranges.append((i, j)); i = j
    else: i += 1
by = {}
for lo, hi in ranges:
    s = seg(lo); by.setdefault(s, []).append((lo, hi))
for s, rs in by.items():
    print('%-40s %3d ranges, first at %#x (vram %#x), %d bytes' % ('%s %s @%#x' % (s[1], s[2], s[0]), len(rs), rs[0][0], rs[0][0] + 0x100000, sum(h - l for l, h in rs)))
