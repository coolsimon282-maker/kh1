#include "common.h"
#include "sifdev.h"
#include "ppp/draw.h"

void op_oef2_set(void*, void*);

void opc(void) {
}

void opc2(void) {
}

void opc3(void) {
}

void op_init_global(void) {
}

void ops_init_spr(void) {
    spr_a[0] = 0x70000000;
    spr_rev_a[0] = 0x70004000;
    spr_index = 0;
    spr_rev_index = 0;
}

void op_num_info(void) {
}

s32 op_spr_alloc(s32 size) {
    s32 i = spr_index;
    s32 addr = spr_a[i];

    i++;
    spr_index = i;
    spr_a[i] = addr + size;
    return addr;
}

s32 op_spr_rev_alloc(s32 size) {
    s32 i = spr_rev_index;
    s32 addr = spr_rev_a[i];

    i++;
    spr_rev_index = i;
    spr_rev_a[i] = addr;
    return addr - size;
}

// todo: next two are being compiled as unsigned despite data entries being signed
void op_spr_free(void) {
    s32 i = spr_index;

    spr_index = i - 1;
}
// void op_spr_free(void) {
//     spr_index--;
// }

void op_spr_rev_free(void) {
    s32 i = spr_rev_index;

    spr_rev_index = i - 1;
}
// void op_spr_rev_free(void) {
//     spr_rev_index--;
// }

s32 op_spr_rev_check(s32 arg0) {
    if ((s32)spr_a + arg0 <= spr_rev_a[spr_rev_index + 1]) {
        return 0;
    }
    return -1;
}

s32 op_spr_check(s32 arg0) {
    if (spr_a[spr_index + 1] <= (s32)spr_rev_a - arg0) {
        return 0;
    }
    return -1;
}

extern char D_00489AD8[];
int printf(const char*, ...);
void exit(int);

s32 op_file_read(char* name, void* dst) {
    char buf[0x400];
    s32 fd;
    s32 size;

    fd = sceOpen(name, SCE_RDONLY);
    if (fd < 0) {
        printf(D_00489AD8, name);
        exit(1);
    }
    size = sceLseek(fd, 0, SCE_SEEK_END);
    sceLseek(fd, 0, SCE_SEEK_SET);
    if (size != sceRead(fd, dst, size)) {
        size = 0;
    }
    sceClose(fd);
    FlushCache(0);
    return size;
}

s32 op_file_size(char* name) {
    char buf[0x400];
    s32 fd;
    s32 size;

    fd = sceOpen(name, SCE_RDONLY);
    if (fd < 0) {
        printf(D_00489AD8, name);
        exit(1);
    }
    size = sceLseek(fd, 0, SCE_SEEK_END);
    sceClose(fd);
    return size;
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_set);

void op_oef2_set2(u8* p) {
    op_oef2_set(p, p + *(s32*)(p + 0x3C));
}

void op_oef2_set2_16(u8* p) {
    p += 0x10;
    op_oef2_set(p, p + *(s32*)(p + 0x3C));
}

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_oef2_a_get);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_random);

INCLUDE_ASM("asm/nonmatchings/ppp/draw/global", op_random_p);

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/global", D_00489AD8);

INCLUDE_RODATA("asm/nonmatchings/ppp/draw/global", D_00489AF0);
