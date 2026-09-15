/* Exact retail word export for [80061830,80061844); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x80061830). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C70;

s32 func_80061830(void) {
    D_80078C70 = 1;
    return 0;
}
