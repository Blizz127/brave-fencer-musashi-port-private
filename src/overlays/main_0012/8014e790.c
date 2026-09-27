/* Overlay range [8014E790,8014E83C) from MAIN.CD member 0012.
 * SHA256(span)=c697a576b33f37b93f8827ae35249b32d63266829f558fbb3ed7c0b4ed03081c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135888(s32, s32, s32, s32);      /* static */

s32 func_8014E790(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x180);
    if ((M2C_FIELD(temp_s0, u16 *, 0) == 0) || !(M2C_FIELD(temp_s0, u16 *, 0x5C) & 0x20) || (temp_a1 = M2C_FIELD(temp_s0, s32 *, 0x58), (temp_a1 == 0)) || (func_80135888(M2C_FIELD(temp_s0, s32 *, 0x20), temp_a1, arg1, arg2) == 0)) {
        M2C_FIELD(arg0, void **, 0x180) = 0;
        return 0;
    }
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(temp_s0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(temp_s0, u16 *, 0xA);
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(temp_s0, u16 *, 0xE);
    return 1;
}
