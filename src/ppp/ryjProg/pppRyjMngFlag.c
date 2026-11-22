#include "ppp.h"

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ u8 bFollowCam;
    /* 0x5 */ u8 bStop;
    /* 0x6 */ u8 bDrawPriority;
} PRyjMngFlag;

void pppRyjMngFlagCalc(pppPObject* pobj, PRyjMngFlag* p, pppCtrlTable* ctbl) {
    if (p->cdt.time == pobj->time) {
        ppvMng->followCam = p->bFollowCam;
        ppvMng->stop = p->bStop;
        ppvMng->drawPriority = p->bDrawPriority;
    }
}

typedef struct {
    /* 0x00 */ f32 pos[4] __attribute__((aligned(16)));
    /* 0x10 */ s32 unk_10[2];
    /* 0x18 */ u64 flags;
} RyjSortEnt; // size = 0x20

extern sceVu0FVECTOR D_002DECE0;
extern RyjSortEnt D_0035C710[256];
extern RyjSortEnt* D_0061E310[256];
extern s32 D_0061E710;

// FM's ppp code behaves as if compiled without strict aliasing (the count is reloaded after the float
// stores); reading the count through a union gives the same alias-everything access.
typedef union {
    s32 v;
} RyjCount;

#define SORT_COUNT (((RyjCount*)&D_0061E710)->v)

// quicksort of D_0061E310[left..right] by pos[3], largest first
void func_0019F698(s32 left, s32 right) {
    s32 i;
    s32 j;
    f32 pivot;
    RyjSortEnt* t;

    i = left;
    j = right;
    pivot = D_0061E310[(left + right) / 2]->pos[3];
    while (1) {
        while (pivot < D_0061E310[i]->pos[3]) {
            i++;
        }
        while (D_0061E310[j]->pos[3] < pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        t = D_0061E310[i];
        D_0061E310[i] = D_0061E310[j];
        D_0061E310[j] = t;
        i++;
        j--;
    }
    if (left < i - 1) {
        func_0019F698(left, i - 1);
    }
    if (j + 1 < right) {
        func_0019F698(j + 1, right);
    }
}

void func_0019F810(void) {
    s32 i;
    RyjSortEnt* e;
    f32 v[4] __attribute__((aligned(16)));

    e = D_0035C710;
    SORT_COUNT = 0;
    for (i = 255; i >= 0; i--, e++) {
        if (e->flags & 0x100) {
            if (!(e->flags & 0x200)) {
                sceVu0SubVector(v, D_002DECE0, e->pos);
                sceVu0MulVector(v, v, v);
                D_0061E310[SORT_COUNT] = e;
                SORT_COUNT++;
                e->pos[3] = v[0] + v[1] + v[2];
            }
        }
    }
    if (SORT_COUNT >= 2) {
        func_0019F698(0, SORT_COUNT - 1);
    }
    for (i = 0; i < SORT_COUNT; i++) {
        D_0061E310[i]->pos[3] = 1.0f;
    }
}
