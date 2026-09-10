/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175690,801756E4).
 * Offset 0x4D538 at overlay base 80128158. SHA256(span)=5fabb07ef369997024a07edd55d85edf2de4905ffacd8c6deef1263024a3b87b.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181B84 here is D_8018240C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018240C[];
void func_801758FC();
void func_80175820();
void func_801759D8();
void func_80175690(u8 *p) {
    D_8018240C[p[1]]();
    func_801758FC();
    func_80175820();
    func_801759D8();
}
