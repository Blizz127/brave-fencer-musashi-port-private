/* Overlay range [801298F4,801299C8) from MAIN.CD member 0012.
 * SHA256(span)=85a655fbd2c89b7495210a290d4d76f0cd585027849366d7dce6aa80f1e7b4c8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_800B99F0;

void func_801298F4(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0x50);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C) + 8;
    temp_v0_2 = temp_v0 + 4;
    temp_v0_3 = temp_v0_2 + 1;
    M2C_FIELD(arg0, s16 *, 2) = (s16) M2C_FIELD(temp_v0, u8 *, 4);
    temp_v0_4 = temp_v0_3 + 1;
    M2C_FIELD(arg0, s16 *, 4) = (s16) M2C_FIELD(temp_v0_2, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(temp_v0_3, u8 *, 1);
    M2C_FIELD(arg0, void **, 8) = temp_v1;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (temp_v0_4 + 1 + 1);
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(temp_v0_4, u8 *, 1);
    M2C_FIELD(arg0, u16 *, 0x14) = (u16) M2C_FIELD(arg0, u16 *, 0x38);
    M2C_FIELD(arg0, u16 *, 0x1A) = (u16) M2C_FIELD(arg0, u16 *, 0x3E);
    M2C_FIELD(arg0, u16 *, 0x16) = (u16) M2C_FIELD(arg0, u16 *, 0x3A);
    M2C_FIELD(arg0, u16 *, 0x18) = (u16) M2C_FIELD(arg0, u16 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((((u8) M2C_FIELD(temp_v1, u8 *, 6) >> 7) << 0x18) | 0x08000000);
    if (D_800B99F0 == 0) {
        M2C_FIELD(arg0, s16 *, 0x1E) = 0;
        M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x22) = 0x80;
    M2C_FIELD(arg0, s8 *, 0x21) = 0x80;
    M2C_FIELD(arg0, s8 *, 0x20) = 0x80;
    M2C_FIELD(arg0, s16 *, 0x28) = 0xA0;
    M2C_FIELD(arg0, s16 *, 0x2A) = 0x78;
    M2C_FIELD(arg0, void **, 0x24) = arg0;
    M2C_FIELD(arg0, s16 *, 0x2E) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}
