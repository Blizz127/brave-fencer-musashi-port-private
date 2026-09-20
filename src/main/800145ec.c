/* Exact retail word export for [800145EC,800146B0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_800145EC\n"
    ".ent\tfunc_800145EC\n"
    ".type\tfunc_800145EC, @function\n"
    "func_800145EC:\n"
    ".end\tfunc_800145EC\n"
    ".size\tfunc_800145EC, .-func_800145EC\n"
);
#else
extern s32 D_80062A3E[];
extern s32 D_80062A40[];
void func_80014774();
void func_800147B8();
void func_800525DC(u16, u16, s32, s32, s32);
void func_80053178(s32, u16, s32, s32);
void func_80053218();
void func_80059234();
extern s32 *D_80062A3C;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;
extern u16 D_800AF7C0;

void func_800145EC(s32 arg0) {
    s32 temp_v0;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v0_2;
    u16 var_a1;

    temp_v0 = (arg0 & 0xFFFF) * 6;
    temp_a0 = *(&D_80062A3C + temp_v0);
    D_800AF7BC = temp_a0;
    temp_a1 = *(D_80062A3E + temp_v0);
    D_800AF7BE = temp_a1;
    temp_v0_2 = *(D_80062A40 + temp_v0);
    D_800AF7C0 = temp_v0_2;
    func_800525DC(temp_a0, temp_a1, temp_v0_2 | 4, 0, 0);
    var_a1 = D_800AF7BE;
    if (var_a1 == 0x1E0) {
        var_a1 = 0;
    }
    func_80053178(0, var_a1, 0, 0);
    func_80059234(1);
    func_80053218();
    func_80014774();
    func_800147B8();
}
#endif
