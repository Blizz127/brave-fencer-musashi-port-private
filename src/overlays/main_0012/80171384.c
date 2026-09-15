/* Overlay range [80171384,801714E4) from MAIN.CD member 0012.
 * SHA256(span)=f61bab4eaf31bed3e6bd2a5b20684cfda625637cc4a6d586a93c4c8741aed454.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u8 func_80012F74(u8, s32, s32, s32);    /* extern */
void func_80171928(s32, u8);                     /* static */
extern void *D_8011F738;

void func_80171384(s32 arg0) {
    u8 temp_a1;
    u8 temp_v0;
    void *temp_s0;

    temp_s0 = D_8011F738;
    M2C_FIELD(temp_s0, u8 *, 0xC) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0xC), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0xD) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0xD), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0xE) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0xE), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x1C) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x1C), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x1D) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x1D), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x1E) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x1E), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x2C) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x2C), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x2D) = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x2D), 0, 0xA, 1);
    temp_v0 = func_80012F74(M2C_FIELD(temp_s0, u8 *, 0x2E), 0, 0xA, 1);
    M2C_FIELD(temp_s0, u8 *, 0x2E) = temp_v0;
    temp_a1 = M2C_FIELD(temp_s0, u8 *, 0x2D);
    if ((M2C_FIELD(temp_s0, u8 *, 0xC) + M2C_FIELD(temp_s0, u8 *, 0xD) + M2C_FIELD(temp_s0, u8 *, 0xE) + M2C_FIELD(temp_s0, u8 *, 0x1C) + M2C_FIELD(temp_s0, u8 *, 0x1D) + M2C_FIELD(temp_s0, u8 *, 0x1E) + M2C_FIELD(temp_s0, u8 *, 0x2C) + temp_a1 + (temp_v0 & 0xFF)) == 0) {
        func_80171928(arg0, temp_a1);
    }
}
