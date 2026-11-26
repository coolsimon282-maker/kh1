// Placeholder for code that hasn't been assigned to a source file yet (Final Mix 0x121B98-0x122028): JP's asm piece
// 0x121A08-0x121DE0 (+0x190 here) and the two hand-written functions JP's xlamp.c has as INCLUDE_ASM (func_00121F6C,
// func_001223B0 = JP 0x122358/0x1223B0; they start 4-aligned, so they cannot start a piece of their own here).
#include "common.h"

void func_00127340(void);
void func_00132E38(void);
void func_0013F2C0(void);
void func_001478E0(void);
void func_00148E60(void);
void func_0014F868(void);
void func_00151B90(void);

typedef struct Seg21B98Unk10 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32* unk_0C;
    struct Seg21B98Unk10 *unk_10;
} Seg21B98Unk10;
typedef struct {
    Seg21B98Unk10 head;
    Seg21B98Unk10 e[0x1FF];
    Seg21B98Unk10 *cur;
} A2NodePool;
extern A2NodePool D_004F45B0;
Seg21B98Unk10* func_00121DE0(s32, s32);

void func_00121F6C(s32, s32, s32);

s32 func_00121B98(void) {
    Seg21B98Unk10* prev = &D_004F45B0.head;
    Seg21B98Unk10* p;
    u32 moved = 0;
    s32 dst;

    for (p = prev->unk_10; p != NULL; p = p->unk_10) {
        p->unk_00++;
        if (p->unk_0C == NULL) {
            p->unk_04 = 0;
            prev->unk_10 = p->unk_10;
        } else {
            if (moved <= 0x1FFFF && (u32)p->unk_00 >= 4) {
                dst = prev->unk_04 + prev->unk_08;
                if (p->unk_04 - dst > 0) {
                    func_00121F6C(p->unk_04, dst, p->unk_08);
                    p->unk_04 = dst;
                    *p->unk_0C = dst;
                    moved += p->unk_08;
                }
            }
            prev = p;
        }
    }
    return 0;
}

extern u8 D_820000[];
extern Seg21B98Unk10 *D_004F6DB0;
s32 func_00121B98(void);
void func_00121AE8(void) {
    A2NodePool *d = &D_004F45B0;
    Seg21B98Unk10 *h;
    s32 i;
    s32 *p = &d->e[0].unk_04;
    for (i = 0; i < 0x1FF; i++) {
        *p = 0; p += 5;
    }
    h = &D_004F45B0.head; D_004F6DB0 = h + 1;
    h->unk_04 = (s32)D_820000;
    h->unk_0C = 0;
    h->unk_10 = 0;
    h->unk_08 = 0;
    ((s16 *)func_0011ED30(200000, func_00121B98))[1] = -1;
}

extern Seg21B98Unk10 *D_004F6DB0;

Seg21B98Unk10 *func_00121D00(void) {
    Seg21B98Unk10 *p = D_004F6DB0;
    s32 i;

    for (i = 1; i < 0x200; i++) {
        p++;
        if (p >= &D_004F45B0.e[0x1FF]) {
            p = D_004F45B0.e;
        }
        if (p->unk_04 == 0) {
            D_004F6DB0 = p;
            return p;
        }
    }
    return NULL;
}

extern u8 D_9A0000[];

Seg21B98Unk10 *func_00121D60(u32 size) {
    Seg21B98Unk10 *prev = &D_004F45B0.head;
    Seg21B98Unk10 *n;

    while ((n = prev->unk_10) != NULL) {
        if ((u32)(n->unk_04 - (prev->unk_04 + prev->unk_08)) >= size) {
            return prev;
        }
        prev = n;
    }
    if ((u32)((s32)D_9A0000 - (prev->unk_04 + prev->unk_08)) >= size) {
        return prev;
    }
    return NULL;
}

Seg21B98Unk10 *func_00121DE0(s32 id, s32 unused) {
    Seg21B98Unk10 *n;

    for (n = D_004F45B0.head.unk_10; n != NULL; n = n->unk_10) {
        if (n->unk_04 == id) {
            return n;
        }
    }
    return NULL;
}

s32 func_00121C98(s32 size, s32 *out) {
    s32 sz = (size + 0x7F) & ~0x7F;
    Seg21B98Unk10 *n = func_00121D00();
    Seg21B98Unk10 *prev = func_00121D60(sz);
    s32 addr = prev->unk_04 + prev->unk_08;

    n->unk_04 = addr;
    if (out != NULL) {
        *out = addr;
    }
    n->unk_08 = sz;
    n->unk_0C = out;
    n->unk_00 = 0;
    n->unk_10 = prev->unk_10;
    prev->unk_10 = n;
    return n->unk_04;
}


void func_00121EB0(s32 arg0, s32 arg1) {
    Seg21B98Unk10* p = func_00121DE0(arg0, arg1);

    if (p->unk_0C != NULL) {
        *p->unk_0C = 0;
    }
    p->unk_0C = NULL;
}

void func_00121D50(s32 id) {
    Seg21B98Unk10 *prev;
    Seg21B98Unk10 *n;

    for (prev = &D_004F45B0.head; (n = prev->unk_10) != NULL; prev = n) {
        if (n->unk_04 == id) {
            break;
        }
    }
    if (n->unk_0C != NULL) {
        *n->unk_0C = 0;
    }
    n->unk_0C = NULL;
    n->unk_04 = 0;
    prev->unk_10 = n->unk_10;
}

void func_00121F30(s32 a0, s32 *a1) {
    Seg21B98Unk10 *p = func_00121DE0(a0, (s32)a1);

    *a1 = a0;
    p->unk_0C = a1;
    p->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121F6C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_001223B0);
