/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016163C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32 *a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_801152B0;
extern s16 D_801152B4;

s32 func_8016163C(s32 a0, u32 a1)
{
    s32 result;
    if ((a1 & 1) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 1;
    }
    if ((a1 & 0x4000) != 0) {
        func_801599A4(a0);
        func_8015BF48((s32 *)a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 2;
    }
    if ((a1 & 0x2000) != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
        func_8014C010((s32)a0, 1);
        func_80161D20((s32)a0, *(u16 *)((s32)a0 + 0x16E));
        return 4;
    }
    if ((a1 & 0x8000) != 0) {
        if (*(u16 *)((s32)a0 + 0x16C) != 0x15) {
            return 0;
        }
        if (func_8014A6C4((s32)a0) == 0) {
            return 0;
        }
        func_801599A4(a0);
        func_8015F2F0(a0);
        result = func_8004CFEC(D_801152B0, D_801152B4);
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = (s16)result;
        return 8;
    }
    return 0;
}
