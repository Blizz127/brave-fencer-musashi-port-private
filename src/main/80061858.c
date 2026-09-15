/* Exact retail word export for [80061858,8006186C); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x80061858). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C78;

s32 func_80061858(void) {
    D_80078C78 = 1;
    return 0;
}
