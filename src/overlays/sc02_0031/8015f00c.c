/* SC02 resident retail span [8015F00C,8015F048). Offset 0x36EB4 at base 80128158.
 * SHA256(span)=35c3ad46030c6e4a4d2d25fbe7fcd299ddb2cfedc52c6a4095576e75e5932ffe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D18->D_80187608.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F00C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015F00C(s32 *a0) {

    extern void (*D_80187608[])(s32 *);
    D_80187608[*(u16 *)((s32)a0 + 0x2)](a0);
}
