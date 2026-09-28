/* SC02 resident retail span [80168744,80168780). Offset 0x405EC at base 80128158.
 * SHA256(span)=9045700e4854c0ae453e7c290bdcd9eec4f89eff4ad454d519ec3352168943c4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181374->D_80187C64.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187C64[])(void);

void func_80168744(void *a0) {
    D_80187C64[*(u16 *)((s32)a0 + 0x2)]();
}
