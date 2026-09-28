/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142D38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32 a0);

s32 func_80142D38(s32 *a0) {
    if (func_8012BEE8((s32)a0) == 1) {
        return 1;
    }
    if (a0[0x1C / 4] & 1) {
        ((s32 *)a0[0x20 / 4])[1] |= 0x80000000;
    } else {
        ((s32 *)a0[0x20 / 4])[1] &= 0x7FFFFFFF;
    }
    return 0;
}
