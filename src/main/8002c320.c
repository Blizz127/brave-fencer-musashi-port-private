/* Main-exec range [8002C320,8002C3B0) from the SLUS executable.
 * SHA256(span)=bc45b3ac220bb74d8607ba4fbc091accf73c21383711723e353df44dfc53606d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_80075AC0;

s32 func_8002C320(void) {
    s32 var_a0;
    s32 var_a3;
    s32 var_t0;
    s32 var_t4;
    s32 var_v0;
    u8 *var_a2;
    u8 *var_t2;
    u8 *var_t3;
    u8 *var_v1;
    u8 temp_v0;

    var_t0 = 0;
    var_t4 = 0;
    var_a3 = 0;
    var_a2 = &D_80075AC0 + 0x10;
    var_t3 = &D_80075AC0 + 2;
    var_t2 = &D_80075AC0;
    do {
        var_a0 = 0;
        if (*var_t2 != 0) {
            var_v1 = var_a2;
            do {
                temp_v0 = *var_v1;
                var_v1 += 1;
                var_a0 += temp_v0;
            } while ((s32) var_v1 < (s32) (var_a2 + 0x70));
            var_v0 = 2 << var_a3;
            if (*var_t3 == (var_a0 & 0xFFFF)) {
                var_v0 = 1 << var_a3;
            }
            var_t0 |= var_v0;
        }
        var_a3 += 8;
        var_a2 += 0x80;
        var_t3 += 0x80;
        var_t4 += 1;
        var_t2 += 0x80;
    } while (var_t4 < 4);
    return var_t0;
}
