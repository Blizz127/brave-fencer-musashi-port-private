/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012D5E4,8012D624).
 * Offset 0x548C at overlay base 80128158. SHA256(span)=df80e8d486265c2b2ae3aa86f48748d0bfac9e7d708d7a209f9ead8df8001b6a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012d5e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8012DEB8();
extern s16 D_80126B98;
s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (func_8012DEB8(a0, a1, a2, a3) != 0) {
        D_80126B98 = a3;
        return 1;
    }
    return 0;
}
