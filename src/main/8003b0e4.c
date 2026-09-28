/* Native retail instruction export [8003B0E4,8003B14C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003B0E4 - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8003B0E4(void)
{
    volatile s32 i;
    volatile s32 v;

    v = 13;
    for (i = 0; i < 60; i++) {
        v = v * 13;
    }
}
