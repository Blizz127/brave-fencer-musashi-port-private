/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A649C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80059A1C(s32, void *);

void func_801A649C(void *a0, u16 a1, u16 a2) {
    u16 buf[4];

    buf[2] = 0x10;
    buf[0] = a1;
    buf[1] = a2;
    buf[3] = 1;
    func_80059A1C((s32)&buf, (void *)a0);
}
