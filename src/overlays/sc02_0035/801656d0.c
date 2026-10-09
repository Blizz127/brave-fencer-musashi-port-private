/* SC02.CD member35 [801656D0,801656E8): twin of main_0012 801656D0 (src/overlays/main_0012/801656d0.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern u8 D_8018724C[];
s32 func_801656D0(s32 a0, u32 a1) {
    return D_8018724C[a1 & 0x7F];
}
