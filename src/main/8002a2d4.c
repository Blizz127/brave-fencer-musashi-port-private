/* Main-exec range [8002A2D4,8002A354) from the SLUS executable.
 * SHA256(span)=7d738daf4841091fc4649276078870993d6d60746426c3eeb54e5efaa093d2ac.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8016E918(s32, s16);                            /* extern */
extern s32 D_800638FE;
s32 func_8002A354();                                /* static */
s32 func_8002A4B8();                                /* static */
void func_8002AAAC();                                  /* static */
void func_8002D4C8(s32, s32);                              /* static */

s32 func_8002A2D4(void) {
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0;
    if (func_8002A354() != 0) {
        temp_v0 = func_8002A4B8();
        func_8016E918(1, (s16) (*(D_800638FE + (temp_v0 * 0x10)) - *(D_800638FE + ((temp_v0 - 1) * 0x10))));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        var_v0 = 1;
    }
    return var_v0;
}
