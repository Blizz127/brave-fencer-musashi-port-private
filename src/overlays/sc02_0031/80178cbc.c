/* SC02 resident retail span [80178CBC,80178D18). Offset 0x50B64 at base 80128158.
 * SHA256(span)=194f0afce77cb94e5ed4592091b5d7c9b84f627620c502ce9f8b0705f734e6ae.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184F38->D_801B70F0; D_80185C7C->D_801B7B0C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801B70F0;
void func_80178D40(s32, s32);                          /* static */
extern s16 D_801B7B0C;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_801B70F0 = arg1;
    do {
        func_80178D40(arg0, D_801B70F0);
    } while (D_801B7B0C == 3);
}

