/**
 * Native command functions, probably called by the actor / AI bytecode: table D_002E2810 holds {function, argument count |
 * 0x40000000 when the command returns a value}, and each function reads its arguments from the array it is passed and
 * writes its result to element 0. Most wrap an engine function; the rest read or set fields of an actor object (XAudObj).
 * Angles in degrees are converted with (d / 180) * PI and wrapped by Angle_Wrap.
 */
#include "common.h"
#include "math.h"

extern s32 D_002979E8;
extern f32 D_002B8344[];
extern f32 D_002B8348;

extern s32 D_002DF430;
extern s32 D_002DF43C;

extern f32 Angle_Wrap(f32);
extern f32 func_00177D68(void);
extern s32 func_00147A10(s32);

typedef struct XAud6C {
    /* 0x00 */ char unk_00[0xBD];
    /* 0xBD */ u8 unk_BD;
    /* 0xBE */ char unk_BE[0xE];
    /* 0xCC */ f32 unk_CC;
} XAud6C;

typedef struct XAud130 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ char unk_1C[0x30];
    /* 0x4C */ u16 unk_4C;
    /* 0x4E */ u16 unk_4E;
    /* 0x50 */ char unk_50[0x8];
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 unk_59;
    /* 0x5A */ u8 unk_5A;
} XAud130;

typedef struct XAud14C_18 {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ f32 unk_24;
} XAud14C_18;

typedef struct XAud14C {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ XAud14C_18* unk_18;
} XAud14C;

typedef struct XAud398 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XAud398;

typedef struct XAud370Bits {
    u64 unk_00 : 35;
    u64 unk_35 : 1;
    u64 unk_36 : 1;
    u64 unk_37 : 2;
    u64 unk_39 : 12;
    u64 unk_51 : 1;
    u64 unk_52 : 1;
    u64 unk_53 : 1;
    u64 unk_54 : 1;
    u64 unk_55 : 9;
} XAud370Bits;

typedef union XAud370 {
    u64 raw;
    XAud370Bits b;
} XAud370;

typedef struct XAudObj {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ char unk_004[0xC];
    /* 0x010 */ f32 unk_010[4];
    /* 0x020 */ char unk_020[0xC];
    /* 0x02C */ struct XAudObj* unk_02C;
    /* 0x030 */ f32 unk_030[4];
    /* 0x040 */ char unk_040[0x2C];
    /* 0x06C */ XAud6C* unk_06C;
    /* 0x070 */ char unk_070[0x18];
    /* 0x088 */ s32 unk_088;
    /* 0x08C */ char unk_08C[0x44];
    /* 0x0D0 */ f32 unk_0D0[4][4];
    /* 0x110 */ char unk_110[0x10];
    /* 0x120 */ f32 unk_120[4];
    /* 0x130 */ XAud130* unk_130;
    /* 0x134 */ char unk_134[0x18];
    /* 0x14C */ XAud14C* unk_14C;
    /* 0x150 */ f32 unk_150;
    /* 0x154 */ char unk_154[0x10];
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ char unk_168[0x10];
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ char unk_17C[0x50];
    /* 0x1CC */ s32 unk_1CC;
    /* 0x1D0 */ char unk_1D0[0xC];
    /* 0x1DC */ s32* unk_1DC;
    /* 0x1E0 */ char unk_1E0[0xA4];
    /* 0x284 */ f32 unk_284;
    /* 0x288 */ char unk_288[0xE8];
    /* 0x370 */ XAud370 unk_370;
    /* 0x378 */ char unk_378[0x20];
    /* 0x398 */ XAud398* unk_398;
    /* 0x39C */ char unk_39C[0x2];
    /* 0x39E */ u8 unk_39E;
    /* 0x39F */ char unk_39F[0x5];
    /* 0x3A4 */ s32 unk_3A4;
    /* 0x3A8 */ s32 unk_3A8;
    /* 0x3AC */ s32 unk_3AC;
    /* 0x3B0 */ s32 unk_3B0;
    /* 0x3B4 */ char unk_3B4[0xC];
    /* 0x3C0 */ f32 unk_3C0[4];
    /* 0x3D0 */ s32 unk_3D0;
    /* 0x3D4 */ f32 unk_3D4;
    /* 0x3D8 */ char unk_3D8[0xC];
    /* 0x3E4 */ s32 unk_3E4;
    /* 0x3E8 */ char unk_3E8[0x68];
    /* 0x450 */ f32 unk_450[4];
    /* 0x460 */ char unk_460[0x30];
    /* 0x490 */ f32 unk_490[4];
} XAudObj;

// arg0[0] seen as a block of pointers
typedef struct XAudPtrs {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ void* unk_08;
} XAudPtrs;

// arg0[0] seen as a u64 of flags
typedef struct XAudFlags0 {
    u64 unk_00 : 2;
    u64 unk_02 : 2;
    u64 unk_04 : 7;
    u64 unk_0B : 1;
    u64 unk_0C : 2;
} XAudFlags0;

// arg0[1] with a u64 of flags at 0x8
typedef struct XAudB8 {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u64 unk_08;
} XAudB8;

typedef union XAudArg {
    s32 s;
    u32 u;
    f32 f;
    void* p;
    XAudObj* obj;
    XAudPtrs* ptrs;
    XAudFlags0* flags;
    XAudB8* b8;
} XAudArg;

// Native command 2 (1 arg, returns a value): sine of the angle a0 in degrees (wrapped by Angle_Wrap).
void NativeCmd_SinDeg(f32* arg0) {
    f32 x = Angle_Wrap((*arg0 / 180.0f) * PI);
    *arg0 = sinf(x);
}

// Native command 3 (1 arg, returns a value): cosine of the angle a0 in degrees.
void NativeCmd_CosDeg(f32* arg0) {
    f32 x = Angle_Wrap((*arg0 / 180.0f) * PI);
    *arg0 = cosf(x);
}

// Native command 25 (0 args, returns a value): a0 = func_00177D68().
void func_00128ED8(f32* arg0) {
    *arg0 = func_00177D68();
}

// Native command 5 (0 args, returns a value): a0 = D_002B8344[0].
void func_00128F00(f32* arg0) {
    *arg0 = D_002B8344[0];
}

// Native command 46 (1 arg, returns a value): a0 = func_00147A10(a0).
void func_00128F10(s32* arg0) {
    *arg0 = func_00147A10(*arg0);
}

// Native command 66 (1 arg): empty.
void func_00128F40(void) {
}

// Native command 72 (1 arg): empty.
void func_00128F48(void) {
}

// Native command 73 (1 arg): empty.
void func_00128F50(void) {
}

// Native command 149 (1 arg, returns a value): a0 degrees to radians (wrapped by Angle_Wrap).
void NativeCmd_DegToRad(f32* arg0) {
    *arg0 = Angle_Wrap((*arg0 / 180.0f) * PI);
}

// Native command 166 (1 arg): D_002B8348 = a0.
void func_00128FA8(f32* arg0) {
    D_002B8348 = *arg0;
}

#ifdef VERSION_FM
extern u32 D_002BBDE4;

// Native command 219 (0 args, returns a value): a0 = D_002BBDE4 >= 2 && D_002BBDE4 != 7.
void fm_func_00128F70(XAudArg* arg0) {
    arg0[0].s = D_002BBDE4 >= 2 && D_002BBDE4 != 7;
}
#endif

#ifdef VERSION_FM
extern u32 D_002C1EA8;
// Native command 221 (0 args, returns a value): a0 = (D_002C1EA8 >> 13) & 1.
void fm_func_00128F98(XAudArg* arg0) {
    arg0[0].s = (D_002C1EA8 >> 13) & 1;
}
#endif

#ifdef VERSION_FM
extern s32 D_00301088;
// Native command 224 (0 args, returns a value): a0 = D_00301088 & 7.
void fm_func_00128FB0(XAudArg* arg0) {
    arg0[0].s = D_00301088 & 7;
}
#endif

f32 Vec_Length(s32);

// Native command 6 (1 arg, returns a value): a0 = Vec_Length(a0).
void func_00128FB8(XAudArg* arg0) {
    arg0[0].f = Vec_Length(arg0[0].s);
}

// Native command 7 (2 args): vector a0 += a1.
void NativeCmd_AddVector(f32** arg0) {
    sceVu0AddVector(arg0[0], arg0[0], arg0[1]);
}

// Native command 8 (2 args): vector a0 -= a1.
void NativeCmd_SubVector(f32** arg0) {
    sceVu0SubVector(arg0[0], arg0[0], arg0[1]);
}

// Native command 9 (1 arg): func_001223B0(a0, a0).
void func_00129038(f32** arg0) {
    func_001223B0(arg0[0], arg0[0]);
}

extern f32 D_002C1E20[4][4];
void sceVu0RotMatrixY(f32 (*)[4], f32 (*)[4], f32);
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);

// Native command 10 (2 args): rotates vector a0 about Y by a1 degrees.
void NativeCmd_RotateVectorY(XAudArg* arg0) {
    f32 m[4][4] __attribute__((aligned(16)));
    sceVu0RotMatrixY(m, D_002C1E20, Angle_Wrap((arg0[1].f / 180.0f) * PI));
    sceVu0ApplyMatrix(arg0[0].p, m, arg0[0].p);
}

extern f32 D_002C1E20[4][4];
void sceVu0RotMatrixZ(f32 (*)[4], f32 (*)[4], f32);
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);

// Native command 31 (2 args): rotates vector a0 about Z by a1 degrees.
void NativeCmd_RotateVectorZ(XAudArg* arg0) {
    f32 m[4][4] __attribute__((aligned(16)));
    sceVu0RotMatrixZ(m, D_002C1E20, Angle_Wrap((arg0[1].f / 180.0f) * PI));
    sceVu0ApplyMatrix(arg0[0].p, m, arg0[0].p);
}

void sceVu0ScaleVectorXYZ(f32*, f32*, f32);

// Native command 18 (3 args): vector a0 += a1 * a2 * D_002B8344[0] (D_002B8344[0] is probably the frame time step).
void NativeCmd_AddScaledVector(XAudArg* arg0) {
    f32 v[4] __attribute__((aligned(16)));
    sceVu0ScaleVectorXYZ(v, arg0[1].p, arg0[2].f * D_002B8344[0]);
    sceVu0AddVector(arg0[0].p, arg0[0].p, v);
}

void Vec_RotateTowards(s32, s32, s32, f32);

// Native command 24 (3 args): Vec_RotateTowards(a0, a1, a0, (a2 / 180.0f) * PI).
void func_00129188(XAudArg* arg0) {
    Vec_RotateTowards(arg0[0].s, arg0[1].s, arg0[0].s, (arg0[2].f / 180.0f) * PI);
}

void sceVu0ScaleVectorXYZ(f32*, f32*, f32);

// Native command 93 (2 args): scales vector a0 (XYZ) by a1.
void NativeCmd_ScaleVector(XAudArg* arg0) {
    sceVu0ScaleVectorXYZ(arg0[0].p, arg0[0].p, arg0[1].f);
}

f32 Vec_CosAngle(s32, s32);

// Native command 100 (2 args, returns a value): a0 = Vec_CosAngle(a0, a1).
void func_00129200(XAudArg* arg0) {
    arg0[0].f = Vec_CosAngle(arg0[0].s, arg0[1].s);
}

void func_0014E668(s32, f32, f32, s32, s32);

// Native command 134 (4 args): func_0014E668(a0, a1, a2, 0, a3).
void func_00129230(XAudArg* arg0) {
    func_0014E668(arg0[0].s, arg0[1].f, arg0[2].f, 0, arg0[3].s);
}

extern f32 D_002C1E20[4][4];
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);
void sceVu0RotMatrix(f32 (*)[4], f32 (*)[4], f32*);

// Native command 144 (2 args): rotates vector a0 by the X/Y/Z angles in degrees of vector a1.
void NativeCmd_RotateVectorXYZ(XAudArg* arg0) {
    f32 rot[4] __attribute__((aligned(16)));
    f32 m[4][4] __attribute__((aligned(16)));
    s32 i;

    for (i = 0; i < 3; i++) {
        rot[i] = Angle_Wrap((((f32*)arg0[1].p)[i] / 180.0f) * PI);
    }
    rot[3] = 0.0f;
    sceVu0RotMatrix(m, D_002C1E20, rot);
    sceVu0ApplyMatrix(arg0[0].p, m, arg0[0].p);
}

#ifdef VERSION_FM
// Native command 177 (1 arg): empty.
void fm_func_00129330(void) {
}
#endif

#ifdef VERSION_FM
void Vec_ToAngles(void*, s32);

// Native command 223 (2 args): Vec_ToAngles(a0, a1).
void func_00129320(XAudArg* arg0) {
    Vec_ToAngles(arg0[0].p, arg0[1].s);
}
#else
void func_00129320(void) {
}
#endif

s32 Actor_FindById(s32);

// Native command 4 (1 arg, returns a value): a0 = Actor_FindById(a0).
void func_00129328(XAudArg* arg0) {
    arg0[0].s = Actor_FindById(arg0[0].s);
}

void func_00137688(XAudObj*, f32);

// Native command 11 (2 args): object a0's angle unk_150 = atan2 of vector a1 (x, z), applied with func_00137688.
void NativeCmd_FaceVector(XAudArg* arg0) {
    f32* v = arg0[1].p;
    XAudObj* obj = arg0[0].obj;
    f32 a = atan2f(v[0], v[2]);
    obj->unk_150 = a;
    func_00137688(obj, a);
}

void func_00130398(s32, s32, f32);

// Native command 12 (3 args): func_00130398(a0, a1, a2).
void func_00129398(XAudArg* arg0) {
    func_00130398(arg0[0].s, arg0[1].s, arg0[2].f);
}

f32* func_00130340(s32, s32, f32);

// Native command 13 (4 args): func_00130340(a0, a1, a2)[1] = a3.
void func_001293C0(XAudArg* arg0) {
    func_00130340(arg0[0].s, arg0[1].s, arg0[2].f)[1] = arg0[3].f;
}

f32* func_00130578(s32, s32, f32);

// Native command 14 (4 args): func_00130578(a0, a1, a2)[1] = a3.
void func_001293F8(XAudArg* arg0) {
    func_00130578(arg0[0].s, arg0[1].s, arg0[2].f)[1] = arg0[3].f;
}

void func_001315C0(s32, s32, f32, s32);

// Native command 19 (4 args): func_001315C0(a0, a1, a2, a3).
void func_00129430(XAudArg* arg0) {
    func_001315C0(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].s);
}

f32 func_00142CF0(s32, s32, f32, f32);

// Native command 27 (4 args, returns a value): a0 = func_00142CF0(a0, a1, a2, a3).
void func_00129458(XAudArg* arg0) {
    arg0[0].f = func_00142CF0(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

s32 Actor_Next(s32);

// Native command 30 (1 arg, returns a value): a0 = Actor_Next(a0).
void func_00129490(XAudArg* arg0) {
    arg0[0].s = Actor_Next(arg0[0].s);
}

void func_0012EC88(void*, s32);

// Native command 32 (2 args): func_0012EC88(a0, a1).
void func_001294C0(XAudArg* arg0) {
    func_0012EC88(arg0[0].p, arg0[1].s);
}

// Native command 35 (1 arg, returns a value).
void func_001294E0(XAudArg* arg0) {
    if (arg0[0].obj->unk_178 == 0) {
        arg0[0].s = 0;
    } else {
        arg0[0].s = 1;
    }
}

void sceVu0CopyVector(f32*, f32*);

// Native command 36 (2 args): object a0's angle unk_150 = atan2 of vector a1 (x, z), without applying it.
void NativeCmd_SetAngleFromVector(XAudArg* arg0) {
    f32 v[4] __attribute__((aligned(16)));
    XAudObj* obj = arg0[0].obj;
    sceVu0CopyVector(v, arg0[1].p);
    obj->unk_150 = atan2f(v[0], v[2]);
}

s32 Actor_Spawn(s32);

// Native command 37 (1 arg, returns a value): a0 = Actor_Spawn(a0).
void func_00129540(XAudArg* arg0) {
    arg0[0].s = Actor_Spawn(arg0[0].s);
}

f32 func_00142E30(s32, s32, s32);

// Native command 40 (3 args, returns a value): a0 = func_00142E30(a0, a1, a2).
void func_00129570(XAudArg* arg0) {
    arg0[0].f = func_00142E30(arg0[0].s, arg0[1].s, arg0[2].s);
}

f32 func_00131A68(s32, s32);

// Native command 43 (2 args, returns a value): a0 = func_00131A68(a0, a1).
void func_001295A8(XAudArg* arg0) {
    arg0[0].f = func_00131A68(arg0[0].s, arg0[1].s);
}

s32 func_001349D0(s32, s32);

// Native command 44 (2 args, returns a value): a0 = func_001349D0(a0, a1).
void func_001295D8(XAudArg* arg0) {
    arg0[0].s = func_001349D0(arg0[0].s, arg0[1].s);
}

void func_0014A380(s32, s32);

// Native command 47 (2 args, returns a value).
void func_00129608(XAudArg* arg0) {
    func_0014A380(arg0[0].s, arg0[1].s);
    arg0[0].s = 0;
}

void func_00138A20(s32, f32, s32);

// Native command 50 (3 args): func_00138A20(a0, a1, a2).
void func_00129638(XAudArg* arg0) {
    func_00138A20(arg0[0].s, arg0[1].f, arg0[2].s);
}

s32 Actor_IsActive(s32);

// Native command 51 (1 arg, returns a value).
void func_00129660(XAudArg* arg0) {
    if (Actor_IsActive(arg0[0].s) != 0) {
        arg0[0].s = arg0[0].obj->unk_164;
    } else {
        arg0[0].s = 0xFFF;
    }
}

// Native command 54 (1 arg): empty.
void func_001296A8(void) {
}

void func_00131C28(void*, f32);

// Native command 59 (2 args): func_00131C28(a0, a1).
void func_001296B0(XAudArg* arg0) {
    func_00131C28(arg0[0].p, arg0[1].f);
}

s32 Actor_FindNextOpponent(s32, s32);

// Native command 65 (2 args, returns a value): a0 = Actor_FindNextOpponent(a0, a1).
void func_001296D0(XAudArg* arg0) {
    arg0[0].s = Actor_FindNextOpponent(arg0[0].s, arg0[1].s);
}

// Native command 69 (1 arg, returns a value): a0 = obj->unk_14C->unk_18->unk_24.
void func_00129700(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_14C->unk_18->unk_24;
}

s32 func_00148A40(s32, s32);

// Native command 75 (2 args, returns a value): a0 = func_00148A40(a0, a1).
void func_00129718(XAudArg* arg0) {
    arg0[0].s = func_00148A40(arg0[0].s, arg0[1].s);
}

s32 func_0012EF30(s32, s32, s32, f32);

// Native command 78 (4 args, returns a value): a0 = func_0012EF30(a0, a1, a2, a3).
void func_00129748(XAudArg* arg0) {
    arg0[0].s = func_0012EF30(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f);
}

void func_0014D428(s32, s32, f32, f32);

// Native command 82 (4 args): func_0014D428(a0, a1, a2, a3).
void func_00129780(XAudArg* arg0) {
    func_0014D428(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

// Native command 83 (2 args): obj->unk_3D0 = a1 - 3.
void func_001297A8(XAudArg* arg0) {
    arg0[0].obj->unk_3D0 = arg0[1].s - 3;
}

s32 func_0014EFE0(s32, s32);

// Native command 84 (2 args, returns a value): a0 = func_0014EFE0(a0, a1).
void func_001297C0(XAudArg* arg0) {
    arg0[0].s = func_0014EFE0(arg0[0].s, arg0[1].s);
}

s32 func_0014EE88(s32);

// Native command 85 (1 arg, returns a value): a0 = func_0014EE88(a0).
void func_001297F0(XAudArg* arg0) {
    arg0[0].s = func_0014EE88(arg0[0].s);
}

void Actor_SetPositionById(void*, s32);

// Native command 86 (2 args): Actor_SetPositionById(a0->unk_04, a1).
void func_00129820(XAudArg* arg0) {
    Actor_SetPositionById(arg0[0].ptrs->unk_04, arg0[1].s);
}

// Native command 87 (2 args): empty.
void func_00129840(void) {
}

void func_0014F658(void*, s32);

// Native command 88 (2 args): func_0014F658(a0, a1).
void func_00129848(XAudArg* arg0) {
    func_0014F658(arg0[0].p, arg0[1].s);
}

// Native command 89 (1 arg, returns a value): a0 = obj->unk_3D4.
void func_00129868(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_3D4;
}

s32 func_00142B30(s32, s32);

// Native command 91 (2 args, returns a value): a0 = func_00142B30(a0, a1).
void func_00129878(XAudArg* arg0) {
    arg0[0].s = func_00142B30(arg0[0].s, arg0[1].s);
}

s32 func_00142C80(s32, s32);

// Native command 92 (2 args, returns a value): a0 = func_00142C80(a0, a1).
void func_001298A8(XAudArg* arg0) {
    arg0[0].s = func_00142C80(arg0[0].s, arg0[1].s);
}

// Native command 96 (2 args): obj->unk_370.b.unk_37 = a1.
void func_001298D8(XAudArg* arg0) {
    arg0[0].obj->unk_370.b.unk_37 = arg0[1].u;
}

void func_00135978(s32, s32, s32);

// Native command 98 (3 args): func_00135978(a0, a1, a2).
void func_00129910(XAudArg* arg0) {
    func_00135978(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_001359C0(s32, s32, s32);

// Native command 99 (3 args): func_001359C0(a0, a1, a2).
void func_00129938(XAudArg* arg0) {
    func_001359C0(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_0014F5C8(s32);
s32 func_0014F600(s32);

// Native command 104 (1 arg, returns a value).
void func_00129960(XAudArg* arg0) {
    s32 r = 0;
    if (func_0014F5C8(arg0[0].s) != 0 || func_0014F600(arg0[0].s) != 0) {
        r = 1;
    }
    arg0[0].s = r;
}

s32 func_00148B70(s32, s32, s32, f32);

// Native command 106 (4 args, returns a value): a0 = func_00148B70(a0, a1, a2, a3).
void func_001299B8(XAudArg* arg0) {
    arg0[0].s = func_00148B70(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f);
}

void func_00148D18(s32, s32, f32);

// Native command 107 (3 args): func_00148D18(a0, a1, a2).
void func_001299F0(XAudArg* arg0) {
    func_00148D18(arg0[0].s, arg0[1].s, arg0[2].f);
}

void func_00148D50(s32, s32, s32, f32, f32);

// Native command 108 (5 args): func_00148D50(a0, a1, a2, a3, a4).
void func_00129A18(XAudArg* arg0) {
    func_00148D50(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].f, arg0[4].f);
}

s32 func_00148B98(s32, s32, s32);

// Native command 109 (3 args, returns a value): a0 = func_00148B98(a0, a1, a2 | 0x1000).
void func_00129A48(XAudArg* arg0) {
    arg0[0].s = func_00148B98(arg0[0].s, arg0[1].s, arg0[2].s | 0x1000);
}

void func_00148DB0(s32, s32, s32, f32);

// Native command 110 (4 args): func_00148DB0(a0, a1, a2 | 0x1000, a3).
void func_00129A80(XAudArg* arg0) {
    func_00148DB0(arg0[0].s, arg0[1].s, arg0[2].s | 0x1000, arg0[3].f);
}

// Native command 111 (2 args): object a0's flags unk_1CC |= a1.
void NativeCmd_SetFlags1CC(XAudArg* arg0) {
    arg0[0].obj->unk_1CC |= arg0[1].s;
}

// Native command 112 (2 args): object a0's flags unk_1CC &= ~a1.
void NativeCmd_ClearFlags1CC(XAudArg* arg0) {
    arg0[0].obj->unk_1CC &= ~arg0[1].s;
}

void func_00131498(XAudObj*, void*);

// Native command 113 (2 args).
void func_00129AE8(XAudArg* arg0) {
    s32* tbl = arg0[0].obj->unk_1DC;
    XAudObj* obj = arg0[1].obj;
    func_00131498(obj, (u8*)tbl + tbl[obj->unk_130->unk_4C + 1]);
}

// Native command 114 (1 arg, returns a value): a0 = obj->unk_130->unk_4C.
void func_00129B28(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_4C;
}

void func_001318E8(s32, s32, f32 (*)[4]);
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);

// Native command 115 (4 args).
void func_00129B40(XAudArg* arg0) {
    f32 m[4][4] __attribute__((aligned(16)));
    func_001318E8(arg0[0].s, arg0[2].s | 0x1000, m);
    sceVu0ApplyMatrix(arg0[3].p, m, arg0[1].p);
}

// Native command 116 (4 args): ors a1, a2, a3 into object a0's flag words unk_3A4, unk_3A8, unk_3AC.
void NativeCmd_SetFlags3A4(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_3A4 |= arg0[1].s;
    obj->unk_3A8 |= arg0[2].s;
    obj->unk_3AC |= arg0[3].s;
}

// Native command 117 (4 args): clears a1, a2, a3 from object a0's flag words unk_3A4, unk_3A8, unk_3AC.
void NativeCmd_ClearFlags3A4(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_3A4 &= ~arg0[1].s;
    obj->unk_3A8 &= ~arg0[2].s;
    obj->unk_3AC &= ~arg0[3].s;
}

// Native command 118 (2 args): sceVu0SubVector(a1, obj->unk_010, obj->unk_490).
void func_00129C08(XAudArg* arg0) {
    sceVu0SubVector(arg0[1].p, arg0[0].obj->unk_010, arg0[0].obj->unk_490);
}

void func_0012EC60(s32, s32, s32);

// Native command 119 (3 args): func_0012EC60(a0, a1, a2).
void func_00129C30(XAudArg* arg0) {
    func_0012EC60(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 Actor_IsActive(s32);

// Native command 120 (1 arg, returns a value): a0 = Actor_IsActive(a0).
void func_00129C58(XAudArg* arg0) {
    arg0[0].s = Actor_IsActive(arg0[0].s);
}

void func_0014F948(void*, s32);

// Native command 121 (2 args): func_0014F948(a0, a1).
void func_00129C88(XAudArg* arg0) {
    func_0014F948(arg0[0].p, arg0[1].s);
}

// Native command 124 (2 args): obj->unk_130->unk_18 = a1.
void func_00129CA8(XAudArg* arg0) {
    arg0[0].obj->unk_130->unk_18 = arg0[1].f;
}

// Native command 125 (2 args): obj->unk_06C->unk_CC = (a1 / 180.0f) * PI.
void func_00129CC0(XAudArg* arg0) {
    arg0[0].obj->unk_06C->unk_CC = (arg0[1].f / 180.0f) * PI;
}

void func_001358B8(void*, s32);

// Native command 127 (2 args): func_001358B8(a0, a1).
void func_00129CF8(XAudArg* arg0) {
    func_001358B8(arg0[0].p, arg0[1].s);
}

void func_001358F8(void*, s32);

// Native command 128 (2 args): func_001358F8(a0, a1).
void func_00129D18(XAudArg* arg0) {
    func_001358F8(arg0[0].p, arg0[1].s);
}

// Native command 129 (1 arg): obj->unk_370.raw |= 0x8000000000000.
void func_00129D38(XAudArg* arg0) {
    arg0[0].obj->unk_370.raw |= 0x8000000000000;
}

// Native command 132 (1 arg, returns a value): a0 = obj->unk_130->unk_5A.
void func_00129D58(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_5A;
}

void func_00131A30(s32, s32, s32);

// Native command 133 (3 args): func_00131A30(a0, a1, a2).
void func_00129D70(XAudArg* arg0) {
    func_00131A30(arg0[0].s, arg0[1].s, arg0[2].s);
}

// Native command 135 (2 args).
void func_00129D98(XAudArg* arg0) {
    func_0014F658(arg0[0].p, 4);
    sceVu0ScaleVectorXYZ(arg0[0].obj->unk_3C0, arg0[1].p, ((f32*)arg0[1].p)[3]);
}

void func_00135A10(void*, s32);

// Native command 136 (2 args): func_00135A10(a0, a1).
void func_00129DD8(XAudArg* arg0) {
    func_00135A10(arg0[0].p, arg0[1].s);
}

void func_00135A38(void*, s32);

// Native command 137 (2 args): func_00135A38(a0, a1).
void func_00129DF8(XAudArg* arg0) {
    func_00135A38(arg0[0].p, arg0[1].s);
}

extern s32 D_002E26A0;
s32 func_0012F1D0(f32*, s32);

// Native command 139 (1 arg, returns a value).
void func_00129E18(XAudArg* arg0) {
    f32 v[4] __attribute__((aligned(16)));
    s32 x = D_002E26A0;
    if (x == 0) {
        arg0[0].s = 1;
    } else {
        func_001315C0(x, 0, 1.0f, (s32)v);
        arg0[0].s = func_0012F1D0(v, arg0[0].s) == 0;
    }
}

s32 func_001237E8(s32);

// Native command 141 (1 arg, returns a value): a0 = func_001237E8(a0).
void func_00129E78(XAudArg* arg0) {
    arg0[0].s = func_001237E8(arg0[0].s);
}

void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);

// Native command 143 (2 args).
void func_00129EA8(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    if (obj->unk_1CC & 8) {
        sceVu0CopyVector(arg0[1].p, obj->unk_450);
        ((f32*)arg0[1].p)[3] = 0.0f;
        sceVu0ApplyMatrix(arg0[1].p, obj->unk_0D0, arg0[1].p);
    } else {
        sceVu0CopyVector(arg0[1].p, obj->unk_030);
    }
}

void func_00137440(void*, s32);

// Native command 146 (2 args): func_00137440(a0, a1).
void func_00129F20(XAudArg* arg0) {
    func_00137440(arg0[0].p, arg0[1].s);
}

// Native command 147 (1 arg, returns a value).
void func_00129F40(XAudArg* arg0) {
    XAud398* p = arg0[0].obj->unk_398;
    arg0[0].s = (p != NULL) ? p->unk_04 : -1;
}

void func_001366D8(s32, s32, s32);

// Native command 153 (3 args, returns a value): func_001366D8(a0, a1, a2).
void func_00129F60(XAudArg* arg0) {
    func_001366D8(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_00137618(s32);

// Native command 156 (1 arg, returns a value): a0 = func_00137618(a0).
void func_00129F88(XAudArg* arg0) {
    arg0[0].s = func_00137618(arg0[0].s);
}

void func_00137448(void*);

// Native command 157 (1 arg): func_00137448(a0).
void func_00129FB8(XAudArg* arg0) {
    func_00137448(arg0[0].p);
}

s32 func_001477E0(s32);

// Native command 158 (2 args, returns a value): a0 = func_001477E0(a1).
void func_00129FD0(XAudArg* arg0) {
    arg0[0].s = func_001477E0(arg0[1].s);
}

// Native command 163 (1 arg, returns a value): a0 = (s32)(obj->unk_370.raw >> 35) & 1.
void func_0012A000(XAudArg* arg0) {
    arg0[0].s = (s32)(arg0[0].obj->unk_370.raw >> 35) & 1;
}

void func_00157818(void*, s32);

// Native command 168 (2 args): func_00157818(a0, a1).
void func_0012A018(XAudArg* arg0) {
    func_00157818(arg0[0].p, arg0[1].s);
}

// Native command 169 (2 args).
void func_0012A038(XAudArg* arg0) {
    func_0014F658(arg0[0].p, 7);
    sceVu0ScaleVectorXYZ(arg0[0].obj->unk_3C0, arg0[1].p, ((f32*)arg0[1].p)[3]);
}

// Native command 170 (1 arg, returns a value).
void func_0012A078(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    arg0[0].s = (obj != NULL) ? (s32)(obj->unk_370.raw >> 37) & 3 : 0;
}

s32 func_00131B08(s32);

// Native command 172 (1 arg, returns a value): a0 = func_00131B08(a0).
void func_0012A098(XAudArg* arg0) {
    arg0[0].s = func_00131B08(arg0[0].s);
}

// Native command 176 (1 arg, returns a value): a0 = obj->unk_130->unk_4E.
void func_0012A0C8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_4E;
}

// Native command 180 (2 args): obj->unk_06C->unk_BD = a1.
void func_0012A0E0(XAudArg* arg0) {
    arg0[0].obj->unk_06C->unk_BD = arg0[1].s;
}

s32 func_00157528(s32);

// Native command 181 (1 arg, returns a value): a0 = func_00157528(a0).
void func_0012A0F8(XAudArg* arg0) {
    arg0[0].s = func_00157528(arg0[0].s);
}

void func_00157648(void*);

// Native command 182 (1 arg): func_00157648(a0).
void func_0012A128(XAudArg* arg0) {
    func_00157648(arg0[0].p);
}

void func_00157978(s32, s32, f32);

// Native command 183 (3 args): func_00157978(a0, a1, a2).
void func_0012A140(XAudArg* arg0) {
    func_00157978(arg0[0].s, arg0[1].s, arg0[2].f);
}

extern s32 D_00350D80[];

// Native command 184 (1 arg).
void func_0012A168(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    if (!((s32)(obj->unk_370.raw >> 54) & 1)) {
        D_00350D80[0] -= obj->unk_130->unk_59;
        obj->unk_370.b.unk_54 = 1;
    }
}

// Native command 187 (1 arg, returns a value): a0 = obj->unk_39E.
void func_0012A1B8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_39E;
}

f32 func_00132F00(s32);

// Native command 189 (1 arg, returns a value): a0 = func_00132F00(a0).
void func_0012A1C8(XAudArg* arg0) {
    arg0[0].f = func_00132F00(arg0[0].s);
}

// Native command 199 (1 arg, returns a value): a0 = obj->unk_130->unk_58.
void func_0012A1F8(XAudArg* arg0) {
    arg0[0].s = arg0[0].obj->unk_130->unk_58;
}

s32 func_001425D0(XAudObj*);

// Native command 203 (2 args).
void func_0012A210(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    if (func_001425D0(obj) == 0) {
        sceVu0AddVector(obj->unk_120, obj->unk_120, arg0[1].p);
    }
}

// Native command 204 (1 arg, returns a value): a0 = obj->unk_284.
void func_0012A270(XAudArg* arg0) {
    arg0[0].f = arg0[0].obj->unk_284;
}

extern f32 D_002C58B0[4];
s32 Party_FindCharacterSlot(s32);
void func_0023E0B0(s32, s32);
void func_00153D88(XAudObj*);

// Native command 207 (1 arg).
void func_0012A280(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_000 |= 0x240;
    func_001358B8(obj, 10);
    func_0014F658(obj, 8);
    sceVu0CopyVector(obj->unk_3C0, D_002C58B0);
    obj->unk_3B0 = 0;
    obj->unk_370.raw |= 0x1000000000000000;
    func_0023E0B0(Party_FindCharacterSlot(obj->unk_130->unk_4C), 3);
    func_00153D88(obj);
}

// Native command 208 (1 arg): obj->unk_370.raw |= 0x10000000000000.
void func_0012A308(XAudArg* arg0) {
    arg0[0].obj->unk_370.raw |= 0x10000000000000;
}

s32 func_00148968(s32, s32, s32);

// Native command 209 (3 args, returns a value): a0 = func_00148968(a0, a1, a2).
void func_0012A328(XAudArg* arg0) {
    arg0[0].s = func_00148968(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00142388(f32*, f32*);
void func_00142470(XAudObj*, f32*);

// Native command 210 (1 arg).
void func_0012A360(XAudArg* arg0) {
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    XAudObj* obj = arg0[0].obj;
    func_001315C0((s32)obj, 0x8003, 0.0f, (s32)v);
    func_00142388(v, w);
    func_00142470(obj, w);
    obj->unk_370.raw |= 0x10000000000000;
}

#ifdef VERSION_FM
void func_F20000(s32, s32);

// Native command 212 (1 arg).
void fm_func_0012A400(XAudArg* arg0) {
    if ((D_002C1EA8 >> 13) & 1) {
        func_F20000(6, arg0[0].s);
    }
}
#endif

s32 func_0014F5C8(s32);
s32 func_0014F600(s32);

// Native command 218 (1 arg, returns a value).
void func_0012A3D0(XAudArg* arg0) {
    s32 r = 0;
    if (func_0014F5C8(arg0[0].s) == 0) {
        r = func_0014F600(arg0[0].s) == 0;
    }
    arg0[0].s = r;
}

#ifdef VERSION_FM
void func_00135848(s32);
void func_00135870(s32);

// Native command 220 (2 args).
void fm_func_0012A498(XAudArg* arg0) {
    if (arg0[1].s != 0) {
        func_00135848(arg0[0].s);
    } else {
        func_00135870(arg0[0].s);
    }
}
#endif

#ifdef VERSION_FM
s32 func_00148A60(s32, s32);

// Native command 225 (2 args, returns a value): a0 = func_00148A60(a0, a1).
void fm_func_0012A4C8(XAudArg* arg0) {
    arg0[0].s = func_00148A60(arg0[0].s, arg0[1].s);
}
#endif

s32 func_00147C98(s32, s32, s32);

// Native command 15 (3 args, returns a value): a0 = func_00147C98(a0, a1, a2).
void func_0012A418(XAudArg* arg0) {
    arg0[0].s = func_00147C98(arg0[0].s, arg0[1].s, arg0[2].s);
}

void sceVu0CopyVector(f32*, f32*);

// Native command 16 (2 args): sceVu0CopyVector(a0->unk_00, a1).
void func_0012A450(XAudArg* arg0) {
    sceVu0CopyVector(arg0[0].ptrs->unk_00, arg0[1].p);
}

void func_00176340(void*);

// Native command 17 (1 arg): func_00176340(a0).
void func_0012A470(XAudArg* arg0) {
    func_00176340(arg0[0].p);
}

s32 func_00148768(s32, s32, s32, s32, f32);

// Native command 21 (5 args, returns a value): a0 = func_00148768(a0, a1, a2, a3, a4).
void func_0012A488(XAudArg* arg0) {
    arg0[0].s = func_00148768(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s, arg0[4].f);
}

void func_00147F88(void*, f32);

// Native command 26 (2 args): func_00147F88(a0, a1).
void func_0012A4C8(XAudArg* arg0) {
    func_00147F88(arg0[0].p, arg0[1].f);
}

extern f32 D_002DEC60[4][4];
void sceVu0InversMatrix(f32 (*)[4], f32 (*)[4]);
void Vec_Project(s32, f32 (*)[4], s32);

// Native command 29 (2 args).
void func_0012A4E8(XAudArg* arg0) {
    f32 m[4][4] __attribute__((aligned(16)));
    sceVu0InversMatrix(m, D_002DEC60);
    Vec_Project(arg0[0].s, m, arg0[1].s);
}

// Native command 39 (2 args): sceVu0CopyVector(a0->unk_08, a1).
void func_0012A528(XAudArg* arg0) {
    sceVu0CopyVector(arg0[0].ptrs->unk_08, arg0[1].p);
}

// Native command 55 (2 args): stores the radian angles of vector a1 as 16-bit angles (0x10000 a turn) in the three words at a0->unk_04.
void NativeCmd_SetAngles16(XAudArg* arg0) {
    XAudArg* v = arg0[1].p;
    XAudPtrs* p = arg0[0].ptrs;
    ((XAudArg*)p->unk_04)[0].s = (u16)(s32)((v[0].f / 6.2831855f) * 65536.0f);
    ((XAudArg*)p->unk_04)[1].s = (u16)(s32)((v[1].f / 6.2831855f) * 65536.0f);
    ((XAudArg*)p->unk_04)[2].s = (u16)(s32)((v[2].f / 6.2831855f) * 65536.0f);
}

extern f32 D_002DEC60[4][4];

// Native command 56 (0 args, returns a value): a0 = atan2f(D_002DEC60[0][2], D_002DEC60[2][2]).
void func_0012A5F0(XAudArg* arg0) {
    arg0[0].f = atan2f(D_002DEC60[0][2], D_002DEC60[2][2]);
}

void func_00147D50(void*, s32);

// Native command 61 (2 args): func_00147D50(a0, a1).
void func_0012A628(XAudArg* arg0) {
    func_00147D50(arg0[0].p, arg0[1].s);
}

s32 func_00147ED8(s32, s32, s32, s32);

// Native command 74 (4 args, returns a value): a0 = func_00147ED8(a0, a1, a2, a3).
void func_0012A648(XAudArg* arg0) {
    arg0[0].s = func_00147ED8(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s);
}

void func_00176310(void*);

// Native command 97 (1 arg, returns a value).
void func_0012A680(XAudArg* arg0) {
    if (arg0[0].p != NULL) {
        func_00176310(arg0[0].p);
    }
    arg0[0].s = 0;
}

void func_0012BD00(void*, s32);

// Native command 103 (2 args): func_0012BD00(a0, a1).
void func_0012A6B8(XAudArg* arg0) {
    func_0012BD00(arg0[0].p, arg0[1].s);
}

void func_001486B0(s32, s32, s32);

// Native command 126 (3 args): func_001486B0(a0, a1, a2).
void func_0012A6D8(XAudArg* arg0) {
    func_001486B0(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00148068(void*, f32);

// Native command 145 (2 args): func_00148068(a0, a1).
void func_0012A700(XAudArg* arg0) {
    func_00148068(arg0[0].p, arg0[1].f);
}

void func_00176310(void*);

// Native command 154 (2 args): func_00176310(a0).
void func_0012A720(XAudArg* arg0) {
    func_00176310(arg0[0].p);
}

s32 func_0014A408(XAudArg*);

// Native command 22 (0 args, returns a value): a0 = func_0014A408(arg0).
void func_0012A738(XAudArg* arg0) {
    arg0[0].s = func_0014A408(arg0);
}

s32* func_0014A4A8(s32, s32, s32);
extern s32 D_00514F10;

// Native command 23 (3 args, returns a value).
void func_0012A760(XAudArg* arg0) {
    s32* p = func_0014A4A8(arg0[0].s, arg0[1].s, arg0[2].s);
    arg0[0].p = p;
    p[0xA0 / 4] = D_00514F10;
}

s32 func_001354B8(s32, s32);

// Native command 60 (2 args, returns a value): a0 = func_001354B8(a0, a1).
void func_0012A7A0(XAudArg* arg0) {
    arg0[0].s = func_001354B8(arg0[0].s, arg0[1].s);
}

void func_0014A898(void*, s32);

// Native command 76 (2 args): func_0014A898(a0, a1).
void func_0012A7D0(XAudArg* arg0) {
    func_0014A898(arg0[0].p, arg0[1].s);
}

// Native command 95 (2 args): a0->unk_0C = a1.
void func_0012A7F0(XAudArg* arg0) {
    arg0[0].flags->unk_0C = arg0[1].u;
}

void func_00135640(void*, s32);

// Native command 159 (2 args): func_00135640(a0, a1).
void func_0012A818(XAudArg* arg0) {
    func_00135640(arg0[0].p, arg0[1].s);
}

void func_00134870(s32, s32, s32);

// Native command 160 (3 args, returns a value).
void func_0012A838(XAudArg* arg0) {
    s32 p = func_001354B8(arg0[0].s, arg0[1].s);
    if (p != 0) {
        func_00134870(arg0[1].s, p, arg0[2].s);
    }
    arg0[0].s = p;
}

void func_0014AB78(void*);

// Native command 175 (1 arg): func_0014AB78(a0).
void func_0012A888(XAudArg* arg0) {
    func_0014AB78(arg0[0].p);
}

// Native command 213 (2 args).
void func_0012A8A0(XAudArg* arg0) {
    XAudFlags0* p = arg0[0].flags;
    if (p != NULL && ((s32)(*(u64*)p >> 11) & 1)) {
        p->unk_02 = arg0[1].u;
    }
}

// Native command 188 (1 arg, returns a value): a0 = obj->unk_02C->unk_06C.
void func_0012A8E8(XAudArg* arg0) {
    arg0[0].p = arg0[0].obj->unk_02C->unk_06C;
}

void func_00138A78(s32, void*);
void func_00139240(s32, void*, s32, f32, f32, f32);

// Native command 38 (6 args, returns a value).
void func_0012A900(XAudArg* arg0) {
    if ((s32)(arg0[1].b8->unk_08 >> 43) & 1) {
        func_00138A78(arg0[0].s, arg0[1].p);
    }
    func_00139240(arg0[0].s, arg0[1].p, arg0[2].s, arg0[3].f, arg0[4].f, arg0[5].f);
    arg0[0].s = 0;
}

void func_00138E58(s32, void*);

// Native command 41 (2 args).
void func_0012A968(XAudArg* arg0) {
    if ((s32)(arg0[1].b8->unk_08 >> 43) & 1) {
        func_00138A78(arg0[0].s, arg0[1].p);
    }
    func_00138E58(arg0[0].s, arg0[1].p);
}

void func_00138C30(s32, void*);

// Native command 42 (2 args).
void func_0012A9B8(XAudArg* arg0) {
    if ((s32)(arg0[1].b8->unk_08 >> 43) & 1) {
        func_00138A78(arg0[0].s, arg0[1].p);
    }
    func_00138C30(arg0[0].s, arg0[1].p);
}

void func_00141F10(void*, s32);

// Native command 45 (2 args): func_00141F10(a0, a1).
void func_0012AA08(XAudArg* arg0) {
    func_00141F10(arg0[0].p, arg0[1].s);
}

s32 func_0013A440(s32, s32, f32, s32);

// Native command 48 (4 args, returns a value): a0 = func_0013A440(a0, a1, a2, a3).
void func_0012AA28(XAudArg* arg0) {
    arg0[0].s = func_0013A440(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].s);
}

void Actor_SetParent(s32, s32, s32);

// Native command 49 (2 args): Actor_SetParent(a0, a1, 0).
void func_0012AA60(XAudArg* arg0) {
    Actor_SetParent(arg0[0].s, arg0[1].s, 0);
}

void func_00139408(s32, s32);

// Native command 57 (2 args, returns a value).
void func_0012AA80(XAudArg* arg0) {
    func_00139408(arg0[0].s, arg0[1].s);
    arg0[0].s = 0;
}

s32 func_001389C0(s32);

// Native command 70 (1 arg, returns a value): a0 = func_001389C0(a0).
void func_0012AAB0(XAudArg* arg0) {
    arg0[0].s = func_001389C0(arg0[0].s);
}

s32 func_001389E8(s32);

// Native command 71 (1 arg, returns a value): a0 = func_001389E8(a0).
void func_0012AAE0(XAudArg* arg0) {
    arg0[0].s = func_001389E8(arg0[0].s);
}

void func_00139170(s32, void*);

// Native command 79 (2 args).
void func_0012AB10(XAudArg* arg0) {
    if ((s32)(arg0[1].b8->unk_08 >> 43) & 1) {
        func_00138A78(arg0[0].s, arg0[1].p);
    }
    func_00139170(arg0[0].s, arg0[1].p);
}

s32 Actor_FindNextAlly(s32, s32);

// Native command 80 (2 args, returns a value): a0 = Actor_FindNextAlly(a0, a1).
void func_0012AB60(XAudArg* arg0) {
    arg0[0].s = Actor_FindNextAlly(arg0[0].s, arg0[1].s);
}

s32 func_00137230(s32, s32, s32);

// Native command 81 (3 args, returns a value): a0 = func_00137230(a0, a1, a2).
void func_0012AB90(XAudArg* arg0) {
    arg0[0].s = func_00137230(arg0[0].s, arg0[1].s, arg0[2].s);
}

s32 func_001334B8(s32, s32, s32, s32, s32);

// Native command 94 (5 args, returns a value): a0 = func_001334B8(a0, a1, a2, a3, a4).
void func_0012ABC8(XAudArg* arg0) {
    arg0[0].s = func_001334B8(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s, arg0[4].s);
}

s32 func_0013A670(s32, s32, f32, f32);

// Native command 102 (4 args, returns a value): a0 = func_0013A670(a0, a1, a2, a3).
void func_0012AC08(XAudArg* arg0) {
    arg0[0].s = func_0013A670(arg0[0].s, arg0[1].s, arg0[2].f, arg0[3].f);
}

void func_00138870(void*);

// Native command 173 (1 arg): func_00138870(a0).
void func_0012AC40(XAudArg* arg0) {
    func_00138870(arg0[0].p);
}

void func_00138808(void*, f32);

// Native command 179 (2 args): func_00138808(a0, a1).
void func_0012AC58(XAudArg* arg0) {
    func_00138808(arg0[0].p, arg0[1].f);
}

// Native command 214 (2 args).
void func_0012AC78(XAudArg* arg0) {
    XAudObj* obj = arg0[0].obj;
    obj->unk_088 &= ~arg0[1].s;
    if (arg0[1].s & 2) {
        obj->unk_3E4 = 0;
    }
}

s32 Light_Add(s32, s32, s32);

// Native command 52 (3 args, returns a value): a0 = Light_Add(a0, a1 | 8, a2).
void NativeCmd_AddLight(XAudArg* arg0) {
    arg0[0].s = Light_Add(arg0[0].s, arg0[1].s | 8, arg0[2].s);
}

void Interpolation_ClearValue(void*);

// Native command 53 (1 arg): Interpolation_ClearValue(a0).
void NativeCmd_ClearInterpolation(XAudArg* arg0) {
    Interpolation_ClearValue(arg0[0].p);
}

void Interpolation_StartVector(void*, void*, f32, void*);

// Native command 201 (3 args): Interpolation_StartVector(a0, a1, a2, NULL).
void NativeCmd_StartInterpolation(XAudArg* arg0) {
    Interpolation_StartVector(arg0[0].p, arg0[1].p, arg0[2].f, NULL);
}

extern s32 D_002C5C60;

// Native command 202 (2 args): Interpolation_StartVector(a0, &D_002C5C60, a1, Interpolation_ClearValue).
void func_0012AD20(XAudArg* arg0) {
    Interpolation_StartVector(arg0[0].p, &D_002C5C60, arg0[1].f, Interpolation_ClearValue);
}

void func_00142058(void*);

// Native command 62 (1 arg): func_00142058(a0).
void func_0012AD50(XAudArg* arg0) {
    func_00142058(arg0[0].p);
}

void func_001421D0(void*, s32);

// Native command 63 (2 args): func_001421D0(a0, a1).
void func_0012AD68(XAudArg* arg0) {
    func_001421D0(arg0[0].p, arg0[1].s);
}

s32 func_00142240(s32);

// Native command 64 (1 arg, returns a value): a0 = func_00142240(a0).
void func_0012AD88(XAudArg* arg0) {
    arg0[0].s = func_00142240(arg0[0].s);
}

void func_001473A8(s32, s32, s32);

// Native command 67 (3 args): func_001473A8(a0, a1, a2).
void func_0012ADB8(XAudArg* arg0) {
    func_001473A8(arg0[0].s, arg0[1].s, arg0[2].s);
}

void func_00147338(void*, s32);

// Native command 68 (2 args): func_00147338(a0, a1).
void func_0012ADE0(XAudArg* arg0) {
    func_00147338(arg0[0].p, arg0[1].s);
}

// Native command 205 (0 args).
void func_0012AE00(void) {
    func_0011D598(65);
    func_001ED878(14);
    func_0023F758();
}

void* func_001EE618(s32, s32, s32);

// Native command 206 (1 arg).
void func_0012AE28(XAudArg* arg0) {
    s32 n = arg0[0].f * 4.0f;
    func_001EE618(0, 0, n);
    func_001EE618(1, 0, n);
}

s32 func_00142480(s32, s32, s32, s32);

// Native command 77 (3 args, returns a value): a0 = func_00142480(a0, a1, 0, a2) + 1.
void func_0012AE78(XAudArg* arg0) {
    arg0[0].s = func_00142480(arg0[0].s, arg0[1].s, 0, arg0[2].s) + 1;
}

typedef struct XAudRay {
    /* 0x00 */ f32 pos[4];
    /* 0x10 */ f32 step[4];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34[3];
    /* 0x40 */ f32 out[4];
    /* 0x50 */ s32 unk_50[12];
} XAudRay __attribute__((aligned(16)));

void func_00116660(XAudRay*);
void func_001166E8(XAudRay*);

// Native command 140 (4 args, returns a value): steps from a0 along a1 (length in its w) in pieces of at most a2 through func_001166E8, stores the end point in a3; a0 = hit bit (probably a collision line check).
void NativeCmd_LineCheck(XAudArg* arg0) {
    XAudRay ray;
    f32 dir[4] __attribute__((aligned(16)));

    func_00116660(&ray);
    ray.unk_24 = arg0[2].f;
    ray.unk_20 = arg0[2].f;
    sceVu0CopyVector(ray.pos, arg0[0].p);
    ray.pos[3] = 1.0f;
    func_001223B0(dir, arg0[1].p);
    do {
        if (arg0[2].f < dir[3]) {
            sceVu0ScaleVector(ray.step, dir, arg0[2].f);
            dir[3] -= arg0[2].f;
        } else {
            sceVu0ScaleVector(ray.step, dir, dir[3]);
            dir[3] = 0.0f;
        }
        ray.step[3] = 1.0f;
        ray.unk_28 = 1;
        func_001166E8(&ray);
        sceVu0CopyVector(ray.pos, ray.out);
    } while (0.0f < dir[3]);
    sceVu0CopyVector(arg0[3].p, ray.out);
    arg0[0].s = ray.unk_30 & 1;
}

s32 func_00142480(s32, s32, s32, s32);

// Native command 148 (4 args, returns a value): a0 = func_00142480(a0, a1, a2, a3) + 1.
void func_0012AFF0(XAudArg* arg0) {
    arg0[0].s = func_00142480(arg0[0].s, arg0[1].s, arg0[2].s, arg0[3].s) + 1;
}

s32 func_0015BD78(s32, s32, s32);

// Native command 90 (2 args, returns a value): a0 = func_0015BD78(a0, a1, 0).
void func_0012B030(XAudArg* arg0) {
    arg0[0].s = func_0015BD78(arg0[0].s, arg0[1].s, 0);
}

void func_0012CC38(void*, s32);

// Native command 101 (2 args): func_0012CC38(a0, a1).
void func_0012B068(XAudArg* arg0) {
    func_0012CC38(arg0[0].p, arg0[1].s);
}

void func_0012CB78(void*, s32);

// Native command 190 (2 args): func_0012CB78(a0, a1).
void func_0012B088(XAudArg* arg0) {
    func_0012CB78(arg0[0].p, arg0[1].s);
}

// Native command 200 (1 arg, returns a value): a0 = func_0012CBC0(a0).
void func_0012B0A8(s32* arg0) {
    *arg0 = func_0012CBC0(*arg0);
}

#ifdef VERSION_FM
extern s32 D_002E31A8[];

// Native command 217 (1 arg).
void fm_func_0012B1A8(XAudArg* arg0) {
    if (arg0[0].s != 0) {
        D_002E31A8[0] |= 4;
    } else {
        D_002E31A8[0] &= ~4;
    }
}
#endif

// Native command 105 (0 args, returns a value): a0 = &D_002DF430.
void func_0012B0D8(s32* arg0) {
    *arg0 = &D_002DF430;
}

// Native command 138 (0 args, returns a value): a0 = &D_002DF43C.
void func_0012B0E8(s32* arg0) {
    *arg0 = &D_002DF43C;
}

extern s32 D_002C5C4C;

// Native command 122 (2 args): func_00146610(a0, a1, D_002C5C4C != 0).
void func_0012B0F8(XAudArg* arg0) {
    func_00146610(arg0[0].s, arg0[1].s, D_002C5C4C != 0);
}

// Native command 155 (1 arg, returns a value): a0 = func_00146740(a0).
void func_0012B120(s32* arg0) {
    *arg0 = func_00146740(*arg0);
}

// Native command 215 (2 args): func_00146610(a0, a1, 1).
void func_0012B150(s32* arg0) {
    func_00146610(arg0[0], arg0[1], 1);
}

// Native command 123 (2 args, returns a value): a0 = func_001C6530(a0, a1).
void func_0012B170(s32* arg0) {
    *arg0 = func_001C6530(arg0[0], arg0[1]);
}

// Native command 192 (0 args, returns a value): a0 = D_002979E8.
void func_0012B1A0(s32* arg0) {
    *arg0 = D_002979E8;
}

#ifdef VERSION_FM
// .data (0x002E2810-0x002E2FB8)
// labels inside the variables below, kept for the code that uses them by name
#define DATA_LABEL(name, base, off) __asm__(".globl " #name "\n" #name " = " #base " + " #off)

void func_00128E18();
void func_00128E20();
void NativeCmd_StartProg();
void NativeCmd_StopProg();
void func_00128DC0();
void NativeCmd_RestartProg();
void func_0012B3A8();
void func_0012B3C0();
void func_0012B408();
void func_00128DF8();
void func_0012B440();
void func_0012B448();
void func_0012B450();
void func_0012B530();
void func_0012B540();
void func_0012B558();
void func_0012B570();
void func_0012B638();
void func_0012B670();
void func_00128DA0();
void func_0012B680();
void func_0012B6F0();
void func_0012B690();
void func_0012B590();
void func_0012B5B0();
void func_0012B5E8();
void func_0012B658();
void func_0012B2C0();
void func_0012B330();
void func_0012B708();
void func_0012B358();
void func_0012B3D8();

// script command table: handler and its argument word (count in the low bits, plus a 0x40000000 flag)
typedef struct {
    void (*func)();
    u32 args;
} XAudCmd;

XAudCmd D_002E2810[226] = {
    {(void (*)())func_00128E18, 0x1},
    {(void (*)())func_00128E20, 0x1},
    {(void (*)())NativeCmd_SinDeg, 0x40000001},
    {(void (*)())NativeCmd_CosDeg, 0x40000001},
    {(void (*)())func_00129328, 0x40000001},
    {(void (*)())func_00128F00, 0x40000000},
    {(void (*)())func_00128FB8, 0x40000001},
    {(void (*)())NativeCmd_AddVector, 0x2},
    {(void (*)())NativeCmd_SubVector, 0x2},
    {(void (*)())func_00129038, 0x1},
    {(void (*)())NativeCmd_RotateVectorY, 0x2},
    {(void (*)())NativeCmd_FaceVector, 0x2},
    {(void (*)())func_00129398, 0x3},
    {(void (*)())func_001293C0, 0x4},
    {(void (*)())func_001293F8, 0x4},
    {(void (*)())func_0012A418, 0x40000003},
    {(void (*)())func_0012A450, 0x2},
    {(void (*)())func_0012A470, 0x1},
    {(void (*)())NativeCmd_AddScaledVector, 0x3},
    {(void (*)())func_00129430, 0x4},
    {(void (*)())NativeCmd_StartProg, 0x40000002},
    {(void (*)())func_0012A488, 0x40000005},
    {(void (*)())func_0012A738, 0x40000000},
    {(void (*)())func_0012A760, 0x40000003},
    {(void (*)())func_00129188, 0x3},
    {(void (*)())func_00128ED8, 0x40000000},
    {(void (*)())func_0012A4C8, 0x2},
    {(void (*)())func_00129458, 0x40000004},
    {(void (*)())NativeCmd_StopProg, 0x1},
    {(void (*)())func_0012A4E8, 0x2},
    {(void (*)())func_00129490, 0x40000001},
    {(void (*)())NativeCmd_RotateVectorZ, 0x2},
    {(void (*)())func_001294C0, 0x2},
    {(void (*)())func_00128DC0, 0x4},
    {(void (*)())NativeCmd_RestartProg, 0x40000003},
    {(void (*)())func_001294E0, 0x40000001},
    {(void (*)())NativeCmd_SetAngleFromVector, 0x2},
    {(void (*)())func_00129540, 0x40000001},
    {(void (*)())func_0012A900, 0x40000006},
    {(void (*)())func_0012A528, 0x2},
    {(void (*)())func_00129570, 0x40000003},
    {(void (*)())func_0012A968, 0x2},
    {(void (*)())func_0012A9B8, 0x2},
    {(void (*)())func_001295A8, 0x40000002},
    {(void (*)())func_001295D8, 0x40000002},
    {(void (*)())func_0012AA08, 0x2},
    {(void (*)())func_00128F10, 0x40000001},
    {(void (*)())func_00129608, 0x40000002},
    {(void (*)())func_0012AA28, 0x40000004},
    {(void (*)())func_0012AA60, 0x2},
    {(void (*)())func_00129638, 0x3},
    {(void (*)())func_00129660, 0x40000001},
    {(void (*)())NativeCmd_AddLight, 0x40000003},
    {(void (*)())NativeCmd_ClearInterpolation, 0x1},
    {(void (*)())func_001296A8, 0x1},
    {(void (*)())NativeCmd_SetAngles16, 0x2},
    {(void (*)())func_0012A5F0, 0x40000000},
    {(void (*)())func_0012AA80, 0x40000002},
    {NULL, 0x0},
    {(void (*)())func_001296B0, 0x2},
    {(void (*)())func_0012A7A0, 0x40000002},
    {(void (*)())func_0012A628, 0x2},
    {(void (*)())func_0012AD50, 0x1},
    {(void (*)())func_0012AD68, 0x2},
    {(void (*)())func_0012AD88, 0x40000001},
    {(void (*)())func_001296D0, 0x40000002},
    {(void (*)())func_00128F40, 0x1},
    {(void (*)())func_0012ADB8, 0x3},
    {(void (*)())func_0012ADE0, 0x2},
    {(void (*)())func_00129700, 0x40000001},
    {(void (*)())func_0012AAB0, 0x40000001},
    {(void (*)())func_0012AAE0, 0x40000001},
    {(void (*)())func_00128F48, 0x1},
    {(void (*)())func_00128F50, 0x1},
    {(void (*)())func_0012A648, 0x40000004},
    {(void (*)())func_00129718, 0x40000002},
    {(void (*)())func_0012A7D0, 0x2},
    {(void (*)())func_0012AE78, 0x40000003},
    {(void (*)())func_00129748, 0x40000004},
    {(void (*)())func_0012AB10, 0x2},
    {(void (*)())func_0012AB60, 0x40000002},
    {(void (*)())func_0012AB90, 0x40000003},
    {(void (*)())func_00129780, 0x4},
    {(void (*)())func_001297A8, 0x2},
    {(void (*)())func_001297C0, 0x40000002},
    {(void (*)())func_001297F0, 0x40000001},
    {(void (*)())func_00129820, 0x2},
    {(void (*)())func_00129840, 0x2},
    {(void (*)())func_00129848, 0x2},
    {(void (*)())func_00129868, 0x40000001},
    {(void (*)())func_0012B030, 0x40000002},
    {(void (*)())func_00129878, 0x40000002},
    {(void (*)())func_001298A8, 0x40000002},
    {(void (*)())NativeCmd_ScaleVector, 0x2},
    {(void (*)())func_0012ABC8, 0x40000005},
    {(void (*)())func_0012A7F0, 0x2},
    {(void (*)())func_001298D8, 0x2},
    {(void (*)())func_0012A680, 0x40000001},
    {(void (*)())func_00129910, 0x3},
    {(void (*)())func_00129938, 0x3},
    {(void (*)())func_00129200, 0x40000002},
    {(void (*)())func_0012B068, 0x2},
    {(void (*)())func_0012AC08, 0x40000004},
    {(void (*)())func_0012A6B8, 0x2},
    {(void (*)())func_00129960, 0x40000001},
    {(void (*)())func_0012B0D8, 0x40000000},
    {(void (*)())func_001299B8, 0x40000004},
    {(void (*)())func_001299F0, 0x3},
    {(void (*)())func_00129A18, 0x5},
    {(void (*)())func_00129A48, 0x40000003},
    {(void (*)())func_00129A80, 0x4},
    {(void (*)())NativeCmd_SetFlags1CC, 0x2},
    {(void (*)())NativeCmd_ClearFlags1CC, 0x2},
    {(void (*)())func_00129AE8, 0x2},
    {(void (*)())func_00129B28, 0x40000001},
    {(void (*)())func_00129B40, 0x4},
    {(void (*)())NativeCmd_SetFlags3A4, 0x4},
    {(void (*)())NativeCmd_ClearFlags3A4, 0x4},
    {(void (*)())func_00129C08, 0x2},
    {(void (*)())func_00129C30, 0x3},
    {(void (*)())func_00129C58, 0x40000001},
    {(void (*)())func_00129C88, 0x2},
    {(void (*)())func_0012B0F8, 0x2},
    {(void (*)())func_0012B170, 0x40000002},
    {(void (*)())func_00129CA8, 0x2},
    {(void (*)())func_00129CC0, 0x2},
    {(void (*)())func_0012A6D8, 0x3},
    {(void (*)())func_00129CF8, 0x2},
    {(void (*)())func_00129D18, 0x2},
    {(void (*)())func_00129D38, 0x1},
    {(void (*)())func_0012B3A8, 0x1},
    {(void (*)())func_0012B3C0, 0x1},
    {(void (*)())func_00129D58, 0x40000001},
    {(void (*)())func_00129D70, 0x3},
    {(void (*)())func_00129230, 0x4},
    {(void (*)())func_00129D98, 0x2},
    {(void (*)())func_00129DD8, 0x2},
    {(void (*)())func_00129DF8, 0x2},
    {(void (*)())func_0012B0E8, 0x40000000},
    {(void (*)())func_00129E18, 0x40000001},
    {(void (*)())NativeCmd_LineCheck, 0x40000004},
    {(void (*)())func_00129E78, 0x40000001},
    {(void (*)())func_0012B408, 0x40000001},
    {(void (*)())func_00129EA8, 0x2},
    {(void (*)())NativeCmd_RotateVectorXYZ, 0x2},
    {(void (*)())func_0012A700, 0x2},
    {(void (*)())func_00129F20, 0x2},
    {(void (*)())func_00129F40, 0x40000001},
    {(void (*)())func_0012AFF0, 0x40000004},
    {(void (*)())NativeCmd_DegToRad, 0x40000001},
    {(void (*)())func_00128DF8, 0x2},
    {(void (*)())func_0012B440, 0x4},
    {(void (*)())func_0012B448, 0x5},
    {(void (*)())func_00129F60, 0x40000003},
    {(void (*)())func_0012A720, 0x2},
    {(void (*)())func_0012B120, 0x40000001},
    {(void (*)())func_00129F88, 0x40000001},
    {(void (*)())func_00129FB8, 0x1},
    {(void (*)())func_00129FD0, 0x40000002},
    {(void (*)())func_0012A818, 0x2},
    {(void (*)())func_0012A838, 0x40000003},
    {(void (*)())func_0012B450, 0x1},
    {(void (*)())func_0012B530, 0x1},
    {(void (*)())func_0012A000, 0x40000001},
    {(void (*)())func_0012B540, 0x1},
    {(void (*)())func_0012B558, 0x1},
    {(void (*)())func_00128FA8, 0x1},
    {(void (*)())func_0012B570, 0x2},
    {(void (*)())func_0012A018, 0x2},
    {(void (*)())func_0012A038, 0x2},
    {(void (*)())func_0012A078, 0x40000001},
    {(void (*)())func_0012B638, 0x1},
    {(void (*)())func_0012A098, 0x40000001},
    {(void (*)())func_0012AC40, 0x1},
    {(void (*)())func_0012B670, 0x40000000},
    {(void (*)())func_0012A888, 0x1},
    {(void (*)())func_0012A0C8, 0x40000001},
    {(void (*)())fm_func_00129330, 0x1},
    {(void (*)())func_00128DA0, 0x0},
    {(void (*)())func_0012AC58, 0x2},
    {(void (*)())func_0012A0E0, 0x2},
    {(void (*)())func_0012A0F8, 0x40000001},
    {(void (*)())func_0012A128, 0x1},
    {(void (*)())func_0012A140, 0x3},
    {(void (*)())func_0012A168, 0x1},
    {(void (*)())func_0012B680, 0x40000000},
    {(void (*)())func_0012B6F0, 0x1},
    {(void (*)())func_0012A1B8, 0x40000001},
    {(void (*)())func_0012A8E8, 0x40000001},
    {(void (*)())func_0012A1C8, 0x40000001},
    {(void (*)())func_0012B088, 0x2},
    {(void (*)())func_0012B690, 0x40000000},
    {(void (*)())func_0012B1A0, 0x40000000},
    {(void (*)())func_0012B590, 0x2},
    {(void (*)())func_0012B5B0, 0x2},
    {(void (*)())func_0012B5E8, 0x2},
    {(void (*)())func_0012B658, 0x0},
    {(void (*)())func_0012B2C0, 0x0},
    {(void (*)())func_0012B330, 0x40000000},
    {(void (*)())func_0012A1F8, 0x40000001},
    {(void (*)())func_0012B0A8, 0x40000001},
    {(void (*)())NativeCmd_StartInterpolation, 0x3},
    {(void (*)())func_0012AD20, 0x2},
    {(void (*)())func_0012A210, 0x2},
    {(void (*)())func_0012A270, 0x40000001},
    {(void (*)())func_0012AE00, 0x0},
    {(void (*)())func_0012AE28, 0x1},
    {(void (*)())func_0012A280, 0x1},
    {(void (*)())func_0012A308, 0x1},
    {(void (*)())func_0012A328, 0x40000003},
    {(void (*)())func_0012A360, 0x1},
    {(void (*)())func_0012B708, 0x40000001},
    {(void (*)())fm_func_0012A400, 0x1},
    {(void (*)())func_0012A8A0, 0x2},
    {(void (*)())func_0012AC78, 0x2},
    {(void (*)())func_0012B150, 0x2},
    {(void (*)())func_0012B358, 0x1},
    {(void (*)())fm_func_0012B1A8, 0x1},
    {(void (*)())func_0012A3D0, 0x40000001},
    {(void (*)())fm_func_00128F70, 0x40000000},
    {(void (*)())fm_func_0012A498, 0x2},
    {(void (*)())fm_func_00128F98, 0x40000000},
    {(void (*)())func_0012B3D8, 0x40000001},
    {(void (*)())func_00129320, 0x2},
    {(void (*)())fm_func_00128FB0, 0x40000000},
    {(void (*)())fm_func_0012A4C8, 0x40000002},
};
extern u8 D_00362340[];
void* D_002E2F20[2] = {D_002E2810, D_00362340};
s32 D_002DF430_a[35] __asm__("D_002DF430") = {0};
DATA_LABEL(D_002DF43C, D_002DF430, 0xC);
#endif
