/* Exact retail word export for [8001A9F8,8001AA78); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_8001A9F8
"
    ".ent	func_8001A9F8
"
    ".type	func_8001A9F8, @function
"
    "func_8001A9F8:
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
    ".end	func_8001A9F8
"
    ".size	func_8001A9F8, .-func_8001A9F8
"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80063108;
extern s32 D_80063120;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_8001A9F8(void) {
    s32 temp_v0;
    void *temp_a0;

    temp_a0 = (D_800B9A02 << 0xE) + &D_800A6610;
    D_80063108 = (s32) ((M2C_FIELD(temp_a0, s32 *, 4) & 0xFFFFFF) | 0x05000000);
    temp_v0 = (M2C_FIELD(temp_a0, s32 *, 4) & 0xFF000000) | ((s32) D_80063108 & 0xFFFFFF);
    M2C_FIELD(temp_a0, s32 *, 4) = temp_v0;
    D_80063120 = (s32) ((temp_v0 & 0xFFFFFF) | 0x05000000);
    M2C_FIELD(temp_a0, s32 *, 4) = (s32) ((M2C_FIELD(temp_a0, s32 *, 4) & 0xFF000000) | ((s32) D_80063120 & 0xFFFFFF));
}
#endif

