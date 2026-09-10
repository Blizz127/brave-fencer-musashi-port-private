/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013D064,8013D13C).
 * Offset 0x14F0C at overlay base 80128158. SHA256(span)=dee97b79ac8ea698725deb778d089d398e0260a5e8259e93c7e7d01b5fe88334.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801841B0->D_801A44D8; D_801841BC->D_801A44E4; D_801841C8->D_801A44F0; D_801841CC->D_801A44F4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801A44D8;
extern s32 D_801A44E4;
extern s32 D_801A44F0;
extern s32 D_801A44F4;
void func_8013D9B0();                                 /* static */

void func_8013D064(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_801A44F0 != 0) {
        if (D_801A44F0 != 2) {
            if ((D_801A44F0 < 3) && (D_801A44F0 == 1)) {
                temp_v0 = D_801A44F4 + 1;
                D_801A44F4 = temp_v0;
                if (temp_v0 >= 0x23B) {
                    D_801A44D8 = (s32) D_801A44F0;
                    D_801A44F0 = 2;
                }
            }
        } else {
            temp_v0_2 = D_801A44D8 - 1;
            D_801A44D8 = temp_v0_2;
            if (temp_v0_2 == 0) {
                D_801A44D8 = (s32) D_801A44F0;
                func_8013D9B0(2);
                if (D_801A44E4 == 0) {
                    D_801A44F0 = (s32) (D_801A44F0 + 1);
                }
            }
        }
    }
}

