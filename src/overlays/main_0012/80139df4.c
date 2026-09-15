/* Overlay range [80139DF4,80139E84) from MAIN.CD member 0012.
 * SHA256(span)=3cd86249b31cc1bc154668f88f43a162746248d03a6715942bd7e07023a89a6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80139A8C(void *);                      /* static */

void func_80139DF4(void *arg0) {
    s32 temp_v1;
    u8 temp_v0;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0xC);
    temp_v0_2 = temp_v0 - 1;
    if ((temp_v0 == 0) || (M2C_FIELD(arg0, u8 *, 0xC) = temp_v0_2, ((temp_v0_2 & 0xFF) == 0))) {
        M2C_FIELD(arg0, s16 *, 4) = 2;
        return;
    }
    func_80139A8C(arg0);
    if (M2C_FIELD(arg0, s32 *, 8) & 0x20) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(arg0, s16 *, 4) = 2;
        M2C_FIELD(arg0, u8 *, 0xC) = 0U;
        if (!(temp_v1 & 0x20000)) {
            M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_v1 & ~0x20);
        }
    }
}
