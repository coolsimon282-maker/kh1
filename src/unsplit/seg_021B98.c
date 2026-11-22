// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x021B98).
// Functions can be matched here like in any other file; the file may be split later.
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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121B98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121AE8);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121D60);

Seg21B98Unk10 *func_00121DE0(s32 id, s32 unused) {
    Seg21B98Unk10 *n;

    for (n = D_004F45B0.head.unk_10; n != NULL; n = n->unk_10) {
        if (n->unk_04 == id) {
            return n;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121C98);


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

extern u32* D_004F6EB8;
extern u32 D_004F6DB8[];

void func_00122410(void) {
    D_004F6DB8[0] = D_004F6DB8[1] = 0x70000000;
    D_004F6EB8 = D_004F6DB8;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122048);

void func_001220B8(void) {
    D_004F6EB8 -= 2;
}

void func_001220D0(void) {
    scePcStop();
}

void func_001220E8(void) {
    func_00148E60();
    func_001478E0();
    func_0013F2C0();
    func_00127340();
    func_0014F868();
    func_00151B90();
    func_00132E38();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122130);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122588);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_001223B8);
