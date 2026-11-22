#include "common.h"

#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 unk2;
} VKeBornRnd5;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char pad_06[6];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ char pad_0F[1];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} PKeBornRnd5;

void func_0018F548();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd5* p, void* func, VKeBornRnd5* v, s16 a, u8 b, u8 c);

void pppKeBornRnd5Calc(pppPObject* pobj, PKeBornRnd5* p, pppCtrlTable* ctbl) {
    VKeBornRnd5* v;

    if (ppvEmptyLoop) {
        return;
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->unk_0D == 0) {
        return;
    }
    v = (VKeBornRnd5*)&pobj->val[ctbl->useVal[0]];
    if (v->unk2 == 0) {
        v->unk2 = p->unk_0D;
        if (p->unk_10 == -1) {
            return;
        }
        if (p->unk_18 == -1) {
            return;
        }
        KeBornRnd2(pobj, p, func_0018F548, v, p->unk_04, p->unk_0E, p->unk_0C);
    }
    v->unk2--;
}

void pppKeBornRnd5Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd5* v = (VKeBornRnd5*)&pobj->val[ctbl->useVal[0]];

    v->unk0 = 0;
    v->unk2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", func_0018F780);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", func_0018F910);

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", D_00489808);

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeBornRnd5", D_00489810);
