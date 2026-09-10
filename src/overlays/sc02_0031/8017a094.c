/* SC02 resident retail span [8017A094,8017A0C4). Offset 0x51F3C at base 80128158.
 * SHA256(span)=61d7493adc71470c507292b6ef413cd81aeaa2a75e584d5a2034b035a2b418a7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185364->D_801B751C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801B751C;
void func_80179B74(s16 *);                             /* static */

void func_8017A094(s32 arg0) {
    s16 sp10;

    D_801B751C = arg0;
    sp10 = 0x15;
    func_80179B74(&sp10);
}
