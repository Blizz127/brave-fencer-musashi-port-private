/* Overlay range [80158D60,80158E24) from MAIN.CD member 0012.
 * SHA256(span)=fadcbe1035d562f6565783bf7e9b770cef2d4e41e63109a1108f31740ce5b042.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80147324();                     /* static */
s32 func_801487F4();                                /* static */
void func_80159434(void *, s32);             /* static */

void func_80158D60(void *arg0) {
    s32 var_s0;

    var_s0 = 1;
    if (func_801487F4() & 0xF0) {
        var_s0 = 4;
    }
    if (var_s0 > 0) {
        do {
            func_80159434(arg0, 0x4C000);
            var_s0 -= 1;
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x10) < 0xC00) {
                func_80147324(0x454);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x10) = 0xC00;
                M2C_FIELD(arg0, s32 *, 0x238) = 0xFFEA0000;
                func_80146CA0(arg0);
                var_s0 = -1;
            }
        } while (var_s0 > 0);
    }
}
