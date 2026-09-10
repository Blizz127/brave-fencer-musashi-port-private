/* SC02 resident retail span [8015E588,8015E5B0). Offset 0x36430 at base 80128158.
 * SHA256(span)=e68457f814ae5c87ae508d6fc7200934e685301c1eb3db2c7e064b4cde9f1e6e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180CF4->D_801875E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801875E4;
void func_8013C9C4();
void func_8015E588(void) {
    func_8013C9C4(&D_801875E4);
}
