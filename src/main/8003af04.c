/* Native retail instruction export [8003AF04,8003AF4C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003AF04 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u16 *D_8006B54C;
extern s32 D_8006B574;
void func_8003AF04(s32 idx, u32 val, s32 mode)
{
    if (mode == 0) {
        D_8006B54C[idx] = val;
    } else {
        D_8006B54C[idx] = val >> D_8006B574;
    }
}
