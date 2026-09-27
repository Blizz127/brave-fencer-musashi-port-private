/* Overlay range [80135480,80135888) from MAIN.CD member 0012.
 * SHA256(span)=a013304adca2220a795012db515a8031787493c6938cc6db02b72efc3b4aafc9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004864C(u16 *, s32 *);                      /* extern */
void func_80048B6C(s32 *, s32 *);                      /* extern */
void func_80048EAC(void *, s32 (*)(), s32);              /* extern */
void func_8004914C(s32 *, u16);                        /* extern */
void func_8004D504(s32 (*)(), s32 *, s32 *);             /* extern */
extern s32 D_8017E910;
extern s32 D_8017E914;
extern s32 D_80184134;
extern s32 D_80184138;
extern s32 D_8018413C;
extern s32 D_80184140;
extern s32 D_80184144;
extern s32 D_80184154;
extern s32 D_8018415A;
extern s32 D_8018415E;
extern s32 D_80184162;
extern s32 *D_80000004;
extern s16 D_80184158;
extern s16 D_8018415C;
extern s16 D_80184160;

s16 func_80135480(void *arg0, s32 arg1, void *arg2, void *arg3) {
    u16 sp64;
    u16 sp62;
    u16 sp60;
    u16 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s16 var_s3;
    s16 var_v0;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_a0;
    u16 temp_a1;

    temp_a0 = arg2->unk0 - arg0->unk48;
    sp10 = temp_a0;
    temp_v1 = arg2->unk4 - arg0->unk50;
    sp18 = temp_v1;
    if ((arg1 & 0x10000000) || (var_v0 = 0, ((((temp_a0 * temp_a0) + (temp_v1 * temp_v1)) > 0x40000) == 0))) {
        var_a0 = arg1 & 0x60000000;
        if (var_a0 != 0) {
            var_s3 = 1;
            if (arg1 >= 0) {
                var_a0 &= 0x40000000;
            }
            sp14 = arg2->unk2 - arg0->unk4C;
            sp20 = arg3->unk0 - arg0->unk48;
            sp24 = arg3->unk2 - arg0->unk4C;
            sp28 = arg3->unk4 - arg0->unk50;
            if (var_a0 != 0x40000000) {
                if (var_a0 <= 0x40000000) {
                    if (var_a0 != 0x20000000) {

                    } else {
                        goto block_11;
                    }
                } else if (var_a0 == 0x60000000) {
                    D_80184134 = (s32) (0x01000000 / (s16) arg0->unk18);
                    temp_lo = 0x01000000 / (s16) arg0->unk1A;
                    var_s3 = 2;
                    D_80184138 = 0;
                    D_80184140 = 0;
                    D_8018413C = temp_lo;
                    D_80184144 = (s16) (0x01000000 / (s16) arg0->unk1C);
                    func_80048EAC(arg0 + 0x34, D_80184134, temp_lo);
                    func_8004D504(D_80184134, &sp10, &sp10);
                    func_80048B6C(&sp20, &sp20);
block_11:
                    temp_a1 = (u16) arg0->unk1C;
                    sp44 = 0;
                    sp4C = 0;
                    sp40 = (s32) arg0->unk18;
                    temp_s0 = (arg1 & 0x0FFFFFFF) | (s32) &D_80000004;
                    sp48 = (s32) arg0->unk1A;
                    sp50 = temp_a1;
                    func_8004914C(&sp40, temp_a1);
                    sp60 = *temp_s0;
                    sp62 = *temp_s0;
                    sp64 = *temp_s0;
                    func_8004864C(&sp60, &sp30);
                    D_80184158 = (s16) sp30;
                    D_8018415C = (s16) sp34;
                    D_80184160 = (s16) sp38;
                    sp60 = *temp_s0;
                    sp62 = *temp_s0;
                    sp64 = *temp_s0;
                    func_8004864C(&sp60, &sp30);
                    D_80184154 = 0;
                    D_8018415A = (s16) sp30;
                    D_8018415E = (s16) sp34;
                    D_80184162 = (s16) sp38;
                    var_s3 += 2;
                }
            } else {
                func_8004D504(arg0 + 0x34, &sp10, &sp10);
                func_80048B6C(&sp20, &sp20);
                var_s3 = 2;
            }
            D_8017E910->unk0 = (s16) sp10;
            D_8017E910->unk2 = (s16) sp14;
            D_8017E910->unk4 = (s16) sp18;
            D_8017E914->unk0 = (s16) sp20;
            D_8017E914->unk2 = (s16) sp24;
            D_8017E914->unk4 = (s16) sp28;
            return var_s3;
        }
        D_8017E910->unk0 = (s16) sp10;
        D_8017E910->unk2 = (s16) ((u16) arg2->unk2 - arg0->unk4C);
        D_8017E910->unk4 = (s16) sp18;
        D_8017E914->unk0 = (s16) ((u16) arg3->unk0 - arg0->unk48);
        D_8017E914->unk2 = (s16) ((u16) arg3->unk2 - arg0->unk4C);
        var_v0 = 1;
        D_8017E914->unk4 = (s16) ((u16) arg3->unk4 - arg0->unk50);
        /* Duplicate return node #15. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
