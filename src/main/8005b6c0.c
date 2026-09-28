/* Main-exec range [8005B6C0,8005B710) from the SLUS executable.
 * SHA256(span)=659c212d27bb10812c58508c78c09460c1d5f9799e7cf80eb60d3af7e1859e99.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005B6C0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u32 *D_8007285C;
extern volatile u32 *D_80072858;
s32 func_8005B6C0(u32 *p, s32 n)
{
    s32 pad[1];
    s32 i;
    *D_8007285C = 0x04000000;
    for (i = n - 1; i != -1; i--) {
        *D_80072858 = *p++;
    }
    return 0;
}
