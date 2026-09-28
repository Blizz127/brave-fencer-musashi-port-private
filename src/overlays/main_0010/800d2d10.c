/* Exact retail overlay 0010 export [800D2D10,800D2DAC), offset 0x23F18. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2D10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D2D10(val, n, dst, flag)
unsigned int val;
short n;
unsigned short *dst;
short flag;
{
    extern unsigned short *D_800D38D8[];
    register unsigned int d __asm__("$8");
    short i;
    int idx;

    for (i = 0; i < n; i++) {
        d = val >> 28;
        idx = d;
        if (flag != 0) {
            if (d != 0) {
                flag = 0;
            } else if (flag < 0) {
                idx = (i != n - 1) ? 10 : 0;
            } else {
                idx = 10;
            }
        }
        val <<= 4;
        *dst = *D_800D38D8[idx];
        dst++;
    }
}
