/* SC02 resident retail span [8016FDB4,8016FDF0). Offset 0x47C5C at base 80128158.
 * SHA256(span)=14d1ff45652d3787866c891db03f2d2198dc49d53fdf98dd988a2efe55d8b31a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181820->D_80188110.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FDB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188110[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016FDB4(void *a0) {
    D_80188110[*(u8 *)((s32)a0 + 0x216)](a0);
}
