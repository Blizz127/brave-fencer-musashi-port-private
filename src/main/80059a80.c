/* Complete retail instruction export [80059A80,80059B44), verified against EXE and asm/main.s. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072780;
extern s32 D_80072838;
extern s32 D_8007283C;
extern s32 D_80072840;
extern s32 D_8007419C;
void func_80059760(s32 (*)(), void *);       /* static */

s32 func_80059A80(void *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    func_80059760(D_8007419C, arg0);
    var_v0 = -1;
    if (M2C_FIELD(arg0, s16 *, 4) != 0) {
        if (M2C_FIELD(arg0, s16 *, 6) == 0) {
            return -1;
        }
        D_8007283C = (s32) ((arg2 << 0x10) | (arg1 & 0xFFFF));
        D_80072838 = (s32) M2C_FIELD(arg0, s32 *, 0);
        D_80072840 = (s32) M2C_FIELD(arg0, s16 *, 4);
        var_v0 = M2C_FIELD(D_80072780, s32 (**)(s32, void *, s32, s32), 8)(M2C_FIELD(D_80072780, s32 *, 0x18), D_80072838 - 8, 0x14, 0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
