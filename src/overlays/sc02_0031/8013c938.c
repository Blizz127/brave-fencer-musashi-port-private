/* SC02 resident retail span [8013C938,8013C964). Offset 0x147E0 at base 80128158.
 * SHA256(span)=1325bf4b9c2ec39cf1f89e47ad8bb94815c59379fe99552da692945104940727.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C10->D_801B7AA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801B7AA0;

void func_8013C938(void) {
    D_801B7AA0 = 1;
}
