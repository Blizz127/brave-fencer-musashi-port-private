/* SC02.CD member35 [80165670,80165694): twin of main_0012 80165670 (src/overlays/main_0012/80165670.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801871D0[];
extern s32 D_80078EC8;
void func_80165670(s32 a0, u32 a1) {
    D_80078EC8 = D_801871D0[a1 & 0x7F];
}
