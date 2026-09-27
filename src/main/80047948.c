/* Exact retail word export for [80047948,800479E8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8A8[];
extern s32 D_8006C8A8[];
extern s32 D_8006D0A8[];

s16 func_80047948(s32 arg0) {
    s32 temp_a0;
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 < 0) {
        var_a0 = -var_a0;
    }
    temp_a0 = var_a0 & 0xFFF;
    if (temp_a0 < 0x801) {
        if (temp_a0 < 0x401) {
            return *(D_8006D0A8 + ((0x400 - temp_a0) * 2));
        }
        return -*(D_8006C8A8 + (temp_a0 * 2));
    }
    if (temp_a0 >= 0xC01) {
        return *(D_8006B8A8 + (temp_a0 * 2));
    }
    return -*(D_8006D0A8 + ((0xC00 - temp_a0) * 2));
}
