/* SC02 resident retail span [8015F324,8015F360). Offset 0x371CC at base 80128158.
 * SHA256(span)=aaffab542983e5c1a962c2a15410a73c7f2cc0d504d7a7a4162d80ffb266bc0c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D20->D_80187610.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F324 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8015F324(s32 *a0) {

    extern void (*D_80187610[])(s32 *);
    D_80187610[*(u16 *)((s32)a0 + 0x2)](a0);
}
