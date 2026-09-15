/* Overlay range [8012C890,8012CAE4) from MAIN.CD member 0012.
 * SHA256(span)=458362dfaf9dc53e742bce1e9871ba45ba12bde0efc138513ff86a1ba9777b46.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);                         /* extern */
extern s32 D_80181B90;
extern s32 D_8011DB08;
extern u16 D_801270C4;
extern u16 D_801274E4;

void *func_8012C890(void *arg0, void *arg1, s32 arg2) {
    s32 var_a1;
    s16 temp_v1_2;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;

    arg1->unk0 = (u16) arg0->unk6;
    temp_v0 = arg0->unk0;
    arg1->unk6 = temp_v0;
    arg1->unk88 = temp_v0;
    temp_v0_2 = arg0->unk2;
    arg1->unkA = temp_v0_2;
    arg1->unk8A = temp_v0_2;
    temp_v0_3 = arg0->unk4;
    arg1->unkC = 0;
    arg1->unk8 = 0;
    arg1->unk4 = 0;
    arg1->unkE = temp_v0_3;
    arg1->unk8C = temp_v0_3;
    arg1->unk70 = (u16) arg0->unk8;
    arg1->unk72 = (s16) (arg0->unkA & 0xF7FF);
    arg1->unkFC = (u16) arg0->unkE;
    arg1->unk78 = D_80181B90;
    arg1->unkDC = (s32) arg0->unk10;
    arg1->unk36 = (u16) D_801270C4;
    temp_v0_4 = D_801270C4 + 1;
    D_801270C4 = temp_v0_4;
    if ((temp_v0_4 << 0x10) == 0) {
        D_801270C4 = 1;
    }
    if (arg2 != 0) {
        arg1->unk64 = arg2;
        arg1->unk68 = 0;
    } else {
        arg1->unk64 = 0;
        arg1->unk68 = arg0;
    }
    arg0->unkA = (u16) (arg0->unkA | 0x8000);
    arg1->unk2 = 0;
    D_801274E4 &= 0xFFFE;
    *((arg1->unk0 * 4) + D_8011DB08)(arg1);
    if (D_801274E4 & 1) {
        temp_a0 = arg1->unk20;
        if (temp_a0 != 0) {
            temp_v1 = temp_a0->unk0;
            if (temp_v1 != 1) {
                var_a1 = 0x38;
                if (temp_v1 == 2) {
                    goto block_11;
                }
            } else {
                var_a1 = 0x84;
block_11:
                func_80016714(temp_a0, var_a1);
            }
        }
        func_80016714(arg1, 0x10C);
        arg0->unkA = (u16) (arg0->unkA & 0x7FFF);
        return 0;
    }
    if (arg1->unk64 == 0) {
        temp_a1 = arg1->unk20;
        if (temp_a1 != 0) {
            if (temp_a1->unk0 == 1) {
                temp_v1_2 = arg0->unkC;
                if (temp_v1_2 != 0x7FFF) {
                    temp_a1->unk12 = temp_v1_2;
                }
            }
            goto block_18;
        }
    } else {
block_18:
        temp_a0_2 = arg1->unk20;
        if (temp_a0_2 != 0) {
            temp_a0_2->unk8 = (s16) (arg1->unk6 + arg1->unk50);
            arg1->unk20->unkA = (s16) (arg1->unkA + arg1->unk52);
            arg1->unk20->unkC = (s16) (arg1->unkE + arg1->unk54);
        }
    }
    return arg1;
}
