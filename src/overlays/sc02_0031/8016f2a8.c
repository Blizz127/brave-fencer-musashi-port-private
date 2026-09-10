/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F2A8,8016F2C8).
 * Offset 0x47150 at overlay base 80128158. SHA256(span)=a6d8ca5ab25e516485ec5cd64759298734906bddfa1a58860a263a997d8b237c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f2a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_80126D50;

void func_8016F2A8(void) {
    D_80126D50 |= 0x02000000;
}
