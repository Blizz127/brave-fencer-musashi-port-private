/* Exact retail word export for [8003C4F0,8003C598); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003C4F0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B0E8;
extern s32 D_8006B580;
extern s32 D_8006B0E0;
extern s32 func_8005CEA8(s32);
s32 func_8003C4F0(s32 flag)
{
    s32 r;

    if (D_8006B0E8 == 1 || D_8006B580 == 1) {
        return 1;
    }
    r = func_8005CEA8(D_8006B0E0); if (flag == 1) { if (r == 0) { while (func_8005CEA8(D_8006B0E0) == 0) { } } D_8006B580 = 1; return 1; } if (r == 1) { D_8006B580 = 1; } return r;
}
