/* SC02 resident retail span [8016216C,801621CC). Offset 0x3A014 at base 80128158.
 * SHA256(span)=4aa18526913a022b8e9c4d9f3654ce88564e4f909d0067f27e8dc75d8e113b7d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842A0->D_801B6458.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_800291C8();
void func_80016714();
extern void *D_801B6458[3];
void func_8016216C(void) {
    s32 i;
    func_800291C8(8, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801B6458[i], 0x38);
    }
}
