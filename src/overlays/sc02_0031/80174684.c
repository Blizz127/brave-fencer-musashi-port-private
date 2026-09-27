/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174684,801746A4).
 * Offset 0x4C52C at overlay base 80128158. SHA256(span)=2961562b4080a5b0a7e21e106247a305aeed2831b2f163a88f45492a8f0725f6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174684.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s8 D_80126D6C;
extern s32 D_80127088;
extern s32 D_801270BC;

void func_80174684(s32 arg0) {
    D_80126D6C = 0;
    D_80127088 = arg0;
    D_801270BC = 0;
}
