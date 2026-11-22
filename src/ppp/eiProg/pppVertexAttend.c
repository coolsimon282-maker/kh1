#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ char pad_04[8];
    /* 0xC */ s16 vsfNo;
} PVertexAttend;

typedef union {
    sceVu0FVECTOR f;
    s16 s[8];
} FVS;

void pppVertexAttendCalc(pppPObject* pobj, PVertexAttend* p, pppCtrlTable* ctbl) {
    FVS v;
    pppVsfSt* vsf;
    pppSVECTOR* vert;
    f32* out;
    u16 idx;

    if (p->vsfNo < 0) {
        return;
    }
    vsf = &ppvEnv->lpVsf[p->vsfNo];
    vert = &ppvEnv->lpModel[(s16)vsf->modelNo].vert[((u16*)vsf->index)[*(u16*)&pobj->val[ctbl->useVal[0]]]];
    out = (f32*)&pobj->val[ctbl->useVal[1]];
    v.f[0] = vert->x;
    v.f[1] = vert->y;
    v.f[2] = vert->z;
    v.f[3] = 1.0f;
    sceVu0ApplyMatrix(v.f, pobj->ppobj->cmat, v.f);
    out[0] = v.f[0];
    out[1] = v.f[1];
    out[2] = v.f[2];
}
