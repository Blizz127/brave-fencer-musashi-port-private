/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Moves the bits in mask between the two flag words: mode 1 moves them from
 * D_800A2BA0 into D_800C7D2C, any other mode moves them back. */
extern u32 D_800A2BA0;
extern u32 D_800C7D2C;

void func_8002F064(s32 mode, u32 mask)
{
    if (mode == 1) {
        D_800A2BA0 &= ~mask;
        D_800C7D2C |= mask;
    } else {
        D_800C7D2C &= ~mask;
        D_800A2BA0 |= mask;
    }
}
