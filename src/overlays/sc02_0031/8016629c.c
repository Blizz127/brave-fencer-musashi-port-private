/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016629C,801662F4).
 * Offset 0x3E144 at overlay base 80128158. SHA256(span)=56b24e8bfc88ec68074c67cda7394884e6a66887e84300c17fb3fbf0bf354b24.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016629c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146A6C();
void func_8016629C(s16 *p) {
    func_80146A6C(3, p, p[3], (s16)((u16)p[5] - 0x10), p[7], 0x0F88FFF2, 0xE000C000);
}
