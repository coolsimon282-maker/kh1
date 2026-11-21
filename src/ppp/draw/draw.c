#include "common.h"
#include "ppp/draw.h"
#include "libgraph.h"
#include "eekernel.h"

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

typedef struct {
    /* 0x0 */ u8 count;
    /* 0x1 */ u8 size;
    /* 0x2 */ u16 stride;
    /* 0x4 */ u32* first;
    /* 0x8 */ u32 pad[2];
} KeThResHd;

void KeThResHd_Init(KeThResHd* hd, u8 count, u8 size) {
    u32* p;
    s32 stride;
    s32 i;

    hd->count = count;
    hd->size = size;
    hd->stride = stride = (u8)(size - 1) * 48 + 0x80;
    hd->first = p = (u32*)(hd + 1);
    for (i = count - 1; i > 0; i--) {
        u32* q = p;
        p = (u32*)((u8*)p + stride);
        *q = (u32)p;
    }
    *p = 0;
}

void func_001AA868(DrawNode*);

void func_001AA9C8(DrawNodeList* list, DrawNodeList* freeList) {
    DrawNode* node = (DrawNode*)list->unk_0;
    DrawNode* cur;

    while (node != NULL) {
        cur = node;
        node = node->next;
        func_001AA868(cur);
        cur->next = freeList->free;
        freeList->free = cur;
    }
    list->unk_0 = 0;
}

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

typedef struct {
    /* 0x00 */ u32 totalSize;
    /* 0x04 */ u32 clutSize;
    /* 0x08 */ u32 imageSize;
    /* 0x0C */ u16 headerSize;
    /* 0x0E */ u16 clutColors;
    /* 0x10 */ u8 pictFormat;
    /* 0x11 */ u8 mipMapTextures;
    /* 0x12 */ u8 clutType;
    /* 0x13 */ u8 imageType;
    /* 0x14 */ s16 imageWidth;
    /* 0x16 */ s16 imageHeight;
    /* 0x18 */ u16 tex0Lo;
    /* 0x1A */ u16 pad1A;
    /* 0x1C */ u32 tex0Hi;
    /* 0x20 */ u32 tex1[2];
    /* 0x28 */ u8 regs[4];
    /* 0x2C */ u32 texClut;
} DrawTim2Picture;
typedef struct {
    /* 0x00 */ u8 pad[0xF];
    /* 0x0F */ u8 unk_F;
    /* 0x10 */ DrawTim2Picture pict;
    /* 0x40 */ u8 data[0];
} DrawTim2;
extern u8 D_003727F0[];
void func_001AC180(DrawTim2* tm) {
    sceGsLoadImage li;
    sceGsLoadImage clut;
    DrawTim2Picture* pict = &tm->pict;
    u8* data;

    if (pict->imageSize != 0) {
        s32 psm = D_003727F0[pict->imageType];
        s32 dbp = pict->tex0Lo;
        data = tm->data;
        tm->unk_F = 0x6F;
        sceGsSetDefLoadImage(&li, dbp & 0x3FFF, pict->regs[0] >> 2, psm,
                             pict->regs[2] << 4, pict->regs[3] << 4, pict->imageWidth, pict->imageHeight);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128*)data);
    }
    if (pict->clutSize != 0) {
        sceGsSetDefLoadImage(&clut, (pict->tex0Hi >> 5) & 0x3FFF, 1, D_003727F0[pict->clutType], 0, 0, 16,
                             pict->clutSize / 64);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceGsExecLoadImage(&clut, (u_long128*)(data + pict->imageSize));
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001AC298);

typedef struct {
    /* 0x00 */ u16 unk_0;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ u8 unk_8;
    /* 0x09 */ u8 unk_9;
    /* 0x0A */ u8 unk_A;
    /* 0x0B */ u8 padB;
    /* 0x0C */ s16 unk_C;
    /* 0x0E */ s16 unk_E;
    /* 0x10 */ u32 pad10;
    /* 0x14 */ u_long128* unk_14;
    /* 0x18 */ u8 unk_18;
} DrawImage;

void func_001AC430(DrawImage* img, s32 wait) {
    sceGsLoadImage li;

    sceGsSetDefLoadImage(&li, img->unk_0 & 0x3FFF, img->unk_A >> 2, img->unk_18, img->unk_8 << 4, img->unk_9 << 4,
                         img->unk_C, img->unk_E);
    sceGsSyncPath(0, 0);
    FlushCache(0);
    sceGsExecLoadImage(&li, img->unk_14);
    if (wait) {
        sceGsSyncPath(0, 0);
    }
}

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

extern u8 D_0061EEA0[];

void op_ot_draw(void) {
    u8* ot = D_0061EEA0;

    sceGsSyncPath(0, 0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, ot);
    sceGsSyncPath(0, 0);
}

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
