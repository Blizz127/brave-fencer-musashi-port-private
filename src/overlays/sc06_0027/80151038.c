/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151038 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern s16 D_800B9A08;

void func_80151038(s32 a0) {
    s32 a2 = 0x18;
    if (D_800B9A08 == 0x30A0) {
        a2 = 0x30;
    }
    func_80151184(a0, 0xC00C, a2);
}
