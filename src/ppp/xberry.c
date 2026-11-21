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

typedef struct XBerryNode {
    /* 0x00 */ u8 unk_00[0x8];
    /* 0x08 */ struct XBerryNode* next;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[0x2E];
    /* 0x3E */ u16 flags;
} XBerryNode;

typedef struct {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ XBerryNode* list;
} XBerryNodeOwner;

void func_001A8770(XBerryNodeOwner* arg0, s32 flags) {
    XBerryNode* node = arg0->list;

    flags |= 8;
    while (node != NULL) {
        node->unk_0C = 0;
        node->flags |= flags;
        node = node->next;
    }
}
