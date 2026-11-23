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

extern u32* D_004F6EB8;
extern u32 D_004F6DB8[];

void func_00122410(void) {
    D_004F6DB8[0] = D_004F6DB8[1] = 0x70000000;
    D_004F6EB8 = D_004F6DB8;
}

u32 func_00122048(s32 a, u32 b) {
    u32 *p = D_004F6EB8;
    u32 *old = p;
    u32 n;

    p += 2;
    D_004F6EB8 = p;
    n = (old[1] + b - 1) / b * b;
    p[0] = n;
    if (a != 0) {
        D_004F6EB8[1] = n + a;
    } else {
        D_004F6EB8[1] = 0x70004000;
    }
    return n;
}

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

void func_0013CE98(void);
void func_001255F8(void);
void func_00124F38(void);
void func_00128B68(void);
void func_00133628(void);
void func_00148F08(void);
void func_00142340(void);
void func_00157DC8(void);
void func_001561F8(void);
void func_0014A248(void);
void func_0012FF80(void);

void func_00122130(void) {
    D_002C1EA8 = 0;
    func_0013CE98();
    func_001255F8();
    func_00124F38();
    func_00128B68();
    func_00133628();
    func_00148F08();
    func_00142340();
    func_00157DC8();
    func_001561F8();
    func_0014A248();
    func_0012FF80();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122588);

extern s32 D_00351A48;
void func_00239488(void);
void func_0014C378(void);
void fm_func_001249D8(void);
void func_0012FB18(void);
void func_0017EBD0(void);
void func_0017DB68(void);
void func_00146508(void);
void func_00151808(void);
void func_001762C8(void);
void func_00168518(void);
void func_001574F0(void);

void func_00122720(void) {
    func_00239488();
    func_00178140(0);
    func_0013BCA8();
    func_0014C378();
    fm_func_001249D8();
    func_0012FB18();
    func_0017EBD0();
    func_0017DB68();
    func_00133520();
    func_00146508();
    func_00151808();
    func_001762C8();
    func_00168518();
    D_00351A48 = 6;
    func_001574F0();
}

void func_00178140(s32);
void func_0013BCA8(void);
void func_001590A8(void);
void func_00124DD0(void);
void func_00133520(void);
void func_00146590(void);
void func_00148E98(void);
void func_0012B738(void);
void func_00123020(void);
void func_0014C330(void);
void func_001356A8(void);
void func_0012FC58(void);
void func_0016F548(void);

void func_001223B8(void) {
    func_00178140(0);
    func_0013BCA8();
    func_001590A8();
    func_00124DD0();
    func_00133520();
    func_00146590();
    func_00148E98();
    func_0012B738();
    func_00123020();
    func_0014C330();
    func_001356A8();
    func_0012FC58();
    func_0016F548();
}
