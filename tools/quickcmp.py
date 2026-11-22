#!/usr/bin/env python3
"""Fast check of one function without a full build (about 3 s): compile src/<file>.c alone with the game's real
pipeline and compare the function's bytes with its target assembly. Run from the repo root in the build mirror:
    python3 tools/quickcmp.py <file e.g. xpotato> <func> [lines=40]
Exit 0 = the function's code matches (relocated words compared without their addresses, so ALWAYS confirm with a
real build before committing); 1 = differs (prints target | yours); 2 = compile error."""
import os, re, struct, subprocess, sys
f, fn = sys.argv[1], sys.argv[2]; lines = int(sys.argv[3]) if len(sys.argv) > 3 else 40
conf = open('configure.py').read()
def lst(name):
    m = re.search(name + r'\s*=\s*\[(.*?)\]', conf, re.S); return re.findall(r'"([^"]+)"', m.group(1)) if m else []
base = f.split('/')[-1] + '.c'
g = '' if base in lst('NO_G_FILES') else '-g'
cf = '' if base in lst('STRICT_ALIASING_FILES') else '-fno-strict-aliasing'
os.makedirs('/tmp/qc', exist_ok=True); obj = '/tmp/qc/%d.o' % os.getpid()
cc = ['tools/cc/ee-gcc2.96/bin/ee-gcc', '-c', '-B', 'tools/cc/ee-gcc2.96/bin/ee-', '-Iinclude', '-isystem', 'include/sdk/ee',
      '-isystem', 'include/gcc', '-DVERSION_FM', '-O2', '-G0'] + ([g] if g else []) + ([cf] if cf else []) + ['src/%s.c' % f, '-S', '-o', '-']
p1 = subprocess.run(cc, capture_output=True)
if p1.returncode:
    print(p1.stderr.decode(errors='replace')[-1500:]); print('COMPILE ERROR'); sys.exit(2)
p2 = subprocess.run(['python3', 'tools/masps2.py'], input=p1.stdout, capture_output=True, env=dict(os.environ, MASPS2_NO_NOPS='1'))
open(obj + '.s', 'wb').write(p2.stdout)
p3 = subprocess.run(['tools/cc/ee-gcc2.96/ee/bin/as', '-O2', '-G0'] + ([g] if g else []) + ['-EL', '-mabi=eabi', obj + '.s', '-o', obj], capture_output=True)
if p3.returncode:
    print(p3.stderr.decode(errors='replace')[-800:]); print('COMPILE ERROR'); sys.exit(2)
run = lambda *a: subprocess.run(a, capture_output=True, text=True).stdout
syms = {}
for l in run('mips-linux-gnu-nm', '-S', obj).splitlines():
    p = l.split()
    if len(p) == 4: syms[p[3]] = (int(p[0], 16), int(p[1], 16))
rel = {}; sec = None
for l in run('mips-linux-gnu-readelf', '-r', obj).splitlines():
    m = re.match(r"Relocation section '\.rel\.?(\S+)'", l)
    if m: sec = m.group(1); continue
    m = re.match(r'^([0-9a-f]{8})\s+\S+\s+(R_MIPS_\S+)', l)
    if m and sec == 'text': rel[int(m.group(1), 16)] = m.group(2)
text = subprocess.run(['mips-linux-gnu-objcopy', '-O', 'binary', '--only-section=.text', obj, '/dev/stdout'], capture_output=True).stdout
dis = {}
for l in run('mips-linux-gnu-objdump', '-d', '-z', '-M', 'no-aliases', obj).splitlines():
    m = re.match(r'^\s+([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)', l)
    if m: dis[int(m.group(1), 16)] = m.group(2)
for x in (obj, obj + '.s'):
    try: os.remove(x)
    except OSError: pass
tw, tt = [], []
for l in open('asm/nonmatchings/%s/%s.s' % (f, fn)):
    m = re.match(r'\s+/\* \w+ \w+ ([0-9A-F]{8}) \*/\s+(.*)', l)
    if m: tw.append(struct.unpack('<I', bytes.fromhex(m.group(1)))[0]); tt.append(m.group(2).strip())
while tw and tw[-1] == 0 and len(tw) * 4 > syms.get(fn, (0, 0))[1]: tw.pop(); tt.pop()   # alignment padding after the function
if fn not in syms:
    print('%s is not defined in the compiled file' % fn); sys.exit(2)
off, sz = syms[fn]
def mask(w, rt): return w if rt is None else (w & 0xFC000000 if '26' in rt else w & 0xFFFF0000)
n = max(len(tw), sz // 4); bad = 0; out = []
for i in range(n):
    a = off + i * 4
    mw = struct.unpack('<I', text[a:a + 4])[0] if i * 4 < sz else None
    t = tw[i] if i < len(tw) else None
    same = mw is not None and t is not None and mask(mw, rel.get(a)) == mask(t, rel.get(a))
    bad += not same
    out.append('%s %4x  %-44.44s | %s' % ('  ' if same else '!!', i * 4, tt[i] if t is not None else '-', dis.get(a, '-').replace('\t', ' ') if mw is not None else '-'))
if bad == 0:
    print('QUICK CHECK: %s matches (%d instructions)' % (fn, n)); sys.exit(0)
print('QUICK CHECK: %s differs in %d of %d instructions (size: target %#x, yours %#x). target | yours:' % (fn, bad, n, len(tw) * 4, sz))
shown = [k for k, l in enumerate(out) if l.startswith('!!')]
keep = sorted({j for k in shown for j in range(max(0, k - 2), min(n, k + 3))})[:lines]
print('\n'.join(out[k] for k in keep)); sys.exit(1)
