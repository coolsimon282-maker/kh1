#!/usr/bin/env python3
"""What the workers' logs say (run on Windows from the main checkout):   python eu-notes/log_analysis.py

Reads every workspace's qwen/times.tsv (one line per finished function: seconds, tries, result) and the rented
workers' session logs (qwen/sessions-all.log), and prints: match rate by size and by try number, where the time
goes, why functions are given up, and which errors recur in the sessions."""
import collections, csv, glob, os, re
ks = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
rows = []
for f in glob.glob(os.path.join(ks, 'kh1-wt', '*', 'qwen', 'times.tsv')):
    w = f.split(os.sep)[-3]
    if w.startswith('bench'): continue
    for r in csv.DictReader(open(f, encoding='utf-8', errors='replace'), delimiter='\t'):
        try: r['seconds'] = int(r['seconds']); r['bytes'] = int(r['bytes'])
        except (ValueError, TypeError): continue
        r['w'] = w; r['ok'] = r['result'] == 'matched'; rows.append(r)
def mmss(s): return '%d:%02d' % (s // 60, s % 60)
print('%d finished functions logged (%d matched)\n' % (len(rows), sum(r['ok'] for r in rows)))

print('== by worker ==')
for w in sorted({r['w'] for r in rows}):
    rs = [r for r in rows if r['w'] == w]; ok = [r for r in rs if r['ok']]; bad = [r for r in rs if not r['ok']]
    tot = sum(r['seconds'] for r in rs)
    print('%-4s %3d matched of %3d (%2d%%) | avg match %s | avg give-up %s | %2d%% of its time went on give-ups | %d bytes matched per hour' % (
        w, len(ok), len(rs), 100 * len(ok) // len(rs), mmss(sum(r['seconds'] for r in ok) // max(1, len(ok))),
        mmss(sum(r['seconds'] for r in bad) // max(1, len(bad))), 100 * sum(r['seconds'] for r in bad) // max(1, tot),
        sum(r['bytes'] for r in ok) * 3600 // max(1, tot)))

print('\n== by size ==')
for lo, hi in ((0, 32), (33, 64), (65, 128), (129, 192), (193, 256), (257, 9999)):
    rs = [r for r in rows if lo <= r['bytes'] <= hi]
    if rs: print('%4d-%-4d bytes: %3d matched of %3d (%2d%%)' % (lo, hi, sum(r['ok'] for r in rs), len(rs), 100 * sum(r['ok'] for r in rs) // len(rs)))

print('\n== matches by try number ==')
c = collections.Counter(r['tries'] for r in rows if r['ok'])
for k in sorted(c): print('  try %s: %d' % (k, c[k]))
print('  give-ups after 0 tries (never submitted anything): %d of %d give-ups' % (
    sum(1 for r in rows if not r['ok'] and r['tries'] == '0'), sum(1 for r in rows if not r['ok'])))

print('\n== why functions are given up ==')
def reason(t):
    t = t.replace('gave up: ', '').lower()
    for k, v in (('3 failed tries', '3 failed tries (automatic)'), ('time limit', 'time limit (12 minutes, tool)'), ('session ended', 'session ended without a result'),
                 ('moved on', 'moved on without matching'), ('vu0', 'vector (VU0) instructions'), ('lqc2', 'vector (VU0) instructions'), ('vector', 'vector (VU0) instructions'),
                 ('ldl', 'unaligned loads (ldl/ldr)'), ('ldr', 'unaligned loads (ldl/ldr)'), ('compil', 'compile errors it could not fix'), ('declar', 'declaration / prototype trouble'),
                 ('prototype', 'declaration / prototype trouble'), ('conflict', 'declaration / prototype trouble'), ('bnel', 'branch-likely'), ('beql', 'branch-likely'),
                 ('register', 'register allocation'), ('cannot be expressed', 'says "cannot be written in C"'), ('cannot emit', 'says "cannot be written in C"'),
                 ('hand', 'hand-written assembly'), ('jump table', 'jump table'), ('break', 'trap / break instruction'), ('float', 'floating point shape')):
        if k in t: return v
    return 'other: ' + t[:50]
rc = collections.Counter(); rt = collections.Counter()
for r in rows:
    if not r['ok']: k = reason(r['result']); rc[k] += 1; rt[k] += r['seconds']
for k, n in rc.most_common(14): print('  %3d  %-42s %5d min in total' % (n, k, rt[k] // 60))

print('\n== rented workers: recurring problems in the session logs ==')
pats = [('COMPILE ERROR', r'COMPILE ERROR'), ('conflicting types', r'conflicting types'), ('undeclared identifier', r'undeclared \(first use'), ('parse error', r'parse error'),
        ('Permission denied (OpenCode)', r'Permission denied'), ('connection reset', r'ECONNRESET'), ('same code resubmitted', r'SAME CODE'), ('STOPPED (other uncommitted C)', r'^STOPPED'),
        ('tool time limit hit', r'TIME UP'), ('auto give-up after 3 tries', r'GAVE UP AUTOMATICALLY'), ('read the tools script (wandering)', r'Read agent-tools\.sh'),
        ('ran git log/status (wandering)', r'\$ .*git (log|status)'), ('grep over src (wandering)', r'\$ .*grep -r'), ('quick check says matches', r'QUICK CHECK: \w+ matches'),
        ('image differs although function matches', r"own code matches but the whole image"), ('MATCHED', r'^MATCHED')]
for f in sorted(glob.glob(os.path.join(ks, 'kh1-wt', 'r*', 'qwen', 'sessions-all.log'))):
    t = re.sub(r'\x1b\[[0-9;]*m', '', open(f, encoding='utf-8', errors='replace').read())
    print(' ', f.split(os.sep)[-3] + ':', ', '.join('%s=%d' % (n, len(re.findall(p, t, re.M))) for n, p in pats if re.search(p, t, re.M)))
