/* Exact retail word export [800476C0,8004787C); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006D058;
extern s32 *D_8006D070;
extern s32 D_8006D074;
extern s32 D_80073AB4;
void func_8005C604(s32 (*)(), s32, s32);                   /* static */

void func_800476C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_v0;
    s8 var_a0_2;
    void *temp_a1_2;

    var_a0 = 0;
    temp_a1 = arg0 * 0x10;
    var_v0 = arg5 & 0xFF;
    if ((temp_a1 + 0x1F800000)->unk1088 & 0x01000000) {
loop_2:
        if (var_a0 != 0x10000) {
            var_a0 += 1;
            if (!((temp_a1 + 0x1F800000)->unk1088 & 0x01000000)) {
                var_v0 = arg5 & 0xFF;
            } else {
                goto loop_2;
            }
        } else {
            func_8005C604(D_80073AB4, (temp_a1 + 0x1F800000)->unk1088, 0x10000);
            var_v0 = arg5 & 0xFF;
        }
    }
    temp_v0 = 1 << arg0;
    if (var_v0 == 1) {
        var_a0_2 = D_8006D074->unk2 | temp_v0;
    } else {
        var_a0_2 = D_8006D074->unk2 & ~temp_v0;
    }
    D_8006D074->unk2 = var_a0_2;
    temp_v0_2 = arg0 * 0x10;
    temp_a1_2 = temp_v0_2 + 0x1F801080;
    *D_8006D070 |= 1 << ((arg0 * 4) + 3);
    *(0x1F801080 + temp_v0_2) = arg1;
    temp_a1_2->unk4 = (s32) ((arg2 << 0x10) | arg3);
    if (!(*D_8006D058 & 0x40)) {
        do {

        } while (!(*D_8006D058 & 0x40));
    }
    (temp_a1_2 + 4)->unk4 = arg4;
}
