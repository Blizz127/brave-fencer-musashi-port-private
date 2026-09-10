/* SC02 resident retail span [801656D0,801656E8). Offset 0x3D578 at base 80128158.
 * SHA256(span)=e2fa19bf14a0cdb300f4a9d8716a82ee2473c35d8805f19e3999454973ce3b5b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801810FC->D_801879EC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_801879EC[];
s32 func_801656D0(s32 a0, u32 a1) {
    return D_801879EC[a1 & 0x7F];
}
