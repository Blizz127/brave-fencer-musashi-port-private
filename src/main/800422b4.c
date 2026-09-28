/* Main-exec range [800422B4,800422E8) from the SLUS executable.
 * SHA256(span)=c09df94756821a91f9d579eefd3a8519790e1dd3a72188ac5b125572bbea204c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800422B4 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B0E8;
extern s32 D_8006B568;
void func_800422B4(s32 a0)
{
    s32 v;
    switch (a0) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8006B0E8 = a0;
    D_8006B568 = v;
}
