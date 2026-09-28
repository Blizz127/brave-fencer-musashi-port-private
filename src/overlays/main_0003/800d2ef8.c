/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2EF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 *D_800DB674;
extern s32 *D_800DB650;
extern s32 *D_800DB648;
extern s32 *D_800DB64C;
extern u32 func_800D3020();

void func_800D2EF8(s32 a0, s32 a1) {
    s32 s1;
    u32 s0;
    s1 = a0;
    s0 = (u32)a1;
    func_800D3020();
    s0 >>= 5;
    *D_800DB674 |= 0x88;
    *D_800DB650 = 0;
    *D_800DB648 = s1;
    *D_800DB64C = (s32)(s0 << 16) | 0x20;
    *D_800DB650 = 0x1000200;
}
