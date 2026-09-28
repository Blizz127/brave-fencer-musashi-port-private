/* SC02 resident retail span [80166618,80166654). Offset 0x3E4C0 at base 80128158.
 * SHA256(span)=95f373c5411fc75796b0e9ec5450091aee8f0f57368966f91f7162dabede1b31.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181330->D_80187C20.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80166618 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C20[])(void);

void func_80166618(void *a0) {
    D_80187C20[*(u16 *)((s32)a0 + 0x2)]();
}
