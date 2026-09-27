/* SC02 resident retail span [8013C9C4,8013CA14). Offset 0x1486C at base 80128158.
 * SHA256(span)=39574d33410846cba45b5bbad8151beea1f7b2018350a2a433f164c1b24b825f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * retargeted for this member: D_801A44C0->D_801B6350; D_801A44C4->D_801B6354; D_801A44C5->D_801B6355.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801B6350;
extern u8 D_801B6354;
extern u8 D_801B6355;
extern s32 D_80062BC0;
s32 func_80019198(void);
void func_80019064(s32 *arg0);

void func_8013C9C4(void *arg0)
{
    D_801B6350 = (s32)arg0;
    D_801B6354 = 0;
    D_801B6355 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
