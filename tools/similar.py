#!/usr/bin/env python3
"""Context for one function to match, printed by `agent-tools.sh next` (run inside WSL, from the checkout):

  python3 tools/similar.py <file> <func> [examples=3]

1. Declarations the project already has for what the function calls and the data it touches (prototypes of its
   `jal` targets, externs of its D_ symbols). A wrong prototype = wrong argument registers = no match.
2. Up to N functions that ALREADY MATCH and whose machine code is most like this one's, with their C. Likeness is
   the overlap of instruction-name triples (no model needed); candidates come from the last built ELF, where a
   function still in assembly carries a '<name>.NON_MATCHING' label and is skipped.

Other projects' LLM pipelines report that examples of similar matched functions and callee signatures are a large
part of their match rate (Mizuchi; see docs/external/README.md). Before this, the local agent only got an example
when an exact twin existed.
"""
import collections, glob, json, os, re, subprocess, sys

f, fn = sys.argv[1], sys.argv[2]
want = int(sys.argv[3]) if len(sys.argv) > 3 else 3
here = os.getcwd()
base = os.path.basename(here)
mirror = os.path.expanduser('~/kh1-decomp-build' if base == 'kh1-decomp' else '~/kh1-build-' + base)
elf = os.path.join(mirror, 'build', 'fm', 'SLPS_251.98.elf')
srcroot = mirror if os.path.isdir(os.path.join(mirror, 'src')) else here    # the mirror is on WSL's own disk: fast

def sources():
    out = {}
    for pat in ('src/**/*.c', 'include/**/*.h', 'src/**/*.h'):
        for p in glob.glob(os.path.join(srcroot, pat), recursive=True):
            if '/libgcc-' in p or '/newlib' in p: continue
            try: out[os.path.relpath(p, srcroot)] = open(p, encoding='utf-8', errors='replace').read()
            except OSError: pass
    return out
SRC = sources()

DEF = re.compile(r'^(?!\s)(?:static\s+|inline\s+)*[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(([^;{}()]*)\)\s*\{', re.M)
defs = {}                                    # name -> (file, start of definition, index of its '{')
for p, s in SRC.items():
    if not p.endswith('.c'): continue
    for m in DEF.finditer(s):
        if m.group(1) not in ('if', 'while', 'for', 'switch', 'return', 'sizeof'): defs.setdefault(m.group(1), (p, m.start(), m.end() - 1))

def body(name):
    p, a, i = defs[name]; s = SRC[p]; d = 0
    for j in range(i, len(s)):
        d += {'{': 1, '}': -1}.get(s[j], 0)
        if d == 0: return p, s[a:j + 1]
    return p, s[a:]

# ---- 1. declarations for what it calls / touches ----
asm_path = os.path.join(here, 'asm', 'nonmatchings', f, fn + '.s')
asm = open(asm_path, errors='replace').read() if os.path.exists(asm_path) else ''
calls = list(dict.fromkeys(re.findall(r'\bj(?:al)?\s+(\w+)', asm)))
data = list(dict.fromkeys(re.findall(r'%(?:hi|lo|gp_rel)\((D_\w+)', asm)))
lines = []
for c in calls:
    if c in defs:
        p, a, i = defs[c]; lines.append('%s;   // defined in %s' % (' '.join(SRC[p][a:i].split()), p))
        continue
    proto = None
    for p, s in SRC.items():
        m = re.search(r'^(?!\s)[A-Za-z_][^\n;{}()=]*\b%s\s*\([^;{}]*\)\s*;' % re.escape(c), s, re.M)
        if m: proto = '%s   // declared in %s' % (' '.join(m.group(0).split()), p); break
    lines.append(proto or '// %s: no C or prototype yet - declare it yourself from the argument registers ($4.. ints, $f12.. floats) and how $2/$f0 is used' % c)
for d in data[:12]:
    decl = None
    for p, s in SRC.items():
        m = re.search(r'^(?!\s)(?:extern\s+)?[A-Za-z_][\w \t\*]*\b%s\b[^;(){}\n]*;' % re.escape(d), s, re.M)
        if m: decl = '%s   // as used in %s' % (' '.join(m.group(0).split()), p); break
    lines.append(decl or '// %s: not declared anywhere yet - choose its type from how it is loaded/stored (lw = s32, lh = s16, lbu = u8, lwc1 = f32)' % d)
if lines:
    print('== declarations this project already uses for what it calls / touches (copy the ones you need) ==')
    print('\n'.join(lines))

# ---- 2. similar functions that already match ----
if not os.path.exists(elf) or want <= 0: sys.exit(0)
idx_path = os.path.join(mirror, 'build', 'fm', '.simindex.json')
idx = None
try:
    j = json.load(open(idx_path))
    if j["mtime"] == os.path.getmtime(elf) and j["funcs"]: idx = j["funcs"]
except (OSError, ValueError, KeyError): pass
if idx is None:
    names = collections.defaultdict(list)
    for l in subprocess.run(['mips-linux-gnu-nm', elf], capture_output=True, text=True).stdout.splitlines():
        p = l.split()
        if len(p) == 3 and p[1] in 'Tt': names[int(p[0], 16)].append(p[2])
    idx = {}; cur = None
    dis = subprocess.run(['mips-linux-gnu-objdump', '-d', '-z', '-M', 'no-aliases', '-j', '.main', elf], capture_output=True, text=True, errors='replace').stdout
    for l in dis.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(\S+)', l)
        if not m: continue
        a = int(m.group(1), 16)
        if a in names:
            ns = [n for n in names[a] if re.match(r'^[A-Za-z_]\w*(\.NON_MATCHING)?$', n) and not n.startswith(('D_', 'jtbl_', 'L'))]
            if ns:
                real = [n for n in ns if not n.endswith('.NON_MATCHING')]
                cur = {'ok': len(real) == len(ns), 'ops': []}
                for n in real or [x[:-13] for x in ns]: idx[n] = cur
            else: cur = None                  # a data symbol: the code before it has ended
        if cur is not None: cur['ops'].append(m.group(2))
    try: json.dump({'mtime': os.path.getmtime(elf), 'funcs': idx}, open(idx_path, 'w'))
    except OSError: pass

def grams(ops):
    while ops and ops[-1] == 'nop': ops = ops[:-1]
    return collections.Counter(zip(ops, ops[1:], ops[2:])), len(ops)
if fn not in idx: sys.exit(0)
tg, tn = grams(list(idx[fn]['ops']))
if tn < 4: sys.exit(0)
scored = []
for name, e in idx.items():
    if not e['ok'] or name == fn or name not in defs: continue
    g, n = grams(list(e['ops']))
    if not (0.6 * tn <= n <= 1.7 * tn): continue
    inter = sum((tg & g).values()); union = sum((tg | g).values())
    s = inter / union if union else 0
    if defs[name][0] == 'src/%s.c' % f: s += 0.05
    if s >= 0.25: scored.append((s, name))
shown = 0
for s, name in sorted(scored, reverse=True):
    p, c = body(name)
    if '__asm__' in c or 'INCLUDE_ASM' in c or c.count('\n') > 45: continue
    if shown == 0:
        print('== functions that ALREADY MATCH and compile to similar code (same compiler: copy their style, types and idioms; names, offsets and constants differ) ==')
    print('// %s (%s), %d%% alike' % (name, p, min(99, int(s * 100)))); print(c)
    shown += 1
    if shown >= want: break
