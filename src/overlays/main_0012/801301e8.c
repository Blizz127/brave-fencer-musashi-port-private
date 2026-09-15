/* Overlay range [801301E8,80130278) from MAIN.CD member 0012.
 * SHA256(span)=8d8a795d5f7332022b7aad0d9d574979d5e53d4033655184dae8ac3b8f386a18.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012BEE8(void *);                          /* static */
void func_80130D48(void *);                      /* static */
void func_801319E0(void *);                      /* static */
void func_80131CA8(void *, s32);             /* static */

void func_801301E8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xB4) & 0x2000) {
        if (M2C_FIELD(arg0, u8 *, 0xC3) != 0) {
            if (M2C_FIELD(arg0, u16 *, 0x72) & 0x4000) {
                goto block_5;
            }
        } else if (func_8012BEE8(arg0) != 0) {
block_5:
            func_80130D48(arg0);
            func_801319E0(arg0);
        }
    }
    func_80131CA8(arg0, 0x26);
}
