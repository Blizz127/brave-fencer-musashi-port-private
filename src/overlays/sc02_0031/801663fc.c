/* SC02 resident retail span [801663FC,80166438). Offset 0x3E2A4 at base 80128158.
 * SHA256(span)=3a2a9364152b5ad9ac4190c922bbef5a00d6e8e9ba5212da3d2e68cb97b59535.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181268->D_80187B58.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801663FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187B58[])(void);

void func_801663FC(void *a0) {
    D_80187B58[*(u16 *)((s32)a0 + 0x2)]();
}
