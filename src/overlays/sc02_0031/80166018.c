/* SC02 resident retail span [80166018,80166054). Offset 0x3DEC0 at base 80128158.
 * SHA256(span)=5d9abb904a1792dd78c2c0a810ecf6d35378e5f894f1c1e3e2bb0fc8bdd989db.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181260->D_80187B50.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80166018 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187B50[])(void);

void func_80166018(void *a0) {
    D_80187B50[*(u16 *)((s32)a0 + 0x2)]();
}
