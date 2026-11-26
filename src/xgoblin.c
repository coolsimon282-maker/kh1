/**
 * System start-up and per-frame services: IOP module loading, the task lists, the controllers and GS packet helpers.
 *
 * A task list (XGoblin) is a pool of fixed-size entries plus a list sorted by priority; each entry holds a function
 * that TaskList_UpdateMatching calls every frame (return value bit 4: remove the task, bit 8: stop the walk). The
 * main list D_004DD188 is set up by TaskSystem_Initialize and run by TaskSystem_Update.
 */
#include "common.h"

#include "io.h"
#include "xlamp.h"

#include "libpc.h"
#include "libpad2.h"
#include "libvu0.h"

void PcService_Initialize();
void* TaskList_Add(UNK_TYPE* arg0, s32 arg1, s32 (*func)(void));
void func_00121AE8();
void func_0012FB18();
void func_00147870();

extern f32 D_002B8340[];
extern sceVu0FMATRIX D_002C1E60;
extern s32 D_002C1EA0;
extern s32 D_002C1EBC;
extern f32 D_002C1EC0;
extern u32 D_002C1EE0[30][2];
extern scePad2SocketParam D_002C1FD8;

extern UNK_TYPE D_004DD188;
extern UNK_TYPE D_004DD198[];
extern u_long128 D_004DDA00;
extern s32 D_004DDC00;

// Loads several modules
extern _VX D_002C1EB8;
extern s32 D_002C5960;
extern s32 D_002C1EC8;
extern char D_0048D1C0[];
extern char D_0048D1D0[];
extern char D_0048D1E0[];
extern char D_0048D1F0[];
extern char D_0048D200[];
extern char D_0048D210[];
extern char D_0048D220[];
extern char D_0048D230[];
void func_00120B10(void);
void func_001209D8(char*);
void Pad_Initialize(void);
void func_0024D4B0(void);
void func_00120BA0(void);
void func_00122410(void);
void func_001220E8(void);

// Loads the IOP modules (sio2man.irx, ..., ds2o.irx twice, ..., libssl.irx) and starts the services that use them.
void Iop_LoadModules(void) {
    s32 i;

    D_002C5960 = 0;
    D_002C1EB8.s32 = 0;
    func_00120B10();
    func_001209D8(D_0048D1C0);
    func_001209D8(D_0048D1D0);
    func_001209D8(D_0048D1E0);
    for (i = 0; i < 2; i++) {
        func_001209D8(D_0048D1F0);
    }
    Pad_Initialize();
    func_001209D8(D_0048D200);
    func_001209D8(D_0048D210);
    func_001209D8(D_0048D220);
    func_001209D8(D_0048D230);
    func_0024D4B0();
    func_00120BA0();
    func_00122410();
    func_001220E8();
    D_002C1EC8 = 0;
}

// Task callback (priority 150000, added by TaskSystem_Initialize): calls func_00122250 every frame.
s32 func_0011EBC8(void) {
    func_00122250();
    return 0;
}

// Clears the system matrices and flags, sets up the main task list and starts the per-frame services.
void TaskSystem_Initialize(void) {
    s32 i, j;

    sceVu0UnitMatrix(D_002C1E20);

    for (i = 0; i < ARRAY_COUNT(D_002C1E60); i++) {
        for (j = 0; j < ARRAY_COUNT(D_002C1E60[0]); j++) {
            D_002C1E60[i][j] = 0;
        }
    }
    D_002C1EA0 = 0;
    D_002C1EA8 = 0;
    D_002C1EBC = 0;
    TaskList_Init(&D_004DD188, D_004DD198, 0x10, 0x80);
    func_00122110();
    func_00121AE8();
    func_00122410();
    func_001208B8();
    func_00147870();
    PcService_Initialize();
    func_0012FB18();
    ((XGoblin*)TaskSystem_AddTask(150000, func_0011EBC8))->unk_02 = -1;
}

// Runs one frame of the main task list (tasks whose flags match D_002C1EBC).
void TaskSystem_Update(void) {
    D_002C1EC0 = 1.0f / D_002B8340[1];
    TaskList_UpdateMatching(&D_004DD188, D_002C1EBC);
    D_002C1EA0 ^= 1;
}

// Adds a task with priority prio and function func to the main task list.
void* TaskSystem_AddTask(s32 arg0, s32 (*func)(void)) {
    return TaskList_Add(&D_004DD188, arg0, func);
}

// Looks a task up by its function in the main task list (the result is not used).
void TaskSystem_FindTask(s32 arg0) {
    TaskList_FindByFunc(&D_004DD188, arg0);
}

// Unlinks the main-list task that runs function func, if there is one.
s32 TaskSystem_RemoveTask(s32 arg0) {
    s32 val = TaskList_FindByFunc(&D_004DD188, arg0);
    if (val != 0) {
        return TaskList_Unlink(&D_004DD188, val);
    }
}

// Sets up a task list over a pool of count entries of size bytes each, all free.
void TaskList_Init(s32* arg0, s32* arg1, s32 arg2, s32 arg3) {
    XGoblin* g = (XGoblin*)arg0;
    s32 i;

    g->unk_00 = arg2;
    g->unk_02 = arg3;
    g->unk_04 = (s32)arg1;
    g->unk_08 = NULL;
    g->unk_0C = NULL;
    for (i = 0; i < arg3; i++) {
        ((XGoblin*)arg1)->unk_00 = 0;
        ((XGoblin*)arg1)->unk_02 = 0;
        arg1 = (s32*)((u8*)arg1 + arg2);
    }
}

// Finds a free entry (unk_00 == 0) in the pool, searching on from the last one handed out (unk_0C).
XGoblin* TaskList_FindFree(XGoblin* g) {
    u8* p = (u8*)g->unk_0C;
    u8* base;
    u8* end;
    s32 i;

    if (p == NULL) {
        p = (u8*)g->unk_04;
    }
    base = (u8*)g->unk_04;
    end = base + g->unk_00 * g->unk_02;
    for (i = 0; i < g->unk_02; i++) {
        p += g->unk_00;
        if (p >= end) {
            p = base;
        }
        if (((XGoblin*)p)->unk_00 == 0) {
            return (XGoblin*)p;
        }
    }
    return NULL;
}

// Returns the entry before arg1 in the list (NULL if arg1 is the first).
XGoblin* TaskList_FindPrevious(XGoblin* arg0, XGoblin* arg1) {
    XGoblin* pXVar;
    XGoblin* pXVar2 = NULL;

    for (pXVar = arg0->unk_08; pXVar != NULL && pXVar != arg1; pXVar = pXVar->unk_08) {
        pXVar2 = pXVar;
    }

    return pXVar2;
}

/* Union access = alias set 0: the target loads the list head only after the stores to the new entry, as
   if built with -fno-strict-aliasing. */
typedef union {
    XGoblin g;
} XGoblinAny;

// Takes a free entry, fills it in and links it into the list sorted by priority (unk_04).
void* TaskList_Add(UNK_TYPE* arg0, s32 arg1, s32 (*func)(void)) {
    XGoblin* g = (XGoblin*)arg0;
    XGoblin* n = TaskList_FindFree(g);
    XGoblin* prev;
    XGoblin* cur;

    if (n != NULL) {
        n->unk_0C = (void*)func;
        n->unk_00 = 0x11;
        n->unk_04 = arg1;
        n->unk_02 = 0;
        prev = NULL;
        for (cur = ((XGoblinAny*)g)->g.unk_08; cur != NULL && arg1 >= cur->unk_04; cur = cur->unk_08) {
            prev = cur;
        }
        if (prev != NULL) {
            prev->unk_08 = n;
        } else {
            g->unk_08 = n;
        }
        n->unk_08 = cur;
    }
    g->unk_0C = (void*)n;
    return n;
}

#ifdef VERSION_FM
void func_0015F010(void);

// Calls every task whose flags contain arg1; unlinks those that return bit 4, stops at one that returns bit 8.
s32 TaskList_UpdateMatching(XGoblin* arg0, s32 arg1) {
    u32 uVar3;

    s32 sVar5 = 0;
    XGoblin* pXVar2 = NULL;
    XGoblin* next = arg0->unk_08;

    while (next != 0) {
        if ((next->unk_02 & arg1) == arg1) {
            uVar3 = next->unk_0C(next);
            func_0015F010();
            next->unk_00 &= 0xFFEF;

            if (uVar3 & 4) {
                if (pXVar2 != 0) {
                    if (pXVar2->unk_08 != next) {
                        pXVar2 = TaskList_FindPrevious(arg0, next);
                    }
                    pXVar2->unk_08 = next->unk_08;
                } else {
                    arg0->unk_08 = next->unk_08;
                }
                next->unk_00 = 0;
            } else {
                pXVar2 = next;
            }

            sVar5++;

            if (uVar3 & 8) {
                break;
            }
        }
        next = next->unk_08;
    }

    arg0->unk_0C = NULL;
    return sVar5;
}
#else
s32 TaskList_UpdateMatching(XGoblin* arg0, s32 arg1) {
    u32 uVar3;

    s32 sVar5 = 0;
    XGoblin* pXVar2 = NULL;
    XGoblin* next = arg0->unk_08;

    while (next != 0) {
        if ((next->unk_02 & arg1) == arg1) {
            uVar3 = next->unk_0C(next);
            next->unk_00 &= 0xFFEF;

            if (uVar3 & 4) {
                if (pXVar2 != 0) {
                    if (pXVar2->unk_08 != next) {
                        pXVar2 = TaskList_FindPrevious(arg0, next);
                    }
                    pXVar2->unk_08 = next->unk_08;
                } else {
                    arg0->unk_08 = next->unk_08;
                }
                next->unk_00 = 0;
            } else {
                pXVar2 = next;
            }

            sVar5++;

            if (uVar3 & 8) {
                pXVar2 = next;
                break;
            }
        }
        next = next->unk_08;
    }

    arg0->unk_0C = NULL;
    return sVar5;
}
#endif

// Unlinks every task for which the callback (or the task's own flags) has bit 4 set.
s32 TaskList_RemoveIf(XGoblin* arg0, u16 (*arg1)(XGoblin*)) {
    XGoblin* next;
    XGoblin* gob;

    s32 iVar1 = 0;

    for (next = arg0->unk_08; next != NULL; next = next->unk_08) {
        if (((next->unk_00 | arg1(next)) & 4) != 0) {
            gob = TaskList_FindPrevious(arg0, next);
            if (gob != NULL) {
                gob->unk_08 = next->unk_08;
            } else {
                arg0->unk_08 = next->unk_08;
            }
            next->unk_00 = 0;
        }
        iVar1++;
    }

    return iVar1;
}

// Returns whether a file load request is still in use (bit 0).
b32 FileLoadTask_IsActive(XOtherCrown* arg0) {
    return arg0->unk_00 & 1;
}

// Returns the task in the list whose function is arg1 (0 if none).
s32 TaskList_FindByFunc(XGoblin* arg0, s32 arg1) {
    XGoblin* p;

    for (p = arg0->unk_08; p != NULL; p = p->unk_08) {
        if ((s32)p->unk_0C == arg1) {
            return (s32)p;
        }
    }
    return 0;
}

// Unlinks task arg1 from the list; returns 1 if it was there.
s32 TaskList_Unlink(XGoblin* arg0, s32 arg1) {
    XGoblin* prev = NULL;
    XGoblin* p;

    for (p = arg0->unk_08; p != NULL; p = p->unk_08) {
        if ((s32)p == arg1) {
            if (prev != NULL) {
                prev->unk_08 = p->unk_08;
            } else {
                arg0->unk_08 = p->unk_08;
            }
            p->unk_08 = NULL;
            return 1;
        }
        prev = p;
    }
    return 0;
}

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[0x1C];
    /* 0x30 */ sceVu0FVECTOR unk_30[2];
    /* 0x50 */ sceVu0FVECTOR unk_50[2];
} XGoblinPadState; /* size = 0x70 */

extern f32 D_002C5C20;

extern f32 D_002C5980[4];
f32 func_00120A38(f32*);

// Reads both analog sticks with a dead zone (D_002C5C20): direction bits for the d-pad, unit and scaled vectors.
s32 Pad_ReadSticks(XGoblinPadState* out, u8* data) {
    s32 bits = 0;
    s32 i;
    s32 j;
    f32 f;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            D_002C5980[j] = data[i * 2 + j + 2] - 127.5f;
            if (D_002C5980[j] > 0.0f) {
                D_002C5980[j] -= D_002C5C20;
                if (D_002C5980[j] < 0.0f) {
                    D_002C5980[j] = 0.0f;
                } else {
                    bits |= ((j * 5) ^ 1) << (21 + i * 8 - j);
                }
            } else {
                D_002C5980[j] += D_002C5C20;
                if (D_002C5980[j] > 0.0f) {
                    D_002C5980[j] = 0.0f;
                } else {
                    bits |= ((j * 5) ^ 4) << (21 + i * 8 - j);
                }
            }
            D_002C5980[j] /= 127.5f - D_002C5C20;
        }
        f = func_00120A38(D_002C5980);
        if (f > 1.0f) {
            f = 1.0f;
        }
        sceVu0Normalize(out->unk_50[i], D_002C5980);
        out->unk_50[i][3] = 1.0f;
        sceVu0ScaleVector(out->unk_30[i], out->unk_50[i], f);
    }
    return bits;
}

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} XGoblinButtons;

extern s32 D_002C5C24;
extern s32 D_002C5C28;
extern f32 D_002B8344;

// Updates held/pressed/released buttons and the key-repeat timers (first delay D_002C5C24, then D_002C5C28).
void Pad_UpdateButtons(XGoblinButtons* p, s32 b) {
    s32 old = p->unk_04;
    s32 x;
    s32 trg;
    s32 d;

    p->unk_14 = 0;
    p->unk_10 = 0;
    p->unk_0C = 0;
    p->unk_08 = 0;
    p->unk_04 = b;
    if (p->unk_00 != 0) {
        x = old ^ b;
        trg = x & b;
        p->unk_0C = x & ~b;
        p->unk_08 = trg;
        if (trg != 0) {
            d = D_002C5C24;
            p->unk_20 = d;
            p->unk_1C = d;
            p->unk_14 = trg;
            p->unk_10 = trg;
            return;
        }
        if (b != 0) {
            p->unk_1C = p->unk_1C - D_002B8344;
            p->unk_20 = p->unk_20 - D_002B8344;
            if (p->unk_1C <= 0.0f) {
                p->unk_1C = D_002C5C28;
                p->unk_10 = b;
            }
            if (p->unk_20 <= 0.0f) {
                p->unk_14 = b;
                p->unk_20 = 0;
            }
        }
    }
}

// Maps raw button bits to game buttons through the table D_002C1EE0.
u32 Pad_MapButtons(u32 arg0) {
    u32 i;
    u32 uVar3 = 0;

    for (i = 0; i < ARRAY_COUNT(D_002C1EE0); i++) {
        if ((arg0 & D_002C1EE0[i][0]) == D_002C1EE0[i][0]) {
            uVar3 |= D_002C1EE0[i][1];
        }
    }

    return uVar3;
}

#include "libvib.h"

extern XGoblinPadState D_002C5AD0[2];
extern XGoblinPadState D_002C5BB0;
extern sceVu0FVECTOR D_002C58B0;
extern s32 D_004E4280;
extern s32 D_004E44F0;
extern s32 D_004E44C0;
extern u8 D_004E44C8[][20];
extern s16 D_002C597A;
extern u8 D_002C5A80[];
s32 func_00218C08(void);
void func_0011FEC0(void);

// Reads the controller (scePad2), sets vibration, updates the button state and the game's mapped copy.
void Pad_Update(void) {
    u8 buf[0x100];
    u32 vib;
    u32 hi;
    s32 i;
    XGoblinPadState* e;
    s32* sock;
    s32 conn;
    s32 btn;

    if ((D_002C1EB8.u8 >> 3) & 3) {
        return;
    }
    D_002C1EB8.u8 &= 0xFE;
    for (i = 0; i < 1; i++) {
        e = &D_002C5AD0[i ^ D_004E4280];
        D_002C5AD0[0].unk_04 += 0;
        sock = &D_004E44C0 + i;

        conn = 0;
        btn = 0;
        while (scePad2GetState(*sock) == 1) {
            if (e->unk_00 == 0 && scePad2GetButtonProfile(*sock, D_004E44C8[i]) < 0) {
                goto next;
            }
            if (scePad2Read(*sock, buf) < 0) {
                goto next;
            }
            btn = (buf[0] | buf[1] << 8) ^ 0xFFFF;
            if ((D_004E44C8[i][2] & 0xF) == 0xF) {
                btn |= Pad_ReadSticks(e, buf);
            }
            if (func_00218C08() == 0 && !(D_002C597A & 1)) {
                hi = e->unk_03 << 1;
                vib = ((u32)(s8)e->unk_02 >> 31) | hi;
                sceVibSetActParam(*sock, 1, D_002C5A80, 2, (u8*)&vib);
            }
            e->unk_03 = 0;
            conn = 1;
            e->unk_02 = 0;
            break;
        }
    next:
        Pad_UpdateButtons((XGoblinButtons*)e, btn);
        e->unk_00 = conn;
    }
    if (D_002C5AD0[D_004E4280].unk_00 != 1) {
        if (D_004E44F0 >= 31) {
            D_002C1EB8.u8 |= 1;
        } else {
            D_004E44F0++;
        }
    } else {
        D_004E44F0 = 0;
    }
    if (((u32)D_002C5960 >> 2) & 1) {

        D_002C5BB0.unk_00 = 0;
        sceVu0CopyVector(D_002C5BB0.unk_30[0], D_002C58B0);
        sceVu0CopyVector(D_002C5BB0.unk_30[1], D_002C58B0);
        sceVu0CopyVector(D_002C5BB0.unk_50[0], D_002C58B0);
        sceVu0CopyVector(D_002C5BB0.unk_50[1], D_002C58B0);
        Pad_UpdateButtons((XGoblinButtons*)&D_002C5BB0, 0);
    } else {
        sceVu0CopyVector(D_002C5BB0.unk_30[0], D_002C5AD0[0].unk_30[0]);
        sceVu0CopyVector(D_002C5BB0.unk_30[1], D_002C5AD0[0].unk_30[1]);
        sceVu0CopyVector(D_002C5BB0.unk_50[0], D_002C5AD0[0].unk_50[0]);
        sceVu0CopyVector(D_002C5BB0.unk_50[1], D_002C5AD0[0].unk_50[1]);
        Pad_UpdateButtons((XGoblinButtons*)&D_002C5BB0, Pad_MapButtons(D_002C5AD0[0].unk_04));
        D_002C5BB0.unk_00 = 1;
    }
    func_0011FEC0();
}

extern s32 D_002C5C2C;
extern XGoblinPadState D_002C5AD0[2];
extern XGoblinPadState D_002C5BB0;
extern sceVu0FVECTOR D_002C58B0;
extern s32 D_004E4280;
extern s32 D_004E44F0;

// Resets the controller state and the dead zone / key-repeat settings.
void Pad_Reset(void) {
    s32 i;
    s32 j;
    XGoblinPadState* e;

    D_002C5C20 = 60.0f;
    D_002C5C24 = 30;
    D_002C5C28 = 4;
    D_002C5C2C = 32;
    for (i = 0; i < 2; i++) {
        e = &D_002C5AD0[i];
        e->unk_10 = 0;
        e->unk_08 = 0;
        e->unk_04 = 0;
        e->unk_00 = 0;
        e->unk_03 = 0;
        e->unk_02 = 0;
        for (j = 0; j < 2; j++) {
            sceVu0CopyVector(e->unk_30[j], D_002C58B0);
            sceVu0CopyVector(e->unk_50[j], D_002C58B0);
        }
    }
    D_002C5BB0.unk_10 = 0;
    D_002C5BB0.unk_08 = 0;
    D_002C5BB0.unk_04 = 0;
    D_004E4280 = 0;
    D_004E44F0 = 0;
}

#ifdef VERSION_FM
extern scePad2SocketParam D_002C5A88;
extern u_long128 D_004E42C0;
extern s32 D_004E44C0;

// Initialises the controller library (sceDbcInit, scePad2Init) and opens the pad socket.
void Pad_Initialize(void) {
    s32* socket = &D_004E44C0;

    sceDbcInit();
    scePad2Init(0);
    *socket = scePad2CreateSocket(&D_002C5A88, &D_004E42C0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xgoblin", Pad_Initialize);
#endif
// void Pad_Initialize(void) {
//     sceDbcInit();
//     scePad2Init(0);
//     D_004DDC00 = scePad2CreateSocket(&D_002C1FD8, &D_004DDA00);
// }

// Starts the performance counters (scePcStart).
s32 PcService_Start(void) {
    scePcStart(0x8000F8DE, 0, 0); // TODO: libpc bitfield macro combination
    return 0;
}

// Starts the performance counters and adds a task (priority 10000) that restarts them every frame.
void PcService_Initialize(void) {
    PcService_Start();
    ((XGoblin*)TaskSystem_AddTask(10000, PcService_Start))->unk_02 = -1;
}

// Writes one A+D pair (value arg1, register arg0) and returns the next position.
u64* GsPacket_AddReg(u64 arg0, u64 arg1, u64* arg2) {
    arg2[0] = arg1;
    arg2[1] = arg0;
    return arg2 + 2;
}

// Writes a GIF tag for the A+D data up to arg2 (one register, A+D; arg1 = EOP).
void GsPacket_SetGifTag(u_long128* arg0, s32 arg1, u_long128* arg2) {
    ((u64*)arg0)[0] = (u64)(arg2 - arg0 - 1) | ((u64)arg1 << 15) | ((u64)0 << 46) | ((u64)0 << 47) |
                      ((u64)0 << 58) | ((u64)1 << 60);
    ((u64*)arg0)[1] = 0xE;
}

// Writes a DMA tag (QWC up to arg2, ID arg1; scratchpad address bit for 0x70000000+).
void GsPacket_SetDmaTag(u_long128* arg0, s32 arg1, u_long128* arg2) {
    u64 tag = (u64)(arg2 - arg0 - 1) | ((u64)arg1 << 28);

    if ((u32)arg2 >= 0x70000000) {
        tag |= (u64)1 << 63;
    }
    *(u64*)arg0 = tag;
}

// Builds a DMA chain that uploads an image to GS memory (BITBLTBUF, TRXPOS, TRXREG, TRXDIR, then the data).
u_long128* GsPacket_LoadImage(s32 dbp, s32 dbw, s32 dpsm, s32 dsax, s32 dsay, s32 rrw, s32 rrh, s32 qwc, s32 src,
                         u_long128* pkt) {
    u_long128* dma = pkt;
    u_long128* gif = pkt + 1;
    u_long128* p = pkt + 2;

    p = (u_long128*)GsPacket_AddReg(0x50, (u64)dbp << 32 | (u64)dbw << 48 | (u64)dpsm << 56, (u64*)p);
    p = (u_long128*)GsPacket_AddReg(0x51, (u64)dsax << 32 | (u64)dsay << 48, (u64*)p);
    p = (u_long128*)GsPacket_AddReg(0x52, (u64)rrw | (u64)rrh << 32, (u64*)p);
    p = (u_long128*)GsPacket_AddReg(0x53, 0, (u64*)p);
    GsPacket_SetGifTag(gif, 0, p);
    gif = p++;
    *(u64*)gif = (u64)(u32)qwc | (2ULL << 58);
    GsPacket_SetDmaTag(dma, 1, p);
    dma = p++;
    *(u64*)dma = (u64)(u32)(qwc | 0x30000000) | (u64)src << 32;
    dma = p++;
    gif = p++;
    p = (u_long128*)GsPacket_AddReg(0x3F, 0, (u64*)p);
    GsPacket_SetGifTag(gif, 1, p);
    GsPacket_SetDmaTag(dma, 7, p);
    return dma;
}
