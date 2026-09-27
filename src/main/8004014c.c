/* Native retail instruction export [8004014C,800401A0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B574;
extern s32 D_8006B5A8;
extern s32 D_8006B5AC;
extern s32 D_8006B5B0;

s32 func_8004014C(s32 arg0, void *arg1) {
    if (arg0 <= 0) {
        return 0;
    }
    M2C_FIELD(arg1, s32 *, 0) = 0x40001010;
    D_8006B5B0 = arg1;
    D_8006B5AC = 0;
    D_8006B5A8 = arg0;
    M2C_FIELD(arg1, s32 *, 4) = (s32) ((0x10000 << D_8006B574) - 0x1010);
    return arg0;
}
