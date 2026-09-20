/* Main-exec range [80016450,80016638) from the SLUS executable.
 * SHA256(span)=e769f19aaa1be0ce832b61b698e2e27be98001a24e72097082f48f96a3ceaaf9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80016450
"
    ".ent	func_80016450
"
    ".type	func_80016450, @function
"
    "func_80016450:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80016450
"
    ".size	func_80016450, .-func_80016450
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
void func_80016638(void *, s32, s32);        /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern s32 *D_800AE7B8;
extern s32 *D_800AE7BC;
extern u16 D_800B9A02;

void func_80016450(s8 arg0, s32 arg1) {
    void *var_v0;
    s32 *temp_a2_2;
    s32 *temp_v1;
    s32 temp_a2;
    s32 var_a0;
    s32 var_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x18);
    M2C_FIELD(temp_v0, s8 *, 3) = 5;
    M2C_FIELD(temp_v0, s8 *, 7) = 0x2A;
    M2C_FIELD(temp_v0, s16 *, 0x10) = -0xA0;
    M2C_FIELD(temp_v0, s16 *, 8) = -0xA0;
    M2C_FIELD(temp_v0, s16 *, 0x14) = 0xA0;
    M2C_FIELD(temp_v0, s16 *, 0xC) = 0xA0;
    M2C_FIELD(temp_v0, s16 *, 0xE) = -0x78;
    M2C_FIELD(temp_v0, s16 *, 0xA) = -0x78;
    var_a1 = arg1 & 0xFFFF;
    M2C_FIELD(temp_v0, s8 *, 6) = arg0;
    M2C_FIELD(temp_v0, s8 *, 5) = arg0;
    M2C_FIELD(temp_v0, s8 *, 4) = arg0;
    M2C_FIELD(temp_v0, s16 *, 0x16) = 0x78;
    M2C_FIELD(temp_v0, s16 *, 0x12) = 0x78;
    if (var_a1 != 0) {
        temp_a2 = var_a1 * 4;
        M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (*(temp_a2 + *(&D_800A651C + (D_800B9A02 * 0x14))) & 0xFFFFFF));
        temp_a2_2 = temp_a2 + *(&D_800A651C + (D_800B9A02 * 0x14));
        *temp_a2_2 = (*temp_a2_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
        var_v0 = &D_800A6518;
        var_a0 = D_800B9A02 * 0x14;
    } else {
        M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (**(&D_800AE7BC + (D_800B9A02 * 0x14)) & 0xFFFFFF));
        temp_v1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
        var_a1 = 0;
        *temp_v1 = (*temp_v1 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
        var_a0 = D_800B9A02 * 0x14;
        var_v0 = &D_800AE7B8;
    }
    func_80016638(var_a0 + var_v0, var_a1, 1);
}
#endif

