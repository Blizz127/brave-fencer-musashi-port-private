/* SC02 resident retail span [8013D13C,8013D164). Offset 0x14FE4 at base 80128158.
 * SHA256(span)=5a8aaafcc3e30a3336e625738522d45f62a5f8bb713b76d130dbc7b2a8391b6a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841BC->D_801B6374.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D13C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013D9B0();
extern s32 D_801B6374;

s32 func_8013D13C(void) {
    func_8013D9B0();
    return D_801B6374;
}
