#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ KeLnsLp lp;
    /* 0xB0 */ u8 unk_B0[0x10];
    /* 0xC0 */ u8 unk_C0;
    /* 0xC1 */ u8 unk_C1;
} KeLnsLpT;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u8 unk_04[0xA];
    /* 0x0E */ u8 rx;
    /* 0x0F */ u8 ry;
    /* 0x10 */ u8 mbk;
} PKeLnsLpT;

void pppKeLnsLpDraw(pppPObject* pobj, PKeLnsLpT* p, pppCtrlTable* ctbl);
void func_00194350(KeLnsLpT* lp, s32 arg1, s32 frame);

void pppKeLnsLpTDraw(pppPObject* pobj, PKeLnsLpT* p, pppCtrlTable* ctbl) {
    KeLnsLpT* lp;
    sceVu0FVECTOR t;

    pppKeLnsLpDraw(pobj, p, ctbl);
    lp = (KeLnsLpT*)&pobj->val[ctbl->useVal[0]];
    if (p->cdt.time == pobj->time) {
        lp->unk_C0 = p->rx * 8;
        lp->unk_C1 = p->ry * 4;
        lp->lp.mbk = p->mbk;
    }
    t[0] = 0.0f;
    t[1] = 0.0f;
    t[2] = 0.0f;
    t[3] = 1.0f;
    sceVu0ApplyMatrix(t, ppvPObj.next->dmat, t);
    sceVu0ScaleVector((f32*)lp->unk_B0, t, 1.0f / t[3]);
    func_00194350(lp, 0, 0);
}

#ifdef VERSION_FM
// .data (0x00372708-0x00372710)
u8 D_00372708 = 0; // next lens index
#else
extern u8 D_00372708; // next lens index
#endif

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

void KeLnsShp_Draw(KeLnsLpTArg* arg, s32 arg1);

void func_00194980(KeLnsLpTUnk* arg0) {
    KeLnsLpTArg arg;

    arg.unk_00 = arg0;
    arg.unk_04 = arg0->unk_24;
    arg.unk_0C = arg0->unk_20;
    arg.unk_08 = ppvScreenMatrix;
    arg.unk_10 = &arg0->unk_10;
    KeLnsShp_Draw(&arg, 0);
}
