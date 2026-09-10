/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017B1D8,8017B238).
 * Offset 0x53080 at overlay base 80128158. SHA256(span)=eadff84f6f462ea2ab607493fe04b5df54a65ee392033a67ce8ed1038d4c98f9.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018534C->D_801A5674; D_801853CC->D_801A56F4; D_801853CE->D_801A56F6; D_801853D0->D_801A56F8; D_80185C08->D_801A5870.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8012A418();
extern u16 D_80126B5E, D_80126B62, D_80126B66;
extern s16 D_801A5870, D_801A5674, D_801A56F4, D_801A56F6, D_801A56F8;
void func_8017B1D8(void) {
    func_8012A418();
    D_801A5870 = 0;
    D_801A5674 = 0;
    D_801A56F4 = D_80126B5E;
    D_801A56F6 = D_80126B62;
    D_801A56F8 = D_80126B66;
}
