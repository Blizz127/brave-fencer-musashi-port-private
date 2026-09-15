/* Overlay range [801535F4,8015369C) from MAIN.CD member 0012.
 * SHA256(span)=0f7e933ce2ceec1517da91fa5ebe70770e061f08cc12223a7beb27a5812d2e29.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146D90(void *);                      /* static */
s32 func_8014CC28(void *);                          /* static */
s32 func_8014ED28();                                /* static */
s32 func_8014FA04(void *);                          /* static */

s32 func_801535F4(void *arg0) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    if (func_8014ED28() != 0) {
        func_80146D90(arg0);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x34) > 0) && (func_8014CC28(arg0) != 0)) {
        var_s1 = 1;
    }
    temp_v0 = func_8014FA04(arg0);
    if (temp_v0 & 0x4000) {
        return 2;
    }
    if (temp_v0 & 0x2000) {
        return 1;
    }
    var_v0 = 4;
    if (!(temp_v0 & 0x8000)) {
        var_v0 = var_s1;
    }
    return var_v0;
}
