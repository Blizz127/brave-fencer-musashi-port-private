/* Exact retail word export for [80011DF4,80011E10); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (7/7 words at 0x80011DF4). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80074780;

s32 func_80011DF4(void) {
    return D_80074780;
}
