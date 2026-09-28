/* SC02 resident retail span [80161CD0,80161D20). Offset 0x39B78 at base 80128158.
 * SHA256(span)=3090b8ea4a31edda5a6322da310d1a0d425cfe7bb25cf9f06392bb02b3a55771.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E68->D_80187758.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161CD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");

void aF80161CD0(int param_1, unsigned int param_2)
{

    extern unsigned short D_80187758;
    if (param_2 < 8) {
        if (func_800CF8B4() != 0) {
            func_80147324((&D_80187758)[param_2]);
        }
    }
}
