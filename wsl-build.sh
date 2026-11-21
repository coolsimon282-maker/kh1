#!/bin/bash
# Runs a build command for this repo inside WSL's own disk.
#
# Why: the PS2 compilers in tools/cc are old 32-bit Linux programs, and they can't read files on the Windows
# drive (/mnt/c) - they fail with "cannot exec cc1". So the repo is mirrored to ~/kh1-decomp-build, the command
# runs there, and the generated asm/ folder is copied back so it can be read from Windows.
#
#   bash wsl-build.sh ninja
#   bash wsl-build.sh python3 configure.py -c -v jp
#   bash wsl-build.sh python3 diff.py -m --format plain func_00112168
#
# Edit files in the Windows copy only; the mirror is overwritten on every run.
set -e
SRC="$(cd "$(dirname "$0")" && pwd)"
DST="$HOME/kh1-decomp-build"
mkdir -p "$DST"
# Mirror the sources (not generated folders, not git). The game program file comes along; it stays local.
rsync -a --delete \
  --exclude .git/ --exclude .venv/ --exclude asm/ --exclude assets/ --exclude build/ --exclude expected/ \
  --exclude build.ninja --exclude .ninja_log --exclude .ninja_deps --exclude .splache   --exclude '/*.ld' --exclude '/*.rom' --exclude '/*.d' --exclude permuter_settings.toml   --exclude 'undefined_*_auto.txt' --exclude __pycache__/ \
  "$SRC/" "$DST/"
cd "$DST"
[ -d .venv ] || { python3 -m venv .venv && . .venv/bin/activate && pip install -q -U -r requirements.txt colorama watchdog Levenshtein cxxfilt; }
. .venv/bin/activate
set +e
"$@"
status=$?
# Bring the generated assembly back for reading from Windows (only when it changed).
# (-rt only: the Windows drive refuses owner/group changes and rsync's temporary files)
[ -d asm ] && rsync -r --inplace --delete asm/ "$SRC/asm/"
exit $status
