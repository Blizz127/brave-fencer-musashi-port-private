/* SC02 resident retail span [80169F00,80169F3C). Offset 0x41DA8 at base 80128158.
 * SHA256(span)=1ec26a9b99b1a9c1888c97e8630d10738edacf90e66c99b1e36492ecfc4c7449.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181460->D_80187D50.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169F00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187D50[])(void *);

void func_80169F00(void *a0) {
    D_80187D50[*(u16 *)((s32)a0 + 0x2)](a0);
}
