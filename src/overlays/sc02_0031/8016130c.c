/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016130C,80161374).
 * Offset 0x391B4 at overlay base 80128158. SHA256(span)=6cf3f8924973e7dc24d4a79396fe240898dd2c3a48d3760176ec7351103217b7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016130c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801599A4();
void func_8015BDD0();
void func_8015BF48();
s32 func_8016130C(void *p, u32 a1) {
    if (a1 == 0 || a1 == 0x8000) {
        func_801599A4(p);
        func_8015BDD0(p);
        return 1;
    }
    if (a1 & 0x4000) {
        func_801599A4(p);
        func_8015BF48(p);
        return 1;
    }
    return 0;
}
