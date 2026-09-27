/* SC02 resident retail span [8017B7A8,8017B824). Offset 0x53650 at base 80128158.
 * SHA256(span)=a7240bf9d2fee9e142e51efc52c1e3d4c07fadee6c9c14914cffada9ee4b3a05.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018534C->D_801B7504; D_801853BC->D_801B7574; D_801853BE->D_801B7576; D_801853C0->D_801B7578; D_801853C4->D_801B757C; D_801853C6->D_801B757E; D_801853C8->D_801B7580.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801B7504;
extern s16 D_801B757C, D_801B757E, D_801B7580;
extern s16 D_801B7574, D_801B7576, D_801B7578;
void func_8017B7A8(void) {
    D_8012694C = 1;
    D_801B7504 = 0;
    D_801B757C = D_80114F30;
    D_801B757E = D_80114F34;
    D_801B7580 = D_80114F38;
    D_801B7574 = D_80114F24;
    D_801B7576 = D_80114F28;
    D_801B7578 = D_80114F2C;
}
