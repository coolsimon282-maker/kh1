#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 model;
    /* 0x08 */ f32 tu;
    /* 0x0C */ f32 dtu;
    /* 0x10 */ f32 ddtu;
    /* 0x14 */ f32 tv;
    /* 0x18 */ f32 dtv;
    /* 0x1C */ f32 ddtv;
} PDrawMdlTs;

typedef struct {
    /* 0x00 */ f32 tu;
    /* 0x04 */ f32 dtu;
    /* 0x08 */ f32 ddtu;
    /* 0x0C */ f32 tv;
    /* 0x10 */ f32 dtv;
    /* 0x14 */ f32 ddtv;
} VDrawMdlTs;

void pppDrawMdlTsCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VDrawMdlTs* v = (VDrawMdlTs*)&pobj->val[ctbl->useVal[2]];
    v->tv = v->dtv = v->ddtv = 0;
    v->tu = v->dtu = v->ddtu = 0;
}

void pppDrawMdlTsCalc(pppPObject* pobj, PDrawMdlTs* p, pppCtrlTable* ctbl) {
    VDrawMdlTs* v = (VDrawMdlTs*)&pobj->val[ctbl->useVal[2]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    v->dtu += v->ddtu;
    v->dtv += v->ddtv;
    v->tu += v->dtu;
    v->tv += v->dtv;
    if (p->cdt.time == pobj->time) {
        v->tu += p->tu;
        v->dtu += p->dtu;
        v->ddtu += p->ddtu;
        v->tv += p->tv;
        v->dtv += p->dtv;
        v->ddtv += p->ddtv;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppDrawMdlTs", pppDrawMdlTsDraw);
