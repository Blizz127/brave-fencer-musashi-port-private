/* Exact retail word export for [800316F8,80031988); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800316F8(void *arg0) {
    s32 temp_a0;
    s32 temp_a2_2;
    u16 temp_v1;
    u16 var_a3;
    u16 var_t0;
    void *temp_a2;

    var_a3 = 0;
    temp_a2 = M2C_FIELD(arg0, void **, 0x14);
    var_t0 = 0;
    M2C_FIELD(arg0, u8 *, 0x37) = 0U;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    if (temp_a2 != 0) {
        temp_v1 = M2C_FIELD(temp_a2, u16 *, 0);
        switch (temp_v1) {
        case 1:
            var_t0 = M2C_FIELD(temp_a2, u16 *, 2);
            var_a3 = M2C_FIELD(temp_a2, u16 *, 4);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, s8 *, 0x38) = 1;
            M2C_FIELD(arg0, u16 *, 0x3A) = (u16) M2C_FIELD(temp_a2, u16 *, 6);
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) M2C_FIELD(temp_a2, u16 *, 8);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xE);
        default:
block_17:
            temp_a2_2 = var_t0 & 0xFFFF;
            temp_a0 = var_a3 & 0xFFFF;
            if ((temp_a2_2 != 0) && (M2C_FIELD(arg0, s32 *, 0x24) != temp_a0)) {
                M2C_FIELD(arg0, s32 *, 0x28) = temp_a0;
                M2C_FIELD(arg0, u8 *, 0x37) = (u8) (M2C_FIELD(arg0, u8 *, 0x37) | 1);
                if (temp_a0 < M2C_FIELD(arg0, s32 *, 0x24)) {
                    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) -temp_a2_2;
                    return;
                }
                M2C_FIELD(arg0, s32 *, 0x2C) = temp_a2_2;
            }
            break;
        case 9:
            var_t0 = M2C_FIELD(temp_a2, u16 *, 2);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, s8 *, 0x38) = 1;
            M2C_FIELD(arg0, u16 *, 0x3A) = (u16) M2C_FIELD(temp_a2, u16 *, 6);
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (M2C_FIELD(temp_a2, u16 *, 8) + M2C_FIELD(arg0, s32 *, 0x20));
            var_a3 = M2C_FIELD(temp_a2, u16 *, 4) + M2C_FIELD(arg0, s32 *, 0x20);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xE);
            goto block_17;
        case 6:
            var_t0 = M2C_FIELD(temp_a2, u16 *, 4);
            var_a3 = M2C_FIELD(temp_a2, u16 *, 6);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, s8 *, 0x38) = 1;
            M2C_FIELD(arg0, u16 *, 0x3A) = (u16) M2C_FIELD(temp_a2, u16 *, 8);
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) M2C_FIELD(temp_a2, u16 *, 0xA);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0x10);
block_10:
            M2C_FIELD(arg0, u16 *, 0x30) = (u16) M2C_FIELD(temp_a2, u16 *, 2);
            goto block_17;
        case 10:
            var_t0 = M2C_FIELD(temp_a2, u16 *, 4);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, s8 *, 0x38) = 1;
            M2C_FIELD(arg0, u16 *, 0x3A) = (u16) M2C_FIELD(temp_a2, u16 *, 8);
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (M2C_FIELD(temp_a2, u16 *, 0xA) + M2C_FIELD(arg0, s32 *, 0x20));
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0x10);
block_12:
            var_a3 = M2C_FIELD(temp_a2, u16 *, 6) + M2C_FIELD(arg0, s32 *, 0x20);
            M2C_FIELD(arg0, u16 *, 0x30) = (u16) M2C_FIELD(temp_a2, u16 *, 2);
            goto block_17;
        case 0:
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            var_t0 = M2C_FIELD(temp_a2, u16 *, 2);
            var_a3 = M2C_FIELD(temp_a2, u16 *, 4);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xA);
            goto block_17;
        case 7:
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            var_t0 = M2C_FIELD(temp_a2, u16 *, 2);
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            var_a3 = M2C_FIELD(temp_a2, u16 *, 4) + M2C_FIELD(arg0, s32 *, 0x20);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xA);
            goto block_17;
        case 5:
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            var_t0 = M2C_FIELD(temp_a2, u16 *, 4);
            var_a3 = M2C_FIELD(temp_a2, u16 *, 6);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xC);
            goto block_10;
        case 8:
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            var_t0 = M2C_FIELD(temp_a2, u16 *, 4);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 0xC);
            goto block_12;
        case 2:
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
block_15:
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_a2, u16 *, 2);
            return;
        case 3:
            M2C_FIELD(arg0, u8 *, 0x37) = (u8) (M2C_FIELD(arg0, u8 *, 0x37) | 2);
            M2C_FIELD(arg0, s32 *, 0x1C) = (s32) ((s16) M2C_FIELD(temp_a2, u16 *, 4) << 8);
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            M2C_FIELD(arg0, u16 *, 0x32) = (u16) M2C_FIELD(temp_a2, u16 *, 6);
            goto block_15;
        case 4:
            M2C_FIELD(arg0, u8 *, 0x37) = (u8) (M2C_FIELD(arg0, u8 *, 0x37) | 2);
            M2C_FIELD(arg0, s32 *, 0x1C) = (s32) ((s16) M2C_FIELD(temp_a2, u16 *, 2) << 8);
            M2C_FIELD(arg0, s8 *, 0x38) = 0;
            M2C_FIELD(arg0, u16 *, 0x30) = 0U;
            M2C_FIELD(arg0, u16 *, 0x32) = (u16) M2C_FIELD(temp_a2, u16 *, 4);
            return;
        }
    }
}
