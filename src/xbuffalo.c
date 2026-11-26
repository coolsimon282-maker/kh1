#include "common.h"
#include <stdarg.h>

s32 D_003759C4;
s32 D_003759C8;
s32 D_003759DC;

s32 D_00623B38;
s32 D_00623B48;

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1680);

s32 func_001C1838(void) {
    return D_003759DC;
}

void func_001C1848(s32 arg0) {
    D_003759C4 = arg0;
}

void func_001C1858(s32 arg0) {
    D_003759C8 = arg0;
}

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u8 unk_14[0xC];
    /* 0x20 */ void (*unk_20)(void);
    /* 0x24 */ u8 unk_24[0xC];
} XBuffaloUnk1868; // size = 0x30

extern s32 D_0037A168;
extern XBuffaloUnk1868* D_0037A16C;

s32* func_001C1868(void) {
    return &D_0037A16C[D_0037A168].unk_10;
}

extern s32 D_0037A164;
extern s32 D_0037A170;
extern s32 D_006257D4;
void func_001BE820(void*, s32);

// sets up the slot table: slot 0, 15 big buffers (0x81C0) and 384 small ones (0x9C0) in D_006257D4
void func_001C1888(void) {
    s32 buf;
    s32 i;
    s32* p;

    D_003759DC = 1;
    D_0037A164 = 0;
    D_0037A168 = 0;
    buf = D_006257D4;
    func_001BE820(D_0037A16C, 0x30);
    D_0037A16C[0].unk_00 = 1;
    D_0037A16C[0].unk_0C = 0;
    D_0037A16C[0].unk_02 = 0;
    D_0037A16C[0].unk_04 = 0;
    D_0037A16C[0].unk_06 = 0;
    D_0037A16C[0].unk_08 = (u8*)buf;
    buf += 0x1C0;
    for (i = 1; i < 16; i++) {
        func_001BE820(&D_0037A16C[i], 0x30);
        D_0037A16C[i].unk_08 = (u8*)buf;
        buf += 0x81B0;
        D_0037A16C[i].unk_0C = buf;
        buf += 0x10;
        D_0037A16C[i].unk_02 = 0;
        D_0037A16C[i].unk_04 = 0;
        D_0037A16C[i].unk_06 = 0;
        D_0037A16C[i].unk_00 = 0;
    }
    for (i = 0; i < 0x180; i++) {
        func_001BE820(&D_0037A16C[i + 16], 0x30);
        D_0037A16C[i + 16].unk_08 = (u8*)buf;
        buf += 0x9B0;
        D_0037A16C[i + 16].unk_0C = buf;
        buf += 0x10;
        D_0037A16C[i + 16].unk_02 = 0;
        D_0037A16C[i + 16].unk_04 = 0;
        D_0037A16C[i + 16].unk_06 = 0;
        D_0037A16C[i + 16].unk_00 = 0;
    }
    p = (s32*)D_0037A170;
    p[0] = (s32)D_0037A16C[0].unk_08;
    p[1] = 0;
    p[2] = 0;
    p[3] = -1;
}

void func_001C1888(void);

s32 func_001C1970(s32 arg0) {
    s32 p;

    p = arg0 + 0x16BC00;
    D_0037A16C = (XBuffaloUnk1868*)p;
    p = arg0 + 0x170700;
    D_0037A170 = p;
    D_003759C4 = 0;
    D_003759C8 = 15;
    D_006257D4 = arg0;
    p = arg0 + 0x171388;
    func_001C1888();
    return p;
}

#ifdef VERSION_FM
s32 func_001C19E8(void) {
    return 0x171388;
}
#else
s32 func_001C19E8(void) {
    return 0x16FA88; // possibly some macro value?
}
#endif

s32 func_001C19F8(s32 arg0) {
    s32 i;

    if (arg0 == 0) {
        for (i = 1; i < 16; i++) {
            if (D_0037A16C[i].unk_00 == 0) {
                return i;
            }
        }
        return -1;
    }
    for (i = 0; i < 0x180; i++) {
        if (D_0037A16C[i + 16].unk_00 == 0) {
            return i + 16;
        }
    }
    return -1;
}

u16 func_001C1A90(s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    return D_0037A16C[arg0].unk_00;
}

void func_001C1AB8(s32 arg0) {
    if (arg0 >= 0) {
        if (D_0037A16C[arg0].unk_20 != NULL) {
            D_0037A16C[arg0].unk_20();
        }
        D_0037A16C[arg0].unk_00 = 0;
        D_0037A16C[arg0].unk_02 = 0;
        D_0037A16C[arg0].unk_04 = 0;
    }
}

// frees every used slot (except slot 0) and sets the table up again
void func_001C1AE0(void) {
    s32 i;

    for (i = 1; i < 400; i++) {
        if (D_0037A16C[i].unk_00 != 0) {
            func_001C1AB8(i);
        }
    }
    func_001C1888();
}

#ifdef VERSION_FM
void fm_func_001C0078(s32 arg0) {
    if (arg0 >= 0) {
        if (D_0037A16C[arg0].unk_00 != 0) {
            D_0037A16C[arg0].unk_04 |= 1;
        }
    } else if (D_0037A168 != 0) {
        D_0037A16C[D_0037A168].unk_04 |= 1;
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1B40);

typedef union { u_long128 q; s32 w[4]; } XBuffaloQW;

s32 puts(const char*);
extern char D_00490300[]; // error message for a full table

// like func_001C1D38, with a slot from 1..15
s32 func_001C1BE8(s32 arg0, s32 arg1, ...) {
    va_list ap;
    XBuffaloQW t;
    s32 idx;
    s32 i;

    if (arg0 < 0) {
        arg0 = 0xFFFF;
    }
    idx = func_001C19F8(0);
    if (idx < 0) {
        puts(D_00490300);
        return -1;
    }
    D_0037A16C[idx].unk_00 = 1;
    D_0037A16C[idx].unk_02 = arg0;
    t.q = 0;
    t.w[0] = D_0037A16C[idx].unk_0C;
    *(u_long128*)(D_0037A16C[idx].unk_08 + 0xD0) = t.q;
    t.w[0] = arg1;
    *(u_long128*)(D_0037A16C[idx].unk_08 + 0xF0) = t.q;
    t.q = 0;
    va_start(ap, arg1);
    for (i = 0; i < 8; i++) {
        t.w[0] = va_arg(ap, s32);
        *(u_long128*)(D_0037A16C[idx].unk_08 + i * 16 + 0x140) = t.q;
    }
    va_end(ap);
    *(u_long128*)&D_0037A16C[idx].unk_10 = 0;
    return idx;
}

// takes a free slot from 16 up; arg0 = id (0xFFFF if < 0), then nine words copied into qwords of unk_08
s32 func_001C1D38(s32 arg0, s32 arg1, ...) {
    va_list ap;
    XBuffaloQW t;
    s32 idx;
    s32 i;

    if (arg0 < 0) {
        arg0 = 0xFFFF;
    }
    idx = func_001C19F8(1);
    if (idx < 0) {
        return -1;
    }
    D_0037A16C[idx].unk_00 = 1;
    D_0037A16C[idx].unk_02 = arg0;
    t.q = 0;
    t.w[0] = D_0037A16C[idx].unk_0C;
    *(u_long128*)(D_0037A16C[idx].unk_08 + 0xD0) = t.q;
    t.w[0] = arg1;
    *(u_long128*)(D_0037A16C[idx].unk_08 + 0xF0) = t.q;
    t.q = 0;
    va_start(ap, arg1);
    for (i = 0; i < 8; i++) {
        t.w[0] = va_arg(ap, s32);
        *(u_long128*)(D_0037A16C[idx].unk_08 + i * 16 + 0x140) = t.q;
    }
    va_end(ap);
    *(u_long128*)&D_0037A16C[idx].unk_10 = 0;
    return idx;
}

typedef struct {
    /* 0x0 */ u8* buf;
    /* 0x4 */ s32 idx;
} XBuffaloDraw;

// frees the slots flagged in unk_04 bit 0, then lists the used slots in D_0037A170 sorted by unk_02 (ends with -1)
void func_001C1E78(void) {
    s16 order[0x400];
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    XBuffaloUnk1868* p;

    n = 1;
    for (i = 1; i < 400; i++) {
        if (D_0037A16C[i].unk_00 != 0 && (u16)(D_0037A16C[i].unk_04 & 1)) {
            func_001C1AB8(i);
        }
        if (D_0037A16C[i].unk_00 != 0) {
            n++;
        }
    }
    D_003759DC = n;
    ((XBuffaloDraw*)D_0037A170)[0].idx = 0;
    ((XBuffaloDraw*)D_0037A170)[0].buf = D_0037A16C[0].unk_08;
    if (n < 2) {
        return;
    }
    order[0] = -1;
    n = 0;
    for (i = 1, p = &D_0037A16C[1]; i < 400; i++, p++) {
        if (p->unk_00 == 0) {
            continue;
        }
        for (j = 0; j < n; j++) {
            if (D_0037A16C[i].unk_02 < D_0037A16C[order[j]].unk_02) {
                break;
            }
        }
        for (k = n - 1; k >= j; k--) {
            order[k + 1] = order[k];
        }
        order[j] = i;
        n++;
    }
    for (i = 0; i < n; i++) {
        ((XBuffaloDraw*)D_0037A170)[i + 1].idx = order[i];
        ((XBuffaloDraw*)D_0037A170)[i + 1].buf = D_0037A16C[order[i]].unk_08;
    }
    ((XBuffaloDraw*)D_0037A170)[i + 1].idx = -1;
    ((XBuffaloDraw*)D_0037A170)[i + 1].buf = 0;
}

void func_001C1680(void);

void func_001C2080(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_001C1680();
    }
}

#ifdef VERSION_FM
void fm_func_001C06C0(s32 arg0, void (*arg1)(void)) {
    if (arg0 < 0) {
        arg0 = D_0037A168;
    }
    D_0037A16C[arg0].unk_20 = arg1;
}
#endif

typedef struct {
    u8 unk_00[0x3034];
    s32 unk_3034;
    s32 unk_3038;
    u8 unk_303C[0x34];
    u64 unk_3070;
} XBuffaloGM;
extern XBuffaloGM D_003854E0;
void* func_001C2178(void);
void func_001DE360(void);

void func_001C20B8(void) {
    D_003854E0.unk_3034 = 0;
    D_003854E0.unk_3038 = 0;
    D_003854E0.unk_3070 &= ~0x0400000000000000;
    func_001C2178();
    func_001DE360();
    return; // the explicit return stops gcc from making the last call a tail call
}

extern s32 D_0037A178[4];

void func_001C21B8(void);
void func_001CEC98(void);
void func_001E01B8(void);
void func_001EA430(void);
void func_001E4918(void);

void func_001C2110(void) {
    func_001C21B8();
    func_001CEC98();
    func_001E01B8();
    func_001EA430();
    func_001E4918();
    D_0037A178[0] = 0;
    D_0037A178[1] = 0;
    D_0037A178[2] = 0;
    D_0037A178[3] = 0;
}

#ifdef VERSION_FM
void fm_func_001C07A8(void) {
    D_0037A178[0] = 0;
    D_0037A178[1] = 0;
    D_0037A178[2] = 0;
    D_0037A178[3] = 0;
}
#endif

s32 func_001C2150(void) {
    TaskList_UpdateMatching(&D_00623B38, 0);
    return 0;
}

void* func_001C2178(void) {
    TaskList_Init(&D_00623B38, &D_00623B48, 0x1C, 8);
    return TaskSystem_AddTask(50002, func_001C2150);
}

