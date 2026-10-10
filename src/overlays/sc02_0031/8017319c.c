/* SC02 resident retail span [8017319C,801731D8). Offset 0x4B044 at base 80128158.
 * SHA256(span)=fea196d459cfeb6adf7d781022b73c8cd203efea56a454cfbe1419cee00926a6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181958->D_80188248.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017319C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_8017319C(void *a0) {

    extern void (*D_80188248[])(void *);
    D_80188248[*(u8 *)((s32)a0 + 0x214)](a0);
}
