/* SC02 resident retail span [8013B7F4,8013B83C). Offset 0x1369C at base 80128158.
 * SHA256(span)=016908d764b8c30e2e810909a3f262c781c3ac810aed950edff6de5442f14784.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C74->D_801B7B04.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B7F4 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013B83C(s32 a0, s32 a1, s32 a2);

void func_8013B7F4(s32 a0, s32 a1) {

    extern s32 D_801B7B04;
    func_8013B83C(a0, a1, D_801B7B04);
}
