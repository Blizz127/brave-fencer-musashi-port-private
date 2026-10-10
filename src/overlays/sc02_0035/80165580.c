/* SC02.CD member35 [80165580,801655E4): twin of main_0012 80165580 (src/overlays/main_0012/80165580.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187134[];
extern u8 D_80078EC5;
extern u8 D_80078EC1;
void func_80165B28();
void func_80165580(void *p) {
    if (D_80078EC5 & 0x80)
        func_80165B28(p);
    else
        D_80187134[D_80078EC1 & 0x7F](p);
}
