"""Find unmatched functions whose instruction pattern equals (or nearly equals) an already-matched function's.
Pattern = opcode + register fields per instruction, with 16-bit immediates and jump targets masked (so struct
offsets, globals, constants and callees may differ). Run in WSL from the build mirror after a build:
  python3 find_twins.py <repo-on-/mnt/c> > twins.tsv"""
import glob, os, re, struct, subprocess, sys, collections
REPO = sys.argv[1]
rom = open('SLPS_251.98.rom', 'rb').read()
VRAM = 0x100000

def norm(off, size):
    out = []
    for i in range(off, off + size, 4):
        w = struct.unpack('<I', rom[i:i + 4])[0]
        op = w >> 26
        if op in (2, 3): w &= 0xfc000000                     # j/jal target
        elif op != 0 and op != 0x1c and op != 0x12 and op != 0x11: w &= 0xffff0000   # immediates (not SPECIAL/MMI/COP)
        out.append(w)
    return tuple(out)

# unmatched: from the asm files of INCLUDE_ASM lines in src
unmatched = {}
for c in glob.glob(REPO + '/src/**/*.c', recursive=True):
    s = open(c, encoding='utf-8', errors='replace').read()
    for d, f in re.findall(r'^INCLUDE_ASM\("([^"]+)",\s*(\w+)\);', s, re.M):
        p = os.path.join(d, f + '.s')
        if not os.path.exists(p): continue
        t = open(p, encoding='utf-8', errors='replace').read()
        m = re.search(r'nonmatching \w+, 0x([0-9A-F]+)', t); a = re.search(r'/\* ([0-9A-F]+) [0-9A-F]{8} ', t)
        if m and a:
            unmatched[f] = (int(a.group(1), 16), int(m.group(1), 16), os.path.relpath(c, REPO)[4:-2])
# matched: functions defined in compiled C objects (nm -S gives sizes); exclude the unmatched ones
matched = {}
nm = subprocess.run(['mips-linux-gnu-nm', '-S', 'build/fm/SLPS_251.98.elf'], capture_output=True, text=True).stdout
for line in nm.splitlines():
    p = line.split()
    if len(p) == 4 and p[2] in ('T', 't') and not p[3].endswith('NON_MATCHING') and p[3] not in unmatched:
        a, z = int(p[0], 16), int(p[1], 16)
        if z >= 8 and VRAM <= a < VRAM + 0x14f318: matched[p[3]] = (a - VRAM, z)
bypat = collections.defaultdict(list)
for n, (o, z) in matched.items(): bypat[norm(o, z)].append(n)
bylen = collections.defaultdict(list)
for n, (o, z) in matched.items(): bylen[z].append(n)
pats = {n: norm(o, z) for n, (o, z) in matched.items()}
# where each matched function's C is
where = {}
for c in glob.glob(REPO + '/src/**/*.c', recursive=True):
    s = open(c, encoding='utf-8', errors='replace').read()
    for f in re.findall(r'^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{]*\)\s*\{', s, re.M): where.setdefault(f, os.path.relpath(c, REPO)[4:-2])
rows = []
for f, (o, z, file) in unmatched.items():
    if z < 8: continue
    p = norm(o, z)
    if p in bypat:
        t = bypat[p][0]; rows.append(('exact', z, f, file, t, where.get(t, '?'))); continue
    if z >= 24:   # near: same length, >= 90% of instructions equal
        best = None
        for t in bylen.get(z, []):
            q = pats[t]; same = sum(a == b for a, b in zip(p, q))
            if same >= 0.9 * len(p) and (not best or same > best[0]): best = (same, t)
        if best: rows.append(('near%d' % round(100 * best[0] / len(p)), z, f, file, best[1], where.get(best[1], '?')))
rows.sort(key=lambda r: (r[0] != 'exact', r[1]))
print('kind\tbytes\tunmatched\tits file\tmatched twin\ttwin file')
for r in rows: print('\t'.join(map(str, r)))
print('# %d unmatched functions with an exact twin, %d near twins; %d unmatched, %d matched considered' % (
    sum(r[0] == 'exact' for r in rows), sum(r[0] != 'exact' for r in rows), len(unmatched), len(matched)), file=sys.stderr)
