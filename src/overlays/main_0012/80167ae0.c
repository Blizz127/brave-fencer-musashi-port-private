/* Overlay range [80167AE0,80167DBC) from MAIN.CD member 0012.
 * SHA256(span)=e51ddc50b71c98c2ba332db52f921b2dc30035d07bd14632147d05190f8e16b5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);            /* extern */
extern s32 D_80181468;
extern s32 D_8018147C;
void func_80168070(void *);                   /* static */
extern u16 D_800B99DA;

void func_80167AE0(void) {
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
    u8 sp52;
    u8 sp51;
    u8 sp50;
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
    s32 sp10;
    s32 (*var_s0)();
    s32 (*var_s0_2)();
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_v0_2;
    u32 temp_v0;
    u8 var_v0;
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
    void *var_s0_3;

    func_80168070(&sp10);
    sp4C = 0;
    sp44 = 0;
    sp34 = 0;
    sp3C = 0;
    sp3A = 0;
    sp38 = 0;
    if (D_800B99DA & 1) {
        var_v0 = 0xA0;
    } else {
        var_v0 = 0xC0;
        if (!(D_800B99DA & 2)) {
            var_v0 = 0x80;
        }
    }
    sp54 = var_v0;
    var_s0 = D_80181468;
    var_s1 = 0;
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
    temp_v0 = var_v0 >> 2;
    sp56 = (s8) temp_v0;
    sp55 = (u8) temp_v0;
    do {
        temp_s0 = var_s0 + 1;
        sp30 = (s16) (s8) M2C_FIELD(var_s0, u8 *, 0);
        temp_s0_2 = temp_s0 + 1;
        sp32 = (s16) (s8) M2C_FIELD(var_s0, u8 *, 1);
        temp_s0_3 = temp_s0_2 + 1;
        sp40 = (s16) (s8) M2C_FIELD(temp_s0, u8 *, 1);
        temp_s0_4 = temp_s0_3 + 1;
        sp42 = (s16) (s8) M2C_FIELD(temp_s0_2, u8 *, 1);
        sp48 = (s16) (s8) M2C_FIELD(temp_s0_3, u8 *, 1);
        var_s0 = (temp_s0_4 + 1) - 1;
        sp4A = (s16) (s8) M2C_FIELD(temp_s0_4, u8 *, 1);
        func_80017758(&sp30, &sp10);
        temp_v0_2 = var_s1 + 1;
        var_s1 = temp_v0_2;
    } while (temp_v0_2 < 4);
    var_s0_2 = D_8018147C;
    var_s1_2 = 0;
    sp4A = 0;
    sp42 = 0;
    sp32 = 0;
    sp3A = 0;
    sp38 = 0;
    sp3C = -0x20;
    do {
        temp_s0_5 = var_s0_2 + 1;
        sp30 = (s16) (s8) M2C_FIELD(var_s0_2, u8 *, 0);
        temp_s0_6 = temp_s0_5 + 1;
        sp34 = (s16) (s8) M2C_FIELD(var_s0_2, u8 *, 1);
        temp_s0_7 = temp_s0_6 + 1;
        sp40 = (s16) (s8) M2C_FIELD(temp_s0_5, u8 *, 1);
        temp_s0_8 = temp_s0_7 + 1;
        sp44 = (s16) (s8) M2C_FIELD(temp_s0_6, u8 *, 1);
        sp48 = (s16) (s8) M2C_FIELD(temp_s0_7, u8 *, 1);
        var_s0_2 = (temp_s0_8 + 1) - 1;
        sp4C = (s16) (s8) M2C_FIELD(temp_s0_8, u8 *, 1);
        func_80017758(&sp30, &sp10);
        var_v0_2 = var_s1_2 + 1;
        if (var_s1_2 == 1) {
            sp3C = 0x20;
            var_s0_2 += 2;
            var_v0_2 = var_s1_2 + 1;
        }
        var_s1_2 = var_v0_2;
    } while (var_v0_2 < 4);
    var_s0_3 = var_s0_2 + 2;
    var_s1_3 = 0;
    sp30 = 0;
    sp34 = -0x20;
    sp50 = sp54;
    sp52 = sp55;
    sp51 = sp55;
    do {
        temp_s0_9 = var_s0_3 + 1;
        sp40 = (s16) (s8) M2C_FIELD(var_s0_3, u8 *, 0);
        temp_s0_10 = temp_s0_9 + 1;
        sp44 = (s16) (s8) M2C_FIELD(var_s0_3, u8 *, 1);
        sp48 = (s16) (s8) M2C_FIELD(temp_s0_9, u8 *, 1);
        var_s0_3 = temp_s0_10 + 1 + 1;
        sp4C = (s16) (s8) M2C_FIELD(temp_s0_10, u8 *, 1);
        func_80017758(&sp30, &sp10);
        temp_v0_3 = var_s1_3 + 1;
        var_s1_3 = temp_v0_3;
    } while (temp_v0_3 < 2);
}
