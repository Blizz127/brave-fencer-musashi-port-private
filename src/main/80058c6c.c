/* Main-exec range [80058C6C,80058CA8) from the SLUS executable.
 * SHA256(span)=1c2e33c9e0ddfcd56385916112089fab3d7d343336e2514633a70260ef7d4064.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058C6C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { unsigned addr : 24; unsigned len : 8; } P_TAG;
void func_80058C6C(void *ot, void *p)
{
    ((P_TAG *)p)->addr = ((P_TAG *)ot)->addr;
    ((P_TAG *)ot)->addr = (u32)p;
}
