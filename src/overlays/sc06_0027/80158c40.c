/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158C40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_801487F4(s32 *a0);
extern s32 func_80159404(s32 a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_80158C40(s32 *a0) {
    s32 n;
    s32 c;
    c = 0x3C000;
    n = 1;
    if (func_801487F4(a0) & 0xF0) {
        n = 4;
    }
    while (n > 0) {
        func_80159404((s32)a0, c);
        if (a0[0x234 / 4] < 0) {
            func_80146E90(a0, 4);
            func_80146CA0(a0);
            n = 0;
        }
        n--;
    }
}
