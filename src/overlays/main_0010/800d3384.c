/* Exact retail overlay 0010 export [800D3384,800D3398), offset 0x2458C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D3384 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D3384(u8 *arg0) {
    *(u8 *)(arg0 + 0x214) += 1;
}
