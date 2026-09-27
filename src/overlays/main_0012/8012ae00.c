/* Overlay range [8012AE00,8012AF0C) from MAIN.CD member 0012.
 * SHA256(span)=ae81aba67de9f37d0ad32faa3b6d035a94c4babcb830d81f1452dbec26709587.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80013478(void *, u16 *);                   /* extern */
s32 func_80135888(s32, s32, u16 *, void *);      /* static */
extern s32 *D_80126B58;
extern s32 D_80126B78;
extern s32 D_80126B90;

s32 func_8012AE00(void *arg0) {
    s32 sp27;
    s32 sp23;
    s32 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_s0_2;
    void *temp_s0;

    sp10 = M2C_FIELD(arg0, u16 *, 0x3A);
    sp12 = M2C_FIELD(arg0, u16 *, 0x3E);
    sp14 = M2C_FIELD(arg0, u16 *, 0x42);
    sp18 = M2C_FIELD(arg0, u16 *, 6);
    sp1A = M2C_FIELD(arg0, u16 *, 0xA);
    sp1C = M2C_FIELD(arg0, u16 *, 0xE);
    sp23 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp27 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    temp_s0 = &D_80126B58 + 4;
    if (func_80135888(D_80126B78, D_80126B90, &sp10, &sp20) != 0) {
        temp_s0_2 = func_80013478(temp_s0, &sp10);
        if (temp_s0_2 >= func_80013478(temp_s0, &sp18)) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
