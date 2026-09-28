/* Exact retail word export for [8003D3B4,8003D3F8); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003D3B4 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u16 *D_8006B54C;
extern void func_8003B0E4(void);
void func_8003D3B4(s32 voice, s32 x)
{
    D_8006B54C[(voice << 3) + 5] = (D_8006B54C[(voice << 3) + 5] & 0xFFC0) | x;
    func_8003B0E4();
}
