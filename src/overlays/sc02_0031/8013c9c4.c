/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013C9C4,8013CA14).
 * Offset 0x1486C at overlay base 80128158. SHA256(span)=6864b919a7d0b25e6fd0d949cd244bdc4aabb30dd26bd45796958dcc0844f8a9.
 * Druthulu shared/ov func_8013C9C4__564fe0e7 donor shape with its data
 * symbols retargeted to the SC02 slot (D_801A44C0/C4/C5); 20/20 words -O2 -G0.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801A44C0;
extern u8 D_801A44C4;
extern u8 D_801A44C5;
extern s32 D_80062BC0;
s32 func_80019198(void);
void func_80019064(s32 *arg0);

void func_8013C9C4(void *arg0)
{
    D_801A44C0 = (s32)arg0;
    D_801A44C4 = 0;
    D_801A44C5 = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
