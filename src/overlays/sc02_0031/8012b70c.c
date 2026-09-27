/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B70C,8012B744).
 * Offset 0x35B4 at overlay base 80128158. SHA256(span)=9ad1b2220b74bd2f7301ee6f5de037b98f071a54d9b083b3c196157d499b27bb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b70c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8004CFEC();
s32 func_8012B70C(s16 *a, s16 *b) {
    return (func_8004CFEC(a[2] - b[2], b[0] - a[0]) - 0x400) & 0xFFF;
}
