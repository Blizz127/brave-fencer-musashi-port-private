/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F40C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8004914C();
extern void func_800491AC();
extern s32 func_8004955C(s32, s32, s32*, s32*);

s32 *func_8012F40C(s32 *param_1, s32 param_2) {
    extern u8 D_800AF648;
    s32 sxy, p, flag;
    sxy = 0;
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_8004914C(r4); }
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_800491AC(r4); }
    ((s32 (*)(s32, s32 *, s32 *, s32 *))func_8004955C)(param_2, &sxy, &p, &flag);
    if (flag < 0) {
        *param_1 = sxy = 0;
    } else {
        *param_1 = sxy;
    }
    return param_1;
}
