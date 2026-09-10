/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017553C,80175590).
 * Offset 0x4D3E4 at overlay base 80128158. SHA256(span)=acba729264d77b3cc9bb551608358b8c160eae98018e5fe113c65caa16bd6bb6.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181B78 here is D_80182400 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182400[];
void func_801758FC();
void func_80175820();
void func_801759D8();
void func_8017553C(u8 *p) {
    D_80182400[p[1]]();
    func_801758FC();
    func_80175820();
    func_801759D8();
}
