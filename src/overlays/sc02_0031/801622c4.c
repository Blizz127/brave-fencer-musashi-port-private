/* SC02 resident retail span [801622C4,80162330). Offset 0x3A16C at base 80128158.
 * SHA256(span)=119ce6e7d998e0e562158da33630181f62989d549ba7ffff297bd786ae32d3d3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842A0->D_801B6458.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80029124();
void func_800291C8();
void func_80016714();
extern void *D_801B6458[3];
void func_801622C4(void) {
    s32 i;
    func_80029124(0x141, 1);
    func_800291C8(8, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801B6458[i], 0x38);
    }
}
