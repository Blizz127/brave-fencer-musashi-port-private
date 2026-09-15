/* Overlay range [80142C9C,80142D38) from MAIN.CD member 0012.
 * SHA256(span)=58f763a882e7fda336a88faf5c62dda89a6a09dfeebb81744cf9cd2c34b62834.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012CBF4();                                /* static */

void func_80142C9C(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x102) < 2) {
        temp_v0 = func_8012CBF4() & 0x6000;
        if (M2C_FIELD(arg0, s32 *, 0x14) > 0x180000) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0x180000;
        }
        if ((temp_v0 != 0) || (M2C_FIELD(arg0, s16 *, 0xA) >= 0x101)) {
            if (M2C_FIELD(arg0, s16 *, 0x102) == 0) {
                M2C_FIELD(arg0, s32 *, 0x14) = -0x80000;
            }
            M2C_FIELD(arg0, s16 *, 0x102) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x102) + 1);
        }
    }
}
