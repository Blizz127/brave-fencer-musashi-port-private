/* SC02 resident retail span [80152058,80152094). Offset 0x29F00 at base 80128158.
 * SHA256(span)=7d6c7f9eabba589b96d0a282a18f1fdfd68b9c3dc5122c2d7681e756c8a58b8d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800C4->D_801869B4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152058 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801869B4[])(void *);

void func_80152058(void *a0) {
    D_801869B4[*(u16 *)((s32)a0 + 0x2)](a0);
}
