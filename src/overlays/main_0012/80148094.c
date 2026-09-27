/* Overlay range [80148094,801483E8) from MAIN.CD member 0012.
 * SHA256(span)=b8dc0b57872c3a657cd7957723136792f35436101394a34ba1785ea0b5adcb44.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80012558(void *, s16);              /* extern */
s16 func_80012A60(s16, s16);                        /* extern */
void func_80013F3C(void *);                   /* extern */
s32 func_80047B3C(s32);                             /* extern */
void func_800484EC(void *, void *, s32 *);    /* extern */
s32 func_8004CFEC(s16, s16);                        /* extern */

void func_80148094(void *arg0, void *arg1, void *arg2) {
    s32 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s16 temp_a1;
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    void *temp_s4;

    temp_a1 = M2C_FIELD(arg1, s16 *, 0);
    temp_s4 = M2C_FIELD(arg0, void **, 0x20);
    if ((temp_a1 != 0) || (M2C_FIELD(arg1, s16 *, 4) != 0)) {
        temp_s1 = func_8004CFEC(-M2C_FIELD(arg1, s16 *, 4), -temp_a1) + 0x400;
        func_80013F3C(&sp20);
        func_80012558(&sp20, M2C_FIELD(temp_s4, s16 *, 0x12));
        func_800484EC(&sp20, arg0 + 0x24, &sp10);
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x24);
        temp_s0 = func_80012A60(temp_s1, (s16) (func_8004CFEC((s16) sp18, (s16) sp10) + 0x400));
        sp10 = temp_v1;
        if (temp_v1 < 0) {
            sp10 = -temp_v1;
        }
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x2C);
        sp18 = temp_v0;
        if (temp_v0 < 0) {
            sp18 = -temp_v0;
        }
        temp_v0_2 = M2C_FIELD(arg1, s16 *, 0);
        temp_v0_3 = M2C_FIELD(arg1, s16 *, 4);
        var_v0 = func_80047B3C((temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3));
        if (var_v0 < 0) {
            var_v0 += 0x3F;
        }
        temp_a0 = func_8004CFEC(M2C_FIELD(arg1, s16 *, 2), (s16) (var_v0 >> 6));
        if (temp_s0 < 0x200) {
            if (sp10 == sp18) {
                temp_v1_2 = -temp_a0;
                sp10 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) * temp_v1_2) / 1024;
                sp14 = 0;
                var_v0_2 = M2C_FIELD(arg0, s32 *, 0x2C) * temp_v1_2;
                if (var_v0_2 < 0) {
                    var_v0_2 += 0x3FF;
                }
                var_v0_3 = var_v0_2 >> 0xA;
            } else {
                if (sp18 < sp10) {
                    sp10 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) * -temp_a0) / 1024;
                    sp14 = 0;
                    goto block_25;
                }
                sp14 = 0;
                sp10 = M2C_FIELD(arg0, s32 *, 0x24);
                var_v0_4 = M2C_FIELD(arg0, s32 *, 0x2C) * -temp_a0;
                if (var_v0_4 < 0) {
                    var_v0_4 += 0x3FF;
                }
                var_v0_3 = var_v0_4 >> 0xA;
            }
        } else if (temp_s0 >= 0x201) {
            if (sp10 == sp18) {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x24);
                temp_a1_2 = -temp_a0;
                sp10 = temp_v1_3 + ((s32) (temp_v1_3 * temp_a1_2) / 1024);
                sp14 = 0;
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x2C);
                var_v0_3 = temp_a0_2 + ((s32) (temp_a0_2 * temp_a1_2) / 1024);
            } else {
                if (sp18 < sp10) {
                    temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x24);
                    sp10 = temp_v1_4 + ((s32) (temp_v1_4 * -temp_a0) / 1024);
                    sp14 = 0;
                    goto block_25;
                }
                sp14 = 0;
                sp10 = M2C_FIELD(arg0, s32 *, 0x24);
                temp_a1_3 = M2C_FIELD(arg0, s32 *, 0x2C);
                var_v0_3 = temp_a1_3 + ((s32) (temp_a1_3 * -temp_a0) / 1024);
            }
        } else {
            sp14 = 0;
            sp10 = M2C_FIELD(arg0, s32 *, 0x24);
block_25:
            var_v0_3 = M2C_FIELD(arg0, s32 *, 0x2C);
        }
        sp18 = var_v0_3;
        M2C_FIELD(arg2, s32 *, 0) = sp10;
        M2C_FIELD(arg2, s32 *, 4) = sp14;
        M2C_FIELD(arg2, s32 *, 8) = var_v0_3;
        return;
    }
    M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
}
