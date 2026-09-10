/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013CB20,8013CB5C).
 * Offset 0x149C8 at overlay base 80128158. SHA256(span)=0e6e779e3876502d08fe0681d766af3ce2f1d78d7d6f393ecc4c201c20c0fed9.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801841BC->D_801A44E4; D_801841C0->D_801A44E8; D_801841E8->D_801A4510; D_801841EC->D_801A4514.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801A44E4;
extern s32 D_801A44E8;
extern s32 D_801A4510;
extern s32 D_801A4514;

void func_8013CB20(void) {
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = D_801A44E8;
    temp_a0 = D_801A44E4;
    D_801A44E8 = 1;
    D_801A44E4 = 0;
    D_801A4510 = temp_v0;
    D_801A4514 = temp_a0;
}

