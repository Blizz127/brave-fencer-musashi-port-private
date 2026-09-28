/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80177AD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80177AD4(int param_1, unsigned int param_2) {
    register unsigned int c __asm__("$2");
    register unsigned int b __asm__("$3");
    char *base; short i; int f; int t;
    f = 0x100; i = 0; base = (char *)param_1;
    do {
        c = (param_2 << 16) >> 28;
        b = c;
        if ((c != 0) || (i == 3) || (i == 1)) f = 0;
        param_2 = param_2 << 4; i = i + 1;
        t = *(unsigned short *)(base + 0x1e);
        *(unsigned short *)(base + 0x1e) = f | (t & ~0x100);
        base[0x20] = b * 8 + 8;
        base = base + 0x14;
    } while (i < 4);
}
