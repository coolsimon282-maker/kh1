#include "ppp.h"

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00[4];
    /* 0x40 */ sceVu0FMATRIX mat;
} VRyjDrawMatrixWorldDtt;

extern sceVu0FMATRIX D_00615E70;

void pppRyjDrawMatrixWorldDttCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldDtt* v = (VRyjDrawMatrixWorldDtt*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyMatrix(v->mat, D_00615E70);
}

extern sceVu0FMATRIX D_00615EB0;

void pppRyjDrawMatrixWorldDttCalc(pppPObject* pobj, void* data, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldDtt* v = (VRyjDrawMatrixWorldDtt*)&pobj->val[ctbl->useVal[1]];

    sceVu0MulMatrix(ppvPObj.next->dmat, v->mat, ppvPObj.next->cmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, D_00615EB0, ppvPObj.next->dmat);
    sceVu0CopyMatrix(v->unk_00, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
