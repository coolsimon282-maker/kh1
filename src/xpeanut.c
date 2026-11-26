/**
 * Camera: field of view (cameraFov, degrees) and the projection distance 256 / tan(fov / 2) (projDistance), eye /
 * target / roll / up vector, and the per-frame view, screen and world-to-screen matrices. Each frame's matrices are kept
 * twice (D_004FAE10 / D_004FAE90 / D_004FAF10, indexed by the frame buffer number D_002C1EA0) so the previous frame's can
 * be used again.
 */
#include "common.h"
#include "xpeanut.h"

#include "math.h"

#ifdef VERSION_FM
// jump table of the first function (func_001251B0.s)
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487038);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487040);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487048);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487050);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487058);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487060);
INCLUDE_RODATA("asm/nonmatchings/xpeanut", D_00487068);
#endif

extern s32 D_002C1EA0;

extern sceVu0FMATRIX D_002B8370;

// .data
sceVu0FVECTOR cameraUp = {0.0f, 1.0f, 0.0f, 1.0f};
sceVu0FMATRIX worldScreenMatrix = {};
sceVu0FMATRIX viewMatrix = {};
sceVu0FMATRIX screenMatrix = {};
sceVu0FVECTOR cameraEye = {};
sceVu0FVECTOR cameraTarget = {};
f32 cameraFov = 0.0f;
f32 cameraRoll = 0.0f;
u32 D_002DED08 = 0;
s32* D_002DED0C = NULL;

// .bss
extern f32 projDistance;
extern sceVu0FMATRIX D_004FAE10[];
extern sceVu0FMATRIX D_004FAE90[];
extern sceVu0FMATRIX D_004FAF10[];
extern f32 D_004FAF90;
extern f32 savedFov;

extern void CameraMats_SaveAndRebuild(f32);
extern f32 Angle_Wrap(f32);
void Mat_AxisAngle(f32, sceVu0FVECTOR, sceVu0FMATRIX);

// Sets the field of view (degrees) and projDistance = 256 / tan(fov / 2).
void Camera_SetFov(f32 arg0) {
    cameraFov = arg0;
    projDistance = 256.0f / tanf(((arg0 * 0.5f) / 180.0f) * PI);
}

// Saves the current field of view in savedFov, then sets a new one.
void Camera_PushFov(f32 arg0) {
    savedFov = cameraFov;
    Camera_SetFov(arg0);
}

// Sets the field of view back to savedFov.
void Camera_PopFov(void) {
    Camera_SetFov(savedFov);
}

// atan2 of (a - b) in x and z: the yaw from b to a (declared void, the result is left in $f0 for callers that read it as f32).
void Vec_YawBetween(f32* arg0, f32* arg1) {
    atan2f(arg0[0] - arg1[0], arg0[2] - arg1[2]);
}

// Rotates arg2 about Y by -cameraRoll, negates x, sets w = arg1, then rotates about Y by arg0 (into arg3); probably a camera-relative direction.
void func_00125100(f32 arg0, f32 arg1, f32* arg2, f32* arg3) {
    sceVu0FMATRIX m;

    sceVu0RotMatrixY(m, D_002C1E20, -Angle_Wrap(cameraRoll));
    sceVu0ApplyMatrix(arg3, m, arg2);
    arg3[0] = -arg3[0];
    arg3[3] = arg1;
    sceVu0RotMatrixY(m, D_002C1E20, arg0);
    sceVu0ApplyMatrix(arg3, m, arg3);
}

INCLUDE_ASM("asm/nonmatchings/xpeanut", func_001251B0);

extern f32 D_004F77E0;
void func_001109A8(void);

// builds this frame's camera: view from cameraEye towards cameraTarget, rolled by cameraRoll
s32 Camera_BuildFrame(void) {
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FMATRIX m;

    CameraMats_SaveAndRebuild(projDistance);
    sceVu0SubVector(v0, cameraTarget, cameraEye);
    sceVu0Normalize(v0, v0);
    Mat_AxisAngle(Angle_Wrap(cameraRoll), v0, m);
    sceVu0ApplyMatrix(v1, m, cameraUp);
    sceVu0CameraMatrix(D_004FAE90[D_002C1EA0], cameraEye, v0, v1);
    sceVu0CopyMatrix(viewMatrix, D_004FAE90[D_002C1EA0]);
    sceVu0CopyMatrix(D_004FAF10[D_002C1EA0], D_002B8370);
    sceVu0CopyMatrix(screenMatrix, D_004FAF10[D_002C1EA0]);
    sceVu0MulMatrix(D_004FAE10[D_002C1EA0], screenMatrix, viewMatrix);
    sceVu0CopyMatrix(worldScreenMatrix, D_004FAE10[D_002C1EA0]);
    D_002DED0C = (s32*)D_004FAE10[D_002C1EA0];
    func_001109A8();
    D_004F77E0 = ((f32 (*)(f32*, f32*))Vec_YawBetween)(cameraEye, cameraTarget);
    return 0;
}
s32 Camera_BuildFrame(void);
// s32 Camera_BuildFrame(void) {
//     sceVu0FVECTOR v0;
//     sceVu0FVECTOR v1;
//     sceVu0FMATRIX m;

//     CameraMats_SaveAndRebuild(projDistance);
//     sceVu0SubVector(v0, cameraTarget, cameraEye);
//     sceVu0Normalize(v0, v0);
//     Mat_AxisAngle(Angle_Wrap(cameraRoll), v0, m);
//     sceVu0ApplyMatrix(v1, m, cameraUp);
//     sceVu0CameraMatrix(D_004FAE90[D_002C1EA0], cameraEye, v0, v1);
//     sceVu0CopyMatrix(viewMatrix, D_004FAE90[D_002C1EA0]);
//     sceVu0CopyMatrix(D_004FAF10[D_002C1EA0], D_002B8370);
//     sceVu0CopyMatrix(screenMatrix, D_004FAF10[D_002C1EA0]);
//     sceVu0MulMatrix(D_004FAE10[D_002C1EA0], screenMatrix, viewMatrix);
//     sceVu0CopyMatrix(worldScreenMatrix, D_004FAE10[D_002C1EA0]);
//     D_002DED0C = D_004FAE10[D_002C1EA0];
//     func_001109A8();
//     Vec_YawBetween(cameraEye, cameraTarget);
//     D_004FAF90 = 0;
//     return 0;
// }

// Copies the previous frame's view, world-to-screen and screen matrices back into the current ones.
s32 Camera_UsePreviousFrame(void) {
    sceVu0CopyMatrix(viewMatrix, D_004FAE90[D_002C1EA0 ^ 1]);
    sceVu0CopyMatrix(worldScreenMatrix, D_004FAE10[D_002C1EA0 ^ 1]);
    sceVu0CopyMatrix(screenMatrix, D_004FAF10[D_002C1EA0 ^ 1]);
    CameraMats_Restore();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xpeanut", func_001255F8);
