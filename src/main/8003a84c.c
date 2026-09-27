/* Native retail instruction export [8003A84C,8003AA18).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 D_8006B564;
extern s32 D_8007344C;
extern s32 D_8007346C;
extern s32 D_80073480;
void func_8003B0E4(u16);                               /* static */
void func_8005C604(s32 (*)(), s32 (*)());                  /* static */

void func_8003A84C(u16 *arg0, u32 arg1) {
    s32 temp_a1_2;
    s32 var_v0;
    s32 var_v1;
    u16 *var_s2;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v0;
    u32 var_s0;
    u32 var_s1;
    u32 var_v1_2;
    u32 var_v1_3;

    var_s1 = arg1;
    temp_a1 = D_8006B54C->unk1AE;
    var_s2 = arg0;
    D_8006B54C->unk1A6 = (u16) D_8006B564;
    func_8003B0E4(temp_a1);
    var_v0 = var_s1 < 0x41U;
    if (var_s1 != 0) {
        do {
            var_s0 = 0x40;
            if (var_v0 != 0) {
                var_s0 = var_s1;
            }
            var_v1 = 0;
            if ((s32) var_s0 > 0) {
                do {
                    temp_v0 = *var_s2;
                    var_s2 += 2;
                    var_v1 += 2;
                    D_8006B54C->unk1A8 = temp_v0;
                } while (var_v1 < (s32) var_s0);
            }
            temp_a0 = (D_8006B54C->unk1AA & 0xFFCF) | 0x10;
            D_8006B54C->unk1AA = temp_a0;
            func_8003B0E4(temp_a0);
            if (D_8006B54C->unk1AE & 0x400) {
                var_v1_2 = 1;
loop_8:
                if (var_v1_2 >= 0xF01U) {
                    func_8005C604(D_8007344C, D_8007346C);
                } else {
                    var_v1_2 += 1;
                    if (D_8006B54C->unk1AE & 0x400) {
                        goto loop_8;
                    }
                }
            }
            var_s1 -= var_s0;
            func_8003B0E4();
            func_8003B0E4();
            var_v0 = var_s1 < 0x41U;
        } while (var_s1 != 0);
    }
    D_8006B54C->unk1AA = (u16) (D_8006B54C->unk1AA & 0xFFCF);
    temp_a1_2 = temp_a1 & 0x7FF & 0xFFFF;
    var_v1_3 = 1;
    if ((D_8006B54C->unk1AE & 0x7FF) != temp_a1_2) {
loop_13:
        if (var_v1_3 >= 0xF01U) {
            func_8005C604(D_8007344C, D_80073480);
            return;
        }
        var_v1_3 += 1;
        if ((D_8006B54C->unk1AE & 0x7FF) == temp_a1_2) {

        } else {
            goto loop_13;
        }
    }
}
