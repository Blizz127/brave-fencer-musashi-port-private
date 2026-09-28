/* SC02 resident retail span [80164EA4,80164EE0). Offset 0x3CD4C at base 80128158.
 * SHA256(span)=fe773662f46914b8cd88e0d3d1919f7d329d1f02048db15339fdbe14619130ac.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180FA0->D_80187890.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187890[])(void);

void func_80164EA4(void *a0) {
    D_80187890[*(u16 *)((s32)a0 + 0x2)]();
}
