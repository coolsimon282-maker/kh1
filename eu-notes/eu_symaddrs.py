"""eumap.py: for an EU link made with --unresolved-symbols=ignore-all (/tmp/eu_ign.elf + /tmp/eu_ign.map), work out
the EU address of every undefined symbol from the original EU program: each relocation against an undefined symbol
is read against the original instruction at the same address (HI16/LO16 pairs, R_MIPS_26, R_MIPS_32).
Also reports, per object, how many words differ from the original outside those relocations (layout check).
Run in the WSL mirror (~/kh1-build-a5). Output: /tmp/eumap.tsv (symbol, address, votes, conflicts) and a report."""
import re, struct, subprocess, sys, collections

ORIG = 'SCES_509.67'
import os
ELF = os.environ.get('ELF', '/tmp/eu_ign.elf')
MAP = os.environ.get('MAP', '/tmp/eu_ign.map')
ALL = sys.argv[1] == 'ALL'     # ALL: every symbol; report the ones whose linked value differs from the computed one
undef = set() if ALL else set(l.strip() for l in open(sys.argv[1]) if l.strip())

def load_segments(path):
    out = subprocess.run(['mips-linux-gnu-readelf', '-lW', path], capture_output=True, text=True).stdout
    segs = []
    for l in out.splitlines():
        t = l.split()
        if t and t[0] == 'LOAD':
            off, va, filesz = int(t[1], 16), int(t[2], 16), int(t[4], 16)
            segs.append((va, off, filesz))
    data = open(path, 'rb').read()
    return segs, data

def reader(path):
    segs, data = load_segments(path)
    def rd(addr):
        for va, off, sz in segs:
            if va <= addr < va + sz:
                return struct.unpack_from('<I', data, off + addr - va)[0]
        return None
    return rd

orig = reader(ORIG)
mine = reader(ELF)

# input sections from the map: (section, address, size, object)
secs = []
cur = None
for l in open(MAP):
    m = re.match(r'^ (\.\S+)\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)\s+(\S+\.o)\s*$', l)
    if m:
        secs.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4)))
        continue
    m = re.match(r'^ (\.\S+)\s*$', l)
    if m: cur = m.group(1); continue
    m = re.match(r'^\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)\s+(\S+\.o)\s*$', l)
    if m and cur:
        secs.append((cur, int(m.group(1), 16), int(m.group(2), 16), m.group(3)))
        cur = None

objs = collections.defaultdict(dict)
for s, a, z, o in secs:
    if z and s in ('.text', '.data', '.rodata', '.sdata'):
        objs[o][s] = a

votes = collections.defaultdict(collections.Counter)
where = collections.defaultdict(list)
def sext(v): return v - 0x10000 if v & 0x8000 else v
for o, smap in sorted(objs.items()):
    if '/src/' not in o: continue
    out = subprocess.run(['mips-linux-gnu-readelf', '-rW', o], capture_output=True, text=True).stdout
    sec = None
    rels = collections.defaultdict(list)
    for l in out.splitlines():
        m = re.match(r"Relocation section '\.rel(\.\S+)'", l)
        if m: sec = m.group(1); continue
        t = l.split()
        if len(t) >= 5 and re.fullmatch(r'[0-9a-f]{8}', t[0]) and sec:
            rels[sec].append((int(t[0], 16), t[2], t[4]))
    for sec, rl in rels.items():
        base = smap.get(sec)
        if base is None: continue
        pending = {}
        for off, typ, sym in rl:
            a = base + off
            ow, mw = orig(a), mine(a)
            if ow is None or mw is None: continue
            if not ALL and sym not in undef:
                continue
            if sym.startswith('.') or sym.startswith('$'):
                continue
            if typ == 'R_MIPS_HI16':
                pending[sym] = (ow & 0xFFFF, mw & 0xFFFF); continue
            if typ == 'R_MIPS_LO16':
                if sym not in pending: continue
                oh, mh = pending[sym]
                tgt = ((oh << 16) + sext(ow & 0xFFFF)) - ((mh << 16) + sext(mw & 0xFFFF))
                tgt &= 0xFFFFFFFF
            elif typ == 'R_MIPS_26':
                tgt = (((a + 4) & 0xF0000000) | ((ow & 0x3FFFFFF) << 2)) - ((mw & 0x3FFFFFF) << 2)
                if (ow >> 26) != (mw >> 26): continue
            elif typ == 'R_MIPS_32':
                tgt = (ow - mw) & 0xFFFFFFFF
            else:
                continue
            votes[sym][tgt] += 1
            where[sym].append(o.split('/src/')[-1])

if ALL:
    linked = {}
    for l in subprocess.run(['mips-linux-gnu-nm', ELF], capture_output=True, text=True).stdout.splitlines():
        t = l.split()
        if len(t) == 3: linked[t[2]] = int(t[0], 16)
    with open('/tmp/euwrong.tsv', 'w') as f:
        for s_, c in sorted(votes.items()):
            (best, n), = c.most_common(1)
            if linked.get(s_) != best:
                f.write('\t'.join(['%s', '%s', '0x%08X', '%d', '%s', '%s']) % (s_, '0x%08X' % linked[s_] if s_ in linked else '-', best, n,
                        ' '.join('0x%08X:%d' % (k, v) for k, v in c.items() if k != best), ','.join(sorted(set(where[s_])))) + '\n')
    sys.exit(0)
with open('/tmp/eumap.tsv', 'w') as f:
    for s in sorted(undef):
        c = votes.get(s)
        if not c:
            f.write('%s\t\t0\tNOREF\n' % s); continue
        (best, n), = c.most_common(1)
        f.write('%s\t0x%08X\t%d\t%s\t%s\n' % (s, best, n, ' '.join('0x%08X:%d' % (k, v) for k, v in c.items() if k != best),
                                            ','.join(sorted(set(where[s])))))
print('done', len(votes), 'of', len(undef))
