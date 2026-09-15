/* Overlay range [8016B5C0,8016B6BC) from MAIN.CD member 0012.
 * SHA256(span)=821a37a09cc780562e5939dbb47cbbe55dfe795558c222e56f7bd47723459e61.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018155C;
void func_8016B6BC(void *, s32, s16, s16);       /* static */
void func_8016B91C(void *);                      /* static */
void func_8016B984(void *);                      /* static */
s32 func_8016B9F8();                                /* static */

void func_8016B5C0(void *arg0) {
    s32 (*var_s1)();
    s16 temp_a2;
    s32 temp_a3;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s3;
    u16 temp_v0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x18);
    if (func_8016B9F8() == 0) {
        temp_v0 = M2C_FIELD(temp_s0, u16 *, 0x1A) + 0x200;
        M2C_FIELD(temp_s0, u16 *, 0x1A) = temp_v0;
        M2C_FIELD(temp_s0, u16 *, 0x18) = temp_v0;
        if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1C);
        } else {
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1C) / 3;
        }
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) - 0x20;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
        if (temp_v0_2 < 0) {
            goto block_5;
        }
        var_s0 = 0;
        var_s1 = D_8018155C;
        do {
            temp_a2 = *var_s1;
            var_s1 += 2;
            temp_a3 = var_s0 << 0x10;
            var_s0 += 1;
            func_8016B6BC(arg0, var_s3, temp_a2, (s16) (temp_a3 >> 0x10));
        } while (var_s0 < 6);
        func_8016B91C(arg0);
        return;
    }
block_5:
    func_8016B984(arg0);
}
