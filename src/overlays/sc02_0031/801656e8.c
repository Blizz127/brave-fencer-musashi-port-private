/* SC02 resident retail span [801656E8,80165700). Offset 0x3D590 at base 80128158.
 * SHA256(span)=30a2c5c8c36bf4c1bb94ac4ba2e293689c134853b9db6f98400f362563b7b69e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018111C->D_80187A0C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801656E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80187A0C[];

u8 func_801656E8(s32 a0, s32 a1) {
    return D_80187A0C[a1 & 0x7F];
}
