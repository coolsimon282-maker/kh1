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
cd "$(dirname "$0")"
case "$1" in
  near)
    n="${4:-30}"
    l=$(grep -n "INCLUDE_ASM(\"[^\"]*\", $3);" "src/$2.c" | head -1 | cut -d: -f1)
    [ -z "$l" ] && l=$(grep -nE "^[^;#]*\b$3\s*\(" "src/$2.c" | head -1 | cut -d: -f1)
    [ -z "$l" ] && { echo "$3 not found in src/$2.c"; exit 1; }
    s=$((l > n ? l - n : 1)); sed -n "${s},$((l + n))p" "src/$2.c" ;;
  put)
    [ -f "$4" ] || { echo "no file $4"; exit 1; }
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
    ;;
  configure)
    bash wsl-build.sh python3 configure.py -c -v fm 2>&1 | grep -iE 'error|duplicate' ; bash wsl-build.sh ninja 2>&1 | tail -1 ;;
  build)
    # The last line is always the verdict: the image's own checksum (OK/FAILED), or BUILD FAILED if ninja failed
    # (then the image on disk is stale and must not be trusted).
    # The log lives in this checkout's own WSL mirror (one per worktree), so parallel agents don't overwrite it;
    # the dashboard (kh1-study\dashboard) shows it.
    bash wsl-build.sh bash -c 'ninja > .agent_build.log 2>&1; s=$?; date "+%H:%M:%S" > .agent_build.time; grep -vE "^\[[0-9]+/[0-9]+\] (cc|as) |warning: |In function|At top level|LOAD segment with RWX" .agent_build.log | tail -25; if [ $s -eq 0 ]; then sha1sum -c config/fm/checksum.sha1 | tee -a .agent_build.log; else echo "BUILD FAILED" | tee -a .agent_build.log; fi' ;;
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
