/* SC02 resident retail span [8013D064,8013D13C). Offset 0x14F0C at base 80128158.
 * SHA256(span)=72cfadd27d6df89df093660e47e874bd8fa8b1ba0f07e5607e9291aa00e1b0b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841B0->D_801B6368; D_801841BC->D_801B6374; D_801841C8->D_801B6380; D_801841CC->D_801B6384.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801B6368;
extern s32 D_801B6374;
extern s32 D_801B6380;
extern s32 D_801B6384;
void func_8013D9B0();                                 /* static */

void func_8013D064(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_801B6380 != 0) {
        if (D_801B6380 != 2) {
            if ((D_801B6380 < 3) && (D_801B6380 == 1)) {
                temp_v0 = D_801B6384 + 1;
                D_801B6384 = temp_v0;
                if (temp_v0 >= 0x23B) {
                    D_801B6368 = (s32) D_801B6380;
                    D_801B6380 = 2;
                }
            }
        } else {
            temp_v0_2 = D_801B6368 - 1;
            D_801B6368 = temp_v0_2;
            if (temp_v0_2 == 0) {
                D_801B6368 = (s32) D_801B6380;
                func_8013D9B0(2);
                if (D_801B6374 == 0) {
                    D_801B6380 = (s32) (D_801B6380 + 1);
                }
            }
        }
    }
}

