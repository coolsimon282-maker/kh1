#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ f32 ofs[3];
    /* 0x10 */ f32 scl[3];
    /* 0x1C */ u8 mode;
} PKeZCrctShp;

extern sceVu0FMATRIX D_00615E70;
extern sceVu0FMATRIX D_00615EB0;

void pppKeZCrctShpCalc(pppPObject* pobj, PKeZCrctShp* p, pppCtrlTable* ctbl) {
    sceVu0FVECTOR* out = (sceVu0FVECTOR*)&pobj->val[ctbl->useVal[0]];
    sceVu0FMATRIX m;
    sceVu0FVECTOR t;

    sceVu0ScaleVector(m[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(m[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(m[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    sceVu0CopyVector(t, ppvPObj.next->cmat[3]);
    t[0] *= p->scl[0];
    t[1] *= p->scl[1];
    t[2] *= p->scl[2];
    switch (p->mode) {
    case 0:
        t[0] += p->ofs[0];
        t[1] += p->ofs[1];
        t[2] += p->ofs[2];
        sceVu0ApplyMatrix(m[3], ppvWorldMatrix, t);
        break;
    case 1:
        sceVu0ApplyMatrix(m[3], ppvWorldMatrix, t);
        m[3][0] += p->ofs[0];
        m[3][1] += p->ofs[1];
        m[3][2] += p->ofs[2];
        break;
    case 2:
        sceVu0ApplyMatrix(m[3], D_00615E70, t);
        m[3][0] += p->ofs[0] * ppvParScl[0];
        m[3][1] += p->ofs[1] * ppvParScl[1];
        m[3][2] += p->ofs[2] * ppvParScl[2];
        sceVu0ApplyMatrix(m[3], D_00615EB0, m[3]);
        break;
    }
    sceVu0MulMatrix(out, ppvScreenMatrix, m);
}
