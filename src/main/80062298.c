/* Main-exec range [80062298,800622D0) from the SLUS executable.
 * SHA256(span)=fc167cc06a8605dced638b5f049ab0010a6c40e55d1cef31d8581d14619fba9c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80062278(s32, s32, s32);                         /* static */
void func_80062288();                                  /* static */

void func_80062298(s32 arg0) {
    func_80062288();
    func_80062278(arg0, 0x3F, 0);
}
