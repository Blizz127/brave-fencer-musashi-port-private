/* Exact retail word export for [8005AC24,8005ACF0); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005AC24 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s16 D_8007278C;
extern s16 D_8007278E;
extern u8 D_80072788;
u32 func_8005AC24(s16 x, s16 y)
{
    s32 pad[1];

    x = (x < 0) ? 0 : ((x > D_8007278C - 1) ? D_8007278C - 1 : x);
    y = (y < 0) ? 0 : ((y > D_8007278E - 1) ? D_8007278E - 1 : y);
    if (D_80072788 == 1 || D_80072788 == 2) {
        return 0xE4000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}
