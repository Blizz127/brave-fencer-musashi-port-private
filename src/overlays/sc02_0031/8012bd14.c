/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BD14,8012BD3C).
 * Offset 0x3BBC at overlay base 80128158. SHA256(span)=37cd07265e696dea55ca8bba2721a9e1215f86caf81fdeb1feb04b4fe38073e2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bd14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80013350(s32, void *);                          /* extern */
extern s32 *D_80126B5C;

void func_8012BD14(s32 arg0) {
    func_80013350(arg0 + 4, &D_80126B5C);
}
