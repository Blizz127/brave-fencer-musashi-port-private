/* SC02 resident retail span [801736FC,80173738). Offset 0x4B5A4 at base 80128158.
 * SHA256(span)=8aa27d66937784cc7d1f55b061c1223656ad5796f7b2ff3e272e34ca1563f018.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181978->D_80188268.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801736FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801736FC(void *a0) {

    extern void (*D_80188268[])(void);
    D_80188268[*(u8 *)((s32)a0 + 0x214)]();
}
