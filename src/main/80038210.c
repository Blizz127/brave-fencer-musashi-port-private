/* Exact retail word export for [80038210,80038308); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80038698(s32 *, s32);                      /* static */
s32 func_800387C0(s32 *);                           /* static */
void func_80038838(s32 *);                       /* static */
extern void *D_800A6428;
extern s32 *D_800B9CD8;
extern s32 *D_800C1320;

s32 func_80038210(s32 arg0, s16 arg1, s32 arg2) {
    s32 *var_s1;
    s32 var_a1;
    s32 var_s2;
    void *var_a0;
    void *var_s0;

    var_s1 = &D_800B9CD8;
    var_s2 = 0;
    var_s0 = &D_800B9CD8 + 0x1FA;
loop_1:
    if (M2C_FIELD(var_s0, u8 *, 1) == 0) {
        D_800A6428 = var_s1 + 0x1BA;
        *var_s1 = arg0;
        M2C_FIELD(var_s0, s16 *, -0xE) = arg1;
        M2C_FIELD(var_s0, s32 *, -0x12) = arg2;
        M2C_FIELD(var_s0, void **, -0x22) = &D_800C1320;
        M2C_FIELD(var_s0, void **, -0x1E) = (void *) (&D_800C1320 + 0x20);
        M2C_FIELD(var_s0, void **, -0x1A) = (void *) (&D_800C1320 + 0x820);
        if ((func_80038698(var_s1, arg0) == 0) && (func_800387C0(var_s1) == 0)) {
            func_80038838(var_s1);
            var_a1 = 0xF;
            var_a0 = var_s1 + 0xF;
            M2C_FIELD(var_s0, u8 *, 1) = 1U;
            M2C_FIELD(var_s0, s8 *, 0) = 0;
            M2C_FIELD(var_s0, s32 *, -0x1F6) = (s32) *var_s1;
            do {
                M2C_FIELD(var_a0, s8 *, 0x1BA) = 0;
                var_a1 -= 1;
                var_a0 -= 1;
            } while (var_a1 >= 0);
            return var_s2;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return -1;
    }
    var_s2 += 1;
    var_s0 += 0x1FC;
    var_s1 += 0x1FC;
    if (var_s2 >= 2) {
        return -1;
    }
    goto loop_1;
}
