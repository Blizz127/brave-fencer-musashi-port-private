/* SC02.CD member35 [80165E2C,80165E90): twin of main_0012 80165E2C (src/overlays/main_0012/80165e2c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801BD020;
void func_8001534C();
void func_800153CC();
void func_80165E2C(u16 *p) {
    func_8001534C(0, &D_801BD020, 0x80, 0x80, 0, 0);
    func_800153CC(1, p[0], 0xA8, 0x80, 0x40, 0);
}
