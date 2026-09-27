/* SC02 resident retail span [8013CAE8,8013CB20). Offset 0x14990 at base 80128158.
 * SHA256(span)=2ef85e490ec4421848aa1fbb440d04c6d077207ad63f025f57f2ceba9acecbc1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841B0->D_801B6368; D_801841B4->D_801B636C; D_801841B8->D_801B6370; D_801841BC->D_801B6374; D_801841C0->D_801B6378.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801B6368;
extern s32 D_801B636C;
extern s32 D_801B6370;
extern s32 D_801B6374;
extern s32 D_801B6378;

void func_8013CAE8(void) {
    D_801B6368 = 1;
    D_801B6374 = 0;
    D_801B636C = 0;
    D_801B6370 = -1;
    D_801B6378 = 0;
}

