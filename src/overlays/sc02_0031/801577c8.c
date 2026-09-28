/* SC02 resident retail span [801577C8,80157808). Offset 0x2F670 at base 80128158.
 * SHA256(span)=6e98b54ac27d50118019f68ba45442a4c1319f9363902e2bbceb0d91ef95ddb2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184280->D_801B6438.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801577C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int D_801B6438;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80157808(void *param_1);

void func_801577C8(s32 arg0) {
    D_801B6438 = 0x12C;
    func_80147078(arg0, 7);
    func_80157808(arg0);
}
