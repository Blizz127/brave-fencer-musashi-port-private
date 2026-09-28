/* SC02 resident retail span [8015282C,80152868). Offset 0x2A6D4 at base 80128158.
 * SHA256(span)=f22ed61b063c4094072877246bf0b027b2838e0fb754da6d3b9150804db711cf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018010C->D_801869FC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015282C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801869FC[])(void);

void func_8015282C(void *a0) {
    D_801869FC[*(u16 *)((s32)a0 + 0x2)]();
}
