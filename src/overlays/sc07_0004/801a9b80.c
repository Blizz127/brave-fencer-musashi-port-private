/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9B80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800599B8(void*, void*);

void func_801A9B80(s32 *a0, u16 a1, u16 a2) {
    s32 t1;
    s32 t2;
    s32 i;
    u16 buf[4];

    t1 = a0[7];
    t2 = a0[6];

    i = 7;
    do {
        a0[i] = a0[i - 2];
        a0[i - 1] = a0[i - 3];
        i -= 2;
    } while (i >= 3);

    a0[i] = t1;
    a0[i - 1] = t2;

    buf[2] = 0x10;
    buf[0] = a1;
    buf[1] = a2;
    buf[3] = 1;

    ((void (*)(u16 *, s32 *))func_800599B8)(buf, a0);
}
