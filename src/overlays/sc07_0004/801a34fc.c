/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A34FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A34FC(s32 arg0, u16 *arg1) {
    s16 *p;
    s16 ax;
    s16 ay;

    *(u16 *)(arg0 + 0xE8) = *(u16 *)(arg1 + 0);
    *(u16 *)(arg0 + 0xEA) = *(u16 *)(arg1 + 2);
    p = (s16 *)(arg0 + 0xEC);
    p[0] = *(u16 *)(arg0 + 0xE8) - *(u16 *)(arg0 + 6);
    p[1] = *(u16 *)(arg0 + 0xEA) - *(u16 *)(arg0 + 0xE);
    if (p[0] < 0) {
        ax = -p[0];
    } else {
        ax = p[0];
    }
    *(s16 *)(arg0 + 0x106) = 0;
    if (p[1] < 0) {
        ay = -p[1];
    } else {
        ay = p[1];
    }
    if (ax < ay) {
        *(s16 *)(arg0 + 0x106) = 1;
    }
}
