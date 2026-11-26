#ifndef XPEANUT_H
#define XPEANUT_H

#include "common.h"

void func_00125010(f32);
#define Camera_SetFov func_00125010 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
void func_00125088(f32);
#define Camera_PushFov func_00125088 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
void func_001250B0(void);
#define Camera_PopFov func_001250B0 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
void func_001250D0(f32*, f32*);
#define Vec_YawBetween func_001250D0 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
void* func_001255F8(void);

extern sceVu0FMATRIX D_002DEC20;
#define worldScreenMatrix D_002DEC20 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern sceVu0FMATRIX D_002DEC60;
#define viewMatrix D_002DEC60 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern sceVu0FMATRIX D_002DECA0;
#define screenMatrix D_002DECA0 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern sceVu0FVECTOR D_002DECE0;
#define cameraEye D_002DECE0 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern sceVu0FVECTOR D_002DECF0;
#define cameraTarget D_002DECF0 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern f32 D_002DED00;
#define cameraFov D_002DED00 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern f32 D_002DED04;
#define cameraRoll D_002DED04 // name in config/fm/symbol_addrs.txt; old identifier kept: xhumungus.c includes this header (rule F1)
extern u32 D_002DED08;

#endif // XPEANUT_H
