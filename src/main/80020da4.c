/* Main-exec range [80020DA4,80020F34) from the SLUS executable.
 * SHA256(span)=efed07b41ad747735ab4792005103efe3913fa9e8cf201f08aecf4d27f7d23e9.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800636D4;

void func_80020DA4(void *arg0, void *arg1) {
    s16 *temp_v0_2;
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t1;
    s32 temp_t3;
    s32 temp_v0_3;
    s32 temp_v1;
    void *temp_v0;

    temp_v0 = ((arg0->unk4 & 0xFFF) * 4) + D_800636D4;
    temp_a2 = *(((arg0->unk0 & 0xFFF) * 4) + D_800636D4);
    temp_t0 = temp_v0->unk0;
    temp_t1 = temp_a2 >> 0x10;
    temp_t2 = temp_v0->unk2;
    temp_v0_2 = ((arg0->unk2 & 0xFFF) * 4) + D_800636D4;
    temp_a0 = *temp_v0_2;
    temp_v1 = (s32) *temp_v0_2;
    temp_v0_3 = temp_v1 >> 0x10;
    temp_a3 = (s32) ((s16) temp_a2 * temp_a0) >> 0xC;
    temp_t3 = (s32) (temp_t1 * temp_t2) >> 0xC;
    temp_a3_2 = (s32) (temp_t1 * temp_t0) >> 0xC;
    arg1->unkC = (s16) -temp_v1;
    arg1->unk0 = (s16) ((s32) (temp_t2 * temp_v0_3) >> 0xC);
    arg1->unk6 = (s16) ((s32) (temp_t0 * temp_v0_3) >> 0xC);
    arg1->unkE = (s16) ((s32) (temp_v0_3 * (s16) temp_a2) >> 0xC);
    arg1->unk10 = (s16) ((s32) (temp_v0_3 * temp_t1) >> 0xC);
    arg1->unk2 = (s16) (((s32) (temp_a3 * temp_t2) >> 0xC) - temp_a3_2);
    arg1->unk4 = (s16) (((s32) (temp_t3 * temp_a0) >> 0xC) + ((s32) ((s16) temp_a2 * temp_t0) >> 0xC));
    arg1->unk8 = (s16) (((s32) (temp_a3 * temp_t0) >> 0xC) + temp_t3);
    arg1->unkA = (s16) (((s32) (temp_a3_2 * temp_a0) >> 0xC) - ((s32) ((s16) temp_a2 * temp_t2) >> 0xC));
}
