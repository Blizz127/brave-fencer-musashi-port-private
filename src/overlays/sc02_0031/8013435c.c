/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013435C,801343C4).
 * Offset 0xC204 at overlay base 80128158. SHA256(span)=e61bfeb03fec06871844b83802c03e7a49a54d380d798b98a022bca2ba18d9f2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013435c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8013435C(s16 *a, s16 *b, s32 extra, s16 *c) {
    s32 lim = -0x2F00;
    if (c[1] < -0xE00) {
        lim = -0x1800;
    }
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + extra < lim;
}
