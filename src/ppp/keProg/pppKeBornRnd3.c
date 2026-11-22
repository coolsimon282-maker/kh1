#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char pad_09[3];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} PKeBornRnd3;

s32 func_001AAF80(void);
void func_0018EDD8();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd3* p, void* func, void* v, s16 a, u8 b, u8 c);

s32 pppKeBornRnd3Calc(pppPObject* pobj, PKeBornRnd3* p, pppCtrlTable* ctbl) {
    if (!ppvEmptyLoop && !(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) && p->unk_07 != 0xFF &&
        !((func_001AAF80() >> 8) & p->unk_07) && p->unk_0C != -1 && p->unk_14 != -1) {
        KeBornRnd2(pobj, p, func_0018EDD8, &pobj->val[ctbl->useVal[0]], p->unk_04, p->unk_08, p->unk_06);
    }
}

typedef struct {
    /* 0x0 */ s16 unk_0;
} VKeBornRnd3;

void pppKeBornRnd3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd3*)&pobj->val[ctbl->useVal[0]])->unk_0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd3", func_0018F000);
