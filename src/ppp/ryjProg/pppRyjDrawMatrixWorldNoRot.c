#include "ppp.h"

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00;
    /* 0x10 */ sceVu0FVECTOR unk_10;
} VRyjDrawMatrixWorldNoRot;

extern sceVu0FVECTOR D_003701D0;

void pppRyjDrawMatrixWorldNoRotCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldNoRot* v = (VRyjDrawMatrixWorldNoRot*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyVector(v->unk_00, D_003701D0);
    sceVu0CopyVector(v->unk_10, ppvParScl);
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldNoRot", pppRyjDrawMatrixWorldNoRotCalc);
