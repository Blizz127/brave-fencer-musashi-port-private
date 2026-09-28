/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801725E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801725E0(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x10;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
