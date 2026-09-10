/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F6C,80179F98).
 * Offset 0x51E14 at overlay base 80128158. SHA256(span)=10e0c3fcfefb1cd89f7b7fe5a24d3fb907c0e19fe411a6cc00fb9694a146ec42.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179F6C(s16 a0) {
    s16 sp[2];
    sp[1] = a0;
    sp[0] = 20;
    func_80179B74(sp);
}
