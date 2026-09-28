/* SC02 resident retail span [8013E054,8013E064). Offset 0x15EFC at base 80128158.
 * SHA256(span)=dfe83c6abe02ccfdedbaed0ea894cd5df31aa6f0f64eeb750bc7133f5df761c5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841C4->D_801B637C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E054 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B637C;

s32 func_8013E054(void) {
    return D_801B637C;
}
