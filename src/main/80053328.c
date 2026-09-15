/* Exact retail word export for [80053328,80053804); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047D3C(s32);                             /* static */
void func_80053804(s16 *, void *);                        /* static */
void func_8005386C(s16 *, void *);                        /* static */
extern s32 D_800A63F0;

s32 func_80053328(s32 arg0, void *arg1) {
    s16 sp40;
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;                                       /* compiler-managed */
    s32 sp1C;                                       /* compiler-managed */
    s32 sp18;                                       /* compiler-managed */
    s32 sp14;                                       /* compiler-managed */
    s32 sp10;                                       /* compiler-managed */
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    u8 temp_s2;
    u8 temp_s3;
    u8 temp_s4;

    temp_s2 = arg1->unkC;
    temp_s3 = arg1->unkD;
    temp_s4 = arg1->unkE;
    sp10 = D_800A63F0.unk0;
    sp14 = D_800A63F0.unk4;
    sp18 = D_800A63F0.unk8;
    sp1C = D_800A63F0.unkC;
    sp20 = D_800A63F0.unk10;
    sp24 = D_800A63F0.unk14;
    sp28 = D_800A63F0.unk18;
    sp2C = D_800A63F0.unk1C;
    func_8005386C(&sp30, &D_800A63F0);
    temp_v0 = arg1->unk0;
    temp_v0_2 = arg1->unk4;
    temp_v0_3 = arg1->unk8;
    temp_v0_4 = func_80047D3C((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2) + (temp_v0_3 * temp_v0_3));
    if (temp_v0_4 == 0) {
        return -1;
    }
    switch (arg0) {                                 /* irregular */
    case 0:
        sp10 = (s16) ((s32) (arg1->unk0 * -0x1000) / temp_v0_4);
        unksp12 = (s16) ((s32) (arg1->unk4 * -0x1000) / temp_v0_4);
        sp30 = (temp_s2 << 0xC) / 255;
        sp36 = (temp_s3 << 0xC) / 255;
        sp3C = (temp_s4 << 0xC) / 255;
        sp14 = (s16) ((s32) (arg1->unk8 * -0x1000) / temp_v0_4);
        break;
    case 1:
        unksp16 = (s16) ((s32) (arg1->unk0 * -0x1000) / temp_v0_4);
        sp18 = (s16) ((s32) (arg1->unk4 * -0x1000) / temp_v0_4);
        sp32 = (temp_s2 << 0xC) / 255;
        sp38 = (temp_s3 << 0xC) / 255;
        sp3E = (temp_s4 << 0xC) / 255;
        unksp1A = (s16) ((s32) (arg1->unk8 * -0x1000) / temp_v0_4);
        break;
    case 2:
        sp1C = (s16) ((s32) (arg1->unk0 * -0x1000) / temp_v0_4);
        unksp1E = (s16) ((s32) (arg1->unk4 * -0x1000) / temp_v0_4);
        sp34 = (temp_s2 << 0xC) / 255;
        sp3A = (temp_s3 << 0xC) / 255;
        sp40 = (temp_s4 << 0xC) / 255;
        sp20 = (s16) ((s32) (arg1->unk8 * -0x1000) / temp_v0_4);
        break;
    }
    D_800A63F0.unk0 = (s32) sp10;
    D_800A63F0.unk4 = (s32) sp14;
    D_800A63F0.unk8 = (s32) sp18;
    D_800A63F0.unkC = (s32) sp1C;
    D_800A63F0.unk10 = (s32) sp20;
    D_800A63F0.unk14 = sp24;
    D_800A63F0.unk18 = sp28;
    D_800A63F0.unk1C = sp2C;
    func_80053804(&sp30, &D_800A63F0);
    return 0;
}
