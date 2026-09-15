/* Overlay range [8016A290,8016A700) from MAIN.CD member 0012.
 * SHA256(span)=94921726a9e3376b070efab654c9da36bf3ce9fdb4056f6a5055b0e2d46a5d0a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);            /* extern */
void func_80017E68(u16 *, void *);            /* extern */
void func_80048FBC(s32, s16 *, s16 *);           /* extern */
void func_80049A1C(s16 *, void *);            /* extern */
s16 func_8004CFEC(s32, s32);                        /* extern */
void func_8004D504(void *, s32 *, s32 *, s16); /* extern */
void func_800D20C0(u16 *, s16 *, s32);       /* extern */
void func_800D23D0(s16 *);                       /* extern */
extern s32 D_80181468;
extern s32 D_8018147C;
void func_80149350(void *, u16 *, u16 *);        /* static */
extern u16 D_800B99DA;
extern s32 D_801269A4;
extern s32 D_801269A8;
extern s32 D_801269AC;

void func_8016A290(void *arg0, void *arg1, void *arg2) {
    s32 spA0;
    s8 sp9E;
    s8 sp9D;
    s8 sp9C;
    s8 sp9A;
    s8 sp99;
    s8 sp98;
    s8 sp96;
    u8 sp95;
    u8 sp94;
    u8 sp92;
    u8 sp91;
    u8 sp90;
    s16 sp8C;
    s16 sp8A;
    s16 sp88;
    s16 sp84;
    s16 sp82;
    s16 sp80;
    s16 sp7C;
    s16 sp7A;
    s16 sp78;
    s16 sp74;
    s16 sp72;
    s16 sp70;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 (*var_s0)();
    s32 (*var_s0_2)();
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_v0_2;
    u32 temp_v0;
    u32 var_v0;
    void *temp_s0;
    void *temp_s0_10;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s4;
    void *var_s0_3;

    temp_s4 = M2C_FIELD(arg0, void **, 0x34);
    sp10 = (u16) ((s32) (M2C_FIELD(arg1, s16 *, 0) + M2C_FIELD(arg2, s16 *, 0)) >> 1);
    sp12 = (u16) ((s32) (M2C_FIELD(arg1, s16 *, 2) + M2C_FIELD(arg2, s16 *, 2)) >> 1);
    sp14 = (u16) ((s32) (M2C_FIELD(arg1, s16 *, 4) + M2C_FIELD(arg2, s16 *, 4)) >> 1);
    func_80149350(temp_s4, &sp10, &sp10);
    M2C_FIELD(arg0, u16 *, 6) = sp10;
    M2C_FIELD(arg0, u16 *, 0xA) = sp12;
    M2C_FIELD(arg0, u16 *, 0xE) = sp14;
    func_800D20C0(&sp10, &sp18, 8);
    func_80017E68(&sp10, &sp30);
    sp18 = (u16) M2C_FIELD(arg2, s16 *, 0) - (u16) M2C_FIELD(arg1, s16 *, 0);
    sp1A = (u16) M2C_FIELD(arg2, s16 *, 2) - (u16) M2C_FIELD(arg1, s16 *, 2);
    sp1C = (u16) M2C_FIELD(arg2, s16 *, 4) - (u16) M2C_FIELD(arg1, s16 *, 4);
    func_80048FBC(M2C_FIELD(temp_s4, s32 *, 0x20) + 0x34, &sp18, &sp18);
    func_800D23D0(&sp18);
    func_80049A1C(&sp18, &sp30);
    sp20 = D_801269A4 - (s16) sp10;
    sp24 = D_801269A8 - (s16) sp12;
    sp28 = D_801269AC - (s16) sp14;
    func_8004D504(&sp30, &sp20, &sp20, (s16) sp12);
    sp1C = -func_8004CFEC(sp20, sp24);
    func_80049A1C(&sp18, &sp30);
    sp8C = 0;
    sp84 = 0;
    sp74 = 0;
    sp7C = 0;
    sp7A = 0;
    sp78 = 0;
    if (D_800B99DA & 1) {
        var_v0 = M2C_FIELD(arg0, u32 *, 0x30) + 0x20;
    } else if (D_800B99DA & 2) {
        var_v0 = M2C_FIELD(arg0, u32 *, 0x30) + 0x40;
    } else {
        var_v0 = M2C_FIELD(arg0, u32 *, 0x30);
    }
    sp94 = (u8) var_v0;
    var_s0 = D_80181468;
    var_s1 = 0;
    sp92 = 0;
    sp91 = 0;
    sp90 = 0;
    sp9A = 0;
    sp99 = 0;
    sp98 = 0;
    sp9E = 0;
    sp9D = 0;
    sp9C = 0;
    spA0 = 0x50000000;
    temp_v0 = var_v0 >> 3;
    sp96 = (s8) temp_v0;
    sp95 = (u8) temp_v0;
    do {
        temp_s0 = var_s0 + 1;
        sp70 = (s16) (s8) M2C_FIELD(var_s0, u8 *, 0);
        temp_s0_2 = temp_s0 + 1;
        sp72 = (s16) (s8) M2C_FIELD(var_s0, u8 *, 1);
        temp_s0_3 = temp_s0_2 + 1;
        sp80 = (s16) (s8) M2C_FIELD(temp_s0, u8 *, 1);
        temp_s0_4 = temp_s0_3 + 1;
        sp82 = (s16) (s8) M2C_FIELD(temp_s0_2, u8 *, 1);
        sp88 = (s16) (s8) M2C_FIELD(temp_s0_3, u8 *, 1);
        var_s0 = (temp_s0_4 + 1) - 1;
        sp8A = (s16) (s8) M2C_FIELD(temp_s0_4, u8 *, 1);
        func_80017758(&sp70, &sp30);
        temp_v0_2 = var_s1 + 1;
        var_s1 = temp_v0_2;
    } while (temp_v0_2 < 4);
    var_s0_2 = D_8018147C;
    var_s1_2 = 0;
    sp8A = 0;
    sp82 = 0;
    sp72 = 0;
    sp7A = 0;
    sp78 = 0;
    sp7C = -0x20;
    do {
        temp_s0_5 = var_s0_2 + 1;
        sp70 = (s16) (s8) M2C_FIELD(var_s0_2, u8 *, 0);
        temp_s0_6 = temp_s0_5 + 1;
        sp74 = (s16) (s8) M2C_FIELD(var_s0_2, u8 *, 1);
        temp_s0_7 = temp_s0_6 + 1;
        sp80 = (s16) (s8) M2C_FIELD(temp_s0_5, u8 *, 1);
        temp_s0_8 = temp_s0_7 + 1;
        sp84 = (s16) (s8) M2C_FIELD(temp_s0_6, u8 *, 1);
        sp88 = (s16) (s8) M2C_FIELD(temp_s0_7, u8 *, 1);
        var_s0_2 = (temp_s0_8 + 1) - 1;
        sp8C = (s16) (s8) M2C_FIELD(temp_s0_8, u8 *, 1);
        func_80017758(&sp70, &sp30);
        var_v0_2 = var_s1_2 + 1;
        if (var_s1_2 == 1) {
            sp7C = 0x20;
            var_s0_2 += 2;
            var_v0_2 = var_s1_2 + 1;
        }
        var_s1_2 = var_v0_2;
    } while (var_v0_2 < 4);
    var_s0_3 = var_s0_2 + 2;
    var_s1_3 = 0;
    sp70 = 0;
    sp74 = -0x20;
    sp90 = sp94;
    sp92 = sp95;
    sp91 = sp95;
    do {
        temp_s0_9 = var_s0_3 + 1;
        sp80 = (s16) (s8) M2C_FIELD(var_s0_3, u8 *, 0);
        temp_s0_10 = temp_s0_9 + 1;
        sp84 = (s16) (s8) M2C_FIELD(var_s0_3, u8 *, 1);
        sp88 = (s16) (s8) M2C_FIELD(temp_s0_9, u8 *, 1);
        var_s0_3 = temp_s0_10 + 1 + 1;
        sp8C = (s16) (s8) M2C_FIELD(temp_s0_10, u8 *, 1);
        func_80017758(&sp70, &sp30);
        temp_v0_3 = var_s1_3 + 1;
        var_s1_3 = temp_v0_3;
    } while (temp_v0_3 < 2);
}
