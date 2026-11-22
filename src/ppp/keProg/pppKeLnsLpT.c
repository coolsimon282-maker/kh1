#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsLpT", pppKeLnsLpTDraw);

typedef struct {
    /* 0x00 */ KeLnsLp lp;
    /* 0xB0 */ u8 unk_B0[0x10];
    /* 0xC0 */ u8 unk_C0;
    /* 0xC1 */ u8 unk_C1;
} KeLnsLpT;

extern u8 D_00372708; // next lens index

void pppKeLnsLpTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLpT* p = (KeLnsLpT*)&pobj->val[ctbl->useVal[0]];

    KeLnsLp_Init(&p->lp);
    p->lp.lVec[3] = 0;
    p->lp.pow = 0;
    p->lp.idx = D_00372708;
    p->lp.mbk = 2;
    p->unk_C0 = 0;
    p->unk_C1 = 0;
    D_00372708++;
}

void pppKeLnsLpTCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsLp* lp = (KeLnsLp*)&pobj->val[ctbl->useVal[0]];

    lp->lVec[3] = 0;
    lp->pow = 0;
}

void pppKeLnsLpTDes(void) {
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u8 unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
} KeLnsLpTUnk;

typedef struct {
    /* 0x00 */ KeLnsLpTUnk* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 (*unk_08)[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ void* unk_10;
} KeLnsLpTArg;

void func_001A8060(KeLnsLpTArg* arg, s32 arg1);

void func_00194980(KeLnsLpTUnk* arg0) {
    KeLnsLpTArg arg;

    arg.unk_00 = arg0;
    arg.unk_04 = arg0->unk_24;
    arg.unk_0C = arg0->unk_20;
    arg.unk_08 = ppvScreenMatrix;
    arg.unk_10 = &arg0->unk_10;
    func_001A8060(&arg, 0);
}
