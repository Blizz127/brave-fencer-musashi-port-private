/* SC02 resident retail span [8017BCA0,8017BCF4). Offset 0x53B48 at base 80128158.
 * SHA256(span)=2a352d71daf9fd4605cc90ab3b731b5187ce888d742b19e8e35dcb519aaf5f66.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8017B0E4();
extern s16 D_801B7504;
extern s16 D_801B7A98;
void func_8017BCA0(void *p) {
    func_8017B0E4(p, 0xC);
    D_801B7504 = D_801B7504 + 1;
    if (D_801B7504 >= 0x1F) {
        D_801B7A98 = 2;
    }
}
