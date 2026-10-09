/* SC02.CD member35 [801634D8,80163534): twin of main_0012 801634D8 (src/overlays/main_0012/801634d8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801BD010;
void func_80163534();
void func_801634D8(s32 a0, s32 a1, s32 a2, s32 a3, u16 a4) {
    S tmp;
    tmp = D_801BD010;
    func_80163534(a0, a1 & 0xFFFF, a2 & 0xFFFF, a3, a4, &tmp);
}
