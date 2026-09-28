/* SC02 resident retail span [80128940,80128998). Offset 0x7E8 at base 80128158.
 * SHA256(span)=cc0025330b2ec847e55d555a6a7f1b6b91924cd1ae44d3de2292ff4e18614e48.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128940 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern int D_800C7C60;
extern int *D_800C7C64;
extern int D_800A2E20;
extern u8 D_800AF560;
extern s32 D_801B5128;

s32 func_80128940(s32 _arg0)
{
    s32 *p = &D_800C7C60;
    *p = 0x5E;
    D_800C7C64 = &D_800A2E20;
    ((void (*)(s32, s32, void *, s32, void *))func_8001ABBC)(0, 0, &D_800AF560, D_801B5128, p);
}
