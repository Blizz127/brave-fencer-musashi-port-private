/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADD98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ADD98(u8 *a0, volatile u8 *a1, volatile u8 *a2) {
    s32 ctr;
    s32 v1;

    ctr = 0;
    do {
        a1[0] = (*(u16 *)a0 >> 8) & 0x7C;
        ctr++;
        v1 = (a1[0] << 24) >> 28;
        a1[1] = (*(u16 *)a0 >> 3) & 0x7C;
        a1[2] = (*a0 << 2) & 0x7C;
        a2[0] = v1;
        a2[1] = (a1[1] << 24) >> 28;
        a0 += 2;
        a2[2] = (a1[2] << 24) >> 28;
        a1 += 3;
        a2 += 3;
    } while (ctr < 0x10);
}
