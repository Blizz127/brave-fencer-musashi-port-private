/* Overlay range [8013B598,8013B6A0) from MAIN.CD member 0012.
 * SHA256(span)=238b1b40b21b86f586baa9703c39099132f0c6e26bd6b94cbc46eb1aad56ed21.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80185B58[];
extern s32 D_80185B5E[];
extern s32 D_80185B60[];
extern s32 D_80185B64[];
extern s32 *D_80185B5C;

void func_8013B598(s32 arg0, void *arg1) {
    *(D_80185B58 + (arg0 * 0x1C)) = 1;
    *(&D_80185B5C + (arg0 * 0x1C)) = M2C_FIELD(arg1, u16 *, 0);
    *(D_80185B5E + (arg0 * 0x1C)) = M2C_FIELD(arg1, u16 *, 2);
    *(D_80185B60 + (arg0 * 0x1C)) = M2C_FIELD(arg1, u16 *, 4);
    *(D_80185B64 + (arg0 * 0x1C)) = 0x100;
}
