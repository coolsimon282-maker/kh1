#include "ppp.h"

NOTHROW_FN(void func_0018FBB0(pppPObject* parent, s32* p, pppCtrlTable* ctbl));
s32 pppKeBornPtCmplCalc(pppPObject* pobj, s32* a1, pppCtrlTable* ctbl) {
    s32* p = a1;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p[2] != -1 && p[4] != -1) {
        func_0018FBB0(pobj, a1, ctbl);
    }
}

typedef struct {
    /* 0x0 */ s32 unk_00;
} VKeBornPtCmpl;

void pppKeBornPtCmplCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornPtCmpl*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornPtCmpl", func_0018FE28);
