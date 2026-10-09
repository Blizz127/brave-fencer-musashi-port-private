/* SC02.CD member35 [80165AC8,80165B08): twin of main_0012 80165AC8 (src/overlays/main_0012/80165ac8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187328[];
extern u8 D_80078EC1;
void func_80165AC8(void) {
    D_80187328[D_80078EC1 & 0x7F]();
}
