/* SC02 resident retail span [80142978,801429C4). Offset 0x1A820 at base 80128158.
 * SHA256(span)=e914c47751a0edb1c502c469207730f1f1a3684aab8413e2719dd0c368b5a5cb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F9B4->D_801862A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142978 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void (*D_801862A4[])(int);

void func_80142978(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_801862A4[*(u16 *)(param_1 + 2)](param_1); /* a0 still holds param_1 at the jalr */
    }
}
