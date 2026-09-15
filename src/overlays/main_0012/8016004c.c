/* Overlay range [8016004C,8016007C) from MAIN.CD member 0012.
 * SHA256(span)=4ac57cb6c800133de6561aceb908976cb663cde8a4978122a53070a556fb7131.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s8 D_800B9A17;

void func_8016004C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x184) = 0;
    M2C_FIELD(arg0, s16 *, 0x18A) = 0;
    M2C_FIELD(arg0, s16 *, 0x188) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) & ~0x10);
    D_800B9A17 = 1;
}
