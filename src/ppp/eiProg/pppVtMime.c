#include "ppp.h"

typedef struct {
    /* 0x0 */ f32 inp;
    /* 0x4 */ f32 dinp;
    /* 0x8 */ f32 ddinp;
    /* 0xC */ pppFVECTOR* lpvt;
} VVtMime;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u8 unk_04[8];
    /* 0x0C */ f32 inp;
    /* 0x10 */ f32 dinp;
    /* 0x14 */ f32 ddinp;
} PVtMime;

void pppVtMimeCalc(pppPObject* pobj, PVtMime* p, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v->dinp += v->ddinp;
    v->inp += v->dinp;
    if (p->cdt.time == pobj->time) {
        v->inp += p->inp;
        v->dinp += p->dinp;
        v->ddinp += p->ddinp;
    }
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 mdl0;
    /* 0x08 */ s32 mdl1;
} PVtMimeDraw;

void pppVtMimeDraw(pppPObject* pobj, PVtMimeDraw* p, pppCtrlTable* ctbl) {
    VVtMime* v;
    pppModelSt* m0;
    pppModelSt* m1;
    pppSVECTOR* src;
    pppSVECTOR* dst;
    pppSVECTOR* out;
    s32 n;

    if (p->mdl0 == 0xFFFF && p->mdl1 == 0xFFFF) {
        return;
    }
    v = (VVtMime*)&pobj->val[ctbl->useVal[0]];
    m0 = (pppModelSt*)(p->mdl0 * sizeof(pppModelSt) + (u32)ppvEnv->lpModel);
    src = m0->vert;
    m1 = (pppModelSt*)(p->mdl1 * sizeof(pppModelSt) + (u32)ppvEnv->lpModel);
    dst = m1->vert;
    n = m0->nvert;
    if (v->lpvt == NULL) {
        v->lpvt = pppDbgAlloc(ppvEnv, n * 6);
    }
    out = (pppSVECTOR*)v->lpvt;
    while (n-- != 0) {
        out->x = (dst->x - src->x) * v->inp + src->x;
        out->y = (dst->y - src->y) * v->inp + src->y;
        out->z = (dst->z - src->z) * v->inp + src->z;
        src++;
        dst++;
        out++;
    }
    ppvPObj.next->lpvert = (pppSVECTOR*)v->lpvt;
}

void pppVtMimeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    v->lpvt = NULL;
    v->inp = v->dinp = v->ddinp = 0;
}

void pppVtMimeCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    v->inp = v->dinp = v->ddinp = 0;
}

void pppVtMimeDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVtMime* v = (VVtMime*)&pobj->val[ctbl->useVal[0]];

    if (v->lpvt != NULL) {
        pppFree(ppvEnv, v->lpvt);
        v->lpvt = NULL;
    }
}
