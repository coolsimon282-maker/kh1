#!/usr/bin/env python3
"""Make an m2c context file parseable:   python3 tools/ctx_fix.py ctx.c

m2c refuses a whole context if it contains one old-style (K&R) function definition, e.g.

    s32 func_001EFBB8(a0)
        s32 a0;
    {

("K&R-style function header is not supported"). A few functions in src/ need that form to match, and each one
left every other function in its file without a first draft (found 23 Nov: all of seg_0EF950). This rewrites such
headers in the context only (never in src/) to the modern form:  s32 func_001EFBB8(s32 a0) {

Second fix: on the PS2 `long` is 64 bits, but m2c takes it as 32 and rejects the whole context at the first wide
bitfield ("Width of bitfield pad01 exceeds its type": Sony's eestruct.h has `unsigned long pad01:63`, and u64 is
a typedef of unsigned long). That left 12 files without drafts, among them seg_03BDE8 (599 functions in
assembly) and xhumungus (161). In the context `long` becomes `long long`: the same 64-bit type to m2c.
"""
import re, sys
p = sys.argv[1]
s = open(p, encoding='utf-8', errors='replace').read()
KR = re.compile(r'^(?P<head>(?!\s)[A-Za-z_][\w \t\*]*?\b\w+\s*)\((?P<params>\s*\w+(?:\s*,\s*\w+)*\s*)\)[ \t]*\n(?P<decls>(?:[ \t]*[A-Za-z_][^;{}()\n]*;[ \t]*\n)+)[ \t]*\{', re.M)
n = 0
def fix(m):
    global n
    names = [x.strip() for x in m.group('params').split(',')]
    types = {}
    for d in m.group('decls').split(';'):
        d = d.strip()
        if not d: continue
        first = re.match(r'^(.*?)([\*\s]*\w+(?:\[[^\]]*\])*)\s*(?:,|$)', d)
        if not first: return m.group(0)
        base = first.group(1).strip()
        for decl in d[len(first.group(1)):].split(','):
            nm = re.search(r'(\w+)(?:\[[^\]]*\])*\s*$', decl.strip())
            if not nm: return m.group(0)
            types[nm.group(1)] = '%s %s' % (base, decl.strip())
    if any(x not in types for x in names): return m.group(0)      # not a K&R definition after all: leave it
    n += 1
    return '%s(%s) {' % (m.group('head'), ', '.join(types[x] for x in names))
s2 = KR.sub(fix, s)
s3 = re.sub(r'\blong\b(?:\s+long\b)?(?!\s+double\b)', 'long long', s2)
if s3 != s2: s2 = s3; n += 1
if n:
    open(p, 'w', encoding='utf-8').write(s2)
