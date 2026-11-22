#include "ppp.h"

#include "libvu0.h"

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00;
    /* 0x10 */ sceVu0FVECTOR unk_10;
} VRyjDrawMatrixWorldFront;

extern sceVu0FVECTOR D_003701D0;

void pppRyjDrawMatrixWorldFrontCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldFront* v = (VRyjDrawMatrixWorldFront*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyVector(v->unk_00, D_003701D0);
    sceVu0CopyVector(v->unk_10, ppvParScl);
}

extern sceVu0FMATRIX D_00615EB0;

void pppRyjDrawMatrixWorldFrontCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldFront* v = (VRyjDrawMatrixWorldFront*)&pobj->val[ctbl->useVal[1]];
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[3][0] = v->unk_00[0];
    m[3][1] = v->unk_00[1];
    m[3][2] = v->unk_00[2];
    sceVu0MulMatrix(m, D_00615EB0, m);
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], v->unk_10[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], v->unk_10[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], v->unk_10[2]);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], m, ppvPObj.next->cmat[3]);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
