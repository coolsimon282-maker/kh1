#ifndef XPEANUT_H
#define XPEANUT_H

#include "common.h"

void Camera_SetFov(f32);
void Camera_PushFov(f32);
void Camera_PopFov(void);
void Vec_YawBetween(f32*, f32*);
void* func_001255F8(void);

extern sceVu0FMATRIX worldScreenMatrix;
extern sceVu0FMATRIX viewMatrix;
extern sceVu0FMATRIX screenMatrix;
extern sceVu0FVECTOR cameraEye;
extern sceVu0FVECTOR cameraTarget;
extern f32 cameraFov;
extern f32 cameraRoll;
extern u32 D_002DED08;

#endif // XPEANUT_H
