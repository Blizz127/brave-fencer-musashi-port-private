/* Overlay range [801347A0,80134A28) from MAIN.CD member 0012.
 * SHA256(span)=9081c7c1fc52b5080e56f02a6775b8b1c9d99a024ed45de4ac0db7ab3c6ad55b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E910;
extern s32 D_8017E914;
extern s32 D_8017E918;
s32 func_80134A28(void *, void *, s32);             /* static */
extern s32 D_801152A8;

s32 func_801347A0(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 temp_s1;
    s32 temp_v0;
    void *temp_s4;

    temp_s4 = arg2 + (arg1->unk2 * 8);
    temp_s1 = *((arg1->unk4 * 4) + arg3);
    if (func_80134A28(temp_s4, D_8017E914, temp_s1) < 0) {
        temp_v0 = func_80134A28(temp_s4, D_8017E910, temp_s1);
        if (temp_v0 >= 0) {
            D_8017E918->unk0 = (u16) D_8017E910->unk0;
            D_8017E918->unk2 = (s16) (D_8017E910->unk2 + ((s32) (temp_v0 * -0x30) / (s32) (temp_s4->unk2 * 0x30)));
            D_8017E918->unk4 = (u16) D_8017E910->unk4;
            if ((func_80134A28(arg2 + (arg1->unk6 * 8), D_8017E918, *((arg1->unk8 * 4) + arg3)) >= -0x2F00) && (func_80134A28(arg2 + (arg1->unkA * 8), D_8017E918, *((arg1->unkC * 4) + arg3)) >= -0x2F00) && (func_80134A28(arg2 + (arg1->unkE * 8), D_8017E918, *((arg1->unk10 * 4) + arg3)) >= -0x2F00) && (((arg0 << 0x10) == 0) || (func_80134A28(arg2 + (arg1->unk12 * 8), D_8017E918, *((arg1->unk14 * 4) + arg3)) >= -0x2F00)) && !(arg1->unk0 & 0x300)) {
                D_8017E918->unk0 = (u16) D_8017E910->unk0;
                D_8017E918->unk4 = (u16) D_8017E910->unk4;
                D_801152A8.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                D_801152A8.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                D_8017E910->unk6 = (u16) temp_s4->unk2;
                return 1;
            }
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return 0;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
