/* Overlay range [80153E00,8015410C) from MAIN.CD member 0012.
 * SHA256(span)=2c1403c959c92a893c8f3b52919fab99bb4192676241baf8a7d84f25c1518446.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146994(s32, void *, s32, s32);                   /* static */
void func_80146A6C(s32, void *, s32, s32, s32, s32, s32);    /* static */
s32 func_80148800(void *);                          /* static */
s32 func_8014891C(void *);                          /* static */
s32 func_80148980(void *);                          /* static */
s32 func_801489E8(void *);                          /* static */
s32 func_80148A48(void *);                          /* static */
void func_80149020();                                  /* static */
void func_8014ACE8(void *, s32, s16);                    /* static */
void func_8014B310(void *);                            /* static */
void func_8014BC44(void *, s16);                       /* static */
void func_80153C18(void *);                            /* static */
void func_8015410C(void *);                            /* static */
void func_80159B3C(void *);                            /* static */
void func_80165718(void *);                            /* static */
extern s32 D_80078E78;
extern s16 D_800B9A08;
extern u16 D_8011DB0C;
extern s16 D_8011DB1A;
extern u16 D_8011F748;
extern s32 D_80127518;

void func_80153E00(void *arg0) {
    s32 temp_s2;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_s1_2;
    u32 temp_s1;
    u32 var_v0;
    u8 temp_v0;
    u8 temp_v1;

    func_80149020();
    temp_v1 = arg0->unkA9;
    if (temp_v1 != 0x53) {
        if ((s32) temp_v1 < 0x54) {
            var_v0 = saved_reg_s1 & 0xFFFF;
            if (temp_v1 != 0x41) {

            } else {
                var_s1 = func_80148800(arg0) & 0xF000;
                goto block_13;
            }
        } else {
            var_v0 = saved_reg_s1 & 0xFFFF;
            if (temp_v1 != 0x73) {

            } else {
                goto block_7;
            }
        }
    } else {
block_7:
        temp_s2 = (func_8014891C(arg0) != 0) << 0xC;
        var_s1_2 = temp_s2;
        if (func_80148980(arg0) != 0) {
            var_s1_2 = temp_s2 | 0x4000;
        }
        if (func_801489E8(arg0) != 0) {
            var_s1_2 |= 0x8000;
        }
        var_v0 = var_s1_2 & 0xFFFF;
        if (func_80148A48(arg0) != 0) {
            var_s1 = var_s1_2 | 0x2000;
block_13:
            var_v0 = var_s1 & 0xFFFF;
        }
    }
    temp_s1 = var_v0 >> 0xC;
    temp_v1_2 = temp_s1 & 0xFFFF;
    if ((temp_v1_2 != 0) && !(temp_v1_2 & arg0->unkDF)) {
        temp_v0 = arg0->unkDE - 1;
        arg0->unkDE = temp_v0;
        if (!(temp_v0 & 0xFF)) {
            func_80153C18(arg0);
        }
    }
    arg0->unkDF = (u8) temp_s1;
    if (D_80127518 == 0) {
        if (D_800B9A08 != 0x3075) {
            arg0->unk88 = (u16) arg0->unk244;
            arg0->unk8A = (u16) arg0->unk246;
            arg0->unk8C = (u16) arg0->unk248;
        }
        func_8015410C(arg0);
        func_80159B3C(arg0);
        func_80165718(arg0);
        return;
    }
    if (D_8011DB0C != 1) {
        if ((s32) D_8011DB0C >= 2) {
            if (D_8011DB0C != 2) {
                if (D_8011DB0C == 3) {
                    func_8014B310(arg0);
                    goto block_27;
                }
            } else {
                func_8014BC44(arg0, D_8011DB1A);
                func_8014ACE8(arg0, 1, D_8011DB1A);
                func_8014B310(arg0);
                func_80146994(0x42, arg0, 0, 0);
                func_80146A6C(0x42, arg0, 0x20, 0, 0, 1, 0);
                func_80146A6C(0x42, arg0, 0, 0, 0x20, 1, 0);
                func_80146A6C(0x42, arg0, -0x20, 0, 0, 1, 0);
                func_80146A6C(0x42, arg0, 0, 0, -0x20, 1, 0);
                goto block_29;
            }
        }
    } else {
block_27:
        func_8014BC44(arg0, D_8011DB1A);
        func_8014ACE8(arg0, 1, D_8011DB1A);
block_29:
        D_8011DB0C = 0;
        D_8011F748 = 0;
    }
    if (D_8011F748 != 0) {
        func_8015410C(arg0);
        func_80159B3C(arg0);
        func_8014BC44(arg0, (s16) D_80078E78.unk3C);
        D_8011DB0C = 0;
        D_8011F748 = 0;
    }
}
