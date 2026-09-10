/* SC02 resident retail span [80141788,801417C4). Offset 0x19630 at base 80128158.
 * SHA256(span)=ef618d70ec27b404fb736fadca3967887920e474b7a64025c7509bfcdb9ff4ef.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F774->D_80186064.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186064[];
extern u16 D_80115112;
void func_80141788(void) {
    D_80186064[D_80115112]();
}
