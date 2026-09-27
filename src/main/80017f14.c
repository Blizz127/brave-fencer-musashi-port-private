/* Main-exec range [80017F14,80018094) from the SLUS executable.
 * SHA256(span)=f61162deeff4827870c8cd50076dc742ab90f132cf6cf8773d195a8c3c52a6af.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80017F14
"
    ".ent	func_80017F14
"
    ".type	func_80017F14, @function
"
    "func_80017F14:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80017F14
"
    ".size	func_80017F14, .-func_80017F14
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
s32 func_80058B40(s32, s32, s32, s32);  /* static */
void func_80058C6C(s32, void *);                 /* static */
void func_8005A600(void *, s32, s32, s32, s32); /* static */
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80017F14(void *arg0, u32 arg1, u32 arg2) {
    s32 temp_s1;
    s32 temp_s4;
    u32 var_s1;
    void *temp_s0;
    void *temp_s0_2;

    var_s1 = arg1;
    if (var_s1 >= 0x1000U) {
        var_s1 = 0xFFF;
    }
    temp_s0 = func_80010A08(0xC);
    temp_s4 = (arg2 >> 0x1C) & 3;
    func_8005A600(temp_s0, 0, 0, func_80058B40(2, temp_s4, 0x280, 0) & 0xFFFF, 0);
    temp_s1 = var_s1 * 4;
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, temp_s0);
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, arg0);
    if (arg2 & 0x40000000) {
        M2C_FIELD(arg0, u8 *, 7) = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
    temp_s0_2 = func_80010A08(0xC);
    func_8005A600(temp_s0_2, 0, 1, func_80058B40(2, temp_s4, 0x280, 0) & 0xFFFF, 0);
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, temp_s0_2);
}
#endif

