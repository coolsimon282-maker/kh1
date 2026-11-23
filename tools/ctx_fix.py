#!/usr/bin/env python3
"""Make an m2c context file parseable:   python3 tools/ctx_fix.py ctx.c

m2c refuses a whole context if it contains one old-style (K&R) function definition, e.g.

    s32 func_001EFBB8(a0)
        s32 a0;
    {

("K&R-style function header is not supported"). A few functions in src/ need that form to match, and each one
left every other function in its file without a first draft (found 23 Nov: all of seg_0EF950). This rewrites such
headers in the context only (never in src/) to the modern form:  s32 func_001EFBB8(s32 a0) {
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
if n:
    open(p, 'w', encoding='utf-8').write(s2)
