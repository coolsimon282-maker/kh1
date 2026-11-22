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

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVtMime", pppVtMimeDraw);

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
