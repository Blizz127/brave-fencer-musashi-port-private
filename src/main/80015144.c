/* Main-exec range [80015144,80015208) from the SLUS executable.
 * SHA256(span)=6ad62d5925c7f85a798c02b205f31b40896b77551a2152570af1c466d32c5f13.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019990();                            /* static */
s32 func_8001AA78();                         /* static */
void func_8002D034();                            /* static */
void func_8002D4C8(s32, s32);            /* static */
void func_8002F67C();                            /* static */
s32 func_80034B98();                                /* static */
void func_8003500C();                            /* static */
void func_8004239C(s32);                         /* static */
extern s32 *D_800AF630;
extern s16 D_800B9A04;

s32 func_80015144(void) {
    s32 var_v0;

    if (func_80034B98() != 0) {
        func_8002D4C8(2, 0);
        do {
            func_8003500C();
            func_8002D034();
            func_8004239C(M2C_FIELD(&D_800AF630, s32 *, 0xA3E8));
        } while (func_80034B98() != 0);
        M2C_FIELD(&D_800AF630, s16 *, 0xA3D4) = 1;
        goto block_6;
    }
    var_v0 = 0;
    if (func_8001AA78(2) == 0) {
        D_800B9A04 = 1;
        func_8002D4C8(2, 0);
block_6:
        func_8002F67C();
        func_80019990();
        var_v0 = 1;
    }
    return var_v0;
}
