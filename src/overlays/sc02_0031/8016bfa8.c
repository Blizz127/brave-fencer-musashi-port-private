/* SC02 resident retail span [8016BFA8,8016BFD0). Offset 0x43E50 at base 80128158.
 * SHA256(span)=3a9b71c5dd6384cf7ee5fa6911f99bc617170abdee62e0dc19716947d200e05f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184780->D_801B6938.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8016BFD0();
extern s32 D_801B6938;
void func_8016BFA8(void *a0, void *a1, void *a2, void *a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_801B6938);
}
