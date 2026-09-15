/* Overlay range [80143640,801437D8) from MAIN.CD member 0012.
 * SHA256(span)=a6e186045920e868d566dca5d5917f320b89e8f96d01fa1045ee8711348ac55c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C(s16);                             /* extern */
void *func_8012913C();                             /* static */

void func_80143640(u16 *arg0, void *arg1, void *arg2, s32 arg3) {
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s32 temp_v1;
    void *temp_v0;

    if (!(*arg0 & (s16) ((1 << arg3) - 1))) {
        temp_v0 = func_8012913C(0x22);
        if (temp_v0 != 0) {
            temp_a0 = arg2->unk0;
            temp_v0->unk6 = (s16) ((arg1->unk0 + (func_8005C49C() % (s32) (temp_a0 * 2))) - temp_a0);
            temp_a0_2 = arg2->unk2;
            temp_v0->unkA = (s16) ((arg1->unk2 + (func_8005C49C(temp_a0) % (s32) (temp_a0_2 * 2))) - temp_a0_2);
            temp_a0_3 = arg2->unk4;
            temp_v1 = func_8005C49C(temp_a0_2) % (s32) (temp_a0_3 * 2);
            temp_v0->unk18 = 0;
            temp_v0->unk14 = 0;
            temp_v0->unk10 = 0;
            temp_v0->unkE = (s16) ((arg1->unk4 + temp_v1) - temp_a0_3);
            temp_v0->unk34 = (u16) arg1->unk6;
            temp_v0->unk20->unk2C = 0xC008;
        }
    }
    *arg0 += 1;
}
