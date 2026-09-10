/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161034,80161094).
 * Offset 0x38EDC at overlay base 80128158. SHA256(span)=1da601a98940ecc2289bf7c2733256bbc91bd1b3ae7ec85f4c9393bc1f633599.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80149020();
void func_80147078();
void func_80159B70();
void func_80161034(u16 *p) {
    func_80149020(p);
    D_801812A4[p[0]](p);
    func_80147078(p, 0);
    func_80159B70(p);
}
