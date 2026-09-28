/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA160 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);
extern void func_8004864C(void *a0, void *a1);
extern void func_80048B6C(void *a0, void *a1);
extern u8 D_801B0790[];
extern u8 D_801B07A0[];

void func_801AA160(s32 arg0, s32 arg1)
{
    s32 vec[12]; /* sp+0x10 */
    s32 s1;
    s32 s0;

    s1 = arg1;
    s0 = func_80132EF4(arg0, 0x22);
    if (s0 != 0) {
        func_8004864C((void *)(D_801B0790 + (s1 << 3)), vec);
        *(u16 *)(s0 + 0x6) += vec[0];
        *(u16 *)(s0 + 0xA) += vec[1];
        *(u16 *)(s0 + 0xE) += vec[2];
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x2C) = 0xC020;
        func_80048B6C((void *)(D_801B07A0 + (s1 << 4)), (void *)(s0 + 0x10));
        *(u16 *)(s0 + 0x34) = 0x3400;
    }
}
