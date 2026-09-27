/* Native retail instruction export [8003FA64,8003FE18).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8FC;
void func_8003FE18(s32, s32);            /* static */
extern u16 D_80078D8C;
extern u16 D_80078D8E;
extern u16 D_80078D90;
extern u16 D_80078D92;
extern s32 *D_8007958E;
extern s32 *D_800795A3;
extern s32 *D_800795A4;
extern s32 *D_800795B0;
extern u8 D_800A4620;
extern u8 D_800AE614;
extern s32 (*D_800AE828)();
extern u16 D_800B9B58;
extern s32 *D_800B9B5C;
extern s32 *D_800B9B5E;
extern s32 (*D_800BA0D0)();
extern u8 D_800BA100;
extern s32 D_800BA1B0;
extern s32 *D_800C7EC0;
extern u16 D_800C7F04;
extern u16 D_800C7F06;

void func_8003FA64(void) {
    s32 *temp_v0_2;
    s32 *var_v1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    u16 *var_a2;
    u16 *var_a3;
    u16 *var_t0;
    u16 *var_t1;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_v0_3;
    u16 temp_v1;
    u8 *var_a1_2;
    void *temp_v0_4;
    void *temp_v0_5;
    void *var_a1;

    var_s0 = 0;
    temp_v0 = (D_800BA1B0 + 1) & 0xF;
    D_800BA1B0 = temp_v0;
    temp_v0_2 = &(&D_800C7EC0)[temp_v0];
    *temp_v0_2 = 0;
    if ((s32) D_800AE614 > 0) {
        var_a1 = D_8006B8FC;
        var_a0 = 0;
        do {
            temp_v0_3 = M2C_FIELD(var_a1, u16 *, 0xC);
            *(&D_8007958E + var_a0) = temp_v0_3;
            if (temp_v0_3 == 0) {
                *temp_v0_2 |= 1 << var_s0;
            }
            var_a1 += 0x10;
            var_s0 += 1;
            var_a0 += 0x34;
        } while (var_s0 < (s32) D_800AE614);
    }
    var_s0_2 = 0;
    if (D_800BA100 == 0) {
        var_s2 = -1;
        var_v1 = &D_800C7EC0;
        do {
            var_s0_2 += 1;
            var_s2 &= *var_v1;
            var_v1 += 4;
        } while (var_s0_2 < 0xF);
        var_s0_3 = 0;
        if ((s32) D_800AE614 > 0) {
            var_s1 = 0;
            do {
                if (var_s2 & (1 << var_s0_3)) {
                    if (*(&D_800795A3 + var_s1) == 2) {
                        func_8003FE18(0, 0xFFFFFF);
                    }
                    *(&D_800795A3 + var_s1) = 0;
                }
                var_s0_3 += 1;
                var_s1 += 0x34;
            } while (var_s0_3 < (s32) D_800AE614);
        }
        var_s0_2 = 0;
    }
    var_s1_2 = 0;
    D_80078D8C &= ~D_800C7F04;
    D_80078D8E &= ~D_800C7F06;
    do {
        if (*(&D_800795A4 + var_s1_2) != 0) {
            D_800BA0D0(var_s0_2);
        }
        if (*(&D_800795B0 + var_s1_2) != 0) {
            D_800AE828(var_s0_2);
        }
        var_s0_2 += 1;
        var_s1_2 += 0x34;
    } while (var_s0_2 < 0x18);
    var_a1_2 = &D_800A4620;
    var_t1 = &D_800B9B58 + 0xA;
    var_t0 = &D_800B9B58 + 8;
    var_a0_2 = 0;
    var_a3 = &D_800B9B58 + 2;
    var_a2 = &D_800B9B58;
    do {
        if (*var_a1_2 & 1) {
            temp_v0_4 = var_a0_2 + D_8006B8FC;
            M2C_FIELD(temp_v0_4, u16 *, 0) = (u16) *var_a2;
            M2C_FIELD(temp_v0_4, u16 *, 2) = (u16) *var_a3;
        }
        if (*var_a1_2 & 4) {
            M2C_FIELD((var_a0_2 + D_8006B8FC), u16 *, 4) = (u16) *(&D_800B9B5C + var_a0_2);
        }
        if (*var_a1_2 & 8) {
            M2C_FIELD((var_a0_2 + D_8006B8FC), u16 *, 6) = (u16) *(&D_800B9B5E + var_a0_2);
        }
        if (*var_a1_2 & 0x10) {
            temp_v0_5 = var_a0_2 + D_8006B8FC;
            M2C_FIELD(temp_v0_5, u16 *, 8) = (u16) *var_t0;
            M2C_FIELD(temp_v0_5, u16 *, 0xA) = (u16) *var_t1;
        }
        *var_a1_2 = 0;
        var_a1_2 += 1;
        var_t1 += 0x10;
        var_t0 += 0x10;
        var_a0_2 += 0x10;
        var_a3 += 0x10;
        var_a2 += 0x10;
    } while ((s32) var_a1_2 < (s32) (&D_800A4620 + 0x18));
    temp_v1 = D_800C7F04;
    temp_a0 = D_800C7F06;
    temp_a1 = D_80078D8C;
    temp_a2 = D_80078D8E;
    D_800C7F04 = 0;
    D_800C7F06 = 0;
    D_80078D8C = 0;
    D_80078D8E = 0;
    M2C_FIELD(D_8006B8FC, u16 *, 0x18C) = temp_v1;
    M2C_FIELD(D_8006B8FC, u16 *, 0x18E) = temp_a0;
    M2C_FIELD(D_8006B8FC, u16 *, 0x188) = temp_a1;
    M2C_FIELD(D_8006B8FC, u16 *, 0x18A) = temp_a2;
    M2C_FIELD(D_8006B8FC, u16 *, 0x198) = (u16) D_80078D90;
    M2C_FIELD(D_8006B8FC, u16 *, 0x19A) = (u16) D_80078D92;
}
