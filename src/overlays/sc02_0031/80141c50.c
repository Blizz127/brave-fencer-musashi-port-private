/* SC02.CD FILE_031 / ov_SC02_031 retail span [80141C50,80141CA4).
 * Offset 0x19AF8 at overlay base 80128158. SHA256(span)=ef5f83027c704e294b206644d70917fdb7be149b2b603616e5e76d4bd60f0c49.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80141c50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80015144();                                /* extern */
extern u16 D_8011511C;
extern u16 D_8011511E;

s32 func_80141C50(void) {
    if ((D_8011511C == 0x90F) && (D_8011511E & 0x800)) {
        return func_80015144() != 0;
    }
    return 0;
}
