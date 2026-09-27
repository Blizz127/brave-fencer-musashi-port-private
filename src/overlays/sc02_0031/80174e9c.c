/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174E9C,80174ED4).
 * Offset 0x4CD44 at overlay base 80128158. SHA256(span)=c2f8845c2a67b807aca5fd18b0d71176591bd385334989ae34db520d973110b8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174e9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_8012697C;
extern s16 D_80126980;
void func_80174F28();
void func_8012A018();
void func_80174E9C(s32 a0) {
    D_8012697C = a0;
    D_80126980 = 0;
    func_8012A018(func_80174F28, 0);
}
