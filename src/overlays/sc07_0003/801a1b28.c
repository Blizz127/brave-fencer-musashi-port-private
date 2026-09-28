/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1B28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801A1B28;
typedef struct { u16 vx, vy, vz, pad; } SV_801A1B28;
typedef struct { s32 vx, vy, vz, pad; } VEC_801A1B28;
extern s32 func_8012E544(s32 a0);
extern s32 func_8017F2D8(void);
extern s32 func_80132EF4(s32 a0, s32 a1);
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80049F3C(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C218(void *a0);
extern u8 D_801A63FC[];
extern u16 D_801F43C0;
extern u8 D_801A68DC[];
extern u8 D_801A6504[];

void func_801A1B28(s32 arg0) {
    MTX_801A1B28 mtx;
    SV_801A1B28 sv;
    VEC_801A1B28 vec;
    s32 obj;
    s32 p;

    if (*(s32 *)(arg0 + 0xE0) & 0x10) {
        if (func_8012E544(0x352) == 0) {
            func_8017F2D8();
            *(s32 *)(arg0 + 0xE0) &= ~0x10;
        }
    }

    if (*(s32 *)(arg0 + 0xE0) & 0x21) {
        if (*(s16 *)(arg0 + 0x76) <= 0) {
            *(s16 *)(arg0 + 0x2) = 0x17;
        } else {
            *(s16 *)(arg0 + 0x2) = 0x15;
        }
        return;
    }

    if (*(u16 *)(arg0 + 0x34) == 0) {
        if (*(u16 *)(arg0 + 0x72) & 0x4000) {
            *(s32 *)(arg0 + 0x1C) += 1;
        }
        if (*(s32 *)(arg0 + 0x90) == (s32)D_801A63FC && *(s32 *)(arg0 + 0x94) == 0) {
            obj = func_80132EF4(arg0, 0x22);
            if (obj != 0) {
                func_8012EC04(arg0, D_801F43C0, (s32 *)&mtx);
                func_8012F14C((s32)&mtx, (s32)D_801A68DC, (s32)&sv);
                *(u16 *)(obj + 0x6) = sv.vx;
                *(u16 *)(obj + 0xA) = sv.vy + 0x20;
                *(u16 *)(obj + 0xE) = sv.vz;
                *(s16 *)(obj + 0x34) = 0x6000;
                *(u16 *)(*(s32 *)(obj + 0x20) + 0x2C) = 0xC010;
                mtx = *(MTX_801A1B28 *)(*(s32 *)(arg0 + 0x20) + 0x34);
                vec.vy = 0;
                vec.vx = 0;
                vec.vz = -0xC0000;
                func_80049F3C(0x200, &mtx);
                func_800484EC((s32)&mtx, (s32)&vec, obj + 0x10);
            }
            func_8002D4C8(0xB9C, 0);
        }
        if (*(s32 *)(arg0 + 0x1C) >= 4) {
            func_8012A828(arg0, D_801A6504);
            *(u16 *)(arg0 + 0x34) += 1;
        }
    } else {
        if (*(s16 *)(arg0 + 0x98) == 0) {
            *(s16 *)(arg0 + 0x2) = 3;
            *(s32 *)(arg0 + 0xEC) = 0x10000;
            *(s32 *)(arg0 + 0xE8) = 0;
            *(s32 *)(arg0 + 0xE0) |= 0x100;
            p = *(s32 *)(arg0 + 0xD8);
            if (p != 0) {
                if (*(u16 *)p != 0) {
                    func_8012C218((void *)p);
                }
            }
        }
    }
}
