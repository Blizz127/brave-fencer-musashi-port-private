/* Exact retail word export for [8003B0B8,8003B0E4); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (11/11 words at 0x8003B0B8). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern volatile s32 *D_8006B560;

void func_8003B0B8(void) {
    *D_8006B560 = (*D_8006B560 & 0xF0FFFFFF) | 0x22000000;
}
