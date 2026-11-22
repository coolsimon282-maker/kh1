#include "ppp/pppKeLns.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeLnsArndT", pppKeLnsArndTDraw);

void pppKeLnsArndTCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeLnsArnd* arnd = (KeLnsArnd*)&pobj->val[ctbl->useVal[0]];

    KeLnsArnd_Init(arnd);
}

void pppKeLnsArndTDes(void) {
}

typedef union {
    f32 f;
    s32 i;
} KeLnsArndTVal;

typedef struct {
    /* 0x00 */ u8 unk_00[0x30];
    /* 0x30 */ u8 unk_30[0x10];
    /* 0x40 */ KeLnsArndTVal unk_40;
    /* 0x44 */ KeLnsArndTVal unk_44;
    /* 0x48 */ KeLnsArndTVal unk_48;
} KeLnsArndTUnk;

typedef struct {
    /* 0x00 */ KeLnsArndTUnk* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 (*unk_08)[4];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ void* unk_14;
} KeLnsArndTArg;

void func_001A7C40(KeLnsArndTArg* arg, s32 arg1);

void func_00194BD0(KeLnsArndTUnk* arg0) {
    KeLnsArndTArg arg;

    arg.unk_00 = arg0;
    arg.unk_10 = arg0->unk_40.f;
    arg.unk_04 = arg0->unk_48.i;
    arg.unk_0C = arg0->unk_44.f;
    arg.unk_08 = ppvScreenMatrix;
    arg.unk_14 = &arg0->unk_30;
    func_001A7C40(&arg, 0);
}
