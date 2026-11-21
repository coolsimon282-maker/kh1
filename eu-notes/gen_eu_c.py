"""Builds the EU config's C pieces (run in WSL, after build_all.sh has compiled the JP C files into ~/kh1-test/obj).

For every JP C file that can be placed in the EU program:
  * a `c` subsegment at its EU position, with `asm` pieces in between, plus its own .data/.rodata pieces;
  * the JP names of its functions at their EU addresses: C functions found in EU (eu_matches.tsv; one found
    several times is settled by its position between its neighbours), everything else placed on EU's own
    function starts (eu_funcs.tsv) in JP order;
  * every symbol its C code refers to (calls, variables), read from the EU instruction at each relocation
    (MIPS REL: the offset is kept in the compiled instruction);
  * C functions that aren't in EU at all are listed in eu-notes/eu_wrap.tsv: apply_eu_wrap.py makes EU
    build them from EU's assembly (#ifdef VERSION_EU ... INCLUDE_ASM), JP keeps the C.
Writes config/eu/jp_names.txt and the generated parts of config/kh.eu.yaml.

    python3 eu-notes/gen_eu_c.py [--only file1,file2]
"""
import bisect, collections, os, re, struct, subprocess, sys

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OBJ = os.path.expanduser('~/kh1-test/obj')
TEXT_END, DATA0, RODATA0, END0 = 0x16d630, 0x16d630, 0x3867d0, 0x38da30
d = open(os.path.join(R, 'SCES_509.67'), 'rb').read()
def eu_word(va): return struct.unpack_from('<I', d, 0x80 + va - 0x100000)[0]
def s16(x): return x - 0x10000 if x & 0x8000 else x
only = set(sys.argv[sys.argv.index('--only') + 1].split(',')) if '--only' in sys.argv else None

JPSYM = {}
for sf in ('config/jp/symbol_addrs.txt', 'config/jp/lib_symbol_addrs.txt'):
    for m in re.finditer(r'^(\w+)\s*=\s*0x([0-9A-Fa-f]+);', open(os.path.join(R, sf)).read(), re.M):
        JPSYM[m.group(1)] = int(m.group(2), 16)
def jp_addr(name):
    m = re.match(r'(?:func|D|jtbl)_([0-9A-F]{8})$', name)
    return int(m.group(1), 16) if m else JPSYM.get(name)

EUF = [int(l.split()[0], 16) for l in open(os.path.join(R, 'eu-notes/eu_funcs.tsv'))]
def eu_next_start(a):
    i = bisect.bisect_right(EUF, a); return EUF[i] if i < len(EUF) else 0x100000 + TEXT_END

hits = {}
for line in open(os.path.join(R, 'eu-notes/eu_matches.tsv')):
    f, name, ln, h, shift = (line.rstrip('\n').split('\t') + [''] * 5)[:5]
    hits[(f.replace('__', '/'), name)] = [int(x, 16) for x in h.split(',')] if h else []

plan, JPEND = [], {}
for line in open(os.path.join(R, 'eu-notes/c_plan.tsv')):
    n, jps, jpe, sh, nf, status = line.rstrip('\n').split('\t')
    JPEND[n] = int(jpe, 16) + 0x100000
    if status != 'no C functions' and (only is None or n in only):
        plan.append(n)

_jy = open(os.path.join(R, 'config/kh.jp.yaml'), encoding='utf-8').read()
_js = [(int(o, 16), t, (nm or '').strip()) for o, t, nm in
       re.findall(r'^\s*-\s*\[\s*0x([0-9a-fA-F]+)\s*(?:,\s*([.\w]+)\s*)?(?:,\s*([^\],#]+))?\]', _jy, re.M)]
JPDATA = {(nm, t): _js[i + 1][0] - o for i, (o, t, nm) in enumerate(_js)
          if t in ('.data', '.rodata') and nm and i + 1 < len(_js)}
SIZES = {}
NOMIGRATE = set()
JPSTART = {(nm, t): o + 0x100000 for o, t, nm in _js if t in ('.data', '.rodata') and nm}

LOADSTORE = {0x09, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2b, 0x31, 0x39, 0x37, 0x3f, 0x1e, 0x1f}
def eu_code_refs(lo, hi, alo, ahi):
    """Addresses in [alo, ahi) that EU code in [lo, hi) builds with lui + offset."""
    out, hreg = set(), {}
    for a in range(lo, hi, 4):
        w = eu_word(a); op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31
        if op == 0x0F: hreg[rt] = (w & 0xFFFF) << 16; continue
        if op in LOADSTORE and rs in hreg:
            x = hreg[rs] + s16(w & 0xFFFF)
            if alo <= x < ahi: out.add(x)
        if w == 0x03E00008: hreg = {}
    return sorted(out)

def objdump(path, *args):
    return subprocess.run(['mips-linux-gnu-objdump', *args, path], capture_output=True, text=True).stdout

def section_bytes(o, sec):
    subprocess.run(['mips-linux-gnu-objcopy', '-O', 'binary', '-j', sec, o, '/tmp/_sec.bin'], check=True)
    rel = {int(l.split()[0], 16) for l in objdump(o, '-r', '-j', sec).splitlines() if re.match(r'^[0-9a-f]{8}\s+R_MIPS', l)}
    return open('/tmp/_sec.bin', 'rb').read(), rel

def parse_functions(o):
    """[(name, start, {off: word}, [(off, type, sym)])] in object order."""
    funcs, cur = [], None
    for line in objdump(o, '-dr', '-z').splitlines():
        m = re.match(r'^([0-9a-f]{8}) <(\S+)>:', line)
        if m:
            cur = None if m.group(2).startswith('.') else (m.group(2), int(m.group(1), 16), {}, [])
            if cur: funcs.append(cur)
            continue
        if cur is None: continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s', line)
        if m: cur[2][int(m.group(1), 16)] = int(m.group(2), 16); continue
        m = re.match(r'^\s+([0-9a-f]+):\s+(R_MIPS_\w+)\s+(\S+)', line)
        if m: cur[3].append((int(m.group(1), 16), m.group(2), m.group(3)))
    return funcs

def same_code_at(f, addr):
    """Is compiled function f (from parse_functions) the same as the EU code at addr, address bits aside?"""
    name, fstart, objw, relocs = f
    mask = {off: (0xFC000000 if t == 'R_MIPS_26' else 0xFFFF0000) for off, t, _ in relocs if t in ('R_MIPS_26', 'R_MIPS_HI16', 'R_MIPS_LO16')}
    offs = sorted(objw)
    while len(offs) > 1 and objw[offs[-1]] == 0 and offs[-1] not in mask: offs.pop()   # alignment padding
    return all((eu_word(addr + off - fstart) & mask.get(off, 0xFFFFFFFF)) == (objw[off] & mask.get(off, 0xFFFFFFFF)) for off in offs)

def align_sizes(J, E, free_end=False):
    '''Needleman-Wunsch on function sizes: [(j index or None, e index or None)] in order.'''
    INF = float('inf'); nj, ne = len(J), len(E)
    D = [[INF] * (ne + 1) for _ in range(nj + 1)]; D[0][0] = 0; B = {}
    for i in range(nj + 1):
        for k in range(ne + 1):
            if i and k and D[i - 1][k - 1] + abs(J[i - 1] - E[k - 1]) < D[i][k]: D[i][k] = D[i - 1][k - 1] + abs(J[i - 1] - E[k - 1]); B[i, k] = 'm'
            if i and D[i - 1][k] + J[i - 1] < D[i][k]: D[i][k] = D[i - 1][k] + J[i - 1]; B[i, k] = 'j'
            if k and D[i][k - 1] + E[k - 1] < D[i][k]: D[i][k] = D[i][k - 1] + E[k - 1]; B[i, k] = 'e'
    k_end = min(range(ne + 1), key=lambda k: D[nj][k]) if free_end else ne
    cost = D[nj][k_end]
    out, i, k = [], nj, k_end
    while i or k:
        b = B[i, k]
        if b == 'm': out.append((i - 1, k - 1)); i -= 1; k -= 1
        elif b == 'j': out.append((i - 1, None)); i -= 1
        else: out.append((None, k - 1)); k -= 1
    return (out[::-1], cost) if free_end else out[::-1]

PEND_EUONLY, PEND_JPONLY = [], []
FORCED_EUONLY = {}

def place_file(n, forced=None):
    """forced: {name: EU address} for every function (window pass). Returns (placed {name: EU addr}, refs {name: EU addr}, wraps [names], dsegs, problem)."""
    o = os.path.join(OBJ, n.replace('/', '__') + '.o')
    if not os.path.exists(o): return None, None, None, None, 'no object'
    src = open(os.path.join(R, 'src', n + '.c'), encoding='utf-8', errors='replace').read()
    rodsyms = re.findall(r'INCLUDE_RODATA\(\s*"[^"]+"\s*,\s*(\w+)\s*\)', src)
    secsize = {}
    for l in objdump(o, '-h').splitlines():
        m = re.match(r'\s+\d+\s+(\.(?:rodata|data|bss|sdata|sbss))\s+([0-9a-f]+)', l)
        if m: secsize[m.group(1)] = int(m.group(2), 16)
    if any(secsize.get(s) for s in ('.bss', '.sdata', '.sbss')): return None, None, None, None, 'zero-filled statics (.bss)'
    own = [s for s in ('.data', '.rodata') if secsize.get(s) or (s == '.rodata' and rodsyms)]
    for s in own:
        jz = JPDATA.get((n, s))
        if jz is None or secsize.get(s, 0) > jz:
            return None, None, None, None, '%s size: object %#x, JP piece %s' % (s, secsize.get(s, 0), hex(jz) if jz else 'none')
    if rodsyms and '.rodata' not in own: return None, None, None, None, 'INCLUDE_RODATA but no JP .rodata piece'
    symsec = {}
    for l in objdump(o, '-t').splitlines():
        m = re.match(r'^([0-9a-f]{8})\s.{7}\s(\.(?:data|rodata))\s+([0-9a-f]+)\s+(\S+)$', l)
        if m and not m.group(4).startswith('.'):
            symsec[m.group(4)] = (m.group(2), int(m.group(1), 16)); SIZES[m.group(4)] = int(m.group(3), 16)

    cfuncs = parse_functions(o)
    asm_funcs = [f for f in re.findall(r'INCLUDE_ASM\(\s*"[^"]+"\s*,\s*(\w+)\s*\)', src) if not f.startswith('eu_')]
    allnames = [f[0] for f in cfuncs] + asm_funcs
    if any(jp_addr(f) is None for f in allnames): return None, None, None, None, 'unknown JP address: ' + next(f for f in allnames if jp_addr(f) is None)
    order = sorted(set(allnames), key=jp_addr)
    pos = {f: i for i, f in enumerate(order)}
    if forced is not None:
        # window pass: names missing from forced are functions EU dropped; eu_func_* ones are EU's additions
        placed = {f: a for f, a in forced.items() if f in pos or f.startswith('eu_func_')}
        for f in order:
            if f not in placed: PEND_JPONLY.append((n, f))
        PEND_EUONLY.extend((n, prev, nm) for prev, nm in FORCED_EUONLY.get(n, []))
        wraps = [f[0] for f in cfuncs if f[0] in placed and not same_code_at(f, placed[f[0]])]
        pass  # own data with wrapped functions: the byte check below and the build decide
    else:
        placed = {f[0]: hits[(n, f[0])][0] for f in cfuncs if len(hits.get((n, f[0]), [])) == 1}
        if not placed: return None, None, None, None, 'no C function found in EU to anchor on'
        # settle functions found several times by their position between anchored neighbours
        changed = True
        while changed:
            changed = False
            for f in cfuncs:
                name = f[0]; h = hits.get((n, name), [])
                if name in placed or len(h) < 2: continue
                lo = max([placed[x] for x in placed if pos[x] < pos[name]], default=0)
                hi = min([placed[x] for x in placed if pos[x] > pos[name]], default=1 << 32)
                c = [a for a in h if lo < a < hi]
                if len(c) == 1: placed[name] = c[0]; changed = True
        # anchors must be in JP order: a small function found once but elsewhere in EU is a false match.
        # Keep the longest in-order run of anchors; the rest are placed like assembly functions (and checked).
        an = sorted(placed, key=lambda x: pos[x])
        if any(placed[a] >= placed[b] for a, b in zip(an, an[1:])):
            best = [[x] for x in an]
            for i in range(len(an)):
                for j in range(i):
                    if placed[an[j]] < placed[an[i]] and len(best[j]) + 1 > len(best[i]): best[i] = best[j] + [an[i]]
            keep = set(max(best, key=len))
            if len(keep) < len(an) / 2: return None, None, None, None, 'anchors out of order'
            for x in an:
                if x not in keep: del placed[x]
            an = sorted(placed, key=lambda x: pos[x])
        wraps = [f[0] for f in cfuncs if f[0] not in placed]
        pass  # own data with wrapped functions: the byte check below and the build decide
        # everything not anchored goes on EU function starts, in JP order, between the anchors
        idx = [pos[a] for a in an]
        for k in range(len(idx) + 1):
            lo = idx[k - 1] if k > 0 else None; hi = idx[k] if k < len(idx) else None
            gap = order[(lo + 1) if lo is not None else 0:hi if hi is not None else len(order)]
            if not gap:
                # two neighbouring JP functions, but EU may have added functions between them
                if lo is not None and hi is not None:
                    for a in EUF:
                        if placed[order[lo]] < a < placed[order[hi]]:
                            nm = 'eu_func_%08X' % a; placed[nm] = a; PEND_EUONLY.append((n, order[lo], nm))
                continue
            full = order + [None]
            jsz = [(jp_addr(full[pos[f] + 1]) if full[pos[f] + 1] else JPEND[n]) - jp_addr(f) for f in gap]
            if lo is not None and hi is not None:
                starts = [a for a in EUF if placed[order[lo]] < a < placed[order[hi]]]
                esz = [eu_next_start(a) - a for a in starts]
                # EU added or removed functions here: line the two up by size (also when the counts happen to
                # agree: EU can drop one function and add another; keep plain order unless that fits much worse)
                pairs = align_sizes(jsz, esz)
                if len(starts) == len(gap):
                    ident = [(i, i) for i in range(len(gap))]
                    c_id = sum(abs(jsz[i] - esz[i]) for i in range(len(gap)))
                    c_al = sum(abs(jsz[a] - esz[b]) if a is not None and b is not None else (jsz[a] if a is not None else esz[b]) for a, b in pairs)
                    if not c_al < c_id / 2: pairs = ident
            else:
                # before the first / after the last anchor nothing bounds the count: line JP's functions up
                # against a few more EU starts than needed; extra EU starts past the edge stay outside the file
                if hi is not None:
                    i = bisect.bisect_left(EUF, placed[order[hi]]); starts = EUF[max(0, i - len(gap) - 3):i][::-1]
                    J = jsz[::-1]
                else:
                    i = bisect.bisect_right(EUF, placed[order[lo]]); starts = EUF[i:i + len(gap) + 3]
                    J = jsz
                esz = [eu_next_start(a) - a for a in starts]
                ident = [(k, k) for k in range(min(len(J), len(starts)))]
                cost_ident = sum(abs(J[a] - esz[b]) for a, b in ident) + sum(J[len(starts):])
                pairs, cost = align_sizes(J, esz, free_end=True)
                if not cost < cost_ident / 2: pairs = ident     # only leave the plain order for a much better fit
                if hi is not None:
                    pairs = [(len(gap) - 1 - a if a is not None else None, b) for a, b in pairs][::-1]
                    starts = starts  # indices into the reversed list stay valid
            prev = order[lo] if lo is not None else None
            for ji, ej in pairs:
                if ji is not None and ej is not None:
                    placed[gap[ji]] = starts[ej]; prev = gap[ji]
                elif ej is not None:
                    if prev is None: continue                  # EU-only before the file's first function: outside
                    nm = 'eu_func_%08X' % starts[ej]; placed[nm] = starts[ej]; PEND_EUONLY.append((n, prev, nm))
                else:
                    PEND_JPONLY.append((n, gap[ji])); prev = gap[ji]
        jponly = {f for _, f in PEND_JPONLY}
        wraps = [w for w in wraps if w not in jponly]
        # a C function that wasn't an anchor may still be the same code at the place it ended up: keep it C
        cf = {f[0]: f for f in cfuncs}
        wraps = [w for w in wraps if not (w in placed and same_code_at(cf[w], placed[w]))]
    # references from the C functions that are the same in EU
    refs, sec_start, own_refs = {}, collections.defaultdict(set), collections.defaultdict(set)
    for name, fstart, objw, relocs in cfuncs:
        if name in wraps or name not in placed: continue
        base, pend = placed[name], {}
        frefs, differs = {}, False
        for off, typ, sym in relocs:
            if sym == '.text': continue
            if sym.startswith('.') and sym not in ('.data', '.rodata'): return None, None, None, None, 'reloc against ' + sym
            w, ow = eu_word(base + off - fstart), objw[off]
            if typ == 'R_MIPS_HI16': pend[sym] = ((w & 0xFFFF) << 16, (ow & 0xFFFF) << 16); continue
            if typ == 'R_MIPS_LO16':
                if sym not in pend: return None, None, None, None, 'LO16 without HI16 ' + sym
                addr = (pend[sym][0] + s16(w & 0xFFFF)) - (pend[sym][1] + s16(ow & 0xFFFF))
            elif typ == 'R_MIPS_26':
                addr = (((base + off - fstart + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)) - ((ow & 0x3FFFFFF) << 2)
            else:
                continue
            if sym in ('.data', '.rodata') or sym in symsec:
                sec, soff = (sym, 0) if sym.startswith('.') else symsec[sym]
                sec_start[sec].add(addr - soff); own_refs[sec].add(addr)
                if not sym.startswith('.'): refs[sym] = addr
                continue
            # the same instruction pointing at something else than other code says (or than this file's other
            # functions say): the C function differs in EU after all (call/variable targets are masked when the
            # code is compared). EU takes it from its own assembly.
            if names.get(sym, addr) != addr or refs.get(sym, addr) != addr or frefs.setdefault(sym, addr) != addr:
                differs = True; break
        if differs: wraps.append(name); continue
        refs.update(frefs)
    dsegs = []
    lo, hi = min(placed.values()), eu_next_start(max(placed.values()))
    for s_ in own:
        Z, Sjp = JPDATA[(n, s_)], JPSTART[(n, s_)]
        alo, ahi = (DATA0 + 0x100000, RODATA0 + 0x100000) if s_ == '.data' else (RODATA0 + 0x100000, END0 + 0x100000)
        # 1. a JP-named piece (INCLUDE_RODATA) that the C refers to fixes the start exactly
        c1 = {refs[x] - (jp_addr(x) - Sjp) for x in (rodsyms if s_ == '.rodata' else []) if x in refs and jp_addr(x)}
        # 2. otherwise: the lowest address in this area that the file's EU code loads
        scan = eu_code_refs(lo, hi, alo, ahi)
        if len(c1) > 1: return None, None, None, None, s_ + ' start: INCLUDE_RODATA names disagree'
        if c1: S = c1.pop()
        elif len(sec_start.get(s_, ())) == 1 and not rodsyms and secsize.get(s_, 0) and Z - secsize[s_] < 16:
            S = next(iter(sec_start[s_]))          # the C defines all of it
        elif scan: S = scan[0]
        else: return None, None, None, None, s_ + ' start unknown'
        inside = [x for x in scan if S <= x < S + Z]
        if any(not (S <= x < S + Z) for x in own_refs.get(s_, ())): return None, None, None, None, s_ + ': a C reference falls outside the piece'
        if secsize.get(s_, 0):
            b_, rel = section_bytes(o, s_)
            base0 = 0x80 + S - 0x100000
            ok_k = [k for k in range(0, Z - len(b_) + 1, 4)
                    if all(i in rel or b_[i:i + 4] == d[base0 + k + i:base0 + k + i + len(b_[i:i + 4])] for i in range(0, len(b_), 4))]
            # where the C's part sits inside the piece: consistent with every C reference to its named data
            ok_k = [k for k in ok_k if all(refs[x] == S + k + so for x, (ss, so) in symsec.items() if ss == s_ and x in refs)]
            if not ok_k: return None, None, None, None, s_ + ': the C data is not inside the EU piece'
            if len(ok_k) > 1 and Z - len(b_) < 16: ok_k = [min(ok_k)]   # C fills the piece; the rest is padding
            if len(ok_k) > 1: return None, None, None, None, s_ + ': the C data fits several places in the EU piece'
            for x, (ss, so) in symsec.items():
                if ss == s_: refs[x] = S + ok_k[0] + so
        dsegs.append((S - 0x100000, s_, n, Z))
        if s_ == '.rodata':
            for x in rodsyms: refs[x] = S + (jp_addr(x) - Sjp)
            # keep these where the C file puts them: splat would otherwise move rodata used only by an
            # EU-assembly function into that function's file, out of order and twice
            NOMIGRATE.update(rodsyms); NOMIGRATE.update(x for x, (ss, _) in symsec.items() if ss == '.rodata')
    return placed, refs, wraps, dsegs, None

names, problems, segs, dsegs, wraps = {}, [], [], [], []
EUONLY, JPONLY = [], []
for n in plan:
    del PEND_EUONLY[:]; del PEND_JPONLY[:]
    placed, refs, w, ds, prob = place_file(n)
    if prob: problems.append((n, prob)); continue
    EUONLY.extend(PEND_EUONLY); JPONLY.extend(PEND_JPONLY)
    clash = [k for k, v in list(placed.items()) + list(refs.items()) if names.get(k, v) != v]
    if clash: problems.append((n, 'disagrees with an earlier file about ' + clash[0])); continue
    names.update(placed); names.update(refs)
    segs.append((min(placed.values()) - 0x100000, eu_next_start(max(placed.values())) - 0x100000, n))
    dsegs.extend(ds); wraps.extend((n, f) for f in w)

# Window pass: a run of unplaced JP C files with placed files right before and after it in JP's layout.
# If EU has exactly as many function starts between those two as JP has functions in the run, the run's
# functions take them in order; each C function is then checked against the EU code at its new place.
jptext = []
for o_, t_, nm_ in _js:
    if t_ in ('data', '.data', 'rodata', '.rodata'): break
    if t_ in ('c', 'asm', 'hasm'): jptext.append((t_, nm_))
def file_funcs(n):
    o = os.path.join(OBJ, n.replace('/', '__') + '.o')
    srcp = os.path.join(R, 'src', n + '.c')
    if not os.path.exists(o) or not os.path.exists(srcp): return None
    fl = [f[0] for f in parse_functions(o)] + re.findall(r'INCLUDE_ASM\(\s*"[^"]+"\s*,\s*(\w+)\s*\)', open(srcp, encoding='utf-8', errors='replace').read())
    fl = [f for f in fl if not f.startswith('eu_')]
    if not fl or any(jp_addr(f) is None for f in fl): return None
    return sorted(set(fl), key=jp_addr)
def jp_sizes(n, fl):
    full = fl + [None]
    return [(jp_addr(full[i + 1]) if full[i + 1] else JPEND[n]) - jp_addr(f) for i, f in enumerate(fl)]

def try_run(run, starts, mode):
    """Place a run of JP C files on EU function starts by lining up sizes.
    mode 'both': starts are exactly the window between two placed files;
    'left' / 'right': only that side is placed, starts run outwards from it (a few more than needed)."""
    fls = [file_funcs(n) for n in run]
    if not all(fls): return ['no function list']
    J, owner = [], []
    for n, fl in zip(run, fls):
        for f, z in zip(fl, jp_sizes(n, fl)): J.append(z); owner.append((n, f))
    st = starts[::-1] if mode == 'right' else starts
    Jx = J[::-1] if mode == 'right' else J
    E = [eu_next_start(a) - a for a in st]
    if mode == 'both':
        pairs = align_sizes(Jx, E)
        if len(E) == len(Jx):
            ident = [(i, i) for i in range(len(Jx))]
            c_id = sum(abs(Jx[i] - E[i]) for i in range(len(Jx)))
            c_al = sum(abs(Jx[a] - E[b]) if a is not None and b is not None else (Jx[a] if a is not None else E[b]) for a, b in pairs)
            if not c_al < c_id / 2: pairs = ident
    else:
        pairs, _ = align_sizes(Jx, E, free_end=True)
    cost = sum(abs(Jx[a] - E[b]) if a is not None and b is not None else (Jx[a] if a is not None else E[b]) for a, b in pairs)
    if cost > 0.1 * sum(J): return ['sizes do not fit (%#x of %#x)' % (cost, sum(J))]
    if mode == 'right':
        pairs = [(len(J) - 1 - a if a is not None else None, len(st) - 1 - b if b is not None else None) for a, b in pairs][::-1]
    forced = {n: {} for n in run}; euonly = {n: [] for n in run}; prev = None
    for a, b in pairs:
        if a is not None and b is not None:
            n, f = owner[a]; forced[n][f] = starts[b]; prev = (n, f)
        elif b is not None:
            if prev is None: continue                       # before the run's first function: outside
            nm = 'eu_func_%08X' % starts[b]; forced[prev[0]][nm] = starts[b]; euonly[prev[0]].append((prev[1], nm))
        else:
            prev = owner[a]                                  # JP-only: left out of forced
    msgs = []
    for n in run:
        if not forced[n]: msgs.append('%s: nothing placed' % n); continue
        FORCED_EUONLY[n] = euonly[n]
        del PEND_EUONLY[:]; del PEND_JPONLY[:]
        placed, refs, w, ds, prob = place_file(n, forced[n])
        if prob: problems.append((n, 'window: ' + prob)); continue
        clash = [x for x, v in list(placed.items()) + list(refs.items()) if names.get(x, v) != v]
        if clash: problems.append((n, 'window: disagrees about ' + clash[0])); continue
        names.update(placed); names.update(refs)
        segs.append((min(placed.values()) - 0x100000, eu_next_start(max(placed.values())) - 0x100000, n))
        dsegs.extend(ds); wraps.extend((n, f) for f in w)
        EUONLY.extend(PEND_EUONLY); JPONLY.extend(PEND_JPONLY)
        msgs.append(None)
    return msgs

windows_tried, progress = set(), True
while progress:
    progress = False
    where = {n: (a, b) for a, b, n in segs}
    def unplaced_c(k):
        return jptext[k][0] == 'c' and jptext[k][1] not in where and not jptext[k][1].startswith('lib/')
    i = 0
    while i < len(jptext):
        if not unplaced_c(i): i += 1; continue
        j = i
        while j < len(jptext) and unplaced_c(j): j += 1
        run = [jptext[k][1] for k in range(i, j)]
        left = jptext[i - 1][1] if i > 0 and jptext[i - 1][0] == 'c' and jptext[i - 1][1] in where else None
        right = jptext[j][1] if j < len(jptext) and jptext[j][0] == 'c' and jptext[j][1] in where else None
        key = (tuple(run), left, right)
        if key not in windows_tried and (left or right):
            windows_tried.add(key)
            fls = [file_funcs(n) for n in run]
            need = sum(len(f) for f in fls if f) + 5
            if left and right:
                lo, hi = where[left][1] + 0x100000, where[right][0] + 0x100000
                res = try_run(run, [a for a in EUF if lo <= a < hi], 'both')
            elif left:
                lo = where[left][1] + 0x100000
                k0 = bisect.bisect_left(EUF, lo); res = try_run(run, EUF[k0:k0 + need], 'left')
            else:
                hi = where[right][0] + 0x100000
                k0 = bisect.bisect_left(EUF, hi); res = try_run(run, EUF[max(0, k0 - need):k0], 'right')
            if any(r is None for r in res): progress = True
            for r in res:
                if r: problems.append((run[0], 'window: ' + r))
        i = j
placed_now = {n for _, _, n in segs}
problems[:] = [p for p in problems if p[0] not in placed_now]

segs.sort(); dsegs.sort()
for (a, b, n), (c, _, m) in zip(segs, segs[1:]):
    if b > c: problems.append((n, 'overlaps ' + m))
for (a, s, n, z), (c, _, m, _) in zip(dsegs, dsegs[1:]):
    if a + z > c: problems.append((n, '%s overlaps %s' % (s, m)))

# EU symbols whose auto-name (func_XXXXXXXX) would clash with a JP name now elsewhere
used, euset = set(names.values()), set(EUF)
for nm in list(names):
    m = re.match(r'(func|D|jtbl)_([0-9A-F]{8})$', nm)
    if not m: continue
    a = int(m.group(2), 16)
    # never inside a C file's own data piece: a new symbol there splits off bytes the C file doesn't include
    in_piece = any(o + 0x100000 < a < o + 0x100000 + z for o, _, _, z in dsegs)
    if a != names[nm] and a not in used and not in_piece and (m.group(1) != 'func' or a in euset):
        names['eu_%s_%08X' % (m.group(1), a)] = a; used.add(a)
byaddr = collections.defaultdict(list)
for nm, a in names.items(): byaddr[a].append(nm)
for a, nms in byaddr.items():
    if len(nms) > 1: problems.append(('names', 'same EU address %#x: %s' % (a, ', '.join(nms))))

# config/kh.eu.yaml
lines, p = ['  - [ 0x0, asm, crt0 ]'], 0x1d8
for a, b, n in segs:
    if a > p: lines.append('  - [ %#x, asm ]' % p)
    lines.append('  - [ %#x, c, %s ]' % (a, n)); p = b
if p < TEXT_END: lines.append('  - [ %#x, asm ]' % p)
def area(lo, hi, filler):
    out, q = [], lo
    for a, s, n, z in dsegs:
        if not lo <= a < hi: continue
        if a > q: out.append('  - [ %#x, %s ]' % (q, filler))
        out.append('  - [ %#x, %s, %s ]' % (a, s, n)); q = a + z
    if q < hi: out.append('  - [ %#x, %s ]' % (q, filler))
    return out
dl = (['  ## .data section ##', '  # Code ends with a tail call at 0x26d61c and nop padding; VU microcode / DMA data follows.']
      + area(DATA0, RODATA0, 'data') + ['', '  ## .rodata section ##',
      '  # Starts like JP\'s: xbeginning\'s jump table (0x20), then xporcupine\'s ".img"/".bin" (0x10). JP: 0x386950.']
      + area(RODATA0, END0, 'rodata'))
y = open(os.path.join(R, 'config/kh.eu.yaml'), encoding='utf-8').read()
ts, te = '  # --- text: generated by eu-notes/gen_eu_c.py ---\n', '  # --- end of generated text ---\n'
y = y[:y.index(ts) + len(ts)] + '\n'.join(lines) + '\n' + y[y.index(te):]
ds, de = '  ## .data section ##', '- [ 0x38da30 ]'
y = y[:y.index(ds)] + '\n'.join(dl) + '\n' + y[y.index(de):]
if 'config/eu/jp_names.txt' not in y:
    y = y.replace('  - config/eu/lib_symbol_addrs.txt\n', '  - config/eu/lib_symbol_addrs.txt\n  - config/eu/jp_names.txt\n')
open(os.path.join(R, 'config/kh.eu.yaml'), 'w', encoding='utf-8', newline='\n').write(y)

# names outside the program and its bss (hardware/scratch addresses) are absolute: undefined_syms.txt
PROG_END = 0x66D5D8
absolute = {nm: a for nm, a in names.items() if not 0x100000 <= a < PROG_END}
for nm in absolute: del names[nm]
with open(os.path.join(R, 'config/eu/undefined_syms.txt'), 'w', newline='\n') as f:
    for nm, a in sorted(absolute.items(), key=lambda t: t[1]): f.write('%s = 0x%08X;\n' % (nm, a))
with open(os.path.join(R, 'config/eu/jp_names.txt'), 'w', newline='\n') as f:
    f.write('// JP names at their EU addresses, for the C files that build for EU. Generated by eu-notes/gen_eu_c.py.\n')
    for nm, a in sorted(names.items(), key=lambda t: t[1]):
        kind = ' // type:func' if a < 0x100000 + TEXT_END and not nm.startswith(('D_', 'jtbl_')) else ''
        if not kind and SIZES.get(nm): kind = ' // size:0x%X' % SIZES[nm]
        if nm in NOMIGRATE: kind = (kind or ' //') + ' force_not_migration:True'
        f.write('%-32s = 0x%08X;%s\n' % (nm, a, kind))
with open(os.path.join(R, 'eu-notes/eu_wrap.tsv'), 'w', newline='\n') as f:
    for n, fn in wraps: f.write('%s\t%s\n' % (n, fn))
with open(os.path.join(R, 'eu-notes/eu_only.tsv'), 'w', newline='\n') as f:
    for n, prev, nm in EUONLY: f.write('%s\t%s\t%s\n' % (n, prev, nm))
with open(os.path.join(R, 'eu-notes/jp_only.tsv'), 'w', newline='\n') as f:
    for n, fn in JPONLY: f.write('%s\t%s\n' % (n, fn))
print('EU-only functions: %d   JP-only functions: %d' % (len(EUONLY), len(JPONLY)))
print('C files placed: %d   names mapped: %d   C functions EU takes from assembly: %d' % (len(segs), len(names), len(wraps)))
for p in problems: print('  skipped/problem:', *p)
