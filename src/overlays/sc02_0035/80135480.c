/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80135480 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyRotMatrix func_8004864C
#define ApplyRotMatrixLV func_80048B6C
#define ApplyTransposeMatrixLV func_8004D504
typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32;
typedef struct { s16 vx, vy, vz, pad; } Vec16;
typedef struct { s32 vx, vy, vz, pad; } Vec32;
extern void func_8004914C(void *);
extern void func_8004914C(void *a0);
extern void ApplyTransposeMatrixLV(void *a0, void *a1, void *a2);
extern void func_8004914C();

s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4)
{
     


    extern u8 D_80184A60;
    extern u8 D_80184A64;
        extern void func_80048EAC(void *m0, void *m1);
    extern void func_8004914C(void *m);
    extern void ApplyTransposeMatrixLV(void *m, void *in, void *out);
    extern void ApplyRotMatrixLV(void *in, void *out);
    extern void ApplyRotMatrix(void *in, void *out);
    extern s32 D_801BD61C, D_801BD620, D_801BD624, D_801BD628;
    extern s16 D_801BD62C;
    extern s32 D_801BD63C;
    extern s16 D_801BD640, D_801BD642, D_801BD644, D_801BD646, D_801BD648, D_801BD64A;

    Vec32 in0, in1, rotout;
    Mat32 mat2;
    Vec16 vecin;
    s32 result;
    s32 mode;
    s32 q1, q2;
    s32 p;
    s32 t18, t1A, t1C;
    s32 *m;

    in0.vx = param_3[0] - *(s32 *)((s32)param_1 + 0x48);
    in0.vz = param_3[2] - *(s32 *)((s32)param_1 + 0x50);
    if ((param_2 & 0x10000000) == 0) {
        if (in0.vx * in0.vx + in0.vz * in0.vz > 0x40000) {
            return 0;
        }
    }
    mode = param_2 & 0x60000000;
    if (mode != 0) {
        result = 1;
        if (param_2 >= 0) {
            mode &= 0x40000000;
        }
        in0.vy = param_3[1] - *(s32 *)((s32)param_1 + 0x4C);
        in1.vx = param_4[0] - *(s32 *)((s32)param_1 + 0x48);
        in1.vy = param_4[1] - *(s32 *)((s32)param_1 + 0x4C);
        in1.vz = param_4[2] - *(s32 *)((s32)param_1 + 0x50);
        switch (mode) {
        case 0x60000000:
            m = &D_801BD61C;
            *m = 0x1000000 / *(s16 *)((s32)param_1 + 0x18);
            q1 = 0x1000000 / *(s16 *)((s32)param_1 + 0x1A);
            q2 = 0x1000000 / *(s16 *)((s32)param_1 + 0x1C);
            D_801BD620 = 0;
            D_801BD628 = 0;
            D_801BD624 = q1;
            D_801BD62C = q2;
            func_80048EAC((void *)((s32)param_1 + 0x34), m);
            ApplyTransposeMatrixLV(m, &in0, &in0);
            ApplyRotMatrixLV(&in1, &in1);
            result = 2;
             
        case 0x20000000:
            p = (param_2 & 0xFFFFFFF) | 0x80000000;
            t18 = *(s16 *)((s32)param_1 + 0x18);
            t1A = *(s16 *)((s32)param_1 + 0x1A);
            t1C = *(u16 *)((s32)param_1 + 0x1C);
            mat2.w4 = 0;
            mat2.wC = 0;
            mat2.w0 = t18;
            mat2.w8 = t1A;
            mat2.h10 = t1C;
            func_8004914C(&mat2);
            vecin.vx = *(u16 *)(p + 4);
            vecin.vy = *(u16 *)(p + 8);
            vecin.vz = *(u16 *)(p + 0xC);
            ApplyRotMatrix(&vecin, &rotout);
            D_801BD640 = rotout.vx;
            D_801BD644 = rotout.vy;
            D_801BD648 = rotout.vz;
            vecin.vx = *(u16 *)(p + 6);
            vecin.vy = *(u16 *)(p + 0xA);
            vecin.vz = *(u16 *)(p + 0xE);
            ApplyRotMatrix(&vecin, &rotout);
            D_801BD63C = 0;
            D_801BD642 = rotout.vx;
            D_801BD646 = rotout.vy;
            D_801BD64A = rotout.vz;
            result += 2;
            break;
        case 0x40000000:
            ApplyTransposeMatrixLV((void *)((s32)param_1 + 0x34), &in0, &in0);
            ApplyRotMatrixLV(&in1, &in1);
            result = 2;
            break;
        }
        {
            s16 *p = *(s16 **)&D_80184A60;
            p[0] = in0.vx;
            p[1] = in0.vy;
            p[2] = in0.vz;
        }
        {
            s16 *p = *(s16 **)&D_80184A64;
            p[0] = in1.vx;
            p[1] = in1.vy;
            p[2] = in1.vz;
        }
        return result;
    }
    {
        s16 *p = *(s16 **)&D_80184A60;
        p[0] = in0.vx;
        p[1] = ((u16 *)param_3)[1] - *(s32 *)((s32)param_1 + 0x4C);
        p[2] = in0.vz;
    }
    {
        s16 *p = *(s16 **)&D_80184A64;
        p[0] = ((u16 *)param_4)[0] - *(s32 *)((s32)param_1 + 0x48);
        p[1] = ((u16 *)param_4)[1] - *(s32 *)((s32)param_1 + 0x4C);
        p[2] = ((u16 *)param_4)[2] - *(s32 *)((s32)param_1 + 0x50);
    }
    return 1;
}
