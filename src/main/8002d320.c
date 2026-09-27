/* Exact retail word export for [8002D320,8002D4B8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003B250(s32, void *);              /* static */
void func_8003BE74(s32, s32);                /* static */
void func_8003C23C(s32, s32);                /* static */
void func_8003D3B4(s32, s32);                /* static */
extern s32 D_800A2B98;
extern s32 D_800A2BA0;
extern s32 *D_800A4C28;
extern s32 *D_800A4C6D;
extern s32 D_800C7D20;
extern s32 D_800C7D2C;

void func_8002D320(void) {
    void *var_s0;
    void *var_s1;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 var_s2;
    s32 var_s2_2;
    void *var_s0_2;

    var_s2 = 0;
    var_s0 = &D_800A4C6D;
    do {
        if (M2C_FIELD(var_s0, u8 *, 0) != 0) {
            if ((M2C_FIELD(var_s0, u8 *, -1) == 0) || !(M2C_FIELD(var_s0, s32 *, -0x41) & 0x60000)) {
                func_8003D3B4(M2C_FIELD(var_s0, s32 *, -5), 1);
            }
            M2C_FIELD(var_s0, u8 *, 0) = 0U;
        }
        var_s2 += 1;
        var_s0 += 0x48;
    } while (var_s2 < 8);
    temp_a1 = D_800A2B98 & 0xFF0000;
    if (temp_a1 != 0) {
        func_8003C23C(0, temp_a1);
        D_800A2B98 = (s32) (u16) D_800A2B98;
    }
    temp_a1_2 = D_800A2BA0 & 0xFF0000;
    if (temp_a1_2 != 0) {
        func_8003BE74(0, temp_a1_2);
        D_800A2BA0 = (s32) (u16) D_800A2BA0;
    }
    var_s1 = &D_800A4C28;
    var_s2_2 = 0;
    var_s0_2 = &D_800A4C28 + 4;
    do {
        if (M2C_FIELD(var_s0_2, u8 *, 0x40) != 0) {
            M2C_FIELD(var_s0_2, u8 *, 0x40) = 0U;
            func_8003B250(M2C_FIELD(var_s0_2, s32 *, 0x3C), var_s1);
            M2C_FIELD(var_s0_2, s32 *, 0) = 0;
        }
        var_s0_2 += 0x48;
        var_s2_2 += 1;
        var_s1 += 0x48;
    } while (var_s2_2 < 8);
    temp_a1_3 = D_800C7D20 & 0xFF0000;
    if (temp_a1_3 != 0) {
        func_8003C23C(1, temp_a1_3);
        D_800C7D20 = (s32) (u16) D_800C7D20;
    }
    temp_a1_4 = D_800C7D2C & 0xFF0000;
    if (temp_a1_4 != 0) {
        func_8003BE74(1, temp_a1_4);
        D_800C7D2C = (s32) (u16) D_800C7D2C;
    }
}
