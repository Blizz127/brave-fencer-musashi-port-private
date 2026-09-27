/* SC02 resident retail span [8017BCF4,8017BD50). Offset 0x53B9C at base 80128158.
 * SHA256(span)=e14d8d2d36f57ed004d379144c69b9c0a7ea3a32a792a1141cd99dc628b3a7a2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8017B0E4();
void func_8012A4BC();
extern s16 D_801B7504;
extern s16 D_801B7A98;
void func_8017BCF4(void *p) {
    func_8017B0E4(p, 6);
    D_801B7504++;
    if (D_801B7504 >= 0x19) {
        func_8012A4BC();
        D_801B7A98 = 0;
    }
}
