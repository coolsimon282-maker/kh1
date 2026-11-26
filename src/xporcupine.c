#include "common.h"
#include "worldfile.h"

// .data
extern s32 D_002A050C;
extern s32 D_002A0520[2];
extern s32 D_002B8688;
extern s32 D_002B868C;
extern s32 D_002B9040;
extern s32 D_002B930C;
extern s32 D_002B9338;
extern s32 D_002BD8B8[2];
extern s32 D_002BD8DC;

// todo: .rodata also used in func_001011E0
const char D_00486970[] = ".img";

// .bss
extern s32 D_0048DE90[2];

extern s32 func_001011B8();
extern void func_0011C6C8(s32);

INCLUDE_ASM("asm/nonmatchings/xporcupine", func_001011E0);

s32 func_001014A8() {
    char stack[64];

    strcpy(stack, worldBinImgFile);
    strcat(stack, D_00486970);
    // strcat(stack, ".img");
    D_002A050C = func_00155ED8(0x34, 8);
    D_002A050C = func_001133E0(D_002A050C, 0x80);
    return cdvd_QueueFileLoad(stack, D_002A050C, func_001011B8, 0);
}

void func_00101528() {
    D_0048DE90[0] = -1;
    D_002BD8B8[0] = 0;
    D_0048DE90[1] = -1;
    D_002BD8B8[1] = 0;
    D_002BD8DC = 0;
    D_002B9338 = 0;
}

void func_00101560() {
    D_002B8688 = -1;
    D_002B868C = -1;
    D_002B930C = 0;
}

void func_00101580() {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_0048DE90); i++) {
        if (D_0048DE90[i] != D_002A0520[i]) {
            if (D_002A0520[i] != 0) {
                func_0011D070(D_002A0520[i], i, &D_002B9040, 0x3FFF);
            }
            D_0048DE90[i] = D_002A0520[i];
        }
    }
}

void func_00101628(s32 arg0) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_0048DE90); i++) {
        if ((D_0048DE90[i] != D_002A0520[i]) || (D_0048DE90[i] == 0)) {
            func_0011D1F8(D_0048DE90[i], i, arg0);
        }
    }
}

// nonmatch: regswap?
void func_001016B8(void) {
    ((s32 (*)(s32))func_0011C6C8)(0);
    D_0048DE90[0] = -1;
    D_0048DE90[1] = -1;
    func_00101580();
}
// void func_001016B8() {
//     func_0011C6C8(0);
//     D_0048DE90[0] = -1;
//     D_0048DE90[1] = -1;
//     func_00101580();
// }

s32 func_001016E8(void) {
    extern s32 D_002BC12C;
    extern s32 D_002B9304;
    extern s32 D_002B9308;
    extern s32 curWorldNo;
    extern s32 D_002B9328;
    extern s32 D_002A0508;
    extern s32 func_00113380();
    extern s32 func_001011E0();
    s32 pad[4];
    char buf[64];

    ((void (*)(s32))worldfile_getBinImgName)(D_002BC12C);
    if (D_002B9304 == 1 && D_002B868C == D_002BC12C) {
        D_002B9308 = D_002B9304;
    }
    func_0011D310(0x1E0);
    func_00101628(0x3C0);
    if (curWorldNo == 8 && D_002BC12C == 8) {
        func_0011C6C8(1);
    }
    if (D_002B8688 == 8 && D_002B868C == 8) {
        func_0011C6C8(0);
    }
    D_002B8688 = curWorldNo;
    if (D_002B9308 == 1) {
        if (D_002B9328 != 0) {
            func_001014A8();
        } else {
            func_0011ED30(0xC350, func_00113380);
        }
    } else {
        strcpy(buf, worldBinImgFile);
        strcat(buf, ".bin");
        D_002A0508 = func_001133E0(D_002A0508, 0x80);
        cdvd_QueueFileLoad(buf, D_002A0508, func_001011E0, 0);
    }
    D_002B868C = D_002BC12C;
    return 4;
}
