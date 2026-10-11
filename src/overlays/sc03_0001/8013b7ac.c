/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { s32 a; u8 pad[24]; } S;
extern S D_801EF328[];
void func_8013B7AC(s32 a0) {
    D_801EF328[a0].a = 0;
}
