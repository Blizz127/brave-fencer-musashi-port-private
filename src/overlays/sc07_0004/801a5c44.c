/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5C44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004787C(s32 a0);

void func_801A5C44(void) {
    register s32 a0 __asm__("$4");
    s32 s0 = a0;
    s32 s2;
    s32 s1;
    s32 temp;

    temp = *(s16 *)(s0 + 0x100);
    s2 = *(s32 *)(s0 + 0xCC);
    s1 = *(s32 *)(s0 + 0xD4);
    temp = func_8004787C(temp) >> 4;
    *(s16 *)(s2 + 0x18) = *(u16 *)(s1 + (*(s16 *)(s0 + 0x70) * 4)) + temp;
    temp = func_8004787C(*(s16 *)(s0 + 0x100) + 0x800) >> 4;
    *(s16 *)(s2 + 0x1A) = *(u16 *)(s1 + (*(s16 *)(s0 + 0x70) * 4) + 2) + temp;
    *(u16 *)(s0 + 0x100) += 0x40;
}
