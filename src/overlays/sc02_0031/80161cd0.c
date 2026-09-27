/* SC02 resident retail span [80161CD0,80161D20). Offset 0x39B78 at base 80128158.
 * SHA256(span)=3090b8ea4a31edda5a6322da310d1a0d425cfe7bb25cf9f06392bb02b3a55771.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E68->D_80187758.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
s32 func_800CF8B4();
void func_80147324();
extern u16 D_80187758[];
void func_80161CD0(void *p, u32 a1) {
    if (a1 >= 8) {
        return;
    }
    if (func_800CF8B4()) {
        func_80147324(D_80187758[a1]);
    }
}
