/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2704 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800D27A0();
extern void func_800D3234(s32 a0, s32 a1);
extern void func_80046B44(s32 a0);

s32 func_800D2704(s32 a0, s32 a1) {
    s32 *ptr;
    s32 cnt;
    s32 ring;
    s32 a1s;
    ptr = (s32 *)a0;
    a1s = a1;
    cnt = 0x20;
    do {
        ring = func_800D27A0((s32)ptr, a1s);
        if (ring == 0) {
            cnt--;
        } else {
            ptr[2] = (ptr[2] == 0);
            func_800D3234(ring, ptr[ptr[2]]);
            func_80046B44(ring);
            return 0;
        }
    } while (cnt != 0);
    return 1;
}
