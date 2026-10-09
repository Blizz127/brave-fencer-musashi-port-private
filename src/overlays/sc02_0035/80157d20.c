/* SC02.CD member35 [80157D20,80157D74): twin of main_0012 80157D20 (src/overlays/main_0012/80157d20.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern u16 D_8018680C[];
void func_80156648();
void func_80147078();
void func_80157D74();
void func_80157D20(void *p, s32 a1) {
    func_80156648(p);
    func_80147078(p, D_8018680C[a1]);
    func_80157D74(p);
}
