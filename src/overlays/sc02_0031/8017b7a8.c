/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017B7A8,8017B824).
 * Offset 0x53650 at overlay base 80128158. SHA256(span)=e907cfaeeca5c055904dda71b67f398f74388403952c899329c517bb687e2a82.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018534C->D_801A5674; D_801853BC->D_801A56E4; D_801853BE->D_801A56E6; D_801853C0->D_801A56E8; D_801853C4->D_801A56EC; D_801853C6->D_801A56EE; D_801853C8->D_801A56F0.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801A5674;
extern s16 D_801A56EC, D_801A56EE, D_801A56F0;
extern s16 D_801A56E4, D_801A56E6, D_801A56E8;
void func_8017B7A8(void) {
    D_8012694C = 1;
    D_801A5674 = 0;
    D_801A56EC = D_80114F30;
    D_801A56EE = D_80114F34;
    D_801A56F0 = D_80114F38;
    D_801A56E4 = D_80114F24;
    D_801A56E6 = D_80114F28;
    D_801A56E8 = D_80114F2C;
}
