/* SC02 resident retail span [80163A58,80163A94). Offset 0x3B900 at base 80128158.
 * SHA256(span)=86516446970e46fa0e4773e0bec6bd0e663fa87bc052a453f31395a60b23b872.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F30->D_80187820.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80163A58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187820[])(void *);

void func_80163A58(void *a0) {
    D_80187820[*(u16 *)((s32)a0 + 0x2)](a0);
}
