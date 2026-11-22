#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsClm", pppKeLnsClmDraw);

void pppKeLnsClmCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsClm_Init(clm);
    clm->num = 4;
}

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ s32 shpIdx;
} PKeLnsClm;

void func_001A84B8(KeLnsClm* p, pppShapeSt* shp);

void func_00193E80(pppPObject* pobj, PKeLnsClm* p, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];
    pppShapeSt* shp;

    if (p->cdt.time == pobj->time) {
        *(s32*)&clm->lp = (s32)&pobj->val[ctbl->useVal[1]];
        if (p->shpIdx == 0xFFFF) {
            clm->shp = NULL;
        } else {
            shp = &ppvEnv->lpShape[p->shpIdx];
            if (shp != clm->shp) {
                func_001A84B8(clm, shp);
            }
        }
    }
}
