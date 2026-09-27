/* SC02.CD FILE_031 / ov_SC02_031 retail span [801632F0,80163328).
 * Offset 0x3B198 at overlay base 80128158. SHA256(span)=151762e577c6c31e070a429f38fbc5cf49431a95b93b31f12d92069225654e6a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801632f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80115200[];
s32 func_801632F0(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_80115200[i] != 0) {
            return D_80115200[i];
        }
    }
    return 0;
}
