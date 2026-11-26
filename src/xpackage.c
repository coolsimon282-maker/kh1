/**
 * More UI part helpers (ttlib/ui.c, see xmonitor.c), then library code with assert file names "src/decode.c" (typed
 * chunks: type byte, 32-bit size, data, with a handler table) and "src/sa_task.c" (eight task groups,
 * TASK_GRUPE_MAX, each with its own context set around func_0024AB00 / func_0024E1D0 calls).
 */
#include "common.h"
#include "xtango.h"

XWhiskey* D_00663A28[8];

#ifdef VERSION_FM
// FM's code reads this table at 0x669A18 (FM's linker puts the definition above somewhere else).
extern XWhiskey* D_00669A18[8];
#define XPACKAGE_TABLE D_00669A18
#else
#define XPACKAGE_TABLE D_00663A28
#endif

// Clears words +0x10 / +0x14 of arg0 consecutive 0x20-byte entries.
void func_00247778(s32 arg0, XWhiskey* arg1) {
    if (arg0 > 0) {
        while (arg0 != 0) {
            arg0 += -1;
            arg1->unk_10 = 0;
            arg1->unk_14 = 0;
            arg1 = &arg1->unk_20;
        };
    }
}

typedef struct {
    /* 0x00 */ s32 unk_00[4];
    /* 0x10 */ u8 unk_10[0x50];
    /* 0x60 */ u64 unk_60;
} XPackageUnk77A8;

void UiPart_GetRect(XPackageUnk77A8* arg0, s32* arg1);

// The part's rectangle: from its rectangle track when that runs (flags 0x14), else its own +0x00.
void UiPart_GetCurrentRect(XPackageUnk77A8* arg0, s32* arg1) {
    if ((arg0->unk_60 & 0x14) == 0x14) {
        UiPart_GetRect(arg0, arg1);
        return;
    }
    arg1[0] = arg0->unk_00[0];
    arg1[1] = arg0->unk_00[1];
    arg1[2] = arg0->unk_00[2];
    arg1[3] = arg0->unk_00[3];
}

typedef struct {
    /* 0x00 */ s32 unk_00[4];
    /* 0x10 */ u8 unk_10[0x10];
    /* 0x20 */ s32 unk_20[4][4];
    /* 0x60 */ u64 unk_60;
} XPackageUnk7808;

void UiPart_GetColor(XPackageUnk7808*, void*);
void UiPart_GetGradient(XPackageUnk7808*, s32 (*)[4]);

// gets an object's matrix: built by one of two helpers depending on the flags, its own, or its first row repeated
void UiPart_GetCurrentColors(XPackageUnk7808* p, s32 (*m)[4]) {
    s32 i, j;
    s32 v[4];
    s32 t[4][4];
    if ((p->unk_60 & 0xA) == 0xA) {
        UiPart_GetColor(p, (void*)v);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                m[i][j] = v[j];
            }
        }
    } else if ((p->unk_60 & 0xC0) == 0xC0) {
        UiPart_GetGradient(p, t);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                m[i][j] = t[i][j];
            }
        }
    } else if (*(u32*)&p->unk_60 & 0x20) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                m[i][j] = p->unk_20[i][j];
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                m[i][j] = p->unk_20[0][j];
            }
        }
    }
}

NOTHROW(void, UiPart_RewindRectAnim);
NOTHROW(void, UiPart_StartRectAnim);
NOTHROW(void, UiPart_RewindColorAnim);
NOTHROW(void, UiPart_StartColorAnim);
NOTHROW(void, UiPart_RewindGradientAnim);
NOTHROW(void, UiPart_StartGradientAnim);
// Rewinds and starts each key track the part has (rectangle 4, colour 2, gradient 0x40).
void UiPart_StartAnims(u8* p) {
    if (*(u32*)(p + 0x60) & 4) {
        UiPart_RewindRectAnim(p);
        UiPart_StartRectAnim(p);
    }
    if (*(u32*)(p + 0x60) & 2) {
        UiPart_RewindColorAnim(p);
        UiPart_StartColorAnim(p);
    }
    if (*(u32*)(p + 0x60) & 0x40) {
        UiPart_RewindGradientAnim(p);
        UiPart_StartGradientAnim(p);
    }
}

NOTHROW(void, UiPart_StopRectAnim);
NOTHROW(void, UiPart_StopColorAnim);
NOTHROW(void, UiPart_StopGradientAnim);
// Stops each key track the part has.
void UiPart_StopAnims(u8* p) {
    if (*(u32*)(p + 0x60) & 4) {
        UiPart_StopRectAnim(p);
    }
    if (*(u32*)(p + 0x60) & 2) {
        UiPart_StopColorAnim(p);
    }
    if (*(u32*)(p + 0x60) & 0x40) {
        UiPart_StopGradientAnim(p);
    }
}

// Advances all three key tracks of the part by one frame.
void UiPart_StepAnims(s32 arg0) {
    UiPart_StepRectAnim(arg0, 1);
    UiPart_StepColorAnim(arg0, 1);
    UiPart_StepGradientAnim(arg0, 1);
}

typedef struct {
    /* 0x00 */ u64 unk_00[0x18];
} XPackageUnk7AE0Entry; // size = 0xC0, the same entries as XPackageUnk7B60Entry

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8; // offset of the entries from the start of this header
} XPackageUnk7AE0Hdr;

// arg0: list of entry indices ended by -1; each entry is copied to arg1[]
void UiFile_CopyParts(s32* arg0, XPackageUnk7AE0Entry* arg1, XPackageUnk7AE0Hdr* arg2) {
    XPackageUnk7AE0Entry* base = (XPackageUnk7AE0Entry*)((u8*)arg2 + arg2->unk_8);

    while (*arg0 != -1) {
        *arg1 = base[*arg0];
        arg0++;
        arg1++;
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0xC0];
} XPackageUnk7B60Entry; // size = 0xC0

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8; // offset of the entries from the start of this header
} XPackageUnk7B60Hdr;

// arg0: list of entry indices ended by -1; arg1 gets each entry's address
void UiFile_GetParts(s32* arg0, s32* arg1, XPackageUnk7B60Hdr* arg2) {
    XPackageUnk7B60Entry* base = (XPackageUnk7B60Entry*)((u8*)arg2 + arg2->unk_8);

    while (*arg0 != -1) {
        *arg1 = (s32)&base[*arg0];
        arg0++;
        arg1++;
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x20];
    /* 0x20 */ s32 unk_20[4][4];
} XPackageUnk7BA8;

// Sets all four corner colours of the part to colour arg1.
void UiPart_SetColor(XPackageUnk7BA8* arg0, s32* arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg0->unk_20[i][j] = arg1[j];
        }
    }
}

// four GS XYZ vertices (x, y, z, 0) of a rectangle, offset by (0x700, 0x740) pixels
typedef struct {
    /* 0x00 */ u8 unk_00[0xA0];
    /* 0xA0 */ s32 vtx[4][4];
} XPackageQuad;

// Fills four GS XYZ vertices of the rectangle (x, y, w, h), offset to the GS window (0x700, 0x740 pixels).
void Gs_SetQuadXYZ(XPackageQuad* q, s32 x, s32 y, s32 w, s32 h) {
    s32 x0 = (x << 4) + 0x7000;
    s32 y0 = (y << 4) + 0x7400;
    s32 y1 = ((y + h) << 4) + 0x7400;
    s32 x1 = ((x + w) << 4) + 0x7000;

    q->vtx[0][0] = x0;
    q->vtx[0][1] = y0;
    q->vtx[0][2] = -0x100;
    q->vtx[0][3] = 0;
    q->vtx[1][0] = x0;
    q->vtx[1][1] = y1;
    q->vtx[1][2] = -0x100;
    q->vtx[1][3] = 0;
    q->vtx[2][0] = x1;
    q->vtx[2][1] = y0;
    q->vtx[2][2] = -0x100;
    q->vtx[2][3] = 0;
    q->vtx[3][0] = x1;
    q->vtx[3][1] = y1;
    q->vtx[3][2] = -0x100;
    q->vtx[3][3] = 0;
}

// arg0: a type byte, a 32-bit little-endian size, then the data
s32 Decode_CopyChunk(u8* arg0, void* arg1, s32* arg2) {
    s32 size = arg0[1] + (arg0[2] << 8) + (arg0[3] << 16) + (arg0[4] << 24);

    memcpy(arg1, arg0 + 5, size);
    *arg2 = size;
    return size;
}

extern void (*D_00469FC8[])(u8* arg0, s32 arg1, s32* arg2);

// Runs the handler of the chunk's type (table D_00469FC8) on it; returns the size it produced.
s32 Decode_Chunk(s32 arg0, u8* arg1) {
    s32 ret;

    D_00469FC8[*arg1](arg1, arg0, &ret);
    return ret;
}

extern char D_00491878[]; // FM address names; probably the file name and message of an assert
extern char D_00491880[];

void Assert_Stub();

// Size field of a chunk of type 1 (asserts the type, src/decode.c).
s32 Decode_GetChunkSize(u8* arg0) {
    if (arg0[0] != 1) {
        Assert_Stub(D_00491878, D_00491880, 0x3F);
    }
    return arg0[1] + (arg0[2] << 8) + (arg0[3] << 16) + (arg0[4] << 24);
}

// Empty: the assert handler (called with expression, file, line), compiled out.
void Assert_Stub(void) {
}

// Clears the eight task group slots (sa_task.c, TASK_GRUPE_MAX).
void SaTask_ClearGroups(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        XPACKAGE_TABLE[i] = NULL;
    }
}

extern s32 D_0046A038;
extern s32 D_0046A03C;
extern s32 D_0046A040;
extern s32 D_0046A044;
extern s32 D_0046A048;

// Calls func_0024AB00(arg1, arg2, arg3) with task group idx's context (D_0046A03C..D_0046A048) set, restoring two of them after.
void SaTask_RunInGroup(s32 idx, s32 arg1, s32 arg2, s32 arg3) {
    XWhiskey* p = XPACKAGE_TABLE[idx];
    s32 old40, old48, new40, new48;

    old40 = D_0046A040;
    old48 = D_0046A048;
    D_0046A03C = p->unk_0C;
    new40 = p->unk_10;
    D_0046A044 = p->unk_14;
    new48 = p->unk_18;
    D_0046A040 = new40;
    D_0046A048 = new48;
    func_0024AB00(arg1, arg2, arg3);
    D_0046A040 = old40;
    D_0046A048 = old48;
}

// SaTask_RunInGroup for group 0.
void SaTask_RunInGroup0(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(0, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 1.
void SaTask_RunInGroup1(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(1, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 2.
void SaTask_RunInGroup2(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(2, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 3.
void SaTask_RunInGroup3(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(3, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 4.
void SaTask_RunInGroup4(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(4, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 5.
void SaTask_RunInGroup5(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(5, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 6.
void SaTask_RunInGroup6(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(6, arg0, arg1, arg2);
}

// SaTask_RunInGroup for group 7.
void SaTask_RunInGroup7(s32 arg0, s32 arg1, s32 arg2) {
    SaTask_RunInGroup(7, arg0, arg1, arg2);
}

void func_0024E1D0(void);

// Steps task group idx (func_0024E1D0) with its context set and counts its steps (+0x1C), unless a system message is up.
void SaTask_StepGroup(s32 idx) {
    s32 old40 = D_0046A040;
    s32 old48 = D_0046A048;
    XWhiskey* p;

    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        p = XPACKAGE_TABLE[idx];
        D_0046A038 = (s32)p;
        D_0046A03C = p->unk_0C;
        D_0046A040 = p->unk_10;
        D_0046A044 = p->unk_14;
        D_0046A048 = p->unk_18;
        p->munny++;
        func_0024E1D0();
        D_0046A040 = old40;
        D_0046A048 = old48;
    }
}

// SaTask_StepGroup for group 0.
void SaTask_StepGroup0(void) {
    SaTask_StepGroup(0);
}

// SaTask_StepGroup for group 1.
void SaTask_StepGroup1(void) {
    SaTask_StepGroup(1);
}

// SaTask_StepGroup for group 2.
void SaTask_StepGroup2(void) {
    SaTask_StepGroup(2);
}

// SaTask_StepGroup for group 3.
void SaTask_StepGroup3(void) {
    SaTask_StepGroup(3);
}

// SaTask_StepGroup for group 4.
void SaTask_StepGroup4(void) {
    SaTask_StepGroup(4);
}

// SaTask_StepGroup for group 5.
void SaTask_StepGroup5(void) {
    SaTask_StepGroup(5);
}

// SaTask_StepGroup for group 6.
void SaTask_StepGroup6(void) {
    SaTask_StepGroup(6);
}

// SaTask_StepGroup for group 7.
void SaTask_StepGroup7(void) {
    SaTask_StepGroup(7);
}

// Frees task group arg0 (when it owns its memory, +0x24) and clears its slot.
void SaTask_FreeGroup(s32 arg0) {
    if (*(s32*)((u8*)XPACKAGE_TABLE[arg0] + 0x24) != 0) {
        free(XPACKAGE_TABLE[arg0]);
    }
    XPACKAGE_TABLE[arg0] = NULL;
}

// SaTask_FreeGroup for group 0.
void SaTask_FreeGroup0(void) {
    SaTask_FreeGroup(0);
}

// SaTask_FreeGroup for group 1.
void SaTask_FreeGroup1(void) {
    SaTask_FreeGroup(1);
}

// SaTask_FreeGroup for group 2.
void SaTask_FreeGroup2(void) {
    SaTask_FreeGroup(2);
}

// SaTask_FreeGroup for group 3.
void SaTask_FreeGroup3(void) {
    SaTask_FreeGroup(3);
}

// SaTask_FreeGroup for group 4.
void SaTask_FreeGroup4(void) {
    SaTask_FreeGroup(4);
}

// SaTask_FreeGroup for group 5.
void SaTask_FreeGroup5(void) {
    SaTask_FreeGroup(5);
}

// SaTask_FreeGroup for group 6.
void SaTask_FreeGroup6(void) {
    SaTask_FreeGroup(6);
}

// SaTask_FreeGroup for group 7.
void SaTask_FreeGroup7(void) {
    SaTask_FreeGroup(7);
}

// SaTask_RunInGroup with a context passed in (arg0[3..6]).
void SaTask_RunWithContext(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 old40, old48, new40, new48;

    old40 = D_0046A040;
    old48 = D_0046A048;
    D_0046A03C = arg0[3];
    new40 = arg0[4];
    D_0046A044 = arg0[5];
    new48 = arg0[6];
    D_0046A040 = new40;
    D_0046A048 = new48;
    func_0024AB00(arg1, arg2, arg3);
    D_0046A040 = old40;
    D_0046A048 = old48;
}

// Calls func_0024AB00.
void func_00248300() {
    func_0024AB00();
}

// Memory a task group with arg0 tasks needs (arg0 * 0x10340 + 0x5E7, 64-byte aligned).
s32 SaTask_GetGroupSize(s32 arg0) {
    return ((arg0 << 5) + arg0 * 0x10320 + 0x5E7) & ~0x3F;
}

// Sets up a task group in the given memory in a free slot (asserts "i!=TASK_GRUPE_MAX").
INCLUDE_ASM("asm/nonmatchings/xpackage", SaTask_CreateGroup);

// SaTask_CreateGroup with memory from malloc(SaTask_GetGroupSize(arg0)), owned by the group.
void SaTask_AllocGroup(s32 arg0) {
    SaTask_CreateGroup(arg0, malloc(SaTask_GetGroupSize(arg0)), 1);
}

// SaTask_ClearGroups.
void SaTask_Init(void) {
    SaTask_ClearGroups();
}
