/* Exact retail word export [8002D858,8002D8A8); verified against pinned EXE and asm. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8003D650(s32, s32, s32);                           /* static */
void func_8003EDE8(s32, s16, s16);                       /* static */
extern s16 D_800760E4;

s16 func_8002D858(void) {
    D_800760E4 = 0x64;
    func_8003D650(0, 1, 0);
    func_8003EDE8(0, D_800760E4, D_800760E4);
    return D_800760E4;
}

