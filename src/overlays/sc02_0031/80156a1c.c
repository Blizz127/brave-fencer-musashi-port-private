/* SC02 resident retail span [80156A1C,80156A88). Offset 0x2E8C4 at base 80128158.
 * SHA256(span)=8e2bbfb6380779042c242c6bfb2f9f9f2657b15fc802443e733149682e887ab3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180654->D_80186F44.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80156A1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned char D_8011520C[];
extern unsigned short D_80186F44[];
extern void func_80147324(s32 arg0);

void func_80156A1C(s32 param_1, s32 param_2)
{
    if (*(unsigned char *)(param_1 + 0xDA) == 0) {
        func_80147324(D_80186F44[D_8011520C[param_2]]);
        *(unsigned char *)(param_1 + 0xDA) = *(unsigned char *)(param_1 + 0xDA) + 1;
    }
}
