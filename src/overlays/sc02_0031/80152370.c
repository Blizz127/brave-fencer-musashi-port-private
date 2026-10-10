/* SC02 resident retail span [80152370,801523AC). Offset 0x2A218 at base 80128158.
 * SHA256(span)=c1b16eca721bfc932d03e8612a250f77c8b3698a3bf38962684d0a3ad0bb073e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801800D8->D_801869C8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152370 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801869C8[])(void *);

void func_80152370(void *a0) {
    D_801869C8[*(u16 *)((s32)a0 + 0x2)](a0);
}
