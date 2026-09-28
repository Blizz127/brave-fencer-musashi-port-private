/* SC02 resident retail span [80131F28,80131F64). Offset 0x9DD0 at base 80128158.
 * SHA256(span)=b393dffb5227903f4dc17ae2e768d6e4ddd92afb9f5096c4fab2315331a776ad.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E8F0->D_801851E0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131F28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801851E0[])(void);

void func_80131F28(void *a0) {
    D_801851E0[*(u16 *)((s32)a0 + 0x2)]();
}
