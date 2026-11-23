"""Compare models on solve time per function.

agent-tools.sh writes one line to qwen/times.tsv in its workspace whenever a job handed out by `next` is matched or
given up (time counted from `next`; the model name comes from qwen/.model). This reads every workspace's log and
prints, per model, how many it matched and how long it took, then the functions more than one model has tried
side by side.   python eu-notes/solve_times.py [--all]   (--all lists every function, not just the shared ones)
"""
import csv, glob, os, sys
from collections import defaultdict

root = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'kh1-wt')
rows = []
for f in sorted(glob.glob(os.path.join(root, '*', 'qwen', 'times.tsv'))):
    for r in csv.DictReader(open(f, encoding='utf-8', errors='replace'), delimiter='\t'):
        try:
            r['seconds'] = int(r['seconds']); r['bytes'] = int(r['bytes'])
        except (ValueError, TypeError):
            continue
        r['ok'] = r['result'] == 'matched'
        rows.append(r)

def mmss(s):
    return '%d:%02d' % (s // 60, s % 60)

def median(v):
    v = sorted(v); n = len(v)
    return 0 if not n else v[n // 2] if n % 2 else (v[n // 2 - 1] + v[n // 2]) // 2

by_model = defaultdict(list)
for r in rows:
    by_model[r['model']].append(r)
print('%-34s %7s %8s %10s %10s %10s %12s' % ('model', 'matched', 'gave up', 'median ok', 'mean ok', 'mean fail', 'bytes/hour'))
for m, rs in sorted(by_model.items()):
    ok = [r for r in rs if r['ok']]; bad = [r for r in rs if not r['ok']]
    total = sum(r['seconds'] for r in rs)
    print('%-34s %7d %8d %10s %10s %10s %12s' % (
        m[:34], len(ok), len(bad), mmss(median([r['seconds'] for r in ok])) if ok else '-',
        mmss(sum(r['seconds'] for r in ok) // len(ok)) if ok else '-',
        mmss(sum(r['seconds'] for r in bad) // len(bad)) if bad else '-',
        '%d' % (sum(r['bytes'] for r in ok) * 3600 // total) if total else '-'))
print('(bytes/hour = bytes of matched code per hour of model time, give-ups included)')

by_func = defaultdict(dict)
for r in rows:
    by_func[(r['bytes'], r['function'])][r['model']] = r     # the latest result per model
models = sorted(by_model)
shared = {k: v for k, v in by_func.items() if len(v) > 1 or '--all' in sys.argv}
if shared:
    print()
    print('%-16s %6s  ' % ('function', 'bytes') + '  '.join('%-24s' % m[:24] for m in models))
    for (b, fn), res in sorted(shared.items()):
        cells = []
        for m in models:
            r = res.get(m)
            cells.append('%-24s' % ('' if not r else '%s %s (%s tries)' % ('ok  ' if r['ok'] else 'FAIL', mmss(r['seconds']), r['tries'])))
        print('%-16s %6d  ' % (fn, b) + '  '.join(cells))
