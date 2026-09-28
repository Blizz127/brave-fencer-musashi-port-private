/* SC02 resident retail span [80141788,801417C4). Offset 0x19630 at base 80128158.
 * SHA256(span)=ef618d70ec27b404fb736fadca3967887920e474b7a64025c7509bfcdb9ff4ef.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F774->D_80186064.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141788 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned short D_80115112;
extern void (*D_80186064[])(void);

void func_80141788(void)
{
    D_80186064[D_80115112]();
}
