/* Overlay range [8012BDBC,8012BE54) from MAIN.CD member 0012.
 * SHA256(span)=cbe13a477501e594e06f7616a976fb2a6b60399f02f37bd30744c8141495f95d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32);                        /* extern */
extern s16 D_80126CB4;
extern s16 D_80126CB8;

s32 func_8012BDBC(void *arg0, s16 arg1) {
    s32 temp_a0;

    temp_a0 = (((func_8004CFEC(M2C_FIELD(arg0, s16 *, 0xE) - D_80126CB8, D_80126CB4 - M2C_FIELD(arg0, s16 *, 6)) - 0x400) & 0xFFF) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12)) & 0xFFF;
    if (temp_a0 >= 0x800) {
        return (0x1000 - temp_a0) < arg1;
    }
    return temp_a0 < arg1;
}
