#!/bin/bash
# Work through ~/perm-queue/queue.tsv (made by tools/perm_seed.py) with decomp-permuter, closest candidates first.
# Run inside the build mirror:  bash tools/permute_queue.sh [seconds per function=900] [jobs=10]
# Matches (score 0) are copied to ~/perm-queue/solved/<func>.c; progress goes to ~/perm-queue/log.txt.
SECS="${1:-900}"; JOBS="${2:-10}"; Q=~/perm-queue; mkdir -p $Q/solved
[ -f .venv/bin/activate ] && . .venv/bin/activate   # (the mirror's Python environment: pycparser etc.)
grep -oE "[A-Za-z_0-9]+\.NON_MATCHING" build/fm/SLPS_251.98.map | sed 's/\.NON_MATCHING//' | sort -u > $Q/unmatched.txt
while IFS=$'\t' read -r d fn f; do
  grep -qx "$fn" $Q/unmatched.txt || continue            # already matched in the merged build
  [ -f "$Q/solved/$fn.c" ] && continue
  [ "$d" -eq 0 ] && { echo "$(date +%H:%M) $fn ($f): quick check already matches - try a real build" | tee -a $Q/log.txt; continue; }
  echo "$(date +%H:%M) $fn ($f): starting, $d instructions off" | tee -a $Q/log.txt
  PERM_TAIL=2 bash tools/permute.sh "$f" "$fn" "$Q/$fn.c" "$SECS" "$JOBS" > $Q/last.txt 2>&1
  best=$(ls -d ~/decomp-permuter/nonmatchings/$fn/output-* 2>/dev/null | sed 's/.*output-//' | sort -t- -k1 -n | head -1)
  if [ "${best%%-*}" = "0" ]; then cp ~/decomp-permuter/nonmatchings/$fn/output-$best/source.c $Q/solved/$fn.c; echo "$(date +%H:%M) $fn: MATCH FOUND -> solved/$fn.c" | tee -a $Q/log.txt
  elif ! grep -q "base score" $Q/last.txt; then echo "$(date +%H:%M) $fn: COULD NOT RUN ($(tr '' '
' < $Q/last.txt | grep -aiE "error|Traceback" | tail -1 | cut -c1-120))" | tee -a $Q/log.txt
  else echo "$(date +%H:%M) $fn: no match in ${SECS}s (best score ${best%%-*}, base $(tr '' '
' < $Q/last.txt | grep -ao "base score = [0-9]*" | head -1 | grep -o "[0-9]*$"))" | tee -a $Q/log.txt; fi
done < $Q/queue.tsv
echo "$(date +%H:%M) queue finished" | tee -a $Q/log.txt
