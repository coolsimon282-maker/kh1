#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldWood", pppRyjDrawMatrixWorldWoodCon);

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00;
    /* 0x10 */ sceVu0FVECTOR unk_10;
} VRyjDrawMatrixWorldWood;

extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FMATRIX D_006160C0;

void pppRyjDrawMatrixWorldWoodCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldWood* v = (VRyjDrawMatrixWorldWood*)&pobj->val[ctbl->useVal[1]];
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[3][0] = v->unk_00[0];
    m[3][1] = v->unk_00[1];
    m[3][2] = v->unk_00[2];
    sceVu0MulMatrix(m, D_00615EB0, m);
    sceVu0MulMatrix(m, ppvScreenMatrix, m);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], v->unk_10[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], v->unk_10[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], v->unk_10[2]);
    *(u_long128*)ppvPObj.next->dmat[3] = *(u_long128*)ppvPObj.next->cmat[3];
    sceVu0MulMatrix(ppvPObj.next->dmat, D_006160C0, ppvPObj.next->dmat);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], m, ppvPObj.next->cmat[3]);
}
