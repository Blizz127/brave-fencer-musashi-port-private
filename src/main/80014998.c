/* Native retail instruction export [80014998,800149E0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80014998\n"
    ".ent\tfunc_80014998\n"
    ".type\tfunc_80014998, @function\n"
    "func_80014998:\n"
    ".end\tfunc_80014998\n"
    ".size\tfunc_80014998, .-func_80014998\n"
);
#else
extern s32 *D_800AF630;

void func_80014998(void) {
    void *var_v1;
    s32 var_a0;

    var_a0 = 0;
    var_v1 = &D_800AF630;
    do {
        M2C_FIELD(var_v1, u8 *, 0x51) = (u8) M2C_FIELD(&D_800AF630, u8 *, 0x192);
        M2C_FIELD(var_v1, u8 *, 0x52) = (u8) M2C_FIELD(&D_800AF630, u8 *, 0x193);
        var_a0 += 1;
        M2C_FIELD(var_v1, u8 *, 0x53) = (u8) M2C_FIELD(&D_800AF630, u8 *, 0x194);
        var_v1 += 0x5C;
    } while (var_a0 < 2);
}
#endif
