/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170DE0,80170E34).
 * Offset 0x48C88 at overlay base 80128158. SHA256(span)=ab74292bdafa8beeeef2efe09ba2a9323f6ab34fa3059140d41523afd890e2c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170de0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029178(s32);                             /* extern */
void func_801718AC(s32);                               /* static */
extern s32 D_8011F738;
extern s32 D_8011F73C;
extern s32 D_8011F740;

void func_80170DE0(void) {
    s32 var_a0;

    if (func_80029178(D_8011F738) & 0xFF) {
        var_a0 = D_8011F740;
    } else {
        var_a0 = D_8011F73C;
    }
    func_801718AC(var_a0);
}
