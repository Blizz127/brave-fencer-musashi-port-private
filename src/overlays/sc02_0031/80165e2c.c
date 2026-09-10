/* SC02 resident retail span [80165E2C,80165E90). Offset 0x3DCD4 at base 80128158.
 * SHA256(span)=5da1e18dad2c554a6444b3790f478349a8f36ea92dcb3f3a892abb02d3ca3bb1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018394C->D_801B5D58.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B5D58;
void func_8001534C();
void func_800153CC();
void func_80165E2C(u16 *p) {
    func_8001534C(0, &D_801B5D58, 0x80, 0x80, 0, 0);
    func_800153CC(1, p[0], 0xA8, 0x80, 0x40, 0);
}
