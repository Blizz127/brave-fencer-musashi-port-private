/* Exact retail overlay 0010 export [800D2DAC,800D2DFC), offset 0x23FB4. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2DAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D3238(void *arg0);
extern void func_8016EDEC(void *arg0, s32 arg1);
extern void func_800167B8(s32 arg0);

s32 func_800D2DAC(u8 *arg0) {
    func_8016EDEC(func_800D3238, 0x1000000);
    func_800167B8(0);
    arg0[0x15]++;
    return 0;
}
