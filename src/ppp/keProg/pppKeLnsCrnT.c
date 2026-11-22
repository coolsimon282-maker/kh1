#include "ppp/pppKeLns.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 shpIdx;
    /* 0x08 */ u8 col[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} PKeLnsCrnTDraw;

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ sceVu0FVECTOR scl;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u8 col[4];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} KeLnsCrnTWork;

void func_00193E80(pppPObject* pobj, PKeLnsCrnTDraw* p, pppCtrlTable* ctbl);
void func_00194E58(KeLnsCrnTWork* w, s32 arg1, s32 arg2);

void pppKeLnsCrnTDraw(pppPObject* pobj, PKeLnsCrnTDraw* p, pppCtrlTable* ctbl) {
    KeLnsCrnTWork* w = (KeLnsCrnTWork*)&pobj->val[ctbl->useVal[0]];

    func_00193E80(pobj, p, ctbl);
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
    func_00194E58(w, 0, 0);
}

void pppKeLnsCrnTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsCrn* crn = (KeLnsCrn*)&pobj->val[ctbl->useVal[0]];

    KeLnsCrn_Init(crn);
}

void pppKeLnsCrnTDes(void) {
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u8 unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ u16 unk_2C;
} KeLnsCrnTObj;
typedef struct {
    /* 0x00 */ KeLnsCrnTObj* obj;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ sceVu0FVECTOR* mat;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ void* unk_14;
} KeLnsFlsPrm;
void KeLnsFls_Draw(KeLnsFlsPrm*, s32); // ppp/xberry

void func_00195148(KeLnsCrnTObj* a) {
    KeLnsFlsPrm prm;

    prm.unk_04 = a->unk_24;
    prm.unk_0C = a->unk_20;
    prm.unk_10 = (u32)a->unk_28;
    prm.obj = a;
    prm.unk_12 = a->unk_2C;
    prm.mat = ppvScreenMatrix;
    prm.unk_14 = a->unk_10;
    KeLnsFls_Draw(&prm, 0);
}
