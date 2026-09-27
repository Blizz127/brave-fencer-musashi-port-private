/* Exact retail word export for [8003BE74,8003BE98); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (9/9 words at 0x8003BE74). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_8003BE98(s32, s32, s32, s32);

void func_8003BE74(s32 arg0, s32 arg1) {
    func_8003BE98(arg0, arg1, 0xCC, 0xCD);
}
