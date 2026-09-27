/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179D78,80179DCC).
 * Offset 0x51C20 at overlay base 80128158. SHA256(span)=a77054f95e407c6d4f6490206b9d5f8779528be6e0f5d59aaa46f5cf13abc2a6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179d78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179D78(s16 *p) {
    s16 sp[5];
    sp[0] = 0x1C;
    sp[1] = p[0];
    sp[2] = p[1];
    sp[3] = p[2];
    sp[4] = p[3];
    func_80179B74(sp);
}
