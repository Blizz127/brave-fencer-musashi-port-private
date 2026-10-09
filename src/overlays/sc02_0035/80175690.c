/* SC02.CD member35 [80175690,801756E4): twin of main_0012 80175690 (src/overlays/main_0012/80175690.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187CD4[];
void func_801758FC();
void func_80175820();
void func_801759D8();
void func_80175690(u8 *p) {
    D_80187CD4[p[1]]();
    func_801758FC();
    func_80175820();
    func_801759D8();
}
