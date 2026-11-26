#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} PKeLnsFls;

typedef struct {
    /* 0x00 */ KeLnsFls* fls;
    /* 0x04 */ u8 col[4];
    /* 0x08 */ sceVu0FVECTOR* scr;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ f32* scl;
} KeLnsFlsDrawInfo;

void KeLnsCrn_Start(pppPObject* pobj, PKeLnsFls* p, pppCtrlTable* ctbl);
void KeLnsFls_Draw(KeLnsFlsDrawInfo* info, s32 arg1);

void pppKeLnsFlsDraw(pppPObject* pobj, PKeLnsFls* p, pppCtrlTable* ctbl) {
    KeLnsFlsDrawInfo info;

    KeLnsCrn_Start(pobj, p, ctbl);
    info.col[0] = p->col[0] * ppvMng->colorR;
    info.col[1] = p->col[1] * ppvMng->colorG;
    info.col[2] = p->col[2] * ppvMng->colorB;
    info.col[3] = p->col[3] * ppvMng->colorA;
    info.scr = ppvScreenMatrix;
    info.unk_0C = p->unk_0C;
    info.unk_10 = p->unk_10;
    info.unk_12 = p->unk_12;
    info.fls = (KeLnsFls*)&pobj->val[ctbl->useVal[0]];
    info.scl = ppvParScl;
    KeLnsFls_Draw(&info, 0);
}

void pppKeLnsFlsCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsFls* fls = (KeLnsFls*)&pobj->val[ctbl->useVal[0]];
    
    KeLnsFls_Init(fls);
}

// Draws the flare effect for KeLnsLpT (builds the draw info for KeLnsFls_Draw, probably).
INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsFls", KeLnsFlsLp_Draw);
