/* Main-exec range [800193B8,8001971C) from the SLUS executable.
 * SHA256(span)=35d47bb97eea16e04ae585d91cb7756e36278a95e49388a48a8ffddf1d5560a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_800193B8
"
    ".ent	func_800193B8
"
    ".type	func_800193B8, @function
"
    "func_800193B8:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_800193B8
"
    ".size	func_800193B8, .-func_800193B8
"
);
#else
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062C38;
extern s32 D_80062C68;
extern s32 D_80062DE8;
extern s32 D_80063074;
extern s32 D_800747D0;
extern s32 D_800747D8;
void func_80019990();                                  /* static */
s32 func_80019A24(s32 (*)(), s32, s32, s32);                /* static */
void func_8004239C();                                 /* static */
void func_80043A18(void *, s32 (*)(), s32 *, void *);       /* static */
s32 *func_80043B1C(void *);                         /* static */
extern s32 *D_800AE830;
extern s32 *D_800AE834;
extern s32 D_80180000;
extern s32 *D_80180004;
extern s32 D_80180008;
extern s32 D_80180010;
extern s32 D_80180018;
extern s32 D_80180020;

void func_800193B8(s32 arg0) {
    s32 *spB4;
    s32 spB0;
    s32 spA8;
    s32 sp18;
    ? sp10();
    s32 (*var_a1)();
    s32 (*var_s1)();
    s32 (*var_s4)();
    void *var_a3;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 *var_s1_2;
    s32 *var_s5;
    s32 temp_a0;
    s32 temp_s2_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_fp;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s6;
    s32 var_s7;
    s32 var_s7_2;
    s32 var_v1;
    void *temp_s2;
    void *temp_s2_2;

    func_80019990();
    temp_s2 = arg0 + 1;
    D_800747D0 = 0;
    D_80063074 = 0;
    D_800747D8 = 0;
    func_80043A18(temp_s2, sp10);
loop_1:
    var_a3 = &sp18;
    if (func_80019A24(sp10, 0x80180000, 0x800, 0) == 0) {
        func_8004239C(0);
        goto loop_1;
    }
    var_a2 = &D_80180000;
    if ((s32) var_a3 & 3) {
        do {
            var_a3->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            var_a3->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            var_a3->unkB = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            var_a3->unkF = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            var_a3 += 0x10;
        } while (var_a2 != (s32 *)0x80180080);
    } else {
        do {
            var_a3->unk0 = (s32) *var_a2;
            var_a3->unk4 = (s32) *var_a2;
            var_a3->unk8 = (s32) *var_a2;
            var_a3->unkC = (s32) *var_a2;
            var_a3 += 0x10;
        } while (var_a2 != (s32 *)0x80180080);
    }
    var_a3->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    var_a3->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    temp_s2_2 = temp_s2 + 1 + ((u32) (sp34 + 0x7FF) >> 0xB);
    func_80043A18(temp_s2_2, sp10, var_a2, var_a3);
loop_10:
    var_s7 = 2;
    if (func_80019A24(sp10, 0x80180000, 0x800, 0) == 0) {
        func_8004239C(0);
        goto loop_10;
    }
    temp_s2_3 = temp_s2_2 + 1;
    var_s1 = D_80062C38 + 0x60;
    func_80043A18(temp_s2_3 + D_80180000, D_80062C38);
    func_80043A18(temp_s2_3 + D_80180008, D_80062C38 + 0x30);
    var_a1 = var_s1;
    do {
        var_s1 += 0x30;
        var_s7 += 1;
        func_80043A18(temp_s2_3 + D_80180010, var_a1);
        var_a1 = var_s1;
    } while (var_s7 < 9);
    func_80043A18(temp_s2_3 + D_80180018, D_80062DE8);
    func_80043A18(temp_s2_3 + D_80180020, D_80062DE8 + 0x210);
loop_15:
    var_fp = 0;
    if (func_80019A24(D_80062C38, 0x80180000, 0xE40, 0) == 0) {
        func_8004239C(0);
        goto loop_15;
    }
    var_s6 = 0;
    var_s7_2 = 0;
    spA8 = 0;
    var_s5 = &D_80180000;
    do {
        var_v1 = *var_s5;
        var_s6 += 1;
        var_s3 = 0;
        var_a2_2 = func_80043B1C(spA8 + D_80062C68);
        if (var_v1 > 0) {
            temp_v0 = var_fp * 8;
            var_s4 = temp_v0 + &D_800AE830;
            var_s2 = temp_v0;
            temp_v0_2 = var_s6 * 8;
            var_s1_2 = temp_v0_2 + &D_80180000;
            var_s0 = temp_v0_2;
            do {
                temp_a0 = *var_s1_2;
                if (temp_a0 != 0) {
                    spB0 = var_v1;
                    spB4 = var_a2_2;
                    func_80043A18(temp_a0 + var_a2_2, var_s4, var_a2_2);
                    *(&D_800AE834 + var_s2) = *(var_s0 + &D_80180004);
                }
                var_s0 += 8;
                var_s5 += 8;
                var_s6 += 1;
                var_s4 += 8;
                var_s2 += 8;
                var_s3 += 1;
                var_fp += 1;
            } while (var_s3 < var_v1);
        }
        var_s7_2 += 1;
        spA8 += 0x30;
    } while (var_s7_2 < 8);
}
#endif

