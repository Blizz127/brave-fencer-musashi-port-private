/* SC02 resident retail span [80136C90,80136D00). Offset 0xEB38 at base 80128158.
 * SHA256(span)=8adcac5d04b9188c68ad2fc98032313283bb4d1d4c5f080aeaff17c90fc3a6e3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182F70->D_801B537C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[10]; } S;
extern S D_801B537C;
void func_8001534C();
void func_80136C90(void) {
    S tmp;
    tmp = D_801B537C;
    func_8001534C(0, &tmp, 0x78, 0x10, 0, 0);
}
