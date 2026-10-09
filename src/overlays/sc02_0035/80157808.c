/* SC02.CD member35 [80157808,80157880): twin of main_0012 80157808 (src/overlays/main_0012/80157808.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801867DC[];
extern s32 D_801BD768;
void func_801599A4();
void func_80159B3C();
void func_80157808(u16 *p) {
    D_801867DC[p[1]]();
    if (--D_801BD768 == -1) {
        func_801599A4(p);
        func_80159B3C(p);
    }
}
