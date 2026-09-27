/* SC02.CD FILE_031 / ov_SC02_031 retail span [801707D4,80170810).
 * Offset 0x4867C at overlay base 80128158. SHA256(span)=1f1d720ece058a54d8dacbf45f973e6c22729b895cbc5b4765fb37af6e13fbd8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801707d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80171928(s32);                               /* static */
s32 func_80174ED4();                                /* static */

void func_801707D4(s32 arg0) {
    if ((func_80174ED4() << 0x10) != 0) {
        func_80171928(arg0);
    }
}
