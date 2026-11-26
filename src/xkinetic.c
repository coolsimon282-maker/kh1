/**
 * The event script VM's opcode handlers (the table scriptOpTable, opcode = top byte of each 32-bit instruction).
 *
 * A script (Script / ScriptVM) has a value stack (sp at 0x180), 26 locals (0x208), a stack of switch values (0x270, top
 * 0x2F0) and 8 thread slots. Handlers return 2 to go on with the next instruction, 1 after a forward jump, 4 after a
 * backward jump (the frame ends), 6 to stop. Opcode names follow jhaton's script_bytecode.py (docs/external/jhaton).
 * The interpreter loop and most commands (CALL_COMMAND) are in xhumungus.c.
 */
#include "common.h"
#include "xflamingo.h"
#include "xhumungus.h"
#include "xcursed.h"

// Script seen as a stack machine: unk_174[3] is the stack pointer, unk_174[4..] the stack
typedef struct {
    /* 0x000 */ char unk_000[0x180];
    /* 0x180 */ s32 sp;
    /* 0x184 */ s32 stack[33];
    /* 0x208 */ s32 var[26];
    /* 0x270 */ s32 unk_270[32];
    /* 0x2F0 */ s32 unk_2F0;
} ScriptVM;

extern u8 D_003C39B0[];
extern u8 D_003C39F0[];
extern u8 D_003C3A30[];
extern XGiantMountain D_003854E0;

static inline void clr64(u8 *p) {
    s32 i;
    for (i = 63; i >= 0; i--) {
        p[i] = 0;
    }
}

void func_001C21B8(void) {
    clr64(D_003C39B0);
    clr64(D_003C39F0);
    clr64(D_003C3A30);
    D_003854E0.unk_3070 &= ~0x40000000000;
}

// Opcode 0 NOP.
s32 ScriptOp_Nop(void) {
    return 2;
}

// Opcode 2 JUMP: adds the operand to the program counter.
s32 ScriptOp_JumpRelative(Script* arg0, s32 arg1) {
    arg0->unk_174[2] += arg1;
    if (arg1 < 0) {
        return 4;
    }
    return 1;
}

// Opcode 3 JUMP_IF_FALSE: pops a value and jumps by the operand if it is 0.
s32 ScriptOp_JumpIfFalse(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    if (vm->stack[vm->sp--] == 0) {
        arg0->unk_174[2] += arg1;
        if (arg1 < 0) {
            return 4;
        }
        return 1;
    }
    return 2;
}

// Opcode 4 (unused): does nothing.
s32 ScriptOp_Reserved04(void) {
    return 2;
}

// Opcode 6 SAVE_SWITCH_VALUE: pops a value into switch slot operand and makes it the current one.
s32 ScriptOp_SaveSwitchValue(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->unk_270[arg1] = vm->stack[vm->sp];
    vm->unk_2F0 = arg1;
    vm->sp--;
    return 2;
}

// Opcode 7 SWITCH_EQ: pushes (current switch value == operand).
s32 ScriptOp_SwitchEq(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] == arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

// Opcode 26 SWITCH_LT: pushes (current switch value < operand).
s32 ScriptOp_SwitchLt(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] < arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

// Opcode 27 SWITCH_LE: pushes (current switch value <= operand).
s32 ScriptOp_SwitchLe(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] <= arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

// Opcode 28 SWITCH_GT: pushes (current switch value > operand).
s32 ScriptOp_SwitchGt(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] > arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

// Opcode 29 SWITCH_GE: pushes (current switch value >= operand).
s32 ScriptOp_SwitchGe(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] >= arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

// Opcode 8 POP_SWITCH_VALUE: drops the current switch value.
s32 ScriptOp_PopSwitchValue(Script* arg0) {
    arg0->unk_2F0--;
    return 2;
}

// Script seen by END: the thread slot table (program counters, -1 = free) and the current slot
typedef struct {
    /* 0x000 */ char unk_000[0x17C];
    /* 0x17C */ s32 pc;
    /* 0x180 */ char unk_180[0x178];
    /* 0x2F8 */ s32 thread[8];
    /* 0x318 */ s32 cur;
    /* 0x31C */ char unk_31C[0xC];
    /* 0x328 */ u64 flags;
} ScriptEnd;

// Opcode 5 END: frees the current thread slot (-1) and switches to the next used slot above it (its program counter
// in slot table thread[]); in slot 7 it sets flag bit 3 of 0x328 instead. Always ends the frame.
s32 ScriptOp_End(Script *arg0) {
    ScriptEnd *s = (ScriptEnd *)arg0;
    s32 i, t;

    if (s->cur == 7) {
        s->flags |= 8;
        return 4;
    }
    s->thread[s->cur] = -1;
    for (i = s->cur + 1; i < 8; i++) {
        t = s->thread[i];
        if (t != -1) {
            s->pc = t;
            s->cur = i;
            break;
        }
    }
    return 4;
}

// Clamps a value to a variable type's range (0/1: one bit, 2: s8, 3: s16, ...).
s64 Script_ClampValue(s64 arg0, s32 arg1) {
    switch (arg1) {
        case 0:
        case 1:
            arg0 &= 1;
        case 2:
            if (arg0 < -0x80) {
                arg0 = -0x80;
            } else if (arg0 >= 0x7f) {
                arg0 = 0x7f;
            }
            break;
        case 3:
            if (arg0 < -0x8000) {
                arg0 = -0x8000;
            } else if (arg0 >= 0x7fff) {
                arg0 = 0x7fff;
            }
            break;
        case 4:
            if (arg0 < -0x800000) {
                arg0 = -0x800000;
            } else if (arg0 >= 0x7fffff) {
                arg0 = 0x7fffff;
            }
            break;
        case 5:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xff) {
                arg0 = 0xff;
            }
            break;
        case 6:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xffff) {
                arg0 = 0xffff;
            }
            break;
        case 7:
            if (arg0 < 0) {
                arg0 = 0;
            } else if (arg0 >= 0xffffff) {
                arg0 = 0xffffff;
            }
            break;
    }
    return arg0;
}

// Opcode 9 PUSH_S24: pushes the (clamped) operand.
s32 Script_PushS24(Script* arg0, s64 arg1) {
    s32 val = Script_ClampValue(arg1, 4);

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

// Opcode 10 LOAD_LOCAL: pushes local variable operand.
s32 ScriptOp_LoadLocal(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    vm->stack[vm->sp] = vm->var[arg1];
    return 2;
}

// Reads 1, 2 or 4 bytes at offset arg0 of work buffer 2 into *arg2.
void Script_ReadWork(s32 arg0, s32 arg1, void* arg2) {
    u8* base = WorkBuffers_Get(2);

    switch (arg1) {
    case 1:
        *(u8*)arg2 = *(u8*)(base + arg0);
        break;
    case 2:
        *(u16*)arg2 = *(u16*)(base + arg0);
        break;
    case 4:
        *(s32*)arg2 = *(s32*)(base + arg0);
        break;
    }
}

// Returns the address of offset arg0 in work buffer 2.
s32 Script_GetWorkAddress(s32 arg0) {
    void* temp = WorkBuffers_Get(2); // todo: find proper struct for this argument
    return temp + arg0;
}

// Writes 1, 2 or 4 bytes from *arg2 to offset arg0 of work buffer 2.
void Script_WriteWork(s32 arg0, s32 arg1, void* arg2) {
    u8* base = WorkBuffers_Get(2);

    switch (arg1) {
    case 1:
        *(u8*)(base + arg0) = *(u8*)arg2;
        break;
    case 2:
        *(u16*)(base + arg0) = *(u16*)arg2;
        break;
    case 4:
        *(s32*)(base + arg0) = *(s32*)arg2;
        break;
    }
}

extern s8 D_003C2D30[];
extern s32 D_0038ACC4[];
extern s32 D_0038B4C4[];

// Opcode 12 LOAD_VAR8: pushes an 8-bit game variable.
s32 ScriptOp_LoadVar8(Script* arg0, s32 arg1) {
    s32 b1 = (s32)WorkBuffers_Get(1);
    s32 b2 = (s32)WorkBuffers_Get(2);

    arg0->unk_174[36] = arg1;
    if (arg1 < 0x800) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s8*)(b1 + arg1);
    } else if (arg1 < 0x900) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s8*)(b1 + arg1);
    } else if (arg1 < 0xB00) {
        arg1 -= 0x900;
        if ((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1) {
            arg0->unk_174[3]++;
            arg0->unk_174[arg0->unk_174[3] + 4] = D_0038B4C4[arg1];
        } else {
            arg0->unk_174[3]++;
            arg0->unk_174[arg0->unk_174[3] + 4] = D_0038ACC4[arg1];
        }
    } else if (arg1 < 0xC80) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(u8*)(arg1 + b1 - 0x200);
    } else if (arg1 < 0xCC0) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = D_003C2D30[arg1];
    } else if (arg1 < 0xD00) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = D_003C2D30[arg1];
    } else if (arg1 < 0xD40) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = D_003C2D30[arg1];
    } else {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s8*)(arg1 + b2 - 0xD40);
    }
    return 2;
}

// Opcode 14 LOAD_VAR16: pushes a 16-bit game variable.
s32 ScriptOp_LoadVar16(Script* arg0, s32 arg1) {
    s32 b1 = (s32)WorkBuffers_Get(1);
    s32 b2 = (s32)WorkBuffers_Get(2);

    arg0->unk_174[36] = arg1;
    if (arg1 < 0x800) {
        s32 t = *(s16*)(b1 + arg1);
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = t;
    } else if (arg1 < 0x900) {
        s32 t = *(s16*)(arg1 + b1);
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = t;
    } else {
        s32 t = *(s16*)(arg1 + b2 - 0xD40);
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = t;
    }
    return 2;
}

extern s32 D_0038ACC4[];
extern s32 D_0038B4C4[];

// Opcode 16 LOAD_VAR32: pushes a 32-bit game variable.
s32 ScriptOp_LoadVar32(Script* arg0, s32 arg1) {
    s32 b1 = (s32)WorkBuffers_Get(1);
    s32 b2 = (s32)WorkBuffers_Get(2);

    arg0->unk_174[36] = arg1;
    if (arg1 < 0x800) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(b1 + arg1);
    } else if (arg1 < 0x900) {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(arg1 + b1);
    } else if (arg1 < 0xB00) {
        arg1 -= 0x900;
        if ((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1) {
            arg0->unk_174[3]++;
            arg0->unk_174[arg0->unk_174[3] + 4] = D_0038B4C4[arg1];
        } else {
            arg0->unk_174[3]++;
            arg0->unk_174[arg0->unk_174[3] + 4] = D_0038ACC4[arg1];
        }
    } else {
        arg0->unk_174[3]++;
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(arg1 + b2 - 0xD40);
    }
    return 2;
}

// Opcode 18 (unused): does nothing.
s32 ScriptOp_Reserved18(void) {
    return 2;
}

// Opcode 19 (unused): does nothing.
s32 ScriptOp_Reserved19(void) {
    return 2;
}

// Opcode 20 (unused): does nothing.
s32 ScriptOp_Reserved20(void) {
    return 2;
}

// Opcode 30 LOAD_WORK_BIT.
INCLUDE_ASM("asm/nonmatchings/xkinetic", ScriptOp_LoadWorkBit);

// Opcode 11 STORE_LOCAL: pops a value into local variable operand.
s32 ScriptOp_StoreLocal(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->var[arg1] = vm->stack[vm->sp--];
    return 2;
}

// Opcode 13 STORE_VAR8.
INCLUDE_ASM("asm/nonmatchings/xkinetic", ScriptOp_StoreVar8);

// Opcode 15 STORE_VAR16.
INCLUDE_ASM("asm/nonmatchings/xkinetic", ScriptOp_StoreVar16);

// Opcode 17 STORE_VAR32.
INCLUDE_ASM("asm/nonmatchings/xkinetic", ScriptOp_StoreVar32);

// Opcode 31 STORE_WORK_BIT.
s32 ScriptOp_StoreWorkBit(Script* arg0, s32 arg1) {
    s32 b1 = (s32)WorkBuffers_Get(1);
    s32 b2 = (s32)WorkBuffers_Get(2);
    s32 bit = arg1 % 8;
    s32 mask;

    arg1 = arg1 / 8 - 0xD40;
    if (arg0->unk_174[arg0->unk_174[3] + 4] >= 2) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else if (arg0->unk_174[arg0->unk_174[3] + 4] < 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    mask = ~(1 << bit);
    ((u8*)b2)[arg1] &= mask;
    ((u8*)b2)[arg1] |= arg0->unk_174[arg0->unk_174[3] + 4] << bit;
    arg0->unk_174[3]--;
    return 2;
}

// Opcode 21 PUSH_S24_ALT: pushes the operand without clamping.
s32 ScriptOp_PushS24Alt(Script* arg0, s32 arg1) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg1;
    return 2;
}

// Probably sets thread slot b of a script to start at entry (used by START_THREAD).
INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3308);

s32 *func_001E98D0(s32, s32);
s32 func_001C3308(s32 *, s32, s32);

// Opcode 22 START_THREAD: pops a script number and a slot (0-7) and starts entry operand there.
s32 ScriptOp_StartThread(Script *arg0, s32 arg1) {
    ScriptVM *vm = (ScriptVM *)arg0;
    s32 a = vm->stack[vm->sp--];
    s32 b = vm->stack[vm->sp--];
    s32 *p;

    if (b < 0) {
        b = 0;
    } else if (b >= 8) {
        b = 7;
    }
    p = func_001E98D0((s32)(*(u64 *)((u8 *)vm + 0x328) >> 5) & 1, a);
    func_001C3308(p, b, p[arg1 + 31]);
    return 2;
}

// Opcode 23 WAIT_THREAD: pops a script number and a slot (0-7); while that slot is still in use (not -1) it moves the
// program counter back 2 (the wait runs again) and ends the frame.
s32 ScriptOp_WaitThread(Script *arg0) {
    ScriptVM *vm = (ScriptVM *)arg0;
    s32 a = vm->stack[vm->sp--];
    s32 b = vm->stack[vm->sp--];
    s32 *p;

    if (b < 0) {
        b = 0;
    } else if (b >= 8) {
        b = 7;
    }
    p = func_001E98D0((s32)(*(u64 *)((u8 *)vm + 0x328) >> 5) & 1, a);
    if (p[b + 0xBE] != -1) {
        arg0->unk_174[2] -= 2;
        return 4;
    }
    return 2;
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgK;
s32 func_001C4640(ScriptMsgK*);

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ u8 unk_004[0x178];
    /* 0x17C */ s32 unk_17C;
    /* 0x180 */ u8 unk_180[0x178];
    /* 0x2F8 */ s32 unk_2F8[8];
    /* 0x318 */ s32 unk_318;
    /* 0x31C */ u8 unk_31C[0xC];
    /* 0x328 */ u64 unk_328;
} ScriptK;

// Opcode 25 STOP_THREAD: pops a script number and a slot and stops that thread (6 if it is this script).
s32 ScriptOp_StopThread(Script* arg0) {
    ScriptVM* vm = (ScriptVM*)arg0;
    ScriptMsgK msg;
    s32 a = vm->stack[vm->sp--];
    s32 b = vm->stack[vm->sp--];
    ScriptK* p;
    s32 j;
    s32 t;

    if (b < 0) {
        b = 0;
    } else if (b >= 8) {
        b = 7;
    }
    p = (ScriptK*)func_001E98D0((s32)(*(u64*)((u8*)vm + 0x328) >> 5) & 1, a);
    if (p == (ScriptK*)arg0) {
        return 6;
    }
    p->unk_2F8[b] = -1;
    if (b != p->unk_318) {
        return 2;
    }
    for (j = b + 1; j < 8; j++) {
        if (p->unk_2F8[j] != -1) {
            p->unk_17C = p->unk_2F8[j];
            p->unk_318 = j;
            break;
        }
    }
    t = *(s32*)&p->unk_328 & 1;
    if (t == 1) {
        msg.unk_00 = 0x12;
        msg.unk_01 = 0;
        msg.unk_10[3] = 1.0f;
        msg.unk_10[0] = 0.0f;
        msg.unk_10[1] = 0.0f;
        msg.unk_04 = p->unk_000;
        msg.unk_10[2] = 0.0f;
        func_001C4640(&msg);
        p->unk_328 &= ~1;
    }
    return 2;
}

// Returns the opcode (top byte) of instruction arg1 at arg0.
s32 Script_GetOpcode(s32 arg0, s32 arg1) {
    return ((s8*)(arg0 + arg1 * 4))[3];
}

// Returns the signed 24-bit operand of instruction arg1 at arg0.
s32 Script_GetOperand(s32 arg0, s32 arg1) {
    return ((u8*)(arg0 + arg1 * 4))[0] | (((u8*)(arg0 + arg1 * 4))[1] << 8) |
           (((s8*)(arg0 + arg1 * 4))[2] << 16);
}
