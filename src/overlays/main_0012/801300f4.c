/* Overlay range [801300F4,801301E8) from MAIN.CD member 0012.
 * SHA256(span)=8523ac67fe53bf90d67f317108684e1816607adda3afbb95dc9466913bf3f999.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012BCCC(void *);                          /* static */
s32 func_80131A34();                         /* static */
s32 func_80131AC8(void *, s32);                 /* static */
s32 func_80131CA8(void *, s32);                 /* static */
void func_80131E00(void *, s32);             /* static */

void func_801300F4(void *arg0) {
    s32 var_a1;
    s32 var_s1;

    var_s1 = 0;
    M2C_FIELD(arg0, s8 *, 0xC1) = 0xD;
    if (M2C_FIELD(arg0, s32 *, 0xB4) & 0x2000) {
        M2C_FIELD(arg0, s16 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x1E;
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x10) = 0;
        if (func_80131A34(0x27) != 0) {
            M2C_FIELD(arg0, s8 *, 0xC3) = 1;
        } else {
            M2C_FIELD(arg0, s8 *, 0xC3) = 0;
        }
        if (func_8012BCCC(arg0) <= 0x8FFF) {
            var_s1 = 1;
            if (func_80131AC8(arg0, 0x30) == 0) {
                var_a1 = 0x31;
                goto block_9;
            }
        } else {
            var_s1 = 1;
            if (func_80131AC8(arg0, 0x31) == 0) {
                var_a1 = 0x30;
block_9:
                var_s1 = 1;
                func_80131AC8(arg0, var_a1);
            }
        }
    }
    if (func_80131CA8(arg0, 0x25) != 0) {
        var_s1 = 1;
    }
    if (var_s1 == 0) {
        func_80131E00(arg0, 6);
    }
}
