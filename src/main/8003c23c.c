/* Exact retail word export for [8003C23C,8003C438); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E4;
extern s32 D_8006B10C;
extern s32 D_8006B110;
extern s32 D_8006B544;
extern s32 D_8006B54C;
extern u16 D_800A6410;
extern u16 D_800A6412;
extern s32 *D_800A6414;

void func_8003C23C(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;
    u16 temp_a1;
    u32 temp_t0;

    temp_a1 = arg1 & 0xFFFFFF;
    temp_t0 = temp_a1 >> 0x10;
    if (arg0 != 0) {
        if (arg0 == 1) {
            if (D_8006B544 & 1) {
                D_800A6410 = temp_a1;
                D_800A6412 = (u16) temp_t0;
                D_8006B110 = (s32) (D_8006B110 | 1);
                D_8006B10C = (s32) (D_8006B10C | temp_a1);
                if (M2C_FIELD(&D_800A6414, u16 *, 0) & temp_a1) {
                    M2C_FIELD(&D_800A6414, u16 *, 0) = (u16) (M2C_FIELD(&D_800A6414, u16 *, 0) & ~temp_a1);
                }
                if (M2C_FIELD(&D_800A6414, u16 *, 2) & temp_t0) {
                    M2C_FIELD(&D_800A6414, u16 *, 2) = (u16) (M2C_FIELD(&D_800A6414, u16 *, 2) & ~temp_t0);
                }
            } else {
                var_v0 = D_8006B0E4 | temp_a1;
                M2C_FIELD(D_8006B54C, u16 *, 0x188) = temp_a1;
                M2C_FIELD(D_8006B54C, s16 *, 0x18A) = (s16) temp_t0;
                goto block_14;
            }
        }
    } else if (D_8006B544 & 1) {
        M2C_FIELD(&D_800A6414, u16 *, 0) = temp_a1;
        M2C_FIELD(&D_800A6414, u16 *, 2) = (u16) temp_t0;
        temp_a0 = ~temp_a1;
        D_8006B110 = (s32) (D_8006B110 | 1);
        D_8006B10C = (s32) (D_8006B10C & temp_a0);
        if (D_800A6410 & temp_a1) {
            D_800A6410 &= temp_a0;
        }
        if (D_800A6412 & temp_t0) {
            D_800A6412 &= ~temp_t0;
        }
    } else {
        M2C_FIELD(D_8006B54C, u16 *, 0x18C) = temp_a1;
        M2C_FIELD(D_8006B54C, s16 *, 0x18E) = (s16) temp_t0;
        var_v0 = D_8006B0E4 & ~temp_a1;
block_14:
        D_8006B0E4 = var_v0;
    }
}
