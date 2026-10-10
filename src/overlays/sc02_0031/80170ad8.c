/* SC02 resident retail span [80170AD8,80170B14). Offset 0x48980 at base 80128158.
 * SHA256(span)=1643b67e0f032d1a478729492be0b290f6e6b1fccecc8c2bcbc5caa6c4e0e004.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181898->D_80188188.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170AD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188188[])(void *);

void func_80170AD8(void *a0) {
    D_80188188[*(u8 *)((s32)a0 + 0x216)](a0);
}
