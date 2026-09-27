/* Main-exec range [8005ADB8,8005AE68) from the SLUS executable.
 * SHA256(span)=8322c45f652ac9936e4a63faa2f50c0cd04023d8032a60ff35a19d4de99cdd69.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072788;
extern u8 D_8007278B;

s32 func_8005ADB8(void *arg0) {
    s32 var_v1;
    u16 temp_v0;

    switch (D_80072788) {                           /* irregular */
    case 1:
        if (D_8007278B != 0) {
            var_v1 = (s32) (s16) M2C_FIELD(arg0, u16 *, 4);
block_5:
            return (0x400 - var_v1) - M2C_FIELD(arg0, s16 *, 0);
        }
    default:
        return (s32) M2C_FIELD(arg0, s16 *, 0);
    case 2:
        if (D_8007278B != 0) {
            var_v1 = (s16) M2C_FIELD(arg0, u16 *, 4) / 2;
            goto block_5;
        }
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0);
        return (s32) ((s16) temp_v0 + ((u32) (temp_v0 << 0x10) >> 0x1F)) >> 1;
    }
}
