/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179E48,80179E74).
 * Offset 0x51CF0 at overlay base 80128158. SHA256(span)=6b555f97fe873b446f8a3a74c61005a4f5564268597d99fa8f0119fe2a5d9579.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179e48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179E48(s16 a0) {
    s16 sp[2];
    sp[1] = a0;
    sp[0] = 31;
    func_80179B74(sp);
}
