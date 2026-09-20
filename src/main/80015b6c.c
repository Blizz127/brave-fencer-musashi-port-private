/* Main-exec range [80015B6C,80015D4C) from the SLUS executable.
 * SHA256(span)=66e85fd30d77c376692991344d02c30c8e6a17d81447d29cd9fcb53d43bae035.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80015B6C
"
    ".ent	func_80015B6C
"
    ".type	func_80015B6C, @function
"
    "func_80015B6C:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80015B6C
"
    ".size	func_80015B6C, .-func_80015B6C
"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80015B6C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s32 sp18;
    s32 sp10;
    s16 temp_s1;
    s16 temp_s2;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    sp10 = arg2;
    sp18 = arg3;
    temp_s0 = *(&D_800A651C + (D_800B9A02 * 0x14));
    temp_v0 = func_80010A08(0x34);
    M2C_FIELD(temp_v0, s8 *, 3) = 1;
    M2C_FIELD(temp_v0, s32 *, 4) = 0xE1000000;
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFFFFFF));
    temp_v0_2 = temp_v0 + 8;
    M2C_FIELD(temp_s0, s32 *, 0x3FFC) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF));
    M2C_FIELD(temp_v0_2, s8 *, 3) = 8;
    M2C_FIELD(temp_v0_2, s8 *, 7) = 0x38;
    M2C_FIELD(temp_v0_2, u8 *, 4) = arg4;
    M2C_FIELD(temp_v0_2, u8 *, 5) = arg5;
    M2C_FIELD(temp_v0_2, u8 *, 6) = arg6;
    M2C_FIELD(temp_v0_2, u8 *, 0xC) = arg4;
    M2C_FIELD(temp_v0_2, u8 *, 0xD) = arg5;
    M2C_FIELD(temp_v0_2, u8 *, 0xE) = arg6;
    M2C_FIELD(temp_v0_2, u8 *, 0x14) = arg7;
    M2C_FIELD(temp_v0_2, u8 *, 0x15) = arg8;
    M2C_FIELD(temp_v0_2, u8 *, 0x16) = arg9;
    M2C_FIELD(temp_v0_2, u8 *, 0x1C) = arg7;
    M2C_FIELD(temp_v0_2, u8 *, 0x1D) = arg8;
    M2C_FIELD(temp_v0_2, u8 *, 0x1E) = arg9;
    M2C_FIELD(temp_v0_2, s16 *, 8) = arg0;
    M2C_FIELD(temp_v0_2, s16 *, 0xA) = arg1;
    temp_s1 = arg0 + sp10;
    M2C_FIELD(temp_v0_2, s16 *, 0x10) = temp_s1;
    M2C_FIELD(temp_v0_2, s16 *, 0x12) = arg1;
    M2C_FIELD(temp_v0_2, s16 *, 0x18) = arg0;
    temp_s2 = arg1 + sp18;
    M2C_FIELD(temp_v0_2, s16 *, 0x1A) = temp_s2;
    M2C_FIELD(temp_v0_2, s16 *, 0x20) = temp_s1;
    M2C_FIELD(temp_v0_2, s16 *, 0x22) = temp_s2;
    M2C_FIELD(temp_v0, s32 *, 8) = (s32) ((M2C_FIELD(temp_v0, s32 *, 8) & 0xFF000000) | (M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFFFFFF));
    temp_v0_3 = temp_v0_2 + 0x24;
    M2C_FIELD(temp_s0, s32 *, 0x3FFC) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFF000000) | ((s32) temp_v0_2 & 0xFFFFFF));
    M2C_FIELD(temp_v0_3, s8 *, 3) = 1;
    M2C_FIELD(temp_v0_3, s32 *, 4) = 0xE1000200;
    M2C_FIELD(temp_v0_2, s32 *, 0x24) = (s32) ((M2C_FIELD(temp_v0_2, s32 *, 0x24) & 0xFF000000) | (M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFFFFFF));
    M2C_FIELD(temp_s0, s32 *, 0x3FFC) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0x3FFC) & 0xFF000000) | ((s32) temp_v0_3 & 0xFFFFFF));
}
#endif

