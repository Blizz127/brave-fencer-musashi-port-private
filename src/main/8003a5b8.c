/* Native retail instruction export [8003A5B8,8003A84C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 D_8006B55C;
extern s32 D_8006B564;
extern s32 D_8006B568;
extern s32 D_8006B56C;
extern s32 D_8006B570;
extern s32 D_8006B574;
extern s32 D_8006B578;
extern s32 D_8006B57C;
extern s32 D_8006B580;
extern s32 D_8006B584;
extern s32 D_8006B588;
extern s32 D_8006B58C;
extern s32 D_8007344C;
extern s32 D_8007345C;
void func_8003A84C(s32 (*)(), s32);                        /* static */
void func_8003B0E4(s32 *, s32, s32);                       /* static */
void func_8005C604(s32 (*)(), s32 (*)());                  /* static */
extern s16 D_800A6410;

s32 func_8003A5B8(s32 arg0) {
    s16 *var_a1;
    s32 var_a0;
    s32 var_a0_2;
    u32 var_v1;
    void *var_v1_2;

    *D_8006B55C |= 0xB0000;
    D_8006B568 = 0;
    D_8006B56C = 0;
    D_8006B564 = 0;
    D_8006B54C->unk180 = 0;
    D_8006B54C->unk182 = 0;
    D_8006B54C->unk1AA = 0;
    func_8003B0E4(D_8006B55C);
    D_8006B54C->unk180 = 0;
    D_8006B54C->unk182 = 0;
    if (D_8006B54C->unk1AE & 0x7FF) {
        var_v1 = 1;
loop_2:
        if (var_v1 >= 0xF01U) {
            func_8005C604(D_8007344C, D_8007345C);
            var_a0 = 0;
        } else {
            var_v1 += 1;
            if (!(D_8006B54C->unk1AE & 0x7FF)) {
                goto block_5;
            }
            goto loop_2;
        }
    } else {
block_5:
        var_a0 = 0;
    }
    var_a1 = &D_800A6410;
    D_8006B570 = 2;
    D_8006B574 = 3;
    D_8006B578 = 8;
    D_8006B57C = 7;
    D_8006B54C->unk1AC = 4;
    D_8006B54C->unk184 = 0;
    D_8006B54C->unk186 = 0;
    D_8006B54C->unk18C = 0xFFFF;
    D_8006B54C->unk18E = 0xFFFF;
    D_8006B54C->unk198 = 0;
    D_8006B54C->unk19A = 0;
    do {
        *var_a1 = 0;
        var_a0 += 1;
        var_a1 += 2;
    } while (var_a0 < 0xA);
    if (arg0 == 0) {
        D_8006B564 = 0x200;
        D_8006B54C->unk190 = 0;
        D_8006B54C->unk192 = 0;
        D_8006B54C->unk194 = 0;
        D_8006B54C->unk196 = 0;
        D_8006B54C->unk1B0 = 0;
        D_8006B54C->unk1B2 = 0;
        D_8006B54C->unk1B4 = 0;
        D_8006B54C->unk1B6 = 0;
        func_8003A84C(D_8006B58C, 0x10);
        var_a0_2 = 0;
        var_v1_2 = D_8006B54C;
        do {
            var_v1_2->unk0 = 0;
            var_v1_2->unk2 = 0;
            var_v1_2->unk4 = 0x3FFF;
            var_v1_2->unk6 = 0x200;
            var_v1_2->unk8 = 0;
            var_v1_2->unkA = 0;
            var_a0_2 += 1;
            var_v1_2 += 0x10;
        } while (var_a0_2 < 0x18);
        D_8006B54C->unk188 = 0xFFFF;
        D_8006B54C->unk18A = 0xFF;
        func_8003B0E4((s32 *) var_a0_2, 0x200, 0x3FFF);
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
        D_8006B54C->unk18C = 0xFFFF;
        D_8006B54C->unk18E = 0xFF;
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
        func_8003B0E4();
    }
    D_8006B580 = 1;
    D_8006B54C->unk1AA = 0xC000;
    D_8006B584 = 0;
    D_8006B588 = 0;
    return 0;
}
