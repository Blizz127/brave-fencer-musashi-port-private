/* SC02 resident retail span [8013D164,8013D178). Offset 0x1500C at base 80128158.
 * SHA256(span)=6349d58e7da1a8bfa1907391e4dc3a2f2fba28d6db95c5fe16e2428f4657e86c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841C8->D_801B6380.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D164 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B6380;

void func_8013D164(void) {
    D_801B6380 = 1;
}
