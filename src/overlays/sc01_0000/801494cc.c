/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801494CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012F038(int param_1, short *param_2, short *param_3);

void func_801494CC(s32 a0, u16 *a1, u16 *a2) {
    u16 dst[3];
    u16 src[3];
    src[0] = a1[1];
    src[1] = a1[3];
    src[2] = a1[5];
    ((void (*)(s32, u16 *, u16 *))func_8012F038)(*(s32 *)(a0 + 0x20) + 0x34, src, dst);
    a2[1] = dst[0];
    a2[3] = dst[1];
    a2[5] = dst[2];
}
