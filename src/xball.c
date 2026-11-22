#include "common.h"
#include "fastmath.h"

f32 func_001215A8(sceVu0FVECTOR, sceVu0FVECTOR);

extern f32 D_002B8340[];
extern f32 D_002B8344[];

f32 func_00120A38(sceVu0FVECTOR arg0) {
    f32 prod = sceVu0InnerProduct(arg0, arg0);
    return _sqrtf(prod);
}

f32 func_00120A58(sceVu0FVECTOR arg0) {
    return _sqrtf(arg0[0] * arg0[0] + arg0[2] * arg0[2]);
}

s32 func_00120A78(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

f32 func_00120AC8(f32 x) {
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
f32 func_00120AC8(f32);

void func_00120B40(sceVu0FVECTOR axis, sceVu0FMATRIX m, f32 ang) {
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


f32 func_00120D38(sceVu0FVECTOR arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
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


void func_00120DB8(sceVu0FVECTOR* arg0, sceVu0FVECTOR arg1) {
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

s32 func_00120E48(sceVu0FMATRIX m, sceVu0FVECTOR* v) {
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

void func_00120F48(f32 arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = arg2[0] * arg0;
    arg1[1] = arg2[1];
    arg1[2] = arg2[2] * arg0;
    arg1[3] = arg2[3];
}

s32 func_00120F78(sceVu0FMATRIX arg0) {
    return (arg0[0][2] < 0.0f || sceVu0ClipScreen(*arg0) != 0) ? TRUE : FALSE;
}

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

void func_00121200(f32* y, s32 n, f32* out) {
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


f32 func_00121340(f32 t, f32* a, f32* b) {
    s32 i = t;
    f32 f = t - i;
    f32 a0 = a[i];
    f32 a1 = a[i + 1];
    f32 b0 = b[i];
    f32 b1 = b[i + 1];

    return (((b1 - b0) * f + b0 * 3.0f) * f + ((a1 - a0) - (b0 + b0 + b1))) * f + a0;
}

f32 func_001213B0(sceVu0FVECTOR out, sceVu0FVECTOR p, sceVu0FVECTOR d, sceVu0FVECTOR q, sceVu0FVECTOR n) {
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


void func_00121480(f32 arg0, f32 arg1, f32 arg2, f32 arg3, sceVu0FMATRIX arg4, sceVu0FVECTOR arg5) {
    sceVu0DropShadowMatrix(arg4, arg5, arg0, arg1, arg2, 0);
    sceVu0ScaleVectorXYZ(arg4[3], arg4[3], arg3);
}

void func_001214C8(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1) {
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

f32 func_00121538(f32 a, f32 b, f32 c) {
    f32 d = func_00120AC8(b - a);

    c *= D_002B8344[0];
    if (c < d) {
        d = c;
    } else if (d < -c) {
        d = -c;
    }
    return func_00120AC8(a + d);
}

#define XB_COS(a, b) (sceVu0InnerProduct(a, b) / (func_00120A38(a) * func_00120A38(b)))
f32 func_001215A8(sceVu0FVECTOR a, sceVu0FVECTOR b) {
    if (XB_COS(a, b) < -1.0f) {
        return -1.0f;
    }
    if (1.0f < XB_COS(a, b)) {
        return 1.0f;
    }
    return XB_COS(a, b);
}

f32 func_001216A8(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    return acosf(func_001215A8(arg0, arg1));
}

void func_00120B40(sceVu0FVECTOR, sceVu0FMATRIX, f32);
void func_001216C8(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR out, f32 t) {
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR axis;
    sceVu0FMATRIX m;
    f32 ang;

    sceVu0Normalize(v0, a);
    sceVu0Normalize(v1, b);
    sceVu0OuterProduct(axis, v0, v1);
    sceVu0Normalize(axis, axis);
    ang = func_001216A8(v0, v1);
    t *= D_002B8344[0];
    if (t < ang) {
        ang = t;
    } else if (ang < -t) {
        ang = -t;
    }
    func_00120B40(axis, m, ang);
    sceVu0CopyVector(out, v0);
    out[3] = 0.0f;
    sceVu0ApplyMatrix(out, m, out);
}


void func_001217C0(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, f32* arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        sceVu0ScaleVectorXYZ(arg0[i], arg1[i], arg2[i]);
    }
}

void func_00121830(f32* arg0, f32* arg1, f32* arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = arg1[i] / arg2[i];
    }
}

void func_00121878(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1, sceVu0FVECTOR arg2) {
    arg1[0] = atan2f(-arg0[1], func_00120A58(arg0));
    arg1[1] = atan2f(arg0[0], arg0[2]);
    arg1[2] = 0.0f;
    arg1[3] = 1.0f;
}

void func_001218E0(sceVu0FMATRIX arg0, sceVu0FVECTOR arg1) {
    sceVu0FMATRIX m;
    s32 i;

    for (i = 0; i < 3; i++) {
        sceVu0Normalize(m[i], arg0[i]);
    }
    arg1[0] = atan2f(-m[1][2], m[0][2]);
    arg1[1] = asinf(-m[2][2]);
    arg1[2] = atan2f(m[2][1], m[2][0]);
}


f32 func_00121970(f32 arg0) {
    if (arg0 > 0.0f) {
        arg0 -= D_002B8340[1];
        if (arg0 < 0.0f) {
            arg0 = 0.0f;
        }
    }
    return arg0;
}

void func_001219A8(sceVu0FVECTOR arg0, sceVu0FVECTOR arg1) {
    sceVu0FVECTOR stack0;
    sceVu0FVECTOR stack1;

    sceVu0CopyVector(stack0, arg0);
    sceVu0CopyVector(stack1, arg1);
    stack0[1] = 0.0f;
    stack1[1] = 0.0f;
    func_001215A8(stack0, stack1);
}
