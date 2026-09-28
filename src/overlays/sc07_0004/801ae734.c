/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE734 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u8 unk0[4]; } M4_801AE734;
extern s32 func_801AEA40(s32 a0, s32 a1, s32 a2);
extern M4_801AE734 D_801B0838[];
extern u8 D_801B0868[];

void func_801AE734(s32 arg0) {
    s32 s0;
    register s32 t1 __asm__("$9");
    s32 m;

    s0 = arg0;
    t1 = func_801AEA40(0x200, *(s32 *)(s0 + 0x20) + 0x10, 0x50000000);
    if (t1 != 0) {
        m = (s16)*(u16 *)(s0 + 0x2C) % 6;
        *(s32 *)(s0 + 0x34) = t1;
        *(u16 *)(s0 + 0x2E) = *(u16 *)(s0 + 0x2C);
        *(M4_801AE734 *)(t1 + 0x14) = D_801B0838[(s16)(m * 2)];
        *(M4_801AE734 *)(t1 + 0x18) = D_801B0838[(s16)(m * 2) + 1];
        *(s16 *)(t1 + 0x12) = -0x3F80;
        *(u16 *)(t1 + 0x10) = 0x200;
        *(u16 *)(t1 + 0xC) = 0x200;
        m = D_801B0868[*(s16 *)(s0 + 0x2C)];
        *(u16 *)(s0 + 2) = *(u16 *)(s0 + 2) + 1;
        *(s32 *)(s0 + 0x1C) = m;
    }
}
