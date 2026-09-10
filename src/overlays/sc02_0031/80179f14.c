/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F14,80179F44).
 * Offset 0x51DBC at overlay base 80128158. SHA256(span)=7c605c9d44acfa7a1e9fce1956ce853557494b528cf41679fd744b10200d2f12.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179F14(s16 a0, s16 a1) {
    s16 sp[3];
    sp[1] = a0;
    sp[0] = 19;
    sp[2] = a1;
    func_80179B74(sp);
}
