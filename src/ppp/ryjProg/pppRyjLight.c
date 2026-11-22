#include "ppp.h"

/// This file's functions are empty in the 2.5 prototype

typedef struct {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 pos[4];
    /* 0x20 */ f32 dir[4];
    /* 0x30 */ f32 col[4];
} RyjLight;

typedef struct {
    RyjLight* unk_00;
} VRyjLight;

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ f32 dir[3];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u8 type;
    /* 0x15 */ u8 flag0;
    /* 0x16 */ u8 flag1;
    /* 0x17 */ u8 flag2;
} PRyjLight;

extern f32 D_003701D0[4];
RyjLight* func_00122AF8(u8 type, s32 flags, s32 arg2);

void pppRyjLightCalc(pppPObject* pobj, PRyjLight* p, pppCtrlTable* ctbl) {
    VRyjLight* v = (VRyjLight*)&pobj->val[ctbl->useVal[2]];
    RyjLight* light;
    f32* pos;
    u8* col;
    s32 flags;

    flags = 0;
    if (p->flag0) {
        flags = 1;
    }
    if (p->flag1) {
        flags |= 2;
    }
    if (p->flag2) {
        flags |= 4;
    }
    light = v->unk_00;
    if (light == NULL) {
        v->unk_00 = func_00122AF8(p->type, flags, 0);
        if (v->unk_00 == NULL) {
            return;
        }
        light = v->unk_00;
    }
    pos = (f32*)&pobj->val[ctbl->useVal[1]];
    col = (u8*)&pobj->val[ctbl->useVal[0]];
    light->pos[0] = pos[0] + D_003701D0[0];
    light->pos[1] = pos[1] + D_003701D0[1];
    light->pos[2] = pos[2] + D_003701D0[2];
    light->pos[3] = 1.0f;
    light->dir[0] = p->dir[0];
    light->dir[1] = p->dir[1];
    light->dir[2] = p->dir[2];
    light->dir[3] = 1.0f;
    light->col[0] = col[8];
    light->col[1] = col[9];
    light->col[2] = col[10];
    light->col[3] = col[11];
    sceVu0ScaleVector(light->col, light->col, 1.0f / 255.0f);
    light->unk_0C = p->unk_10;
}

void pppRyjLightCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VRyjLight*)&pobj->val[ctbl->useVal[2]])->unk_00 = NULL;
}

void pppRyjLightDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjLight* ryjLight = (VRyjLight*)&pobj->val[ctbl->useVal[2]];

    if (ryjLight->unk_00 != NULL) {
        func_00122B70(ryjLight->unk_00);
        ryjLight->unk_00 = NULL;
    }
}
