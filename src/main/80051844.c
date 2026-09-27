/* Main-exec range [80051844,80051B0C) from the SLUS executable.
 * SHA256(span)=08284eeecd6439d5edcb2fe51e0d0aca500b99c3fa909c0c64c99465be86cfce.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80051D78(s32, u16 *, s32 *);                   /* static */
extern s16 D_800A6548;
extern s16 D_800A654A;

void func_80051844(void *arg0, void *arg1, s32 arg2) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp18;
    s16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_v0;
    s32 temp_v0_3;
    u8 temp_v0_2;
    u8 temp_v0_4;
    u8 var_v0;
    u8 var_v0_2;

    temp_s5 = arg1->unkA + D_800A6548;
    temp_s4 = arg1->unkC + D_800A654A;
    if (arg1->unk16 & 1) {
        temp_v0 = (arg1->unk9 + arg1->unk10) - 1;
        sp3C = temp_v0;
        sp38 = temp_v0;
        var_v0 = arg1->unk9;
        sp44 = (s32) var_v0;
    } else {
        temp_v0_2 = arg1->unk9;
        sp3C = (s32) temp_v0_2;
        sp38 = (s32) temp_v0_2;
        var_v0 = (arg1->unk9 + arg1->unk10) - 1;
        sp44 = (s32) var_v0;
    }
    sp40 = (s32) var_v0;
    if (arg1->unk16 & 2) {
        temp_v0_3 = (arg1->unk8 + arg1->unkE) - 1;
        sp30 = temp_v0_3;
        sp28 = temp_v0_3;
        var_v0_2 = arg1->unk8;
        sp34 = (s32) var_v0_2;
    } else {
        temp_v0_4 = arg1->unk8;
        sp30 = (s32) temp_v0_4;
        sp28 = (s32) temp_v0_4;
        var_v0_2 = (arg1->unk8 + arg1->unkE) - 1;
        sp34 = (s32) var_v0_2;
    }
    sp2C = (s32) var_v0_2;
    arg0->unk3 = (u8) arg1->unk0;
    arg0->unk0 = (u8) arg1->unk1;
    arg0->unk1 = (u8) arg1->unk2;
    arg0->unk2 = (u8) arg1->unk3;
    arg0->unk12 = (u16) arg1->unk4;
    arg0->unkA = (u16) arg1->unk6;
    sp10 = arg1->unk12;
    sp14 = 0;
    sp12 = arg1->unk14;
    func_80051D78(arg2, &sp10, &sp18);
    arg0->unk4 = (s16) (temp_s5 + sp18);
    arg0->unk6 = (s16) (temp_s4 + sp1C);
    arg0->unk8 = (s8) sp28;
    arg0->unk9 = (s8) sp38;
    sp10 = arg1->unk12 + (u16) arg1->unkE;
    func_80051D78(arg2, &sp10, &sp18);
    arg0->unkC = (s16) (temp_s5 + sp18);
    arg0->unkE = (s16) (temp_s4 + sp1C);
    arg0->unk10 = (s8) sp2C;
    arg0->unk11 = (s8) sp3C;
    sp12 = arg1->unk14 + (u16) arg1->unk10;
    func_80051D78(arg2, &sp10, &sp18);
    arg0->unk1C = (s16) (temp_s5 + sp18);
    arg0->unk1E = (s16) (temp_s4 + sp1C);
    arg0->unk20 = (s8) sp34;
    arg0->unk21 = (s8) sp44;
    sp10 = arg1->unk12;
    func_80051D78(arg2, &sp10, &sp18);
    arg0->unk14 = (s16) (temp_s5 + sp18);
    arg0->unk16 = (s16) (temp_s4 + sp1C);
    arg0->unk18 = (s8) sp30;
    arg0->unk19 = (s8) sp40;
}
