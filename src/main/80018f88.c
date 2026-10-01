/* Exact retail word export for [80018F88,80018FC8); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (16/16 words at 0x80018F88). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_80018F88(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    void *var_v0;

    var_v1 = 1;
    var_v0 = arg0 + 1;
    do {
        (*(u8 *) ((s8 *) (var_v0) + (0x2A))) = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    var_v1_2 = 2;
    do {
        (*(u8 *) ((s8 *) ((arg0 + var_v1_2)) + (0x2A))) = 0x80;
        var_v1_2 += 1;
    } while (var_v1_2 < 6);
}
