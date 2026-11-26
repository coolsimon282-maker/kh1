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

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C21B8);

s32 ScriptOp_Nop(void) {
    return 2;
}

s32 ScriptOp_JumpRelative(Script* arg0, s32 arg1) {
    arg0->unk_174[2] += arg1;
    if (arg1 < 0) {
        return 4;
    }
    return 1;
}

s32 func_001C2298(Script* arg0, s32 arg1) {
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

s32 func_001C22E8(void) {
    return 2;
}

s32 func_001C22F0(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->unk_270[arg1] = vm->stack[vm->sp];
    vm->unk_2F0 = arg1;
    vm->sp--;
    return 2;
}

s32 func_001C2328(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] == arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

s32 func_001C2370(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] < arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

s32 func_001C23C0(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] <= arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

s32 func_001C2410(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] > arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

s32 func_001C2460(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    if (vm->unk_270[vm->unk_2F0] >= arg1) {
        vm->stack[vm->sp] = 1;
    } else {
        vm->stack[vm->sp] = 0;
    }
    return 2;
}

s32 func_001C24B0(Script* arg0) {
    arg0->unk_2F0--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C24C8);

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

s32 Script_PushS24(Script* arg0, s64 arg1) {
    s32 val = Script_ClampValue(arg1, 4);

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001C26F8(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->sp++;
    vm->stack[vm->sp] = vm->var[arg1];
    return 2;
}

void func_001C2728(s32 arg0, s32 arg1, void* arg2) {
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

s32 Script_GetWorkAddress(s32 arg0) {
    void* temp = WorkBuffers_Get(2); // todo: find proper struct for this argument
    return temp + arg0;
}

void func_001C2808(s32 arg0, s32 arg1, void* arg2) {
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

s32 func_001C28B8(Script* arg0, s32 arg1) {
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

s32 func_001C2AA0(Script* arg0, s32 arg1) {
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

s32 func_001C2B60(Script* arg0, s32 arg1) {
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

s32 func_001C2CA0(void) {
    return 2;
}

s32 func_001C2CA8(void) {
    return 2;
}

s32 func_001C2CB0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2CB8);

s32 func_001C2D40(Script* arg0, s32 arg1) {
    ScriptVM* vm = (ScriptVM*)arg0;

    vm->var[arg1] = vm->stack[vm->sp--];
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2D70);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C2FB0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C30A0);

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3208);

s32 func_001C32E8(Script* arg0, s32 arg1) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg1;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3308);

s32 *func_001E98D0(s32, s32);
s32 func_001C3308(s32 *, s32, s32);

s32 func_001C3380(Script *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/nonmatchings/xkinetic", func_001C3430);

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

s32 func_001C34E0(Script* arg0) {
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

s32 func_001C3670(s32 arg0, s32 arg1) {
    return ((s8*)(arg0 + arg1 * 4))[3];
}

s32 func_001C3680(s32 arg0, s32 arg1) {
    return ((u8*)(arg0 + arg1 * 4))[0] | (((u8*)(arg0 + arg1 * 4))[1] << 8) |
           (((s8*)(arg0 + arg1 * 4))[2] << 16);
}
