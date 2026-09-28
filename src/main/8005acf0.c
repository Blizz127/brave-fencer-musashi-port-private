/* Exact retail word export for [8005ACF0,8005AD34); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005ACF0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_80072788;
u32 func_8005ACF0(s32 x, s32 y)
{
    if (D_80072788 == 1 || D_80072788 == 2) {
        return 0xE5000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE5000000 | ((y & 0x7FF) << 11) | (x & 0x7FF);
}
