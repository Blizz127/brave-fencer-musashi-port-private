/* Exact retail overlay 0010 export [800D2624,800D2650), offset 0x2382C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2624 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800B9A13;
extern void func_8002D4C8(s32 arg0, s32 arg1);

void func_800D2624(void) {
    D_800B9A13 = 0;
    func_8002D4C8(0x15, 0);
}
