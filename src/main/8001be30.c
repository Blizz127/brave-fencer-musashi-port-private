/* Main-exec range [8001BE30,8001BFA0) from the SLUS executable.
 * SHA256(span)=8809a183b5e72629bc72787be6c9673714adb2f1b988acc595c4fab87d373f2d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800747E4;
extern s32 D_800747E8;
extern s32 D_800747EC;
void func_8002D4C8(s32, s32);                              /* static */
s32 func_80034B98();                                /* static */
extern s32 D_800AE708;
extern s32 D_800BA1B4;

s32 func_8001BE30(void) {
    s32 temp_a0;
    s32 var_v0;
    s32 var_v0_2;

    if (D_800747EC != 1) {
        if (D_800747EC < 2) {
            if (D_800747EC != 0) {
                return 0;
            }
            temp_a0 = func_80034B98();
            if (D_800BA1B4 == 5) {
                if (D_800747E4 != 0) {
                    func_8002D4C8(0x16, 0);
                }
                D_800BA1B4 = 0;
                D_800747E8 = 0;
                D_800747E4 = 0;
                D_800747EC = 3;
                return 0;
            }
            if ((temp_a0 == 1) || (temp_a0 == 4) || (temp_a0 == 2)) {
                func_8002D4C8(0x16, 0);
                D_800747EC = (s32) (D_800747EC + 1);
                return 0;
            }
            var_v0 = 1;
            if (D_800AE708 != 0) {
                D_800747EC = 2;
                return 0;
            }
            /* Duplicate return node #22. Try simplifying control flow for better match */
            return var_v0;
        }
        switch (D_800747EC) {                       /* irregular */
        case 2:
            var_v0_2 = D_800AE708;
            goto block_20;
        case 3:
            var_v0_2 = D_800747E8;
            goto block_20;
        default:
            return 0;
        }
    } else {
        var_v0_2 = func_80034B98();
block_20:
        var_v0 = 0;
        if (var_v0_2 == 0) {
            var_v0 = 1;
        }
        return var_v0;
    }
}
