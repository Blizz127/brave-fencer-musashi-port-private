/* SC02.CD member35 [80165700,80165718): twin of main_0012 80165700 (src/overlays/main_0012/80165700.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern u8 D_8018728C[];
s32 func_80165700(s32 a0, u32 a1) {
    return D_8018728C[a1 & 0x7F];
}
