/* SC02.CD FILE_031 / ov_SC02_031 retail span [801655E4,80165624).
 * Offset 0x3D48C at overlay base 80128158. SHA256(span)=dc224d423f7f01e72d425bfff61bd198cd0195486cf2708a448793e13db6a885.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801655e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80078EC1;
s32 func_80165658();
void func_8014BD60();
void func_801655E4(void *p) {
    s32 v = func_80165658(p, D_80078EC1 & 0x7F);
    func_8014BD60(p, v & 0x7F);
}
