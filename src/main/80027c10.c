/* Main-exec range [80027C10,80027D20) from the SLUS executable.
 * SHA256(span)=bf87c333734cccdeeb1ce752c2a4a0d020246107e59bdc2183ec955620c5ca3e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80027D20(s32, s32, s32, u32 *, u32, s32, s32); /* static */
void func_80027F4C(s32, s32, s32, u32 *, u32, s32, s32); /* static */
extern s32 *D_80000000;

void func_80027C10(void *arg0, void *arg1, s32 arg2) {
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_v0;
    u32 *var_a3;
    u32 temp_s0;
    u32 temp_s2;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 8);
    var_a3 = M2C_FIELD(arg0, u32 **, 0xC);
    temp_s4 = M2C_FIELD(temp_v0, s32 *, 0);
    temp_s3 = M2C_FIELD(temp_v0, s32 *, 8);
    var_s1 = M2C_FIELD(temp_v0, s32 *, 0x10);
    do {
        temp_s2 = *var_a3;
        temp_s0 = *var_a3;
        temp_v1_2 = (temp_s2 >> 0x18) & 0xFC;
        switch (temp_v1_2) {                        /* irregular */
        case 0x30:
            func_80027D20(var_s1, temp_s4, temp_s3, var_a3, temp_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
            var_v0 = temp_s0 * 0x14;
block_6:
            var_s1 += var_v0;
            break;
        case 0x38:
            func_80027F4C(var_s1, temp_s4, temp_s3, var_a3, temp_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
            var_v0 = temp_s0 * 0x18;
            goto block_6;
        }
        temp_v1 = temp_s2 & 0xFFFFFF;
        var_a3 = (u32 *) (temp_v1 | (s32) &D_80000000);
    } while (temp_v1 != 0);
}
