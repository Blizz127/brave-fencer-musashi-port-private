/* Overlay range [8016B114,8016B234) from MAIN.CD member 0012.
 * SHA256(span)=26b1ee0717f60a1b82cbb8aadda101996e3149c1e6408e65ed8be5fcf4eabfcd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D22E4(void *);                      /* extern */
void func_80146C3C(void *);                      /* static */
void func_8016B234();                            /* static */

void func_8016B114(void *arg0) {
    s32 temp_v0_2;
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
                goto block_9;
            }
            goto block_8;
        }
        if (temp_v1 < 8U) {
            temp_v0 = M2C_FIELD(temp_s1, u8 *, 0x26) - 0x10;
            M2C_FIELD(temp_s1, u8 *, 0x26) = temp_v0;
            M2C_FIELD(temp_s1, u8 *, 0x25) = temp_v0;
            M2C_FIELD(temp_s1, u8 *, 0x24) = temp_v0;
            M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - 2);
        } else {
block_9:
            M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - 2);
            M2C_FIELD(arg0, u16 *, 0x26) = (u16) (M2C_FIELD(arg0, u16 *, 0x26) + 1);
            M2C_FIELD(arg0, u16 *, 0x24) = (u16) (M2C_FIELD(arg0, u16 *, 0x24) - 0x10);
        }
    } else {
block_8:
        func_800D22E4(arg0);
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 0x18000);
        M2C_FIELD(arg0, u16 *, 0x26) = (u16) (M2C_FIELD(arg0, u16 *, 0x26) + 1);
        M2C_FIELD(arg0, u16 *, 0x24) = (u16) (M2C_FIELD(arg0, u16 *, 0x24) - 0x10);
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
    if (temp_v0_2 == 0) {
        func_80146C3C(arg0);
    }
}
