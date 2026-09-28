/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146014 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80059A80(void *a0, s32 a1, s32 a2);

void func_80146014(s32 a0) {
    s32 *r = (s32 *)a0;
    if (r[3] == 0) {
        return;
    }
    do {
        func_80059A80(r, r[2], r[3]);
        r += 4;
    } while (r[3] != 0);
}
