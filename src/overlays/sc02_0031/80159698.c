/* SC02 resident retail span [80159698,801596D4). Offset 0x31540 at base 80128158.
 * SHA256(span)=b93072b120c363dbb2881c301748a32c3f3b64dcbac5c678f2acb05406a9968f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018096C->D_8018725C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018725C[];
typedef struct { u8 pad[21]; u8 idx; } T;
void func_80159698(T *p) {
    D_8018725C[p->idx](p);
}
