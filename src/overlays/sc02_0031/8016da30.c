/* SC02 resident retail span [8016DA30,8016DA7C). Offset 0x458D8 at base 80128158.
 * SHA256(span)=d49e945414dd49550a097c104fb89955ba9e8ca6fd9125073cb2202904e2788b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018167C->D_80187F6C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187F6C[];
void func_8016DBD8();
void func_8016DA30(u16 *p) {
    func_8016DBD8(p);
    D_80187F6C[p[1]](p);
}
