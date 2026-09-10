/* SC02 resident retail span [8017B880,8017B8E8). Offset 0x53728 at base 80128158.
 * SHA256(span)=699bdc0c1d391e0db3813b7ede520c4dfa904649739d1f0872b3dc1837b4d031.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801853DC->D_801B7594; D_801853DE->D_801B7596; D_801853E0->D_801B7598; D_801853E4->D_801B759C; D_801853E6->D_801B759E; D_801853E8->D_801B75A0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_801B7594, D_801B7596, D_801B7598;
extern s16 D_801B759C, D_801B759E, D_801B75A0;
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
void func_8017B880(void) {
    D_80114F30 = D_801B7594;
    D_80114F34 = D_801B7596;
    D_80114F38 = D_801B7598;
    D_80114F24 = D_801B759C;
    D_80114F28 = D_801B759E;
    D_80114F2C = D_801B75A0;
}
