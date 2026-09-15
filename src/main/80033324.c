/* Main-exec range [80033324,80033398) from the SLUS executable.
 * SHA256(span)=fea3b49da81371a004075e38ddc933ed4af86640c52e618c7fdd0a5a2282104c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A46E8;

void func_80033324(s32 arg0, s32 arg1) {
    u16 temp_v0;
    void *temp_a1;

    temp_a1 = (arg1 * 0x54) + &D_800A46E8;
    if ((M2C_FIELD(temp_a1, u16 *, 0) & 0x3F) == 1) {
        M2C_FIELD((temp_a1 + arg0), s8 *, 0xE) = 0;
        temp_v0 = M2C_FIELD(temp_a1, u16 *, 0xC) - 1;
        M2C_FIELD(temp_a1, u16 *, 0xC) = temp_v0;
        if (!(temp_v0 & 0xFFFF) && (M2C_FIELD(temp_a1, u8 *, 0xA) != 5)) {
            M2C_FIELD(temp_a1, u8 *, 0xA) = 0U;
            M2C_FIELD(temp_a1, u16 *, 0) = 0U;
        }
    }
}
