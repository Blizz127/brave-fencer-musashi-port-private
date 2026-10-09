/* SC02.CD member35 [8017B8E8,8017B940): twin of main_0012 8017B8E8 (src/overlays/main_0012/8017b8e8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801BE8AC;
extern S D_801BE8A4;
void func_8017B8E8(S *p) {
    D_801BE8AC = p[0];
    D_801BE8A4 = p[1];
}
