/* Complete SC02 retail span [8014BF8C,8014BFB0).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BF8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800291A0(s32, s32);

void func_8014BF8C(u8 arg0) {
    func_800291A0(0xD0, arg0);
}
