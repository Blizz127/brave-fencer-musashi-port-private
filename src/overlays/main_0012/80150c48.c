/* Overlay range [80150C48,80150CA0) from MAIN.CD member 0012.
 * SHA256(span)=918e7db2141986db17be133b7d75fc133447cec99e701e1c76a3ac5256dd437c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80150480();                                /* static */
extern s32 D_800AE6B0;
extern u16 D_800AE6DC;

void func_80150C48(void *arg0) {
    if (func_80150480() != 0) {
        D_800AE6B0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1A4), s32 *, 0xDC);
        D_800AE6DC = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1A4), u16 *, 0xFC);
    }
}
