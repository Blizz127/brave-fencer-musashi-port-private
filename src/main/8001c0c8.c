/* Exact retail word export [8001C0C8,8001C14C); verified against pinned EXE and asm. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);             /* static */
extern s32 *D_800AF630;

void func_8001C0C8(void) {
    s32 var_s0;
    s32 var_s0_2;
    void *var_s1;
    void *var_s1_2;

    var_s1 = &D_800AF630 + 0x65A8;
    var_s0 = 0;
    do {
        func_80016714(var_s1, 0x38);
        var_s0 += 1;
        var_s1 += 0x38;
    } while (var_s0 < 0x100);
    var_s1_2 = &D_800AF630 + 0x2A8;
    var_s0_2 = 0;
    do {
        func_80016714(var_s1_2, 0x84);
        var_s0_2 += 1;
        var_s1_2 += 0x84;
    } while (var_s0_2 < 0xC0);
    M2C_FIELD(&D_800AF630, s16 *, 0x19C) = 0;
}
