/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174EF0,80174F28).
 * Offset 0x4CD98 at overlay base 80128158. SHA256(span)=c32575595599ef1d7237adda765ac1bc9abb0f494305c22cb59e1e76cfc564d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174ef0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_8012697C;
extern s16 D_80126980;
void func_80174F28();
void func_8012A018();
void func_80174EF0(s32 a0, s32 a1) {
    D_8012697C = a0;
    D_80126980 = a1;
    func_8012A018(func_80174F28, 1);
}
