/* Overlay range [8016C83C,8016C998) from MAIN.CD member 0012.
 * SHA256(span)=3b2d09722548014b7c2bd4bd86dc9832f0a86aeb13967990429152fd350b6eda.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047E98(s16 *, s16 *);                    /* extern */
void func_800D22E4(void *);                      /* extern */
void func_8016CF04(void *, s32);             /* static */

void func_8016C83C(void *arg0) {
    s16 sp14;                                       /* compiler-managed */
    s16 sp12;                                       /* compiler-managed */
    s16 sp10;                                       /* compiler-managed */
    s32 var_a1;
    s32 temp_v0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x34);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s16 *, 2) = 4;
        var_a1 = 2;
    } else {
        sp10 = M2C_FIELD(temp_a1, u16 *, 6) - M2C_FIELD(arg0, u16 *, 6);
        sp12 = M2C_FIELD(temp_a1, u16 *, 0xA) - M2C_FIELD(arg0, u16 *, 0xA);
        sp14 = M2C_FIELD(temp_a1, u16 *, 0xE) - M2C_FIELD(arg0, u16 *, 0xE);
        if (func_80047E98(&sp10, &sp10) < 0x790) {
            M2C_FIELD(arg0, s16 *, 2) = 4;
            var_a1 = 2;
        } else {
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (sp10 << 6));
            M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + (sp12 << 6));
            M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + (sp14 << 6));
            sp10 = M2C_FIELD(arg0, u16 *, 0x12);
            sp12 = M2C_FIELD(arg0, u16 *, 0x16);
            sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
            if (func_80047E98((s16 *) &sp10, (s16 *) &sp10) > 0x1000) {
                M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((s16) sp10 << 0xA);
                M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((s16) sp12 << 0xA);
                M2C_FIELD(arg0, s32 *, 0x18) = (s32) ((s16) sp14 << 0xA);
            }
            func_800D22E4(arg0);
            var_a1 = 1;
        }
    }
    func_8016CF04(arg0, var_a1);
}
