/* SC02 resident retail span [80165658,80165670). Offset 0x3D500 at base 80128158.
 * SHA256(span)=3011c053929ec65153c608e016d527f8991581b7409631bc70f0d0e36afbb290.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181060->D_80187950.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165658 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80187950[];

u8 func_80165658(s32 a0, s32 a1) {
    return D_80187950[a1 & 0x7F];
}
