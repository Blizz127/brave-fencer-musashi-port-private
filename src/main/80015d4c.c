/* Main-exec range [80015D4C,80015F04) from the SLUS executable.
 * SHA256(span)=d7586e917f3c4a27f327489ad34e909c0484dab2ec3e23e4432eeac438bb94fe.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80015D4C
"
    ".ent	func_80015D4C
"
    ".type	func_80015D4C, @function
"
    "func_80015D4C:
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
    ".end	func_80015D4C
"
    ".size	func_80015D4C, .-func_80015D4C
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
void func_80016638(void *, u16, u32, s32);   /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80015D4C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8) {
    u16 sp18;
    s32 sp10;
    s16 temp_v0_2;
    s16 temp_v1;
    s32 *temp_a1_2;
    s32 temp_a1;
    s32 temp_t2;
    u32 temp_s0;
    void *temp_v0;

    sp10 = arg3;
    sp18 = arg7;
    temp_v0 = func_80010A08(0x18);
    M2C_FIELD(temp_v0, s8 *, 3) = 5;
    temp_s0 = arg8 & 0xFFFF;
    temp_t2 = temp_s0 < 4U;
    M2C_FIELD(temp_v0, s8 *, 7) = 0x28;
    if (temp_t2 != 0) {
        M2C_FIELD(temp_v0, s8 *, 7) = 0x2A;
    }
    temp_v1 = arg0 + arg2;
    M2C_FIELD(temp_v0, u8 *, 4) = arg4;
    M2C_FIELD(temp_v0, u8 *, 5) = arg5;
    M2C_FIELD(temp_v0, u8 *, 6) = arg6;
    M2C_FIELD(temp_v0, s16 *, 8) = arg0;
    M2C_FIELD(temp_v0, s16 *, 0xA) = arg1;
    M2C_FIELD(temp_v0, s16 *, 0xC) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0xE) = arg1;
    M2C_FIELD(temp_v0, s16 *, 0x10) = arg0;
    temp_v0_2 = arg1 + sp10;
    M2C_FIELD(temp_v0, s16 *, 0x12) = temp_v0_2;
    M2C_FIELD(temp_v0, s16 *, 0x14) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0x16) = temp_v0_2;
    temp_a1 = sp18 * 4;
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (*(temp_a1 + *(&D_800A651C + (D_800B9A02 * 0x14))) & 0xFFFFFF));
    temp_a1_2 = temp_a1 + *(&D_800A651C + (D_800B9A02 * 0x14));
    *temp_a1_2 = (*temp_a1_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
    if (temp_t2 != 0) {
        func_80016638((D_800B9A02 * 0x14) + &D_800A6518, sp18, temp_s0, 0xFF000000);
    }
}
#endif

