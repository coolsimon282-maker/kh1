#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", pppRyjMegaBirthPrizeDraw);

extern u8 D_0035C710[];

void pppRyjMegaBirthPrizeCon(void) {
    memset(D_0035C710, 0, 0x2000);
    ppvMng->unk_B3 = 1;
    ppvMng->drawPriority = 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ sceVu0FVECTOR unk_10;
    /* 0x20 */ char unk_20[0x30];
} RyjPrize; // size = 0x50

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} RyjPrizeHdr;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ RyjPrizeHdr* unk_04;
    /* 0x08 */ RyjPrize* unk_08;
} RyjPrizeMng;

extern RyjPrizeMng D_0035E710;

RyjPrize* func_0019FD18(s32 arg0) {
    RyjPrize* e = D_0035E710.unk_08;
    RyjPrize* ret = NULL;
    s32 i;
    if (e != NULL) {
        for (i = 0; i < D_0035E710.unk_04->unk_04; i++, e++) {
            if (arg0 == e->unk_08) {
                ret = e;
                break;
            }
        }
    }
    return ret;
}

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x18];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
} RyjPrizeSrc;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ RyjPrizeSrc* src;
    /* 0x14 */ RyjPrize* prize;
    /* 0x18 */ char unk_18[0x8];
} RyjPrizeSlot; // size = 0x20

typedef struct {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ char unk_08[0x4];
    /* 0x0C */ RyjPrizeSlot* unk_0C;
    /* 0x10 */ RyjPrizeSlot* unk_10;
} RyjPrizeList;

s32 func_0019FD78(RyjPrizeList* l, RyjPrizeSrc* s) {
    u32 i;
    RyjPrizeSlot* e;

    if (l->unk_0C == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_00; i++) {
        e = &l->unk_0C[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_20;
            e->pos[1] += s->unk_24;
            e->pos[2] += s->unk_28;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}

s32 func_0019FE58(RyjPrizeList* l, RyjPrizeSrc* s) {
    u32 i;
    RyjPrizeSlot* e;

    if (l->unk_10 == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_04; i++) {
        e = &l->unk_10[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_20;
            e->pos[1] += s->unk_24;
            e->pos[2] += s->unk_28;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x1C];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk_30[0x10];
    /* 0x40 */ u8 unk_40;
    /* 0x41 */ u8 unk_41;
    /* 0x42 */ u8 unk_42;
} RyjPrizeSrc2;

typedef struct {
    /* 0x00 */ sceVu0FVECTOR pos;
    /* 0x10 */ RyjPrizeSrc2* src;
    /* 0x14 */ RyjPrize* prize;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ char unk_20[0x10];
} RyjPrizeSlot2; // size = 0x30

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ char unk_0C[0x8];
    /* 0x14 */ RyjPrizeSlot2* unk_14;
} RyjPrizeList2;

s32 func_0019FF38(RyjPrizeList2* l, RyjPrizeSrc2* s) {
    u32 i;
    RyjPrizeSlot2* e;

    if (l->unk_14 == NULL) {
        return 0;
    }
    for (i = 0; i < l->unk_08; i++) {
        e = &l->unk_14[i];
        if (e->src == NULL) {
            e->src = s;
            e->prize = func_0019FD18(s->unk_04);
            e->unk_1C = s->unk_40;
            e->unk_1D = s->unk_41;
            e->unk_1E = 0x7FFF / s->unk_42;
            sceVu0CopyVector(e->pos, e->prize->unk_10);
            e->pos[0] += s->unk_24;
            e->pos[1] += s->unk_28;
            e->pos[2] += s->unk_2C;
            e->pos[3] = 1.0f;
            break;
        }
    }
    return 1;
}
