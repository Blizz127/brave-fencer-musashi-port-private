/* Exact retail word export for [80038838,800388E8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80038838(void *arg0) {
    s32 var_a2_2;
    s32 var_v0;
    s8 *var_a3;
    s8 *var_v1;
    s8 var_a2;
    void *var_a1;
    void *var_v0_2;

    var_a3 = arg0 + 0x1A;
    var_a2 = 0;
    var_a1 = arg0 + 0x1B;
    do {
        var_v1 = var_a3 + 9;
        var_v0 = 0xF;
        *var_a3 = var_a2;
        M2C_FIELD(var_a1, s16 *, 1) = 0x40;
        M2C_FIELD(var_a1, s8 *, 3) = 0x40;
        M2C_FIELD(var_a1, s8 *, 6) = 0;
        M2C_FIELD(var_a1, s8 *, 0) = 0x7F;
loop_2:
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 += 1;
        if (var_v0 >= 0) {
            goto loop_2;
        }
        var_a2 += 1;
        var_a1 += 0x1A;
        var_a3 += 0x1A;
    } while (var_a2 < 0x10);
    var_a2_2 = 0;
    var_v0_2 = arg0;
    do {
        M2C_FIELD(var_v0_2, s8 *, 0x18) = 0;
        M2C_FIELD(var_v0_2, s16 *, 0x12) = 0x4000;
        var_a2_2 += 1;
        var_v0_2 += 8;
    } while (var_a2_2 <= 0);
    M2C_FIELD(arg0, s32 *, 8) = 1;
    M2C_FIELD(arg0, s32 *, 0x1D0) = 0xE10;
    M2C_FIELD(arg0, s32 *, 0x1D4) = 0xE10;
    M2C_FIELD(arg0, s32 *, 0x1CC) = 0xE10;
    M2C_FIELD(arg0, s8 *, 0x1F4) = 0;
    M2C_FIELD(arg0, s16 *, 0x1E4) = 0x78;
    M2C_FIELD(arg0, s8 *, 0x1F7) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F8) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F9) = 0;
    M2C_FIELD(arg0, s8 *, 0x1FA) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F6) = 0;
}
