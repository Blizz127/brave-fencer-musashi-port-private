/* Main-exec range [8001BADC,8001BB60) from the SLUS executable.
 * SHA256(span)=b909afa18cff70984aa827361035edcf81b1d006e037152add1f2d9604b5cba9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80074808;

s32 func_8001BADC(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t1;

    var_t0 = 0;
    var_t1 = 0;
    do {
        var_a2 = 0;
        if (var_t0 < arg0) {
            var_a2 = -(arg1 != 0) & 8;
        }
        temp_a0 = 0x1D - var_t0;
        var_t0 += 1;
        temp_v1 = (var_a2 << 0x10) | ((var_a2 << 8) | 0x62000000) | var_a2;
        M2C_FIELD((D_80074808 + var_t1), s32 *, 8) = temp_v1;
        var_t1 += 0x14;
        M2C_FIELD((D_80074808 + (temp_a0 * 0x14)), s32 *, 8) = temp_v1;
    } while (var_t0 < 0xF);
    return arg0 >= 0x2C;
}
