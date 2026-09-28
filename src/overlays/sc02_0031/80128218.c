/* SC02 resident retail span [80128218,80128228). Offset 0xC0 at base 80128158.
 * SHA256(span)=838b34049533ad069b4fa45c8d858297006ead52bed045a0073f084b5eedc833.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128218 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B5128;

s32 func_80128218(void) {
    return D_801B5128;
}
