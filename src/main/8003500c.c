/* Exact retail word export for [8003500C,800351E8); EXE and assembly verified. */
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
extern s32 D_80076114;
extern s32 *D_80076118;
extern s32 *D_80076138;
extern s8 D_8007620C;

void func_8003500C(void) {
    s32 (*temp_a2)();
    s32 (*temp_v0_2)();
    u32 temp_v0;
    u32 temp_v0_3;
    u8 temp_a1;
    void *temp_s0;

    if (D_8006AEF5 == 0) {
        if (D_8006AEFC != D_8006AEF8) {
            temp_s0 = (D_8006AEF8 * 0x30) + &D_80076118;
            if (temp_s0->unk0 != 0) {
                D_80076114 = (s32) temp_s0->unk4;
                if (temp_s0->unk8(temp_s0) != 0) {
                    temp_a1 = temp_s0->unk4;
                    temp_a2 = temp_s0->unk1C;
                    D_80076114 = (s32) temp_a1;
                    if (temp_a2 != 0) {
                        temp_a2(*(&D_80076138 + (D_8006AEF8 * 0x30)), temp_a1, temp_a2);
                    }
                    temp_s0->unk0 = 0U;
                    temp_s0->unk1 = 0U;
                    temp_v0 = D_8006AEF8 + 1;
                    D_8006AEF8 = temp_v0;
                    if (temp_v0 >= 4U) {
                        D_8006AEF8 = 0U;
                    }
                    if (D_8006AEF8 == D_8006AEFC) {
                        goto block_9;
                    }
                }
            } else if ((temp_s0->unk1 != 0) && (temp_s0->unk7 == 0)) {
                temp_v0_2 = temp_s0->unk24;
                if (temp_v0_2 != 0) {
                    temp_v0_2(temp_s0);
                }
                if (temp_s0->unk2 == 0) {
                    goto block_15;
                }
            } else {
block_15:
                temp_s0->unk1 = 0U;
                temp_v0_3 = D_8006AEF8 + 1;
                D_8006AEF8 = temp_v0_3;
                if (temp_v0_3 >= 4U) {
                    D_8006AEF8 = 0U;
                }
                if (D_8006AEF8 != D_8006AEFC) {
                    D_80076114 = 1;
                    return;
                }
block_9:
                D_80076114 = 0;
            }
        } else {
            D_8007620C = 0;
        }
    }
}
