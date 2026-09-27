/* Exact retail word export [8002D8D4,8002D904); verified against pinned EXE and asm. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_8003EDE8(s32, s32, s32);                           /* static */
extern s32 D_800A4F24;

s32 func_8002D8D4(void) {
    D_800A4F24 = 0;
    func_8003EDE8(0, 0, 0);
    return 0;
}

