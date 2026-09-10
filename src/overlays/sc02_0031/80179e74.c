/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179E74,80179EA0).
 * Offset 0x51D1C at overlay base 80128158. SHA256(span)=444a98cd774b8a4187be2174923dcf1f5ac41142b6fa9506391027a761c98f18.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179e74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179E74(s16 a0) {
    s16 sp[2];
    sp[1] = a0;
    sp[0] = 4;
    func_80179B74(sp);
}
