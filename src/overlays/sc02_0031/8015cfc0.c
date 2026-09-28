/* SC02 resident retail span [8015CFC0,8015CFFC). Offset 0x34E68 at base 80128158.
 * SHA256(span)=e3246b951e0bb994ead6470aa0516edb7dd0c82134ee756fa0e0da28d1a134b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180BF0->D_801874E0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CFC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015CFC0(s32 *a0) {

    extern void (*D_801874E0[])(void);
    D_801874E0[*(u16 *)((s32)a0 + 0x2)]();
}
