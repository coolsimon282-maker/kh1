#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsCrnT", pppKeLnsCrnTDraw);

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
