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
#   try <file> <func> <cfile>  put + build in one step; on OK prints the exact commit command, otherwise a short diff
#   giveup <file> <func> <reason...>  put src/<file>.c back as last committed and add "<func>: gave up: <reason>"
#                            to this checkout's notes file (notes/<checkout name>.md)
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
case "$1" in
  try)
    bash "$0" put "$2" "$3" "$4" || exit 1
    out=$(bash "$0" build); echo "$out" | tail -4
    if [ "$(echo "$out" | tail -1)" = "build/fm/SLPS_251.98.rom: OK" ]; then
      echo "MATCHED. Commit it now (PowerShell, in the checkout folder):"
      echo "  git add src/$2.c; git commit -m \"Match $3 ($2)\""
    else
      echo "Not matching yet. Differences (target on the left):"
      bash "$0" diff "$3" 40
    fi ;;
  giveup)
    f="$2"; fn="$3"; shift 3
    git show "HEAD:src/$f.c" > "src/$f.c.tmp" && mv "src/$f.c.tmp" "src/$f.c" || { echo "couldn't restore src/$f.c"; exit 1; }
    n="notes/$(basename "$PWD").md"; [ "$(basename "$PWD")" = "kh1-decomp" ] && n="notes/main.md"
    echo "- $fn ($f): gave up: $*" >> "$n"
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
    python3 - "$2" "$3" "$4" <<'PY'
import re, subprocess, sys
f, fn, cfile = 'src/%s.c' % sys.argv[1], sys.argv[2], sys.argv[3]
s = open(f, encoding='utf-8').read()
pat = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*%s\);$' % re.escape(fn), re.M)
hits = pat.findall(s)
if len(hits) == 0:
    # an earlier attempt is already in place: start again from the file as last committed (every match is
    # committed straight away, so the only uncommitted change in it is this function's attempt)
    base = subprocess.run(['git', 'show', 'HEAD:' + f], capture_output=True, text=True).stdout
    if len(pat.findall(base)) == 1:
        s, hits = base, pat.findall(base)
        print('(an earlier attempt was in place: started again from the last commit of %s)' % f)
if len(hits) != 1:
    sys.exit('expected exactly one INCLUDE_ASM line for %s in %s, found %d' % (fn, f, len(hits)))
c = open(cfile, encoding='utf-8').read().replace('\r\n', '\n').rstrip('\n')
s = pat.sub(lambda m: c, s, count=1)
open(f, 'w', encoding='utf-8', newline='\n').write(s)
print('replaced the INCLUDE_ASM line for %s in %s with %s (%d lines)' % (fn, f, cfile, c.count('\n') + 1))
PY
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
    FUNCS="$funcs" bash wsl-build.sh bash -c 'ninja > .agent_build.log 2>&1; s=$?; date "+%H:%M:%S" > .agent_build.time; grep -vE "^\[[0-9]+/[0-9]+\] (cc|as) |warning: |In function|At top level|LOAD segment with RWX" .agent_build.log | tail -25; if [ $s -eq 0 ] && sha1sum -c config/fm/checksum.sha1 > .agent_build.v 2>&1; then v=OK; elif [ $s -eq 0 ]; then v=DIFFERS; elif grep -q "checksum did NOT match" .agent_build.log; then v=DIFFERS; else v=ERROR; fi; if [ $s -eq 0 ]; then sha1sum -c config/fm/checksum.sha1 2>&1 | tee -a .agent_build.log; else echo "BUILD FAILED" | tee -a .agent_build.log; fi; printf "%s\t%s\t%s\n" "$(date +%s)" "$v" "$FUNCS" >> .agent_build.history' ;;
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
    bash wsl-build.sh bash -c "python3 tools/m2ctx.py 'src/$2.c' >/dev/null && ~/m2c-venv/bin/python ~/m2c/m2c.py -t mipsee-gcc-c --context ctx.c 'asm/nonmatchings/$2/$3.s'" 2>&1 ;;
  diff)
    KH_VERSION=fm bash wsl-build.sh python3 diff.py -m --format plain "$2" 2>&1 | head -"${3:-120}" ;;
  *)
    sed -n '2,10p' "$0" ;;
esac
