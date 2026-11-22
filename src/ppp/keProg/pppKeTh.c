#include "common.h"
#include "ppp.h"

typedef struct {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[0x14];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ u8 unk_28[4];
    /* 0x2C */ s32 unk_2C;
} KeThSub; // size = 0x30

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ KeThSub sub;
    /* 0x40 */ u8 unk_40[0x2C];
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ u64 unk_70;
    /* 0x78 */ u64 unk_78;
    /* 0x80 */ u64 unk_80;
    /* 0x88 */ u64 unk_88;
} KeTh; // size = 0x90

// Accessed through unions: the stores keep their order between the two bases.
typedef union {
    KeTh v;
    u8 raw[0x90];
} KeThU;

typedef union {
    KeThSub s;
    u8 raw[0x30];
} KeThSubU;

void func_001AADB8(void*);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeTh", pppKeThCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeTh", pppKeThDraw);

void pppKeThCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThU* v = (KeThU*)&pobj->val[ctbl->useVal[0]];
    KeThSubU* sub = (KeThSubU*)&v->v.sub;

    func_001AADB8(v);
    v->v.unk_70 = 0;
    v->v.unk_78 = 0;
    v->v.unk_80 = 0;
    v->v.unk_88 = 0;
    v->v.unk_6C = 0;
    sub->s.unk_0C = 0;
    sub->s.unk_24 = 0;
    sub->s.unk_2C = 0;
}

void pppKeThCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    KeThU* v = (KeThU*)&pobj->val[ctbl->useVal[0]];
    KeThSubU* sub = (KeThSubU*)&v->v.sub;

    v->v.unk_70 = 0;
    v->v.unk_78 = 0;
    v->v.unk_80 = 0;
    v->v.unk_88 = 0;
    v->v.unk_6C = 0;
    sub->s.unk_0C = 0;
    sub->s.unk_24 = 0;
    sub->s.unk_2C = 0;
}

void pppKeThDes(void) {
}

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeTh", D_004897F8);

INCLUDE_RODATA("asm/nonmatchings/ppp/keProg/pppKeTh", D_00489800);
