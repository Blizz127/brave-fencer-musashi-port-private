/* Native retail instruction export [8003C598,8003C92C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;

void func_8003C598(void *arg0) {
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_a2_2;
    s16 var_t0_2;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s16 var_v1_4;
    s32 temp_t1;
    s32 temp_t2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_v0;
    s32 var_v0_2;
    u16 var_a2;
    u16 var_t0;

    var_a2 = 0;
    temp_t1 = M2C_FIELD(arg0, s32 *, 0);
    temp_t2 = temp_t1 == 0;
    var_t0 = 0;
    if (temp_t2 == 0) {
        if (temp_t1 & 1) {
            if (temp_t1 & 4) {
                goto block_3;
            }
            goto block_12;
            goto block_13;
        }
    } else {
block_3:
        temp_v1 = M2C_FIELD(arg0, s16 *, 8);
        switch (temp_v1) {                          /* switch 1 */
        case 1:                                     /* switch 1 */
            var_a1 = 0x8000;
            break;
        case 2:                                     /* switch 1 */
            var_a1 = 0x9000;
            break;
        case 3:                                     /* switch 1 */
            var_a1 = 0xA000;
            break;
        case 4:                                     /* switch 1 */
            var_a1 = 0xB000;
            break;
        case 5:                                     /* switch 1 */
            var_a1 = 0xC000;
            break;
        case 6:                                     /* switch 1 */
            var_a1 = 0xD000;
            break;
        case 7:                                     /* switch 1 */
            var_a1 = 0xE000;
            break;
        default:                                    /* switch 1 */
block_12:
            var_a2 = M2C_FIELD(arg0, u16 *, 4);
            var_a1 = 0;
            break;
        }
block_13:
        var_v0 = var_a2 & 0x7FFF;
        if (var_a1 != 0) {
            temp_a3 = (s16) M2C_FIELD(arg0, u16 *, 4);
            if (temp_a3 >= 0x80) {
                var_a2_2 = 0x7F;
            } else {
                var_a2_2 = temp_a3;
                if (temp_a3 < 0) {
                    var_a2_2 = 0;
                }
            }
            var_v0 = var_a2_2 & 0x7FFF;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x180) = (s16) (var_v0 | var_a1);
    }
    if (temp_t2 == 0) {
        if (temp_t1 & 2) {
            if (temp_t1 & 8) {
                goto block_23;
            }
            goto block_32;
            goto block_33;
        }
    } else {
block_23:
        temp_v1_2 = M2C_FIELD(arg0, s16 *, 0xA);
        switch (temp_v1_2) {                        /* switch 2 */
        case 1:                                     /* switch 2 */
            var_a1_2 = 0x8000;
            break;
        case 2:                                     /* switch 2 */
            var_a1_2 = 0x9000;
            break;
        case 3:                                     /* switch 2 */
            var_a1_2 = 0xA000;
            break;
        case 4:                                     /* switch 2 */
            var_a1_2 = 0xB000;
            break;
        case 5:                                     /* switch 2 */
            var_a1_2 = 0xC000;
            break;
        case 6:                                     /* switch 2 */
            var_a1_2 = 0xD000;
            break;
        case 7:                                     /* switch 2 */
            var_a1_2 = 0xE000;
            break;
        default:                                    /* switch 2 */
block_32:
            var_t0 = M2C_FIELD(arg0, u16 *, 6);
            var_a1_2 = 0;
            break;
        }
block_33:
        var_v0_2 = var_t0 & 0x7FFF;
        if (var_a1_2 != 0) {
            temp_a2 = (s16) M2C_FIELD(arg0, u16 *, 6);
            if (temp_a2 >= 0x80) {
                var_t0_2 = 0x7F;
            } else {
                var_t0_2 = temp_a2;
                if (temp_a2 < 0) {
                    var_t0_2 = 0;
                }
            }
            var_v0_2 = var_t0_2 & 0x7FFF;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x182) = (s16) (var_v0_2 | var_a1_2);
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x40)) {
        M2C_FIELD(D_8006B54C, u16 *, 0x1B0) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x80)) {
        M2C_FIELD(D_8006B54C, u16 *, 0x1B2) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x400)) {
        M2C_FIELD(D_8006B54C, u16 *, 0x1B4) = (u16) M2C_FIELD(arg0, u16 *, 0x1C);
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x800)) {
        M2C_FIELD(D_8006B54C, u16 *, 0x1B6) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x100)) {
        if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
            var_v1 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFFB;
        } else {
            var_v1 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 4;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x1AA) = var_v1;
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x200)) {
        if (M2C_FIELD(arg0, s32 *, 0x18) == 0) {
            var_v1_2 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFFE;
        } else {
            var_v1_2 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 1;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x1AA) = var_v1_2;
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x1000)) {
        if (M2C_FIELD(arg0, s32 *, 0x20) == 0) {
            var_v1_3 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFF7;
        } else {
            var_v1_3 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 8;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x1AA) = var_v1_3;
    }
    if ((temp_t2 != 0) || (temp_t1 & 0x2000)) {
        if (M2C_FIELD(arg0, s32 *, 0x24) == 0) {
            var_v1_4 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFFD;
        } else {
            var_v1_4 = M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 2;
        }
        M2C_FIELD(D_8006B54C, s16 *, 0x1AA) = var_v1_4;
    }
}
