/* SC02 resident retail span [8013B7AC,8013B7F4). Offset 0x13654 at base 80128158.
 * SHA256(span)=ea815d176496ebb3654867125e57de1ba9da66747c52a324f0b69a33a1283d22.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185B58->D_801B79E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s32 a; u8 pad[24]; } S;
extern S D_801B79E8[];
void func_8013B7AC(s32 a0) {
    D_801B79E8[a0].a = 0;
}
