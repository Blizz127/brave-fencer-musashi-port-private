/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801632F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80115200;

s32 func_801632F0(void) {
    s32 i = 0;
    s32 *p = &D_80115200;
    s32 v0;
    do {
        v0 = p[0];
        if (v0 != 0) {
            return v0;
        }
        i++;
        p++;
    } while (i < 3);
    return 0;
}
