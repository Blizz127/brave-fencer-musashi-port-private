/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012927C,801292C8).
 * Offset 0x1124 at overlay base 80128158. SHA256(span)=5dfa851c421f6574efc831adb85001c11505c0846129e38ac19302df45b26054.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012927c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_801292C8(void *);                               /* static */
extern s32 *D_8011DB30;

void func_8012927C(void) {
    void *var_s1;
    s32 var_s0;

    var_s1 = &D_8011DB30;
    var_s0 = 0;
    do {
        func_801292C8(var_s1);
        var_s0 += 1;
        var_s1 += 0x38;
    } while (var_s0 < 0x80);
}
