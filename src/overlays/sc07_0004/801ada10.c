/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADA10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u8 unk0[4]; } M4_801AE734;
extern M4_801AE734 D_801B0838[];

void func_801ADA10(s32 a0) {
    s32 m;
    s32 d;

    m = (s16)(*(u16 *)(a0 + 0x2E) + 1) % 6;
    *(u16 *)(a0 + 0x2E) = *(u16 *)(a0 + 0x2E) + 1;
    d = *(s32 *)(a0 + 0x34);
    *(M4_801AE734 *)(d + 0x14) = D_801B0838[(s16)(m * 2)];
    *(M4_801AE734 *)(d + 0x18) = D_801B0838[(s16)(m * 2) + 1];
}
