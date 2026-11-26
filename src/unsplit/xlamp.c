// Final Mix's version of the rest of xlamp (JP: src/xlamp.c 0x121DE0-0x122828; here 0x122028-0x122430, from JP's
// func_00122410 on). JP's first half is not here (func_00122228/func_001222B0 are at 0x15ED80, in seg_03BDE8).
// Split out of the placeholder seg_021B98; FM only (JP/EU use src/xlamp.c).
#include "common.h"

void func_00127340(void);
void func_00132E38(void);
void func_0013F2C0(void);
void func_001478E0(void);
void func_00148E60(void);
void func_0014F868(void);
void func_00151B90(void);
void func_00121F30(s32 a0, s32 *a1);

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

void func_00122588(s32 a0, s32 a1) {
    extern s32 D_002B8678;
    extern s32 D_002B8680;
    extern s32 D_002B8684;
    extern s32 D_002C5C4C;
    extern s32 D_002C5C50;
    extern s32 D_002C5C54;
    extern void func_00132C70(s32, s32);

    D_002C1EA8 = 0;
    if (D_002B8678 == 0x10 && (D_002B8680 == 0x1A || D_002B8680 == 0x21 || D_002B8680 == 0x22)) {
        D_002C1EA8 |= 0x20;
    }
    D_002C5C4C = D_002B8678 == 9 || (D_002B8678 == 0x10 && D_002B8680 == 0x15);
    D_002C5C50 = D_002B8678 == 10 || (D_002B8678 == 0x10 && D_002B8680 == 0x16);
    D_002C5C54 = D_002B8678 == 0xF && D_002B8684 == 10;
    func_0012B738();
    func_00124F38();
    func_00142030();
    func_001561B0();
    func_00132C70(a0, a1);
    func_00133520();
    func_00146590();
    func_00151808();
    func_001356A8();
    func_0014C378();
    func_0012FF80();
    func_00123108();
    func_00134718();
    func_0013BCA8();
    func_0012EA38();
}

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
