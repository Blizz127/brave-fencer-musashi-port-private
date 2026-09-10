/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161C98,80161CD0).
 * Offset 0x39B40 at overlay base 80128158. SHA256(span)=54f337bf5e8d06a1a7dfe0aac601df8f15b826c41bb4c45a64d400924a5fe97c.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180E58 here is D_801816E0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
extern u16 D_801816E0[];
void func_80161C98(s32 a0, u32 a1) {
    if (a1 < 8) {
        func_80147324(D_801816E0[a1]);
    }
}
