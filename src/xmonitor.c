#include "common.h"
#include "eestruct.h"

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

typedef struct {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 unk_04[0x1C];
} MonitorKey; // size = 0x20

extern char D_00491848[]; // "ttlib/ui.c"
extern char D_00491858[];
void __assert(const char* file, int line, const char* expr);

void func_00246B50(Monitor* m, s32 dt) {
    MonitorSub* s;

    if ((*(u64*)&m->unk60 & 0xA) == 0xA) {
        s = &m->sub[0];
        if (s == NULL) {
            __assert(D_00491848, 14, D_00491858);
        }
        if (s->unk4 < s->unk8 - 1) {
            s->unk0 += dt;
            do {
                s32 t = ((MonitorKey*)s->unkC)[s->unk4].time;

                if (s->unk0 < t) {
                    return;
                }
                s->unk0 -= t;
                s->unk4++;
            } while (s->unk4 != s->unk8 - 1);
            m->sub[0].unk10 |= 4;
        }
    }
}

void func_00246C28(Monitor* m) {
    m->unk60 |= 8;
    m->sub[0].unk10 |= 2;
}

void func_00246C48(Monitor* m) {
    m->sub[0].unk10 = 0;
    m->unk60 &= ~8;
}

void func_00246C60(Monitor* m) {
    MonitorSub* s = &m->sub[0];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246C80);

s32 func_00246D60(Monitor* m) {
    return m->sub[0].unk10;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246D68);

void func_00246E80(Monitor* m) {
    MonitorSub* s = &m->sub[1];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00246EA0);

void func_00246FF0(Monitor* m) {
    m->unk60 |= 0x80;
    m->sub[1].unk10 |= 2;
}

void func_00247010(Monitor* m) {
    m->sub[1].unk10 = 0;
    m->unk60 &= ~0x80;
}

s32 func_00247028(Monitor* m) {
    return m->sub[1].unk10;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247030);

void func_00247108(Monitor* m) {
    MonitorSub* s = &m->sub[2];
    s->unk4 = 0;
    s->unk0 = 0;
    s->unk10 &= ~4;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247128);

void func_00247218(Monitor* m) {
    m->unk60 |= 0x10;
    m->sub[2].unk10 |= 2;
}

void func_00247238(Monitor* m) {
    m->sub[2].unk10 = 0;
    m->unk60 &= ~0x10;
}

s32 func_00247250(Monitor* m) {
    return m->sub[2].unk10;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247258);

void func_00247258(sceGsTex0* tex, s32 arg1, u64 arg2);

void func_002475E8(s32 arg0, sceGsTex0* tex, u64* arg2) {
    func_00247258(tex, arg0, arg2[3]);
    tex->CSA = 0;
    tex->CLD = 1;
    tex->PSM = 0x13;
}

INCLUDE_ASM("asm/nonmatchings/xmonitor", func_00247668);
