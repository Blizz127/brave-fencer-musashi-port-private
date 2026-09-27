/* SC02 resident retail span [801550FC,80155150). Offset 0x2CFA4 at base 80128158.
 * SHA256(span)=d36ad38f16d983c326d8aa1e9506d9c8299a172e7822bcb7f59c727c369077cb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801801AC->D_80186A9C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80059A80();
void func_800183E0();
extern u8 D_80186A9C[];
void func_801550FC(s32 a0) {
    if (a0 & 0x40000000) {
        func_80059A80(D_80186A9C + ((a0 & 0xFF) * 8), 0x200, 0x100);
    } else {
        func_800183E0(a0);
    }
}
