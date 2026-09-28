/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80156648 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80156A14(s32 *a0);

void func_80156648(s32 *a0) {
    *((u8 *)a0 + 0x1A8) = 0;
    *((u8 *)a0 + 0x1A9) = 0;
    *((u8 *)a0 + 0x1C0) = 0;
    func_80156A14(a0);
}
