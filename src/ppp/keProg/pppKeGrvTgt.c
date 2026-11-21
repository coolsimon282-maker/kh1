#include "ppp.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} VKeGrvTgt;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeGrvTgt", pppKeGrvTgtCalc);

void pppKeGrvTgtCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeGrvTgt*)&pobj->val[ctbl->useVal[1]])->unk_08 = 0;
}
