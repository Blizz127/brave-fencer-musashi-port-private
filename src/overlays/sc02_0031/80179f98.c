/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F98,80179FEC).
 * Offset 0x51E40 at overlay base 80128158. SHA256(span)=101ab523d4e9c0ec0e8840db8c13667f8b6cfc1628293874bcd9339de76bf47f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f98.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80179B74();
void func_80179F98(s16 *p) {
    s16 sp[5];
    sp[0] = 0x17;
    sp[1] = p[0];
    sp[2] = p[1];
    sp[3] = p[2];
    sp[4] = p[3];
    func_80179B74(sp);
}
