/* SC02 resident retail span [80166654,80166690). Offset 0x3E4FC at base 80128158.
 * SHA256(span)=12380af1913a31410920fd2f8b1f3669aed08869f2a8ab2b0f9c12e5473c2c6f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181340->D_80187C30.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80166654 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C30[])(void);

void func_80166654(void *a0) {
    D_80187C30[*(u16 *)((s32)a0 + 0x2)]();
}
