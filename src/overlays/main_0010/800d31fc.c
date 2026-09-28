/* Exact retail overlay 0010 export [800D31FC,800D3238), offset 0x24404. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D31FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_800D3928[])(void);

void func_800D31FC(u8 *arg0) {
    D_800D3928[arg0[0x15]]();
}
