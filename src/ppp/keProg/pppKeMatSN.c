#include "ppp/pppUtil.h"

typedef struct {
    /* 0x00 */ char unk_00[0x40];
    /* 0x40 */ sceVu0FMATRIX mat;
    /* 0x80 */ pppIVECTOR ang;
} VKeMatSN;

extern void* ppvlpCMatrix;
extern sceVu0FVECTOR D_003727B0;

void pppKeMatSNCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    VKeMatSN* v0 = (VKeMatSN*)&pobj->val[ctbl->useVal[0]];
    pppIVECTOR* v1 = (pppIVECTOR*)&pobj->val[ctbl->useVal[1]];
    pppIVECTOR a;

    ppvlpCMatrix = v0;
    a = v0->ang;
    v0->ang.x = v1->x;
    a.x -= v0->ang.x;
    v0->ang.y = v1->y;
    a.y -= v0->ang.y;
    v0->ang.z = v1->z;
    a.z -= v0->ang.z;
    pppGetRotMatrixXYZ(v0->mat, &a);
    *(u_long128*)v0->mat[3] = *(u_long128*)D_003727B0;
}

void pppKeMatSNCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeMatSN* v = (VKeMatSN*)&pobj->val[ctbl->useVal[0]];

    v->ang.x = 0;
    v->ang.y = 0;
    v->ang.z = 0;
}
