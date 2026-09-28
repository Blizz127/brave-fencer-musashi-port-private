/* SC02 resident retail span [80162834,80162870). Offset 0x3A6DC at base 80128158.
 * SHA256(span)=3183d3de40d02a03f48ce91b49fe745201127afa0cb16e5fab22b3215e0a80a9.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F28->D_80187818.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162834 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187818[])(void);

void func_80162834(void *a0) {
    D_80187818[*(u8 *)((s32)a0 + 0x1)]();
}
