/* SC02.CD member35 [80163408,8016345C): twin of main_0012 80163408 (src/overlays/main_0012/80163408.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801BD010;
void func_8016345C();
void func_80163408(s32 a0, s32 a1, s32 a2, s32 a3) {
    S tmp;
    tmp = D_801BD010;
    func_8016345C(a0, a1 & 0xFFFF, a2, a3 & 0xFFFF, &tmp);
}
