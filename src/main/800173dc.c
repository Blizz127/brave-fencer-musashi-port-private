/* Main-exec range [800173DC,800174DC) from the SLUS executable.
 * SHA256(span)=b0e3a3426d9f6065b9e940a88f06c2a557b8c4a2aa9828323b57ead44c93b284.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_800173DC
"
    ".ent	func_800173DC
"
    ".type	func_800173DC, @function
"
    "func_800173DC:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_800173DC
"
    ".size	func_800173DC, .-func_800173DC
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
void func_80017E8C(s32);                         /* static */
void func_80018094(void *, s16, s32);            /* static */
s16 func_8004958C(void *, void *, void *, void *, void *, void *, void *, s32 *); /* static */
void func_80058D98(void *);                      /* static */

void func_800173DC(void *arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;
    s16 var_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x1C);
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    func_80058D98(temp_v0);
    if (arg1 != 0) {
        func_80017E8C(arg1);
        var_a1 = func_8004958C(arg0, arg0 + 8, arg0 + 0x10, temp_v0 + 8, temp_v0 + 0x10, temp_v0 + 0x18, &sp20, &sp24);
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        var_a1 = M2C_FIELD(arg0, s16 *, 4);
        sp24 = 0;
    }
    if (!(sp24 & ~0x1000)) {
        func_80018094(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x24));
    }
}
#endif

