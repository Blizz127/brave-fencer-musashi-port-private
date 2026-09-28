/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A900C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801AA91C(s32 a0, s32 a1, s32 a2);

void func_801A900C(s32 a0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_801AA91C(a0, -0x300, (s16)(i << 10));
        func_801AA91C(a0, 0x300, (s16)(i << 10));
    }

    for (i = 0; i < 8; i++) {
        func_801AA91C(a0, -0x180, (0x1000000 + i * 0x2000000) >> 16);
        func_801AA91C(a0, 0x180, (0x1000000 + i * 0x2000000) >> 16);
        func_801AA91C(a0, 0, (s16)(i << 9));
    }
}
