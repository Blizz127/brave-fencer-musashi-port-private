/* Exact retail word export for [8005D184,8005D244); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072970();                                     /* static */

u8 func_8005D184(void) {
    u8 temp_v1;
    u8 var_v0;
    void *temp_v0;

    temp_v0 = D_80072970();
    if ((temp_v0->unk34 & 0xFFFF0000) || ((temp_v0 != temp_v0->unk10) && (temp_v0->unk38 != 0)) || (*temp_v0->unk30 != 0)) {
        temp_v1 = temp_v0->unk49;
        if (temp_v1 != 3) {
            if ((s32) temp_v1 < 4) {
                var_v0 = 1;
                if (temp_v1 != 2) {
                    goto block_11;
                }
            } else {
                var_v0 = 4;
                if (temp_v1 != 6) {
                    goto block_11;
                }
            }
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return var_v0;
        }
        return 1U;
    }
block_11:
    var_v0 = temp_v0->unk49;
    return var_v0;
}
