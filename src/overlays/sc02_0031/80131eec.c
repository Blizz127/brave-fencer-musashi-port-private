/* SC02 resident retail span [80131EEC,80131F28). Offset 0x9D94 at base 80128158.
 * SHA256(span)=2eb44c06f60955d6a59135c3f089364d414954f98436ac6a9d5e818cc73859f6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E8A8->D_80185198.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131EEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80185198[])(void);

void func_80131EEC(void *a0) {
    D_80185198[*(u16 *)((s32)a0 + 0x2)]();
}
