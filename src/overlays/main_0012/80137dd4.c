/* Overlay range [80137DD4,80137FD8) from MAIN.CD member 0012.
 * SHA256(span)=ebb82deffe593086cb253e7b484b49434596cadaff55a7a4af95a2828902cfd4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80010A08(s32, s32);                          /* extern */
void func_80137FD8(void *, void *, s32, s16);          /* static */

void func_80137DD4(void *arg0, void *arg1, void *arg2) {
    s16 temp_s0;
    s32 *temp_a0_2;
    s32 *temp_v1;
    s32 *temp_v1_2;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_a1;
    void *temp_v0;

    temp_a0 = arg0->unk12 - arg0->unk16;
    var_a1 = temp_a0;
    if (temp_a0 & 0x8000) {
        var_a1 = arg0->unk2E + (temp_a0 + 1);
    }
    temp_s0 = arg0->unk32 + ((s16) ((var_a1 - arg0->unk21) + ((s8) arg0->unk1F + 1)) * 0xE);
    temp_s1 = func_80010A08(0x48, var_a1);
    temp_a2 = temp_s1;
    arg1->unk3 = 0;
    func_80137FD8(arg0, arg1, temp_a2, temp_s0);
    temp_s1->unk0 = (s32) ((temp_s1->unk0 & 0xFF000000) | (*((arg0->unk1A * 4) + arg2->unk4) & 0xFFFFFF));
    temp_s1_2 = temp_s1 + 0x24;
    temp_v1 = (arg0->unk1A * 4) + arg2->unk4;
    *temp_v1 = (*temp_v1 & 0xFF000000) | (temp_s1 & 0xFFFFFF);
    arg1->unk3 = 1;
    func_80137FD8(arg0, arg1, temp_s1_2, temp_s0);
    temp_s1->unk24 = (s32) ((temp_s1->unk24 & 0xFF000000) | (*((arg0->unk1A * 4) + arg2->unk4) & 0xFFFFFF));
    temp_v1_2 = (arg0->unk1A * 4) + arg2->unk4;
    *temp_v1_2 = (*temp_v1_2 & 0xFF000000) | (temp_s1_2 & 0xFFFFFF);
    temp_v0 = func_80010A08(8);
    temp_v0->unk3 = 1;
    temp_v0->unk4 = 0xE100000A;
    temp_v0->unk0 = (s32) ((temp_v0->unk0 & 0xFF000000) | (*((arg0->unk1A * 4) + arg2->unk4) & 0xFFFFFF));
    temp_a0_2 = (arg0->unk1A * 4) + arg2->unk4;
    *temp_a0_2 = (*temp_a0_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
}
