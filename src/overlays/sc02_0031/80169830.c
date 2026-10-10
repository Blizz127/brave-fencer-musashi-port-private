/* SC02 resident retail span [80169830,8016986C). Offset 0x416D8 at base 80128158.
 * SHA256(span)=7aa1cd3a9acca3b8f4ed8406e4a2b912ab9440ed0c740b17e734a8147ec99437.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801813A4->D_80187C94.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169830 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C94[])(void *);

void func_80169830(void *a0) {
    D_80187C94[*(u16 *)((s32)a0 + 0x2)](a0);
}
