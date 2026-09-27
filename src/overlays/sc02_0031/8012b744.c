/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B744,8012B77C).
 * Offset 0x35EC at overlay base 80128158. SHA256(span)=66c200460f09ae886a3758d63a79e1d5251379a837b8ea71055535740707708b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b744.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8004CFEC();
s32 func_8012B744(s16 *a, s16 *b) {
    return (func_8004CFEC(a[5] - b[2], b[0] - a[1]) - 0x400) & 0xFFF;
}
