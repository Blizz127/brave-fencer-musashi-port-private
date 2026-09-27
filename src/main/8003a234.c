/* Main-exec range [8003A234,8003A3D8) from the SLUS executable.
 * SHA256(span)=3d54a6a2f02394ae122f754b990b20ed428ad447d17cd0b9b662a0e894ebc1b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003A234(void *arg0) {
    s32 temp_lo;
    u8 temp_v1;
    void *temp_a2;
    void *temp_v0;
    void *temp_v1_2;

    temp_a2 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 1);
    temp_v1 = M2C_FIELD(temp_a2, u8 *, 0);
    if (temp_v1 != 0x2F) {
        if ((s32) temp_v1 < 0x30) {
            if ((s32) temp_v1 < 8) {
                if (temp_v1 == 0) {
                    if (temp_v1 != 0) {
                        goto block_23;
                    }
                    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 2);
                    if (M2C_FIELD(temp_a2, u8 *, 1) == 2) {
                        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 4);
                        return;
                    }
                    goto block_23;
                }
                goto block_19;
            }
            if (temp_v1 != 0x20) {
                goto block_23;
            }
            M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 3);
            return;
        }
        switch ((s32) temp_v1) {                    /* irregular */
        case 0x51:
            M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 2);
            if (M2C_FIELD(temp_a2, u8 *, 1) == 3) {
                M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 3);
                M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 4);
                M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 5);
                temp_lo = 0x03938700 / (s32) ((M2C_FIELD(temp_a2, u8 *, 2) << 0x10) + (M2C_FIELD(temp_a2, u8 *, 3) << 8) + M2C_FIELD(temp_a2, u8 *, 4));
                M2C_FIELD(arg0, s16 *, 0x1E4) = (s16) temp_lo;
                M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (temp_lo * M2C_FIELD(arg0, s16 *, 0x1E6));
                return;
            }
            goto block_23;
        case 0x7F:
        case 0x54:
block_19:
            temp_v1_2 = M2C_FIELD(arg0, void **, 0);
            temp_v0 = temp_v1_2 + 1;
            M2C_FIELD(arg0, void **, 0) = temp_v0;
            M2C_FIELD(arg0, void **, 0) = (void *) (temp_v0 + M2C_FIELD(temp_v1_2, u8 *, 0));
            return;
        }
    } else {
        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a2 + 2);
block_23:
        M2C_FIELD(arg0, s8 *, 0x1F9) = 1;
    }
}
