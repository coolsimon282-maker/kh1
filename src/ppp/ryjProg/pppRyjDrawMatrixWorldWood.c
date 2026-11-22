#include "ppp.h"

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00;
    /* 0x10 */ sceVu0FVECTOR unk_10;
} VRyjDrawMatrixWorldWood;

extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FMATRIX D_006160C0;
extern sceVu0FMATRIX D_00616000;
extern sceVu0FVECTOR D_003701D0;

void pppRyjDrawMatrixWorldWoodCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldWood* v = (VRyjDrawMatrixWorldWood*)&pobj->val[ctbl->useVal[1]];
    sceVu0FVECTOR x;
    sceVu0FVECTOR y;
    sceVu0FVECTOR z;

    sceVu0CopyVector(v->unk_00, D_003701D0);
    sceVu0CopyVector(v->unk_10, ppvParScl);
    y[0] = ppvWorldMatrix[1][0];
    y[1] = ppvWorldMatrix[1][1];
    y[2] = ppvWorldMatrix[1][2];
    y[3] = 0.0f;
    sceVu0Normalize(y, y);
    *(u_long128*)D_00616000[1] = *(u_long128*)y;
    x[0] = y[1];
    x[1] = -y[0];
    x[2] = 0.0f;
    x[3] = 0.0f;
    sceVu0Normalize(x, x);
    *(u_long128*)D_00616000[0] = *(u_long128*)x;
    sceVu0OuterProduct(z, x, y);
    sceVu0Normalize(z, z);
    *(u_long128*)D_00616000[2] = *(u_long128*)z;
    *(u_long128*)D_00616000[3] = *(u_long128*)ppvWorldMatrix[3];
    sceVu0MulMatrix(D_006160C0, ppvScreenMatrix, D_00616000);
}

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
