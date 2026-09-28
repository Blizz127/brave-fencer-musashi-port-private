/* SC02 resident retail span [8015AD3C,8015AD78). Offset 0x32BE4 at base 80128158.
 * SHA256(span)=90b0751db56f2f11260c31afe03854ce90fcbc3edd9c90010f8918d648bdeed6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B74->D_80187464.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015AD3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187464[])(void);

void func_8015AD3C(void *a0) {
    D_80187464[*(u16 *)((s32)a0 + 0x2)]();
}
