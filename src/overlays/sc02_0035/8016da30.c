/* SC02.CD member35 [8016DA30,8016DA7C): twin of main_0012 8016DA30 (src/overlays/main_0012/8016da30.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801877CC[];
void func_8016DBD8();
void func_8016DA30(u16 *p) {
    func_8016DBD8(p);
    D_801877CC[p[1]](p);
}
