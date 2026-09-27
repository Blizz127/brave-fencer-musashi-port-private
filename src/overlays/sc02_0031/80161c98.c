/* SC02 resident retail span [80161C98,80161CD0). Offset 0x39B40 at base 80128158.
 * SHA256(span)=c4c9809b7caab251bbf97432bdea9cb73f22f3e08bdffaccc3f355f60456ca67.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E58->D_80187748.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u16 D_80187748[];
void func_80161C98(s32 a0, u32 a1) {
    if (a1 < 8) {
        func_80147324(D_80187748[a1]);
    }
}
