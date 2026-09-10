/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161D20,80161D58).
 * Offset 0x39BC8 at overlay base 80128158. SHA256(span)=b5a436e41622e9221656e2bccf45cd58a3c35974ea1b6d27599f734bacfdcd43.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180E78 here is D_80181700 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u16 D_80181700[];
void func_80161D20(s32 a0, u32 a1) {
    if (a1 < 8) {
        func_80147324(D_80181700[a1]);
    }
}
