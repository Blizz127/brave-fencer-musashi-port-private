/* Exact retail overlay 0010 export [800D33B8,800D33E0), offset 0x245C0. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D33B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D3AAC;
extern void func_8016EE40(u8 *arg0, s32 arg1);

void func_800D33B8(void) {
    func_8016EE40(&D_800D3AAC, 0x1000000);
}
