/* SC02 resident retail span [80172CA0,80172CDC). Offset 0x4AB48 at base 80128158.
 * SHA256(span)=5559d3171f6aedd9b6aedd466fa7cee64949639611e2d919e120ea1f5e57633a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181934->D_80188224.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172CA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188224[])(void *);

void func_80172CA0(void *a0) {
    D_80188224[*(u8 *)((s32)a0 + 0x214)](a0);
}
