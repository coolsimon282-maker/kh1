#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsCrn", pppKeLnsCrnDraw);

void pppKeLnsCrnCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsCrn* crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];

    KeLnsCrn_Init(crn);
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpNo;
} PKeLnsCrnShp;

void func_001940F0(pppPObject* pobj, PKeLnsCrnShp* p, pppCtrlTable* ctbl) {
    KeLnsCrn* v = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&v->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpNo == 0xFFFF) {
            v->shp = NULL;
            return;
        }
        shp = &ppvEnv->lpShape[p->shpNo];
        if (shp != v->shp) {
            *(s32*)&v->shp = (s32)shp;
            v->flr.cnt = ((u16*)*(s32*)shp)[9];
            v->flr.seqIdx = 0;
        }
    }
}
