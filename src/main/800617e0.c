/* Exact retail word export for [800617E0,800617F4); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x800617E0). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C60;

s32 func_800617E0(void) {
    D_80078C60 = 1;
    return 0;
}
