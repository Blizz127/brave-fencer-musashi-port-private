/* SC02 resident retail span [80175690,801756E4). Offset 0x4D538 at base 80128158.
 * SHA256(span)=2bb2c50d09766e418efa2795ae6072e379e3e289e9d148cfd5982a1af8306add.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181B84->D_80188474.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188474[];
void func_801758FC();
void func_80175820();
void func_801759D8();
void func_80175690(u8 *p) {
    D_80188474[p[1]]();
    func_801758FC();
    func_80175820();
    func_801759D8();
}
