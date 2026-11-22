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

typedef struct DrawNode {
    /* 0x00 */ struct DrawNode* next;
    /* 0x04 */ struct DrawNode* prev;
    /* 0x08 */ struct DrawNode* link;
    /* 0x0C */ struct DrawNode* linkPrev;
    /* 0x10 */ u8 pad10[0x20];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u8 pad36[2];
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u8 pad3A[2];
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 flags;
    /* 0x40 */ f32 unk_40[4];
    /* 0x50 */ u8 pad50[0xC];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60[4];
} DrawNode;

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ DrawNode* free;
} DrawNodeList;

// 0x30-byte entries from 0x40 of a DrawNode (func_001A8770 is in xberry)
typedef struct {
    /* 0x00 */ u8 data[0x30];
} DrawNodeEntry;

void func_001A8770(DrawNodeEntry*, s32);

void func_001AA868(DrawNode* node) {
    DrawNodeEntry* e = (DrawNodeEntry*)node->unk_40;
    s32 flags = node->flags & 0x20;
    s32 i;

    for (i = node->unk_3C; i > 0; i--) {
        func_001A8770(e++, flags);
    }
    e = (DrawNodeEntry*)node->unk_40 + node->unk_34;
    for (i = node->unk_38; i > 0; i--) {
        func_001A8770(e++, flags);
    }
    if (node->linkPrev != NULL) {
        if (node->link != NULL) {
            node->link->linkPrev = node->linkPrev;
        }
        node->linkPrev->next = node->link;
    }
}

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

typedef struct {
    /* 0x0 */ DrawNode* first;
    /* 0x4 */ u8 flags;
} DrawNodeHead;

typedef struct {
    /* 0x0 */ DrawNode* node;
    /* 0x4 */ u8 count;
} DrawNodeInit;

void func_001AA7C0(DrawNodeInit*);
void func_001AB0F0(f32*, f32*);

// pool is a DrawNodeList*; the variable is reused for the flags (that's what gives the register use)
void func_001AAA30(DrawNodeHead* head, s32 pool, f32* arg2, f32* arg3) {
    DrawNodeInit init;
    DrawNode* node;
    u8 bits;

    node = func_001AA940((DrawNodeList*)pool);
    if (node == NULL) {
        return;
    }
    init.count = ((u8*)pool)[1];
    init.node = node;
    func_001AA7C0(&init);
    node->unk_5C = 0;
    node->unk_30 = 0;
    bits = head->flags;
    pool = 0x100;
    if (bits & 4) {
        pool = 0x180;
    }
    if (bits & 0x10) {
        pool |= 0x200;
    }
    if (bits & 8) {
        pool |= 0x400;
    }
    if (bits & 0x20) {
        pool |= 0x1000;
    }
    node->flags |= pool;
    func_001AB0F0(node->unk_40, arg2);
    func_001AB0F0(node->unk_60, arg3);
    if (head->first != NULL) {
        head->first->prev = node;
    }
    node->next = head->first;
    node->prev = (DrawNode*)head;
    head->first = node;
}

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

s32 func_001AAF80(void) {
    f32 r;
    __asm__ volatile("addi $8,$0,-1\n\tqmtc2.ni $8,$vf2\n\tvrxor R,$vf2x\n\tvitof0.x $vf2,$vf2\n\tvrnext.x $vf1,R\n\tvadd.x $vf1,$vf1,$vf2\n\tqmfc2.ni %0,$vf1" : "=r"(r) : : "$8");
    return r * 32768.0f;
}

typedef struct {
    /* 0x00 */ f32 org[4]; // ray origin, relative to the sphere's centre
    /* 0x10 */ f32 dir[4];
    /* 0x20 */ f32 radius;
    /* 0x24 */ f32 t; // out: distance along dir to the first hit
} DrawRaySphere;

f32 func_001AB380(f32); // square root

// ray/sphere intersection: solves a*t*t + b*t + c = 0, returns 0 if the ray misses
s32 func_001AAFC0(DrawRaySphere* r) {
    f32 a, b, c, d;

    a = r->dir[0] * r->dir[0] + r->dir[1] * r->dir[1] + r->dir[2] * r->dir[2];
    b = r->dir[0] * r->org[0];
    b += r->dir[1] * r->org[1];
    b += r->dir[2] * r->org[2];
    b *= 2.0f;
    c = r->org[0] * r->org[0];
    c += r->org[1] * r->org[1];
    c += r->org[2] * r->org[2];
    c -= r->radius * r->radius;
    d = b * b - a * 4.0f * c;
    c = -b;
    b = a * 2.0f;
    if (d < 0.0f) {
        return 0;
    }
    r->t = (c - func_001AB380(d)) / b;
    return 1;
}

f32 func_001AB0B0(f32 a, f32 b) {
    f32 v[4];
    v[0] = a;
    v[1] = b;
    __asm__ volatile("lqc2 $vf1,0(%0)\n\tvmaxy.x $vf1,$vf1,$vf1y\n\tsqc2 $vf1,0(%0)" : : "r"(v) : "memory");
    return v[0];
}

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

f32 func_001AB380(f32 a) {
    f32 v[4];
    f32 r;
    v[1] = a;
    __asm__ volatile("lqc2 $vf10,0(%1)\n\tvsqrt Q,$vf10y\n\tvwaitq\n\tcfc2.ni $2,$vi22\n\tmtc1 $2,%0" : "=f"(r) : "r"(v) : "$2", "memory");
    return r;
}

f32 func_001AB3A8(f32* a) {
    f32 v[4];
    __asm__ volatile("lqc2 $vf10,0(%0)\n\tvmul.xyz $vf10,$vf10,$vf10\n\tvmove.xyz $vf9,$vf10\n\tvaddx.y $vf9,$vf9,$vf9x\n\tvaddy.z $vf9,$vf9,$vf9y\n\tvsqrt Q,$vf9z\n\tvwaitq\n\tvaddq.x $vf10,$vf0,Q\n\tsqc2 $vf10,0(%1)" : : "r"(a), "r"(v) : "memory");
    return v[0];
}

f32 func_001AB3E0(f32* a) {
    f32 r;
    __asm__ volatile("lqc2 $vf10,0(%1)\n\tvmul.xy $vf10,$vf10,$vf10\n\tvaddx.y $vf10,$vf10,$vf10x\n\tvsqrt Q,$vf10y\n\tvwaitq\n\tcfc2.ni $2,$vi22\n\tmtc1 $2,%0" : "=f"(r) : "r"(a) : "$2");
    return r;
}

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

// stores a zero qword with `sq $0` (gcc itself always goes through a register)
#define DRAW_SQ_ZERO(addr) __asm__ volatile("sq $0,%0" : "=m"(*(u_long128*)(addr)))

// a word store gcc can't move (DMA tags are written this way, right after DRAW_SQ_ZERO)
#define DRAW_SW(dst, val) __asm__ volatile("sw %1,%0" : "=m"(dst) : "r"(val))

// ordering-table entry: a DMA "next" tag; `last` is the last packet linked into it
typedef struct {
    /* 0x0 */ u32 tag;
    /* 0x4 */ u32* next;
    /* 0x8 */ u32* last;
    /* 0xC */ u32 pad;
} DrawOtEnt;

// links packet p (qwc qwords) at priority pri (clamped to 0..max) into ordering table ot
#define DRAW_OT_INSERT(ot, max, p, qwc, pri)       \
    {                                              \
        DrawOtEnt* e;                              \
        u32* last;                                 \
        u32* t;                                    \
                                                   \
        DRAW_SQ_ZERO(p);                           \
        DRAW_SW((p)[0], ((qwc) - 1) | 0x20000000); \
        if (pri < 1) {                             \
            pri = 0;                               \
        }                                          \
        if (pri > (max)) {                         \
            pri = (max);                           \
        }                                          \
        e = &(ot)[pri];                            \
        last = e->last;                            \
        t = (u32*)last[1];                         \
        last[1] = (u32)(p);                        \
        (p)[1] = (u32)t;                           \
        e->last = (p);                             \
    }

// stores a qword through a pointer register
#define DRAW_SQ(ptr, val) __asm__ volatile("sq %1,0(%0)" : : "r"(ptr), "r"(val) : "memory")

extern u_long128 D_0061E800[];
extern u_long128 D_0061E8B0[];
extern u8 D_0061EEA0[];

void func_001AC758(u32* p, s32 qwc, s32 pri, s32 arg3);
void func_001AC7A8(u32* p, s32 qwc, s32 pri, s32 arg3);

// the three ordering tables (16 + 256 + 16 entries at D_0061EEA0) chained by "next" tags and closed by an end
// tag, then the two fixed packets linked in
void op_otz_init(void) {
    DrawOtEnt* p;
    s32 i;
    u_long128 tag;

    p = (DrawOtEnt*)D_0061EEA0;
    tag = 0x20000000;
    for (i = 0; i < 0x120; i++) {
        DRAW_SQ(p, tag);
        p->next = (u32*)(p + 1);
        p->last = (u32*)p;
        p++;
    }
    DRAW_SQ(p, tag);
    p->tag = 0x70000000;
    func_001AC758((u32*)D_0061E800, 7, 0, 0);
    func_001AC7A8((u32*)D_0061E8B0, 7, 15, 0);
}

// sends the packet at D_0061E8B0 on its own (its first tag replaced by an end tag with 6 qwords)
void func_001AC0A8(void) {
    u_long128 save = D_0061E8B0[0];

    D_0061E8B0[0] = 0x70000006;
    sceGsSyncPath(0, 0);
    FlushCache(0);
    sceDmaSend(oa_dmagif, D_0061E8B0);
    sceGsSyncPath(0, 0);
    D_0061E8B0[0] = save;
}

s32 rand(void);

// seeds the VU0 random register from rand()
void func_001AC120(void) {
    s32 r = rand();

    __asm__ volatile("qmtc2.ni %0,$vf31\n\tvrxor R,$vf31x" : : "r"(r) : "$2");
}

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

void op_ot_draw(void) {
    u8* ot = D_0061EEA0;

    sceGsSyncPath(0, 0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(oa_dmagif, ot);
    sceGsSyncPath(0, 0);
}

// ordering table 0 (16 priorities)
void func_001AC758(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT((DrawOtEnt*)D_0061EEA0, 15, p, qwc, pri);
}

extern DrawOtEnt D_0061FFA0[];

// ordering table 1 (16 priorities)
void func_001AC7A8(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT(D_0061FFA0, 15, p, qwc, pri);
}

extern DrawOtEnt D_0061EFA0[];

// ordering table 2 (256 priorities)
void func_001AC7F8(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT(D_0061EFA0, 255, p, qwc, pri);
}


// GS packet: alpha register + a 2-vertex sprite in colour rgba, inserted in OT 1 at priority 0
u8* func_001AC848(u8* p, u32 rgba, u8 alpha, u8 fix) {
    *(u64*)(p + 0x10) = 0x41A3400000008001;
    *(u64*)(p + 0x18) = 0x441E;
    DRAW_SQ_ZERO(p + 0x20);
    p[0x20] = alpha;
    p[0x24] = fix;
    *(u64*)(p + 0x28) = 0x42;
    // spread the four colour bytes into the RGBAQ words
    __asm__ volatile("pextlb %1,$0,%1\n\tpextlh %1,$0,%1\n\tsq %1,%0" : "=m"(*(u_long128*)(p + 0x30)), "+r"(rgba));
    *(u_long128*)(p + 0x40) = (u_long128)0xFFFFFFFE0000780000007000;
    *(u_long128*)(p + 0x50) = (u_long128)0xFFFFFFFE0000880000009000;
    func_001AC7A8((u32*)p, 6, 0, 0);
    return p + 0x60;
}

extern f32 D_00372800[16]; // fog work

void op_init_fog_work(void) {
    f32* w = D_00372800;

    w[0] = w[1] = 0.0f;
    w[2] = 255.0f;
    w[3] = 0.0f;
    w[4] = w[5] = 0.0f;
    w[6] = 255.0f;
    w[7] = 255.0f;
    w[8] = 0.8f;
    w[9] = -32.0f;
    w[10] = 128.0f;
    w[11] = 0.0f;
    w[12] = 0.0f;
    w[13] = 128.0f;
    w[14] = 128.0f;
    w[15] = 0.0f;
}

extern f32 D_002BC120;
extern f32 D_002BC124;

void func_001AC978(void) {
    D_00372800[0] = D_002BC120;
    D_00372800[1] = D_002BC124;
}

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/draw", D_00489A60);
