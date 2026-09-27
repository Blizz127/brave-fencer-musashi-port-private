/* Overlay range [8014E048,8014E284) from MAIN.CD member 0012.
 * SHA256(span)=553a9ff705612ab46df5806ab6dcad88ad858b53b55009b7d143b955c74c4ffc.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s16);                        /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */
s32 func_80133784(s32, u16 *, s16 *, u16);      /* static */
s32 func_80135A4C(s32, s32, void *, void *);        /* static */
extern u16 D_801152A8;
extern u16 D_801152AC;

s32 func_8014E048(void *arg0, void *arg1, void *arg2) {
    s16 sp1C;
    u16 sp1A;
    s16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s1;
    s16 temp_s1_2;
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_v0_3;
    u16 temp_a3;
    u16 temp_a3_2;
    u16 temp_v0_2;
    u16 temp_v1;
    void *temp_s2;

    temp_s0 = M2C_FIELD(arg2, u16 *, 0) - M2C_FIELD(arg1, u16 *, 0);
    temp_s1 = M2C_FIELD(arg2, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
    if (((temp_s0 | temp_s1) << 0x10) != 0) {
        sp18 = temp_s0;
        sp1A = M2C_FIELD(arg2, u16 *, 2) - M2C_FIELD(arg1, u16 *, 2);
        sp18 = -temp_s0;
        temp_v0 = M2C_FIELD(arg2, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
        sp1C = temp_v0;
        sp1C = -temp_v0;
        temp_s2 = M2C_FIELD(arg0, void **, 0x170);
        if ((M2C_FIELD(temp_s2, u16 *, 0) != 0) && (M2C_FIELD(temp_s2, u16 *, 0x5C) & 0x1000)) {
            temp_a1 = M2C_FIELD(temp_s2, s32 *, 0x58);
            if ((temp_a1 != 0) && (func_80135A4C(M2C_FIELD(temp_s2, s32 *, 0x20), temp_a1, arg1, arg2) != 0)) {
                temp_s1_2 = M2C_FIELD(temp_s2, u16 *, 6) - M2C_FIELD(arg0, u16 *, 6);
                temp_s0_2 = M2C_FIELD(temp_s2, u16 *, 0xE) - M2C_FIELD(arg0, u16 *, 0xE);
                temp_s0_3 = func_8004CFEC(temp_s1, temp_s0);
                if (func_80012A60(temp_s0_3, func_8004CFEC(temp_s0_2, temp_s1_2)) < 0x400) {
                    temp_v0_2 = M2C_FIELD(temp_s2, u16 *, 6);
                    sp10 = temp_v0_2;
                    temp_a3 = M2C_FIELD(temp_s2, u16 *, 0xA);
                    sp12 = temp_a3;
                    temp_v1 = M2C_FIELD(temp_s2, u16 *, 0xE);
                    sp18 = temp_v0_2 + (u16) sp18;
                    temp_a3_2 = temp_a3 + sp1A;
                    sp14 = temp_v1;
                    sp1A = temp_a3_2;
                    sp1C = temp_v1 + (u16) sp1C;
                    temp_v0_3 = func_80133784(0, &sp10, &sp18, temp_a3_2);
                    if ((temp_v0_3 == 0) || ((temp_v0_3 & 0x2000) && ((D_801152A8 | D_801152AC) == 0))) {
                        M2C_FIELD(temp_s2, u16 *, 6) = (u16) sp18;
                        M2C_FIELD(temp_s2, u16 *, 0xA) = sp1A;
                        M2C_FIELD(temp_s2, u16 *, 0xE) = (u16) sp1C;
                    } else {
                        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 0);
                        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg1, u16 *, 2) + 0x10);
                        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg1, u16 *, 4);
                    }
                    return 1;
                }
            }
        }
    }
    M2C_FIELD(arg0, void **, 0x170) = 0;
    return 0;
}
