/* Overlay range [8016C74C,8016C83C) from MAIN.CD member 0012.
 * SHA256(span)=c7ecaf0e84cb58dbfef578428d65b89ac3e9c5da0200eb79be083fa9d1f2ae4f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047E98(void *, s16);                     /* extern */

void func_8016C74C(void *arg0, void *arg1, s16 arg2, s16 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (M2C_FIELD(arg1, s16 *, 0) << arg2));
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + (M2C_FIELD(arg1, s16 *, 2) << arg2));
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + (M2C_FIELD(arg1, s16 *, 4) << arg2));
    M2C_FIELD(arg1, s16 *, 0) = (s16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg1, s16 *, 2) = (s16) M2C_FIELD(arg0, u16 *, 0x16);
    M2C_FIELD(arg1, s16 *, 4) = (s16) M2C_FIELD(arg0, u16 *, 0x1A);
    if (arg4 < func_80047E98(arg1, arg2)) {
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg1, s16 *, 0) << arg3);
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg1, s16 *, 2) << arg3);
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg1, s16 *, 4) << arg3);
    }
}
