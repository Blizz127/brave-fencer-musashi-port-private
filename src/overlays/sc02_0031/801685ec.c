/* SC02.CD FILE_031 / ov_SC02_031 retail span [801685EC,80168640).
 * Offset 0x40494 at overlay base 80128158. SHA256(span)=c1bacffacf0cb151cda0a3d0fcadbffc31471bb8afe4b6db72ffc43cbd808a03.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801685ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80166994();
s32 func_80166690();
void func_80146C3C();
void func_801685EC(void *p) {
    func_80166994(p, 2, 2, 0);
    if ((s16)func_80166690(2, 1) == 0) {
        func_80146C3C(p);
    }
}
