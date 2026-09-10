/* SC02 resident retail span [80142978,801429C4). Offset 0x1A820 at base 80128158.
 * SHA256(span)=e914c47751a0edb1c502c469207730f1f1a3684aab8413e2719dd0c368b5a5cb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F9B4->D_801862A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801862A4[];
extern s16 D_801270C0;
void func_80142978(u16 *p) {
    if (D_801270C0 != 3)
        D_801862A4[p[1]]();
}
