/* SC02 resident retail span [80164E40,80164EA4). Offset 0x3CCE8 at base 80128158.
 * SHA256(span)=29f66ab913ec85c34e0f1ca45ad19f26d3d650d9fa89031bd2c98ffd1d0e81b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * retargeted for this member: D_801A4680->D_801B6510; D_801A4681->D_801B6511; D_801A4682->D_801B6512.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164E40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B6510;
extern u8 D_801B6511;
extern u8 D_801B6512;

s32 func_80164E40(void) {
    u8 *p = &D_801B6510;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_801B6511 != 0) {
        D_801B6511 -= 0x10;
    }
    if (D_801B6512 != 0) {
        D_801B6512 -= 0x10;
    }
    return *(s32 *)p == 0;
}
