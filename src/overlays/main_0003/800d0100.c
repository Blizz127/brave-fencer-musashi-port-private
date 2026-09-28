/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0100 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern void (*D_800D363C[])(void);

void func_800D0100(void) {
    register u8 *p = D_800AF630;
    D_800D363C[*(u16 *)(p + 0xA3B4)]();
}
