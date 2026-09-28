/* SC02.CD member31 [8014CA88,8014CAE4); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CA88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_8014CAE4(s32 *a0, s32 a1);
extern void func_80147364();
extern void *D_8012707C;

s32 func_8014CA88(s32 *a0, s32 a1) {
    u16 x = func_8014CAE4(a0, a1);
    if (x == 0) {
        return 1;
    }
    if (x != (s32)D_8012707C) {
        func_80147364(x, 0);
        return 0;
    }
    D_8012707C = 0;
    return 0;
}
