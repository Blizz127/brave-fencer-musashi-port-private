/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164E40,80164EA4).
 * Offset 0x3CCE8 at overlay base 80128158. SHA256(span)=5dc4adeb9a8507977135ce91d0dc015d98b86f2348f0579702d84af5fdd14c49.
 * Druthulu shared/ov func_80164E40__b458f4a1 donor shape with the byte
 * triple retargeted to the SC02 slot (D_801A4680..82); 25/25 words -O2 -G0.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_801A4680;
extern u8 D_801A4681;
extern u8 D_801A4682;

s32 func_80164E40(void) {
    u8 *p = &D_801A4680;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_801A4681 != 0) {
        D_801A4681 -= 0x10;
    }
    if (D_801A4682 != 0) {
        D_801A4682 -= 0x10;
    }
    return *(s32 *)p == 0;
}
