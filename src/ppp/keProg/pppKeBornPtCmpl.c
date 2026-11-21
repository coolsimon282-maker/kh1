#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornPtCmpl", pppKeBornPtCmplCalc);

typedef struct {
    /* 0x0 */ s32 unk_00;
} VKeBornPtCmpl;

void pppKeBornPtCmplCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornPtCmpl*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornPtCmpl", func_0018FE28);
