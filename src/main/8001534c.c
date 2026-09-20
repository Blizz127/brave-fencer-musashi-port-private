/* Exact retail word export for [8001534C,800153A4); EXE and assembly verified. */
#include "psx_types.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_8001534C\n"
    ".ent\tfunc_8001534C\n"
    ".type\tfunc_8001534C, @function\n"
    "func_8001534C:\n"
    ".end\tfunc_8001534C\n"
    ".size\tfunc_8001534C, .-func_8001534C\n"
);
#else
void func_800153A4(void *, s16, s16, s32, s32);
extern s32 *D_800AF630;

void func_8001534C(s32 arg0, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    func_800153A4(((s32) (arg0 << 0x10) >> 0xC) + 0x9DA8 + &D_800AF630, arg2, arg3, (s32) arg4, (s32) arg5);
}
#endif
