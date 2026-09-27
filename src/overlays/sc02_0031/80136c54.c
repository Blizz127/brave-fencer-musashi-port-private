/* SC02 resident retail span [80136C54,80136C90). Offset 0xEAFC at base 80128158.
 * SHA256(span)=7c552b666cd83711941c299478b06e67e7db319fb005685c5f83573f77205728.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E92C->D_8018521C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018521C[];
extern u16 D_800B99F0;
void func_80136C54(void) {
    D_8018521C[D_800B99F0]();
}
