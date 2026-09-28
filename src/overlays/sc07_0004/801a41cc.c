/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A41CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F8744[];

void func_801A41CC(void) {
    s32 i;
    u8 *src;
    s32 n;
    s32 dst;
    i = 1;
    src = D_801F8744;
    n = 4;
    dst = 0x40;
    while (i < 4) {
        D_801F8744[dst + 0] = (src[0] >> 2) * (n - i);
        D_801F8744[dst + 1] = (src[1] >> 2) * (n - i);
        D_801F8744[dst + 2] = (src[2] >> 2) * (n - i);
        dst += 0x40;
        i++;
    }
}
