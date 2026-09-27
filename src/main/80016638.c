/* Exact retail word export for [80016638,800166E8); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80016638
"
    ".ent	func_80016638
"
    ".type	func_80016638, @function
"
    "func_80016638:
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
    ".end	func_80016638
"
    ".size	func_80016638, .-func_80016638
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

void func_80016638(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_s1_2;
    s32 temp_s1;
    void *temp_v0;

    temp_v0 = func_80010A08(8);
    M2C_FIELD(temp_v0, s8 *, 3) = 1;
    temp_s1 = arg1 * 4;
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) (((arg2 << 5) & 0x9FF) | 0xE1000000);
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (*(s32 *) (temp_s1 + M2C_FIELD(arg0, s32 *, 4)) & 0xFFFFFF));
    temp_s1_2 = temp_s1 + M2C_FIELD(arg0, s32 *, 4);
    *temp_s1_2 = (*temp_s1_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
}
#endif

