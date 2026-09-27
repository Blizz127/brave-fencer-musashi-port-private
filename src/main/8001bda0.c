/* Main-exec range [8001BDA0,8001BE20) from the SLUS executable.
 * SHA256(span)=b5fe9e44b21699b2b3439273ea4d9729c67cb0362b1856653294fd898c9ae9ce.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8002CCD8();                                  /* static */
void func_8004239C();                                 /* static */
void func_80042580();                                  /* static */
void func_80042674();                                  /* static */
void func_80043300();                                  /* static */
void func_80059234();                                 /* static */
void func_800595FC();                                 /* static */
void func_80059658();                                 /* static */
void func_800596F4();                                 /* static */
void func_8005D06C();                                  /* static */
void func_8005D118();                                  /* static */

void func_8001BDA0(void) {
    func_8002CCD8();
    func_800596F4(0);
    func_800595FC(0);
    func_80059234(0);
    func_80059658(0);
    func_8004239C(0);
    func_800596F4(0);
    func_80059234(3);
    func_8005D118();
    func_8005D06C();
    func_80043300();
    func_80042580();
    func_80042674();
}
