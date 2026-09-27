/* PSY-Q ratan2 retail span [8004CFEC,8004D16C) from the SLUS executable.
 * SHA256(span)=7c71d5c7b60dcceae3b2c20983d1b6461a6b85e35997511c5408ea821f584a74.
 * Word export only: the native seam needs the retail instruction stream so the
 * guest can execute the library routine it calls. There is no C match claim
 * here - recovering ratan2 as C (it uses the 0x80071F1C table and guarded
 * signed division) is separate work.
 */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80071F1C[];

s16 func_8004CFEC(s32 arg0, s32 arg1) {
    s16 var_v0;
    s16 var_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0_2;
    s32 var_v0_3;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = 0;
    var_a3 = 0;
    if (var_a1 < 0) {
        var_a2 = 1;
        var_a1 = -var_a1;
    }
    if (var_a0 < 0) {
        var_a3 = 1;
        var_a0 = -var_a0;
    }
    if ((var_a1 == 0) && (var_a0 == 0)) {
        return 0;
    }
    if (var_a0 < var_a1) {
        if (var_a0 & 0x7FE00000) {
            var_v0_2 = (var_a0 / (s32) (var_a1 >> 0xA)) * 2;
        } else {
            var_v0_2 = ((s32) (var_a0 << 0xA) / var_a1) * 2;
        }
        var_v1 = *(D_80071F1C + var_v0_2);
    } else {
        if (var_a1 & 0x7FE00000) {
            var_v0_3 = (var_a1 / (s32) (var_a0 >> 0xA)) * 2;
        } else {
            var_v0_3 = ((s32) (var_a1 << 0xA) / var_a0) * 2;
        }
        var_v1 = 0x400 - *(D_80071F1C + var_v0_3);
    }
    if (var_a2 != 0) {
        var_v1 = 0x800 - var_v1;
    }
    var_v0 = var_v1;
    if (var_a3 != 0) {
        var_v0 = -var_v1;
    }
    return var_v0;
}
