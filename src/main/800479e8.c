/* Main-exec range [800479E8,80047B3C) from the SLUS executable.
 * SHA256(span)=9d40ef0d06c3abc874d022dd99de79c3b7f29c329c14b070420edf1671a1fdfe.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800479E8(s32 arg0) {
    s32 sp34;
    s32 sp30;
    s32 sp24;
    s32 sp14;
    s32 sp10;
    s32 sp4;
    s32 *var_a2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v1;

    var_a3 = 1;
    var_a2 = &sp4;
    sp4 = arg0 + 0x5D50AD;
    sp24 = arg0 - 0x5D50AD;
    do {
        if (var_a3 != 4) {
            temp_v1 = var_a2->unk20;
            if (temp_v1 >= 0) {
                var_a2->unk4 = (s32) (var_a2->unk0 - (temp_v1 >> var_a3));
                (&sp24)[var_a3] = var_a2->unk20 - ((s32) var_a2->unk0 >> var_a3);
            } else {
                var_a2->unk4 = (s32) (var_a2->unk0 + (temp_v1 >> var_a3));
                (&sp24)[var_a3] = var_a2->unk20 + ((s32) var_a2->unk0 >> var_a3);
            }
        } else {
            temp_v0 = sp30 >> 4;
            if (sp30 >= 0) {
                var_a1 = sp10 - temp_v0;
                var_v1 = sp30 - (sp10 >> 4);
                sp10 = var_a1;
                sp30 = var_v1;
                if (var_v1 >= 0) {
                    sp14 = var_a1 - (var_v1 >> 4);
                    var_v0 = var_v1 - (var_a1 >> 4);
                } else {
                    goto block_10;
                }
            } else {
                var_a1 = sp10 + temp_v0;
                var_v1 = sp30 + (sp10 >> 4);
                sp10 = var_a1;
                sp30 = var_v1;
                if (var_v1 >= 0) {
                    sp14 = var_a1 - (var_v1 >> 4);
                    var_v0 = var_v1 - (var_a1 >> 4);
                } else {
block_10:
                    sp14 = var_a1 + (var_v1 >> 4);
                    var_v0 = var_v1 + (var_a1 >> 4);
                }
            }
            sp34 = var_v0;
        }
        var_a3 += 1;
        var_a2 += 4;
    } while (var_a3 < 7);
    return sp1C;
}
