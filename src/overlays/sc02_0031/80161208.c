/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161208,80161240).
 * Offset 0x390B0 at overlay base 80128158. SHA256(span)=b1699664ed2ac0f7b72e97e75262e495452d1b75e6e72ee3cf37bfe5b355548e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161208.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801612B8();
void func_8016130C();
void func_80161208(void *p) {
    func_8016130C(p, func_801612B8(p, 0));
}
