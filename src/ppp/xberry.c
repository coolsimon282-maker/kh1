#include "common.h"

#include "ppp/pppUtil.h"
#include "ppp/pppKeLns.h"

#include "libvu0.h"

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", KeBornRnd2);

// reads the u16 at 0x12 of the shape data (a count; maybe its number of frames)
void func_001A75B0(KeLnsFlr* flr, pppShapeSt* shp) {
    flr->cnt = ((u16*)shp->shape)[9];
    flr->seqIdx = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A75C8);

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A7668);

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A76E8);

void KeLnsLp_Init(KeLnsLp* lp) {
    ppvMng->drawPriority = 2;
    sceVu0UnitMatrix(lp->zMat);
    lp->preHidePow = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A7C40);

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A7F48);

void KeLnsClm_Init(KeLnsClm* p) {
    p->flag = 0;
    p->lp = &ppvDbgTemp;
    p->shp = NULL;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A8060);

void KeLnsArnd_Init(KeLnsArnd* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A8248);

void func_001A84B8(KeLnsCrn* p, pppShapeSt* shp) {
    p->shp = shp;
    func_001A75B0(&p->flr, shp);
}

void KeLnsCrn_Init(KeLnsCrn* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", KeLnsFls_Draw);

void KeLnsFls_Init(KeLnsFls* p) {
    p->shp = NULL;
    p->lp = &ppvDbgTemp;
}

INCLUDE_ASM("asm/nonmatchings/ppp/xberry", func_001A8770);
