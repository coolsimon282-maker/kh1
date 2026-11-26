/**
 * Vector, matrix and angle maths on VU0 types: lengths, angle wrapping and stepping, rotations, projection and screen
 * tests, cubic splines, line intersection, Euler angles, and a frame-time countdown.
 */
#include "common.h"
#include "fastmath.h"

f32 Vec_CosAngle(sceVu0FVECTOR, sceVu0FVECTOR);

extern f32 D_002B8340[];
extern f32 D_002B8344[];

// Length of the vector (sqrt of its inner product).
f32 Vec_Length(sceVu0FVECTOR arg0) {
    f32 prod = sceVu0InnerProduct(arg0, arg0);
    return _sqrtf(prod);
}

// Length of the vector in the XZ plane.
#ifdef VERSION_EU
f32 Vec_LengthXZ(sceVu0FVECTOR arg0);
INCLUDE_ASM("asm/nonmatchings/xball", Vec_LengthXZ);
#else
f32 Vec_LengthXZ(sceVu0FVECTOR arg0) {
    return _sqrtf(arg0[0] * arg0[0] + arg0[2] * arg0[2]);
}
#endif

// arg0 = arg1 rotated about Z, X, then Y by the angles in arg2.
s32 Mat_RotateZXY(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

// Wraps an angle into -PI..PI (at most 0x400 steps of 2 PI).
f32 Angle_Wrap(f32 x) {
    s32 i;

    for (i = 0; i < 0x400; i++) {
        if (x > PI) {
            x -= 2 * PI;
        } else if (x < -PI) {
            x += 2 * PI;
        } else {
            break;
        }
    }
    return x;
}
f32 Angle_Wrap(f32);

// Rotation matrix of angle ang about the unit axis (Rodrigues form).
void Mat_AxisAngle(sceVu0FVECTOR axis, sceVu0FMATRIX m, f32 ang) {
    sceVu0FVECTOR tmp[3];
    sceVu0FVECTOR v;
    f32 c;
    f32 f;
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        m[i][3] = m[3][i] = 0.0f;
    }
    m[3][3] = 1.0f;
    sceVu0ScaleVector(v, axis, sinf(ang));
    c = cosf(ang);
    for (i = 0; i < 3; i++) {
        sceVu0ScaleVector(tmp[i], axis, axis[i]);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == j) {
                m[i][j] = c;
            } else {
                if ((i + 3 - j) % 3 == 1) {
                    m[i][j] = -v[3 - (i + j)];
                } else {
                    m[i][j] = v[3 - (i + j)];
                }
            }
        }
    }
    c = 1.0f - c;
    for (i = 0; i < 3; i++) {
        sceVu0ScaleVector(tmp[i], tmp[i], c);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            m[i][j] += tmp[i][j];
        }
    }
}


// arg0 = arg1 * arg2 (w set to 1) divided by its w; returns 1 / w.
f32 Vec_Project(sceVu0FVECTOR arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    f32 f;
    s32 i;

    arg2[3] = 1.0f;
    sceVu0ApplyMatrix(arg0, arg1, arg2);
    f = 1.0f / arg0[3];
    for (i = 0; i < 3; i++) {
        arg0[i] *= f;
    }
    arg0[3] = 1.0f;
    return f;
}


// Normalised normal of the triangle arg0[0..2].
void Vec_TriangleNormal(sceVu0FVECTOR* arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR v[2];
    s32 i;

    for (i = 0; i < 2; i++) {
        sceVu0SubVector(v[i], arg0[i + 1], arg0[i]);
    }
    v[0][3] = 1.0f;
    v[1][3] = 1.0f;
    sceVu0OuterProduct(arg1, v[0], v[1]);
    func_001223B0(arg1, arg1);
}

// True when all eight points, transformed by m, are in front (w >= 1) and inside 0..4095 on screen.
s32 Mat_IsBoxOnScreen(sceVu0FMATRIX m, sceVu0FVECTOR* v) {
    sceVu0FVECTOR t;
    s32 i;

    for (i = 0; i < 8; i++) {
        sceVu0ApplyMatrix(t, m, v[i]);
        if (t[3] < 1.0f) {
            return 0;
        }
        t[0] /= t[3];
        t[1] /= t[3];
        if (t[0] < 0.0f || 4095.0f < t[0] || t[1] < 0.0f || 4095.0f < t[1]) {
            return 0;
        }
    }
    return 1;
}

// arg1 = arg2 with X and Z scaled by arg0.
void Vec_ScaleXZ(f32 arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = arg2[0] * arg0;
    arg1[1] = arg2[1];
    arg1[2] = arg2[2] * arg0;
    arg1[3] = arg2[3];
}

// True when arg0[0][2] < 0 or sceVu0ClipScreen rejects it.
#ifdef VERSION_EU
s32 Mat_IsClipped(sceVu0FMATRIX arg0);
INCLUDE_ASM("asm/nonmatchings/xball", Mat_IsClipped);
#else
s32 Mat_IsClipped(sceVu0FMATRIX arg0) {
    return (arg0[0][2] < 0.0f || sceVu0ClipScreen(*arg0) != 0) ? TRUE : FALSE;
}
#endif

// Interpolates between two lines arg2 and arg3 (around their crossing point) by arg0 into arg1; returns 1.
s32 func_00120FC8(f32 arg0, sceVu0FMATRIX arg1, sceVu0FMATRIX arg2, sceVu0FMATRIX arg3) {
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR v2;
    sceVu0FVECTOR v3;
    sceVu0FVECTOR v4;

    sceVu0SubVector(v1, arg2[1], arg2[0]);
    sceVu0SubVector(v2, arg3[1], arg3[0]);
    sceVu0ScaleVector(
        v3, v1, ((arg3[0][1] - arg2[0][1]) + v2[1] * (arg3[0][0] - arg2[0][0])) / (v2[0] * v1[1] - v2[1] * v1[0])
    );
    sceVu0AddVector(v3, v3, arg2[0]);

    sceVu0SubVector(v1, arg2[0], v3);
    func_001223B0(v1, v1);

    sceVu0SubVector(v2, arg3[0], v3);
    func_001223B0(v2, v2);

    sceVu0InterVector(v0, v2, v1, arg0);
    sceVu0Normalize(v0, v0);
    sceVu0ScaleVector(v4, v0, v1[3] + (v2[3] - v1[3]) * arg0);
    sceVu0AddVector(arg1[0], v3, v4);
    arg1[0][3] = 1.0f;

    sceVu0SubVector(v1, arg2[1], v3);
    func_001223B0(v1, v1);

    sceVu0SubVector(v2, arg3[1], v3);
    func_001223B0(v2, v2);

    sceVu0InterVector(v0, v2, v1, arg0);
    sceVu0Normalize(v0, v0);
    sceVu0ScaleVector(v4, v0, v1[3] + (v2[3] - v1[3]) * arg0);
    sceVu0AddVector(arg1[1], v3, v4);
    arg1[1][3] = 1.0f;

    return 1;
}

// Natural cubic spline: the second-derivative terms of the n values y (end values 0).
void Spline_ComputeCoeffs(f32* y, s32 n, f32* out) {
    f32 h[32];
    f32 t;
    s32 i;

    out[0] = out[n - 1] = 0.0f;
    for (i = 0; i < n - 1; i++) {
        h[i + 1] = y[i + 1] - y[i];
    }
    out[1] = h[2] - h[1] - out[0];
    h[1] = 4.0f;
    for (i = 1; i < n - 2; i++) {
        t = 1.0f / h[i];
        out[i + 1] = h[i + 2] - h[i + 1] - out[i] * t;
        h[i + 1] = 4.0f - t;
    }
    out[n - 2] -= out[n - 1];
    for (i = n - 2; i > 0; i--) {
        out[i] = (out[i] - out[i + 1]) / h[i];
    }
}


// Cubic spline value at t from values a and coefficients b.
f32 Spline_Evaluate(f32 t, f32* a, f32* b) {
    s32 i = t;
    f32 f = t - i;
    f32 a0 = a[i];
    f32 a1 = a[i + 1];
    f32 b0 = b[i];
    f32 b1 = b[i + 1];

    return (((b1 - b0) * f + b0 * 3.0f) * f + ((a1 - a0) - (b0 + b0 + b1))) * f + a0;
}

// Point where line p + t d meets the line through q along n in the XZ plane; returns t (NaN when parallel).
#ifdef VERSION_EU
f32 Line_IntersectXZ(sceVu0FVECTOR out, sceVu0FVECTOR p, sceVu0FVECTOR d, sceVu0FVECTOR q, sceVu0FVECTOR n);
INCLUDE_ASM("asm/nonmatchings/xball", Line_IntersectXZ);
#else
f32 Line_IntersectXZ(sceVu0FVECTOR out, sceVu0FVECTOR p, sceVu0FVECTOR d, sceVu0FVECTOR q, sceVu0FVECTOR n) {
    f32 den = d[2] * n[0] - n[2] * d[0];
    f32 t;

    if (den == 0.0f) {
        return nan();
    }
    t = (n[0] * (q[2] - p[2]) + n[2] * (p[0] - q[0])) / den;
    sceVu0ScaleVector(out, d, t);
    sceVu0AddVector(out, out, p);
    return t;
}
#endif


// Drop shadow matrix (sceVu0DropShadowMatrix) with its translation scaled by arg3.
void Mat_DropShadow(f32 arg0, f32 arg1, f32 arg2, f32 arg3, sceVu0FMATRIX arg4, sceVu0FVECTOR arg5) {
    sceVu0DropShadowMatrix(arg4, arg5, arg0, arg1, arg2, 0);
    sceVu0ScaleVectorXYZ(arg4[3], arg4[3], arg3);
}

// arg0 = the transposed 3x3 part of arg1, without translation.
void Mat_Transpose3x3(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1) {
    arg0[0][0] = arg1[0][0];
    arg0[0][1] = arg1[1][0];
    arg0[0][2] = arg1[2][0];
    arg0[0][3] = 0.0f;
    arg0[1][0] = arg1[0][1];
    arg0[1][1] = arg1[1][1];
    arg0[1][2] = arg1[2][1];
    arg0[1][3] = 0.0f;
    arg0[2][0] = arg1[0][2];
    arg0[2][1] = arg1[1][2];
    arg0[2][2] = arg1[2][2];
    arg0[2][3] = 0.0f;
    arg0[3][0] = 0.0f;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[3][3] = 1.0f;
}

// Angle a turned towards b by at most c per frame (scaled by the time step D_002B8344).
f32 Angle_StepTowards(f32 a, f32 b, f32 c) {
    f32 d = Angle_Wrap(b - a);

    c *= D_002B8344[0];
    if (c < d) {
        d = c;
    } else if (d < -c) {
        d = -c;
    }
    return Angle_Wrap(a + d);
}

#define XB_COS(a, b) (sceVu0InnerProduct(a, b) / (Vec_Length(a) * Vec_Length(b)))
// Cosine of the angle between two vectors, clamped to -1..1.
f32 Vec_CosAngle(sceVu0FVECTOR a, sceVu0FVECTOR b) {
    if (XB_COS(a, b) < -1.0f) {
        return -1.0f;
    }
    if (1.0f < XB_COS(a, b)) {
        return 1.0f;
    }
    return XB_COS(a, b);
}

// Angle between two vectors (acos of Vec_CosAngle).
f32 Vec_Angle(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    return acosf(Vec_CosAngle(arg0, arg1));
}

void Mat_AxisAngle(sceVu0FVECTOR, sceVu0FMATRIX, f32);
// out = direction a turned towards b by at most t per frame.
void Vec_RotateTowards(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR out, f32 t) {
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR axis;
    sceVu0FMATRIX m;
    f32 ang;

    sceVu0Normalize(v0, a);
    sceVu0Normalize(v1, b);
    sceVu0OuterProduct(axis, v0, v1);
    sceVu0Normalize(axis, axis);
    ang = Vec_Angle(v0, v1);
    t *= D_002B8344[0];
    if (t < ang) {
        ang = t;
    } else if (ang < -t) {
        ang = -t;
    }
    Mat_AxisAngle(axis, m, ang);
    sceVu0CopyVector(out, v0);
    out[3] = 0.0f;
    sceVu0ApplyMatrix(out, m, out);
}


// arg0 rows 0..2 = arg1 rows scaled by arg2[0..2].
void Mat_ScaleRows(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, f32* arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        sceVu0ScaleVectorXYZ(arg0[i], arg1[i], arg2[i]);
    }
}

// arg0[i] = arg1[i] / arg2[i] for X, Y, Z.
void Vec_Div3(f32* arg0, f32* arg1, f32* arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = arg1[i] / arg2[i];
    }
}

// Pitch and yaw of direction arg0 into arg1 (roll 0).
#ifdef VERSION_EU
void Vec_ToAngles(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2);
INCLUDE_ASM("asm/nonmatchings/xball", Vec_ToAngles);
#else
void Vec_ToAngles(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = atan2f(-arg0[1], Vec_LengthXZ(arg0));
    arg1[1] = atan2f(arg0[0], arg0[2]);
    arg1[2] = 0.0f;
    arg1[3] = 1.0f;
}
#endif

// Euler angles of the normalised rotation matrix arg0 into arg1.
void Mat_ToEuler(sceVu0FMATRIX arg0, sceVu0FVECTOR arg1) {
    sceVu0FMATRIX m;
    s32 i;

    for (i = 0; i < 3; i++) {
        sceVu0Normalize(m[i], arg0[i]);
    }
    arg1[0] = atan2f(-m[1][2], m[0][2]);
    arg1[1] = asinf(-m[2][2]);
    arg1[2] = atan2f(m[2][1], m[2][0]);
}


// A positive timer minus D_002B8340[1], not below 0.
#ifdef VERSION_EU
f32 Timer_CountDown(f32 arg0);
INCLUDE_ASM("asm/nonmatchings/xball", Timer_CountDown);
#else
f32 Timer_CountDown(f32 arg0) {
    if (arg0 > 0.0f) {
        arg0 -= D_002B8340[1];
        if (arg0 < 0.0f) {
            arg0 = 0.0f;
        }
    }
    return arg0;
}
#endif

// Vec_CosAngle of the two vectors flattened to Y = 0 (the result is not returned).
void Vec_CosAngleXZ(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack0;
    sceVu0FVECTOR stack1;

    sceVu0CopyVector(stack0, arg0);
    sceVu0CopyVector(stack1, arg1);
    stack0[1] = 0.0f;
    stack1[1] = 0.0f;
    Vec_CosAngle(stack0, stack1);
}
