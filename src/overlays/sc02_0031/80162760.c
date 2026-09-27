/* SC02 resident retail span [80162760,801627C0). Offset 0x3A608 at base 80128158.
 * SHA256(span)=8e788c975347171416fe68b960228397451b6564cd3efe9da2f80ccd419f8dd2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842F8->D_801B64B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_800291C8();
void func_80016714();
extern void *D_801B64B0[3];
void func_80162760(void) {
    s32 i;
    func_800291C8(0x12, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801B64B0[i], 0x38);
    }
}
