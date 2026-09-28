/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA91C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);
extern s32 func_8005C49C(void);

void func_801AA91C(s32 param_1, s32 param_2, s32 param_3)
{
    register s32 s1 __asm__("$17") = param_1;
    register s32 s2 __asm__("$18") = param_2;
    register s32 s3 __asm__("$19") = param_3;
    register s32 s0 __asm__("$16");

    s0 = func_80132EF4(param_1, 0x71);

    if (s0 != 0) {
        *(u16 *)(s0 + 0xA) += *(u16 *)(s1 + 0x52);
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x10) = s2;
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x12) = s3;
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x14) = 0;
        *(u16 *)(s0 + 0x30) = 5;
        *(u16 *)(s0 + 0x32) = 0;
        if (func_8005C49C() & 1) {
            *(s32 *)(s0 + 0x34) = 0x180FF80;
        } else {
            *(s32 *)(s0 + 0x34) = 0x1FF8080;
        }
    }
}
