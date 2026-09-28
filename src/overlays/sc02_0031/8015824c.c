/* SC02 resident retail span [8015824C,80158288). Offset 0x300F4 at base 80128158.
 * SHA256(span)=d1c5c8b525455030c96a401b2ba7942ae8fd8856c76ae3aed1a0c4b60abfdc6d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806E0->D_80186FD0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015824C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186FD0[])(void);

void func_8015824C(void *a0) {
    D_80186FD0[*(u16 *)((s32)a0 + 0x2)]();
}
