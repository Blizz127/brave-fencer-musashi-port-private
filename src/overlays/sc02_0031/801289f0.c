/* SC02 resident retail span [801289F0,80128A28). Offset 0x898 at base 80128158.
 * SHA256(span)=ee175764630c30d12f01a8a062de7e6bc2652ee8a4ab3a1c00d6da73e484d8a5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8001ABBC(s32, s32, void *, s32, s32);               /* extern */
extern s32 D_801B5128;
extern s32 *D_800AECB8;

void func_801289F0(void) {
    func_8001ABBC(0, 0, &D_800AECB8, D_801B5128, 0);
}

