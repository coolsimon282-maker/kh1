extern s32* D_002A0508;
extern s32 D_002A04F8;
extern s32 D_002A04FC;
extern s32 D_002A0500;
extern s32 D_002A0504;
extern s32 D_002A0510;
extern s32 D_002A0518;
extern s32 D_002979E0;
extern s32 D_002979E4;
extern s32 D_002979E8;
extern s32 D_002979EC;
extern s32 D_002B9340;
extern s32 D_0048DE98;
extern s32 D_0048DE9C;
extern void func_00106CE8(s32, s32);
extern void func_00105068(s32, s32);
extern void func_00108B48(s32, s32, s32);
extern void func_00100648(void);
extern void func_00100690(void);
extern void func_00177908(s32);
extern void func_00105B88(s32);

void func_001011E0(s32 arg0) {
    s32* base = D_002A0508;
    s32 count;
    s32* ptr;
    char stack[64];

    D_002A04FC = (s32)base + base[4];
    D_0048DE98 = (s32)base + base[8];
    D_002A0504 = base[7];
    D_0048DE9C = (s32)base + base[0xa];
    D_002A0500 = (s32)base + base[6];
    D_002A0518 = (s32)base + base[0xc];
    ptr = base + 0xe;
    count = base[0];

    func_00106CE8(D_002A0500, D_002A0504);
    func_00105068(D_002A04FC, 1);
    func_00108B48(D_0048DE98, 0, 4);
    func_00100648();
    func_00108B48(D_0048DE9C, 1, 4);
    func_00100690();

    D_002979E0 = 0;
    D_002979E4 = 0;
    D_002979E8 = 0;
    D_002979EC = 0;

    if (count > 5) {
        if (ptr[1] != 0) {
            D_002979E0 = (s32)D_002A0508 + *ptr;
            func_00177908(D_002979E0);
        }
        ptr = base + 0x10;

        if (ptr[1] != 0) {
            D_002979E4 = (s32)D_002A0508 + *ptr;
        }

        if (count > 7) {
            ptr = base + 0x12;

            if (ptr[1] != 0) {
                D_002979E8 = (s32)D_002A0508 + *ptr;
                func_00177908(D_002979E8);
            }
            ptr = base + 0x14;

            if (ptr[1] != 0) {
                D_002979EC = (s32)D_002A0508 + *ptr;
            }
            ptr = base + 0x16;
        }

        if (count > 9) {
            if (ptr[1] != 0) {
                D_002A04F8 = (s32)D_002A0508 + *ptr;
                func_00105B88(D_002A04F8);
            }
        }
    }

    D_002B9340 = (s32)D_002A0508 + arg0;

    if (D_002B930C == 0) {
        strcpy(stack, worldBinImgFile);
        strcat(stack, D_00486970);
        D_002A050C = (s32)D_002A0508 + arg0;
        D_002A050C = func_001133E0(D_002A050C, 0x80);
        func_00120590(stack, D_002A050C, func_001011B8, 0);
    } else {
        func_001011B8(D_002A0510, 0, D_002A050C);
    }
}
