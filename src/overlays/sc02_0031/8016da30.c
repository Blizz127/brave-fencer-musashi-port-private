/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016DA30,8016DA7C).
 * Offset 0x458D8 at overlay base 80128158. SHA256(span)=be2a2d64e5464ca3471c570ae40f6b75d5e3721a69d261c58719d072afe0f177.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8018167C here is D_80181F04 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181F04[];
void func_8016DBD8();
void func_8016DA30(u16 *p) {
    func_8016DBD8(p);
    D_80181F04[p[1]](p);
}
