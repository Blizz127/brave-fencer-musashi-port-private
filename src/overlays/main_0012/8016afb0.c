/* Overlay range [8016AFB0,8016B114) from MAIN.CD member 0012.
 * SHA256(span)=b900bf5219c4dc0e6b7d2401dc24971540aa0c031eec59f6f45805a72ee2707f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D22E4(void *);                      /* extern */
void func_8016B234();                            /* static */

void func_8016AFB0(void *arg0) {
    s32 temp_v0_2;
    s32 temp_v1_2;
    s8 var_v1;
    u32 temp_v1;
    u8 temp_v0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x20);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x2C) < 6U) {
        func_8016B234();
    }
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x2C);
    if (temp_v1 != 5) {
        if (temp_v1 < 6U) {
            if (temp_v1 != 1) {

            } else {
                goto block_13;
            }
            goto block_14;
        }
        if (temp_v1 != 6) {
            if (temp_v1 == 7) {
                var_v1 = 0xB4;
                if (M2C_FIELD(arg0, s32 *, 0x1C) & 1) {
                    var_v1 = 0xAE;
                }
                M2C_FIELD(temp_s1, s8 *, 0x27) = var_v1;
                goto block_11;
            }
            goto block_14;
        }
block_11:
        temp_v0 = M2C_FIELD(temp_s1, u8 *, 0x26) - 8;
        M2C_FIELD(temp_s1, u8 *, 0x26) = temp_v0;
        M2C_FIELD(temp_s1, u8 *, 0x25) = temp_v0;
        M2C_FIELD(temp_s1, u8 *, 0x24) = temp_v0;
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
        if (temp_v0_2 == 0) {
            M2C_FIELD(temp_s1, u8 *, 0x26) = 0x70U;
            M2C_FIELD(temp_s1, u8 *, 0x25) = 0x70U;
            M2C_FIELD(temp_s1, u8 *, 0x24) = 0x70U;
            M2C_FIELD(temp_s1, s32 *, 4) = (s32) (M2C_FIELD(temp_s1, s32 *, 4) | 0x50000000);
            M2C_FIELD(arg0, s32 *, 0x1C) = 7;
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        }
    } else {
block_13:
        func_800D22E4(arg0);
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 0x18000);
block_14:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
        M2C_FIELD(arg0, u16 *, 0x24) = (u16) (M2C_FIELD(arg0, u16 *, 0x24) - 8);
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_v1_2;
        if (temp_v1_2 == 0) {
            M2C_FIELD(arg0, u16 *, 0x24) = 0x70U;
            M2C_FIELD(arg0, s32 *, 0x1C) = 7;
            M2C_FIELD(arg0, u16 *, 0x26) = (u16) (M2C_FIELD(arg0, u16 *, 0x26) + 1);
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        }
    }
}
