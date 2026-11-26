/**
 * Memory card layer over libmc (memcard_*): initialisation and defaults, per-command status getters, get info / list
 * files / format / unformat / chdir / mkdir / delete / write / rename, and the command runner.
 * JP/EU: 0x2304D8-0x233078. Final Mix (#ifdef VERSION_FM): 0x233A80-0x236618, the same functions in the same order
 * (FM's names are its own addresses), paired with JP's.
 */
#include "common.h"

#ifdef VERSION_FM
#include "sdk/ee/eetypes.h"

extern u64 D_006477B0[];
void func_00233AC8(void);
void func_00233A80(void) {
    u64* p;
    s32 i;

    sceMcInit();
    p = D_006477B0;
    for (i = 0x100; i > 0; i--) {
        *p++ = 0;
    }
    func_00233AC8();
}
#else
#include "memcard.h"

#include "libmc.h"

void (*memcardCommands[14])(void) = {
    func_00231370,    memcard_GetInfo, memcard_GetAllFiles, memcard_GetDirFiles, memcard_Format,
    memcard_Unformat, memcard_Chdir,   memcard_Mkdir,       memcard_Create,      memcard_Delete,
    memcard_Read,     memcard_Write,   memcard_Rename,      func_00232FF8,
};
s32 D_0041F900[2] = {};
s32 memcardPort = 0;
s32 memcardSlot = 0;
// Type of memory card detected
s32 memcardType = sceMcTypeNoCard;

// Number of free clusters on memory card, if available
s32 memcardFree = 0;

// Boolean indicating if the memory card is formatted
s32 memcardFormat = 0;
s32 D_0041F920[2][4] = {};
s32 D_0041F940[2][4] = {};
s32 D_0041F960[2][4] = {};
s32 D_0041F980[2][4] = {};

// Buffer for storing the obtained file list
sceMcTblGetDir* memcardFileBuf = NULL;

// Number of entries to be written to table
// If negative, skips writing and `sceMcSync` only returns number of entries matching `name`
s32 memcardEntries = 0;

// Buffer for storing the current directory
char memcardDirStore[32] = {};
s32 D_0041F9C8[2] = {};

// .bss

s32 D_006417B8;
s64 D_006417C0[0x100];
s32 memcardCurCmdIdx;
// Commands are executed in a loop, altering behavior based on the current step
s32 memcardLoopStep;
s32 D_00641FC8;
s32 D_00641FCC;
s32 D_00641FD0;
s32 D_00641FD4;

// Stores result of sceMcSync. Negative values indicate an error, positive carries contextual values
s32 memcardResult;

s32 D_00641FDC;
s32 D_00641FE0;
s32 D_00641FE4;
s32 D_00641FE8;
s32 D_00641FEC;
s32 D_00641FF0;

// Status flags for each command
s32 memcardStatus[14];

char* memcardFileName;
char* memcardNewFileName;
void* memcardFileBuffer;
s32 memcardFileSize;
s32 memcardFileHandle;
s32 (*D_00642044)(s32);

void memcard_Initialize(void) {
    s32 i;
    s64* buffer;

    sceMcInit();
    buffer = D_006417C0;
    for (i = ARRAY_COUNT(D_006417C0); i > 0; i--) {
        *buffer = 0;
        buffer++;
    }
    memcard_SetDefaults();
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00233AC8);
#else
void memcard_SetDefaults(void) {
    s32 i, j;
    s32 port;

    for (i = 0; i < 2; i++) {
        D_0041F9C8[i] = 1;
        D_0041F900[i] = sceMcGetSlotMax(i);
    }

    memcardCurCmdIdx = 0;
    memcardLoopStep = 0;
    D_00641FC8 = 0;
    D_00641FCC = 0;
    D_00641FD0 = 1;
    D_00641FD4 = 1;
    memcardPort = 0;
    memcardSlot = 0;
    D_006417B8 = 0;
    D_00641FE4 = 300;
    D_00641FE8 = 300;

    for (i = 0; i < ARRAY_COUNT(memcardStatus); i++) {
        memcardStatus[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_0041F920[i][j] = 3;
            D_0041F940[i][j] = 0;
            D_0041F960[i][j] = 0;
            D_0041F980[i][j] = 0;
        }
    }

    for (port = 0; port < 2; port++) {
        sceMcGetInfo(port, 0, &memcardType, &memcardFree, &memcardFormat);

        sceMcSync(0, 0, &memcardResult);
        switch (memcardResult) {
            case 0:
                D_0041F920[port][0] = 0;
                break;
            case -1:
                D_0041F920[port][0] = 1;
                break;
            case -2:
                D_0041F920[port][0] = 2;
                break;
            default:
                D_0041F920[port][0] = 3;
                break;
        }
    }
}
#endif

#ifdef VERSION_FM
typedef struct { s32 a; s32 id; u8 pad[0x18]; } Q233D08;
extern Q233D08 D_006477B0_r[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FBC;
extern s32 D_00647FB0_r __asm__("D_00647FB0");
extern s32 D_00647FC4_r __asm__("D_00647FC4");
s32 func_00233D08(s32 id) {
    s32 i;

    if (id != 0) {
        for (i = D_00647FBC; i != D_00647FB8; i++, i &= 0x3F) {
            if (D_006477B0_r[i].id == id) {
                return 1;
            }
        }
        if (D_00647FB0_r != 0 && D_00647FC4_r == id) {
            return 1;
        }
    } else if (D_00647FB8 != D_00647FBC || D_00647FB0_r != 0) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230760);
#endif

#ifdef VERSION_FM
typedef struct { s32 a; s32 id; u8 pad[0x18]; } Q132_20;
extern Q132_20 D_006477B0_q[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FBC;
extern s32 D_00647FB0_q __asm__("D_00647FB0");
extern s32 D_00647FC4_q __asm__("D_00647FC4");
void func_002365E0(void);
int sceGsSyncV(int);

void func_00233DB0(s32 id) {
    s32 i;

    if (id != 0) {
    again:
        for (i = D_00647FBC; i != D_00647FB8; i++, i &= 0x3F) {
            if (D_006477B0_q[i].id == id) {
                func_002365E0();
                sceGsSyncV(0);
                goto again;
            }
        }
        if (D_00647FB0_q != 0 && D_00647FC4_q == id) {
            do {
                func_002365E0();
                sceGsSyncV(0);
            } while (D_00647FB0_q != 0);
        }
    } else {
        while (D_00647FB8 != D_00647FBC || D_00647FB0_q != 0) {
            func_002365E0();
            sceGsSyncV(0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230810);
#endif

#ifdef VERSION_FM
extern s32 D_006477A8;

s32 func_00233EE8(void) {
    return D_006477A8;
}
#else
s32 func_00230948(void) {
    return D_006417B8;
}
#endif

#ifdef VERSION_FM
extern s32 D_006477A8;
extern s32 D_00647FD4;
extern s32 D_00647FD8;
void func_00233EF8(s32 arg0) {
    D_006477A8 = 1;
    D_00647FD4 = arg0;
    D_00647FD8 = 0;
}
#else
void func_00230958(s32 arg0) {
    D_006417B8 = 1;
    D_00641FE4 = arg0;
    D_00641FE8 = 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_006477A8;

void func_00233F18(void) {
    D_006477A8 = 0;
}
#else
void func_00230978(void) {
    D_006417B8 = 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FDC;
extern s32 D_00647FE0;

void func_00233F28(s32 arg0, s32 arg1) {
    D_00647FDC = arg0;
    D_00647FE0 = arg1;
}
#else
void func_00230988(s32 arg0, s32 arg1) {
    D_00641FEC = arg0;
    D_00641FF0 = arg1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C48[];

s32 func_00233F40(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}
#else
s32 func_002309A0(s32 port, s32 slot) {
    s32 iVar1 = D_0041F940[port][slot];
    D_0041F940[port][slot] = 0;
    return iVar1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C48[];

void func_00233F68(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    *ptr = 0;
}
#else
void func_002309C8(s32 port, s32 slot) {
    D_0041F940[port][slot] = 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C68[];

s32 func_00233F88(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}
#else
s32 func_002309E8(s32 port, s32 slot) {
    s32 iVar1 = D_0041F960[port][slot];
    D_0041F960[port][slot] = 0;
    return iVar1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C68[];

void func_00233FB0(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4))) = 0;
}
#else
void func_00230A10(s32 port, s32 slot) {
    D_0041F960[port][slot] = 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C88[];

s32 func_00233FD0(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}
#else
s32 func_00230A30(s32 port, s32 slot) {
    s32 iVar1 = D_0041F980[port][slot];
    D_0041F980[port][slot] = 0;
    return iVar1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00425C88[];

void func_00233FF8(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4))) = 0;
}
#else
void func_00230A58(s32 port, s32 slot) {
    D_0041F980[port][slot] = 0;
}
#endif

#ifdef VERSION_FM
typedef struct { s32 type; s32 serial; s32 arg[6]; } Ent2340;
extern Ent2340 D_Ent2340[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FC0;

s32 func_00234018(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 1;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230A78);
#endif

#ifdef VERSION_FM
s32 func_00234098(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 2;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230AF8);
#endif

#ifdef VERSION_FM
s32 func_00234148(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 3;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230BA8);
#endif

#ifdef VERSION_FM
s32 func_00234210(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 4;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230C70);
#endif

#ifdef VERSION_FM
s32 func_00234290(s32 a0, s32 a1, s32 a2) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 5;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230CF0);
#endif

#ifdef VERSION_FM
s32 func_00234310(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 6;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230D70);
#endif

#ifdef VERSION_FM
s32 func_002343A8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 7;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230E08);
#endif

#ifdef VERSION_FM
s32 func_00234440(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 8;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230EA0);
#endif

#ifdef VERSION_FM
s32 func_00234508(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 9;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00230F68);
#endif

#ifdef VERSION_FM
s32 func_002345A0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 10;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00231000);
#endif

#ifdef VERSION_FM
s32 func_00234668(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 11;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_Ent2340[D_00647FB8].arg[5] = a5;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_002310C8);
#endif

#ifdef VERSION_FM
s32 func_00234730(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 s;
    D_Ent2340[D_00647FB8].type = 9;
    D_Ent2340[D_00647FB8].serial = D_00647FC0;
    D_Ent2340[D_00647FB8].arg[0] = a0;
    D_Ent2340[D_00647FB8].arg[1] = a1;
    D_Ent2340[D_00647FB8].arg[2] = a2;
    D_Ent2340[D_00647FB8].arg[3] = a3;
    D_Ent2340[D_00647FB8].arg[4] = a4;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00231190);
#endif

#ifdef VERSION_FM
typedef struct { s32 type; s32 serial; s32 arg[6]; } Ent2347;
extern Ent2347 D_Ent2347[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FC0;
s32 func_002347E0(s32 a0) {
    s32 s;
    D_Ent2347[D_00647FB8].type = 0xD;
    D_Ent2347[D_00647FB8].serial = D_00647FC0;
    D_Ent2347[D_00647FB8].arg[0] = a0;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/memcard", func_00231240);
#endif

#ifdef VERSION_FM
extern s32 D_00647FEC;

s32 func_00234840(void) {
    return D_00647FEC;
}
#else
s32 func_002312A0(void) {
    return memcardStatus[1];
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FF0;

s32 func_00234850(void) {
    return D_00647FF0;
}
#else
s32 memcard_GetAllStatus(void) {
    return memcardStatus[2];
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FF4;

s32 func_00234860(void) {
    return D_00647FF4;
}
#else
s32 memcard_GetDirStatus(void) {
    return memcardStatus[3];
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FF8;

s32 func_00234870(void) {
    return D_00647FF8;
}
#else
s32 memcard_GetFormatStatus(void) {
    return memcardStatus[4];
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FFC;

s32 func_00234880(void) {
    return D_00647FFC;
}
#else
s32 memcard_GetUnformatStatus(void) {
    return memcardStatus[5];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648000;

s32 func_00234890(void) {
    return D_00648000;
}
#else
s32 memcard_GetChdirStatus(void) {
    return memcardStatus[6];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648004;

s32 func_002348A0(void) {
    return D_00648004;
}
#else
s32 memcard_GetMkdirStatus(void) {
    return memcardStatus[7];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648008;

s32 func_002348B0(void) {
    return D_00648008;
}
#else
s32 memcard_GetCreateStatus(void) {
    return memcardStatus[8];
}
#endif

#ifdef VERSION_FM
extern s32 D_0064800C;

s32 func_002348C0(void) {
    return D_0064800C;
}
#else
s32 memcard_GetDeleteStatus(void) {
    return memcardStatus[9];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648010;

s32 func_002348D0(void) {
    return D_00648010;
}
#else
s32 memcard_GetReadStatus(void) {
    return memcardStatus[10];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648014;

s32 func_002348E0(void) {
    return D_00648014;
}
#else
s32 memcard_GetWriteStatus(void) {
    return memcardStatus[11];
}
#endif

#ifdef VERSION_FM
extern s32 D_00648018;

s32 func_002348F0(void) {
    return D_00648018;
}
#else
s32 memcard_GetRenameStatus(void) {
    return memcardStatus[12];
}
#endif

#ifdef VERSION_FM
extern s32 D_0064801C;

s32 func_00234900(void) {
    return D_0064801C;
}
#else
s32 func_00231360(void) {
    return memcardStatus[13];
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00234910);
#else
// todo: confusing struct?
INCLUDE_ASM("asm/nonmatchings/memcard", func_00231370);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00234F80);
#else
// void func_00231370(void) {
//     if (D_00641FC8 != D_00641FCC) {
//         switch (*(s32*)(D_006417C0 + D_00641FCC * 4)) {
//             case 1:
//                 memcardCurCmdIdx = 1;
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 2:
//                 memcardCurCmdIdx = 2;
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileBuf = *(sceMcTblGetDir**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardEntries = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 3:
//                 memcardCurCmdIdx = 3;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x1c);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardFileBuf = *(sceMcTblGetDir**)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardEntries = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 4:
//                 memcardCurCmdIdx = 4;
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FDC = 0;
//                 D_00641FE0 = 0;
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 5:
//                 memcardCurCmdIdx = 5;
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FDC = 0;
//                 D_00641FE0 = 0;
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 6:
//                 memcardCurCmdIdx = 6;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 7:
//                 memcardCurCmdIdx = 7;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 8:
//                 memcardCurCmdIdx = 8;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x1c);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardFileBuffer = *(void**)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardFileSize = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 4 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 9:
//                 memcardCurCmdIdx = 9;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 10:
//                 memcardCurCmdIdx = 10;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x1c);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardFileBuffer = *(void**)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardFileSize = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 4 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 11:
//                 memcardCurCmdIdx = 11;
//                 D_00642044 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0x1c);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardFileBuffer = *(void**)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 memcardFileSize = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 4 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 12:
//                 memcardCurCmdIdx = 12;
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 3);
//                 memcardLoopStep = 0;
//                 memcardPort = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 memcardSlot = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 0xc);
//                 memcardFileName = *(char**)(D_006417C0 + D_00641FCC * 4 + 2);
//                 memcardNewFileName = *(char**)((int)D_006417C0 + D_00641FCC * 0x20 + 0x14);
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//                 break;
//             case 13:
//                 memcardCurCmdIdx = 13;
//                 D_00641FD4 = *(s32*)((int)D_006417C0 + D_00641FCC * 0x20 + 4);
//                 D_00642044 = *(s32*)(D_006417C0 + D_00641FCC * 4 + 1);
//                 D_00641FCC = D_00641FCC + 1 & 0x3f;
//         }
//     } else {
//         if (D_006417B8 == 0) {
//             return;
//         }
//         if (D_00641FE8 != 0) {
//             D_00641FE8--;
//             return;
//         }
//         memcardCurCmdIdx = 1;
//         D_00642044 = 0;
//         memcardLoopStep = 0;
//         memcardPort = D_00641FEC;
//         memcardSlot = D_00641FF0;
//         D_00641FE8 = D_00641FE4;
//     }
// }

void memcard_GetInfo(void) {
    switch (memcardLoopStep) {
        case 0: // Examine the memory card status
            sceMcGetInfo(memcardPort, memcardSlot, &memcardType, &memcardFree, &memcardFormat);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetInfo to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the memory card status
            if (memcardType == sceMcTypePDA) {
                D_0041F920[memcardPort][memcardSlot] = 3;
            } else {
                switch (memcardResult) {
                    case sceMcResSucceed: // Same card has been used continuously
                        memcardStatus[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 0;
                        break;

                    case sceMcResChangedCard: // Card has since been changed to a formatted card
                        memcardStatus[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 1;
                        D_0041F940[memcardPort][memcardSlot] = 1;
                        D_0041F960[memcardPort][memcardSlot] = 1;
                        break;

                    case sceMcResNoFormat: // Card has since been changed to an unformatted card
                        memcardStatus[1] = 0;
                        D_0041F920[memcardPort][memcardSlot] = 2;
                        D_0041F940[memcardPort][memcardSlot] = 1;
                        D_0041F960[memcardPort][memcardSlot] = 1;
                        break;

                    default: // Card could not be accessed or detected
                        D_0041F920[memcardPort][memcardSlot] = 3;
                        if (memcardStatus[1] == 0) {
                            D_0041F940[memcardPort][memcardSlot] = 1;
                            D_0041F980[memcardPort][memcardSlot] = 1;
                        }
                        memcardStatus[1] = 1;
                        break;
                }
            }

            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char D_004913F8[];
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_00235228(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_004913F8, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF0 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF0 = 1;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF0 = 2;
        } else {
            D_00425CAC = -1;
            D_00647FF0 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}
#else
void memcard_GetAllFiles(void) {
    switch (memcardLoopStep) {
        case 0: // Get all files on the memory card
            sceMcGetDir(memcardPort, memcardSlot, "*", 0, memcardEntries, memcardFileBuf);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetDir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Result contains number of entries obtained, negative if it won't write to table
            if (memcardResult >= 0) {
                memcardEntries = memcardResult;
                memcardStatus[2] = 0;
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardEntries = -1;
                    memcardStatus[2] = 1;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardEntries = -1;
                    memcardStatus[2] = 2;
                } else {
                    memcardEntries = -1;
                    memcardStatus[2] = 3;
                }
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_002353A8(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_00648020, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF4 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF4 = 2;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF4 = 3;
        } else {
            D_00425CAC = -1;
            D_00647FF4 = 4;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}
#else
void memcard_GetDirFiles(void) {
    switch (memcardLoopStep) {
        case 0: // Get files in the specified directory
            sceMcGetDir(memcardPort, memcardSlot, memcardFileName, 0, memcardEntries, memcardFileBuf);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcGetDir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Result contains number of entries obtained, negative if it won't write to table
            if (memcardResult >= 0) {
                memcardEntries = memcardResult;
                memcardStatus[3] = 0;
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardEntries = -1;
                    memcardStatus[3] = 2;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardEntries = -1;
                    memcardStatus[3] = 3;
                } else {
                    memcardEntries = -1;
                    memcardStatus[3] = 4;
                }
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcFormat(int, int);
int sceMcSync(int, int *, int *);

void func_00235520(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcFormat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FF8 = 1;
        } else {
            D_00647FF8 = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}
#else
void memcard_Format(void) {
    switch (memcardLoopStep) {
        case 0: // Format the memory card
            sceMcFormat(memcardPort, memcardSlot);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcFormat to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the format
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    memcardLoopStep = 3;
                    break;
                }
                memcardStatus[4] = TRUE;
            } else {
                memcardStatus[4] = FALSE;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;

        case 3:
            if (D_00641FE0 != 0) {
                D_00641FE0--;
                break;
            }
            memcardLoopStep = 0;
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcUnformat(int, int);
int sceMcSync(int, int *, int *);

void func_00235688(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcUnformat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FFC = 1;
        } else {
            D_00647FFC = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}
#else
void memcard_Unformat(void) {
    switch (memcardLoopStep) {
        case 0: // Erase memory card formatting
            sceMcUnformat(memcardPort, memcardSlot);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcUnformat to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the unformat
            if (memcardResult != sceMcResSucceed) {
                if (D_00641FDC != 0) {
                    D_00641FDC--;
                    D_00641FE0 = 60;
                    memcardLoopStep = 3;
                    break;
                }
                memcardStatus[5] = TRUE;
            } else {
                memcardStatus[5] = FALSE;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
            break;

        case 3:
            if (D_00641FE0 != 0) {
                D_00641FE0--;
                break;
            }
            memcardLoopStep = 0;
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char D_00425CB0[];
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcChdir(int, int, const char *, char *);
int sceMcSync(int, int *, int *);

void func_002357F0(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcChdir(D_00425C10, D_00425C14, D_00648020, D_00425CB0);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        switch (D_00647FC8) {
        case 0:
            D_00648000 = 0;
            break;
        case -2:
            D_00648000 = 1;
            break;
        case -4:
            D_00648000 = 2;
            break;
        default:
            D_00648000 = 3;
            break;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}
#else
void memcard_Chdir(void) {
    switch (memcardLoopStep) {
        case 0: // Change the current working directory
            sceMcChdir(memcardPort, memcardSlot, memcardFileName, memcardDirStore);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcChdir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the chdir
            switch (memcardResult) {
                case sceMcResSucceed: // Directory was changed successfully
                    memcardStatus[6] = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardStatus[6] = 1;
                    break;
                case sceMcResNoEntry: // Specified directory does not exist
                    memcardStatus[6] = 2;
                    break;
                default: // Memory card could not be accessed or detected
                    memcardStatus[6] = 3;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00235950);
#else
void memcard_Mkdir(void) {
    switch (memcardLoopStep) {
        case 0: // Create a new directory
            sceMcMkdir(memcardPort, memcardSlot, memcardFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcMkdir to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the mkdir
            switch (memcardResult) {
                case sceMcResSucceed: // Directory was created successfully
                    memcardStatus[7] = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardStatus[7] = 1;
                    break;
                case sceMcResFullDevice: // Memory card is too full
                    memcardStatus[7] = 2;
                    break;
                case sceMcResNoEntry: // Specified directory already exists
                    memcardStatus[7] = 3;
                    break;
                default: // Memory card could not be accessed or detected
                    memcardStatus[7] = 4;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00235AB0);
#else
// todo: match without goto
INCLUDE_ASM("asm/nonmatchings/memcard", memcard_Create);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00235D70);
#else
// void memcard_Create(void) {
//     int iVar1;
//     s32 sVar2;

//     switch (memcardLoopStep) {
//         case 0: // Open the file
//             sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_CREAT | SCE_RDWR);
//             memcardLoopStep++;
//             break;

//         case 1: // Wait for sceMcOpen to finish
//             if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
//                 memcardLoopStep++;
//             }
//             break;

//         case 2: // Store the file handle
//             if (memcardResult > -1) {
//                 memcardLoopStep++;
//                 memcardFileHandle = memcardResult;
//                 return;
//             }
//             if (memcardResult == sceMcResNoFormat) {
//                 memcardStatus[8] = 1;
//             } else if (memcardResult == sceMcResFullDevice) {
//                 memcardStatus[8] = 2;
//             } else if (memcardResult == sceMcResNoEntry) {
//                 memcardStatus[8] = 3;
//             } else if (memcardResult == sceMcResDeniedPermit) {
//                 memcardStatus[8] = 4;
//             } else if (memcardResult == sceMcResUpLimitHandle) {
//                 memcardStatus[8] = 5;
//             } else {
//                 memcardStatus[8] = 7;
//             }
//             goto LAB_0023278c;

//         case 3: // Write to the file
//             sceMcWrite(memcardFileHandle, memcardFileBuffer, memcardFileSize);
//             memcardLoopStep++;
//             break;

//         case 4: // Wait for sceMcWrite to finish
//             if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
//                 memcardLoopStep++;
//             }
//             break;

//         case 5: // Check the result of the write
//             if (memcardResult >= 0) {
//                 if (memcardResult == memcardFileSize) {
//                     memcardStatus[8] = 0;
//                 } else {
//                     memcardStatus[8] = 6;
//                 }
//             } else {
//                 if (memcardResult == sceMcResNoFormat) {
//                     memcardStatus[8] = 1;
//                 } else if (memcardResult == sceMcResFullDevice) {
//                     memcardStatus[8] = 2;
//                 } else if (memcardResult == sceMcResNoEntry) {
//                     memcardStatus[8] = 5;
//                 } else if (memcardResult == sceMcResDeniedPermit) {
//                     memcardStatus[8] = 4;
//                 } else if (memcardResult == sceMcResFailReplace) {
//                     memcardStatus[8] = 6;
//                 } else {
//                     memcardStatus[8] = 7;
//                 }
//             }
//             memcardLoopStep++;
//             return;

//         case 6: // Close the file
//             sceMcClose(memcardFileHandle);
//             memcardLoopStep++;
//             break;

//         case 7: // Block until sceMcClose is finished
//             if (sceMcSync(1, NULL, &memcardResult) == sceMcExecRun) {
//                 return;
//             }
//         LAB_0023278c:
//             memcardCurCmdIdx = 0;
//             D_00641FE8 = D_00641FE4;
//             if (D_00642044 != NULL) {
//                 D_00642044(D_00641FD4);
//             }
//     }
// }

void memcard_Delete(void) {
    switch (memcardLoopStep) {
        case 0: // Delete the file or directory
            sceMcDelete(memcardPort, memcardSlot, memcardFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcDelete to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the delete
            switch (memcardResult) {
                case sceMcResSucceed: // File or directory was deleted successfully
                    memcardStatus[9] = 0;
                    break;
                case sceMcResNoFormat: // Memory card was unformatted
                    memcardStatus[9] = 1;
                    break;
                case sceMcResNoEntry: // Specified file or directory does not exist
                    memcardStatus[9] = 2;
                    break;
                case sceMcResDeniedPermit: // File or directory could not be deleted
                    memcardStatus[9] = 3;
                    break;
                case sceMcResNotEmpty: // Directory is not empty
                    memcardStatus[9] = 4;
                    break;
                default: // Memory card could not be accessed or detected
                    memcardStatus[9] = 5;
                    break;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00235EE8);
#else
// todo: match without goto
INCLUDE_ASM("asm/nonmatchings/memcard", memcard_Read);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/memcard", func_00236190);
#else
// void memcard_Read(void) {
//     switch (memcardLoopStep) {
//         case 0: // Open the file
//             sceMcOpen(memcardPort, memcardSlot, memcardFileName, SCE_RDONLY);
//             memcardLoopStep++;
//             return;

//         case 1: // Wait for sceMcOpen to finish
//             if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
//                 memcardLoopStep++;
//             }
//             return;

//         case 2: // Store the file handle
//             if (memcardResult > -1) {
//                 memcardLoopStep++;
//                 memcardFileHandle = memcardResult;
//                 return;
//             }
//             if (memcardResult == sceMcResNoFormat) {
//                 memcardStatus[10] = 1;
//             } else if (memcardResult == sceMcResFullDevice) {
//                 memcardStatus[10] = 2;
//             } else if (memcardResult == sceMcResNoEntry) {
//                 memcardStatus[10] = 3;
//             } else if (memcardResult == sceMcResDeniedPermit) {
//                 memcardStatus[10] = 4;
//             } else if (memcardResult == sceMcResUpLimitHandle) {
//                 memcardStatus[10] = 5;
//             } else {
//                 memcardStatus[10] = 7;
//             }
//             goto LAB_00232bac;

//         case 3: // Read from the file
//             sceMcRead(memcardFileHandle, memcardFileBuffer, memcardFileSize);
//             memcardLoopStep++;
//             return;

//         case 4: // Wait for sceMcRead to finish
//             if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
//                 memcardLoopStep++;
//             }
//             return;

//         case 5: // Check the result of the read
//             if (memcardResult >= sceMcResSucceed) {
//                 if (memcardResult == memcardFileSize) {
//                     memcardStatus[10] = 0;
//                 } else {
//                     memcardStatus[10] = 6;
//                 }
//             } else {
//                 if (memcardResult == sceMcResNoFormat) {
//                     memcardStatus[10] = 1;
//                 } else if (memcardResult == sceMcResFullDevice) {
//                     memcardStatus[10] = 6;
//                 } else if (memcardResult == sceMcResNoEntry) {
//                     memcardStatus[10] = 5;
//                 } else if (memcardResult == sceMcResDeniedPermit) {
//                     memcardStatus[10] = 4;
//                 } else {
//                     memcardStatus[10] = 7;
//                 }
//             }
//             memcardLoopStep++;
//             return;

//         case 6: // Close the file
//             sceMcClose(memcardFileHandle);
//             memcardLoopStep++;
//             return;

//         case 7: // Block until sceMcClose is finished
//             if (sceMcSync(1, NULL, &memcardResult) == sceMcExecRun) {
//                 return;
//             }
//         LAB_00232bac:
//             memcardCurCmdIdx = 0;
//             D_00641FE8 = D_00641FE4;
//             if (D_00642044 != NULL) {
//                 D_00642044(D_00641FD4);
//             }
//     }
// }

// todo: match without goto
void memcard_Write(void) {
    switch (memcardLoopStep) {
        case 0: // Open the file
            sceMcOpen(memcardPort, memcardSlot, memcardFileName, 2);
            memcardLoopStep++;
            return;

        case 1: // Wait for sceMcOpen to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 2: // Store the file handle
            if (memcardResult > -1) {
                memcardLoopStep++;
                memcardFileHandle = memcardResult;
                return;
            }
            if (memcardResult == sceMcResNoFormat) {
                memcardStatus[11] = 1;
            } else if (memcardResult == sceMcResFullDevice) {
                memcardStatus[11] = 2;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardStatus[11] = 3;
            } else if (memcardResult == sceMcResDeniedPermit) {
                memcardStatus[11] = 4;
            } else if (memcardResult == sceMcResUpLimitHandle) {
                memcardStatus[11] = 5;
            } else {
                memcardStatus[11] = 7;
            }
            goto LAB_00232bac;

        case 3: // Write to the file
            sceMcWrite(memcardFileHandle, memcardFileBuffer, memcardFileSize);
            memcardLoopStep++;
            return;

        case 4: // Wait for sceMcWrite to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            return;

        case 5: // Check the result of the write
            if (memcardResult >= 0) {
                if (memcardResult == memcardFileSize) {
                    memcardStatus[11] = 0;
                } else {
                    memcardStatus[11] = 6;
                }
            } else {
                if (memcardResult == sceMcResNoFormat) {
                    memcardStatus[11] = 1;
                } else if (memcardResult == sceMcResFullDevice) {
                    memcardStatus[11] = 2;
                } else if (memcardResult == sceMcResNoEntry) {
                    memcardStatus[11] = 5;
                } else if (memcardResult == sceMcResDeniedPermit) {
                    memcardStatus[11] = 4;
                } else if (memcardResult == sceMcResFailReplace) {
                    memcardStatus[11] = 6;
                } else {
                    memcardStatus[11] = 7;
                }
            }
            memcardLoopStep++;
            return;

        case 6: // Close the file
            sceMcClose(memcardFileHandle);
            memcardLoopStep++;
            return;

        case 7: // Block until sceMcClose is finished
            if (sceMcSync(1, NULL, &memcardResult) == 0) {
                return;
            }
        LAB_00232bac:
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char *D_00648024;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcRename(int, int, const char *, const char *);
int sceMcSync(int, int *, int *);

void func_00236450(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcRename(D_00425C10, D_00425C14, D_00648020, D_00648024);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r == 0) {
            D_00648018 = 0;
        } else if (r == -2) {
            D_00648018 = 1;
        } else if (r == -4) {
            D_00648018 = 2;
        } else {
            D_00648018 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}
#else
void memcard_Rename(void) {
    switch (memcardLoopStep) {
        case 0: // Rename the file
            sceMcRename(memcardPort, memcardSlot, memcardFileName, memcardNewFileName);
            memcardLoopStep++;
            break;

        case 1: // Wait for sceMcRename to finish
            if (sceMcSync(1, NULL, &memcardResult) != sceMcExecRun) {
                memcardLoopStep++;
            }
            break;

        case 2: // Check the result of the rename
            if (memcardResult == sceMcResSucceed) {
                memcardStatus[12] = 0;
            } else if (memcardResult == sceMcResNoFormat) {
                memcardStatus[12] = 1;
            } else if (memcardResult == sceMcResNoEntry) {
                memcardStatus[12] = 2;
            } else {
                memcardStatus[12] = 3;
            }
            memcardCurCmdIdx = 0;
            D_00641FE8 = D_00641FE4;
            if (D_00642044 != NULL) {
                D_00642044(D_00641FD4);
            }
    }
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB0_b __asm__("D_00647FB0");
extern s32 D_0064801C_b __asm__("D_0064801C");
extern s32 (*D_00648034)(s32);
extern s32 D_00647FC4;
void func_00236598(void) {
    D_00647FB0_b = 0;
    D_00647FD8 = D_00647FD4;
    D_0064801C_b = D_00648034(D_00647FC4);
}
#else
void func_00232FF8(void) {
    memcardCurCmdIdx = 0;
    D_00641FE8 = D_00641FE4;
    memcardStatus[13] = D_00642044(D_00641FD4);
}
#endif

#ifdef VERSION_FM
extern s32 D_00647FB0;
extern void (*D_00425BD0[])(void);
void func_002365E0(void) {
    D_00425BD0[D_00647FB0]();
}
#else
void memcard_RunCommand(void) {
    memcardCommands[memcardCurCmdIdx]();
}
#endif
