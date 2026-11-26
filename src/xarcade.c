#include "common_funcs.h"

#include "xlamp.h"
#include "xblade.h"
#include "xnoodle.h"
#include "xtailor.h"
#include "xpeanut.h"
#include "disk.h"
#include "io.h"

#include "libgraph.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
} XArcade;

extern char D_002B29B0[]; // "host:./kingdom.cnf"
extern char* D_002B29C8;
extern s64 D_002B2BB8;
extern s32 D_002B2C00;
extern s32 D_002B2CB0;
extern s32 D_002B2CC0;
extern s32 D_002B2CC4;
extern u_long128* D_002B2CC8;
extern u_long128* D_002B2CCC;
extern s32 D_002B85C0[4];
extern s32** D_002B8690;
extern s32** D_002B8694;
extern sceGsLoadImage D_002B8700;
extern sceGsLoadImage D_002B8760;
extern s32 D_002B8870;
extern s32 D_002B8C70;
extern s32 D_002B8C8C;

extern s32 D_00358BE0;
extern s32 D_002B9328;
extern vs32 D_00495160;
extern vs32 D_00495164;

extern XArcade D_0048EC00;
extern s32 D_0048EC08;

extern void func_F20000(s32, s32);
extern void func_00100240(); // in xbeginning
extern void func_00101560(void); // in xporcupine
void* func_00109DE8(void);
extern void func_00109C98();
extern u_long128* func_00121C98(s32, u_long128**);
extern void func_001600B8();
extern void func_001C20B8();
extern void func_00233968();
extern void func_00248530();

#ifdef VERSION_FM
extern u32 D_002BBDE4;
extern char D_002B6460[];
extern DiskManager D_0046A688; // disk_Mgr
extern char* D_002B6478;
extern s32 D_002BC73C;
void fm_func_00110068(void);
KingdomFile* func_00120190(char* filename); // cdvd_FindFile

void Graphics_Initialize(void) {
    KingdomFile* file;

    D_002BBDE4 = 7;
    fm_func_00110068();
    func_0010C010();
    GameData_BindBuffer();
    WorkBuffers_Clear(-1);
    func_0011EAF8(D_002B6460, "host:./kingdom.log");

    file = func_00120190("kingdom.img");
    if (file != NULL) {
        D_0046A688.unk_18(file->length);
    } else {
        D_0046A688.unk_18(0);
    }
    D_002B6478 = D_0046A688.unk_1C();
    func_00110230(0);
    D_002BC73C = 0;
    func_001ED888(NULL);
    func_0011F7C0();
}
#else
void Graphics_Initialize(void) {
    KingdomFile* file;

    func_0010FEC0();
    func_001102A0();
    func_0010C010();
    GameData_BindBuffer();
    WorkBuffers_Clear(-1);
    func_0011EAF8(D_002B29B0, "host:./kingdom.log");

    file = cdvd_FindFile("kingdom.img");
    if (file != NULL) {
        disk_Mgr.unk_18(file->length);
    } else {
        disk_Mgr.unk_18(0);
    }
    D_002B29C8 = disk_Mgr.unk_1C();
    func_00110230(0);
    D_002B8C8C = 0;
    func_001ED888(NULL);
    func_0011F7C0();
}
#endif

s32 func_001091B0(void) {
    TaskList_UpdateMatching(&D_002B8C70, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xarcade", func_001091D8);
void func_001091D8();

void* func_00109340(void) {
    func_00110190();
    func_00176E30();
    func_00176E98();
    D_00358BE0 = 1;
    func_0011EDD0(&D_002B8C70, &D_002B8870, 0x20, 0x20);
    return func_0011ED30(190050, func_001091B0);
}

void* func_001093A8(s32 arg0) {
    D_00495164 = arg0;
    D_00495160 = 2;
    return func_00109DE8();
}

#ifdef VERSION_FM
s32 fm_func_00109588(void) {
    D_002B9328 = 0;
    func_00101560();
    return func_00155ED8(0, 0x40);
}
#endif

#ifdef VERSION_FM
extern s32** D_002BC140;
extern s32** D_002BC144;
extern volatile s32 D_002BBDE0;
void func_00122130(void);
void func_0015F018(void);
void func_00236F18(void);

void func_001093D8(void) {
    func_00122130();
    func_0015F018();
    func_00100240();
    func_001C20B8();
    func_00236F18();
    func_00248530();
    D_002BC140 = D_002DEC60;
    D_002BC144 = D_002DECA0;
    D_002BBDE0 = 3;
    D_00495160 = 0;
}
#else
void func_001093D8(void) {
    func_00122518();
    func_001600B8();
    func_00100240();
    func_001C20B8();
    func_00233968();
    func_00248530();
    D_002B8690 = D_002DEC60;
    D_002B8694 = D_002DECA0;
}
#endif

void func_00109440(void) {
    FlushCache(INVALIDATE_ICACHE);
    func_F20000(0, 0);
}

extern s32 D_002B6484;
extern u32 D_002BCA00_w[] __asm__("D_002BCA00");
extern s32 D_002BBE08;
extern s32 D_002B9030;
s32 func_0010BF98_s(void) __asm__("func_0010BF98");
s32 func_00110F68_s(void) __asm__("func_00110F68");
s32 func_001EE090(void);
void func_00239488(void);
void func_00178140(s32);
void func_001220D0(void);
s32 func_0010FB90_s(void) __asm__("func_0010FB90");

s32 func_00109468(void) {


    if (D_002B6484 == 0 && (*(u64 *)D_002BCA00_w & 0xF0900000000) == 0xF0900000000 && (D_002BCA00_w[2] & 0xF09) != 0 &&
        func_0010BF98_s() == 0 && func_001EE090() == 0) {
        *(volatile s32 *)&D_002BBE08 = 0;
        func_001ED888(1);
        func_00114420();
        func_00239488();
        func_00178140(0);
        func_0010FB90_s();
        if (D_002B9030 != 0) {
            do {
                func_001220D0();
                func_00110FA8();
                func_001102C0();
            } while (func_00110F68_s() != 1);
            func_00110FC8();
        }
        func_001102C0();
        func_0010FDB8(0);
    }
    return *(volatile s32 *)&D_002BBE08;
}

INCLUDE_ASM("asm/nonmatchings/xarcade", func_00109580);

void func_001099D8(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, &func_F20000);
    sceGsSetDefLoadImage(&D_002B8760, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8760, &func_F20000 + 0x48000);
}

s32 func_00109AA0(void) {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(&img, func_F20000); // TODO look into - F20000 is probably an overlay location
    return 4;
}

void* func_00109B00(void) {
    return func_0011ED30(190000, func_00109AA0);
}

#ifdef VERSION_FM
extern f32 D_00495184;
extern f32 D_00495168;
extern f32 D_0049516C;
extern f32 D_002B8344;
extern u64 D_002B6490[];
extern u8 D_002B65E0[];
void func_001099D8(void);

s32 func_00109B28(void) {
    f32 a;
    f32 c;
    switch (D_0048EC08) {
    case 0:
        D_0048EC08 = 1;
        D_00495168 = D_00495184;
        D_0049516C = 128.0f / D_00495184;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_00495184 <= 0.0f)) {
        func_001099D8();
        c = (D_00495168 - D_00495184) * D_0049516C;
        a = D_00495184 * D_0049516C;
        D_002B6490[33] = (u64)(s32)a << 24 | 0x100808080;
        D_002B6490[17] = (u64)(s32)c << 24 | 0x100808080;
        func_00106948(D_002B65E0);
        D_00495184 -= D_002B8344;
        return 0;
    }
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", func_00109B28);
#endif
s32 func_00109B28();

void* func_00109C50(s32 arg0) {
    D_0048EC00.unk_04 = arg0 << 1;
    D_0048EC08 = 0;
    return func_0011ED30(190000, func_00109B28);
}

void func_00109C98(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, D_002B2CCC);
    sceGsSetDefLoadImage(&D_002B8760, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8760, D_002B2CCC + 0x4800);
}

s32 func_00109D68(void) {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CCC = func_00155ED8(62, 2);
    sceGsExecStoreImage(&img, D_002B2CCC);
    return 4;
}

void* func_00109DE8(void) {
    D_002B2CC4 = 1;
    if (D_002B85C0[0] != 0x80) {
        func_001037C8(1);
    }
    return func_0011ED30(190000, func_00109D68);
}

#ifdef VERSION_FM
extern f32 D_00495170;
extern s32 D_00495174;
extern f32 D_00495178;
extern f32 D_002B8344;
void func_00110170(void);

s32 func_00109E30(void) {
    s32 c;
    switch (D_0048EC00.unk_00) {
    case 0:
        D_00495170 = 64.0f;
        D_00495174 = 0x80;
        D_00495178 = 2.0f;
        D_0048EC00.unk_00 = 1;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_00495170 <= 0.0f)) {
        func_00109C98();
        c = D_00495174;
        D_002B2BB8 = (u64)c | ((u64)c << 8) | ((u64)c << 16) | ((u64)0x80 << 24) | ((u64)1 << 32);
        func_00106948(&D_002B2C00);
        D_00495170 -= D_002B8344;
        D_00495174 = D_00495170 * D_00495178;
        return 0;
    }
    D_002B2CC4 = 0;
    func_00110170();
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", func_00109E30);
#endif
s32 func_00109E30();

#ifdef VERSION_FM
extern f32 D_0049517C;
extern f32 D_002B8344;
void Fade_StartOverlayIn(s32);

s32 func_00109F60(void) {
    switch (D_0048EC00.unk_00) {
    case 0:
        Fade_StartOverlayIn(0x20);
        D_0048EC00.unk_00++;
        D_0049517C = 64.0f;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_0049517C <= 0.0f)) {
        func_00109C98();
        D_002B2BB8 = 0x180808080;
        func_00106948(&D_002B2C00);
        D_0049517C -= D_002B8344;
        return 0;
    }
    D_002B2CC4 = 0;
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", func_00109F60);
#endif
s32 func_00109F60();

void* func_0010A040(void) {
    D_0048EC00.unk_00 = 0;
    if (D_002B2CC0 != 0) {
        return func_0011ED30(190000, func_00109F60);
    }
    return func_0011ED30(190000, func_00109E30);
}

s32 func_0010A098(void) {
    func_00109C98();
    D_002B2BB8 = 0x180808080;
    func_00106948(&D_002B2C00);
    return 0;
}

void* func_0010A0E0(void) {
    return func_0011ED30(190000, func_0010A098);
}

void func_0010A108(void) {
    sceGsStoreImage img;

    func_00106948(&D_002B2CB0);
    sceGsSetDefStoreImage(&img, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CC8 = func_00121C98(0x24000, &D_002B2CC8);
    sceGsExecStoreImage(&img, D_002B2CC8);
}

void func_0010A190(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, D_002B2CC8);
}
