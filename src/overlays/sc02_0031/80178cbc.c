/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178CBC,80178D18).
 * Offset 0x50B64 at overlay base 80128158. SHA256(span)=7ed68c6af4f883e6bc8f2be3fc2d7e3a36a634157120ccc7c9a7444e699500d5.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184F38->D_801A5260; D_80185C7C->D_801A58E4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801A5260;
void func_80178D40(s32, s32);                          /* static */
extern s16 D_801A58E4;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_801A5260 = arg1;
    do {
        func_80178D40(arg0, D_801A5260);
    } while (D_801A58E4 == 3);
}

