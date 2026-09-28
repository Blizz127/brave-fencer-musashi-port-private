/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158E24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern M2C_UNK D_800D5904;

void func_80158E24(s32 *a0) {
    s32 n;
    s32 c;
    c = 0x4C000;
    n = 1;
    if (func_801487F4(a0) & 0xF0) {
        n = 4;
    }
    while (n > 0) {
        func_80159434((s32)a0, c);
        if (*(s16 *)(a0[0x20 / 4] + 0x10) < 0xC00) {
            *(s16 *)(a0[0x20 / 4] + 0x10) = 0xC00;
            func_80154274(a0, (s32)&D_800D5904);
            func_80154A74((s32)a0, 0x20);
            func_8002D4C8(0x2A, 0);
            func_8002D4C8(0x1C, 0);
            func_80146CA0(a0);
            n = 0;
        }
        n--;
    }
}
