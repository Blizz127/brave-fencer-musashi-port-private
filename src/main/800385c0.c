/* Exact retail word export for [800385C0,80038638); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800B9ED2;
extern s32 *D_800B9ED3;
extern s32 *D_800C6E2A;

void func_800385C0(s32 arg0) {
    void *var_v1;
    s32 temp_v0;
    s32 var_a1;

    var_a1 = 0;
    var_v1 = &D_800C6E2A;
    do {
        if ((M2C_FIELD(var_v1, u8 *, 2) != 0) && (M2C_FIELD(M2C_FIELD(var_v1, void **, -0xA), s16 *, 0x1F0) == arg0)) {
            M2C_FIELD(var_v1, u8 *, 2) = 0U;
            M2C_FIELD(var_v1, s8 *, 0) = 0;
        }
        var_a1 += 1;
        var_v1 += 0x60;
    } while (var_a1 < 0x10);
    temp_v0 = arg0 * 0x1FC;
    *(&D_800B9ED2 + temp_v0) = 0;
    *(&D_800B9ED3 + temp_v0) = 0;
}
