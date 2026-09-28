/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E410 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];

s32 func_8013E410(void) {
    s32 a0;
    s32 v1;
    v1 = (s32)D_801202A0;
    for (a0 = 0; a0 < 0x60; a0++, v1 += 0x10C) {
        if (*(u16 *)v1 == 0) {
            return v1;
        }
    }
    return 0;
}
