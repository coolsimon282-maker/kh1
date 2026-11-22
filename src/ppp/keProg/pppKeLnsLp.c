#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ f32 lWid;
    /* 0x8 */ f32 pow;
    /* 0xC */ u8 r;
    /* 0xD */ u8 md;
} PKeLnsLp;

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLp", pppKeLnsLpDraw);

void pppKeLnsLpCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    KeLnsLp_Init(lp);
    lp->lVec[3] = 0;
    lp->pow = 0;
}

void pppKeLnsLpCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    lp->lVec[3] = 0;
    lp->pow = 0;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpNo;
} PKeLnsLpShp;

void func_00193978(pppPObject* pobj, PKeLnsLpShp* p, pppCtrlTable* ctbl) {
    KeLnsArnd* v = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];
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
