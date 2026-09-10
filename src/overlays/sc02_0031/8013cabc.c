/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013CABC,8013CAE8).
 * Offset 0x14964 at overlay base 80128158. SHA256(span)=f1f374dc930c5bb554f801b8f2caf32a147c77178c36c129afc6854a91c66959.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801841B0->D_801A44D8; D_801841B4->D_801A44DC; D_801841BC->D_801A44E4; D_801841C0->D_801A44E8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801A44D8;
extern s32 D_801A44DC;
extern s32 D_801A44E4;
extern s32 D_801A44E8;

void func_8013CABC(void) {
    D_801A44E4 = 1;
    D_801A44D8 = 1;
    D_801A44DC = 0;
    D_801A44E8 = 1;
}

