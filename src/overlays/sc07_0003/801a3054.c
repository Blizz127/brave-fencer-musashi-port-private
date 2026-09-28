/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3054 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B66;
extern u16 D_80126B5E;
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_801A3054(s32 s0, s32 a1, s32 s1) {
    s32 v0;
    s32 v1;

    v0 = func_8004CFEC(*(s16 *)(a1 + 4) - *(s16 *)&D_80126B66,
                *(s16 *)&D_80126B5E - *(s16 *)(a1 + 0));
    v0 = ((v0 - 0x400) & 0xFFF) - *(s16 *)(*(s32 *)(s0 + 0x20) + 0x12);
    v1 = v0 & 0xFFF;
    if (v1 < 0x800) {
        return v1 < (s16)s1;
    }
    return 0x1000 - v1 < (s16)s1;
}
