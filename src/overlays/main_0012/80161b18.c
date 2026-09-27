/* Overlay range [80161B18,80161B84) from MAIN.CD member 0012.
 * SHA256(span)=7f0fa660fd707b5e73f78ad4a3d9c3183ed896b89a83775198b2ceed39ff8e7a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801599A4(void *);                      /* static */
void func_8015FA78(void *);                      /* static */
extern s32 D_800AE6B0;

s32 func_80161B18(void *arg0) {
    if ((D_800AE6B0 & 0x80FFFFFF) || !(M2C_FIELD(arg0, s32 *, 0x44) & 0x10)) {
        return 0;
    }
    func_801599A4(arg0);
    func_8015FA78(arg0);
    return 1;
}
