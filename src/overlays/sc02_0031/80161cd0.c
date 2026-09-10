/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161CD0,80161D20).
 * Offset 0x39B78 at overlay base 80128158. SHA256(span)=2b728fcc8b838e36648b426f52bdfc39ef3ce61cc6edd62e31a1f52a958ea31c.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180E68 here is D_801816F0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
s32 func_800CF8B4();
void func_80147324();
extern u16 D_801816F0[];
void func_80161CD0(void *p, u32 a1) {
    if (a1 >= 8) {
        return;
    }
    if (func_800CF8B4()) {
        func_80147324(D_801816F0[a1]);
    }
}
