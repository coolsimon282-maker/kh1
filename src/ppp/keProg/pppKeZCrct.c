#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ f32 ofs[3];
    /* 0x10 */ f32 scl[3];
    /* 0x1C */ u8 mode;
} PKeZCrct;

extern sceVu0FMATRIX D_00615E70;
extern sceVu0FMATRIX D_00615EB0;
extern sceVu0FMATRIX D_00616000;

void pppKeZCrctCalc(pppPObject* pobj, PKeZCrct* p, pppCtrlTable* ctbl) {
    sceVu0FVECTOR* out = (sceVu0FVECTOR*)&pobj->val[ctbl->useVal[0]];
    sceVu0FMATRIX m;

    sceVu0ScaleVector(m[0], ppvPObj.next->cmat[0], p->scl[0]);
    sceVu0ScaleVector(m[1], ppvPObj.next->cmat[1], p->scl[1]);
    sceVu0ScaleVector(m[2], ppvPObj.next->cmat[2], p->scl[2]);
    sceVu0CopyVector(m[3], ppvPObj.next->cmat[3]);
    switch (p->mode) {
        case 0:
            m[3][0] += p->ofs[0];
            m[3][1] += p->ofs[1];
            m[3][2] += p->ofs[2];
            sceVu0MulMatrix(m, ppvWorldMatrix, m);
            break;
        case 1:
            sceVu0MulMatrix(m, ppvWorldMatrix, m);
            m[3][0] += p->ofs[0];
            m[3][1] += p->ofs[1];
            m[3][2] += p->ofs[2];
            break;
        case 2:
            sceVu0MulMatrix(m, D_00615E70, m);
            m[3][0] += p->ofs[0] * ppvParScl[0];
            m[3][1] += p->ofs[1] * ppvParScl[1];
            m[3][2] += p->ofs[2] * ppvParScl[2];
            sceVu0MulMatrix(m, D_00615EB0, m);
            break;
        case 3:
            sceVu0MulMatrix(m, D_00616000, m);
            m[3][0] += p->ofs[0];
            m[3][1] += p->ofs[1];
            m[3][2] += p->ofs[2];
            break;
    }
    sceVu0MulMatrix(out, ppvScreenMatrix, m);
}
