/* Complete SC02 retail span [8014AD7C,8014ADA8).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014AD7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126B58;
extern void func_8014ADA8(s32 a0, s32 a1);

void func_8014AD7C(s32 a0) {
    func_8014ADA8((s32)&D_80126B58, a0);
}
