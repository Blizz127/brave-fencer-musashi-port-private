/* SC02 resident retail span [80165700,80165718). Offset 0x3D5A8 at base 80128158.
 * SHA256(span)=5b86052886aaec3137f5917bd59a3d84ff3713dedce857a53188c0225c0d65ba.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018113C->D_80187A2C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165700 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80187A2C[];

u8 func_80165700(s32 a0, s32 a1) {
    return D_80187A2C[a1 & 0x7F];
}
