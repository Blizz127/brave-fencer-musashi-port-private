/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD5B4 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern u16 D_801B0828[];

void func_801AD5B4(s32 param_1, s32 param_2) {
    s32 s2;
    s32 s0;
    s32 s1;
    s32 r;
    s32 b;

    s2 = param_1;
    s0 = param_2;
    s1 = func_80132EF4(param_1, 0x2F);

    if (s1 != 0) {
        r = func_8005C49C();
        s0 = s0 & 3;
        b = D_801B0828[s0] - 0x40;
        *(u16 *)(s1 + 0x2C) = b + (r & 0x7C);
        r = func_8005C49C();
        *(u16 *)(s1 + 0x2E) = s0 + ((r & 3) << 12);
        *(s32 *)(s1 + 0x34) = s2;
    }
}
