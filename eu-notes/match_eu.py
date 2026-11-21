# For each compiled function, look for its exact code in the EU program, ignoring the address bits that
# the linker fills in (relocations). Prints a summary and writes eu_matches.tsv.
import subprocess, struct, glob, os, re, collections, sys
ELF = '/mnt/c/Users/you/Downloads/Kingdom Hearts (Europe)/extracted/SCES_509.67'
d = open(ELF, 'rb').read()
BASE, OFF, SIZE = 0x100000, 0x80, 0x38da30
eu = list(struct.unpack_from('<%dI' % (SIZE // 4), d, OFF))
index = collections.defaultdict(list)
for i, w in enumerate(eu): index[w].append(i)
MASK = {'R_MIPS_26': 0xFC000000, 'R_MIPS_HI16': 0xFFFF0000, 'R_MIPS_LO16': 0xFFFF0000}
rows = []
for o in sorted(glob.glob(os.path.expanduser('~/kh1-test/obj/*.o'))):
    dump = subprocess.run(['mips-linux-gnu-objdump', '-d', '-r', '-z', o], capture_output=True, text=True).stdout
    funcs, cur = [], None
    for line in dump.splitlines():
        m = re.match(r'^([0-9a-f]{8}) <(\S+)>:', line)
        if m: cur = [m.group(2), [], []]; funcs.append(cur); continue
        if cur is None: continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s', line)
        if m: cur[1].append(int(m.group(2), 16)); cur[2].append(0xFFFFFFFF); continue
        m = re.match(r'^\s+[0-9a-f]+:\s+(R_MIPS_\w+)', line)
        if m and cur[1]: cur[2][-1] = MASK.get(m.group(1), 0)
    for name, words, masks in funcs:
        if not words or name.startswith('.'): continue
        while len(words) > 1 and words[-1] == 0 and masks[-1] == 0xFFFFFFFF: words.pop(); masks.pop()  # padding
        k = next((j for j, m in enumerate(masks) if m == 0xFFFFFFFF and words[j] not in (0, 0x03E00008)), None)
        hits = []
        if k is not None:
            for p in index.get(words[k], []):
                s = p - k
                if s >= 0 and s + len(words) <= len(eu) and all((eu[s + j] & masks[j]) == (words[j] & masks[j]) for j in range(len(words))):
                    hits.append(BASE + 4 * s)
        rows.append((os.path.basename(o)[:-2], name, len(words), hits))
# Several hits: pick the one nearest the shift of the closest unique neighbour in the same file.
SYM = {}
for sf in ['config/jp/symbol_addrs.txt', 'config/jp/lib_symbol_addrs.txt']:
    for m in re.finditer(r'^(\w+)\s*=\s*0x([0-9A-Fa-f]+);', open('/mnt/c/Users/you/psp-learning/kh1-study/kh1-decomp/' + sf).read(), re.M):
        SYM[m.group(1)] = int(m.group(2), 16)
def jpaddr(n):
    if re.match(r'func_[0-9A-F]{8}$', n): return int(n[5:13], 16)
    return SYM.get(n)
uniq = {}
for fl, n, ln, h in rows:
    if len(h) == 1 and jpaddr(n): uniq.setdefault(fl, []).append((jpaddr(n), h[0] - jpaddr(n)))
resolved = 0
for r in rows:
    fl, n, ln, h = r
    if len(h) > 1 and jpaddr(n) and uniq.get(fl):
        a = jpaddr(n); sh = min(uniq[fl], key=lambda t: abs(t[0] - a))[1]
        best = min(h, key=lambda x: abs(x - a - sh))
        if abs(best - a - sh) <= 0x100: r[3][:] = [best]; resolved += 1
print('settled by neighbours: %d' % resolved)
found = [r for r in rows if len(r[3]) == 1]; multi = [r for r in rows if len(r[3]) > 1]; none = [r for r in rows if not r[3]]
print('functions compiled: %d' % len(rows))
print('found once in EU (same code): %d   found several times: %d   not found: %d' % (len(found), len(multi), len(none)))
big = [r for r in found if r[2] >= 20]
byfile = collections.Counter(); totfile = collections.Counter()
for fl, n, ln, h in rows:
    totfile[fl.split('__')[0]] += 1
    if len(h) == 1: byfile[fl.split('__')[0]] += 1
print('by folder:', ', '.join('%s %d/%d' % (k, byfile[k], totfile[k]) for k in sorted(totfile, key=lambda k: -totfile[k])[:8]))
print('of the unique finds, %d are 20+ instructions long' % len(big))
with open(os.path.expanduser('~/kh1-test/eu_matches.tsv'), 'w') as f:
    for fl, n, ln, h in rows:
        jp = jpaddr(n) or 0
        f.write('%s\t%s\t%d\t%s\t%s\n' % (fl, n, ln, ','.join('%08X' % x for x in h), ('%+x' % (h[0] - jp)) if len(h) == 1 and jp else ''))
