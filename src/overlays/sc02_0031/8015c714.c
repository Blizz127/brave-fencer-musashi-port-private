/* SC02 resident retail span [8015C714,8015C750). Offset 0x345BC at base 80128158.
 * SHA256(span)=1e93c33afe18173ca7414e63e4d7da17315c3f118225247c6b4ff3da55e5fd04.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180BA8->D_80187498.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C714 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187498[])(void *);

void func_8015C714(void *a0) {
    D_80187498[*(u16 *)((s32)a0 + 0x2)](a0);
}
