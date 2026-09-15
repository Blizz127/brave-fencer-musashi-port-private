/* Overlay range [80158C40,80158CD8) from MAIN.CD member 0012.
 * SHA256(span)=5d104ce881fcb28cd47be63a6f9878ef2106ee395087571b8059ec1c2734390a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80146E90(void *, s32);             /* static */
s32 func_801487F4();                                /* static */
void func_80159404(void *, s32);             /* static */

void func_80158C40(void *arg0) {
    s32 var_s0;

    var_s0 = 1;
    if (func_801487F4() & 0xF0) {
        var_s0 = 4;
    }
    if (var_s0 > 0) {
        do {
            func_80159404(arg0, 0x3C000);
            var_s0 -= 1;
            if (M2C_FIELD(arg0, s32 *, 0x234) < 0) {
                func_80146E90(arg0, 4);
                func_80146CA0(arg0);
                var_s0 = -1;
            }
        } while (var_s0 > 0);
    }
}
