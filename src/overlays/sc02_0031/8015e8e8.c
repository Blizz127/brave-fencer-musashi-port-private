/* SC02 resident retail span [8015E8E8,8015E924). Offset 0x36790 at base 80128158.
 * SHA256(span)=ac9ff4f179947c1a9bd8ef60b1a70842fe8099cb0cf5e4d79eb6dd4b1772e970.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D08->D_801875F8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E8E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015E8E8(s32 *a0) {

    extern void (*D_801875F8[])(s32 *);
    D_801875F8[*(u16 *)((s32)a0 + 0x2)](a0);
}
