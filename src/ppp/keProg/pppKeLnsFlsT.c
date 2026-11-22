#include "ppp.h"

void KeLnsFls_Init(void*);

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} PKeLnsFlsTDraw;

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ sceVu0FVECTOR scl;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u8 col[4];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ u16 unk_2C;
} KeLnsFlsTWork;

void func_001940F0(pppPObject* pobj, PKeLnsFlsTDraw* p, pppCtrlTable* ctbl);
void func_00195148(KeLnsFlsTWork* w, s32 arg1, s32 arg2);

void pppKeLnsFlsTDraw(pppPObject* pobj, PKeLnsFlsTDraw* p, pppCtrlTable* ctbl) {
    KeLnsFlsTWork* w = (KeLnsFlsTWork*)&pobj->val[ctbl->useVal[0]];

    func_001940F0(pobj, p, ctbl);
    if (p->cdt.time == pobj->time) {
        w->unk_20 = p->unk_0C;
        w->unk_28 = p->unk_10;
        w->unk_2C = p->unk_12;
    }
    w->col[0] = p->col[0] * ppvMng->colorR;
    w->col[1] = p->col[1] * ppvMng->colorG;
    w->col[2] = p->col[2] * ppvMng->colorB;
    w->col[3] = p->col[3] * ppvMng->colorA;
    sceVu0CopyVector(w->scl, ppvParScl);
    func_00195148(w, 0, 0);
}

void pppKeLnsFlsTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    void* fls = &pobj->val[ctbl->useVal[0]];

    KeLnsFls_Init(fls);
}

void pppKeLnsFlsTDes(void) {
}
