"""Which library functions does KH1 FM's game code call, and from how many places?
Scans every jal in the game code (everything before the library area) of the original program, maps targets to
names via the build's symbol table, and groups the library ones by library (from config/kh.fm.yaml lib/ pieces)."""
import re, struct, collections, sys, os, json
sys.path.insert(0, os.path.dirname(__file__))
from elf_funcs import elf_functions
REPO = r'C:\Users\you\psp-learning\kh1-study\kh1-decomp'
W = r'\\wsl.localhost\Ubuntu\home\you\kh1-decomp-build'
rom = open(os.path.join(W, 'SLPS_251.98.rom'), 'rb').read()
names = elf_functions(os.path.join(W, 'build', 'fm', 'SLPS_251.98.elf'))
LIB0 = 0x14f318
y = open(os.path.join(REPO, 'config', 'kh.fm.yaml'), encoding='utf-8').read()
segs = sorted((int(o, 16), t, (n or '').strip()) for o, t, n in
              re.findall(r'^\s*-\s*\[\s*0x([0-9a-f]+)\s*,\s*([.\w]+)\s*(?:,\s*([^\]#]+))?\]', y, re.M))
text = [(o, n) for o, t, n in segs if t in ('c', 'asm', 'hasm') and o < 0x172c70]
starts = [o for o, n in text]
import bisect
def libof(off):
    i = bisect.bisect_right(starts, off) - 1
    n = text[i][1] if i >= 0 else ''
    return n
def nm(v):
    c = [x for x in names.get(v, []) if not x.endswith('.NON_MATCHING') and x]
    return c[0] if c else 'func_%08X' % v
calls = collections.Counter(); callers = collections.defaultdict(set)
for off in range(0x1d8, LIB0, 4):
    w = struct.unpack_from('<I', rom, off)[0]
    if w >> 26 != 3: continue
    tgt = ((off + 0x100000) & 0xf0000000) | ((w & 0x3ffffff) << 2)
    toff = tgt - 0x100000
    if LIB0 <= toff < 0x172c70:
        calls[tgt] += 1; callers[tgt].add(libof(off))
bylib = collections.defaultdict(list)
for tgt, n in calls.items():
    lib = libof(tgt - 0x100000)
    lib = lib.split('/')[1] if lib.startswith('lib/') else lib
    bylib[lib].append((n, nm(tgt), len(callers[tgt])))
out = []
for lib in sorted(bylib, key=lambda l: -sum(x[0] for x in bylib[l])):
    fs = sorted(bylib[lib], reverse=True)
    out.append((lib, sum(x[0] for x in fs), fs))
    print('%-10s %4d call sites, %3d functions: %s' % (lib, sum(x[0] for x in fs), len(fs),
          ', '.join('%s(%d)' % (f, n) for n, f, c in fs[:8]) + (' ...' if len(fs) > 8 else '')))
json.dump(out, open(os.path.join(os.path.dirname(__file__), 'platform_calls.json'), 'w'), indent=0)
print('total: %d library functions called from game code, %d call sites' % (len(calls), sum(calls.values())))
