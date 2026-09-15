/* Overlay range [80161A90,80161B18) from MAIN.CD member 0012.
 * SHA256(span)=6447d02f5b4ebe5a4a0a33455f61433fa69ffeb0996a2502f8d32e3e8a6d1eb0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8014AC10();                     /* static */
extern s32 *D_80078E78;
extern u8 D_80078EC0;

void func_80161A90(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s16 *, 0x1C8) != 0) {
        var_v0 = (D_80078EC0 & 0x7F) == 6;
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x1C8) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x1C8) - 1);
    }
    if (((M2C_FIELD(&D_80078E78, u8 *, 0x48) & 0x7F) == 6) && (M2C_FIELD(arg0, s16 *, 0x1C8) == 0)) {
        func_8014AC10(0x3B);
    }
}
