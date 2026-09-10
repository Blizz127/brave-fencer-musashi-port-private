/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A040,8017A094).
 * Offset 0x51EE8 at overlay base 80128158. SHA256(span)=20461568c56c4b18e6e77ae77348e62e26e4b547ad5d4a2b65a157edb4bb0bac.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a040.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_8017A040(s16 *p) {
    s16 sp[5];
    sp[0] = 0x1D;
    sp[1] = p[0];
    sp[2] = p[1];
    sp[3] = p[2];
    sp[4] = p[3];
    func_80179B74(sp);
}
