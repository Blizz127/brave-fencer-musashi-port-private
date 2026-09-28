/* SC02.CD member31 [8014CA70,8014CA88); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CA70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


u16 func_8014CA70(s32 a0, s32 a1) {
    s32 base = *(s32 *)((s32)a0 + 0x78);
    return *(u16 *)((a1 << 1) + base + 0x14);
}
