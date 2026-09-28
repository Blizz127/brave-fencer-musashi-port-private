/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801620C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_800291DC(int);
extern int func_800D0E30(void *a0);

int func_801620C4(void) {
    short local;
    int lo;
    local = func_800291DC(8) & 0x7FFF;
    local = func_800D0E30(&local);
    lo = *(unsigned char *)&local;
    return (short)(*((unsigned char *)&local + 1) * 100 + lo);
}
