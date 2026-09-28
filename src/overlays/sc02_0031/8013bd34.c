/* SC02 resident retail span [8013BD34,8013BD74). Offset 0x13BDC at base 80128158.
 * SHA256(span)=0e85d0fe54e984adc8c2909a84e060ee05015d3aa40bd1cc5874a6b8ab8d9c5b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C10->D_801B7AA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BD34 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013BD74(void *a0, s32 a1);

void func_8013BD34(s32 a0) {

    extern s32 D_801B7AA0;
    func_8013BD74(&D_801B7AA0, a0);
}
