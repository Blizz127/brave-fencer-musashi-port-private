/* SC02.CD FILE_031 / ov_SC02_031 retail span [801633A8,80163408).
 * Offset 0x3B250 at overlay base 80128158. SHA256(span)=6c52fab41ff765cc9ae8fa4fdb1f0389bdde66bcb35b4df1e33fb1c4ecf64680.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801633a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80115200[];
extern u8 *D_80115100[];
s32 func_801633A8(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_80115200[i]) {
            if ((*(u16 *)(D_80115100[i] + 0x5C) & 0x400) == 0) {
                return D_80115200[i];
            }
        }
    }
    return 0;
}
