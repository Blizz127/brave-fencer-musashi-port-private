/* Overlay range [801479BC,80147A10) from MAIN.CD member 0012.
 * SHA256(span)=fe530e04fb6afc1481ab84c1ccc0013bedfc372dcc92116cc445f93c8bd6877b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801479BC(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x28) + arg1;
    M2C_FIELD(arg0, s32 *, 0x28) = temp_v0;
    if (arg1 < 0) {
        temp_v1 = -arg2;
        if (temp_v1 >= temp_v0) {
            M2C_FIELD(arg0, s32 *, 0x28) = temp_v1;
            return;
        }
    }
    if ((arg1 > 0) && (M2C_FIELD(arg0, s32 *, 0x28) >= arg2)) {
        M2C_FIELD(arg0, s32 *, 0x28) = arg2;
    }
}
