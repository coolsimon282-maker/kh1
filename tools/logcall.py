#!/usr/bin/env python3
"""Record one agent-tools.sh call for the training set:   logcall.py <exit code> <start epoch> <output file> <args...>
Appends to kh1-study/dataset/calls/<workspace>.jsonl: time, worker, command, args, exit code, seconds, and the
full output the worker saw (the job packet from `next`, an m2c draft, the look-alike functions, a comparison, a
build verdict...). `lesson` calls also go to dataset/lessons/<workspace>.jsonl. Errors here are swallowed."""
import json, os, sys, time
try:
    rc, t0, tmp, args = sys.argv[1], float(sys.argv[2]), sys.argv[3], sys.argv[4:]
    root = os.getcwd()
    while root != os.path.dirname(root) and not os.path.isdir(os.path.join(root, 'kh1-decomp')): root = os.path.dirname(root)
    if os.path.isdir(os.path.join(root, 'kh1-decomp')) and args:
        out = open(tmp, encoding='utf-8', errors='replace').read()
        worker = os.path.basename(os.getcwd())
        rec = {'time': time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(t0)), 'worker': worker, 'cmd': args[0], 'args': args[1:],
               'rc': int(rc), 'secs': round(time.time() - t0, 1), 'output': out[-80000:]}
        for sub in (['calls'] + (['lessons'] if args[0] == 'lesson' else [])):
            d = os.path.join(root, 'dataset', sub); os.makedirs(d, exist_ok=True)
            with open(os.path.join(d, worker + '.jsonl'), 'a', encoding='utf-8', newline='\n') as o:
                o.write(json.dumps(rec, ensure_ascii=False) + '\n')
except Exception:
    pass
