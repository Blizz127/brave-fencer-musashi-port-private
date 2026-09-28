/* Main-exec range [80058CA8,80058CE4) from the SLUS executable.
 * SHA256(span)=b8f4360e6e689e8860897359cf6e98bab5eaba5e11b218cb5637492c1875b33c.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058CA8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { unsigned addr : 24; unsigned len : 8; } P_TAG;
void func_80058CA8(void *ot, void *p0, void *p1)
{
    ((P_TAG *)p1)->addr = ((P_TAG *)ot)->addr;
    ((P_TAG *)ot)->addr = (u32)p0;
}
