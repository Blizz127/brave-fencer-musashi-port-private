/* SC02.CD member35 [8017A144,8017A180): twin of main_0012 8017A144 (src/overlays/main_0012/8017a144.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

extern s32 D_801BE874;
void func_80179B74(s16 *);                             /* static */

void func_8017A144(s32 arg0) {
    s16 sp10;

    sp10 = 0x1B;
    func_80179B74(&sp10);
    D_801BE874 = arg0;
}
