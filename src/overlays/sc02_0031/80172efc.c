/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172EFC,80172F24).
 * Offset 0x4ADA4 at overlay base 80128158. SHA256(span)=0ef39a6ca74b531b6b64240984c3192852d64fdc2fd4c7cf7262400b2a693066.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172efc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8017303C(void *);                               /* static */
extern s32 *D_800D599C;

void func_80172EFC(void) {
    func_8017303C(&D_800D599C);
}
