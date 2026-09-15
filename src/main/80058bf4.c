/* Main-exec range [80058BF4,80058C34) from the SLUS executable.
 * SHA256(span)=989e22de97bafa071af6e3638dbec38c1545850e3aac1e25377883f8434f3acc.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80073F98;

void func_80058BF4(s32 arg0) {
    D_80072784(D_80073F98, (arg0 & 0x3F) * 0x10, (u32) (arg0 & 0xFFFF) >> 6);
}
