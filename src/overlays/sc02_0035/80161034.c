/* SC02.CD member35 [80161034,80161094): twin of main_0012 80161034 (src/overlays/main_0012/80161034.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186B6C[];
void func_80149020();
void func_80147078();
void func_80159B70();
void func_80161034(u16 *p) {
    func_80149020(p);
    D_80186B6C[p[0]](p);
    func_80147078(p, 0);
    func_80159B70(p);
}
