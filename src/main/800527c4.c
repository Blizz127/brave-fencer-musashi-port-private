/* Exact retail word export for [800527C4,8005283C); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800527C4 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A649C;
extern u16 D_800A649E;
extern u16 D_800A644C;
extern u8 D_800A644E;
extern u8 D_800A644F;
extern u8 D_800A6450;
extern u8 D_800A64A8;
extern u16 D_800C7C88;
extern u8 D_800A64A9;
extern void func_8005283C(u16, u16);
void func_800527C4(u16 x, u16 y, s32 intl, s32 dither, u16 vram)
{
    D_800A649C = x;
    D_800A649E = y;
    D_800A644C = 0;
    D_800A644E = dither;
    D_800A644F = 0;
    D_800A6450 = 0;
    D_800A64A8 = intl & 1;
    D_800C7C88 = intl & 4;
    D_800A64A9 = vram;
    func_8005283C(x, y);
}
