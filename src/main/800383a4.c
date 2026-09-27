/* Exact retail word export for [800383A4,800384A8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073140;
void func_8002EFF8(s32, s32);                /* static */
void func_8003916C(s16);                         /* static */
extern s8 D_800A4F1D;
extern s32 *D_800B9CD8;
extern s32 *D_800C6E2D;

void func_800383A4(s32 arg0) {
    s32 (*var_s2)();
    void *var_s0;
    s16 var_s1;
    s32 var_s4;
    u8 *var_s3;
    void *temp_v0;
    void *var_s5;

    temp_v0 = (arg0 * 0x1FC) + &D_800B9CD8;
    var_s5 = temp_v0 + 0x1A;
    var_s4 = 0;
    D_800A4F1D = 1;
    M2C_FIELD(temp_v0, s8 *, 0x1FA) = 0;
    do {
        var_s3 = var_s5 + 9;
        var_s1 = 0;
        var_s0 = &D_800C6E2D;
        var_s2 = D_80073140;
loop_2:
        var_s3 += 1;
        if (*var_s3 != 0) {
            M2C_FIELD(var_s0, s8 *, 1) = 1;
            M2C_FIELD(var_s0, s8 *, 0) = 0;
            func_8003916C(var_s1);
            func_8002EFF8(0, *var_s2);
        }
        var_s2 += 4;
        var_s1 += 1;
        var_s0 += 0x60;
        if (var_s1 < 0x10) {
            goto loop_2;
        }
        var_s4 += 1;
        var_s5 += 0x1A;
    } while (var_s4 < 0x10);
    D_800A4F1D = 0;
}
