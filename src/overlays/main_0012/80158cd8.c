/* Overlay range [80158CD8,80158D60) from MAIN.CD member 0012.
 * SHA256(span)=2e106d30de8537312d94e60a17d1b3845e7cd6aa27e50f72d14f20e9b4a7d250.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
s32 func_80146E98(void *);                          /* static */
void func_80147324();                     /* static */
s32 func_801487F4();                                /* static */

void func_80158CD8(void *arg0) {
    s32 var_s0;

    var_s0 = 1;
    if (func_801487F4() & 0xF0) {
        var_s0 = 4;
    }
    if (var_s0 > 0) {
        do {
            var_s0 -= 1;
            if (func_80146E98(arg0) != 0) {
                func_80147324(0x453);
                M2C_FIELD(arg0, s32 *, 0x238) = 0x5B0000;
                func_80146CA0(arg0);
                var_s0 = -1;
            }
        } while (var_s0 > 0);
    }
}
