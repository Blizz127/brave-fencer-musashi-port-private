/* Exact retail word export for [800116E0,80011778); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80028D9C();                                /* static */
s32 func_80028FBC();                                /* static */
s32 func_80029000();                                /* static */
void func_8002D4C8(s32, s32);                            /* static */

void func_800116E0(void) {
    func_8002D4C8(0x21, func_80028FBC() & 0xFFFF);
    func_8002D4C8(0x22, func_80029000() & 0xFFFF);
    if (func_80028D9C() == 0) {
        func_8002D4C8(0xC, 0);
        return;
    }
    func_8002D4C8(0xB, 0);
}
