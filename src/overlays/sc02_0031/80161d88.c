/* SC02 resident retail span [80161D88,80161E08). Offset 0x39C30 at base 80128158.
 * SHA256(span)=bbab2aa72f8250fd30f6d01dc1ad45ccfe8407c654276a6fca58079ec7947653.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180EBC->D_801877AC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
s32 func_80029178();
void func_80029124();
void func_800D1734();
extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern s32 D_801877AC;
void func_80161D88(void) {
    if (D_800AE6B0 & 0x80FFFFFF) {
        return;
    }
    if (D_800AE6A8 & 0x80FFFFFF) {
        return;
    }
    if (func_80029178(0x141) & 0xFF) {
        func_80029124(0x141, 0);
        func_80029124(0x95, 1);
        func_800D1734(&D_801877AC);
    }
}
