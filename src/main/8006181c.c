/* Exact retail word export for [8006181C,80061830); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x8006181C). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C6C;

s32 func_8006181C(void) {
    D_80078C6C = 1;
    return 0;
}
