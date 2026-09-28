/* Exact retail overlay 0010 export [800CEE40,800CEE84), offset 0x20048. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEE40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800B99F6;
extern void (*D_800D3480[])(void);

void func_800CEE40(void) {
    if (D_800B99F6 < 2) {
        D_800D3480[D_800B99F6]();
    }
}
