/* Main-exec range [8003B02C,8003B08C) from the SLUS executable.
 * SHA256(span)=6be9a3427b222c65b68d5e98c9ec9ba08efe9a514edddbd5c6e43fcede474242.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003B02C - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u32 *D_8006B55C;
void func_8003B02C(s32 flag)
{
    *D_8006B55C &= 0xFFF8FFFF;
    if (flag) {
        *D_8006B55C |= 0x30000;
    } else {
        *D_8006B55C |= 0x50000;
    }
}
