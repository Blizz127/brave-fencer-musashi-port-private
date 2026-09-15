/* Exact retail word export for [8005EA54,8005EA68); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x8005EA54). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_8005EA54(u8 *p) {
    p[0x36] = 0x45;
    *(s32 *) (p + 0x2C) = 0;
    p[0x35] = 0;
}
