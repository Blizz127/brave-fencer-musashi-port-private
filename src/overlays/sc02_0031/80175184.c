/* SC02 resident retail span [80175184,801751D8). Offset 0x4D02C at base 80128158.
 * SHA256(span)=cde082c6151e1f38669d0062a33fe61b3b1b72f0df618ad5f5b86a542fa653d7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181A08->D_801882F8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801882F8[];
void func_80175268();
void func_80175184(u16 *p) {
    u16 idx = p[1];
    if (idx < 2)
        D_801882F8[idx]();
    else
        func_80175268();
}
