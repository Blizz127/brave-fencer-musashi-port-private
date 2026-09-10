/* SC02 resident retail span [8013CB5C,8013CB84). Offset 0x14A04 at base 80128158.
 * SHA256(span)=2fb2073cf83fafc8664e2bd30909493820b2ccd26ca8daef481a9409917fd0cb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841BC->D_801B6374; D_801841C0->D_801B6378; D_801841E8->D_801B63A0; D_801841EC->D_801B63A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801B6374;
extern s32 D_801B6378;
extern s32 D_801B63A0;
extern s32 D_801B63A4;

void func_8013CB5C(void) {
    D_801B6378 = (s32) D_801B63A0;
    D_801B6374 = (s32) D_801B63A4;
}

