#include "ppp.h"

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
} VKeBornRnd6;

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
} PKeBornRnd6;

void func_0018F910();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd6* p, void* func, VKeBornRnd6* v, s16 a, u8 b, u8 c);

void pppKeBornRnd6Calc(pppPObject* pobj, PKeBornRnd6* p, pppCtrlTable* ctbl) {
    VKeBornRnd6* v;

    if (ppvEmptyLoop) {
        return;
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->unk_07 == 0) {
        return;
    }
    v = (VKeBornRnd6*)&pobj->val[ctbl->useVal[0]];
    if (v->unk_02 == 0) {
        v->unk_02 = p->unk_07;
        if (p->unk_0C == -1) {
            return;
        }
        if (p->unk_14 == -1) {
            return;
        }
        KeBornRnd2(pobj, p, func_0018F910, v, p->unk_04, p->unk_08, p->unk_06);
    }
    v->unk_02--;
}

void pppKeBornRnd6Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd6* v = (VKeBornRnd6*)&pobj->val[ctbl->useVal[0]];

    v->unk_00 = 0;
    v->unk_02 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd6", func_0018FBB0);
