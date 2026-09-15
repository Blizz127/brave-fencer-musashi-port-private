/* Main-exec range [8002A544,8002A5C4) from the SLUS executable.
 * SHA256(span)=b51002e0f5933d6770a2d2cd79086913e4f775f509f4425331d545db2562df89.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8016E918(s32, s16);                /* extern */
extern s32 D_80063902[];
s32 func_8002A5C4();                                /* static */
s32 func_8002A728();                                /* static */
void func_8002AAAC();                            /* static */
void func_8002D4C8(s32, s32);            /* static */

s32 func_8002A544(void) {
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0;
    if (func_8002A5C4() != 0) {
        temp_v0 = func_8002A728();
        func_8016E918(3, (s16) (*(D_80063902 + (temp_v0 * 0x10)) - *(D_80063902 + ((temp_v0 - 1) * 0x10))));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        var_v0 = 1;
    }
    return var_v0;
}
