"""apply_eu_wrap.py for a source tree that has VERSION_FM blocks: every lookup only sees text an EU build compiles
(outside #ifdef VERSION_FM, inside its #else, inside #ifndef VERSION_FM). Same three steps and markers as
eu-notes/apply_eu_wrap.py (eu_wrap.tsv, jp_only.tsv, eu_only.tsv); safe to run again.
Run from WSL: python3 eu-notes/apply_eu_wrap_fm.py"""
import os, re, sys
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M = 'VERSION_EU'

def read_tsv(name):
    return [l.rstrip('\n').split('\t') for l in open(os.path.join(R, 'eu-notes', name)) if l.strip()]

def visible(s):
    """list of booleans per character offset start of line -> visible for EU; returns function pos->bool"""
    vis = []          # (line_start, visible)
    stack = []        # each: [cond_known, branch_value, parent_visible]
    cur = True
    pos = 0
    for line in s.split('\n'):
        t = line.strip()
        m = re.match(r'#\s*(ifdef|ifndef|if|else|endif|elif)\b\s*(.*)', t)
        if m:
            d, arg = m.group(1), m.group(2).strip()
            if d in ('ifdef', 'ifndef', 'if'):
                val = None
                if d == 'ifdef' and arg.startswith('VERSION_'): val = arg == M
                elif d == 'ifndef' and arg.startswith('VERSION_'): val = arg != M
                elif d == 'if' and arg == '0': val = False
                stack.append([val, cur])
                vis.append((pos, cur))
                cur = cur and (val is not False)
            elif d == 'else' or d == 'elif':
                val, parent = stack[-1]
                vis.append((pos, cur))
                cur = parent and (val is None or not val)
            elif d == 'endif':
                val, parent = stack.pop()
                vis.append((pos, cur))
                cur = parent
        else:
            vis.append((pos, cur))
        pos += len(line) + 1
    starts = [p for p, v in vis]
    import bisect
    def f(off):
        i = bisect.bisect_right(starts, off) - 1
        return vis[i][1]
    return f

def c_def(s, fn, vis):
    for m in re.finditer(r'^(?!\s|/)[^\n;#]*\b%s\s*\([^;{]*\)\s*\{' % re.escape(fn), s, re.M):
        if not vis(m.start()): continue
        i, depth = m.end() - 1, 0
        while True:
            if s[i] == '{': depth += 1
            elif s[i] == '}':
                depth -= 1
                if depth == 0: return m.start(), i + 1
            i += 1
    return None

def asm_line(s, fn, vis):
    for m in re.finditer(r'^INCLUDE_ASM\("[^"]+",\s*%s\);' % re.escape(fn), s, re.M):
        if vis(m.start()): return m.start(), m.end()
    return None

def func_span(s, fn, vis):
    sp = c_def(s, fn, vis) or asm_line(s, fn, vis)
    if sp is None: return None
    a, b = sp
    if s.startswith('\n#endif', b):
        w = s.rfind('#ifdef ' + M + '\n', 0, a)
        w2 = s.rfind('#ifndef ' + M + '\n', 0, a)
        w = max(w, w2)
        if w != -1 and s.count('#endif', w, a) == 0 and s.count('#if', w + 3, a) == 0:
            a, b = w, b + len('\n#endif')
    return a, b

files = {}
def src(n):
    if n not in files: files[n] = open(os.path.join(R, 'src', n + '.c'), encoding='utf-8').read()
    return files[n]

wrapped = jponly = euonly = skipped = 0
for n, fn in read_tsv('eu_wrap.tsv'):
    s = src(n); vis = visible(s)
    if asm_line(s, fn, vis): skipped += 1; continue          # EU already takes the assembly
    sp = c_def(s, fn, vis)
    if not sp: print('  wrap: not found:', n, fn); continue
    a, b = sp
    proto = re.sub(r'\s+', ' ', s[a:s.index('{', a)]).strip() + ';'
    files[n] = s[:a] + ('#ifdef ' + M + '\n%s\nINCLUDE_ASM("asm/nonmatchings/%s", %s);\n#else\n%s\n#endif'
                        % (proto, n, fn, s[a:b])) + s[b:]
    wrapped += 1

for n, fn in read_tsv('jp_only.tsv'):
    s = src(n); vis = visible(s)
    sp = c_def(s, fn, vis) or asm_line(s, fn, vis)
    if not sp: print('  jp_only: not found (or not visible):', n, fn); continue
    a, b = sp
    if s[max(0, a - 19):a] == '#ifndef ' + M + '\n': continue
    files[n] = s[:a] + '#ifndef ' + M + '\n' + s[a:b] + '\n#endif' + s[b:]
    jponly += 1

last = {}
for n, prev, nm in read_tsv('eu_only.tsv'):
    s = src(n)
    after = last.get((n, prev), prev)
    last[(n, prev)] = nm
    if re.search(r'INCLUDE_ASM\("[^"]+", %s\);' % nm, s): continue
    vis = visible(s)
    sp = func_span(s, after, vis)
    if not sp: print('  eu_only: not found:', n, after); continue
    b = sp[1]
    files[n] = s[:b] + '\n\n#ifdef ' + M + '\nINCLUDE_ASM("asm/nonmatchings/%s", %s);\n#endif' % (n, nm) + s[b:]
    euonly += 1

for n, s in files.items():
    open(os.path.join(R, 'src', n + '.c'), 'w', encoding='utf-8', newline='\n').write(s)
print('wrapped %d (already assembly %d), JP-only %d, EU-only added %d' % (wrapped, skipped, jponly, euonly))
