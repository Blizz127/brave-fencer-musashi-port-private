/* SC02 resident retail span [80136C90,80136D00). Offset 0xEB38 at base 80128158.
 * SHA256(span)=8adcac5d04b9188c68ad2fc98032313283bb4d1d4c5f080aeaff17c90fc3a6e3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182F70->D_801B537C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136C90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char s[10]; } S10_80136C90;

s32 func_80136C90()
{
    extern void func_8001534C(int, void *, int, int, int, int);
    extern S10_80136C90 D_801B537C;

    S10_80136C90 buf = D_801B537C;
    func_8001534C(0, &buf, 0x78, 0x10, 0, 0);
}
