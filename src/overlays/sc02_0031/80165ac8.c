/* SC02 resident retail span [80165AC8,80165B08). Offset 0x3D970 at base 80128158.
 * SHA256(span)=fb73e55cb1f864158e645e82307ce4a05f6a3184ef6468e54362372bb20705b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801811D8->D_80187AC8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165AC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern void (*D_80187AC8[])(void);

void func_80165AC8(void) {
    D_80187AC8[D_80078EC1 & 0x7F]();
}
