/**
 * Lights and vector interpolation tasks.
 *
 * lightTbl holds 31 lights of 0x40 bytes: type (1 = ambient colour multiplier, 2 = directional, 3 = point, 4 = spot,
 * 5 = ambient sphere), flags (0x10/0x11: ignored, 8: temporary), range, position, direction, colour. Objects keep a
 * mask of the lights that reach them (+0x420) and their ambient colour (+0x430). The interpolation tasks move a vector
 * to a target over a time and live on their own task list (interpTaskList, see xgoblin.c).
 */
#include "common.h"

extern sceVu0FVECTOR D_002C5C60;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x38];
} XOwlEnt;

extern XOwlEnt lightTbl[];

typedef struct {
    /* 0x00 */ char unk_0x00[0x10];
    /* 0x10 */ sceVu0FVECTOR* unk_10;
    /* 0x20 */ sceVu0FVECTOR unk_20;
    /* 0x30 */ sceVu0FVECTOR unk_30;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ void (*unk_48)(sceVu0FVECTOR*);
} XHoot;

extern f32 D_002B8340[];

s32 interpTaskList;
s32 D_004FA680;

// Interpolation task: moves the vector towards the target; at the end calls the callback and returns 4 (remove).
s32 VectorInterpolationTask_Update(XHoot* arg0) {
    s32 uVar1;
    f32 fVar2;
    f32 r;

    uVar1 = 0;
    fVar2 = arg0->unk_44 - D_002B8340[1];

    r = fVar2 / arg0->unk_40;
    arg0->unk_44 = fVar2;
    if (r < 0.0f) {
        r = 0.0f;
        if (arg0->unk_48 != NULL) {
            arg0->unk_48(arg0->unk_10);
        }
        uVar1 = 4;
    }
    sceVu0InterVector(arg0->unk_10[3], &arg0->unk_20, &arg0->unk_30, r);
    return uVar1;
}

// Moves vec[3] to target over time (at once if time <= 0), calling done when it gets there.
void Interpolation_StartVector(f32 arg0, sceVu0FVECTOR* arg1, f32* arg2, void (*arg3)()) {
    XHoot* pvVar1;

    if (0.0f >= arg0) {
        sceVu0CopyVector(arg1[3], arg2);
    } else {
        pvVar1 = TaskList_Add(&interpTaskList, 0, VectorInterpolationTask_Update);
        pvVar1->unk_10 = arg1;
        pvVar1->unk_44 = arg0;
        pvVar1->unk_40 = arg0;
        pvVar1->unk_48 = arg3;
        sceVu0CopyVector(pvVar1->unk_20, arg1[3]);
        sceVu0CopyVector(pvVar1->unk_30, arg2);
    }
}


typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 range;
    /* 0x10 */ sceVu0FVECTOR pos;
    /* 0x20 */ sceVu0FVECTOR dir;
    /* 0x30 */ sceVu0FVECTOR col;
} XOwlAmb;

extern sceVu0FVECTOR D_002C5C70;
f32 Vec_Length(sceVu0FVECTOR);

// Computes an object's ambient colour and the mask of directional/point/spot lights that reach it.
void Light_CalcAmbient(u8* ctx) {
    sceVu0FVECTOR v;
    f32* amb;
    XOwlAmb* e;
    s32 i;
    u32 mask;
    f32 d;

    amb = (f32*)(ctx + 0x430);
    mask = 0;
    sceVu0CopyVector(amb, D_002C5C70);
    e = (XOwlAmb*)lightTbl;
    for (i = 0; i < 31; i++, e++) {
        if (e->flags & 0x11) {
            continue;
        }
        switch (e->type) {
        case 1:
            sceVu0MulVector(amb, amb, e->col);
            break;
        case 2:
            mask |= 1 << i;
            break;
        case 3:
            mask |= 1 << i;
            break;
        case 4:
            mask |= 1 << i;
            break;
        case 5:
            sceVu0SubVector(v, (f32*)(ctx + 0x10), e->pos);
            d = Vec_Length(v);
            if (d < e->range) {
                sceVu0InterVector(v, e->col, D_002C5C70, cosf(d / e->range * 3.1415928f * 0.5f));
                sceVu0MulVector(amb, amb, v);
            }
            break;
        }
    }
    *(u32*)(ctx + 0x420) = mask;
}

// Takes a free light, sets its type, flags and unk_08 and a default colour; returns it (NULL if none is free).
XOwlEnt* Light_Add(s32 arg0, s32 arg1, s32 arg2) {
    XOwlEnt* p = lightTbl;
    s32 i;

    for (i = 0; i < 31; i++, p++) {
        if (p->unk_00 == 0) {
            p->unk_00 = arg0;
            p->unk_04 = arg1;
            *(s32*)((u8*)p + 8) = arg2;
            sceVu0CopyVector((f32*)((u8*)p + 0x30), D_002C5C60);
            return p;
        }
    }
    return NULL;
}

// Writes 0 to *arg0 (used to free a light: type 0).
void Interpolation_ClearValue(s32* arg0) {
    *arg0 = 0;
}

#ifdef VERSION_FM
typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 range;
    /* 0x10 */ sceVu0FVECTOR pos;
    /* 0x20 */ sceVu0FVECTOR dir;
    /* 0x30 */ sceVu0FVECTOR unk_30;
} XOwlLight;

typedef struct {
    /* 0x000 */ char unk_00[0x420];
    /* 0x420 */ u32 lightMask;
} XOwlLit;

extern sceVu0FMATRIX D_002C1E60;
void func_001223B0(sceVu0FVECTOR, sceVu0FVECTOR);

// Builds the light direction matrix for an object at pos from the lights in its mask (spot/point falloff included).
void Light_GetDirMatrix(XOwlLit* ctx, sceVu0FVECTOR pos, sceVu0FMATRIX m) {
    sceVu0FVECTOR v;
    XOwlLight* e;
    s32 i;
    s32 j;
    s32 k;
    f32 d;

    k = 0;
    sceVu0CopyMatrix(m, D_002C1E60);
    e = (XOwlLight*)lightTbl;
    for (i = 0; i < 31; i++, e++) {
        if (ctx->lightMask & (1 << i)) {
            switch (e->type) {
            case 2:
                for (j = 0; j < 3; j++) {
                    m[j][k] = -e->dir[j];
                }
                k++;
                break;
            case 3:
                sceVu0SubVector(v, e->pos, pos);
                func_001223B0(v, v);
                if (v[3] < e->range) {
                    sceVu0ScaleVector(v, v, cosf(v[3] / e->range * 3.1415928f * 0.5f));
                    for (j = 0; j < 3; j++) {
                        m[j][k] = v[j];
                    }
                }
                k++;
                break;
            case 4:
                sceVu0SubVector(v, e->pos, pos);
                func_001223B0(v, v);
                d = -sceVu0InnerProduct(e->dir, v);
                if (e->range < d) {
                    sceVu0ScaleVector(v, v, (d - e->range) / (1.0f - e->range));
                    for (j = 0; j < 3; j++) {
                        m[j][k] = v[j];
                    }
                }
                k++;
                break;
            }
        }
    }
    m[3][3] = 1.0f;
}

#else
INCLUDE_ASM("asm/nonmatchings/xowl", Light_GetDirMatrix);
#endif

extern sceVu0FMATRIX D_002C1E60;

// Builds the light colour matrix for an object from the lights in its mask, ambient colour in row 3.
void Light_GetColorMatrix(u8* obj, sceVu0FMATRIX m) {
    s32 k;
    XOwlEnt* e;
    s32 i;
    s32 j;

    sceVu0CopyMatrix(m, D_002C1E60);
    for (j = 3; j >= 0; j--) {
        m[3][j] = 1.0f;
    }
    e = lightTbl;
    k = 0;
    for (i = 0; i < 31; i++, e++) {
        if (*(u32*)(obj + 0x420) & (1 << i)) {
            switch (e->unk_00) {
                case 2:
                case 3:
                case 4:
                    sceVu0CopyVector(m[k++], (f32*)((u8*)e + 0x30));
                    break;
            }
        }
    }
    sceVu0CopyVector(m[3], (f32*)(obj + 0x430));
}

extern u32 D_002B85F8;
extern sceVu0FVECTOR D_002C6450;
void func_00107E10(XOwlEnt*);
void func_00110C70(sceVu0FVECTOR);
void TaskList_UpdateMatching(s32*, s32);

// Per-frame task: runs the interpolation tasks, recomputes the global ambient colour and handles type 3 lights.
s32 LightTask_Update(void) {
    XOwlEnt* e;
    s32 i;

    TaskList_UpdateMatching(&interpTaskList, 0);
    D_002C6450[3] = 1.0f;
    D_002C6450[2] = 1.0f;
    D_002C6450[1] = 1.0f;
    D_002C6450[0] = 1.0f;
    D_002B85F8 &= ~0x10;
    e = lightTbl;
    for (i = 30; i >= 0; i--, e++) {
        if (!(e->unk_04 & 0x12)) {
            if (e->unk_00 != 1) {
                if (e->unk_00 == 3) {
                    func_00107E10(e);
                    D_002B85F8 |= 0x10;
                }
            } else {
                sceVu0MulVector(D_002C6450, D_002C6450, (f32*)((u8*)e + 0x30));
            }
        }
    }
    D_002C6450[3] = 1.0f;
    func_00110C70(D_002C6450);
    return 0;
}


// Sets up the interpolation task list (8 entries of 0x50 bytes).
void Interpolation_Initialize(void) {
    TaskList_Init(&interpTaskList, &D_004FA680, 0x50, 8);
}

// Frees every temporary light (flag 8) and resets the interpolation tasks.
void Light_ClearTemporary(void) {
    XOwlEnt* p = lightTbl;
    s32 i;

    for (i = 30; i >= 0; i--) {
        if (p->unk_00 != 0 && (p->unk_04 & 8)) {
            Interpolation_ClearValue((s32*)p);
        }
        p++;
    }
    Interpolation_Initialize();
}

// Sets flag 0x10 (ignored) on every temporary light.
void Light_DisableTemporary(void) {
    XOwlEnt* p = lightTbl;
    s32 i;

    for (i = 30; i >= 0; i--) {
        if (p->unk_00 != 0 && (p->unk_04 & 8)) {
            p->unk_04 |= 0x10;
        }
        p++;
    }
}

// Clears flag 0x10 on every light.
void Light_EnableAll(void) {
    XOwlEnt* p = lightTbl;
    s32 i;

    for (i = 0; i < 31; i++, p++) {
        p->unk_04 &= ~0x10;
    }
}

typedef struct XOwlE2 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    char unk_0C[0x14];
    sceVu0FVECTOR unk_20;
    sceVu0FVECTOR unk_30;
} XOwlE2;
typedef union {
    XOwlE2* p;
    f32 f;
} XOwlU;
extern XOwlU D_002C6440;
s32 LightTask_Update(void);
s32 TaskSystem_FindTask(s32 (*)(void));

// Clears every light, adds the default directional light (0, 1, 0, white) and starts LightTask_Update.
void Light_Initialize(void) {
    s32 i;

    for (i = 0; i < 31; i++) {
        lightTbl[i].unk_00 = 0;
        lightTbl[i].unk_04 = 0;
    }
    D_002C6440.p = (void*)Light_Add(2, 7, 0);
    D_002C6440.p->unk_20[0] = 0.0f;
    D_002C6440.p->unk_20[1] = 1.0f;
    D_002C6440.p->unk_20[2] = 0.0f;
    D_002C6440.p->unk_20[3] = 1.0f;
    D_002C6440.p->unk_30[0] = 1.0f;
    D_002C6440.p->unk_30[1] = 1.0f;
    D_002C6440.p->unk_30[2] = 1.0f;
    D_002C6440.p->unk_30[3] = 1.0f;
    Interpolation_Initialize();
    if (TaskSystem_FindTask(LightTask_Update) == 0) {
        TaskSystem_AddTask(60000, LightTask_Update);
    }
}

