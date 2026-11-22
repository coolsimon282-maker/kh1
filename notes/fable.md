# Fable notes

## xpotato func_00215CE8 (22 Nov, 1 hour, not matched: 3 diffs -> best 2 diffs)

Target block: `lw $2,CC8; lui $3,%hi(D_0063CF04); lw $5,CF44; li $4,3; addiu $2,-1; bne $5,$2; sw $4,%lo(D_0063CF04)($3)`.
All earlier attempts give lui=$4 / const=$3.

What decides it (read from gcc 2.95.3 local-alloc.c / haifa-sched.c, confirmed with -dl and -dR -fsched-verbose=4 dumps):

* local-alloc gives hard regs to the block's local values ("qtys") in priority order (2 refs / life, shorter life
  first). With EXACTLY 3 qtys it uses a hand-written sort that compares qty numbers 0,1,2 instead of positions:
  birth order q0,q1,q2 ends as [0,1,2] (p1<=p0, p2<=p1, or p1>p0, p2<=p1), [0,2,1] (p1<=p0, p2>p1) or [2,1,0].
  4+ qtys are sorted properly; 2 qtys: higher priority first. This explains many "two registers swapped" cases.
* sched2 breaks ties by priority, relation to the last scheduled insn, number of dependents, then original order.
  So `lui` before `li` in the final code means `lui` was before `li` in the stream local-alloc saw.
* Together: with `lui` born before the constant, a block-local constant always outranks the `lui` (shorter life) and
  gets the lower register. The target (const in $4, after CC8=$2 and lui=$3) is only possible if the constant's
  pseudo is NOT handled by local-alloc, i.e. it is allocated by global-alloc: used in more than one block, or
  set/dying more than once (REG_N_DEATHS != 1).

Evidence (scratchpad fable/, variants on a3's best C):
* `n = D_00642CC8 - 1; k = 3; D_0063CF04 = k; if (D_0063CF44 == n)` (constant born first): registers all right,
  2 diffs left (li and lui swapped in order).
* `D_0063CF04 = k = 3;` here and `D_0063CF04 = k = 1;` in the first branch (k is then a global pseudo): THIS block
  matches exactly, but the first branch breaks (it needs its constant local: const=$2, lui=$3).

So the original probably stored 3 through a variable that is also set/used somewhere else in the function in a way
that leaves the first branch's `D_0063CF04 = 1` a plain constant store. Not found yet: sharing the variable with the
`func_001F3D58(m, 5)` argument or with the D_00425BC8 pointer temp didn't work. Next ideas: a variable shared with
something in the trailing loop (sel / r / i / y roles differently assigned), or the state value coming from an
inline helper used in both places.

Tools: scratchpad fable/t.sh (sandbox compile + compare), show.sh (diffs + block RTL + local reg assignment),
sched.sh + strace.py (sched2 trace).
