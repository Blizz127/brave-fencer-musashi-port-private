/* Native retail instruction export [8004014C,800401A0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8004014C - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B574;
extern u32 *D_8006B5B0;
extern s32 D_8006B5AC;
extern s32 D_8006B5A8;
s32 func_8004014C(s32 n, u32 *p)
{
    s32 sh;
    if (n > 0) {
        sh = D_8006B574;
        p[0] = 0x40001010;
        D_8006B5B0 = p;
        D_8006B5AC = 0;
        D_8006B5A8 = n;
        p[1] = (0x10000 << sh) - 0x1010;
        return n;
    }
    return 0;
}
