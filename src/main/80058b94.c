/* Main-exec range [80058B94,80058BF4) from the SLUS executable.
 * SHA256(span)=7a53b65c1a0d04d197aacbe86e0aeb8cf758102ede4a93a47890f49fbdb88785.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80073F80;

void func_80058B94(s32 arg0) {
    u32 temp_a3;

    temp_a3 = arg0 & 0xFFFF;
    D_80072784(D_80073F80, (temp_a3 >> 7) & 3, (temp_a3 >> 5) & 3, (temp_a3 << 6) & 0x7C0, ((temp_a3 * 0x10) & 0x100) + ((temp_a3 >> 2) & 0x200));
}
