/* Main-exec range [8005E9D4,8005EA34) from the SLUS executable.
 * SHA256(span)=b68a457b59c63c93696473a10a807e0f5733af8cc278523c04a10f07a3b604bb.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072960();                               /* static */

s32 func_8005E9D4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x53) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0x46) == 2) {
            return 1;
        }
        M2C_FIELD(arg0, u8 *, 0x46) = 0xFEU;
        goto block_5;
    }
    D_80072960();
block_5:
    return 0;
}
