/* Exact retail word export for [80014928,80014960); EXE and assembly verified. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_8005CE18(s32, s32);                              /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */

void func_80014928(void) {
    func_8005CF08();
    func_8005CE18(0x801FF800, 0x800);
    func_8005CF18();
}
