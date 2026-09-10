/* SC02 resident retail span [8013C964,8013C98C). Offset 0x1480C at base 80128158.
 * SHA256(span)=5468c95213714914275c0477c1d7a3d66be291a224cef3a6e39d8404cc3889a9.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C10->D_801B7AA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801B7AA0;

void func_8013C964(void) {
    D_801B7AA0 = 0;
}
