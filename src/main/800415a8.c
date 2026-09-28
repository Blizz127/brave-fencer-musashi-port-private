/* Exact retail word export for [800415A8,8004162C); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800415A8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800B9B40[];
extern u32 D_800C7CE0[];
extern u16 D_800C7CD8;
extern void func_8004162C(u32);
void func_800415A8(s16 n)
{
    if ((u16)n < 16 && D_800B9B40[n] == 1) {
        func_8004162C(D_800C7CE0[n]);
        D_800B9B40[n] = 0;
        D_800C7CD8--;
    }
}
