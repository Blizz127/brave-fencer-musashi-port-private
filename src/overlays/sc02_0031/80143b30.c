/* SC02 resident retail span [80143B30,80143B6C). Offset 0x1B9D8 at base 80128158.
 * SHA256(span)=c1eb4b002c49f77a2d1e155d9ed4c5ddadfb54ea6df87cf70b4aec994e4a5a59.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FCA4->D_80186594.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143B30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80186594[])(void);

void func_80143B30(void *a0) {
    D_80186594[*(u16 *)((s32)a0 + 0x2)]();
}
