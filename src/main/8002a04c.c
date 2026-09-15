/* Main-exec range [8002A04C,8002A088) from the SLUS executable.
 * SHA256(span)=9449f527502f2333a36fcac22cde5621468f6080f5a9778e3b14b38d6cc02a19.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002A088(s16);                             /* static */

s32 func_8002A04C(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x78);
    if (temp_v0 == 0) {
        return 0;
    }
    return func_8002A088(M2C_FIELD(temp_v0, s16 *, 0x2E));
}
