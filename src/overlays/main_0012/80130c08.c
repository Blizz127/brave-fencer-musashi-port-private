/* Overlay range [80130C08,80130D0C) from MAIN.CD member 0012.
 * SHA256(span)=91c91577383acc43fb7184f4b31bb4c05bc8533949e8029da2af238c13588f4c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012BEE8(void *);                          /* static */
s32 func_8012CBCC();                                /* static */
void func_80131C78(void *);                      /* static */
void func_80131CA8(void *, s32);             /* static */
void func_80131E00(void *, s32);             /* static */

void func_80130C08(void *arg0) {
    s32 var_a1;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0xC4) & 2)) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xB4);
        if (temp_v1 & 0x20000) {
            if (temp_v1 & 1) {
                if ((func_8012CBCC() & 0xFF) == 2) {
                    func_80131E00(arg0, 0x12);
                    return;
                }
                if (M2C_FIELD(arg0, u8 *, 0xC2) != 0) {
                    var_v0 = func_8012BEE8(arg0);
                } else {
                    var_v0 = M2C_FIELD(arg0, u16 *, 0x72) & 0x4000;
                }
                if (var_v0 != 0) {
                    var_s1 = 1;
                }
                if (var_s1 != 0) {
                    func_80131C78(arg0);
                }
                goto block_13;
            }
block_13:
            func_80131CA8(arg0, 5);
            goto block_14;
        }
block_14:
        if (M2C_FIELD(arg0, s32 *, 0xC4) & 2) {
            goto block_15;
        }
        var_a1 = 0x38;
        goto block_17;
    }
block_15:
    var_a1 = 5;
block_17:
    func_80131CA8(arg0, var_a1);
}
