/* Exact retail word export for [8005EA68,8005EA88); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (8/8 words at 0x8005EA68). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_8005EA68(u8 *p, s32 arg) {
    p[0x36] = 0x4C;
    *(u8 **) (p + 0x2C) = p + 0x24;
    p[0x24] = arg;
    p[0x35] = 1;
}
