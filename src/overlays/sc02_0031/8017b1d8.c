/* SC02 resident retail span [8017B1D8,8017B238). Offset 0x53080 at base 80128158.
 * SHA256(span)=3e2a6b78cfaeff14e6d67c8b1a0516e255f000dc4c52f5975943f66573891a5b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_801853CC->D_801B7584; D_801853CE->D_801B7586; D_801853D0->D_801B7588; D_80185C08->D_801B7A98.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8012A418();
extern u16 D_80126B5E, D_80126B62, D_80126B66;
extern s16 D_801B7A98, D_801B7504, D_801B7584, D_801B7586, D_801B7588;
void func_8017B1D8(void) {
    func_8012A418();
    D_801B7A98 = 0;
    D_801B7504 = 0;
    D_801B7584 = D_80126B5E;
    D_801B7586 = D_80126B62;
    D_801B7588 = D_80126B66;
}
