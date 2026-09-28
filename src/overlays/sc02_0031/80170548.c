/* SC02 resident retail span [80170548,80170584). Offset 0x483F0 at base 80128158.
 * SHA256(span)=c64be7d8d573834e2988512f3a1e75b5e46ddcc257c19a3d863521000ffc63d7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181870->D_80188160.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170548 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188160[])(void);
extern void func_8012A568(void (*a0)(void));

void func_80170548(void *a0) {
    D_80188160[*(u8 *)((s32)a0 + 0x216)]();
}
