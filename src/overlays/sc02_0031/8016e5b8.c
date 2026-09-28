/* SC02 resident retail span [8016E5B8,8016E5F4). Offset 0x46460 at base 80128158.
 * SHA256(span)=f72d4567f5c009add4d412075037205e764ef31061cd0bb779e1f3cbb3e51154.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018170C->D_80187FFC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E5B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187FFC[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016E5B8(void *a0) {
    D_80187FFC[*(u16 *)((s32)a0 + 0x2)]();
}
