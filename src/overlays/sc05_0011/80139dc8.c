/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139DC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8012811A;

void func_80139DC8(void) {
    s32 i = 0x287;
    s16 *p = &D_8012811A;
    do {
        *p = 0;
        i--;
        p = (s16 *)((s32)p - 2);
    } while (i >= 0);
}
