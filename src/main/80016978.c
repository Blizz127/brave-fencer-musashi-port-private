/* Main-exec range [80016978,80016A3C) from the SLUS executable.
 * SHA256(span)=f42d53c8dd5f4c86f7c8e039340b5d199dbe9c4e6994fdc7598917856f47f191.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80016978
"
    ".ent	func_80016978
"
    ".type	func_80016978, @function
"
    "func_80016978:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80016978
"
    ".size	func_80016978, .-func_80016978
"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062BA0[];
void func_80016450(s32, s32);                /* static */
extern s32 *D_800AF630;
extern u16 D_800AF7CE;
extern s32 D_800B9A18;

s32 func_80016978(s32 arg0) {
    s32 temp_a0;
    u16 var_a0;
    u16 var_v0;
    u8 var_v1;

    temp_a0 = arg0 & 3;
    if (temp_a0 == 0) {
        var_v1 = *(D_80062BA0 + D_800B9A18);
    } else {
        var_v1 = *(D_80062BA0 + temp_a0);
    }
    D_800AF7CE += var_v1;
    var_a0 = M2C_FIELD(&D_800AF630, u16 *, 0x19E);
    if (var_a0 >= 0xFFU) {
        var_a0 = 0xFF;
    }
    if ((u32) (arg0 & 0xFFFF) < 4U) {
        var_v0 = 0xFF - var_a0;
    } else {
        var_v0 = var_a0;
    }
    func_80016450(var_v0 & 0xFF, 0);
    return (u16) M2C_FIELD(&D_800AF630, u16 *, 0x19E) >= 0xFFU;
}
#endif

