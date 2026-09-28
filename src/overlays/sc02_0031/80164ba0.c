/* SC02 resident retail span [80164BA0,80164BDC). Offset 0x3CA48 at base 80128158.
 * SHA256(span)=e0e8364213b00f74b74f394ff72d93a9b31f81d1aee39466d1d8fd1938ba3007.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F90->D_80187880.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164BA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187880[])(void);

void func_80164BA0(void *a0) {
    D_80187880[*(u16 *)((s32)a0 + 0x2)]();
}
