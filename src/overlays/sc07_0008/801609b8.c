/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801609B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_801487F4(s32 *a0);
extern void func_80160A74(s32 *a0);
extern s32 func_80161208();
extern void (*D_8017F99C[])(void*);

void func_801609B8(u16 *param_1) {
    if ((((u32 (*)(void))func_801487F4)() & 8) == 0) {
        ((void (**)(u16*))D_8017F99C)[*param_1](param_1);
        ((void (*)(u16 *))func_80160A74)(param_1);
    } else {
        ((void (*)(u16 *))func_80161208)(param_1);
    }
}
