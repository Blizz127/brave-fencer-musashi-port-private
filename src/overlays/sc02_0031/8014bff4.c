/* Complete SC02 retail span [8014BFF4,8014C010).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BFF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014BFF4(s32 a0, s32 a1) {
    if (*(u8 *)(a0 + 0x4E) == 0) {
        *(u8 *)(a0 + 0x4E) = a1;
    }
}
