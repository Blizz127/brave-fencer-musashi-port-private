/* Exact retail word export for [80015A74,80015AD0); EXE and assembly verified. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80015A74\n"
    ".ent\tfunc_80015A74\n"
    ".type\tfunc_80015A74, @function\n"
    "func_80015A74:\n"
    ".end\tfunc_80015A74\n"
    ".size\tfunc_80015A74, .-func_80015A74\n"
);
#else
u32 func_80015A74(u32 val) {
    u32 div = 1000000000U;
    u32 res = 0;
    s32 count = 9;
    do {
        u32 q = val / div;
        val %= div;
        div /= 10;
        res = (res << 4) | (q & 0xF);
        count--;
    } while (count >= 0);
    return res;
}
#endif
