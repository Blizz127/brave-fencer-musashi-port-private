/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179EA0,80179EE8).
 * Offset 0x51D48 at overlay base 80128158. SHA256(span)=6fa2132412e5a1e7fd2ae8100475b0f98cccced9049ba0a421ad0ee573afd7c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179ea0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179EA0(s16 *p) {
    s16 sp[4];
    sp[0] = 5;
    sp[1] = p[0];
    sp[2] = p[1];
    sp[3] = p[2];
    func_80179B74(sp);
}
