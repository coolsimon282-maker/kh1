#include "common.h"

#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 unk2;
} VKeBornRnd5;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char pad_06[6];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ char pad_0F[1];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} PKeBornRnd5;

void KeBornRnd4_Born();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd5* p, void* func, VKeBornRnd5* v, s16 a, u8 b, u8 c);

void pppKeBornRnd5Calc(pppPObject* pobj, PKeBornRnd5* p, pppCtrlTable* ctbl) {
    VKeBornRnd5* v;

    if (ppvEmptyLoop) {
        return;
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->unk_0D == 0) {
        return;
    }
    v = (VKeBornRnd5*)&pobj->val[ctbl->useVal[0]];
    if (v->unk2 == 0) {
        v->unk2 = p->unk_0D;
        if (p->unk_10 == -1) {
            return;
        }
        if (p->unk_18 == -1) {
            return;
        }
        KeBornRnd2(pobj, p, KeBornRnd4_Born, v, p->unk_04, p->unk_0E, p->unk_0C);
    }
    v->unk2--;
}

void pppKeBornRnd5Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeBornRnd5* v = (VKeBornRnd5*)&pobj->val[ctbl->useVal[0]];

    v->unk0 = 0;
    v->unk2 = 0;
}

double atan(double);
// atan2 of (v[1], v[0]) written out with atan and quadrant fixes.
s32 KeBornRnd5_Atan2(f32* v, f32* out) {
    f32 x = v[0];
    f32 y = v[1];
    f32 r = x * y;

    if (r > 0.0f) {
        r = (x > 0.0f) ? 0.0f : -3.1415926f;
        r += atan(y / x);
    } else if (r < 0.0f) {
        r = (y > 0.0f) ? 1.5707963f : -1.5707963f;
        r -= atan(x / y);
    } else if (x != 0.0f) {
        r = (x > 0.0f) ? 0.0f : 3.1415926f;
    } else {
        if (y == 0.0f) {
            return 0;
        }
        r = -1.5707963f;
        if (y > 0.0f) {
            r = 1.5707963f;
        }
    }
    *out = r;
    return 1;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ char pad_04[8];
    /* 0x0C */ s32 pdtn;
    /* 0x10 */ s32 posOff;
    /* 0x14 */ char pad_14[4];
    /* 0x18 */ s32 angOff;
} PKeBornRnd5Cb;

pppPObject* pppCreatePObject(ppvmng* mng, void* pdt);
void op_vec_copy_xyz(void* dst, void* src);
f32 op_sqrt(f32);

// KeBornRnd5's particle creation at point sv with an angle.
void KeBornRnd5_Born(pppPObject* pobj, PKeBornRnd5Cb* p, s16* sv) {
    pppPObject* born;
    void* pdt;
    s32* ang;
    f32 x;
    f32 y;
    sceVu0FVECTOR t;
    f32 r;

    born = NULL;
    pdt = (char*)ppvMng->unk_80 + p->pdtn * 16;
    if (pdt != NULL) {
        born = pppCreatePObject(ppvMng, pdt);
        born->ppobj = pobj;
    }
    t[0] = sv[0];
    t[1] = sv[1];
    t[2] = sv[2];
    t[3] = 1.0f;
    op_vec_copy_xyz(&born->val[p->posOff], t);
    y = t[1];
    x = t[0];
    ang = (s32*)&born->val[p->angOff];
    t[0] = -y;
    t[1] = x;
    if (KeBornRnd5_Atan2(t, &r)) {
        ang[2] = r * 32768.0f / 3.141592654;
    }
    t[0] = op_sqrt(y * y + x * x);
    t[1] = -t[2];
    if (KeBornRnd5_Atan2(t, &r)) {
        ang[0] = r * 32768.0f / 3.141592654;
    }
    ang[1] = 0;
}


