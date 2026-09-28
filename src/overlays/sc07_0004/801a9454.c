/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9454 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);

s32 func_801A9454(s32 self, s32 amount) {
    s32 obj;
    u16 v;

    obj = func_80132EF4(self, 0x2D);
    if (obj != 0) {
        v = *(u16 *)(obj + 0xA);
        *(u16 *)(obj + 0x2C) = 2;
        *(u16 *)(obj + 0xA) = v + amount;
    }
    return obj;
}
