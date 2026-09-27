/* Overlay range [8016B6BC,8016B834) from MAIN.CD member 0012.
 * SHA256(span)=00e77e59e5c02e24d237e988fd2a84ab27d144ecfa162ea4d255d9cb45d72a33.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013CFC(s16, s32, void *, s32);                /* extern */
void func_80015978(void *, u16 *);                     /* extern */
void func_8001739C(void *, u16);                          /* extern */
extern s32 D_80181544;

void func_8016B6BC(void *arg0, u32 arg1, s16 arg2, s32 arg3) {
    u16 sp38;
    s32 sp34;
    s32 sp10;
    s32 temp_a3;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 var_t0;
    u32 var_a0;

    var_a0 = 0x20;
    temp_a3 = (s32) (arg3 << 0x10) >> 0xE;
    temp_s2 = *(D_80181544 + temp_a3);
    sp34 = 0x50000000;
    if (arg1 < 0x20U) {
        var_a0 = arg1;
    }
    if (arg0->unk2C == 0) {
        var_t0 = arg1 | ((var_a0 << 0x10) | (var_a0 << 8));
    } else {
        var_t0 = (arg1 << 8) | (var_a0 << 0x10) | var_a0;
    }
    temp_s2_2 = temp_s2 + 8;
    sp10.unk18 = var_t0;
    sp10.unk1C = 0;
    sp10.unk20 = 0;
    func_80013CFC(arg2, temp_s2, &sp10, temp_a3);
    func_80013CFC(arg2, temp_s2_2, &sp10 + 8);
    func_80013CFC(arg2, temp_s2_2 + 8, &sp10 + 0x10);
    func_80015978(arg0 + 4, &sp38);
    sp10.unk0 = (u16) (sp10.unk0 + sp38);
    sp10.unk2 = (u16) (sp10.unk2 + sp3A);
    sp10.unk8 = (u16) (sp10.unk8 + sp38);
    sp10.unkA = (u16) (sp10.unkA + sp3A);
    sp10.unk10 = (u16) (sp10.unk10 + sp38);
    sp10.unk4 = 3;
    sp10.unk12 = (u16) (sp10.unk12 + sp3A);
    func_8001739C(&sp10, sp3A);
}
