#include "common.h"

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
    /* 0x06 */ u8 unk_06[0xA];
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

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1888);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1970);

#ifdef VERSION_FM
s32 func_001C19E8(void) {
    return 0x171388;
}
#else
s32 func_001C19E8(void) {
    return 0x16FA88; // possibly some macro value?
}
#endif

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C19F8);

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

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1AE0);

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xbuffalo", fm_func_001C0078);
#endif

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1B40);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1BE8);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1D38);

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C1E78);

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

INCLUDE_ASM("asm/nonmatchings/xbuffalo", func_001C20B8);

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
    func_0011EF58(&D_00623B38, 0);
    return 0;
}

void* func_001C2178(void) {
    func_0011EDD0(&D_00623B38, &D_00623B48, 0x1C, 8);
    return func_0011ED30(50002, func_001C2150);
}

