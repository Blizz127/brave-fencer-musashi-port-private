/* SC02 resident retail span [80178CBC,80178D18). Offset 0x50B64 at base 80128158.
 * SHA256(span)=194f0afce77cb94e5ed4592091b5d7c9b84f627620c502ce9f8b0705f734e6ae.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184F38->D_801B70F0; D_80185C7C->D_801B7B0C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178CBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B70F0;
extern short D_801B7B0C;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_801B70F0 = arg1;
    do {
        func_80178D40(arg0, D_801B70F0);
    } while (D_801B7B0C == 3);
}
