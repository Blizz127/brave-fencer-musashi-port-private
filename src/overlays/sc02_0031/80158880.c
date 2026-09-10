/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158880,801588CC).
 * Offset 0x30728 at overlay base 80128158. SHA256(span)=45370c12621428ac53a1154d08a1fe372b7c37c9e5978f3a52c88ce9cf57464b.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8018071C here is D_80180FA4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180FA4[];
void func_80149020();
typedef struct { u8 pad[0x4F]; u8 idx; } T;
void func_80158880(T *p) {
    func_80149020(p);
    D_80180FA4[p->idx](p);
}
