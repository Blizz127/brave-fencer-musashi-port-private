/* Exact retail overlay 0010 export [800D33E0,800D3408), offset 0x245E8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D33E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D3AB0;
extern void func_8016EE40(u8 *arg0, s32 arg1);

void func_800D33E0(void) {
    func_8016EE40(&D_800D3AB0, 0x1000000);
}
