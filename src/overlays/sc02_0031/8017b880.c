/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017B880,8017B8E8).
 * Offset 0x53728 at overlay base 80128158. SHA256(span)=e80b20491be411b1d6ee8341f3229a65857dfd1e30ce5e4242fbaa95521c1fe0.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801853DC->D_801A5704; D_801853DE->D_801A5706; D_801853E0->D_801A5708; D_801853E4->D_801A570C; D_801853E6->D_801A570E; D_801853E8->D_801A5710.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_801A5704, D_801A5706, D_801A5708;
extern s16 D_801A570C, D_801A570E, D_801A5710;
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
void func_8017B880(void) {
    D_80114F30 = D_801A5704;
    D_80114F34 = D_801A5706;
    D_80114F38 = D_801A5708;
    D_80114F24 = D_801A570C;
    D_80114F28 = D_801A570E;
    D_80114F2C = D_801A5710;
}
