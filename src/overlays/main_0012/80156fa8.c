/* Overlay range [80156FA8,80157158) from MAIN.CD member 0012.
 * SHA256(span)=1be9cbcd53e448e69513ed7c4e616d793a0ec6a3a985ca05a6c79e581dfe5937.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80013294(void *, s16);                     /* extern */

void func_80156FA8(void *arg0, void *arg1, void *arg2) {
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_v0;
    s16 temp_v1;

    sp10 = (M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg0, s16 *, 0)) / 3;
    sp12 = (M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg0, s16 *, 2)) / 3;
    temp_v0 = M2C_FIELD(arg1, s16 *, 4);
    temp_v1 = M2C_FIELD(arg0, s16 *, 4);
    sp14 = (temp_v0 - temp_v1) / 3;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    if (func_80013294(arg0, (temp_v0 - temp_v1) / 3) >= 0x41) {
        if ((sp10 != 0) || (sp12 != 0) || (sp14 != 0)) {
            M2C_FIELD(arg2, s16 *, 0) = (s16) ((u16) M2C_FIELD(arg1, s16 *, 0) - (u16) sp10);
            M2C_FIELD(arg2, s16 *, 2) = (s16) ((u16) M2C_FIELD(arg1, s16 *, 2) - (u16) sp12);
            M2C_FIELD(arg2, s16 *, 6) = 0;
            M2C_FIELD(arg2, s16 *, 4) = (s16) ((u16) M2C_FIELD(arg1, s16 *, 4) - (u16) sp14);
        } else {
            M2C_FIELD(arg2, s16 *, 6) = 1;
        }
        if ((sp10 != 0) || (sp12 != 0) || (sp14 != 0)) {
            M2C_FIELD(arg1, s16 *, 0) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0) + (u16) sp10);
            M2C_FIELD(arg1, s16 *, 2) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 2) + (u16) sp12);
            M2C_FIELD(arg1, s16 *, 6) = 0;
            M2C_FIELD(arg1, s16 *, 4) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 4) + (u16) sp14);
            return;
        }
        goto block_11;
    }
    M2C_FIELD(arg2, s16 *, 6) = 1;
block_11:
    M2C_FIELD(arg1, s16 *, 6) = 1;
}
