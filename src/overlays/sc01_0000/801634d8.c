/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801A3E54;
void func_80163534();
void func_801634D8(s32 a0, s32 a1, s32 a2, s32 a3, u16 a4) {
    S tmp;
    tmp = D_801A3E54;
    func_80163534(a0, a1 & 0xFFFF, a2 & 0xFFFF, a3, a4, &tmp);
}
