#!/bin/bash
# Helpers for agents matching functions (Final Mix). Run from the checkout's root folder, from Windows:
#   wsl -e bash ./agent-tools.sh <command> ...
#
#   configure                re-split and build from scratch (once per checkout after tool changes)
#   build                    build FM; the last line must be "build/fm/SLPS_251.98.rom: OK"
#   list <file>              assembly functions left in src/<file>.c, smallest first (size in bytes, name)
#   asm <file> <func>        the function's assembly
#   m2c <file> <func>        a first draft of C for it (m2c, with the file's types as context)
#   diff <func> [lines]      build, then compare the function with the original (default 120 lines)
#   near <file> <func> [n]   the n lines (default 30) before and after the function in src/<file>.c
#   put <file> <func> <cfile>  replace the function's INCLUDE_ASM line in src/<file>.c with the C in <cfile>
#                            (again after a failed try: it starts from the last commit of the file)
#                            (so big files like xhumungus.c never need opening; <cfile> e.g. qwen/work.c)
#   cfunc <func>             print an already-matched function's C (searches all of src/; shows the file too)
#   quick <file> <func>      fast check of one function without a full build (under a second)
#   try <file> <func> <cfile>  put + fast check (+ full build to confirm) in one step; on OK prints the exact commit command, otherwise a short diff
#   giveup <file> <func> <reason...>  put src/<file>.c back as last committed and add "<func>: gave up: <reason>"
#                            to this checkout's notes file (notes/<checkout name>.md)
#   next                     the next job from qwen/twins.txt then qwen/queue.txt (skipping matched and given-up
#                            ones), with its assembly and the twin's C (or an m2c draft): everything for one function
cd "$(dirname "$0")"
# git inside WSL: a worktree's .git file holds a Windows path (C:/...) that WSL's git can't follow, so translate it.
# Read-only use: no index writes (GIT_OPTIONAL_LOCKS=0), file modes ignored.
gd=$(sed -n 's/^gitdir: //p' .git 2>/dev/null | sed -E 's#^([A-Za-z]):#/mnt/\L\1#')
[ -n "$gd" ] && export GIT_DIR="$gd" GIT_WORK_TREE="$PWD"
export GIT_OPTIONAL_LOCKS=0 GIT_CONFIG_COUNT=1 GIT_CONFIG_KEY_0=core.filemode GIT_CONFIG_VALUE_0=false
# functions whose INCLUDE_ASM line is currently replaced by uncommitted C, one "func file" per line
replaced() {
  git diff -U0 -- src | awk '/^\+\+\+ b\/src\//{f=substr($2,7); sub(/\.c$/,"",f)} /^-INCLUDE_ASM\(/{n=$0; sub(/^[^,]*, */,"",n); sub(/\).*/,"",n); print n" "f}'
}
# Solve-time log, to compare models: `next` notes the job and its start (qwen/.job_info); when that job is matched or
# given up, one line goes to qwen/times.tsv (model name from qwen/.model, which the launcher writes).
logtime() {
  [ -f qwen/.job_info ] || return 0
  read -r lf lfile lbytes lstart < qwen/.job_info
  [ "$lf" = "$1" ] || return 0
  shift
  [ -f qwen/times.tsv ] || printf 'finished\tmodel\tfunction\tfile\tbytes\tseconds\ttries\tresult\n' > qwen/times.tsv
  lm=$(head -1 qwen/.model 2>/dev/null | tr -d '\r'); [ -z "$lm" ] && lm=unknown
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "$lm" "$lf" "$lfile" "$lbytes" \
    "$(( $(date +%s) - lstart ))" "$(cat qwen/.job_tries 2>/dev/null || echo 0)" "$*" >> qwen/times.tsv
  rm -f qwen/.job_info qwen/.job_tries
}
# Time limit per job for the local agent: `next` notes when it handed a job out (qwen/.job); 6 minutes later any
# command gives the job up and says so (the agent kept researching one function for 40 minutes instead of giving up).
if [ -f qwen/.job ] && [ "$1" != next ] && [ "$1" != giveup ] && [ "$1" != configure ] && [ -n "$(find qwen/.job -mmin +6 2>/dev/null)" ]; then
  read -r jf jfile < qwen/.job; rm -f qwen/.job
  if grep -q "INCLUDE_ASM(\"[^\"]*\", $jf);" "src/$jfile.c" 2>/dev/null || [ -n "$(replaced)" ]; then
    bash "$0" giveup "$jfile" "$jf" "time limit (6 minutes)" >/dev/null
    echo "TIME UP: 6 minutes on $jf - it has been given up automatically. Do not look at it again."
    echo "Run now: wsl -e bash ./agent-tools.sh next"
    exit 0
  fi
fi
# Every call is recorded for the training set (kh1-study/dataset/calls/<workspace>.jsonl: the command, its full
# output as the worker saw it, exit code and duration; tools/logcall.py). The call runs once more inside this
# wrapper with KH1_LOGGED set, so calls the tool makes to itself are not recorded twice.
if [ -z "$KH1_LOGGED" ] && [ -n "$1" ]; then
  export KH1_LOGGED=1; kt0=$(date +%s.%N); ktmp=$(mktemp)
  bash "$0" "$@" 2>&1 | tee "$ktmp"; krc=${PIPESTATUS[0]}
  python3 tools/logcall.py "$krc" "$kt0" "$ktmp" "$@" > /dev/null 2>&1; rm -f "$ktmp"
  exit $krc
fi
# a file argument given as "src/lib/x.c" or "lib/x.c" means "lib/x" (the local model does this now and then; the
# give-up then failed and left a stray .c.c.tmp file, 24 Nov)
if [ -n "$2" ]; then f2="${2#src/}"; f2="${f2%.c}"; c1="$1"; shift 2; set -- "$c1" "$f2" "$@"; fi
case "$1" in
  lesson)
    # lesson <file> <func> <what the difference looked like -> what fixed it (or: why it cannot match)>
    # One line of hard-won knowledge, kept with the function it came from (dataset/lessons/<workspace>.jsonl).
    f="$2"; fn="$3"; shift 3
    [ -z "$fn" ] || [ -z "$*" ] && { echo "usage: lesson <file> <func> <symptom -> fix, in one or two sentences>"; exit 1; }
    echo "lesson noted for $fn ($f): $*" ;;
  next)
    # an attempt left in place (the agent moved on without giving up) would block every later try: clear it here
    replaced | while read -r lf lfile; do
      [ -n "$lf" ] && bash "$0" giveup "$lfile" "$lf" "moved on without matching (cleared by next)" >/dev/null && echo "(cleared your unfinished attempt at $lf)"
    done
    rm -rf .tries
    # the previous job ended with neither a match nor a give-up (the session ran out of time or just stopped):
    # note it as given up, or the same function is handed out again every round (seen 23 Nov, rented model)
    if [ -f qwen/.job ]; then
      read -r pj pf < qwen/.job
      pn="notes/$(basename "$PWD").md"
      if [ -n "$pj" ] && grep -q "INCLUDE_ASM(\"[^\"]*\", $pj);" "src/$pf.c" 2>/dev/null && ! grep -q "^- $pj (.*): gave up" "$pn" 2>/dev/null; then
        bash "$0" giveup "$pf" "$pj" "session ended without a result" >/dev/null && echo "(your last job $pj ended without a result: noted as given up)"
      fi
    fi
    # rounds: the unattended launcher asks for a few functions per fresh session; after 6 jobs, end the round
    # (the counter resets when it's older than an hour, i.e. the next round starts again at 1)
    rc=qwen/.round_count; [ -f "$rc" ] && [ -n "$(find "$rc" -mmin +60 2>/dev/null)" ] && rm -f "$rc"
    n=$(( $(cat "$rc" 2>/dev/null || echo 0) + 1 ))
    rs=$(tr -dc 0-9 < qwen/.round_size 2>/dev/null); [ -z "$rs" ] && rs=6
    if [ "$n" -gt "$rs" ]; then rm -f "$rc"; echo "ROUND COMPLETE: you've done $rs job(s) this round. Reply DONE and stop now (a fresh round starts automatically)."; exit 0; fi
    echo "$n" > "$rc"
    python3 - > /tmp/next_job.$$ <<'PY'
import os, re
notes = 'notes/%s.md' % os.path.basename(os.getcwd())
given = open(notes, errors='replace').read() if os.path.exists(notes) else ''
gave = set(re.findall(r'(\w+)(?: \([^)]*\))?: (?:twin of \w+, )?gave up', given))
for jobs in ('qwen/twins.txt', 'qwen/queue.txt'):
    if not os.path.exists(jobs): continue
    for line in open(jobs, errors='replace'):
        m = re.match(r'^\s*(\d+)\s+(\w+)\s+(\S+)(?:\s+<-\s+(\w+))?', line)
        if not m or m.group(2) in gave: continue
        src = 'src/%s.c' % m.group(3)
        if os.path.exists(src) and re.search(r'^INCLUDE_ASM\("[^"]+",\s*%s\);' % m.group(2), open(src, errors='replace').read(), re.M):
            print(m.group(2), m.group(3), m.group(4) or '-', m.group(1)); raise SystemExit
PY
    job=$(cat /tmp/next_job.$$); rm -f /tmp/next_job.$$
    [ -z "$job" ] && { echo "No jobs left in qwen/twins.txt or qwen/queue.txt. Reply that the job list is finished, then stop."; exit 0; }
    set -- $job
    echo "$1 $2" > qwen/.job
    echo "$1 $2 $4 $(date +%s)" > qwen/.job_info; rm -f qwen/.job_tries
    # start every job with an empty work file: the previous function's C left in it sent the model searching for
    # that function's symbols in a loop (23 Nov, _localeconv_r after func_00148F08)
    echo "// work file for $1 (src/$2.c): write this one function here, with the declarations it needs above it" > qwen/work.c
    echo "NEXT JOB: $1 in src/$2.c ($4 bytes)$( [ "$3" != - ] && echo " - twin of $3: copy the twin's C and change the names/offsets/constants")"
    # library code: show the same function from the reference sources (kh1-study/libref: Sony SDK / newlib / libgcc
    # files from the ICO and King's Field IV decompiles, MIT) - usually the original source, give or take SDK version
    case "$2" in lib/*) python3 tools/libref.py "$1" ;; esac
    # the layout changed (e.g. fm was merged with new C files) and this checkout has not been re-split yet: the
    # function's assembly file is missing until a build does that (23 Nov: the model went hunting for it instead)
    [ -f "asm/nonmatchings/$2/$1.s" ] || { echo "(the layout changed: re-splitting this checkout first, a few minutes)"; bash "$0" build > /dev/null 2>&1; }
    echo "== assembly of $1 =="
    grep -vE '^\s*$|^\.|^/\* Generated|glabel|endlabel|nonmatching' "asm/nonmatchings/$2/$1.s" | sed -E 's#^ +/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/ +##'
    if [ "$3" != - ]; then echo "== the twin's matched C =="; bash "$0" cfunc "$3"
    else echo "== m2c draft (check types against the assembly) =="; bash "$0" m2c "$2" "$1" | grep -v '^\s*$' | head -60; fi
    # (with a twin the twin IS the example: only the declarations then)
    python3 tools/similar.py "$2" "$1" "$( [ "$3" != - ] && echo 0 || echo 3 )" 2>/dev/null
    echo "== then: write qwen/work.c, and run: wsl -e bash ./agent-tools.sh try $2 $1 qwen/work.c" ;;
  try)
    # refuse (not just warn) if the file holds uncommitted C for other functions: either a forgotten attempt, or a
    # second session working in this checkout - both make every build fail or mislabel commits
    others=$(replaced | awk -v f="$2" -v fn="$3" '$2 == f && $1 != fn {printf "%s ", $1}')
    if [ -n "$others" ]; then
      echo "STOPPED: src/$2.c already has uncommitted C for: ${others}"
      echo "If that's an attempt you abandoned: wsl -e bash ./agent-tools.sh giveup $2 <that func> <reason>, then try again."
      echo "If you didn't write it, ANOTHER SESSION is working in this checkout: stop now and tell the owner."
      exit 1
    fi
    mkdir -p .tries
    h=$(tr -d ' \t\r\n' < "$4" 2>/dev/null | md5sum | cut -c1-32)
    if grep -qx "$h" ".tries/$3.seen" 2>/dev/null; then
      # identical to a try that already failed: nothing to build, and it still uses up a try
      q=1; qout="SAME CODE as a try that already failed - nothing was built. Change the C (types, expression order, a temporary, the prototype of a called function) before trying again."; out="$qout"
    else
      echo "$h" >> ".tries/$3.seen"
      bash "$0" put "$2" "$3" "$4" || exit 1
      # fast check first (under a second: compiles this one file and compares the function); the full build only
      # runs to confirm when the fast check says it matches
      q=0; qout=""
      qout=$(bash wsl-build.sh python3 tools/quickcmp.py "$2" "$3" 40 2>&1); q=$?   # (library files too since 23 Nov: quickcmp knows their compilers)
      echo "$qout" | python3 tools/logattempt.py "$2" "$3" "$q" try > /dev/null 2>&1
      if [ $q -eq 0 ]; then out=$(bash "$0" build); echo "$out" | tail -4; else out="$qout"; fi
      # a give-up used to throw the attempt away. Keep the closest one per function (qwen/attempts/<func>.c and
      # .score = "<instructions off> <of how many>"): a near-miss is a head start for a stronger model or the permuter
      if [ -d qwen ] && [ $q -ne 0 ]; then
        sc=$(echo "$qout" | sed -n 's/^QUICK CHECK: .* differs in \([0-9]*\) of \([0-9]*\) instructions.*/\1 \2/p' | head -1)
        if [ -n "$sc" ]; then
          mkdir -p qwen/attempts; old=$(cut -d' ' -f1 "qwen/attempts/$3.score" 2>/dev/null)
          if [ -z "$old" ] || [ "${sc%% *}" -lt "$old" ]; then cp "$4" "qwen/attempts/$3.c"; echo "$sc $2" > "qwen/attempts/$3.score"; fi
        fi
      fi
    fi
    # failed tries per function are counted; the 2nd failure gives up automatically (23 Nov: of 14 logged matches none came on a 3rd try) (the local agent kept researching
    # one function for an hour instead of giving up)
    mkdir -p .tries; tf=".tries/$3"
    [ -f qwen/.job_info ] && echo $(( $(cat qwen/.job_tries 2>/dev/null || echo 0) + 1 )) > qwen/.job_tries
    if [ "$(echo "$out" | tail -1)" = "build/fm/SLPS_251.98.rom: OK" ]; then
      rm -f "$tf" "qwen/attempts/$3.c" "qwen/attempts/$3.score"
      logtime "$3" matched
      echo "MATCHED. Commit it now (PowerShell, in the checkout folder):"
      echo "  git add src/$2.c; git commit -m \"Match $3 ($2)\""
    else
      t=$(( $(cat "$tf" 2>/dev/null || echo 0) + 1 )); echo "$t" > "$tf"
      if [ "$t" -ge 2 ]; then
        rm -f "$tf"
        bash "$0" giveup "$2" "$3" "2 failed tries (automatic)" >/dev/null
        echo "GAVE UP AUTOMATICALLY after 2 failed tries: src/$2.c is restored and $3 is noted as given up."
        echo "Do NOT research it further. Run 'wsl -e bash ./agent-tools.sh next' now for the next function."
      else
        echo "Not matching yet (failed try $t of 2)."
        if [ $q -ne 0 ]; then echo "$qout" | tail -45; else echo "The function's own code matches but the whole image does not: check symbol names (D_/func_ addresses), data it defines, and other functions you changed. Differences (target on the left):"; bash "$0" diff "$3" 40; fi
      fi
    fi ;;
  quick)
    # the function must be C in the working file: compared while still INCLUDE_ASM it is the original against
    # itself and "matches" (that fooled a batch commit on 23 Nov)
    if grep -q "^INCLUDE_ASM(\"[^\"]*\", *$3);" "src/$2.c" 2>/dev/null; then
      echo "NOT COMPARED: $3 is still INCLUDE_ASM in src/$2.c - your C is not in the file (put it again)."; exit 3
    fi
    qo=$(bash wsl-build.sh python3 tools/quickcmp.py "$2" "$3" "${4:-40}" 2>&1); qr=$?; echo "$qo"
    # every attempt is kept for a future training set (kh1-study/dataset/attempts, see tools/logattempt.py)
    echo "$qo" | python3 tools/logattempt.py "$2" "$3" "$qr" quick > /dev/null 2>&1
    exit $qr ;;
  giveup)
    f="$2"; fn="$3"; shift 3
    python3 tools/logattempt.py "$f" "$fn" 1 giveup "$@" < /dev/null > /dev/null 2>&1
    git show "HEAD:src/$f.c" > "src/$f.c.tmp" && mv "src/$f.c.tmp" "src/$f.c" || { echo "couldn't restore src/$f.c"; exit 1; }
    n="notes/$(basename "$PWD").md"; [ "$(basename "$PWD")" = "kh1-decomp" ] && n="notes/main.md"
    best=""; [ -f "qwen/attempts/$fn.score" ] && best=" [closest try: $(cut -d' ' -f1 "qwen/attempts/$fn.score") of $(cut -d' ' -f2 "qwen/attempts/$fn.score") instructions off, kept in qwen/attempts/$fn.c]"
    echo "- $fn ($f): gave up: $*$best" >> "$n"
    logtime "$fn" "gave up: $*"
    echo "src/$f.c is back to its last commit; noted in $n. Take the next function." ;;
  cfunc)
    python3 - "$2" <<'PY'
import glob, re, sys
fn = sys.argv[1]
for f in sorted(glob.glob('src/**/*.c', recursive=True)):
    s = open(f, encoding='utf-8', errors='replace').read()
    m = re.search(r'^[A-Za-z_][^;{}\n]*\b%s\s*\([^;{}]*\)(?:\s*[^;{}()]+;)*\s*\{' % re.escape(fn), s, re.M)
    if not m: continue
    i, depth = s.index('{', m.start()), 0
    for j in range(i, len(s)):
        depth += {'{': 1, '}': -1}.get(s[j], 0)
        if depth == 0: break
    start = s.rfind('\n#if', 0, m.start()); start = start + 1 if start != -1 and s.count('\n', start, m.start()) <= 1 else m.start()
    print('// %s (%s)' % (fn, f)); print(s[start:j + 1]); sys.exit(0)
sys.exit('%s: no C definition found in src/' % fn)
PY
    ;;
  near)
    n="${4:-30}"
    l=$(grep -n "INCLUDE_ASM(\"[^\"]*\", $3);" "src/$2.c" | head -1 | cut -d: -f1)
    [ -z "$l" ] && l=$(grep -nE "^[^;#]*\b$3\s*\(" "src/$2.c" | head -1 | cut -d: -f1)
    [ -z "$l" ] && { echo "$3 not found in src/$2.c"; exit 1; }
    s=$((l > n ? l - n : 1)); sed -n "${s},$((l + n))p" "src/$2.c" ;;
  put)
    [ -f "$4" ] || { echo "no file $4"; exit 1; }
    others=$(replaced | awk -v f="$2" -v fn="$3" '$2 == f && $1 != fn {printf "%s ", $1}')
    python3 - "$2" "$3" "$4" $others <<'PY'
import os, re, subprocess, sys
f, fn, cfile, others = 'src/%s.c' % sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
s = open(f, encoding='utf-8').read()
def line(name): return re.compile(r'^INCLUDE_ASM\("[^"]+",\s*%s\);$' % re.escape(name), re.M)
pat = line(fn)
hits = pat.findall(s)
os.makedirs('.puts', exist_ok=True)
if len(hits) == 0:
    # an earlier attempt of THIS function is already in place: start again from the file as last committed, and
    # put back the other functions that were waiting uncommitted in it (their C is remembered in .puts/).
    # Before 23 Nov those were silently dropped, and batches got committed with names whose C was not in them.
    base = subprocess.run(['git', 'show', 'HEAD:' + f], capture_output=True, text=True).stdout
    if len(pat.findall(base)) == 1:
        s, hits = base, pat.findall(base)
        print('(an earlier attempt of %s was in place: started again from the last commit of %s)' % (fn, f))
        for o in others:
            saved = os.path.join('.puts', o + '.c')
            if os.path.exists(saved) and len(line(o).findall(s)) == 1:
                oc = open(saved, encoding='utf-8').read()
                s = line(o).sub(lambda m: oc, s, count=1); print('(kept your uncommitted %s)' % o)
            else:
                print('WARNING: your uncommitted C for %s was DROPPED from %s (no saved copy): put it again.' % (o, f))
if len(hits) != 1:
    sys.exit('expected exactly one INCLUDE_ASM line for %s in %s, found %d (is it already committed as C?)' % (fn, f, len(hits)))
c = open(cfile, encoding='utf-8').read().replace('\r\n', '\n').rstrip('\n')
open(os.path.join('.puts', fn + '.c'), 'w', encoding='utf-8', newline='\n').write(c)
s = pat.sub(lambda m: c, s, count=1)
open(f, 'w', encoding='utf-8', newline='\n').write(s)
print('replaced the INCLUDE_ASM line for %s in %s with %s (%d lines)' % (fn, f, cfile, c.count('\n') + 1))
PY
    ps=$?; [ $ps -ne 0 ] && exit $ps
    if [ -n "$others" ]; then echo "WARNING: src/$2.c still has uncommitted C for other functions too: ${others}- a build only passes if ALL of them match. If you gave up on them: git checkout -- src/$2.c, then put this function again."; fi
    ;;
  configure)
    bash wsl-build.sh python3 configure.py -c -v fm 2>&1 | grep -iE 'error|duplicate' ; bash wsl-build.sh ninja 2>&1 | tail -1 ;;
  build)
    # The last line is always the verdict: the image's own checksum (OK/FAILED), or BUILD FAILED if ninja failed
    # (then the image on disk is stale and must not be trusted).
    # The log lives in this checkout's own WSL mirror (one per worktree), so parallel agents don't overwrite it;
    # the dashboard (kh1-study\dashboard) shows it.
    # Every build also appends "epoch <tab> verdict <tab> functions being worked on" to .agent_build.history
    # (the functions whose INCLUDE_ASM line is currently replaced), for the dashboard's per-agent statistics.
    funcs=$(replaced | awk '{printf "%s ", $1}')
    nf=$(echo $funcs | wc -w)
    [ "$nf" -gt 1 ] && echo "NOTE: this build contains $nf functions in uncommitted C: ${funcs}- it only passes if ALL of them match. Revert any you gave up on (git checkout -- src/<file>.c)."
    # a stale split (the layout, symbol lists or configure.py changed since the last configure, e.g. after merging fm)
    # makes every build fail whatever the C says: re-split first (it cost the local agent three whole rounds, 22 Nov)
    FUNCS="$funcs" bash wsl-build.sh bash -c 'if [ ! -f build.ninja ] || [ -n "$(find config/kh.fm.yaml config/fm configure.py -newer build.ninja -print -quit 2>/dev/null)" ] || [ -n "$(python3 tools/missing_asm.py check 2>/dev/null)" ]; then echo "(layout changed since the last configure, or an assembly file is missing: re-splitting first, a few minutes)"; python3 configure.py -c -v fm > .agent_configure.log 2>&1 || { tail -5 .agent_configure.log; }; python3 tools/missing_asm.py baseline 2>/dev/null; fi; ninja > .agent_build.log 2>&1; s=$?; date "+%H:%M:%S" > .agent_build.time; grep -vE "^\[[0-9]+/[0-9]+\] (cc|as) |warning: |In function|At top level|LOAD segment with RWX" .agent_build.log | tail -25; if [ $s -eq 0 ] && sha1sum -c config/fm/checksum.sha1 > .agent_build.v 2>&1; then v=OK; elif [ $s -eq 0 ]; then v=DIFFERS; elif grep -q "checksum did NOT match" .agent_build.log; then v=DIFFERS; else v=ERROR; fi; if [ $s -eq 0 ]; then sha1sum -c config/fm/checksum.sha1 2>&1 | tee -a .agent_build.log; else echo "BUILD FAILED" | tee -a .agent_build.log; fi; printf "%s\t%s\t%s\n" "$(date +%s)" "$v" "$FUNCS" >> .agent_build.history' ;;
  list)
    for f in $(grep -oP '^INCLUDE_ASM\("asm/nonmatchings/[^"]+",\s*\K\w+' "src/$2.c"); do
      p="asm/nonmatchings/$2/$f.s"
      [ -f "$p" ] || continue
      z=$(grep -oP 'nonmatching \w+, 0x\K[0-9A-F]+' "$p" | head -1)
      [ -n "$z" ] && echo "$((16#$z)) $f"
    done | sort -n ;;
  asm)
    cat "asm/nonmatchings/$2/$3.s" ;;
  m2c)
    bash wsl-build.sh bash -c "python3 tools/m2ctx.py 'src/$2.c' >/dev/null && python3 tools/ctx_fix.py ctx.c && ~/m2c-venv/bin/python ~/m2c/m2c.py -t mipsee-gcc-c --context ctx.c 'asm/nonmatchings/$2/$3.s'" 2>&1 ;;
  diff)
    KH_VERSION=fm bash wsl-build.sh python3 diff.py -m --format plain "$2" 2>&1 | head -"${3:-120}" ;;
  *)
    sed -n '2,10p' "$0" ;;
esac
