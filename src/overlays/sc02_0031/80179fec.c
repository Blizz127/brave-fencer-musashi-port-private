/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179FEC,8017A040).
 * Offset 0x51E94 at overlay base 80128158. SHA256(span)=0623e227bf666a34800636dbbe0c05b229846524bdb5ce87460e68dde58266bd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179fec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179FEC(s16 *p) {
    s16 sp[5];
    sp[0] = 0x20;
    sp[1] = p[0];
    sp[2] = p[1];
    sp[3] = p[2];
    sp[4] = p[3];
    func_80179B74(sp);
}
