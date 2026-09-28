/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B608 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_8012B608(s32 a0, s32 a1, s32 a2) {
    s32 v1;
    s32 t;
    a0 &= 0xFFF;
    a1 &= 0xFFF;
    v1 = a1 - a0;
    if (a0 == a1) {
        return 0;
    }
    if (v1 >= 0x801) {
        t = a0 + 0x1000;
        v1 = a1 - t;
    }
    if (v1 < -0x800) {
        t = a0 - 0x1000;
        v1 = a1 - t;
    }
    if (v1 >= 0) {
        v1 = v1 / a2;
        if (v1 != 0) {
            return v1;
        }
        v1 = 1;
    } else {
        v1 = v1 / a2;
        if (v1 != 0) {
            return v1;
        }
        v1 = -1;
    }
    return v1;
}
