/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174B6C,80174BBC).
 * Offset 0x4CA14 at overlay base 80128158. SHA256(span)=6532858b9b81868e6a9670094cf730e54e771656601c89eebe8118c9aadc584c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174b6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8012A018(s32 (*)(), s32);                     /* static */
void func_8012A0E0();                                  /* static */
void func_80174BBC(void *);                               /* static */
void func_80174BF4(void *);                               /* static */
extern s32 *D_80126948;

void func_80174B6C(void) {
    func_80174BBC(&D_80126948);
    func_8012A018(func_80174BF4, 0);
    func_8012A0E0();
    func_80174BF4(&D_80126948);
}
