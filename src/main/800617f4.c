/* Exact retail word export for [800617F4,80061808); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x800617F4). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C64;

s32 func_800617F4(void) {
    D_80078C64 = 1;
    return 0;
}
