/* SC02 resident retail span [80165700,80165718). Offset 0x3D5A8 at base 80128158.
 * SHA256(span)=5b86052886aaec3137f5917bd59a3d84ff3713dedce857a53188c0225c0d65ba.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018113C->D_80187A2C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80187A2C[];
s32 func_80165700(s32 a0, u32 a1) {
    return D_80187A2C[a1 & 0x7F];
}
