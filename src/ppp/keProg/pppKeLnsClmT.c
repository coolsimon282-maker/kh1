#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsClmT", pppKeLnsClmTDraw);

void pppKeLnsClmTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsClm* clm = (KeLnsClm*)&pobj->val[ctbl->useVal[0]];

    KeLnsClm_Init(clm);
    clm->num = 4;
}

void pppKeLnsClmTDes(void) {
}

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} KeLnsClmTArg;

typedef struct {
    /* 0x00 */ KeLnsClmTArg* arg;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ sceVu0FMATRIX* mat;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ void* unk_14;
} KeLnsClmTDrawSt;

void func_001A8248(KeLnsClmTDrawSt* st, s32 arg1);

void func_00194E58(KeLnsClmTArg* arg) {
    KeLnsClmTDrawSt st;

    st.unk_04 = arg->unk_24;
    st.unk_10 = (u32)arg->unk_28;
    st.unk_12 = (u32)arg->unk_2C;
    st.unk_14 = arg->unk_10;
    st.arg = arg;
    st.unk_0C = arg->unk_20;
    st.mat = &ppvScreenMatrix;
    func_001A8248(&st, 0);
}
