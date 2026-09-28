/* SC02 resident retail span [8016039C,801603D8). Offset 0x38244 at base 80128158.
 * SHA256(span)=386bdb0e4b23286658539ba3fce66961156223aa00b4b7d096cddd83f55c9a35.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E04->D_801876F4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016039C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8016039C(s32 *a0) {

    extern void (*D_801876F4[])(void);
    D_801876F4[*(u16 *)((s32)a0 + 0x2)]();
}
