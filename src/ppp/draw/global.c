#include "common.h"
#include "sifdev.h"
#include "ppp/draw.h"

#ifdef VERSION_FM
// .data (0x00372EA0-0x00373000)
s8 spr_index = 0;
s32 spr_a[32] = {0};
s8 spr_rev_index = 0;
s32 spr_rev_a[32] = {0};
// table nothing refers to by name (up to ppp/draw/md's .data)
s32 D_00372FB0[20] = {0x14, 0x1C, 0x20, 0x28, 0x18, 0x20, 0x28, 0x30, 0, 0, 0, 0, 0, 0, 0, 0, 0x1C};
#endif

void op_oef2_set(void*, void*);

#ifdef VERSION_FM
int printf(const char*, ...);
// The four "error !" strings at the start of this file's .rodata have no code using them: the checks that printed
// them were folded away at compile time (never true), but gcc had already put out their strings. An if (0) keeps that.
#define SPR_ERROR(msg) \
    if (0) {           \
        printf(msg);   \
    }
#else
#define SPR_ERROR(msg)
#endif

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
    SPR_ERROR("op_spr_alloc error !\n");
    return addr;
}

s32 op_spr_rev_alloc(s32 size) {
    s32 i = spr_rev_index;
    s32 addr = spr_rev_a[i];

    i++;
    spr_rev_index = i;
    spr_rev_a[i] = addr;
    SPR_ERROR("op_spr_rev_alloc error !\n");
    return addr - size;
}

// todo: next two are being compiled as unsigned despite data entries being signed
void op_spr_free(void) {
    s32 i = spr_index;

    spr_index = i - 1;
    SPR_ERROR("op_spr_free error !\n");
}
// void op_spr_free(void) {
//     spr_index--;
// }

void op_spr_rev_free(void) {
    s32 i = spr_rev_index;

    spr_rev_index = i - 1;
    SPR_ERROR("op_spr_rev_free error !\n");
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

extern char D_00489AF0[];
/* the first five loops store through a named temporary, the last one directly: that is what gives the target's registers */
void exit(int);
int printf(const char*, ...);
void op_oef2_set(void* a0, void* a1) {
    u8* o = a0;
    u8* h = a1;
    s32 val;
    s32* src;
    u8* dst;
    s32 i;

    if ((u32)h & 0xF) {
        printf(D_00489AF0);
        exit(1);
    }
    if (*(u16*)(h + 0x42) != 0) {
        src = (s32*)(*(s32*)(h + 0x4) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0x4) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x42); i++, src++, dst += 0x4) {
            if (*src != 0) {
                val = *src + (s32)h;
                *(s32*)(dst + 0x0) = val;
            }
        }
    }
    if (*(u16*)(h + 0x44) != 0) {
        src = (s32*)(*(s32*)(h + 0x8) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0x8) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x44); i++, src++, dst += 0x20) {
            if (*src != 0) {
                val = *src + (s32)h;
                *(s32*)(dst + 0x14) = val;
            }
        }
    }
    if (*(u16*)(h + 0x46) != 0) {
        src = (s32*)(*(s32*)(h + 0xC) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0xC) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x46); i++, src++, dst += 0x10) {
            if (*src != 0) {
                val = *src + (s32)h;
                *(s32*)(dst + 0x4) = val;
            }
        }
    }
    if (*(u16*)(h + 0x48) != 0) {
        src = (s32*)(*(s32*)(h + 0x10) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0x10) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x48); i++, src++, dst += 0x4) {
            if (*src != 0) {
                val = *src + (s32)h;
                *(s32*)(dst + 0x0) = val;
            }
        }
    }
    if (*(u16*)(h + 0x50) != 0) {
        src = (s32*)(*(s32*)(h + 0x20) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0x20) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x50); i++, src++, dst += 0x4) {
            if (*src != 0) {
                val = *src + (s32)h;
                *(s32*)(dst + 0x0) = val;
            }
        }
    }
    if (*(u16*)(h + 0x52) != 0) {
        src = (s32*)(*(s32*)(h + 0x24) + (u32)h);
        dst = (u8*)(*(s32*)(o + 0x24) + (u32)o);
        for (i = 0; i < *(u16*)(h + 0x52); i++, src++, dst += 0x4) {
            if (*src != 0) {
                *(s32*)(dst + 0x0) = *src + (s32)h;
            }
        }
    }
}

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
