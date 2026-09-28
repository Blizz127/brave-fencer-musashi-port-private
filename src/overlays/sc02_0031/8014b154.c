/* Complete SC02 retail span [8014B154,8014B160).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B154 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8014B154(s32 *a0) {
    return *(s32*)((s32)a0 + 0x44) & 0x80;
}
