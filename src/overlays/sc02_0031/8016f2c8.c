/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F2C8,8016F2EC).
 * Offset 0x47170 at overlay base 80128158. SHA256(span)=df6a9a1f0b8bdd811d3c679ecce5aa426c98f8f6f3a61cc9f05244a198085f01.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f2c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_80126D50;

void func_8016F2C8(void) {
    D_80126D50 &= 0xFDFFFFFF;
}
