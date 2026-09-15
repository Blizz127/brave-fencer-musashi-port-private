/* Overlay range [80137FD8,801380E0) from MAIN.CD member 0012.
 * SHA256(span)=876b1dc46c6a8705d5d1c4ef43fb8cdd6c8ffad6721b666712e96447363793b0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80137FD8(void *arg0, void *arg1, void *arg2, s16 arg3) {
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v1;
    s16 var_v0;
    u16 temp_v0;

    M2C_FIELD(arg2, s8 *, 3) = 8;
    M2C_FIELD(arg2, s8 *, 7) = 0x3A;
    M2C_FIELD(arg2, u8 *, 4) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg2, u8 *, 5) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg2, u8 *, 6) = (u8) M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg2, s8 *, 0x14) = 0xFF;
    M2C_FIELD(arg2, s8 *, 0x15) = 0xFF;
    M2C_FIELD(arg2, s8 *, 0x16) = 0xFF;
    M2C_FIELD(arg2, s8 *, 0x1C) = 0xFF;
    M2C_FIELD(arg2, s8 *, 0x1D) = 0xFF;
    M2C_FIELD(arg2, s8 *, 0x1E) = 0xFF;
    M2C_FIELD(arg2, u8 *, 0xE) = (u8) M2C_FIELD(arg1, u8 *, 2);
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x30);
    M2C_FIELD(arg2, u16 *, 0x18) = temp_v0;
    M2C_FIELD(arg2, u16 *, 8) = temp_v0;
    if (M2C_FIELD(arg0, s32 *, 8) & 0x2000) {
        var_v0 = (M2C_FIELD(arg0, u16 *, 0x30) + M2C_FIELD(arg0, u16 *, 0x34)) - 0xC;
    } else {
        var_v0 = M2C_FIELD(arg0, u16 *, 0x30) + M2C_FIELD(arg0, u16 *, 0x34);
    }
    M2C_FIELD(arg2, s16 *, 0x20) = var_v0;
    M2C_FIELD(arg2, s16 *, 0x10) = var_v0;
    temp_v0_2 = arg3 + 0xC;
    if (M2C_FIELD(arg1, u8 *, 3) == 0) {
        temp_v0_3 = arg3 + 5;
        M2C_FIELD(arg2, s16 *, 0x12) = arg3;
        M2C_FIELD(arg2, s16 *, 0xA) = arg3;
        M2C_FIELD(arg2, s16 *, 0x22) = temp_v0_3;
        M2C_FIELD(arg2, s16 *, 0x1A) = temp_v0_3;
        return;
    }
    temp_v1 = arg3 + 5;
    M2C_FIELD(arg2, s16 *, 0x12) = temp_v0_2;
    M2C_FIELD(arg2, s16 *, 0xA) = temp_v0_2;
    M2C_FIELD(arg2, s16 *, 0x22) = temp_v1;
    M2C_FIELD(arg2, s16 *, 0x1A) = temp_v1;
}
