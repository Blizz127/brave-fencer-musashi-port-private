/* Exact retail word export for [80037FC4,8003819C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80038A58();                            /* static */
void func_8003B250(s32, void *);                 /* static */
void func_8003BE74(s32, u16);                /* static */
void func_8003C23C(s32, u16);                /* static */
void func_8003D3B4(s32, s32);                /* static */
extern u16 D_800A2B98;
extern u16 D_800A2BA0;
extern u8 D_800A4F1D;
extern s32 *D_800C6DD0;
extern s32 *D_800C6E2E;
extern u16 D_800C7D20;
extern u16 D_800C7D2C;

void func_80037FC4(void) {
    void *var_s0;
    void *var_s2;
    s32 var_s1;
    s32 var_s1_2;
    void *var_s0_2;

    if (D_800A4F1D == 0) {
        func_80038A58();
    }
    var_s1 = 0;
    var_s0 = &D_800C6E2E;
    do {
        if ((M2C_FIELD(var_s0, u8 *, -4) != 0) && (M2C_FIELD(var_s0, u8 *, -1) == 0) && (M2C_FIELD(var_s0, u8 *, 0) != 0)) {
            func_8003D3B4(var_s1, 8);
            M2C_FIELD(var_s0, u8 *, 0) = 0U;
            M2C_FIELD(var_s0, s32 *, -0x4A) = (s32) (M2C_FIELD(var_s0, s32 *, -0x4A) & 0xFFF9FFFF);
        }
        var_s1 += 1;
        var_s0 += 0x60;
    } while (var_s1 < 0x10);
    if (D_800A2B98 != 0) {
        func_8003C23C(0, D_800A2B98);
        D_800A2B98 = (s32) ((s32) D_800A2B98 & 0xFF0000);
    }
    if (D_800A2BA0 != 0) {
        func_8003BE74(0, D_800A2BA0);
        D_800A2BA0 = (s32) ((s32) D_800A2BA0 & 0xFF0000);
    }
    var_s2 = &D_800C6DD0;
    var_s1_2 = 0;
    var_s0_2 = &D_800C6DD0 + 0x5E;
    do {
        if ((M2C_FIELD(var_s0_2, u8 *, -4) != 0) && (M2C_FIELD(var_s0_2, u8 *, -1) != 0)) {
            func_8003B250(var_s1_2, var_s2 + 0x10);
            M2C_FIELD(var_s0_2, s32 *, -0x4A) = 0;
            M2C_FIELD(var_s0_2, u8 *, -1) = 0U;
            M2C_FIELD(var_s0_2, s8 *, 0) = 0;
        }
        var_s1_2 += 1;
        var_s0_2 += 0x60;
        var_s2 += 0x60;
    } while (var_s1_2 < 0x10);
    if (D_800C7D20 != 0) {
        func_8003C23C(1, D_800C7D20);
        D_800C7D20 = (s32) ((s32) D_800C7D20 & 0xFF0000);
    }
    if (D_800C7D2C != 0) {
        func_8003BE74(1, D_800C7D2C);
        D_800C7D2C = (s32) ((s32) D_800C7D2C & 0xFF0000);
    }
}
