/* Complete SC02 retail span [8014BCEC,8014BD24).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BCEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80078EB6;

s32 func_8014BCEC(s32 a0, s32 a1)
{
    u16 v;
    v = D_80078EB6 + a1;
    D_80078EB6 = v;
    if (v >= 0x663) {
        D_80078EB6 = 0x662;
    }
}
