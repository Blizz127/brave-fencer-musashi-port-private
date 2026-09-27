/* Overlay range [80171AB0,80171B10) from MAIN.CD member 0012.
 * SHA256(span)=f04c4ca87decfb4116f3fba64f937ecafc5b790d01ebd961ea2b3ee6a53bcfa6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012B04(s16, s16, s32);               /* extern */
s16 func_8014C568();                                /* static */

s16 func_80171AB0(void *arg0) {
    s16 temp_v0;
    void *temp_a1;

    temp_v0 = func_80012B04(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12), func_8014C568(), 4);
    temp_a1 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_a1, s16 *, 0x12) = (s16) (((u16) M2C_FIELD(temp_a1, s16 *, 0x12) + temp_v0) & 0xFFF);
    return temp_v0;
}
