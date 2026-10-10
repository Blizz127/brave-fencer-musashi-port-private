/* SC02 resident retail span [80165580,801655E4). Offset 0x3D428 at base 80128158.
 * SHA256(span)=2222d6104a8bc52298799b18c43ea461b69827eaba86322e3b06956f01bac2db.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180FE4->D_801878D4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165580 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC5;
extern u8 D_80078EC1;
extern void (*D_801878D4[])(s32);
extern void func_80165B28(void *a0);

void func_80165580(s32 _arg0)
{
    if (D_80078EC5 & 0x80) {
        ((void (*)(void))func_80165B28)();
    } else {
        D_801878D4[D_80078EC1 & 0x7F](_arg0);
    }
}
