/* SC02.CD FILE_031 / ov_SC02_031 retail span [801565C0,80156600).
 * Offset 0x2E468 at overlay base 80128158. SHA256(span)=f5aaa140f8a6f7105fa73592a2560d6211649ca71a1b18a552f54b52694acbe7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801565c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801151E0[];
s32 func_801565C0(void) {
    s32 bits = 0;
    u32 i;
    for (i = 0; i < 3; i++) {
        if (D_801151E0[i] & 1) {
            bits |= 1;
        }
    }
    return bits;
}
