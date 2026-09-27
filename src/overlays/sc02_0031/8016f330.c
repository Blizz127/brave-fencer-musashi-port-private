/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F330,8016F350).
 * Offset 0x471D8 at overlay base 80128158. SHA256(span)=f1172e30af7d3f0a1e28680fe6b826bf01d6999ab9d776f28803b6a9bf73ab5b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f330.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_80126D50;

void func_8016F330(void) {
    D_80126D50 |= 0x10000000;
}
