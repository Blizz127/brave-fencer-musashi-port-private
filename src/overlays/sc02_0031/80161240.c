/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161240,80161278).
 * Offset 0x390E8 at overlay base 80128158. SHA256(span)=65e99b9e2c11703de93d1e55219e31d68c313e8964fbae4b718b087a7ae80fa1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161240.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801612B8();
void func_8016130C();
void func_80161240(void *p) {
    func_8016130C(p, func_801612B8(p, 1));
}
