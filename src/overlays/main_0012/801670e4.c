/* Overlay range [801670E4,80167540) from MAIN.CD member 0012.
 * SHA256(span)=68bb0b741ba19d6a73907fa229ec0faeb22c5eb1356f84ab40c9787039c2356e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);                        /* extern */
void func_80017DC4(u16 *, void *);                        /* extern */
void func_80017E68(u16 *, void *, u16);                   /* extern */
void func_80048EAC(void *, void *);                          /* extern */
void func_80049A1C(u16 *, void *);                        /* extern */
void func_800D20C0(u16 *, u16 *, s32);                   /* extern */
void func_800D23D0(u16 *);                             /* extern */
extern s32 D_80181270;
extern s32 D_80181284;
extern s32 D_80181298;
void func_80149350(s32, u16 *, u16 *);                 /* static */
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;
extern u16 D_80126CE0;

void func_801670E4(void *arg0, u16 arg1, u16 arg2, u16 arg3) {
    s32 sp88;
    s32 sp68;
    s32 sp60;
    s8 sp5E;
    s8 sp5D;
    s8 sp5C;
    s8 sp5A;
    s8 sp59;
    s8 sp58;
    s8 sp56;
    u8 sp55;
    u8 sp54;
    s8 sp52;
    s8 sp51;
    s8 sp50;
    s16 sp4C;
    s16 sp4A;
    s16 sp48;
    s16 sp44;
    s16 sp42;
    s16 sp40;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 (*var_s2)();
    s32 (*var_s2_2)();
    s32 (*var_s2_3)();
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 var_s4;
    s16 var_s4_2;
    s16 var_s4_3;
    s32 temp_v1_2;
    u16 temp_a2;
    u16 temp_v0_3;
    u8 temp_v1;
    void *temp_s2;
    void *temp_s2_10;
    void *temp_s2_11;
    void *temp_s2_12;
    void *temp_s2_2;
    void *temp_s2_3;
    void *temp_s2_4;
    void *temp_s2_5;
    void *temp_s2_6;
    void *temp_s2_7;
    void *temp_s2_8;
    void *temp_s2_9;

    sp3C = 0;
    sp3A = 0;
    sp38 = 0;
    sp4C = 0;
    sp44 = 0;
    sp34 = 0;
    sp56 = 0x70;
    temp_v1 = arg0->unk12;
    sp10 = arg1;
    sp12 = arg2;
    var_s2 = D_80181284;
    var_s4 = 0;
    sp52 = 0;
    sp51 = 0;
    sp50 = 0;
    sp5A = 0;
    sp59 = 0;
    sp58 = 0;
    sp5E = 0;
    sp5D = 0;
    sp5C = 0;
    sp60 = 0x50000000;
    sp14 = arg3;
    sp55 = temp_v1;
    sp54 = temp_v1;
    func_80149350(arg0->unk34, &sp10, &sp10);
    arg0->unk6 = sp10;
    arg0->unk4C = (s32) (s16) sp10;
    arg0->unkA = sp12;
    arg0->unk50 = (s32) (s16) sp12;
    arg0->unkE = sp14;
    arg0->unk54 = (s32) (s16) sp14;
    func_800D20C0(&sp10, &sp18, 7);
    func_80017E68(&sp10, &sp68);
    func_800D23D0(&sp18);
    func_80049A1C(&sp18, &sp68);
    do {
        temp_s2 = var_s2 + 1;
        sp30 = (s16) (s8) var_s2->unk0;
        temp_s2_2 = temp_s2 + 1;
        sp32 = (s16) (s8) var_s2->unk1;
        temp_s2_3 = temp_s2_2 + 1;
        sp40 = (s16) (s8) temp_s2->unk1;
        temp_s2_4 = temp_s2_3 + 1;
        sp42 = (s16) (s8) temp_s2_2->unk1;
        sp48 = (s16) (s8) temp_s2_3->unk1;
        var_s2 = (temp_s2_4 + 1) - 1;
        sp4A = (s16) (s8) temp_s2_4->unk1;
        func_80017758(&sp30, &sp68);
        temp_v0 = var_s4 + 1;
        var_s4 = temp_v0;
    } while (temp_v0 < 4);
    var_s2_2 = D_80181270;
    sp55 = 0xA0;
    sp56 = 0x10;
    sp54 = 0x10;
    var_s4_2 = 0;
    sp4A = 0;
    sp42 = 0;
    sp32 = 0;
    sp20 = D_801269A4 - (s16) sp10;
    sp28 = D_801269AC - (s16) sp14;
    sp24 = D_801269A8 - (s16) sp12;
    do {
        temp_s2_5 = var_s2_2 + 1;
        sp30 = (s16) (s8) var_s2_2->unk0;
        temp_s2_6 = temp_s2_5 + 1;
        sp34 = (s16) (s8) var_s2_2->unk1;
        temp_s2_7 = temp_s2_6 + 1;
        sp40 = (s16) (s8) temp_s2_5->unk1;
        temp_s2_8 = temp_s2_7 + 1;
        sp44 = (s16) (s8) temp_s2_6->unk1;
        sp48 = (s16) (s8) temp_s2_7->unk1;
        var_s2_2 = (temp_s2_8 + 1) - 1;
        sp4C = (s16) (s8) temp_s2_8->unk1;
        func_80017758(&sp30, arg0 + 0x38);
        temp_v0_2 = var_s4_2 + 1;
        var_s4_2 = temp_v0_2;
    } while (temp_v0_2 < 4);
    if (arg0->unk30 > 0) {
        var_s2_3 = D_80181298;
        var_s4_3 = 0;
        temp_v1_2 = (s32) (sp18 << 0x10) >> 0x16;
        sp10 += temp_v1_2;
        temp_a2 = sp14 + temp_v1_2;
        sp14 = temp_a2;
        sp12 += temp_v1_2;
        func_80017E68(&sp10, &sp68, temp_a2);
        temp_v0_3 = ((u32) arg0->unk30 >> 1) + (D_80126CE0 << 5);
        sp14 = temp_v0_3;
        sp12 = temp_v0_3;
        sp10 = temp_v0_3;
        func_80017DC4(&sp10, &sp88);
        func_80048EAC(&sp88, &sp68);
        sp4C = 0;
        sp44 = 0;
        sp34 = 0;
        sp56 = 0x20;
        sp54 = 0x20;
        sp5E = 0;
        sp5C = 0;
        sp5A = 0;
        sp58 = 0;
        sp52 = 0;
        sp50 = 0;
        sp5D = 0;
        sp59 = 0;
        sp51 = 0;
        sp55 = arg0->unk12 + 0x60;
        do {
            temp_s2_9 = var_s2_3 + 1;
            sp30 = (s16) (s8) var_s2_3->unk0;
            temp_s2_10 = temp_s2_9 + 1;
            sp32 = (s16) (s8) var_s2_3->unk1;
            temp_s2_11 = temp_s2_10 + 1;
            sp40 = (s16) (s8) temp_s2_9->unk1;
            temp_s2_12 = temp_s2_11 + 1;
            sp42 = (s16) (s8) temp_s2_10->unk1;
            sp48 = (s16) (s8) temp_s2_11->unk1;
            var_s2_3 = (temp_s2_12 + 1) - 1;
            sp4A = (s16) (s8) temp_s2_12->unk1;
            func_80017758(&sp30, &sp68);
            temp_v0_4 = var_s4_3 + 1;
            var_s4_3 = temp_v0_4;
        } while (temp_v0_4 < 8);
    }
}
