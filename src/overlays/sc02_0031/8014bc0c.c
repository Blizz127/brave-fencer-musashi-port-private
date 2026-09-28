/* Complete SC02 retail span [8014BC0C,8014BC44).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BC0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80078EB2;

void func_8014BC0C(s32 a0, s32 a1) {
    D_80078EB2 += a1;
    if ((u16)D_80078EB2 >= 0x1F5) {
        D_80078EB2 = 0x1F4;
    }
}
