/* Main-exec range [80017294,8001739C) from the SLUS executable.
 * SHA256(span)=94c2291cf2e35ebb22746974a9400a64f1a5ef49d4b2ffedea353256c09aebcd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80017294
"
    ".ent	func_80017294
"
    ".type	func_80017294, @function
"
    "func_80017294:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80017294
"
    ".size	func_80017294, .-func_80017294
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
s16 func_8004961C(void *, void *, void *, void *, void *, void *, void *, void *, void *, s32 *); /* static */
void func_80058DC0(void *);                      /* static */

void func_80017294(void *arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;
    s16 var_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x18);
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    func_80058DC0(temp_v0);
    if (arg1 != 0) {
        func_80017E8C(arg1);
        var_a1 = func_8004961C(arg0, arg0 + 8, arg0 + 0x10, arg0 + 0x18, temp_v0 + 8, temp_v0 + 0xC, temp_v0 + 0x10, temp_v0 + 0x14, &sp28, &sp2C);
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
        var_a1 = M2C_FIELD(arg0, s16 *, 4);
        sp2C = 0;
    }
    if (!(sp2C & ~0x1000)) {
        func_80018094(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x24));
    }
}
#endif

