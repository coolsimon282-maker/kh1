"""Applies the EU source changes that eu-notes/gen_eu_c.py worked out. JP and FM builds are unaffected; every step
is safe to run again.

1. eu_wrap.tsv: C functions that are different in EU take EU's own assembly:
       #ifdef VERSION_EU
       <declaration>;                       (so later code that calls or points to it still compiles)
       INCLUDE_ASM("asm/nonmatchings/<file>", name);
       #else
       <the JP C, unchanged>
       #endif
2. jp_only.tsv: functions EU doesn't have:   #ifndef VERSION_EU ... #endif
3. eu_only.tsv: functions only EU has, after the JP function they follow:
       #ifdef VERSION_EU
       INCLUDE_ASM("asm/nonmatchings/<file>", eu_func_XXXXXXXX);
       #endif
"""
import os, re
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VER = os.environ.get('VER', 'eu')
M = 'VERSION_' + VER.upper()

def read_tsv(name):
    p = os.path.join(R, 'eu-notes', name if VER == 'eu' else '%s_%s' % (VER, name.replace('eu_', '')))
    return [l.rstrip('\n').split('\t') for l in open(p)] if os.path.exists(p) else []

def c_def(s, fn):
    """(start, end) of the C definition of fn, or None."""
    m = re.search(r'^(?!\s)[^\n;#]*\b%s\s*\([^;{]*\)\s*\{' % re.escape(fn), s, re.M)
    if not m: return None
    i, depth = m.end() - 1, 0
    while True:
        if s[i] == '{': depth += 1
        elif s[i] == '}':
            depth -= 1
            if depth == 0: return m.start(), i + 1
        i += 1

def func_span(s, fn):
    """(start, end) of fn in the source: its C definition, or its INCLUDE_ASM line; widened to a VERSION_EU
    wrapper around it."""
    sp = c_def(s, fn)
    if sp is None:
        m = re.search(r'^INCLUDE_ASM\("[^"]+",\s*%s\);' % re.escape(fn), s, re.M)
        if not m: return None
        sp = (m.start(), m.end())
    a, b = sp
    if s.startswith('\n#endif', b):
        b += len('\n#endif')
        w = s.rfind('#ifdef ' + M + '\n', 0, a)
        if w != -1 and s.count('#endif', w, a) == 0: a = w
    return a, b

files = {}
def src(n):
    if n not in files: files[n] = open(os.path.join(R, 'src', n + '.c'), encoding='utf-8').read()
    return files[n]

wrapped = jponly = euonly = 0
for n, fn in read_tsv('eu_wrap.tsv'):
    s = src(n)
    if re.search(r'#ifdef ' + M + r'\n(?:[^\n]*;\n)?INCLUDE_ASM\("[^"]+", %s\);' % fn, s): continue
    sp = c_def(s, fn)
    if not sp: print('  not found in source:', n, fn); continue
    a, b = sp
    proto = re.sub(r'\s+', ' ', s[a:s.index('{', a)]).strip() + ';'
    files[n] = s[:a] + ('#ifdef ' + M + '\n%s\nINCLUDE_ASM("asm/nonmatchings/%s", %s);\n#else\n%s\n#endif'
                        % (proto, n, fn, s[a:b])) + s[b:]
    wrapped += 1

for n, fn in read_tsv('jp_only.tsv'):
    s = src(n)
    sp = func_span(s, fn)
    if not sp: print('  not found in source:', n, fn); continue
    a, b = sp
    if s[max(0, a - 19):a] == '#ifndef ' + M + '\n': continue
    files[n] = s[:a] + '#ifndef ' + M + '\n' + s[a:b] + '\n#endif' + s[b:]
    jponly += 1

last = {}
for n, prev, nm in read_tsv('eu_only.tsv'):
    s = src(n)
    after = last.get((n, prev), prev)        # several EU-only functions after one JP function keep their order
    last[(n, prev)] = nm
    if re.search(r'INCLUDE_ASM\("[^"]+", %s\);' % nm, s): continue
    sp = func_span(s, after)
    if not sp: print('  not found in source:', n, prev); continue
    b = sp[1]
    if s[b:b + 20].startswith('\n#endif') and s[max(0, sp[0] - 19):sp[0]] == '#ifndef ' + M + '\n':
        b += len('\n#endif')
    files[n] = s[:b] + '\n\n#ifdef ' + M + '\nINCLUDE_ASM("asm/nonmatchings/%s", %s);\n#endif' % (n, nm) + s[b:]
    euonly += 1

for n, s in files.items():
    open(os.path.join(R, 'src', n + '.c'), 'w', encoding='utf-8', newline='\n').write(s)
print('wrapped %d, JP-only %d, EU-only added %d' % (wrapped, jponly, euonly))
