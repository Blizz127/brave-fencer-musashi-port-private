/* SC02.CD FILE_031 / ov_SC02_031 retail span [801663A4,801663FC).
 * Offset 0x3E24C at overlay base 80128158. SHA256(span)=7c7fe941e18e4936399c8b8cfdfba780c02766aa5e5b6b2aed8afd15864e9576.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801663a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146A6C();
void func_801663A4(s16 *p) {
    func_80146A6C(3, p, p[3], (s16)((u16)p[5] - 0x10), p[7], 0x0CCCFFF8, 0xE000C000);
}
