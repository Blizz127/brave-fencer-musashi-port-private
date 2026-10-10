/* SC02 resident retail span [80160138,80160174). Offset 0x37FE0 at base 80128158.
 * SHA256(span)=20515e702c963f38365380fe714d59787d3e91a804bd595ca5eba99857dbdf32.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180DF4->D_801876E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160138 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80160138(s32 *a0) {

    extern void (*D_801876E4[])(s32 *);
    D_801876E4[*(u16 *)((s32)a0 + 0x2)](a0);
}
