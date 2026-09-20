/* Main-exec range [80016A7C,80016B60) from the SLUS executable.
 * SHA256(span)=fb5252e0389d12c04386428083cf2aaa07d52c93a570dc9017b8820dfc67d88e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80016A7C
"
    ".ent	func_80016A7C
"
    ".type	func_80016A7C, @function
"
    "func_80016A7C:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80016A7C
"
    ".size	func_80016A7C, .-func_80016A7C
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
void func_80058EB0(void *);                      /* static */

void func_80016A7C(void *arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;
    s16 var_a1;
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = func_80010A08(0x14);
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
    func_80058EB0(temp_v0);
    if (arg1 != 0) {
        func_80017E8C(arg1);
        temp_a1 = arg0 + 8;
        temp_v0_2 = temp_v0 + 0x10;
        var_a1 = func_8004958C(arg0, temp_a1, temp_a1, temp_v0 + 8, temp_v0_2, temp_v0_2, &sp20, &sp24);
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
        var_a1 = M2C_FIELD(arg0, s16 *, 4);
        sp24 = 0;
    }
    if (!(sp24 & ~0x1000)) {
        func_80018094(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x18));
    }
}
#endif

