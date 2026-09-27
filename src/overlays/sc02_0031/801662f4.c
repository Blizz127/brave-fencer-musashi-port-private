/* SC02.CD FILE_031 / ov_SC02_031 retail span [801662F4,8016634C).
 * Offset 0x3E19C at overlay base 80128158. SHA256(span)=9a3fe87257535b015f304e60795991c0a00cb3a773c696219b2d959cbb19a037.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801662f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146A6C();
void func_801662F4(s16 *p) {
    func_80146A6C(3, p, p[3], (s16)((u16)p[5] - 0x10), p[7], 0x08FEFFF4, 0xE000C000);
}
