/* Exact retail word export for [80011350,8001136C); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (7/7 words at 0x80011350). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_80074784;

s32 func_80011350(void) {
    return D_80074784;
}
