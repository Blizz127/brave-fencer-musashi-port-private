/* SC02 resident retail span [80165AC8,80165B08). Offset 0x3D970 at base 80128158.
 * SHA256(span)=fb73e55cb1f864158e645e82307ce4a05f6a3184ef6468e54362372bb20705b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801811D8->D_80187AC8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187AC8[];
extern u8 D_80078EC1;
void func_80165AC8(void) {
    D_80187AC8[D_80078EC1 & 0x7F]();
}
