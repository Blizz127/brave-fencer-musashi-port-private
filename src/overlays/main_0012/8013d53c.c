/* Overlay range [8013D53C,8013D8FC) from MAIN.CD member 0012.
 * SHA256(span)=cef3d4e62ca66287aba0150c94b3e7fb9a57c786b1f150f0e5428a754d65fb3b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017ECB8;
extern s32 D_8017ECE8;
extern s32 D_8017ECEC;
extern s32 D_8017ECF0;
extern s32 D_801841A0;
extern s32 D_801841A8;
extern s32 D_801841AC;
extern s32 D_801841B0;
extern s32 D_801841B8;
extern s32 D_801841BC;
extern s32 D_801841C0;
extern s32 D_801841C4;
extern s32 D_801841C8;
extern s32 D_801841CC;
extern s32 D_801841D0;
extern s32 D_801841D8;
extern s32 D_801841DC;
extern s32 D_801841E0;
extern s32 D_801841E4;
extern s32 D_80185B10;
extern s32 D_80185B31;
extern s32 D_80185B32;
extern s32 D_80185BEC;
extern s32 D_80185BF0;
extern s32 D_80185C0A;
extern s32 D_80185C7E;
extern u8 D_80078EAF;
extern s32 D_80185B28;
extern s32 D_80185BC8;

void func_8013D53C(u16 *arg0) {
    s16 *var_t3;
    s16 var_a1;
    s32 temp_lo;
    s32 temp_v0;
    s32 var_s0;
    s32 var_t2;
    s32 var_t8;
    s32 var_t9;
    s32 var_v1;
    u16 *var_t1;
    u16 *var_t7;
    u16 temp_a0;
    u16 temp_a3;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 var_v0;
    void *temp_v0_3;
    void *temp_v1_3;
    void *var_t5;

    var_t7 = arg0;
    if (!(D_801841D0 & 1)) {
        var_v0 = 1;
    } else {
        var_v0 = D_80078EAF;
    }
    D_801841B8 = (s32) var_v0;
    temp_v0 = D_801841B8 * 0xC;
    temp_v1 = *(D_8017ECE8 + temp_v0);
    D_80185C0A = temp_v1;
    D_80185C7E = temp_v1;
    temp_v1_2 = *(D_8017ECEC + temp_v0);
    D_80185B32 = temp_v1_2;
    D_80185BEC = temp_v1_2;
    temp_v0_2 = *(D_8017ECF0 + temp_v0);
    D_80185B10 = temp_v0_2;
    D_80185B31 = temp_v0_2;
    D_80185B28.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185B28.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185B28.unk8 = (s8) *(D_8017ECB8 + (D_801841B8 * 9));
    D_80185BC8.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185BC8.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185BC8.unk8 = (s8) D_80185B28.unk8;
    D_80185BF0 = 1;
    D_801841CC = -1;
    D_801841C8 = 0;
    D_801841C4 = -1;
    D_801841B0 = 0;
    D_801841BC = 0;
    D_801841C0 = 0;
    if ((D_801841D0 & 2) && (D_801841B8 == 4)) {
        var_s0 = D_801841A0->unk48;
        var_t9 = D_801841A0->unk4C;
        var_t8 = D_801841A0->unk50;
    } else {
        temp_v1_3 = (D_801841B8 * 0xC) + D_801841A0;
        var_s0 = temp_v1_3->unk0;
        var_t9 = temp_v1_3->unk4;
        var_t8 = temp_v1_3->unk8;
    }
    D_801841AC = var_t7;
    if (var_t7 != 0) {
        if (D_801841D8 != 0) {
            temp_v0_3 = (D_801841B8 * 0xC) + D_801841A8;
            D_801841DC = (s32) temp_v0_3->unk0;
            D_801841E0 = (s32) temp_v0_3->unk4;
            D_801841E4 = (s32) temp_v0_3->unk8;
            return;
        }
        temp_a0 = *var_t7;
        if ((temp_a0 & 0xFFFF) != 0xFF) {
            var_t5 = var_t7 + 0xC;
            var_v1 = temp_a0 & 0xFFFF;
            do {
                if (var_v1 == 9) {
                    temp_lo = var_t5->unk-4 * var_t5->unk-2;
                    var_t2 = 0;
                    var_t1 = var_t5->unk0;
                    var_t3 = var_t1 + (temp_lo * 2);
                    if (temp_lo > 0) {
                        do {
                            temp_a3 = *var_t1;
                            var_a1 = (((temp_a3 & 0x1F) * var_s0) / 2560) | ((((temp_a3 & 0x3E0) * var_t9) / 2560) & 0x3E0) | ((((temp_a3 & 0x7C00) * var_t8) / 2560) & 0x7C00) | (temp_a3 & 0x8000);
                            if ((var_a1 == 0) && (temp_a3 != 0)) {
                                var_a1 = 0x8000;
                            }
                            *var_t3 = var_a1;
                            var_t3 += 2;
                            var_t2 += 1;
                            var_t1 += 2;
                        } while (var_t2 < temp_lo);
                    }
                }
                var_t7 += 0x10;
                var_v1 = *var_t7 & 0xFFFF;
                var_t5 += 0x10;
            } while (var_v1 != 0xFF);
        }
    }
}
