#!/usr/bin/env python3
"""Keep every matching attempt for a future training set (24 Nov). Called by agent-tools.sh after each quick
check / try / give-up; the check's output comes in on stdin:

    ... | python3 tools/logattempt.py <file> <func> <exit code> <quick|try|giveup> [reason...]

It appends one JSON line to  kh1-study/dataset/attempts/<workspace>.jsonl  (outside the repo, never committed):
  time, worker (workspace name), file, func, kind, result (match / differs / compile_error / gave_up), off / of
  (instructions that differ / compared, when the check printed them), head (the commit the attempt was made on),
  attempt (the uncommitted change to the source file = the C that was tried, as a git diff), target (the function's
  assembly), output (what the check printed: the side-by-side differences or the compiler error), reason (give-ups).
An attempt identical to the worker's previous one for that function is not written twice.
This must never break the tools: any error here is swallowed."""
import hashlib, json, os, re, subprocess, sys, time

def main():
    f, fn, rc, kind = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
    reason = ' '.join(sys.argv[5:])
    out = sys.stdin.read() if not sys.stdin.isatty() else ''
    here = os.getcwd()
    root = here
    while root != os.path.dirname(root) and not os.path.isdir(os.path.join(root, 'kh1-decomp')):
        root = os.path.dirname(root)
    if not os.path.isdir(os.path.join(root, 'kh1-decomp')): return
    d = os.path.join(root, 'dataset', 'attempts'); os.makedirs(d, exist_ok=True)
    git = lambda *a: subprocess.run(['git', *a], capture_output=True, text=True, errors='replace', timeout=30).stdout
    attempt = git('diff', '-U2', '--', 'src/%s.c' % f)
    try: target = open('asm/nonmatchings/%s/%s.s' % (f, fn), errors='replace').read()
    except OSError: target = ''
    m = re.search(r'differs in (\d+) of (\d+) instructions', out) or re.search(r'matches \((\d+) instructions\)', out)
    if kind == 'giveup': result = 'gave_up'
    elif rc == '0': result = 'match'
    elif rc == '2' or 'COMPILE ERROR' in out: result = 'compile_error'
    else: result = 'differs'
    worker = os.path.basename(here)
    rec = {'time': time.strftime('%Y-%m-%d %H:%M:%S'), 'worker': worker, 'file': f, 'func': fn, 'kind': kind, 'result': result,
           'off': int(m.group(1)) if m and 'differs' in m.group(0) else (0 if result == 'match' else None),
           'of': int(m.group(2)) if m and 'differs' in m.group(0) else (int(m.group(1)) if m else None),
           'head': git('rev-parse', '--short', 'HEAD').strip(), 'attempt': attempt, 'target': target,
           'output': out[-12000:], 'reason': reason}
    key = hashlib.md5((fn + kind + attempt + result).encode('utf-8', 'replace')).hexdigest()
    last = os.path.join(d, '.last_' + worker)
    try:
        if kind != 'giveup' and open(last).read() == key: return
    except OSError: pass
    with open(os.path.join(d, worker + '.jsonl'), 'a', encoding='utf-8', newline='\n') as o:
        o.write(json.dumps(rec, ensure_ascii=False) + '\n')
    open(last, 'w').write(key)

try: main()
except Exception: pass
