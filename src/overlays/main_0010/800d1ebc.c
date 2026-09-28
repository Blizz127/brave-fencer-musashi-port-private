/* Exact retail overlay 0010 export [800D1EBC,800D1F58), offset 0x230C4. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1EBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern u16 D_80078E50;
extern s32 func_800CFC5C(s32);
extern s32 func_800CFD68(s32);
extern u16 func_800168C4(s32);
extern u16 func_800167F0(s32);

s32 func_800D1EBC(void) {
    s32 state;
    s16 loc = D_800B9A08;
    u16 ret;

    if (loc == 0x3005) {
        state = 2;
    } else if (func_800CFC5C(loc) != 0) {
        state = 2;
    } else if (func_800CFD68(D_80078E50) == 0) {
        state = 2;
    } else if (func_800CFC5C(D_80078E50) != 0) {
        state = 2;
    } else {
        state = 1;
    }

    if (state < 0) {
        ret = func_800167F0(4);
    } else if (state < 2) {
        ret = func_800168C4(4);
    } else {
        ret = func_800167F0(4);
    }
    return ret != 0;
}
