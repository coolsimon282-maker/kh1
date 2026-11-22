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

extern sceVu0FMATRIX D_00615EB0;

// FM's ppp code was compiled as if without strict aliasing: the float stores below make the compiler
// reload ppvPObj.next. Reading it through a union gets the same (alias set 0) behaviour.
typedef union {
    pppPObject* next;
} PObjNext;

#define NEXT (((PObjNext*)&ppvPObj)->next)

void pppRyjDrawMatrixWorldNoRotCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldNoRot* v = (VRyjDrawMatrixWorldNoRot*)&pobj->val[ctbl->useVal[1]];
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[3][0] = v->unk_00[0];
    m[3][1] = v->unk_00[1];
    m[3][2] = v->unk_00[2];
    sceVu0MulMatrix(m, D_00615EB0, m);
    sceVu0ScaleVector(NEXT->dmat[0], NEXT->cmat[0], v->unk_10[0]);
    sceVu0ScaleVector(NEXT->dmat[1], NEXT->cmat[1], v->unk_10[1]);
    sceVu0ScaleVector(NEXT->dmat[2], NEXT->cmat[2], v->unk_10[2]);
    sceVu0MulVector(NEXT->dmat[3], NEXT->cmat[3], v->unk_10);
    NEXT->dmat[3][0] += m[3][0];
    NEXT->dmat[3][1] += m[3][1];
    NEXT->dmat[3][2] += m[3][2];
    sceVu0MulMatrix(NEXT->dmat, ppvScreenMatrix, NEXT->dmat);
}
