#include "common.h"
#include "ppp/draw.h"

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9280);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A95B8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9620);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A96D0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9C50);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA7C0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA868);

typedef struct DrawNode {
    /* 0x0 */ struct DrawNode* next;
} DrawNode;

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ DrawNode* free;
} DrawNodeList;

DrawNode* func_001AA940(DrawNodeList* list) {
    DrawNode* node = list->free;

    if (node == NULL) {
        return NULL;
    }
    list->free = node->next;
    return node;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", KeThResHd_Init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AA9C8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAA30);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAB28);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAC80);

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ u8 unk_4;
} DrawUnkAADB8;

void func_001AADB8(DrawUnkAADB8* arg0) {
    arg0->unk_0 = 0;
    arg0->unk_4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AADC8);

extern s32 D_00372760;

void func_001AAF58(void) {
    D_00372760 = (D_00372760 * 0x80D + 7) & 0xFFFF;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAF80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AAFC0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0B0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0D8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB0F0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB108);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB120);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB138);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB150);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB168);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB180);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB198);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB208);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB270);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB2A0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB320);

f32 func_001AB348(s32 n, f32 x) {
    f32 r = 1.0f;
    s32 i;

    for (i = 0; i < n; i++) {
        r *= x;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB380);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB3A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB3E0);

void func_001AB408(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack;

    sceVu0SubVector(stack, arg0, arg1);
    func_001AB3A8(stack);
}

typedef struct {
    /* 0x0 */ u16* next;
    /* 0x4 */ u16 count;
    /* 0x6 */ u16 head;
} DrawFreeList;

s32 func_001AB438(DrawFreeList* list) {
    u16 idx;

    if (list->head == 0xFFFF) {
        return 0xFFFF;
    }
    idx = list->head;
    list->head = list->next[idx];
    return idx;
}

void func_001AB470(DrawFreeList* list, u16* next, u16 count) {
    u16 i;

    list->next = next;
    list->head = 0;
    list->count = count;
    for (i = 1; i < count; i++) {
        *next++ = i;
    }
    *next = 0xFFFF;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB4B8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AB828);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABA80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABCC8);

void op_init_draw(void) {
    ops_init_draw_work();
    ops_init_spr();
}

void ops_init_draw_work(void) {
    oa_dmagif = sceDmaGetChan(SCE_DMA_GIF);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_gs2_init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_otz_init);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC0A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC120);

s32 func_001AC148(s32 n) {
    s32 i = 1;
    s32 bits = 0;

    while (i < n) {
        i <<= 1;
        bits++;
    }
    return bits;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC180);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC298);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC430);

typedef struct {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ u8 unk_8;
    /* 0x9 */ u8 unk_9;
} DrawUnkAC4C8;

void func_001AC298(s32, u8, u16, s32);

void func_001AC4C8(DrawUnkAC4C8* arg0, s32 arg1) {
    func_001AC298(arg0->unk_4, arg0->unk_9, arg0->unk_0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC4F0);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_ot_draw);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC758);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC7A8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC7F8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC848);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_init_fog_work);

extern f32 D_002BC120;
extern f32 D_002BC124;
extern f32 D_00372800[2];

void func_001AC978(void) {
    D_00372800[0] = D_002BC120;
    D_00372800[1] = D_002BC124;
}

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/draw", D_00489A60);
