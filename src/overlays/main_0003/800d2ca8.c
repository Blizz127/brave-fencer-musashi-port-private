/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2CA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D2F88(s32 a0, s32 a1);
extern s32 func_800D30B8(void);

s32 func_800D2CA8(s32 a0, s32 a1) {
    s32 var;
    if (a0 == 0) {
        var = ((s32 (*)())func_800D2F88)();
    } else {
        var = (((u32 (*)(void))func_800D30B8)() >> 29) & 1;
    }
    return var;
}
