/* SC02 resident retail span [80157D20,80157D74). Offset 0x2FBC8 at base 80128158.
 * SHA256(span)=1998ffaf33f9b3b8116f48f6cafd991e2a49d74b15d5937234081b2b0f0604b3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806BC->D_80186FAC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern u16 D_80186FAC[];
void func_80156648();
void func_80147078();
void func_80157D74();
void func_80157D20(void *p, s32 a1) {
    func_80156648(p);
    func_80147078(p, D_80186FAC[a1]);
    func_80157D74(p);
}
