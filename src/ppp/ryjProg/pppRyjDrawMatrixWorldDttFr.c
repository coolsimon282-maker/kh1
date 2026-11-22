#include "ppp.h"

extern sceVu0FVECTOR D_003701D0;

void pppRyjDrawMatrixWorldDttFrCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyVector((f32*)(v + 0x40), D_003701D0);
    sceVu0CopyVector((f32*)(v + 0x50), ppvParScl);
}

#ifdef VERSION_FM
extern sceVu0FMATRIX D_00615EB0;

void pppRyjDrawMatrixWorldDttFrCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    u8* v = (u8*)&pobj->val[ctbl->useVal[1]];
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[3][0] = ((f32*)(v + 0x40))[0];
    m[3][1] = ((f32*)(v + 0x40))[1];
    m[3][2] = ((f32*)(v + 0x40))[2];
    sceVu0MulMatrix(m, D_00615EB0, m);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ((f32*)(v + 0x50))[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ((f32*)(v + 0x50))[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ((f32*)(v + 0x50))[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], m, ppvPObj.next->cmat[3]);
    sceVu0CopyMatrix((void*)v, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
#else
INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", pppRyjDrawMatrixWorldDttFrCalc);
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A3F98);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A3FE0);

s32 func_001A4040(s32* arg0, ppvmng* arg1) {
    if (arg0[0] == 0) {
        return 0;
    }
    if (arg1->unk_B6 != 0) {
        if (arg0[1] == 0) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4070);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4538);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4680);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4BC8);
