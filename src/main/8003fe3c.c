/* Native retail instruction export [8003FE3C,8004014C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8FC;
void func_8003FA64();                            /* static */
void func_8004014C(s32, void *);          /* static */
void func_800401A0();                     /* static */
void func_80040868(s32, void *);             /* static */
extern s32 *D_800762D0;
extern s16 D_80078D8C;
extern s16 D_80078D8E;
extern s16 D_80078D90;
extern s16 D_80078D92;
extern s32 *D_80079588;
extern s32 *D_8007958A;
extern s32 *D_8007958C;
extern s32 *D_8007958E;
extern s32 *D_80079590;
extern s32 *D_80079592;
extern s32 *D_80079596;
extern s32 *D_80079598;
extern s32 *D_8007959A;
extern s32 *D_8007959C;
extern s32 *D_800795A3;
extern s32 *D_800795A4;
extern s32 *D_800795A6;
extern s32 *D_800795AA;
extern s32 *D_800795AC;
extern s32 *D_800795B0;
extern s32 *D_800795B2;
extern s32 *D_800795B4;
extern s32 *D_800795B6;
extern s32 *D_800795B8;
extern s32 D_800A2B80;
extern s32 D_800A2B84;
extern s16 D_800A2B88;
extern s16 D_800A2B8A;
extern s32 *D_800A4620;
extern s16 D_800A5F60;
extern s16 D_800A6434;
extern s16 D_800A6540;
extern u8 D_800AE614;
extern s16 D_800B9B3A;
extern s32 *D_800B9B40;
extern s32 *D_800B9B58;
extern s8 D_800BA100;
extern s16 D_800C7CD8;
extern s16 D_800C7F04;

void func_8003FE3C(s32 arg0) {
    s16 var_s0_4;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    u8 temp_a0;
    void *temp_a1;

    func_800401A0(0);
    D_800A5F60 = 0;
    func_8004014C(0x20, &D_800762D0);
    var_s0 = 0;
    var_v0 = 0 & 0xFFFF;
    do {
        *((var_v0 * 2) + &D_800B9B58) = 0;
        var_s0 += 1;
        var_v0 = var_s0 & 0xFFFF;
    } while ((u32) (var_s0 & 0xFFFF) < 0xC0U);
    var_s0_2 = 0;
    var_v0_2 = 0 & 0xFFFF;
    do {
        *(&D_800A4620 + var_v0_2) = 0;
        var_s0_2 += 1;
        var_v0_2 = var_s0_2 & 0xFFFF;
    } while ((u32) (var_s0_2 & 0xFFFF) < 0x18U);
    D_800C7CD8 = 0;
    var_s0_3 = 0;
    var_v0_3 = 0 & 0xFFFF;
    do {
        *(&D_800B9B40 + var_v0_3) = 0;
        var_s0_3 += 1;
        var_v0_3 = var_s0_3 & 0xFFFF;
    } while ((u32) (var_s0_3 & 0xFFFF) < 0x10U);
    temp_a0 = arg0 & 0xFF;
    if (temp_a0 >= 0x18U) {
        D_800AE614 = 0x18;
    } else {
        D_800AE614 = temp_a0;
    }
    var_s0_4 = 0;
    if (D_800AE614 != 0) {
        var_v1 = 0 & 0xFFFF;
        do {
            temp_v0 = var_v1 * 0x34;
            *(&D_8007958A + temp_v0) = 0x18;
            *(&D_80079596 + temp_v0) = -1;
            *(&D_80079588 + temp_v0) = 0xFF;
            *(&D_800795A3 + temp_v0) = 0;
            *(&D_8007958C + temp_v0) = 0;
            *(&D_8007958E + temp_v0) = 0;
            *(&D_80079598 + temp_v0) = 0;
            *(&D_8007959A + temp_v0) = 0;
            *(&D_8007959C + temp_v0) = 0xFF;
            *(&D_80079590 + temp_v0) = 0;
            *(&D_80079592 + temp_v0) = 0x40;
            *(&D_800795A4 + temp_v0) = 0;
            *(&D_800795A6 + temp_v0) = 0;
            M2C_FIELD((temp_v0 + 0x80080000), s16 *, -0x6A58) = 0;
            *(&D_800795AA + temp_v0) = 0;
            *(&D_800795B0 + temp_v0) = 0;
            *(&D_800795B2 + temp_v0) = 0;
            *(&D_800795B4 + temp_v0) = 0;
            *(&D_800795B6 + temp_v0) = 0;
            *(&D_800795B8 + temp_v0) = 0;
            *(&D_800795AC + temp_v0) = 0;
            temp_a1 = (((var_v1 * 8) & 0xFFFF) * 2) + D_8006B8FC;
            M2C_FIELD(temp_a1, s16 *, 6) = 0x200;
            M2C_FIELD(temp_a1, s16 *, 4) = 0x1000;
            M2C_FIELD(temp_a1, s16 *, 8) = 0x80FF;
            M2C_FIELD(temp_a1, s16 *, 0) = 0;
            M2C_FIELD(temp_a1, s16 *, 2) = 0;
            M2C_FIELD(temp_a1, s16 *, 0xA) = 0x4000;
            D_800B9B3A = var_s0_4;
            func_80040868(1, temp_a1);
            var_s0_4 += 1;
            var_v1 = var_s0_4 & 0xFFFF;
        } while ((u32) (var_s0_4 & 0xFFFF) < (u8) D_800AE614);
    }
    D_800A2B88 = 0x3FFF;
    D_800A2B8A = 0x3FFF;
    D_80078D8C = 0;
    D_80078D8E = 0;
    D_800C7F04 = 0;
    D_80078D90 = 0;
    D_80078D92 = 0;
    D_800A2B80 = 0;
    D_800A2B84 = 0;
    D_800BA100 = 0;
    D_800A6434 = 0;
    D_800A6540 = 0x80;
    func_8003FA64();
}
