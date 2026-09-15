/* Exact retail word export for [8005E3AC,8005E79C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8005E480;
extern s32 *D_8005E528;
void D_80072978();                                     /* static */

s32 func_8005E3AC(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_v0;

    if (arg1 != 0) {
        var_v0 = 0;
        if (arg0->unk4 == 0) {
            var_v0 = 1;
            if (D_80072978() != 0) {
                goto block_3;
            }
            arg0->unk49 = 4;
            arg0->unk46 = 1;
            arg0->unk14 = &D_8005E480;
            arg0->unk18 = &D_8005E528;
            temp_a1 = ((s32) (arg1 + 3) >> 2) * 4;
            arg0->unk0 = temp_a1;
            arg0->unk47 = 0;
            temp_a1_2 = temp_a1 + (((s32) (arg0->unkE3 + 1) >> 1) * 4);
            arg0->unk4 = temp_a1_2;
            arg0->unk8 = (s32) (temp_a1_2 + (((arg0->unkE9 * 5) + 3) & 0xFFC));
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_3:
    return 0;
}
