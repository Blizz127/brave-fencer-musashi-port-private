/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2E64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 *D_800DB674;
extern s32 *D_800DB63C;
extern s32 *D_800DB640;
extern s32 *D_800DB66C;
extern s32 *D_800DB644;
extern void func_800D2F88(s32 a0, s32 a1);

void func_800D2E64(s32 a0, s32 a1) {
    u32 s0;
    s32 s1;
    s1 = a0;
    s0 = (u32)a1;
    func_800D2F88(a0, a1);
    s0 = (s0 >> 5) << 16;
    *D_800DB674 |= 0x88;
    *D_800DB63C = s1 + 4;
    *D_800DB640 = s0 | 0x20;
    *D_800DB66C = *(s32 *)s1;
    *D_800DB644 = 0x1000201;
}
