/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016236C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014706C(void *a0);
extern s32 D_80126B58;

s32 func_8016236C(u8 *a0) {
    func_8014706C(&D_80126B58);
    *(s32 *)(a0 + 0x28) = 0xA;
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
