/* SC02 resident retail span [80174F28,80174F64). Offset 0x4CDD0 at base 80128158.
 * SHA256(span)=4cfae82bbccd1a328332638f08121aeed34474c1ec37c93e24b98f8914ee5f81.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181A00->D_801882F0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174F28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80174F28(void *a0) {

    extern void (*D_801882F0[])(void);
    D_801882F0[*(u8 *)((s32)a0 + 0x4)]();
}
