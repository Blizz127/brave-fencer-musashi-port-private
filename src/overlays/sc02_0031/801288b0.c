/* SC02 resident retail span [801288B0,801288E8). Offset 0x758 at base 80128158.
 * SHA256(span)=be4549dc7d23880bf3179da53b32980e24ab3ded181d99e8f219619d92293ca2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801288B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801B5128;
extern u8 D_800AEFD0;

s32 func_801288B0(void) {
    func_8001ABBC(0, 0, &D_800AEFD0, D_801B5128, 0);
}
