/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F2EC,8016F30C).
 * Offset 0x47194 at overlay base 80128158. SHA256(span)=6175d6cfc06234956e09007741beaf8c787b8dddccfddcd8ea966ce980642b1d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f2ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_80126D50;

void func_8016F2EC(void) {
    D_80126D50 |= 0x08000000;
}
