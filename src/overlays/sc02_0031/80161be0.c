/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161BE0,80161C24).
 * Offset 0x39A88 at overlay base 80128158. SHA256(span)=19923fc5cf85b6eb07dafec6841e87ea12b81cc68f4d5a344d121c7758ad65dd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161be0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801497A8();
void func_801599A4();
void func_80149864();
s32 func_80161BE0(void *p) {
    if (func_801497A8(p) == 0) {
        return 0;
    }
    func_801599A4(p);
    func_80149864(p);
    return 1;
}
