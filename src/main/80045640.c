/* Exact retail word export for [80045640,80045660); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (8/8 words at 0x80045640). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

s32 func_8005C584(s32, s32, s32);

s32 func_80045640(s32 arg0, s32 arg1) {
    return func_8005C584(arg0, arg1, 0xC) == 0;
}
