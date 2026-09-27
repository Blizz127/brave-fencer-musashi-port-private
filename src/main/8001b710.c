/* Exact retail word export for [8001B710,8001B788); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_800291B4();                               /* static */
void func_8002D4C8(s32, s32);                              /* static */

void func_8001B710(void) {
    if ((func_800291B4(0x44) & 0xFF) >= 2) {
        func_8002D4C8(0x24, 0);
    }
    if ((func_800291B4(0x56) & 0xFF) >= 2) {
        func_8002D4C8(0x25, 0);
    }
    if ((func_800291B4(0x5C) & 0xFF) >= 2) {
        func_8002D4C8(0x26, 0);
    }
}
