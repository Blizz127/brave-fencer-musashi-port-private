/* Complete SC02 retail span [80148980,801489E8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148980 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80148980(u8 *a0) {
    u8 c;
    s32 v0;
    c = a0[0xA9];
    switch (c) {
    case 0x41:
        v0 = *(u16 *)(a0 + 0xAA) & 0x4000;
        break;
    case 0x53:
    case 0x73:
        v0 = ((u32)*(u16 *)(a0 + 0xAE) >> 8) < 0xC1;
        v0 = v0 ^ 1;
        break;
    default:
        v0 = 0;
        break;
    }
    return v0;
}
