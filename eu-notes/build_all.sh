#!/bin/bash
# Compiles every game .c (not src/lib) in ~/kh1-test to ~/kh1-test/obj/*.o, INCLUDE_ASM left out.
cd ~/kh1-test; mkdir -p obj; CC=$PWD/tools/cc/ee-gcc2.96; ok=0; bad=0
for f in $(find src -name "*.c" -not -path "src/lib/*"); do
  n=${f#src/}; n=${n%.c}; n=${n//\//__}; g=-g; case $(basename $f .c) in xblade|gumi) g=;; esac
  if $CC/bin/ee-gcc -c -B $CC/bin/ee- -Iinclude -isystem include/sdk/ee -isystem include/gcc -O2 -G0 $g -DPERMUTER $f -S -o - 2>/dev/null \
     | python3 tools/masps2.py > obj/$n.s && $CC/ee/bin/as -O2 -G0 $g -EL -mabi=eabi -Iinclude/ee-as -Iinclude -o obj/$n.o obj/$n.s 2>/dev/null
  then ok=$((ok+1)); else bad=$((bad+1)); echo "failed: $n"; fi
done
echo "compiled $ok files, $bad failed"
