/* SC02 resident retail span [80161C98,80161CD0). Offset 0x39B40 at base 80128158.
 * SHA256(span)=c4c9809b7caab251bbf97432bdea9cb73f22f3e08bdffaccc3f355f60456ca67.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E58->D_80187748.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161C98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80187748[];
extern void func_80147324(s32 arg0);

void func_80161C98(int param_1, u32 param_2)
{
    if (param_2 < 8) {
        func_80147324(D_80187748[param_2]);
    }
    return;
}
