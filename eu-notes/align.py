import re, glob, struct, difflib, rabbitizer
from eu_dis import d, BASE, OFF, word
R = r'C:/Users/you/psp-learning/kh1-study/kh1-decomp'
TEXT_END_EU = 0x100000 + 0x38da30
# JP function starts: every func_XXXXXXXX the repo knows + named symbols with type:func
jp = set()
for f in glob.glob(R+'/src/**/*.c', recursive=True):
    for m in re.finditer(r'func_([0-9A-F]{8})', open(f, encoding='utf-8', errors='replace').read()):
        jp.add(int(m.group(1), 16))
for f in [R+'/config/jp/symbol_addrs.txt', R+'/config/jp/lib_symbol_addrs.txt']:
    for m in re.finditer(r'=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func', open(f).read()):
        jp.add(int(m.group(1), 16))
# JP text end: first rodata/data segment in the yaml
segs = re.findall(r'\[\s*0x([0-9A-Fa-f]+),\s*([a-z.]+)', open(R+'/config/kh.jp.yaml').read())
jp_text_end = 0x100000 + min(int(o,16) for o,t in segs if t in ('data','.data','rodata','.rodata') and int(o,16) > 0x1000)
jp = sorted(a for a in jp if 0x100000 <= a < jp_text_end)
# EU function starts: every jal target inside the code
eu = set([0x100008])
a = 0x100000
while a < TEXT_END_EU:
    w = word(a)
    if (w >> 26) == 3: eu.add(((a + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    a += 4
eu_text_end = min([TEXT_END_EU])
eu = sorted(x for x in eu if 0x100000 <= x < TEXT_END_EU)
print('JP text end %#x, JP functions known %d' % (jp_text_end, len(jp)))
print('EU text end %#x, EU jal targets %d' % (TEXT_END_EU, len(eu)))
def sizes(s, end): return [b - a for a, b in zip(s, s[1:] + [end])]
js, es = sizes(jp, jp_text_end), sizes(eu, TEXT_END_EU)
sm = difflib.SequenceMatcher(None, js, es, autojunk=False)
blocks = [b for b in sm.get_matching_blocks() if b.size]
matched = sum(b.size for b in blocks)
print('functions with matching size sequence: %d of %d JP' % (matched, len(jp)))
print('\nJP addr -> EU addr, shift, run length (runs >= 20):')
for b in blocks:
    if b.size >= 20:
        print('  %08X -> %08X  shift %+#7x  %4d funcs' % (jp[b.a], eu[b.b], eu[b.b] - jp[b.a], b.size))
import json; json.dump({'jp': jp, 'eu': eu, 'blocks': [(b.a, b.b, b.size) for b in blocks]}, open('align.json','w'))
