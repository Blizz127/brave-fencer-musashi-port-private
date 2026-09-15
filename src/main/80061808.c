/* Exact retail word export for [80061808,8006181C); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (5/5 words at 0x80061808). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80078C68;

s32 func_80061808(void) {
    D_80078C68 = 1;
    return 0;
}
