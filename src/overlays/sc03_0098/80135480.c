/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135480 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32;
typedef struct { s16 vx, vy, vz, pad; } Vec16;
typedef struct { s32 vx, vy, vz, pad; } Vec32;

s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4)
{
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §100); the whole-binary byte-gate is the arbiter. */
    extern u8 D_801858B0;
    extern u8 D_801858B4;
        extern void func_80048EAC(void *m0, void *m1);
    extern void func_8004914C(void *m);
    extern void func_8004D504(void *m, void *in, void *out);
    extern void func_80048B6C(void *in, void *out);
    extern void func_8004864C(void *in, void *out);
    extern s32 D_801C420C, D_801C4210, D_801C4214, D_801C4218;
    extern s16 D_801C421C;
    extern s32 D_801C422C;
    extern s16 D_801C4230, D_801C4232, D_801C4234, D_801C4236, D_801C4238, D_801C423A;

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
            m = &D_801C420C;
            *m = 0x1000000 / *(s16 *)((s32)param_1 + 0x18);
            q1 = 0x1000000 / *(s16 *)((s32)param_1 + 0x1A);
            q2 = 0x1000000 / *(s16 *)((s32)param_1 + 0x1C);
            D_801C4210 = 0;
            D_801C4218 = 0;
            D_801C4214 = q1;
            D_801C421C = q2;
            func_80048EAC((void *)((s32)param_1 + 0x34), m);
            func_8004D504(m, &in0, &in0);
            func_80048B6C(&in1, &in1);
            result = 2;
            /* fallthrough */
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
            func_8004864C(&vecin, &rotout);
            D_801C4230 = rotout.vx;
            D_801C4234 = rotout.vy;
            D_801C4238 = rotout.vz;
            vecin.vx = *(u16 *)(p + 6);
            vecin.vy = *(u16 *)(p + 0xA);
            vecin.vz = *(u16 *)(p + 0xE);
            func_8004864C(&vecin, &rotout);
            D_801C422C = 0;
            D_801C4232 = rotout.vx;
            D_801C4236 = rotout.vy;
            D_801C423A = rotout.vz;
            result += 2;
            break;
        case 0x40000000:
            func_8004D504((void *)((s32)param_1 + 0x34), &in0, &in0);
            func_80048B6C(&in1, &in1);
            result = 2;
            break;
        }
        {
            s16 *p = *(s16 **)&D_801858B0;
            p[0] = in0.vx;
            p[1] = in0.vy;
            p[2] = in0.vz;
        }
        {
            s16 *p = *(s16 **)&D_801858B4;
            p[0] = in1.vx;
            p[1] = in1.vy;
            p[2] = in1.vz;
        }
        return result;
    }
    {
        s16 *p = *(s16 **)&D_801858B0;
        p[0] = in0.vx;
        p[1] = ((u16 *)param_3)[1] - *(s32 *)((s32)param_1 + 0x4C);
        p[2] = in0.vz;
    }
    {
        s16 *p = *(s16 **)&D_801858B4;
        p[0] = ((u16 *)param_4)[0] - *(s32 *)((s32)param_1 + 0x48);
        p[1] = ((u16 *)param_4)[1] - *(s32 *)((s32)param_1 + 0x4C);
        p[2] = ((u16 *)param_4)[2] - *(s32 *)((s32)param_1 + 0x50);
    }
    return 1;
}
