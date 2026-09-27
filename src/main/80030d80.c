/* Exact retail word export for [80030D80,80030F80); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073140;
void func_8002EFF8(s32, s32, s32 (*)());                   /* static */
void func_80031988(void *);                            /* static */
extern s32 *D_800A4C2C;
extern s32 *D_800A4C6D;
extern u8 D_800A4F17;
extern s32 D_800C7D20;

void func_80030D80(void *arg0, s32 arg1, s32 (*arg2)()) {
    s32 (*temp_v0)();
    s32 (*var_a2)();
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s1;
    s32 var_v0;
    u8 temp_s2;

    var_a2 = arg2;
    temp_s2 = D_800A4F17;
    D_800A4F17 = 1;
    var_s1 = 1;
    if (arg0->unk0 != 0) {
        arg0->unk0 = 0;
    } else {
        var_v0 = arg1 << 0x10;
        if ((u8) arg0->unk4E >= 2U) {
            var_a2 = D_80073140;
            var_v0 = arg1 << 0x10;
            if (D_800C7D20 & *(D_80073140 + (arg0->unkA * 4))) {
                *(&D_800A4C6D + (arg0->unk51 * 0x48)) = 1;
                temp_v1 = arg0->unk51 * 0x48;
                *(&D_800A4C2C + temp_v1) = *(&D_800A4C2C + temp_v1) & 0xFFF9FFFF;
                var_a1 = *((arg0->unkA * 4) + D_80073140);
                var_s1 = 1;
                goto block_7;
            }
        }
        var_s1 = 0;
        if (var_v0 != 0) {
            arg0->unk50 = 1;
            *(&D_800A4C6D + (arg0->unk51 * 0x48)) = 1;
            temp_v1_2 = arg0->unk51 * 0x48;
            *(&D_800A4C2C + temp_v1_2) = *(&D_800A4C2C + temp_v1_2) & 0xFFF9FFFF;
            var_a1 = *(D_80073140 + (arg0->unkA * 4));
block_7:
            func_8002EFF8(0, var_a1, var_a2);
        } else {
            arg0->unk50 = 0;
            func_8002EFF8(0, *(D_80073140 + (arg0->unkA * 4)), var_a2);
            func_80031988(arg0);
        }
    }
    temp_v0 = arg0->unk40;
    if (temp_v0 != 0) {
        temp_v0(arg0->unk51, arg0->unk44);
    }
    arg0->unk40 = 0;
    if (var_s1 & 0xFF) {
        arg0->unk4E = 0U;
    }
    D_800A4F17 = temp_s2;
}
