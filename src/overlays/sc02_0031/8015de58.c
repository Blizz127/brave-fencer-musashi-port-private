/* SC02 resident retail span [8015DE58,8015DE94). Offset 0x35D00 at base 80128158.
 * SHA256(span)=27af050874fb5eaadd45cd7542c7ba7b25fed62f3212eb15fc88b9407c28e794.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180CB4->D_801875A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DE58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015DE58(s32 *a0) {

    extern void (*D_801875A4[])(s32 *);
    D_801875A4[*(u16 *)((s32)a0 + 0x2)](a0);
}
