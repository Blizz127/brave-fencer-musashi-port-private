/* Exact retail word export for [8002F248,8002F4E4); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9F8[];
void func_8002DC68(u16, s32);                /* static */
s32 func_800331D4();                         /* static */
extern s32 *D_800A4694;
extern u32 D_800A4EEC;

void func_8002F248(void *arg0, s32 arg1) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a1;
    s32 var_a1_2;
    u16 var_a0;
    u32 temp_v0;
    u32 temp_v0_4;
    u32 temp_v0_5;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u8 temp_v1;
    void *var_a0_2;
    void *var_a0_3;

    temp_v1 = M2C_FIELD(arg0, u8 *, 3);
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        temp_v0 = (D_800A4EEC * 0x41C64E6D) + 0x3039;
        D_800A4EEC = temp_v0;
        temp_v1_2 = (temp_v0 >> 0x10) & 7;
        switch (temp_v1_2) {                        /* switch 2 */
        case 0:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
            var_a0 = 0x67C;
block_28:
            func_8002DC68(var_a0, 0);
            break;
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            var_a0 = 0x689;
            goto block_28;
        case 4:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            var_a0 = 0x67B;
            goto block_28;
        }
    default:                                        /* switch 1 */
        return;
    case 1:                                         /* switch 1 */
        var_a0 = arg1 & 0xFFFF;
        goto block_28;
    case 2:                                         /* switch 1 */
        temp_v0_2 = func_800331D4(0x95C);
        if (temp_v0_2 != 0) {
            var_a1 = 0;
            var_a0_2 = &D_800A4694 + 0x2F4;
            do {
                if (M2C_FIELD(((temp_v0_2 * 0x54) + &D_800A4694 + var_a1), u8 *, 0xE) != 0) {
                    M2C_FIELD(var_a0_2, s16 *, 0x30) = 0;
                    M2C_FIELD(var_a0_2, s8 *, 0x38) = 0;
                    M2C_FIELD(var_a0_2, s32 *, 0x2C) = -0x18;
                    M2C_FIELD(var_a0_2, s32 *, 0x28) = (s32) (M2C_FIELD(var_a0_2, s32 *, 0x20) - 0x100);
                    M2C_FIELD(var_a0_2, u8 *, 0x37) = (u8) (M2C_FIELD(var_a0_2, u8 *, 0x37) | 1);
                }
                var_a1 += 1;
                var_a0_2 += 0x54;
            } while (var_a1 < 8);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        temp_v0_3 = func_800331D4(0x95C);
        if (temp_v0_3 != 0) {
            var_a1_2 = 0;
            var_a0_3 = &D_800A4694 + 0x2F4;
            do {
                if (M2C_FIELD(((temp_v0_3 * 0x54) + &D_800A4694 + var_a1_2), u8 *, 0xE) != 0) {
                    M2C_FIELD(var_a0_3, s16 *, 0x30) = 0;
                    M2C_FIELD(var_a0_3, s8 *, 0x38) = 0;
                    M2C_FIELD(var_a0_3, s32 *, 0x2C) = 0x18;
                    M2C_FIELD(var_a0_3, s32 *, 0x28) = (s32) (M2C_FIELD(var_a0_3, s32 *, 0x20) + 0x100);
                    M2C_FIELD(var_a0_3, u8 *, 0x37) = (u8) (M2C_FIELD(var_a0_3, u8 *, 0x37) | 1);
                }
                var_a1_2 += 1;
                var_a0_3 += 0x54;
            } while (var_a1_2 < 8);
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        temp_v0_4 = (D_800A4EEC * 0x41C64E6D) + 0x3039;
        D_800A4EEC = temp_v0_4;
        temp_v1_3 = (temp_v0_4 >> 0x10) & 7;
        switch (temp_v1_3) {                        /* switch 3 */
        case 0:                                     /* switch 3 */
        case 3:                                     /* switch 3 */
            var_a0 = 0xAFD;
            goto block_28;
        case 1:                                     /* switch 3 */
        case 2:                                     /* switch 3 */
        case 5:                                     /* switch 3 */
            var_a0 = 0xAFF;
            goto block_28;
        case 4:                                     /* switch 3 */
            var_a0 = 0xAFE;
            goto block_28;
        }
        break;
    case 5:                                         /* switch 1 */
        func_8002DC68(0xB06U, 0);
        var_a0 = 0xB07;
        goto block_28;
    case 6:                                         /* switch 1 */
        func_8002DC68(0xB06U, 0);
        var_a0 = 0xC60;
        goto block_28;
    case 7:                                         /* switch 1 */
        temp_v0_5 = (D_800A4EEC * 0x41C64E6D) + 0x3039;
        D_800A4EEC = temp_v0_5;
        var_a0 = *(D_8006A9F8 + ((temp_v0_5 >> 0xF) & 0x1E));
        goto block_28;
    }
}
