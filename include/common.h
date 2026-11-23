#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

typedef char s8;
typedef short s16;
typedef int s32;
typedef long s64;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef union {
    vs8 s8;
    vs16 s16;
    vs32 s32;
    vs64 s64;
    vu8 u8;
    vu16 u16;
    vu32 u32;
    vu64 u64;
} _VX;

typedef float f32;

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

#define NULL 0
#define TRUE 1
#define FALSE 0
#define b32 s32 // 32-bit boolean (TRUE/FALSE)

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define BSS __attribute__ ((section (".bss")))

/* NOTHROW(ret, f); declares f as a function that ee-gcc 2.96 knows "cannot throw".
 *
 * The compiler learns that about a function when it compiles the function's body, and uses it for every call
 * further down in the same file: such calls get a REG_EH_REGION 0 note, and next to them the delay-slot pass
 * fills a branch slot without annulling (target has bne/beqz + a useful slot where a plain declaration gives
 * bnel/beqzl). So the original file had the callee's body above the caller. Use this when ours can't yet:
 * the callee is still INCLUDE_ASM further down, or sits in another file because the split is too fine.
 *
 * How: an `extern inline` body is compiled far enough to get the flag but never emitted, and the old-style
 * double parameter makes inlining fail at every call (argument mode mismatch), so a normal call comes out.
 * The declaration has no prototype: don't use it for callees taking float arguments. Use it INSTEAD of the
 * normal prototype, and drop it once the callee's real C definition is above the caller.
 *
 * NOTHROW_FN(s8 f(s16 a, f32 b)); does the same WITH a full prototype (needed for float arguments; give the
 * parameters names). Only for a callee that lives in ANOTHER source file: it compiles an empty weak copy of f
 * into a section the linker script throws away, and the real f from the other file is linked. (A callee that
 * is INCLUDE_ASM in this same file would be defined twice: use NOTHROW for that.) */
#ifdef M2CTX
#define NOTHROW(ret, name) ret name()
#define NOTHROW_FN(decl) decl
#else
#define NOTHROW(ret, name) extern inline ret name(nothrow_arg_) double nothrow_arg_; {} extern int nothrow_dummy_
#define NOTHROW_FN(decl) decl __attribute__((weak, section(".nothrow_dup"))); decl {} extern int nothrow_dummy_
#endif

#include "common_data.h"
#include "common_funcs.h"
#include "common_math.h"

#endif /* COMMON_H */
