/* Main-exec range [80018094,80018194) from the SLUS executable.
 * SHA256(span)=71f6173fe63ac65906671fe5f0b56ce7c799199153af963059b76599a72d9015.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80018094
"
    ".ent	func_80018094
"
    ".type	func_80018094, @function
"
    "func_80018094:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80018094
"
    ".size	func_80018094, .-func_80018094
"
);
#else
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                             /* static */
s32 func_80058B40(s32, s32, s32, s32);                    /* static */
void func_80058C6C(s32, void *, u32);                  /* static */
void func_8005A600(void *, s32, s32, s32, s32);            /* static */
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80018094(void *arg0, u32 arg1, u32 arg2) {
    s32 temp_s2;
    u32 var_a3;
    void *temp_s0;

    var_a3 = arg1;
    if (var_a3 >= 0x1000U) {
        var_a3 = 0xFFF;
    }
    temp_s2 = var_a3 * 4;
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s2, arg0, var_a3);
    if (arg2 & 0x40000000) {
        arg0->unk7 = (u8) (arg0->unk7 | 2);
        temp_s0 = func_80010A08(0xC);
        func_8005A600(temp_s0, 0, 0, func_80058B40(2, (arg2 >> 0x1C) & 3, 0x280, 0) & 0xFFFF, 0);
        func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s2, temp_s0);
    }
}
#endif

