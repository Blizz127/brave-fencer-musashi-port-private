/* Overlay range [8016AE5C,8016AFB0) from MAIN.CD member 0012.
 * SHA256(span)=e8024b94fe1ca2c3db23eb4b4c9e141b409fb90b57be695c6b4cbfdada8cfb45.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D22E4(void *);                      /* extern */
void func_8016B234();                            /* static */

void func_8016AE5C(void *arg0) {
    s32 temp_a0;
    s32 temp_v1_2;
    s32 var_v0;
    u32 temp_v1;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x20);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x2C) < 6U) {
        func_8016B234();
    }
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x2C);
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - M2C_FIELD(arg0, s32 *, 0x1C));
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_v1_2;
        if (temp_v1_2 != 0) {
            if ((temp_v1_2 & 3) == 1) {
                M2C_FIELD(arg0, u16 *, 0x26) = (u16) (M2C_FIELD(arg0, u16 *, 0x26) + 1);
                return;
            }
        } else {
            M2C_FIELD(arg0, s16 *, 0x24) = 0xFF;
            M2C_FIELD(arg0, s32 *, 0x1C) = 8;
block_14:
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        default:
            return;
        }
        break;
    case 1:
    case 5:
        func_800D22E4(arg0);
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 0x18000);
        /* fallthrough */
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - M2C_FIELD(arg0, s32 *, 0x1C));
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_a0;
        if (temp_a0 == 0) {
            if ((u32) M2C_FIELD(arg0, u32 *, 0x2C) < 6U) {
                M2C_FIELD(arg0, s16 *, 0x24) = 0xC0;
                var_v0 = 8;
            } else {
                M2C_FIELD(temp_s1, s8 *, 0x26) = 0xC0;
                M2C_FIELD(temp_s1, s8 *, 0x25) = 0xC0;
                M2C_FIELD(temp_s1, s8 *, 0x24) = 0xC0;
                var_v0 = 0xC;
            }
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
            goto block_14;
        }
        break;
    }
}
