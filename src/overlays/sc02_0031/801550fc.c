/* SC02.CD FILE_031 / ov_SC02_031 retail span [801550FC,80155150).
 * Offset 0x2CFA4 at overlay base 80128158. SHA256(span)=435dc4cf15bd8f9644e66963fcb2ad668c2b236ee8f7ff96cbbe64494cf5d0f5.
 * Same shape as the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801550fc.c; only the image table base differs
 * (D_80180A34 here, D_801801AC in member 0012), so this span is not a
 * straight re-carve. Re-earned through the oracle: 21/21 words -O2 -G0.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80059A80();
void func_800183E0();
extern u8 D_80180A34[];

void func_801550FC(s32 a0) {
    if (a0 & 0x40000000) {
        func_80059A80(D_80180A34 + ((a0 & 0xFF) * 8), 0x200, 0x100);
    } else {
        func_800183E0(a0);
    }
}
