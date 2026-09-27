/* Native retail instruction export [8003AF04,8003AF4C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 D_8006B574;

void func_8003AF04(s32 arg0, u16 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0 * 2;
    if (arg2 == 0) {
        *(s32 *) (temp_v0 + D_8006B54C) = arg1;
        return;
    }
    *(s32 *) (temp_v0 + D_8006B54C) = (s16) (arg1 >> D_8006B574);
}
