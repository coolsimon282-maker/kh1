#!/usr/bin/env python3
"""Sort EVERYTHING still in assembly by difficulty and deal it out by model strength (run inside WSL from the
main checkout, after a build):   python3 eu-notes/tiers.py [--write]

Difficulty of a function (lower = easier), from its assembly:
    instructions + 3 x conditional branches + 2 x calls + 6 x loops (backward branches) + float instructions / 2
    then scaled down by up to 80% when an ALREADY-MATCHED function has nearly the same machine code
    (the worker is shown that function's C, so the job is mostly renaming).
History moves a function up a tier: given up by a Qwen after real tries -> at least the Opus tier; recorded in a
Claude agent's notes as given up / close -> the Fable tier. Vector (VU0) and special-instruction code is parked.

Tiers:  easy -> the Qwens (local q1 + rented r1..r3)   medium -> Opus agents (a1, a2)   hard -> Fable (f1)
With --write it replaces the workers' queue files (whole files per worker inside a tier where possible, so two
workers of one tier rarely edit the same file); without it, it only prints the numbers."""
import collections, glob, json, os, re, sys
WRITE = '--write' in sys.argv
ks = os.path.dirname(os.getcwd())
mirror = os.path.expanduser('~/kh1-decomp-build')
idx = json.load(open(os.path.join(mirror, 'build', 'fm', '.simindex.json')))['funcs']
where, defined = {}, set()
for p in glob.glob('src/**/*.c', recursive=True):
    s = open(p, encoding='utf-8', errors='replace').read()
    f = p[4:-2]
    for m in re.finditer(r'^INCLUDE_ASM\("asm/nonmatchings/[^"]+",\s*(\w+)\);', s, re.M): where[m.group(1)] = f
    for m in re.finditer(r'^(?!\s)[A-Za-z_][\w \t\*]*?\b(\w+)\s*\([^;{}()]*\)\s*\{', s, re.M): defined.add(m.group(1))
def grams(ops):
    while ops and ops[-1] == 'nop': ops = ops[:-1]
    return collections.Counter(zip(ops, ops[1:], ops[2:])), len(ops)
by_len = collections.defaultdict(list)
for n, e in idx.items():
    if e['ok'] and n in defined:
        g, l = grams(list(e['ops'])); by_len[l].append((n, g))
def best_sim(fn):
    if fn not in idx: return 0.0
    tg, tn = grams(list(idx[fn]['ops']))
    if tn < 4: return 0.0
    best = 0.0
    for l in range(int(0.75 * tn), int(1.35 * tn) + 1):
        for n, g in by_len.get(l, ()):
            if n == fn: continue
            u = sum((tg | g).values()); s = sum((tg & g).values()) / u if u else 0
            if s > best: best = s
    return best

# history
def notes_text(pat):
    return '\n'.join(open(n, errors='replace').read() for n in glob.glob(pat))
qwen_notes = notes_text(os.path.join(ks, 'kh1-wt', '[qr]*', 'notes', '[qr]*.md'))
qwen_gave = set(re.findall(r'^- (\w+) \([^)]*\): (?:gave up|retry)', qwen_notes, re.M))
claude_noted = set(re.findall(r'\b(?:fm_)?func_[0-9A-Fa-f]{8}\b|\bppp\w+(?:Calc|Draw|Con|Des)\b', notes_text('notes/a*.md') + notes_text('notes/f*.md')))

VEC = re.compile(r'\b(lqc2|sqc2|vmul\w*|vadd\w*|vsub\w*|vdiv|vsqrt|qmfc2|qmtc2|ctc2|cfc2|vcallms|mfc0|mtc0|syscall|sq|lq)\b')
rows = []; parked = 0
for fn, f in where.items():
    if f.startswith('lib/'): continue
    p = os.path.join('asm', 'nonmatchings', f, fn + '.s')
    if not os.path.exists(p): continue
    t = open(p, errors='replace').read()
    z = re.search(r'nonmatching\s+\w+,\s*(0x[0-9A-Fa-f]+)', t)
    if not z: continue
    size = int(z.group(1), 16)
    ins = [m.group(2) for m in re.finditer(r'/\* \w+ (\w+) \w+ \*/\s+(\S+)(.*)', t)]
    lines = re.findall(r'/\* \w+ (\w+) \w+ \*/\s+(\S+)\s*(.*)', t)
    if VEC.search(t) or re.search(r'\bjr\s+\$(?!31\b)', t) or re.search(r'\bbreak\b', t) and 'div' not in t:
        parked += 1; continue
    labels = {m.group(1): int(a, 16) for a, m in ((x.group(2), x) for x in re.finditer(r'^\s*(\.L\w+):\s*\n\s*/\* \w+ (\w+)', t, re.M))}
    br = calls = loops = fl = 0
    for addr, op, args in lines:
        if op in ('jal', 'jalr'): calls += 1
        elif op.startswith('b') and op not in ('b', 'break'):
            br += 1
            m = re.search(r'(\.L\w+)\s*$', args)
            if m and labels.get(m.group(1), 1 << 40) <= int(addr, 16): loops += 1
        elif op == 'b':
            m = re.search(r'(\.L\w+)\s*$', args)
            if m and labels.get(m.group(1), 1 << 40) <= int(addr, 16): loops += 1
        if op.endswith('.s') or op in ('mtc1', 'mfc1', 'lwc1', 'swc1', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl'): fl += 1
    n = len(lines)
    sim = best_sim(fn)
    score = n + 3 * br + 2 * calls + 6 * loops + fl / 2.0
    if sim >= 0.5: score *= 1 - 0.8 * sim
    tier = 'easy' if score <= 55 else 'medium' if score <= 220 else 'hard'
    if fn in qwen_gave and tier == 'easy': tier = 'medium'
    if fn in claude_noted: tier = 'hard'
    rows.append({'fn': fn, 'f': f, 'size': size, 'score': score, 'sim': sim, 'tier': tier})

print('%d functions still in assembly (game code), %d parked (vector / jump table / trap)' % (len(rows) + parked, parked))
for t in ('easy', 'medium', 'hard'):
    rs = [r for r in rows if r['tier'] == t]
    print('%-6s %4d functions, %4d KB | median size %d bytes | with a look-alike (>=0.6): %d' % (
        t, len(rs), sum(r['size'] for r in rs) // 1024, sorted(r['size'] for r in rs)[len(rs) // 2] if rs else 0, sum(1 for r in rs if r['sim'] >= 0.6)))

def deal(rs, workers):
    """whole files to one worker, biggest files first to the least loaded; each list easiest first"""
    byf = collections.defaultdict(list)
    for r in rs: byf[r['f']].append(r)
    load = {w: 0 for w in workers}; out = {w: [] for w in workers}
    for f, ls in sorted(byf.items(), key=lambda x: -len(x[1])):
        w = min(load, key=load.get); out[w] += ls; load[w] += len(ls)
    return {w: sorted(ls, key=lambda r: r['score']) for w, ls in out.items()}
def write(path, rs, title):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + '.new'
    with open(tmp, 'w', newline='\n') as o:
        o.write('# %s\n# Made by eu-notes/tiers.py, easiest first. Columns: bytes  function  file   # difficulty, look-alike score\n' % title)
        for r in rs: o.write('%4d  %-22s %-30s # %d%s\n' % (r['size'], r['fn'], r['f'], r['score'], ', like a matched one %.2f' % r['sim'] if r['sim'] >= 0.5 else ''))
    os.replace(tmp, path)
plan = {}
plan.update(deal([r for r in rows if r['tier'] == 'easy'], ['q1', 'r1', 'r2', 'r3']))
plan.update(deal([r for r in rows if r['tier'] == 'medium'], ['a1', 'a2']))
plan['f1'] = sorted([r for r in rows if r['tier'] == 'hard'], key=lambda r: r['score'])
for w in ('q1', 'r1', 'r2', 'r3', 'a1', 'a2', 'f1'):
    rs = plan[w]
    print('%-3s %4d functions, %3d KB, %2d files' % (w, len(rs), sum(r['size'] for r in rs) // 1024, len({r['f'] for r in rs})))
if WRITE:
    wt = os.path.join(ks, 'kh1-wt')
    for w in ('q1', 'r1', 'r2', 'r3'):
        write(os.path.join(wt, w, 'qwen', 'queue.txt'), plan[w], 'EASY tier for %s (23 Nov re-deal): the simplest functions left, and ones that look like a matched function' % w)
        tw = os.path.join(wt, w, 'qwen', 'twins.txt')
        open(tw, 'w', newline='\n').write('# (none: the queue covers everything)\n')
    write(os.path.join(ks, 'qwen-staging', 'queue.txt'), plan['q1'], 'EASY tier for q1 (23 Nov re-deal)')
    open(os.path.join(ks, 'qwen-staging', 'twins.txt'), 'w', newline='\n').write('# (none: the queue covers everything)\n')
    for w in ('a1', 'a2'):
        write(os.path.join(wt, w, 'work', 'queue.txt'), plan[w], 'MEDIUM tier for Opus agent %s (23 Nov re-deal)' % w)
    write(os.path.join(wt, 'f1', 'fable-work', 'hard_queue.txt'), plan['f1'], 'HARD tier for the Fable agent (23 Nov re-deal): big, or already given up by a Claude agent')
    print('queues written')
