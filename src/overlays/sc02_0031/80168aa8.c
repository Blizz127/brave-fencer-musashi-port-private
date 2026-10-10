/* SC02 resident retail span [80168AA8,80168AE4). Offset 0x40950 at base 80128158.
 * SHA256(span)=6fcc99214f924973d73dfbb6ef7e09923194e9c267148c228dd4629c98cb9d87.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181384->D_80187C74.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168AA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C74[])(void *);

void func_80168AA8(void *a0) {
    D_80187C74[*(u16 *)((s32)a0 + 0x2)](a0);
}
