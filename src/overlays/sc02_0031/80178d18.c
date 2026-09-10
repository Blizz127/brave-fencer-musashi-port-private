/* SC02 resident retail span [80178D18,80178D40). Offset 0x50BC0 at base 80128158.
 * SHA256(span)=b6fa4207fb98a8dc1c27f334aaed30e032d45f7bf812aabe5d17c9fcae55db97.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185C7C->D_801B7B0C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

void func_80174714();                                  /* static */
extern s16 D_801B7B0C;

void func_80178D18(void) {
    D_801B7B0C = 0;
    func_80174714();
}
