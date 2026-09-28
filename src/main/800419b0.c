/* Exact retail word export for [800419B0,80041A20); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800419B0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800B9B40[];
extern void func_800401A0(s32);
s32 func_800419B0(s16 n)
{
    if ((u16)n <= 16 && D_800B9B40[n] == 2) {
        func_800401A0(0);
        D_800B9B40[n] = 1;
        return n;
    }
    return -1;
}
