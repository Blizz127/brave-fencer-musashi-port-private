/* Native retail instruction export [8003B45C,8003B954).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0F4;
extern s32 D_8006B0FC;
extern s32 D_8006B102;
extern s32 D_8006B104;
extern s32 D_8006B108;
extern s32 D_8006B54C;
extern s32 D_8006B5B4;
extern s32 D_8006B604;
void func_8003AF04(s32, s32, s32);                         /* static */
s32 func_8003B3D0(s32);                             /* static */
void func_8003B954(s32 *, s32 *, s32, s32);            /* static */
void func_8003C0A0(u32);                               /* static */
extern u16 D_8006B100;

s32 func_8003B45C(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 sp58;
    s16 sp4A;
    s16 sp48;
    s16 sp34;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp22;
    s32 sp10;
    s32 *var_a1_2;
    s32 *var_a2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a3;
    s32 var_fp;
    s32 var_s4;
    s32 var_s6;
    s32 var_s7;
    s32 var_v0;
    u32 var_s0;
    u8 *var_v1;
    u8 *var_v1_2;
    u8 *var_v1_3;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_4;

    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    var_s7 = 0;
    var_s4 = 0;
    var_s6 = 0;
    sp58 = 0;
    temp_s3 = arg0->unk0;
    var_fp = 0;
    temp_s5 = temp_s3 == 0;
    sp10 = 0;
    if ((temp_s5 != 0) || (temp_s3 & 1)) {
        var_s0 = arg0->unk4;
        if (var_s0 & 0x100) {
            var_s0 &= ~0x100;
            sp58 = 1;
        }
        if ((var_s0 >= 0xAU) || (var_s4 = 1, (func_8003B3D0(*(D_8006B5B4 + (var_s0 * 4))) != 0))) {
            return -1;
        }
        var_a2 = &sp10;
        var_a1 = 0x43;
        D_8006B0FC = var_s0;
        var_a3 = -1;
        var_v1 = (D_8006B0FC * 0x44) + D_8006B604;
        D_8006B0F4 = (s32) *((D_8006B0FC * 4) + D_8006B5B4);
        do {
            temp_v0 = *var_v1;
            var_v1 += 1;
            var_a1 -= 1;
            *var_a2 = temp_v0;
            var_a2 += 1;
        } while (var_a1 != -1);
        switch (D_8006B0FC) {                       /* irregular */
        case 7:
            D_8006B108 = 0x7F;
            D_8006B104 = 0x7F;
            break;
        case 8:
            D_8006B108 = 0;
            D_8006B104 = 0x7F;
            break;
        default:
            D_8006B108 = 0;
            D_8006B104 = 0;
            break;
        }
        goto block_15;
    }
block_15:
    if (((temp_s5 != 0) || (temp_s3 & 8)) && ((s32) D_8006B0FC < 9) && ((s32) D_8006B0FC >= 7)) {
        var_s6 = 1;
        if (var_s4 == 0) {
            var_a1_2 = &sp10;
            var_a0 = 0x43;
            var_v1_2 = (D_8006B0FC * 0x44) + D_8006B604;
            do {
                temp_v0_2 = *var_v1_2;
                var_v1_2 += 1;
                var_a0 -= 1;
                *var_a1_2 = temp_v0_2;
                var_a1_2 += 1;
            } while (var_a0 != -1);
            sp10 = 0x0C011C00;
        }
        temp_v0_3 = arg0->unkC;
        var_a3 = MULT_HI((temp_v0_3 << 0xD), 0x81020409);
        temp_a1 = temp_v0_3 << 0xC;
        D_8006B104 = temp_v0_3;
        sp28 = ((temp_v0_3 << 0xD) / 127) - sp14;
        var_a2 = (s32 *) MULT_HI(temp_a1, 0x81020409);
        var_a1 = temp_a1 >> 0x1F;
        temp_a0 = ((s32) (var_a2 + temp_a1) >> 6) - var_a1;
        sp2A = temp_a0 - sp16;
        sp34 = sp36 + temp_a0;
        sp2C = sp2E + temp_a0;
        sp4A = sp4E + temp_a0;
        sp48 = sp4C + temp_a0;
    }
    if (((temp_s5 != 0) || (temp_s3 & 0x10)) && ((s32) D_8006B0FC < 9) && ((s32) D_8006B0FC >= 7)) {
        var_fp = 1;
        if (var_s4 == 0) {
            var_a1 = (s32) &sp10;
            if (var_s6 == 0) {
                var_a0_2 = 0x43;
                var_a2 = (s32 *)-1;
                var_v1_3 = (D_8006B0FC * 0x44) + D_8006B604;
                do {
                    temp_v0_4 = *var_v1_3;
                    var_v1_3 += 1;
                    var_a0_2 -= 1;
                    *var_a1 = temp_v0_4;
                    var_a1 += 1;
                } while (var_a0_2 != -1);
                var_v0 = 0x80;
            } else {
                var_v0 = sp10 | 0x80;
            }
            sp10 = var_v0;
        }
        temp_v1 = arg0->unk10;
        D_8006B108 = temp_v1;
        sp22 = (temp_v1 * 0x8100) / 127;
    }
    if (var_s4 != 0) {
        var_s7 = ((u16) D_8006B54C->unk1AA >> 7) & 1;
        if (var_s7 != 0) {
            D_8006B54C->unk1AA = (u16) (D_8006B54C->unk1AA & 0xFF7F);
        }
        D_8006B54C->unk184 = 0U;
        D_8006B54C->unk186 = 0U;
        D_8006B100 = 0;
        D_8006B102 = 0U;
    } else {
        if ((temp_s5 != 0) || (temp_s3 & 2)) {
            D_8006B54C->unk184 = (u16) arg0->unk8;
            D_8006B100 = arg0->unk8;
        }
        if ((temp_s5 != 0) || (temp_s3 & 4)) {
            D_8006B54C->unk186 = (u16) arg0->unkA;
            D_8006B102 = (u16) arg0->unkA;
        }
    }
    if ((var_s4 != 0) || (var_s6 != 0) || (var_fp != 0)) {
        func_8003B954(&sp10, (s32 *) var_a1, (s32) var_a2, var_a3);
    }
    if (sp58 != 0) {
        func_8003C0A0(D_8006B0FC);
    }
    if (var_s4 != 0) {
        func_8003AF04(0xD1, D_8006B0F4, 0);
        if (var_s7 != 0) {
            D_8006B54C->unk1AA = (u16) (D_8006B54C->unk1AA | 0x80);
        }
    }
    return 0;
}
