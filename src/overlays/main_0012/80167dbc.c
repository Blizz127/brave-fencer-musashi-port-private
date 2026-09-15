/* Overlay range [80167DBC,80168070) from MAIN.CD member 0012.
 * SHA256(span)=0d486fe6da9de5693a57713cc791fbe6ca038cc244a7095002e0ebc9db8674c7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);            /* extern */
s32 func_80029178();                         /* extern */
extern s32 D_801812BC;
extern s32 D_801812D0;
void func_80168070(void *);                   /* static */
extern u16 D_800B99DA;

void func_80167DBC(void) {
    s32 sp60;
    u8 sp5E;
    u8 sp5D;
    u8 sp5C;
    s8 sp5A;
    s8 sp59;
    s8 sp58;
    u8 sp56;
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
    u32 temp_v0;
    u8 temp_v1;
    u8 var_v0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_s0_8;

    func_80168070(&sp10);
    sp4C = 0;
    sp44 = 0;
    sp34 = 0;
    sp3C = 0;
    sp3A = 0;
    sp38 = 0;
    if (D_800B99DA & 1) {
        var_v0 = 0x58;
    } else {
        var_v0 = 0x48;
    }
    sp56 = var_v0;
    temp_v0 = var_v0 >> 2;
    sp55 = (u8) temp_v0;
    sp54 = (u8) temp_v0;
    if (func_80029178(0x81) & 0xFF) {
        sp55 *= 4;
        sp56 = (u8) (sp56 >> 1);
    }
    var_s0 = D_801812BC;
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
    var_s0_2 = D_801812D0;
    sp3C = -0x12;
    var_s1_2 = 0;
    sp4A = 0;
    sp42 = 0;
    sp32 = 0;
    sp3A = 0;
    sp38 = 0;
    temp_v1 = sp55 * 2;
    sp56 *= 2;
    sp55 = temp_v1;
    sp54 = temp_v1;
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
        sp4C = (s16) (s8) M2C_FIELD(temp_s0_8, u8 *, 1);
        var_s0_2 = (temp_s0_8 + 1) - 1;
        if (var_s1_2 == 2) {
            sp5E = sp56;
            sp5D = sp54;
            sp5C = sp54;
        } else if (var_s1_2 == 3) {
            sp5E = 0;
            sp5D = 0;
            sp5C = 0;
            sp52 = sp56;
            sp51 = sp54;
            sp50 = sp54;
        }
        func_80017758(&sp30, &sp10);
        temp_v0_3 = var_s1_2 + 1;
        var_s1_2 = temp_v0_3;
    } while (temp_v0_3 < 4);
}
