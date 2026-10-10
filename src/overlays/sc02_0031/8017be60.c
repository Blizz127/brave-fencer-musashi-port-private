/* SC02 resident retail span [8017BE60,8017BE9C). Offset 0x53D08 at base 80128158.
 * SHA256(span)=985587ddd24817307dbfee398347868608eeeb60a676690e604d9ddcc81cfc14.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181D60->D_80188650.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BE60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188650[])(void *);

void func_8017BE60(void *a0) {
    D_80188650[*(u8 *)((s32)a0 + 0x4)](a0);
}
