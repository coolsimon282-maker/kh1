#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} MonitorSub;

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    MonitorSub sub[3];
} Monitor;

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246B50);

void func_00246C28(Monitor* m) {
    m->unk60 |= 8;
    m->sub[0].unk10 |= 2;
}

void func_00246C48(Monitor* m) {
    m->sub[0].unk10 = 0;
    m->unk60 &= ~8;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246C60);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246C80);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246D60);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246D68);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246E80);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246EA0);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246FF0);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247010);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247028);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247030);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247108);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247128);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247218);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247238);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247250);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247258);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_002475E8);

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247668);
