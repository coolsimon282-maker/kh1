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

## 23 Nov: the "bne vs bnel" family and two register rules (11 matched)

Matched: func_001C4788, func_0024F008, func_001016B8, func_00125B68 (permuter queue / cleaned up), func_0011D350,
func_0011D448, func_0011D5F0, func_0017EFF8, func_0015A348, func_0011E610, func_0011E700, func_0011E758.
func_00152880 matches too, but only once func_00152770 (2 instructions off, below) is C.

Rules (each confirmed by a match):

1. **Branch-likely next to a call depends on whether the callee's DEFINITION is visible, not on a compiler flag.**
   A branch that skips over `jal f` comes out plain (`bne`/`beqz`, slot filled non-annulled) when `f` is defined
   in C earlier in the same file, and likely (`bnel`/`beqzl`) when `f` is only declared (still INCLUDE_ASM, in
   another file, defined later, or called through an `__asm__("f")` alias).
   - Target has the plain branch, ours the likely one: call `f` DIRECTLY (not through the alias); if `f` is still
     assembly in this file, match `f` first. The whole "reorg bne vs bnel" skip list was this.
   - Target has the likely branch, ours the plain one: hide the definition with the alias declaration.
2. **A missing `move a0,s0` before a call = the incoming parameter itself is passed on.** If the target saves a0
   in s0 but still calls `g` with a0 untouched (`jal g` with no argument set-up), write
   `T f(u8* a0, ...) { u8* p = a0; ... g(a0); ... }` and use `p` everywhere else. The live a0 also changes nearby
   delay slots (func_0015A348: `beql` + load; func_00152880: the loaded value lands in a1 because v0, v1, a0 are
   busy). Check the callee's real parameter count in its own assembly: m2c invents extra ones.
3. **After a call, `lui $2 / lw $3` (target) vs `lui v1 / lw v0` (ours) = the call's return type.** A call whose
   value is unused still occupies $2 at that point if the callee is declared to return something, so the address
   temp moves to $3. If the target has the temp in $2, call through a void-returning declaration
   (`void f_v(...) __asm__("f");`); if it has it in $3, the callee returns a value.
4. `(x & 1) == 1` is folded to `!= 0`; the target's `li $4,1; andi; bne $3,$4` needs `s32 t = x & 1; if (t == 1)`.
5. `if (a != 0 || (p->flags & M)) { ... } return p->x;` gives the "jump into the middle, flags reloaded" shape
   (func_0015A348).

Open: func_00152770 (C in git history of fable-work, see below): everything matches except the order of
`daddu $5,$29` / `addiu $4,$17,0x10` before the first sceVu0CopyVector (target sets a1 first). sched2 picks by
LUID there, so the target's a1 set was emitted before the a0 set; plain variables, struct types and statement
order don't change it. Its one-parameter signature is `void func_00152770(u8*)`.

Tools: scratchpad fable/sdump.sh + ex2.py (compile one function with -dS -dR -dl dumps and split out its part).
