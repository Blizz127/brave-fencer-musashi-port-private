/* SC02 resident retail span [8016BFA8,8016BFD0). Offset 0x43E50 at base 80128158.
 * SHA256(span)=3a9b71c5dd6384cf7ee5fa6911f99bc617170abdee62e0dc19716947d200e05f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184780->D_801B6938.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016BFD0(s32 a0, s32 a1, s32 a2, s32 a3, void *a4);
extern s32 D_801B6938;
extern void func_8012A568(void (*a0)(void));

void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_801B6938);
}
