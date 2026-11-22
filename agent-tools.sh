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
cd "$(dirname "$0")"
case "$1" in
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
