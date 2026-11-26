/**
 * Event script runner (the opcode handlers are in xkinetic.c) and functions on the event system's big state block
 * D_003854E0 (XGiantMountain).
 */
#include "xhumungus.h"
#include "xflamingo.h"

typedef s32 (*XHumungusFunc2)(UNK_PTR, s32);

extern XHumungusFunc2 scriptOpTable[];
extern XGiantMountain D_003854E0;

s32 Script_GetOpcode(s32, s32);
s32 Script_GetOperand(s32, s32);

// Runs script entry arg1 at once, up to END or a handler returning 4 or 8, then puts the program counter back.
void Script_ExecuteEntry(Script* arg0, s32 arg1) {
    s32 initialPos = arg0->unk_174[2];
    s32 idx;
    s32 result;
    s32 temp_5;

    arg0->unk_174[2] = arg0->unk_7C[arg1];

    while (TRUE) {
        idx = Script_GetOpcode(arg0->unk_70, arg0->unk_174[2]);
        temp_5 = Script_GetOperand(arg0->unk_70, arg0->unk_174[2]);
        if (idx == 5) {
            break;
        }
        result = scriptOpTable[idx](arg0, temp_5);
        if (result & 2) {
            arg0->unk_174[2]++;
        }
        if (result & 4) {
            break;
        }
        if (result & 8) {
            break;
        }
    }
    arg0->unk_174[2] = initialPos;
}

#ifdef VERSION_FM
extern s32 D_003F34A4;

// Returns 0 while D_003F34A4 is 1; otherwise clears flag 0x1000 of D_003854E0.unk_3078 and returns 4.
s32 fm_func_001C1DF8(void) {
    if (D_003F34A4 == 1) {
        return 0;
    }
    D_003854E0.unk_3078 &= ~0x1000;
    return 4;
}
#endif

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C3780);

// Sets bit 40 of D_003854E0.unk_3070.
void func_001C38C0(void) {
    D_003854E0.unk_3070 |= 0x10000000000;
}

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C38E0);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4000);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4260);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4598);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4668);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4740);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4C80);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C4FF0);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C5390);

INCLUDE_ASM("asm/nonmatchings/xflamingo", func_001C5918);
