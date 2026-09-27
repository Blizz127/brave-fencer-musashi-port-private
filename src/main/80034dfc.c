/* Exact retail word export for [80034DFC,8003500C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEF5;
extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern s32 *D_80076118;

void func_80034DFC(s32 arg0) {
    s16 temp_s1;
    s16 var_a1;
    s16 var_s2;
    u8 temp_s3;
    void *temp_s0;
    void *var_v1;

    if ((arg0 << 0x10) != 0) {
        var_a1 = arg0 - 1;
        var_v1 = (var_a1 * 0x30) + &D_80076118;
        temp_s3 = D_8006AEF5;
        D_8006AEF5 = 1U;
        if (var_v1->unk0 != 0) {
            var_v1->unk0 = 0U;
            var_v1->unk1 = 1;
            if ((var_a1 != D_8006AEF8) && (var_v1->unk7 != 0)) {
                var_s2 = var_a1 + 1;
loop_6:
                if (var_s2 >= 4) {
                    var_s2 = 0;
                }
                if (var_s2 != D_8006AEFC) {
                    temp_s0 = (var_s2 * 0x30) + &D_80076118;
                    var_v1->unk0 = (u8) temp_s0->unk0;
                    var_v1->unk1 = (u8) temp_s0->unk1;
                    var_v1->unk2 = (u8) temp_s0->unk2;
                    var_v1->unk3 = (u8) temp_s0->unk3;
                    var_v1->unk4 = (u8) temp_s0->unk4;
                    var_v1->unk5 = (u8) temp_s0->unk5;
                    var_v1->unk6 = (u8) temp_s0->unk6;
                    var_v1->unk7 = (u8) temp_s0->unk7;
                    var_v1->unk8 = (s32) temp_s0->unk8;
                    var_v1->unkC = (s32) temp_s0->unkC;
                    var_v1->unk10 = (s32) temp_s0->unk10;
                    var_v1->unk14 = (s32) temp_s0->unk14;
                    var_v1->unk18 = (s32) temp_s0->unk18;
                    var_v1->unk1C = (s32) temp_s0->unk1C;
                    var_v1->unk20 = (s32) temp_s0->unk20;
                    var_v1->unk24 = (s32) temp_s0->unk24;
                    temp_s1 = var_s2 + 1;
                    var_v1->unk28 = (s32 (*)()) temp_s0->unk28;
                    var_v1->unk2C = (s32) temp_s0->unk2C;
                    temp_s0->unk28(temp_s1, var_a1 + 1);
                    var_a1 = var_s2;
                    var_v1 = temp_s0;
                    var_s2 = temp_s1;
                    goto loop_6;
                }
                D_8006AEFC = (s32) var_a1;
                *(&D_80076118 + (var_a1 * 0x30)) = 0;
            }
        }
        D_8006AEF5 = temp_s3;
    }
}
