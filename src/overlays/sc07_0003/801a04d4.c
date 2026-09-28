/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A04D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F1AC(void);
extern s32 func_80178B18(s32 a0, s32 a1);
extern s16 D_801A698C;

void func_801A04D4(s32 arg0) {
    s32 s0 = arg0;

    if (func_8016F1AC() == 0) {
        func_80178B18((s32)s0, (s32)&D_801A698C);
        *(s16 *)(s0 + 2) = 2;
        *(s16 *)(s0 + 0x34) = 0;
        *(s32 *)(s0 + 0x1C) = 0;
    }
}
