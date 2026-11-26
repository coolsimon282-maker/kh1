/**
 * Low-level drawing for the effects (op_* functions): GS set-up, three ordering tables of GS packets (OT 0 and 1 with
 * 16 priorities, OT 2 with 256) sent by DMA in op_ot_draw, image (TIM2) upload, fog work, small math helpers and the
 * node lists the draw code uses.
 */
#include "common.h"
#include "ppp/draw.h"
#include "libgraph.h"
#include "eekernel.h"
#include "ppp.h"

#ifdef VERSION_FM
// .data (0x00372750-0x00372EA0)
void (*D_00372750[4])(sceVu0FMATRIX, sceVu0FMATRIX, f32) = {sceVu0RotMatrixX, sceVu0RotMatrixY, sceVu0RotMatrixZ, NULL};
s32 D_00372760 = 0; // random seed
u64 D_00372770[4] __attribute__((aligned(16))) = { // pppKeTkFade (as u_long128[2])
    0x0901010101010101ULL, 0xF101010101010101ULL,
    0x0901010101010101ULL, 0x0101010101010101ULL,
};
s8 D_00372790[32] = { // pppKeTkFade
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
};
sceVu0FVECTOR D_003727B0[4] = { // pppKeMatSN
    {0.0f, 0.0f, 0.0f, 1.0f},
    {1.0f, 0.0f, 0.0f, 1.0f},
    {0.0f, 1.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 1.0f, 1.0f},
};
u8 D_003727F0[16] = {0x00, 0x02, 0x01, 0x00, 0x14, 0x13}; // GS psm per image/clut type
f32 D_00372800[48] = {0}; // fog work
u32 D_003728C0[18] = { // bit table (read by ppp/draw/md0)
    0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
    0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
};
sceDmaChan* oa_dmagif = NULL;
// zero area nothing refers to by name, up to ppp/draw/global's .data
s32 D_0037290C = 0;
u8 D_00372910[0x590] = {0};
#endif

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9280);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A95B8);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001A9620);

// Builds the GS packet of one draw node (called by DrawNodeList_Draw); returns whether there is something to send.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", DrawNode_BuildPacket);

// Updates one draw node (called by DrawNodeList_Update for each node).
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", DrawNode_Update);

typedef struct DrawNode {
    /* 0x00 */ struct DrawNode* next;
    /* 0x04 */ struct DrawNode* prev;
    /* 0x08 */ struct DrawNode* link;
    /* 0x0C */ struct DrawNode* linkPrev;
    /* 0x10 */ struct DrawNode* self;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 pad1F;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u8 pad22;
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u8 unk_36;
    /* 0x37 */ u8 unk_37;
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u8 pad3A[2];
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 flags;
    /* 0x40 */ f32 unk_40[4];
    /* 0x50 */ u8 pad50[8];
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60[4];
} DrawNode;

typedef struct {
    /* 0x0 */ DrawNode* node;
    /* 0x4 */ u8 count;
} DrawNodeInit;

// sets up a node taken from the pool: clears it, links it to itself and writes the first entry's GIF tags
void DrawNode_Init(DrawNodeInit* init) {
    DrawNode* node = init->node;
    s32* e;

    node->flags = 0;
    node->self = node;
    node->unk_37 = init->count;
    node->unk_18 = 0;
    node->unk_40[3] = 1.0f;
    node->unk_34 = 0;
    node->unk_36 = 0;
    node->unk_20 = node->unk_37 * 3 + 2;
    node->unk_3C = 0;
    node->unk_38 = 0;
    node->unk_1E = 0;
    node->unk_14 = 0;
    node->prev = NULL;
    e = (s32*)((u8*)node + 0x40 + node->unk_37 * 0x30);
    node->next = NULL;
    node->linkPrev = NULL;
    node->unk_23 = 0x70;
    node->link = NULL;
    node->unk_58 = 0;
    node->unk_28 = 0x040000B0;
    node->unk_1C = 0;
    e[0] = 0;
    e[1] = 0x11000000;
    e[2] = 0x14000000;
    e[3] = 0x11000000;
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ DrawNode* free;
} DrawNodeList;

// 0x30-byte entries from 0x40 of a DrawNode (func_001A8770 is in xberry)
typedef struct {
    /* 0x00 */ u8 data[0x30];
} DrawNodeEntry;

void func_001A8770(DrawNodeEntry*, s32);

// Releases the node's entries (func_001A8770) and unlinks it from its link chain.
void DrawNode_Release(DrawNode* node) {
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

// Takes the first node of the free list, or NULL.
DrawNode* DrawNodeList_Take(DrawNodeList* list) {
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

void DrawNode_Release(DrawNode*);

// Releases every node of the list and puts it back on the free list.
void DrawNodeList_FreeAll(DrawNodeList* list, DrawNodeList* freeList) {
    DrawNode* node = (DrawNode*)list->unk_0;
    DrawNode* cur;

    while (node != NULL) {
        cur = node;
        node = node->next;
        DrawNode_Release(cur);
        cur->next = freeList->free;
        freeList->free = cur;
    }
    list->unk_0 = 0;
}

typedef struct {
    /* 0x0 */ DrawNode* first;
    /* 0x4 */ u8 flags;
} DrawNodeHead;

void DrawNode_Init(DrawNodeInit*);
void op_vec_copy_xyz(f32*, f32*);

// pool is a DrawNodeList*; the variable is reused for the flags (that's what gives the register use)
void DrawNode_Add(DrawNodeHead* head, s32 pool, f32* arg2, f32* arg3) {
    DrawNodeInit init;
    DrawNode* node;
    u8 bits;

    node = DrawNodeList_Take((DrawNodeList*)pool);
    if (node == NULL) {
        return;
    }
    init.count = ((u8*)pool)[1];
    init.node = node;
    DrawNode_Init(&init);
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
    op_vec_copy_xyz(node->unk_40, arg2);
    op_vec_copy_xyz(node->unk_60, arg3);
    if (head->first != NULL) {
        head->first->prev = node;
    }
    node->next = head->first;
    node->prev = (DrawNode*)head;
    head->first = node;
}

typedef struct {
    /* 0x00 */ DrawNodeHead* head;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ DrawNodeList* freeList;
    /* 0x10 */ f32* unk_10;
    /* 0x14 */ f32* unk_14;
} DrawNodeUpd;

typedef struct {
    /* 0x00 */ sceVu0FMATRIX m;
    /* 0x40 */ DrawNode* node;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ DrawNodeList* unk_48;
    /* 0x4C */ s32 unk_4C;
} DrawNodeCtx;

void DrawNode_Update(DrawNodeCtx*);
// updates every node of a list (vectors, flags), draws it with DrawNode_Update and frees the ones flagged 0x10
void DrawNodeList_Update(DrawNodeUpd* u) {
    DrawNodeCtx ctx;
    DrawNodeHead* head = u->head;
    DrawNode* node;
    DrawNode* cur;
    s32 bits = 0;

    if (head->flags & 2) {
        head->flags &= ~2;
        bits = 0x20;
    }
    sceVu0UnitMatrix(ctx.m);
    ctx.unk_44 = u->unk_04;
    ctx.unk_48 = u->freeList;
    ctx.unk_4C = u->unk_08;
    node = head->first;
    while (node != NULL) {
        if (node->flags & 0x200) {
            op_vec_copy_xyz((f32*)((DrawNodeEntry*)node->unk_40 + node->unk_34)->data, u->unk_10);
            op_vec_copy_xyz((f32*)(((DrawNodeEntry*)node->unk_40 + node->unk_34)->data + 0x20), u->unk_14);
        }
        if (node->flags & 0x100) {
            node->flags |= bits;
        }
        ctx.node = node;
        DrawNode_Update(&ctx);
        if (node->flags & 0x10) {
            cur = node;
            node = cur->next;
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            cur->prev->next = cur->next;
            DrawNode_Release(cur);
            cur->next = u->freeList->free;
            u->freeList->free = cur;
        } else {
            node = node->next;
        }
    }
}

// draws every node of a list: DrawNode_BuildPacket builds each one's packet after a 16-byte DMA tag, sent on path 2
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ DrawNode* node;
    /* 0x08 */ u32 pkt;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u64* unk_14;
    /* 0x18 */ u64 unk_18;
    /* 0x20 */ u64 unk_20;
} DrawPktCtx;

s32 DrawNode_BuildPacket(DrawPktCtx*);

// Draws every node of a list: DrawNode_BuildPacket builds each packet after a DMA tag, sent on channel 2.
void DrawNodeList_Draw(DrawNode** list, s32 arg1, s32 arg2, s32 arg3, u32* buf, u64 arg5, u64 arg6) {
    DrawPktCtx ctx;
    sceDmaChan* ch = sceDmaGetChan(2);
    DrawNode* node = *list;
    u8* p;

    ctx.unk_0C = arg3;
    ctx.unk_00 = arg1;
    ctx.unk_10 = arg2;
    ctx.unk_18 = arg5;
    ctx.unk_20 = arg6;
    sceGsSyncPath(0, 0);
    for (; node != NULL; node = node->next) {
        ctx.node = node;
        ctx.pkt = *buf + 0x10;
        if (DrawNode_BuildPacket(&ctx)) {
            p = (u8*)*buf;
            *(u_long128*)p = 0;
            p[3] = 0x70;
            *ctx.unk_14 |= 0x8000;
            *(u16*)p = ((ctx.pkt - *buf) >> 4) + 0xFFFF;
            FlushCache(0);
            sceDmaSend(ch, p);
            sceGsSyncPath(0, 0);
        }
    }
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ u8 unk_4;
} DrawUnkAADB8;

// Clears a node list head (first node and flags).
void DrawNodeHead_Clear(DrawUnkAADB8* arg0) {
    arg0->unk_0 = 0;
    arg0->unk_4 = 0;
}

double atan(double);
#define DRAW_PI 3.1415926f
#define DRAW_HPI 1.5707963f

// atan2 of (v[1], v[0]) with atan and quadrant fixes; returns 0 for the zero vector.
s32 op_atan2(f32* v, f32* out) {
    f32 x = v[0];
    f32 y = v[1];
    f32 r = x * y;

    if (r > 0.0f) {
        r = (x > 0.0f) ? 0.0f : -DRAW_PI;
        r += atan(y / x);
    } else if (r < 0.0f) {
        r = (y > 0.0f) ? DRAW_HPI : -DRAW_HPI;
        r -= atan(x / y);
    } else if (x != 0.0f) {
        r = (x > 0.0f) ? 0.0f : DRAW_PI;
    } else {
        if (y == 0.0f) {
            return 0;
        }
        r = -DRAW_HPI;
        if (y > 0.0f) {
            r = DRAW_HPI;
        }
    }
    *out = r;
    return 1;
}

extern s32 D_00372760;

// Steps the 16-bit random seed D_00372760 (x * 0x80D + 7).
void op_rand_lcg_step(void) {
    D_00372760 = (D_00372760 * 0x80D + 7) & 0xFFFF;
}

// VU0 random number times 32768.
s32 op_rand16(void) {
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

f32 op_sqrt(f32); // square root

// ray/sphere intersection: solves a*t*t + b*t + c = 0, returns 0 if the ray misses
s32 op_ray_sphere(DrawRaySphere* r) {
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
    r->t = (c - op_sqrt(d)) / b;
    return 1;
}

// The larger of a and b (VU0 vmax).
f32 op_max(f32 a, f32 b) {
    f32 v[4];
    v[0] = a;
    v[1] = b;
    __asm__ volatile("lqc2 $vf1,0(%0)\n\tvmaxy.x $vf1,$vf1,$vf1y\n\tsqc2 $vf1,0(%0)" : : "r"(v) : "memory");
    return v[0];
}

// Copies X and Y of b into a (VU0; the store writes vf31, probably a slip in the original).
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_copy_xy);

// Copies X, Y, Z of b into a, keeping a's W.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_copy_xyz);

// dst.xyz = src.xyz * f.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_scale_xyz);

// dst.xy = src.xy * f.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_scale_xy);

// dst.xy = a.xy + b.xy.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_add_xy);

// dst.xyz = a.xyz - b.xyz.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_sub_xyz);

// dst.xyz = a.xyz + b.xyz.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_add_xyz);

// dst.xy = a.xy - b.xy.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_sub_xy);

// Adds the XY of two vectors and converts the result to GS fixed point (12.4) with a range check.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_add_xy_gs);

// Converts a vector to GS fixed point (XY 12.4, ZW integer) with a range check.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_to_gs);

// Normalises the XY part of a vector.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_normalize_xy);

// Applies the matrix and divides by W.
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_project);

// Divides by W and converts to GS fixed point (XY 12.4, Z integer, W kept).
INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", op_vec_to_gs_persp);

// x to the n-th power by repeated multiplication.
f32 op_pow_int(s32 n, f32 x) {
    f32 r = 1.0f;
    s32 i;

    for (i = 0; i < n; i++) {
        r *= x;
    }
    return r;
}

// Square root (VU0 vsqrt).
f32 op_sqrt(f32 a) {
    f32 v[4];
    f32 r;
    v[1] = a;
    __asm__ volatile("lqc2 $vf10,0(%1)\n\tvsqrt Q,$vf10y\n\tvwaitq\n\tcfc2.ni $2,$vi22\n\tmtc1 $2,%0" : "=f"(r) : "r"(v) : "$2", "memory");
    return r;
}

// Sum of the squares of X, Y, Z (VU0), probably.
f32 op_vec_length_sq(f32* a) {
    f32 v[4];
    __asm__ volatile("lqc2 $vf10,0(%0)\n\tvmul.xyz $vf10,$vf10,$vf10\n\tvmove.xyz $vf9,$vf10\n\tvaddx.y $vf9,$vf9,$vf9x\n\tvaddy.z $vf9,$vf9,$vf9y\n\tvsqrt Q,$vf9z\n\tvwaitq\n\tvaddq.x $vf10,$vf0,Q\n\tsqc2 $vf10,0(%1)" : : "r"(a), "r"(v) : "memory");
    return v[0];
}

// Length of the XY part (VU0 vsqrt).
f32 op_vec_length_xy(f32* a) {
    f32 r;
    __asm__ volatile("lqc2 $vf10,0(%1)\n\tvmul.xy $vf10,$vf10,$vf10\n\tvaddx.y $vf10,$vf10,$vf10x\n\tvsqrt Q,$vf10y\n\tvwaitq\n\tcfc2.ni $2,$vi22\n\tmtc1 $2,%0" : "=f"(r) : "r"(a) : "$2");
    return r;
}

void func_001AB408(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack;

    sceVu0SubVector(stack, arg0, arg1);
    op_vec_length_sq(stack);
}

typedef struct {
    /* 0x0 */ u16* next;
    /* 0x4 */ u16 count;
    /* 0x6 */ u16 head;
} DrawFreeList;

// Takes an index from a u16 free list, or 0xFFFF when empty.
s32 DrawFreeList_Take(DrawFreeList* list) {
    u16 idx;

    if (list->head == 0xFFFF) {
        return 0xFFFF;
    }
    idx = list->head;
    list->head = list->next[idx];
    return idx;
}

// Sets up a u16 free list of count entries chained in order.
void DrawFreeList_Init(DrawFreeList* list, u16* next, u16 count) {
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

typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ u16 flag;
    /* 0x0A */ u8 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 col[4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ void* dmat;
    /* 0x24 */ void* unk_24;
    /* 0x28 */ void* unk_28;
    /* 0x2C */ void* cmat;
    /* 0x30 */ void* unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ pppSVECTOR* lpvert;
    /* 0x3C */ pppSVECTOR* lpnorm;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ char pad[0x18];
} DrawMdPrm; // parameter block for op1_md_draw (as MdPrm in pppDrawMdl.c)

extern char D_00616240[];
extern char D_00616140[];
extern char D_00616100[];
extern s32 D_00616224;
s32 op1_md_draw(OMD_H* omd, DrawMdPrm* prm, s32 size);

// Draws model index from the effect environment with op1_md_draw (mode bits from flags and the model's flags, colour col >> 7).
void op_draw_model(u32 index, u16* col, s32 a2, s32 a3, s32 a4, u8 flags, s32 a6) {
    pppModelSt* mdl;
    OMD_H* omd;
    sceVu0FMATRIX m;
    DrawMdPrm prm;

    if (index == 0xFFFF) {
        return;
    }
    mdl = &ppvEnv->lpModel[index];
    omd = mdl->omd;
    prm.mode = 0;
    if (flags & 2) {
        prm.mode = 4;
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    } else {
        if (flags & 1) {
            prm.mode = 0x80;
        }
        if (!(omd->flag & 1)) {
            prm.mode |= 8;
        }
    }
    if (!(omd->flag & 2)) {
        prm.mode |= 0x10;
    }
    if (flags & 4) {
        prm.mode |= 0x200;
    }
    if (flags & 8) {
        prm.mode |= 0x100;
    }
    if (flags & 0x10) {
        prm.mode |= 0x2000;
        prm.unk_30 = m;
        sceVu0MulMatrix(m, ppvWorldMatrix, ppvPObj.next->cmat);
    }
    prm.unk_44 = (flags & 0x20) ? a6 : 0;
    prm.flag = *(u16*)&omd->alpha;
    prm.unk_1C = 0;
    prm.lpvert = ppvPObj.next->lpvert;
    prm.lpnorm = ppvPObj.next->lpnorm;
    prm.unk_04 = D_00616240;
    prm.unk_0E = a2;
    prm.unk_10 = a3 << 16;
    prm.unk_14 = a4 << 16;
    prm.col[0] = col[0] >> 7;
    prm.col[1] = col[1] >> 7;
    prm.col[2] = col[2] >> 7;
    prm.col[3] = col[3] >> 7;
    prm.dmat = ppvPObj.next->dmat;
    prm.unk_24 = D_00616140;
    prm.unk_28 = D_00616100;
    prm.cmat = ppvPObj.next->cmat;
    prm.unk_34 = D_00616224;
    prm.unk_0C = 0;
    prm.unk_40 = 0;
    prm.unk_0A = 0;
    D_00616224 = op1_md_draw(omd, &prm, mdl->nPacketSize);
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABA80);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/draw", func_001ABCC8);

void op_init_draw(void) {
    ops_init_draw_work();
    ops_init_spr();
}

void ops_init_draw_work(void) {
    oa_dmagif = sceDmaGetChan(SCE_DMA_GIF);
}

extern u_long128 D_0061E800[];
extern u_long128 D_0061E8B0[];

// the two fixed GS register packets (A+D): ZBUF_1, TEST_1, TEX1_1, CLAMP_1, TEXA; they differ only in ZBUF
void op_gs2_init(void) {
    u64* p;

    p = (u64*)D_0061E800;
    p[2] = 0x5000000000008001;
    p[3] = 0xEEEEE;
    p[6] = 0x131000070;
    p[7] = 0x4E;
    p[12] = 0x7000D;
    p[13] = 0x47;
    p[14] = 0x21;
    p[15] = 0x14;
    p[18] = 0;
    p[19] = 8;
    p[16] = 0x8000000000;
    p[17] = 0x3B;
    p = (u64*)D_0061E8B0;
    p[2] = 0x5000000000008001;
    p[3] = 0xEEEEE;
    p[6] = 0x31000070;
    p[7] = 0x4E;
    p[12] = 0x7000D;
    p[13] = 0x47;
    p[14] = 0x21;
    p[15] = 0x14;
    p[18] = 0;
    p[19] = 8;
    p[16] = 0x8000000000;
    p[17] = 0x3B;
}

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

void op_ot_insert0(u32* p, s32 qwc, s32 pri, s32 arg3);
void op_ot_insert1(u32* p, s32 qwc, s32 pri, s32 arg3);

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
    op_ot_insert0((u32*)D_0061E800, 7, 0, 0);
    op_ot_insert1((u32*)D_0061E8B0, 7, 15, 0);
}

// sends the packet at D_0061E8B0 on its own (its first tag replaced by an end tag with 6 qwords)
void op_send_gs2_packet(void) {
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
void op_seed_vu0_rand(void) {
    s32 r = rand();

    __asm__ volatile("qmtc2.ni %0,$vf31\n\tvrxor R,$vf31x" : : "r"(r) : "$2");
}

// Returns the number of bits needed for n (the smallest b with 1 << b >= n).
s32 op_log2_ceil(s32 n) {
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
// Uploads a TIM2 picture's image (and CLUT, if it has one) to GS memory.
void op_load_tim2(DrawTim2* tm) {
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

// Uploads an image described by a DrawImage (VRAM base, width, format, position, size) and optionally waits.
void op_load_image(DrawImage* img, s32 wait) {
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
void op_ot_insert0(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT((DrawOtEnt*)D_0061EEA0, 15, p, qwc, pri);
}

extern DrawOtEnt D_0061FFA0[];

// ordering table 1 (16 priorities)
void op_ot_insert1(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT(D_0061FFA0, 15, p, qwc, pri);
}

extern DrawOtEnt D_0061EFA0[];

// ordering table 2 (256 priorities)
void op_ot_insert2(u32* p, s32 qwc, s32 pri, s32 arg3) {
    DRAW_OT_INSERT(D_0061EFA0, 255, p, qwc, pri);
}


// GS packet: alpha register + a 2-vertex sprite in colour rgba, inserted in OT 1 at priority 0
u8* op_fill_sprite(u8* p, u32 rgba, u8 alpha, u8 fix) {
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
    op_ot_insert1((u32*)p, 6, 0, 0);
    return p + 0x60;
}

#ifndef VERSION_FM
extern f32 D_00372800[16]; // fog work
#endif

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

// Copies D_002BC120 / D_002BC124 into the first two fog work values (probably fog near / far).
void op_fog_set_range(void) {
    D_00372800[0] = D_002BC120;
    D_00372800[1] = D_002BC124;
}

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/draw", D_00489A60);
