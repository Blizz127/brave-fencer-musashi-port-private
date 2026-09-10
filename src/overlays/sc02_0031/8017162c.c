/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017162C,801716AC).
 * Offset 0x494D4 at overlay base 80128158. SHA256(span)=99b0c815a85ddb0ff6987a0396c6fa66797297345fd43b62143eb1fc7afbb553.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017162c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_801716AC(s32, s32, s32 *);                     /* static */
void func_80171928(s32);                               /* static */
extern s32 D_8011F738;

void func_8017162C(s32 arg0) {
    s32 sp10;
    s32 temp_s0;

    temp_s0 = D_8011F738;
    sp10 = 0;
    func_801716AC(0, temp_s0, &sp10);
    func_801716AC(1, temp_s0, &sp10);
    func_801716AC(2, temp_s0, &sp10);
    if (sp10 == 0) {
        func_80171928(arg0);
    }
}
